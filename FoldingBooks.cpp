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
#include "Large Language Models.h"
#include "MySQL.h"
#include "Parsers.h"
#include "Settings.h"
#include "Utilities.h"

using namespace std;

// Prompt Memory
string* llama3_prompt_memory = new string[100];
string* wizard_prompt_memory = new string[100];
string* commandr_prompt_memory = new string[100];
string* dolphin_prompt_memory = new string[100];

// Response Memory
string* llama3_response_memory = new string[100];
string* wizard_response_memory = new string[100];
string* commandr_response = new string[100];
string* dolphin_reponse_memory = new string[100];

// MySQL Settings
string mysql_hostname = "MARS.CROCKETT.AI";
string mysql_username = "tyler";
string mysql_password = "Anaheim92801%";
string mysql_input_database = "literature_fiction";
string mysql_output_database = "folded_literature_fiction";

// LLM Server Settings
string llm_hostname = "http://localhost:11434/api/generate";
string llm_username = "Tyler";
string llm_password = "Anaheim92801%";
string llm_model = "command-r-plus:104b";

// Folding Databases:
// 1. literature
// 2. literature_ancient_asia
// 3. literature_ancient_egyptian
// 4. literature_ancient_greece
// 5. literature_ancient_near_east
// 6. literature_ancient_rome
// 7. literature_anthropology
// 8. literature_articles_and_essays
// 9. literature_australia_new_zealand
// 10. literature_autobiographies
// 11. literature_christian
// 12. literature_corpus
// 13. literature_esoteric_and_occult
// 14. literature_fiction

int main()
{
    string input2;
    bool boolean1 = false;

    while (true)
    {
        system("cls");

        cout << endl;
        cout << "============== Main Menu ===============" << endl;
        cout << "| 1. Books Folding                     |" << endl;
        cout << "----------------------------------------" << endl;
        cout << "| 0.  MySQL Settings                   |" << endl;
        cout << "| 01. LLM Server Settings              |" << endl;
        cout << "----------------------------------------" << endl;
        cout << endl;
        cout << "Current Settings" << endl;
        cout << "MySQL Hostname: " << mysql_hostname << endl;
        cout << "MySQL Username: " << mysql_username << endl;
        cout << "MySQL Password: " << mysql_password << endl;
        cout << "LLM Server Hostname: " << llm_hostname << endl;
        cout << "LLM Server Username: " << llm_username << endl;
        cout << "LLM Server Password: " << llm_password << endl;
        cout << "LLM Model: " << llm_model << endl;
        cout << endl;
        cout << "Your Selection: ";
        getline(cin, input2);

        if (input2 == "1")
        {
            _AI::DatabaseSelectionMenu();
        }
    }
}

void _AI::DatabaseSelectionMenu()
{
    string input;
    bool boolean1 = false;

    while (!boolean1)
    {
        system("cls");

        cout << endl;
        cout << "======================== Databases =====================" << endl;
        cout << "| 1. literature                                        |" << endl;
        cout << "| 2. literature_americas                               |" << endl;
        cout << "| 3. literature_ancient_asia                           |" << endl;
        cout << "| 4. literature_ancient_egyptian                       |" << endl;
        cout << "| 5. literature_ancient_greece                         |" << endl;
        cout << "| 6. literature_ancient_near_east                      |" << endl;
        cout << "| 7. literature_ancient_rome                           |" << endl;
        cout << "| 8. literature_anthropology                           |" << endl;
        cout << "| 9. literature_articles_and_essays                    |" << endl;
        cout << "| 10. literature_australia_new_zealand                 |" << endl;
        cout << "| 11. literature_autobiographies                       |" << endl;
        cout << "| 12. literature_christian                             |" << endl;
        cout << "| 13. literature_corpus                                |" << endl;
        cout << "| 14. literature_esoteric_and_occult                   |" << endl;
        cout << "| 15. literature_fiction                               |" << endl;
        cout << "| 16. literature_great_britain                         |" << endl;
        cout << "| 17. literature_humorous_non_fiction                  |" << endl;
        cout << "| 18. literature_law_and_crime                         |" << endl;
        cout << "| 19. literature_law_of_attraction                     |" << endl;
        cout << "| 20. literature_military_and_war                      |" << endl;
        cout << "| 21. literature_miscellaneous                         |" << endl;
        cout << "| 22. literature_philosophy_and_ethics                 |" << endl;
        cout << "| 23. literature_poetry                                |" << endl;
        cout << "| 24. literature_politics_and_society                  |" << endl;
        cout << "| 25. literature_prophecies                            |" << endl;
        cout << "| 26. literature_psychology                            |" << endl;
        cout << "| 27. literature_science_and_natural_philosophy        |" << endl;
        cout << "| 28. literature_sexuality_and_relationships           |" << endl;
        cout << "| 29. literature_shakespere                            |" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << endl;
        cout << "Current Settings" << endl;
        cout << "MySQL Hostname: " << mysql_hostname << endl;
        cout << "MySQL Username: " << mysql_username << endl;
        cout << "MySQL Password: " << mysql_password << endl;
        cout << "LLM Server Hostname: " << llm_hostname << endl;
        cout << "LLM Server Username: " << llm_username << endl;
        cout << "LLM Server Password: " << llm_password << endl;
        cout << "LLM Model: " << llm_model << endl;
        cout << endl;
        cout << "Your Selection: ";
        getline(cin, input);

        if (input == "1")
        {
            mysql_input_database = "literature";
            mysql_output_database = "folded_literature";
            _AI::BooksList();
            _AI::LiteratureFolding();
        }
        if (input == "2")
        {
            mysql_input_database = "literature_americas";
            mysql_output_database = "folded_literature_americas";
            _AI::BooksList();
            _AI::LiteratureFolding();
        }
        if (input == "3")
        {
            mysql_input_database = "literature_ancient_asia";
            mysql_output_database = "folded_literature_ancient_asia";
            _AI::BooksList();
            _AI::LiteratureFolding();
        }
        if (input == "4")
        {
            mysql_input_database = "literature_ancient_egyptian";
            mysql_output_database = "folded_literature_ancient_egyptian";
            _AI::BooksList();
            _AI::LiteratureFolding();
        }
        if (input == "5")
        {
            mysql_input_database = "literature_ancient_greece";
            mysql_output_database = "folded_literature_ancient_greece";
            _AI::BooksList();
            _AI::LiteratureFolding();
        }
        if (input == "6")
        {
            mysql_input_database = "literature_ancient_near_east";
            mysql_output_database = "folded_literature_ancient_near_east";
            _AI::BooksList();
            _AI::LiteratureFolding();
        }
        if (input == "7")
        {
            mysql_input_database = "literature_ancient_rome";
            mysql_output_database = "folded_literature_ancient_rome";
            _AI::BooksList();
            _AI::LiteratureFolding();
        }
        if (input == "8")
        {
            mysql_input_database = "literature_anthropology";
            mysql_output_database = "folded_literature_anthropology";
            _AI::BooksList();
            _AI::LiteratureFolding();
        }
        if (input == "9")
        {
            mysql_input_database = "literature_articles_and_essays";
            mysql_output_database = "folded_literature_articles_and_essays";
            _AI::BooksList();
            _AI::LiteratureFolding();
        }
        if (input == "10")
        {
            mysql_input_database = "literature_australia_new_zealand";
            mysql_output_database = "folded_literature_australia_new_zealand";
            _AI::BooksList();
            _AI::LiteratureFolding();
        }
        if (input == "11")
        {
            mysql_input_database = "literature_autobiographies";
            mysql_output_database = "folded_literature_autobiographies";
            _AI::BooksList();
            _AI::LiteratureFolding();
        }
        if (input == "12")
        {
            mysql_input_database = "literature_christian";
            mysql_output_database = "folded_literature_christian";
            _AI::BooksList();
            _AI::LiteratureFolding();
        }
        if (input == "13")
        {
            mysql_input_database = "literature_corpus";
            mysql_output_database = "folded_literature_corpus";
            _AI::BooksList();
            _AI::LiteratureFolding();
        }
        if (input == "14")
        {
            mysql_input_database = "literature_esoteric_and_occult";
            mysql_output_database = "folded_literature_esoteric_and_occult";
            _AI::BooksList();
            _AI::LiteratureFolding();
        }
        if (input == "15")
        {
            mysql_input_database = "literature_fiction";
            mysql_output_database = "folded_literature_fiction";
            _AI::BooksList();
            _AI::LiteratureFolding();
        }
        if (input == "16")
        {
            mysql_input_database = "literature_great_britain";
            mysql_output_database = "folded_literature_great_britain";
            _AI::BooksList();
            _AI::LiteratureFolding();
        }
        if (input == "17")
        {
            mysql_input_database = "literature_humorous_non_fiction";
            mysql_output_database = "folded_literature_humorous_non_fiction";
            _AI::BooksList();
            _AI::LiteratureFolding();
        }
        if (input == "18")
        {
            mysql_input_database = "literature_law_and_crime";
            mysql_output_database = "folded_literature_law_and_crime";
            _AI::BooksList();
            _AI::LiteratureFolding();
        }
        if (input == "19")
        {
            mysql_input_database = "literature_law_of_attraction";
            mysql_output_database = "folded_literature_law_of_attraction";
            _AI::BooksList();
            _AI::LiteratureFolding();
        }
        if (input == "20")
        {
            mysql_input_database = "literature_military_and_war";
            mysql_output_database = "folded_literature_military_and_war";
            _AI::BooksList();
            _AI::LiteratureFolding();
        }
        if (input == "21")
        {
            mysql_input_database = "literature_miscellaneous";
            mysql_output_database = "folded_literature_miscellaneous";
            _AI::BooksList();
            _AI::LiteratureFolding();
        }
        if (input == "22")
        {
            mysql_input_database = "literature_philosophy_and_ethics";
            mysql_output_database = "folded_literature_philosophy_and_ethics";
            _AI::BooksList();
            _AI::LiteratureFolding();
        }
        if (input == "23")
        {
            mysql_input_database = "literature_poetry";
            mysql_output_database = "folded_literature_poetry";
            _AI::BooksList();
            _AI::LiteratureFolding();
        }
        if (input == "24")
        {
            mysql_input_database = "literature_politics_and_society";
            mysql_output_database = "folded_literature_politics_and_society";
            _AI::BooksList();
            _AI::LiteratureFolding();
        }
        if (input == "25")
        {
            mysql_input_database = "literature_prophecies";
            mysql_output_database = "folded_literature_prophecies";
            _AI::BooksList();
            _AI::LiteratureFolding();
        }
        if (input == "26")
        {
            mysql_input_database = "literature_psychology";
            mysql_output_database = "folded_literature_psychology";
            _AI::BooksList();
            _AI::LiteratureFolding();
        }
        if (input == "27")
        {
            mysql_input_database = "literature_science_and_natural_philosophy";
            mysql_output_database = "folded_literature_science_and_natural_philosophy";
            _AI::BooksList();
            _AI::LiteratureFolding();
        }
        if (input == "28")
        {
            mysql_input_database = "literature_sexuality_and_relationships";
            mysql_output_database = "folded_literature_sexuality_and_relationships";
            _AI::BooksList();
            _AI::LiteratureFolding();
        }
        if (input == "29")
        {
            mysql_input_database = "literature_shakespere";
            mysql_output_database = "folded_literature_shakespere";
            _AI::BooksList();
            _AI::LiteratureFolding();
        }
        if (input == "30")
        {

        }
    }
}

void _AI::BooksList()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* result;
    string input;
    string sql1;
    string* lines = new string[1000];
    int number = 0;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, mysql_hostname.c_str(), mysql_username.c_str(), mysql_password.c_str(), mysql_input_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        // 1. Pull article from MySQL
        sql1 = "SHOW TABLES;";
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            cout << number << ". " << row[0] << endl;
            lines[number] = row[0];
            number++;
        }
        cout << "Your Selection: ";
        getline(cin, input);

        if (input != "")
        {
            int index = stoi(input);
            string table = lines[index];
            _AI::LiteratureFoldingTable(table);
        }
    }
}

void _AI::LiteratureFolding()
{
    MYSQL* conn;
    MYSQL* conn2;
    MYSQL_ROW row;
    MYSQL_ROW row2;
    MYSQL_RES* result;
    MYSQL_RES* result2;
    string sql1;
    string sql2;
    string table;
    string chapter;
    string previous_chapter;
    string page_number;
    string paragraph;
    string book_text;
    string output;
    string order;
    string parallel_plot;
    string epigraph;
    string metaphor;
    string irony;
    string similies;
    string narration;
    string plot;
    string foils;
    string dialogue;
    string prologue;
    string epilogue;
    string allusion;
    string foreshadowing;
    string figurative_language;
    string imagery;
    string chararacterization;
    string symbolism;
    string alitteration;
    string anchronism;
    string bias;
    string fallacy;
    string aphorism;
    string diction;
    string double_entendre;
    string epigram;
    string euphemism;
    string hyperbole;
    string idiom;
    string litotes;
    string malapropism;
    string metonymy;
    string oxymoron;
    string parable;
    string paradox;
    string parallelism;
    string parody;
    string personification;
    string prose;
    string pun;
    string rhetoric;
    string satire;
    string setting;
    string simile;
    string situational_irony;
    string soliloquy;
    string synecdoche;
    string theme;
    string tone;
    string verbal_irony;
    string allegory;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, mysql_hostname.c_str(), mysql_username.c_str(), mysql_password.c_str(), mysql_input_database.c_str(), 3306, NULL, 0);
    conn2 = mysql_init(0);
    conn2 = mysql_real_connect(conn2, mysql_hostname.c_str(), mysql_username.c_str(), mysql_password.c_str(), mysql_input_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        // 1. Pull article from MySQL
        sql1 = "SHOW TABLES;";
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            if (!_MySQL::ArticleExists(row[0]))
            {
                cout << "TITLE: " << row[0] << endl;
                table = row[0];
                //table = _Utilities::FixWikiTableName(table);
                sql2 = "SELECT * FROM `";
                sql2 += table.c_str();
                sql2 += "`;";
                mysql_query(conn2, sql2.c_str());
                //fprintf(stderr, "%s\n", mysql_error(conn));
                result2 = mysql_store_result(conn2);

                while (row2 = mysql_fetch_row(result2))
                {
                    output = "Given the following paragraph of literature label literature devices: Order, parallel plot, epigraph, metaphor, irony, similies, narration, plot, foils, dialogue, prologue, epilogue, allusion, foreshadowing, figureative language, imagery, characterization, symbolism, alitteration, anachronism, bias, fallacy, aphorism, diction, double entendre, epigram, euphemism, hyperbole, idiom, litotes, malapropism, metonymy, oxymoron, parable, paradox, parallelism, parody, personinfication, prose, pun, rhetoric, satire, setting, simile, situational irony, soliloquy, synecdoche, theme, tone, verbal irony, and allegory. Make sure each device found starts with the devices then a colon and then why. Make sure to separate devices when there are two detected of the same why: \\n\\n";

                    chapter = row2[0];
                    page_number = row2[1];
                    paragraph = row2[2];
                    book_text = row2[3];

                    output += book_text + "\\n";

                    // Debug
                    //cout << "output: " << output << endl;
                    //cin.get();

                    // 3. Create string from complete article for sending a prompt to OllamaAPI and create deductive syllogisms
                    string data;
                    data = "{\"model\": \"";
                    data += llm_model;
                    data += "\", \"prompt\": \"";
                    data += output;
                    data += "\", \"stream\": false}";

                    //cout << data << endl;
                    string response = _LLM::OllamaAPI(llm_model, data);
                    response = _Parsers::JSONParser(response);
                    //cout << endl;
                    //cout << "Response: " << response << endl;
                    //cout << endl;
                    _Parsers::LLM::LiteratureParser(table, chapter, paragraph, response);

                    //previous_chapter = chapter;
                }
            }
        }
    }
}

void _AI::LiteratureFoldingTable(string table)
{
    MYSQL* conn;
    MYSQL* conn2;
    MYSQL_ROW row;
    MYSQL_ROW row2;
    MYSQL_RES* result;
    MYSQL_RES* result2;
    string sql1;
    string sql2;
    string chapter;
    string previous_chapter;
    string page_number;
    string paragraph;
    string book_text;
    string chapter2;
    string page_number2;
    string paragraph2;
    string book_text2;
    string output;
    string order;
    string parallel_plot;
    string epigraph;
    string metaphor;
    string irony;
    string similies;
    string narration;
    string plot;
    string foils;
    string dialogue;
    string prologue;
    string epilogue;
    string allusion;
    string foreshadowing;
    string figurative_language;
    string imagery;
    string chararacterization;
    string symbolism;
    string alitteration;
    string anchronism;
    string bias;
    string fallacy;
    string aphorism;
    string diction;
    string double_entendre;
    string epigram;
    string euphemism;
    string hyperbole;
    string idiom;
    string litotes;
    string malapropism;
    string metonymy;
    string oxymoron;
    string parable;
    string paradox;
    string parallelism;
    string parody;
    string personification;
    string prose;
    string pun;
    string rhetoric;
    string satire;
    string setting;
    string simile;
    string situational_irony;
    string soliloquy;
    string synecdoche;
    string theme;
    string tone;
    string verbal_irony;
    string allegory;
    bool paragraph_past = false;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, mysql_hostname.c_str(), mysql_username.c_str(), mysql_password.c_str(), mysql_input_database.c_str(), 3306, NULL, 0);
    conn2 = mysql_init(0);
    conn2 = mysql_real_connect(conn2, mysql_hostname.c_str(), mysql_username.c_str(), mysql_password.c_str(), mysql_output_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        cout << "TITLE: " << table << endl;
        //table = _Utilities::FixWikiTableName(table);
        sql1 = "SELECT * FROM `";
        sql1 += table.c_str();
        sql1 += "`;";
        mysql_query(conn, sql1.c_str());
        //fprintf(stderr, "%s\n", mysql_error(conn));
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            output = "Given the following paragraph of literature label literature devices: Order, parallel plot, epigraph, metaphor, irony, similies, narration, plot, foils, dialogue, prologue, epilogue, allusion, foreshadowing, figureative language, imagery, characterization, symbolism, alitteration, anachronism, bias, fallacy, aphorism, diction, double entendre, epigram, euphemism, hyperbole, idiom, litotes, malapropism, metonymy, oxymoron, parable, paradox, parallelism, parody, personinfication, prose, pun, rhetoric, satire, setting, simile, situational irony, soliloquy, synecdoche, theme, tone, verbal irony, and allegory. Make sure each device found starts with the device and then why. Make sure to separate devices when there are two detected of the same literature device: \\n\\n";

            chapter = row[0];
            page_number = row[1];
            paragraph = row[2];
            book_text = row[3];

            cout << table << endl;
            cout << "Chapter: " << chapter << endl;
            cout << "Page Number: " << page_number << endl;
            cout << "Paragraph: " << paragraph << endl;
            cout << book_text << endl;

            output += book_text + "\\n";

            // 3. Create string from complete article for sending a prompt to OllamaAPI and create deductive syllogisms
            string data;
            data = "{\"model\": \"";
            data += llm_model;
            data += "\", \"prompt\": \"";
            data += output;
            data += "\", \"stream\": false}";

            //cout << data << endl;
            string response = _LLM::OllamaAPI(llm_model, data);
            response = _Parsers::JSONParser(response);
            _Parsers::LLM::LiteratureParser(table, chapter, paragraph, response);

            //previous_chapter = chapter;
        }
    }
        
}