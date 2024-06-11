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

// https://github.com/dafanghe/DeepSceneTextReader

#include "FoldingBooks.h"

using namespace std;
//using namespace cv;
//using namespace tensorflow;
//using namespace torch;

class _Utilities
{
public:
    static void PrintLicense();
    static string* String2Sentences(string input);
    static string* String2Words(string input);
    //static void fourPointsTransform(const Mat& frame, const Point2f vertices[], Mat& result);
    static void swap(int* a, int* b);
    static int partition(int arr[], int low, int high);
    static void quickSort(int arr[], int low, int high);
    static string* RemovePunctuationArr(string* words);
    static string* RemovePunctuationString(string sentence);
    static string ReturnPunctuation(string* words);
    static double* ParseVector(string vector);
    static double* VectorSum(double* vector_sum, double* vector);
    static double* VectorAverage(double* vector_sum, int word_count);
    static string FixWikiTableName(string title);
    static string* ArrayOfStringsToLowercase(string* words);
    static string** Create2DStringArray(unsigned int width, unsigned int height);
    static string Vector2String(double* vector);
    static string toLowerWord(string word);
    static string* toLowerWordsArr(string* words);
    static string* WordsArrPunctuationExplode(string* words);
    static string StringArray2String(string* arr);
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp);
    static void SaveResponse(string llm_model, string response);
    static void SavePrompt(string llm_model, string prompt);
    static string LoadPrompts(string llm_model);
    static string LoadResponses(string llm_model);
};