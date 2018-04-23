//#pragma once
#ifndef TOMMATSUMOTO_H
#define TOMMATSUMOTO_H

// Do the includes
#include "../util/util.h"

// Define the public and private methods for the object
class tommatsumoto {
	public:
        void find_words(const char* filename);
		void read_file(); 
	private:
		void _check_word_price(double price, int& word_counter, const char* word);
		char _make_lower(const char cur_char);
		double _character_price(const char cur_char);
		double _calc_word_price(char* word);
};

#endif
