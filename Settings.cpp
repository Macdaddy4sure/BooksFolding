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
#include "Settings.h"

using namespace std;

void _Settings::MySQLSettings()
{
	string input;
	string input2;
	bool boolean = false;
	bool boolean2 = false;

	while (!boolean)
	{
		cout << endl;
		cout << "============ MySQL Settings ============" << endl;
		cout << "| 1. MySQL Hostname                    |" << endl;
		cout << "| 2. MySQL Username                    |" << endl;
		cout << "| 3. MySQL Password                    |" << endl;
		cout << "----------------------------------------" << endl;
		cout << "| 0. Back to main menu                 |" << endl;
		cout << "----------------------------------------" << endl;
		cout << endl;
		cout << "MySQL Settings" << endl;
		cout << "MySQL Hostname: " << mysql_hostname << endl;
		cout << "MySQL Username: " << mysql_username << endl;
		cout << "MySQL Password: " << mysql_password << endl;
		cout << endl;
		cout << "Your Selection: ";
		getline(cin, input);

		if (input == "1")
		{
			while (!boolean2)
			{
				system("cls");

				cout << endl;
				cout << "MySQL Hostname" << endl;
				cout << endl;
				cout << "Your Selection: ";
				getline(cin, input2);

				if (input2 != "")
				{
					mysql_hostname = input2;
					boolean2 = true;
				}
			}
		}
		if (input == "2")
		{
			while (!boolean2)
			{
				system("cls");

				cout << endl;
				cout << "MySQL Username" << endl;
				cout << endl;
				cout << "Your Selection: ";
				getline(cin, input2);

				if (input2 != "")
				{
					mysql_username = input2;
					boolean2 = true;
				}
			}
		}
		if (input == "3")
		{
			while (!boolean2)
			{
				system("cls");

				cout << endl;
				cout << "MySQL Password" << endl;
				cout << endl;
				cout << "Your Selection: ";
				getline(cin, input2);

				if (input2 != "")
				{
					mysql_password = input2;
					boolean2 = true;
				}
			}
		}
	}
}

void _Settings::LLMServerSettings()
{
	string input;
	string input2;
	bool boolean = false;
	bool boolean2 = false;

	while (!boolean)
	{
		system("cls");

		cout << endl;
		cout << "========== LLM Server Settings ==========" << endl;
		cout << "| 1. Server Hostname                    |" << endl;
		cout << "| 2. Server Username                    |" << endl;
		cout << "| 3. Server Password                    |" << endl;
		cout << "| 4. Set Model                          |" << endl;
		cout << "-----------------------------------------" << endl;
		cout << "| 0. Main Menu                          |" << endl;
		cout << "-----------------------------------------" << endl;
		cout << endl;
		cout << "LLM Server Settings" << endl;
		cout << "LLM Hostname: " << llm_hostname << endl;
		cout << "LLM Username: " << llm_username << endl;
		cout << "LLM Password: " << llm_password << endl;
		cout << "LLM Model: " << llm_model << endl;
		cout << endl;
		cout << "Your Selection: ";
		getline(cin, input);

		if (input == "1")
		{
			while (!boolean2)
			{
				system("cls");

				cout << "LLM Server Hostname" << endl;
				cout << endl;
				cout << "Your Selection: ";
				getline(cin, input2);

				if (input2 != "")
				{
					llm_hostname = input2;
					boolean2 = true;
				}
			}
		}
		else if (input == "2")
		{
			while (!boolean2)
			{
				system("cls");

				cout << "LLM Server Username" << endl;
				cout << endl;
				cout << "Your Selection: ";
				getline(cin, input2);

				if (input2 != "")
				{
					llm_username = input2;
					boolean2 = true;
				}
			}
		}
		else if (input == "3")
		{
			while (!boolean2)
			{
				system("cls");

				cout << "LLM Server Password" << endl;
				cout << endl;
				cout << "Your Selection: ";
				getline(cin, input2);

				if (input2 != "")
				{
					llm_password = input2;
					boolean2 = true;
				}
			}
		}
		else if (input == "4")
		{
			while (!boolean2)
			{
				system("cls");

				cout << "LLM Model" << endl;
				cout << endl;
				cout << "Your Selection: ";
				getline(cin, input2);

				if (input2 != "")
				{
					llm_model = input2;
					boolean2 = true;
				}
			}
		}
		else if (input == "0")
		{
			boolean = true;
		}
		else
		{
			cout << "Invalid Options..." << endl;
		}
	}
}