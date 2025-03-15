#define my_assert(e) {std::cout << #e << ((e) ? " passed" : " failed") << std::endl;}
#include "ladder.h"
 


void test_ladder_simple(){
    std::set<std::string> word_list;
    load_words(word_list, "words.txt");
    my_assert(generate_word_ladder("hike", "like", word_list).size() == 2);
    my_assert(generate_word_ladder("tap", "cap", word_list).size() == 2);
    my_assert(generate_word_ladder("car", "bar", word_list).size() == 2);
}


void test_ladder_hard(){
    std::set<std::string> word_list;
    load_words(word_list, "words.txt");
    my_assert(generate_word_ladder("eagle", "tiger", word_list).size() == 7);
    my_assert(generate_word_ladder("dessert", "oasis", word_list).size() == 8);
    my_assert(generate_word_ladder("artist", "writer", word_list).size() == 9);  
}





int main(){
    verify_word_ladder();
    test_ladder_simple();
    test_ladder_hard();
    return 0;
}
