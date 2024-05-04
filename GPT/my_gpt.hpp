#pragma once

#include <fstream>
#include <iostream>
#include <sstream>

#include "HTTPRequest.hpp"
#include "json.hpp"

using json = nlohmann::json;

using namespace std;

const std::string OPENAI_API_URL = "";

string requestJson(const string& prompt)
{
    return R"({
      "model": "gpt-3.5-turbo",
      "messages": [
        {          
          "role": "system",
          "content": "You are a helpful assistant"
        },
        {
          "role": "user",
          "content": ")"
        + prompt + R"("
        }                         
      ]
    })";
}

std::string gpt(const string& prompt)
{

    try {
        http::Request request { OPENAI_API_URL + "/v1/chat/completions" };
        const std::string body = requestJson(prompt);
        const auto response = request.send("POST", body, { { "Content-Type", "application/json" } });

        auto resp = json::parse(std::string { response.body.begin(), response.body.end() });
        cout << resp << endl;
        return resp["choices"][0]["message"]["content"];

    } catch (const std::exception& e) {
        std::cerr << "Request failed, error: " << e.what() << '\n';
        return "";
    }
}