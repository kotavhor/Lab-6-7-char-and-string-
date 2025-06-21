#include <iostream>     
#include <sstream>      
#include <string>       
#include <cctype>    
#include <Windows.h>

const int MAX_WORDS = 300;  

// ‘ункци€ провер€ет, состоит ли строка только из цифр
bool isDigitsOnly(const std::string& s) {
    if (s.empty()) return false;              // пуста€ строка Ч не считаетс€
    for (char ch : s) {
        if (!isdigit(ch)) return false;       // если хот€ бы один символ Ч не цифра, возвращаем false
    }
    return true;                              // все символы Ч цифры
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string input;                        
    std::cout << "¬ведите строку: ";
    std::getline(std::cin, input);            

    for (char& ch : input) {
        if (ispunct(ch)) ch = ' ';
    }

    std::string words[MAX_WORDS];             
    bool is_digit[MAX_WORDS];                 // флаг: состоит ли слово только из цифр
    int count = 0;                            // количество считанных слов

    std::istringstream iss(input);            
    std::string word;

    while (iss >> word && count < MAX_WORDS) {
        words[count] = word;                  
        is_digit[count] = isDigitsOnly(word); // сохран€ем, состоит ли оно только из цифр
        ++count;                             
    }

    std::string result;                       // финальный результат
    std::string leftovers;                    // слова, не подошедшие под правила
    int pos = 1;                              // позици€ (нечЄтна€/чЄтна€)

    for (int i = 0; i < count; ++i) {
        if (pos % 2 == 1 && is_digit[i]) {            // если нечЄтна€ позици€ и слово Ч цифры
            result += words[i] + " ";                 
            ++pos;
        }
        else if (pos % 2 == 0 && !is_digit[i]) {     // если чЄтна€ позици€ и слово Ч не цифры
            result += words[i] + " ";                 
            ++pos;
        }
        else {
            leftovers += words[i] + " ";              // иначе Ч в конец строки
        }
    }

    result += leftovers;                              
    if (!result.empty() && result.back() == ' ')      
        result.pop_back();

    std::cout << "–езультат: " << result << std::endl;  
    return 0;                                           
}
