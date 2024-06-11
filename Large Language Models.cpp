/*
    Copyright(C) 2024 Tyler Crockett | Macdaddy4sure.com

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissionsand
    limitations under the License.
*/

/*
    Open Source Initiative OSI - The MIT License - cURL

    http://www.opensource.org/licenses/mit-license.php

    Copyright(c) 2010 - 2013 Brian Cavalier and John Hann

    Permission is hereby granted, free of charge, to any person obtaining
    a copy of this software and associated documentation files(the
        "Software"), to deal in the Software without restriction, including
        without limitation the rights to use, copy, modify, merge, publish,
        distribute, sublicense, and /or sell copies of the Software, and to
        permit persons to whom the Software is furnished to do so, subject to
        the following conditions :

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
    LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
    OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
    WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "FoldingBooks.h"
#include "Large Language Models.h"
#include "Parsers.h"
#include "Settings.h"
#include "Utilities.h"

using namespace std;

string models[] = { "dolphin-mixtral:8x7b-v2.7-fp16", "llama3:8b-instruct-q8_0", "command-r:104b", "llama3:70b-instruct", "wizardlm2:8x22b"};

// To Do:
// 1. Input handling
//  a. Spell check
//  b. Remove quotes
// 2. Output handling (json parser)

string _LLM::OllamaAPI(string model, string data)
{
    CURL* curl;
    CURLcode res;
    string response;
    bool stream = true;
    
    struct curl_slist* headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");

    curl = curl_easy_init();

    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, llm_hostname.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, _Utilities::WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
        {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }

        curl_easy_cleanup(curl);
        return response;
    }

    return response;
}
