#include "Header.h"

 
int32_t CountOfWords(char* str,char* delim) {
	int32_t count{};
	char* copy_str = new char[strlen(str) + 1];
	strcpy(copy_str, str);
	char* ptr_word = strtok(copy_str, delim);
	while (ptr_word != NULL) {
		ptr_word = strtok(NULL, " ");
		++count;
	}
	delete[] ptr_word;
	return count;
}
int32_t CountOfDiffSymbols(char* ptr_word) {
	char array_of_symbols[256]{};
	int32_t count_diff{};
	char symbol{};
	for (int32_t i{}; i < strlen(ptr_word); ++i) {
		symbol = ptr_word[i];
		++array_of_symbols[symbol];

	}
	for (int32_t i{}; i < 256; ++i) {
		if (array_of_symbols[i] != 0) {
			++count_diff;
		}
	}
	return count_diff;
}

int32_t FindMaxCountOfDiffSymbols(char* str, char* delim) {
	char* copy_str = new char[strlen(str) + 1];
	strcpy(copy_str, str);
	int32_t max_count_symbols{};
	char* ptr_word = strtok(copy_str, delim);

	char* str_max_diff_symbls = new char[255];
	strcpy(str_max_diff_symbls, ptr_word);
	while (ptr_word != NULL) {
		if (CountOfDiffSymbols(ptr_word) > CountOfDiffSymbols(str_max_diff_symbls)) {
			max_count_symbols = strlen(ptr_word);
		}
		ptr_word = strtok(NULL, delim);
	}
	delete[] copy_str;
	delete[] ptr_word;
	return max_count_symbols;
}

int32_t FindCountOfStrWithMaxDiff(char* str, char* delim) {
	char* copy_str = new char[strlen(str) + 1];
	strcpy(copy_str, str);
	int32_t max_count_symbols{ FindMaxCountOfDiffSymbols(copy_str,delim) };
	strcpy(copy_str, str);
	char* ptr_word = nullptr;
	ptr_word = strtok(copy_str, delim);
	int32_t count_of_max_str{};
	strcpy(copy_str, str);
	while (ptr_word != NULL) {
		if (CountOfDiffSymbols(ptr_word) == max_count_symbols) {
			++count_of_max_str;
		}
		ptr_word = strtok(NULL, delim);
	}
	delete[] copy_str;
	delete[] ptr_word;
	return count_of_max_str;
}

void FillArrayOfMaxDiffWords(char**& array_of_max_diff_words, char* str, char* delim) {
	int32_t max_count_symbols{ FindMaxCountOfDiffSymbols(str,delim) };
	char* ptr_word = strtok(str, delim);
	int32_t i{};
	while (ptr_word != NULL) {
		if (CountOfDiffSymbols(ptr_word) == max_count_symbols) {
			array_of_max_diff_words[i] = ptr_word;
			++i;
		}
		ptr_word = strtok(NULL, delim);
	}
	delete[] ptr_word;
}
void OutputArrayOfMaxDiffWords(char**& array_of_max_diff_words, int32_t count_of_max_str) {
	for (int32_t i{}; i < count_of_max_str; ++i) {
		if (i == count_of_max_str - 1) {
			std::cout << array_of_max_diff_words[i];
			break;
		}
		std::cout << array_of_max_diff_words[i] << ", ";
	}
}