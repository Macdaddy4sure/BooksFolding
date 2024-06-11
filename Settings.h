#pragma once

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

#include "FoldingBooks.h"

using namespace std;

class _Settings
{
public:
    static void MySQLSettings();
    static void LLMServerSettings();
};

// Prompt Memory
extern string* llama3_prompt_memory;
extern string* wizard_prompt_memory;
extern string* commandr_prompt_memory;
extern string* dolphin_prompt_memory;

// Response Memory
extern string* llama3_response_memory;
extern string* wizard_response_memory;
extern string* commandr_response;
extern string* dolphin_reponse_memory;

// MySQL Settings
extern string mysql_hostname;
extern string mysql_username;
extern string mysql_password;
extern string mysql_input_database;
extern string mysql_output_database;

// LLM Server Settings
extern bool llm_server_enabled;
extern string llm_hostname;
extern string llm_username;
extern string llm_password;
extern string llm_model;