
#include <fstream>
#include <iostream>
#include <sstream>

#include "HTTPRequest.hpp"
#include "json.hpp"
#include "rang.hpp"

using json = nlohmann::json;

using namespace std;

const std::string OPENAI_API_URL = "";

string requestJson(const string& prompt) {
  return R"({
      "model": "gpt-3.5-turbo",
      "messages": [
        {          
          "role": "system",
          "content": "You are a helpful assistant"
        },
        {
          "role": "user",
          "content": ")" + prompt + R"("
        }                         
      ]
    })";
}


std::string gpt(const string &prompt) {

  try {
    http::Request request{OPENAI_API_URL + "/v1/chat/completions"};
    const std::string body = requestJson(prompt);
    const auto response =
        request.send("POST", body, {{"Content-Type", "application/json"}});

    auto resp =
        json::parse(std::string{response.body.begin(), response.body.end()});
    return resp["choices"][0]["message"]["content"];

  } catch (const std::exception &e) {
    std::cerr << "Request failed, error: " << e.what() << '\n';
    return "";
  }
}

int main(int argc, char** argv) {  
  if (OPENAI_API_URL.empty()) {
    cout << "Error: OPENAI_API_URL constant is empty";
    return 1;
  }

  string gptOutput = gpt("Напиши викторину на тему C++. Выводи всё в строгом формате: в первой строке количество вопросов (N), далее N вопросов, каждый вопрос это одна строка вопроса и 3 строки вариантов ответа. После вариантов ответа выводи номер правильного ответа с новой строки. Не выводи ничего, кроме того, что я указал, формат строгий, твой вывод я читаю программой, так что нельзя писать ничего в духе '#### Вопрос 1' или '**Ответы**'. Не используй Markdown, всё в plaintext. Также не делай лишние пустые строки. Пусть N = 5");

  struct Question {
    string question;
    vector<string> answers;
    int correctAnswerIndex;
  };

  cout << gptOutput << endl;

  stringstream gin(gptOutput);
  vector<Question> quiz;
  int n;
  string nStr;
  getline(gin, nStr);
  n = stoi(nStr);

  for (int i = 0; i < n; i++) {
    Question q;
    while(q.question.empty()) getline(gin, q.question);
    for (int j = 0; j < 3; j++) {
      string answer;
      getline(gin, answer);
      q.answers.push_back(answer);
    }
    int correctNum;
    string correctNumStr;
    getline(gin, correctNumStr);
    correctNum = stoi(correctNumStr);
    q.correctAnswerIndex = correctNum - 1;

    quiz.push_back(q);
  }

  cout << quiz.size() << " questions loaded." << endl;
  cout << string(80, '\n') << endl;

  for (const Question& q: quiz) {
    cout << rang::style::bold << q.question << rang::style::reset << endl;
    for (int i = 0; i < q.answers.size(); i++) {
      cout << i + 1 << ". " << q.answers[i] << endl;
    }
    
    cout << "Ответ?\n > ";
    int userAnswer;
    cin >> userAnswer;
    
    if (userAnswer - 1 == q.correctAnswerIndex) {
      cout << rang::fg::green << "Верно!" << rang::fg::reset << endl << endl;
    }
    else {
      cout << rang::fg::red <<"Неверно. Правильный ответ: " << q.answers[q.correctAnswerIndex] << rang::fg::reset << endl << endl;
    }
  }
} 
