#include <iostream>     
#include <sstream>      
#include <string>       
#include <cctype>    
#include <Windows.h>

const int MAX_WORDS = 300;  

// ������� ���������, ������� �� ������ ������ �� ����
bool isDigitsOnly(const std::string& s) {
    if (s.empty()) return false;              // ������ ������ � �� ���������
    for (char ch : s) {
        if (!isdigit(ch)) return false;       // ���� ���� �� ���� ������ � �� �����, ���������� false
    }
    return true;                              // ��� ������� � �����
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string input;                        
    std::cout << "������� ������: ";
    std::getline(std::cin, input);            

    for (char& ch : input) {
        if (ispunct(ch)) ch = ' ';
    }

    std::string words[MAX_WORDS];             
    bool is_digit[MAX_WORDS];                 // ����: ������� �� ����� ������ �� ����
    int count = 0;                            // ���������� ��������� ����

    std::istringstream iss(input);            
    std::string word;

    while (iss >> word && count < MAX_WORDS) {
        words[count] = word;                  
        is_digit[count] = isDigitsOnly(word); // ���������, ������� �� ��� ������ �� ����
        ++count;                             
    }

    std::string result;                       // ��������� ���������
    std::string leftovers;                    // �����, �� ���������� ��� �������
    int pos = 1;                              // ������� (��������/������)

    for (int i = 0; i < count; ++i) {
        if (pos % 2 == 1 && is_digit[i]) {            // ���� �������� ������� � ����� � �����
            result += words[i] + " ";                 
            ++pos;
        }
        else if (pos % 2 == 0 && !is_digit[i]) {     // ���� ������ ������� � ����� � �� �����
            result += words[i] + " ";                 
            ++pos;
        }
        else {
            leftovers += words[i] + " ";              // ����� � � ����� ������
        }
    }

    result += leftovers;                              
    if (!result.empty() && result.back() == ' ')      
        result.pop_back();

    std::cout << "���������: " << result << std::endl;  
    return 0;                                           
}
