#include "Header.h"

int main() {
	char str[256];
	std::cout << "enter string: \n";
	std::cin.getline(str, 256);
	std::cin.ignore();
	try {
		if (strlen(str) == 0) {
			throw "your string is epmty\n";
		}
		char delim[20];
		std::cout << "enter delimiters : \n";
		std::cin.getline(delim, 20);
		int32_t count_of_words{ CountOfWords(str,delim) };

		char* copy_str = new char[strlen(str) + 1];
		strcpy(copy_str, str);
		/*int32_t max_count_symbols{};*/

		int32_t count_of_max_str{};

		char** array_of_max_diff_words = new char* [count_of_words];
		for (int32_t i{}; i < count_of_words; ++i) {
			array_of_max_diff_words[i] = new char[100] {'\0'};
		}

		//max_count_symbols = FindMaxCountOfDiffSymbols(copy_str, delim);// макс количество различных символов

		count_of_max_str = FindCountOfStrWithMaxDiff(copy_str, delim);//количество строк с макс значением различных символов

		FillArrayOfMaxDiffWords(array_of_max_diff_words, copy_str, delim);

		std::cout << "words with max count of different symbols : \n";

		OutputArrayOfMaxDiffWords(array_of_max_diff_words, count_of_max_str);

		delete[] copy_str;
	}
	catch (const char* messege) {
		std::cout << messege;
	}
	//for (int32_t i{}; i < count_of_words; ++i) {
	//	delete[] array_of_max_diff_words[i];
	//}
	//delete[] array_of_max_diff_words;

	
	return 0;
}