#define my_assert(e) {std::cout << #e << ((e) ? " passed" : " failed") << std::endl;}
#include "ladder.h"
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>





void error(string word1, string word2, string msg);

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    int str1_length = str1.length();
    int str2_length = str2.length();
    int x = 0;
    int y = 0;
    int count = 0;
    while(x < str1_length && y < str2_length){
        if(str1[x] == str2[y]){
            ++x;
            ++y;
            continue;
        }
        count += 1;
        if(count > 1){
            return false;
        }
         ++x;
         ++y;
        if(str1_length > str2_length){--y;}
        else if(str2_length > str1_length){--x;}
    }
    if(x < str1_length || y < str2_length){
        count += std::abs(str1_length - str2_length);
    }
    if(count <= d){
        return true;
    }
    return false;
}


bool is_adjacent(const string& word1, const string& word2){
    return edit_distance_within(word1, word2, 1);
}
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    std::queue<std::vector<std::string>> ladder_queue;
    ladder_queue.push({begin_word});
    std::set<std::string> visited;
    visited.insert(begin_word);

    while(!ladder_queue.empty()){
        std::vector<std::string> ladder = ladder_queue.front();
        ladder_queue.pop();
        std::string last_word = ladder.back();


        for(std::string word: word_list){
            if(is_adjacent(last_word, word)){
                if(visited.find(word) == visited.end()){
                    visited.insert(word);
                    std::vector<std::string> new_ladder = ladder;
                    new_ladder.push_back(word);
                    if(word == end_word){
                        return new_ladder;
                    }
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }
    return {};

}
void load_words(set<string> & word_list, const string& file_name){
    ifstream in(file_name);
    std::string word;
    while(in >> word){
        word_list.insert(word);
    }
}
void print_word_ladder(const vector<string>& ladder){
    if(ladder.empty()){
        std::cout << "No word ladder found." << std::endl;
    }
    for(size_t i = 0; i < ladder.size(); ++i){
        std::cout << ladder[i] << " ";
    }  
}

void verify_word_ladder(){
    std::set<std::string> word_list;
    load_words(word_list, "words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}


