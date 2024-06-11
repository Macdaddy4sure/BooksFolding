/*
    Copyright(C) 2024 Tyler Crockett | Macdaddy4sure.com

    Licensed under the Apache License, string Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, string software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, string either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include "FoldingBooks.h"
#include "MySQL.h"
#include "Settings.h"
#include "Utilities.h"

using namespace std;

void _MySQL::QueryDatabase(string table, string chapter, string paragraph, string order, string parallel_plot, string epigraph, string metaphor, string irony, string similies, string narration, string plot, string foils, string dialogue, string prologue, string epilogue, string allusion, string foreshadowing, string figurative_language, string imagery, string chararacterization, string symbolism, string alitteration, string anchronism, string bias, string fallacy, string aphorism, string diction, string double_entendre, string epigram, string euphemism, string hyperbole, string idiom, string litotes, string malapropism, string metonymy, string oxymoron, string parable, string paradox, string parallelism, string parody, string personification, string prose, string pun, string rhetoric, string satire, string setting, string simile, string situational_irony, string soliloquy, string synecdoche, string theme, string tone, string verbal_irony, string allegory)
{
    MYSQL* conn;
    MYSQL_RES* result;
    string sql1;
    string mysql_table = table;
    //mysql_table = _Utilities::FixWikiTableName(mysql_table);

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, mysql_hostname.c_str(), mysql_username.c_str(), mysql_password.c_str(), mysql_output_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        sql1 = "INSERT INTO `";
        sql1 += mysql_table.c_str();
        sql1 += "`(`chapter`, `paragraph`, `order`, `parallel_plot`, `epigraph`, `metaphor`, `irony`, `similies`, `narration`, `plot`, `foils`, `dialogue`, `prologue`, `epilogue`, `allusion`, `foreshadowing`, `figurative_language`, `imagery`, `chararacterization`, `symbolism`, `alitteration`, `anchronism`, `bias`, `fallacy`, `aphorism`, `diction`, `double_entendre`, `epigram`, `euphemism`, `hyperbole`, `idiom`, `litotes`, `malapropism`, `metonymy`, `oxymoron`, `parable`, `paradox`, `parallelism`, `parody`, `personification`, `prose`, `pun`, `rhetoric`, `satire`, `setting`, `simile`, `situational_irony`, `soliloquy`, `synecdoche`, `theme`, `tone`, `verbal_irony`, `allegory`) VALUES(\"";
        sql1 += chapter.c_str();
        sql1 += "\", \"";
        sql1 += paragraph.c_str();
        sql1 += "\", \"";
        sql1 += order.c_str();
        sql1 += "\", \"";
        sql1 += parallel_plot.c_str();
        sql1 += "\", \"";
        sql1 += epigraph.c_str();
        sql1 += "\", \"";
        sql1 += metaphor.c_str();
        sql1 += "\", \"";
        sql1 += irony.c_str();
        sql1 += "\", \"";
        sql1 += similies.c_str();
        sql1 += "\", \"";
        sql1 += narration.c_str();
        sql1 += "\", \"";
        sql1 += plot.c_str();
        sql1 += "\", \"";
        sql1 += foils.c_str();
        sql1 += "\", \"";
        sql1 += dialogue.c_str();
        sql1 += "\", \"";
        sql1 += prologue.c_str();
        sql1 += "\", \"";
        sql1 += epilogue.c_str();
        sql1 += "\", \"";
        sql1 += allusion.c_str();
        sql1 += "\", \"";
        sql1 += foreshadowing.c_str();
        sql1 += "\", \"";
        sql1 += figurative_language.c_str();
        sql1 += "\", \"";
        sql1 += imagery.c_str();
        sql1 += "\", \"";
        sql1 += chararacterization.c_str();
        sql1 += "\", \"";
        sql1 += symbolism.c_str();
        sql1 += "\", \"";
        sql1 += alitteration.c_str();
        sql1 += "\", \"";
        sql1 += anchronism.c_str();
        sql1 += "\", \"";
        sql1 += bias.c_str();
        sql1 += "\", \"";
        sql1 += fallacy.c_str();
        sql1 += "\", \"";
        sql1 += aphorism.c_str();
        sql1 += "\", \"";
        sql1 += diction.c_str();
        sql1 += "\", \"";
        sql1 += double_entendre.c_str();
        sql1 += "\", \"";
        sql1 += epigram.c_str();
        sql1 += "\", \"";
        sql1 += euphemism.c_str();
        sql1 += "\", \"";
        sql1 += hyperbole.c_str();
        sql1 += "\", \"";
        sql1 += idiom.c_str();
        sql1 += "\", \"";
        sql1 += litotes.c_str();
        sql1 += "\", \"";
        sql1 += malapropism.c_str();
        sql1 += "\", \"";
        sql1 += metonymy.c_str();
        sql1 += "\", \"";
        sql1 += oxymoron.c_str();
        sql1 += "\", \"";
        sql1 += parable.c_str();
        sql1 += "\", \"";
        sql1 += paradox.c_str();
        sql1 += "\", \"";
        sql1 += parallelism.c_str();
        sql1 += "\", \"";
        sql1 += parody.c_str();
        sql1 += "\", \"";
        sql1 += personification.c_str();
        sql1 += "\", \"";
        sql1 += prose.c_str();
        sql1 += "\", \"";
        sql1 += pun.c_str();
        sql1 += "\", \"";
        sql1 += rhetoric.c_str();
        sql1 += "\", \"";
        sql1 += satire.c_str();
        sql1 += "\", \"";
        sql1 += setting.c_str();
        sql1 += "\", \"";
        sql1 += simile.c_str();
        sql1 += "\", \"";
        sql1 += situational_irony.c_str();
        sql1 += "\", \"";
        sql1 += soliloquy.c_str();
        sql1 += "\", \"";
        sql1 += synecdoche.c_str();
        sql1 += "\", \"";
        sql1 += theme.c_str();
        sql1 += "\", \"";
        sql1 += tone.c_str();
        sql1 += "\", \"";
        sql1 += verbal_irony.c_str();
        sql1 += "\", \"";
        sql1 += allegory.c_str();
        sql1 += "\");";
        //cout << "SQL1: " << sql1 << endl;
        mysql_query(conn, sql1.c_str());
        //fprintf(stderr, "%s\n", mysql_error(conn));
        result = mysql_store_result(conn);
        mysql_close(conn);
    }
}

void _MySQL::CreateTable(string table)
{
    MYSQL* conn2;
    MYSQL_RES* result;
    string sql1;
    string mysql_table = table;

    conn2 = mysql_init(0);
    conn2 = mysql_real_connect(conn2, mysql_hostname.c_str(), mysql_username.c_str(), mysql_password.c_str(), mysql_output_database.c_str(), 3306, NULL, 0);

    if (conn2)
    {
        sql1 = "CREATE TABLE IF NOT EXISTS `";
        sql1 += mysql_table.c_str();
        sql1 += "`(`chapter` TEXT, `paragraph` TEXT, `order` TEXT, `parallel_plot` TEXT, `epigraph` TEXT, `metaphor` TEXT, `irony` TEXT, `similies` TEXT, `narration` TEXT, `plot` TEXT, `foils` TEXT, `dialogue` TEXT, `prologue` TEXT, `epilogue` TEXT, `allusion` TEXT, `foreshadowing` TEXT, `figurative_language` TEXT, `imagery` TEXT, `chararacterization` TEXT, `symbolism` TEXT, `alitteration` TEXT, `anchronism` TEXT, `bias` TEXT, `fallacy` TEXT, `aphorism` TEXT, `diction` TEXT, `double_entendre` TEXT, `epigram` TEXT, `euphemism` TEXT, `hyperbole` TEXT, `idiom` TEXT, `litotes` TEXT, `malapropism` TEXT, `metonymy` TEXT, `oxymoron` TEXT, `parable` TEXT, `paradox` TEXT, `parallelism` TEXT, `parody` TEXT, `personification` TEXT, `prose` TEXT, `pun` TEXT, `rhetoric` TEXT, `satire` TEXT, `setting` TEXT, `simile` TEXT, `situational_irony` TEXT, `soliloquy` TEXT, `synecdoche` TEXT, `theme` TEXT, `tone` TEXT, `verbal_irony` TEXT, `allegory` TEXT);";
        //cout << "sql1: " << sql1 << endl;
        mysql_query(conn2, sql1.c_str());
        mysql_close(conn2);
    }
}

bool _MySQL::ArticleExists(string article)
{
    MYSQL* conn;
    MYSQL_RES* result;
    MYSQL_ROW row;
    string sql1;
    string mysql_table = article;
    mysql_table = _Utilities::FixWikiTableName(mysql_table);

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, mysql_hostname.c_str(), mysql_username.c_str(), mysql_password.c_str(), mysql_output_database.c_str(), 3306, NULL, 0);

    if (conn)
    {
        sql1 = "SHOW TABLES;";
        mysql_query(conn, sql1.c_str());
        result = mysql_store_result(conn);

        while (row = mysql_fetch_row(result))
        {
            if (mysql_table == row[0])
            {
                mysql_close(conn);
                return true;
            }
        }

        mysql_close(conn);
        return false;
    }
    return false;
}