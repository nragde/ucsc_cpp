//#pragma once
#ifndef TOMMATSUMOTO_H
#define TOMMATSUMOTO_H

// Do the includes
#include "../util/util.h"

// Define the public and private methods for the object
class tommatsumoto {
	public:
            void find_words();
            static void read_file();
            
	private:
            //char*& _get_word();
            //int _word_value();
            //void _check_word_price(float price, int& word_counter);
            
            void _check_word_price(float price, int& word_counter, char*& word);
            float _character_price(const char cur_char);
            char _make_lower(const char cur_char);
            //int
};

#endif
