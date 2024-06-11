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

class _MySQL
{
public:
    static void QueryDatabase(string table, string chapter, string paragraph, string order, string parallel_plot, string epigraph, string metaphor, string irony, string similies, string narration, string plot, string foils, string dialogue, string prologue, string epilogue, string allusion, string foreshadowing, string figurative_language, string imagery, string characterization, string symbolism, string alitteration, string anchronism, string bias, string fallacy, string aphorism, string diction, string double_entendre, string epigram, string euphemism, string hyperbole, string idiom, string litotes, string malapropism, string metonymy, string oxymoron, string parable, string paradox, string parallelism, string parody, string personification, string prose, string pun, string rhetoric, string satire, string setting, string simile, string situational_irony, string soliloquy, string synecdoche, string theme, string tone, string verbal_irony, string allegory);
    static void CreateTable(string table);
    static bool ArticleExists(string article);
};