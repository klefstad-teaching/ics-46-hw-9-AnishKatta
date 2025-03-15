#define my_assert(e) {std::cout << #e << ((e) ? " passed" : " failed") << std::endl;}
#include "ladder.h"
#include <queue>
#include <algorithm>
// #include <unordered_set>
#include <cmath>
#include <set>





void error(string word1, string word2, string msg);
bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    int str1_length = str1.length();
    int str2_length = str2.length();
    // if(std::abs(str1_length - str2_length) > d){
    //     return false;
    // }
    int x = 0;
    int y = 0;
    int count = 0;
    while(x < str1_length && y < str2_length){
        if(str1[x] != str2[y]){
            count += 1;
            if(count > d){return false;}
            if(str1_length > str2_length){++x;}
            else if(str2_length > str1_length){++y;}
            else{
                ++x; 
                ++y;
            }
        }else{
            ++x;
            ++y;
        }
    }
    count += std::abs(str1_length - str2_length);
    return count <= d;
}


bool is_adjacent(const string& word1, const string& word2){
    return edit_distance_within(word1, word2, 1);
}
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    std::queue<std::vector<std::string>> ladder_queue;
    ladder_queue.push({begin_word});

    std::vector<std::string> visited;
    visited.push_back(begin_word);

    //std::unordered_set<std::string> visited;
    //visited.insert(begin_word);

    while(!ladder_queue.empty()){
        std::vector<std::string> ladder = ladder_queue.front();
        ladder_queue.pop();
        std::string last_word = ladder.top();


        for(std::string word: word_list){
            if(is_adjacent(last_word, word)){
                if(std::find(visited.begin(), visited.end(), word) == visited.end()){
                    visited.push_back(word);

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
void print_word_ladder(const vector<string>& ladder);

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


