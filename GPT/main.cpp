
#include <iostream>

#include "my_gpt.hpp"
#include "rang.hpp"

using namespace std;

int getlineInt(istream& stream)
{
    string line;
    getline(stream, line);
    return stoi(line);
}

int main()
{
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
    int n = getlineInt(gin);

    for (int i = 0; i < n; i++) {
        Question q;
        while (q.question.empty())
            getline(gin, q.question);
        for (int j = 0; j < 3; j++) {
            string answer;
            getline(gin, answer);
            q.answers.push_back(answer);
        }
        int correctNum = getlineInt(gin);
        q.correctAnswerIndex = correctNum - 1;

        quiz.push_back(q);
    }

    cout << quiz.size() << " questions loaded." << endl;
    cout << string(80, '\n') << endl;

    for (const Question& q : quiz) {
        cout << rang::style::bold << q.question << rang::style::reset << endl;
        for (int i = 0; i < q.answers.size(); i++) {
            cout << i + 1 << ". " << q.answers[i] << endl;
        }

        cout << "Ответ?\n > ";
        int userAnswer;
        cin >> userAnswer;

        if (userAnswer - 1 == q.correctAnswerIndex) {
            cout << rang::fg::green << "Верно!" << rang::fg::reset << endl
                 << endl;
        } else {
            cout << rang::fg::red << "Неверно. Правильный ответ: " << q.answers[q.correctAnswerIndex] << rang::fg::reset << endl
                 << endl;
        }
    }
}
