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
#include "Utilities.h"

using namespace std;
using namespace filesystem;

string* _Utilities::ArrayOfStringsToLowercase(string* words)
{
    string* array_temp = new string[sizeof(words)];
    string temp;

    for (int x = 0; x <= sizeof(words); x++)
    {
        temp = words[x];

        for (int y = 0; y <= temp.length(); y++)
        {
            array_temp[x] += tolower(temp[y]);
        }
    }

    return array_temp;
}

string** _Utilities::Create2DStringArray(unsigned int height, unsigned int width)
{
    string** array2D = 0;
    array2D = new string*[height];

    for (int h = 0; h < height; h++)
    {
        array2D[h] = new string[width];

        for (int w = 0; w < width; w++)
        {
            // fill in some initial values
            // (filling in zeros would be more logic, but this is just for the example)
            array2D[h][w] = w + width * h;
        }
    }

    return array2D;
}

string _Utilities::FixWikiTableName(string title)
{
    string temp = "";

    for (int x = 0; x <= title.length(); x++)
    {
        if (isspace(title[x]))
        {
            temp += '_';
        }
        else
        {
            temp += tolower(title[x]);
        }
    }

    return temp;
}

string _Utilities::ReturnPunctuation(string* words)
{
    string temp;

    for (int x = 0; x <= sizeof(words); x++)
    {
        temp = words[x];

        for (int y = 0; y <= temp.length(); y++)
        {
            if (temp[y] == ',')
            {
                return "comma";
            }
            else if (temp[y] == ';')
            {
                return "semi_colon";
            }
            else if (temp[y] == '\\')
            {
                return "backslash";
            }
            else if (temp[y] == '\"')
            {
                return "quotes";
            }
            else
                return "false";
        }
    }

    return "false";
}

string _Utilities::toLowerWord(string word)
{
    string temp;

    for (int x = 0; x <= word.length(); x++)
    {
        temp += tolower(word[x]);
    }

    return temp;
}

string* _Utilities::toLowerWordsArr(string* words)
{
    string* temp = new string[sizeof(words)];

    for (int x = 0; x <= sizeof(words); x++)
    {
        temp[x] = _Utilities::toLowerWord(words[x]);
    }

    return temp;
}

string* _Utilities::WordsArrPunctuationExplode(string* words)
{
    string temp;
    string temp_str;
    string punctuation;

    for (int x = 0; x <= sizeof(words); x++)
    {
        temp = words[x];

        for (int y = 0; y <= words[x].length(); y++)
        {
            if (!ispunct(temp[y]))
            {
                temp_str += temp[y];
            }
            else
            {
                punctuation = temp[y];
                temp_str += ' ';
                temp_str += punctuation;
            }
        }
    }

    return _Utilities::String2Words(temp_str);
}

string _Utilities::StringArray2String(string* arr)
{
    string temp;

    for (int x = 0; x <= sizeof(arr); x++)
    {
        if (x == 0)
        {
            temp.append(arr[x]);
            temp.append(" ");
        }
        else
        {
            temp.append(arr[x]);

            if (x != sizeof(arr))
                temp.append(" ");
        }
    }

    return temp;
}

// Purpose: Separate text strings into individual sentences
string* _Utilities::String2Sentences(string input)
{
    string temp;
    int count = 0;
    int count1 = 0;

    for (int y = 0; y <= input.length(); y++)
    {
        if (input[y] == '.' || input[y] == '?' || input[y] == '!')
        {
            count1++;
        }
    }

    string* sentences = new string[sizeof(count1)];

    for (int x = 0; x <= input.length(); x++)
    {
        if (x == 0 && input[x] == '*' && isspace(input[x + 1]))
        {
            x++;
        }
        else if (x == 0)
        {
            temp += input[x];
        }

        if (input[x] == '.' || input[x] == '?' || input[x] == '!')
        {
            temp += input[x];
            sentences[count] = temp;
            count++;
            x++;
        }
        else if (x == input.length())
        {
            sentences[count] = temp;
            count++;
        }
        else
        {
            temp += input[x];
        }
    }

    return sentences;
}

// Purpose: Separate sentences into individual words
string* _Utilities::String2Words(string input)
{
    string temp;
    int count1 = 0;
    int count = 0;

    for (int y = 0; y <= input.length(); y++)
    {
        if (isspace(input[y]))
        {
            count1++;
        }
        if (input[y] == '.' || input[y] == '?' || input[y] == '!')
        {
            count1++;
        }
    }

    string* words = new string[count1];

    for (int x = 0; x <= input.length(); x++)
    {
        if (x == 0)
        {
            words[count] = input[x];
        }
        else if (isspace(input[x]))
        {
            count++;
        }
        else if (input[x] == '.' || input[x] == '?' || input[x] == '!')
        {
            words[count] += input[x];
        }
        else
        {
            words[count] += input[x];
        }
    }

    return words;
}

string _Utilities::Vector2String(double* vector)
{
    string vector_string = "";

    for (int x = 0; x <= sizeof(vector); x++)
    {
        vector_string += to_string(vector[x]);

        if (x != sizeof(vector))
            vector_string += " ";
    }

    return vector_string;
}

double* _Utilities::ParseVector(string vector)
{
    double* vectors = new double[300];
    int lines = 0;

    for (int x = 0; x <= vector.length(); x++)
    {
        if (x == 0)
        {
            // Get the first available position in the vector
            vectors[lines] = (double)vector[x];
        }
        else if (isalnum(vector[x]))
        {
            vectors[lines] += (double)vector[x];
        }
        else if (isspace(vector[x]) && isalnum(vector[x + 1]))
        {
            lines++;
        }
    }

    return vectors;
}

double* _Utilities::VectorSum(double* vector_sum, double* vector)
{
    double temp;
    double temp2;

    for (int x = 0; x <= sizeof(vector) / sizeof(vector[0]); x++)
    {
        temp = vector_sum[x];
        temp2 = vector[x];
        temp += temp2;
        vector_sum[x] = temp;
    }

    return vector_sum;
}

double* _Utilities::VectorAverage(double* vector_sum, int word_count)
{
    double temp;

    for (int x = 0; x <= sizeof(vector_sum) / sizeof(vector_sum[0]); x++)
    {
        temp = vector_sum[x];
        temp = temp / word_count;
        vector_sum[x] = temp;
    }

    return vector_sum;
}

// Callback function to capture the response data
size_t _Utilities::WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp)
{
    size_t realSize = size * nmemb;
    userp->append(static_cast<char*>(contents), realSize);
    return realSize;
}

void _Utilities::SaveResponse(string llm_model, string response)
{

}

void _Utilities::SavePrompt(string llm_model, string prompt)
{

}
string _Utilities::LoadPrompts(string llm_model)
{

}

string _Utilities::LoadResponses(string llm_model)
{

}

void _Utilities::PrintLicense()
{
    
}