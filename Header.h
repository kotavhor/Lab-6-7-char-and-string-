#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <cstring>

int32_t CountOfWords(char*, char* );
int32_t CountOfDiffSymbols(char* );
int32_t FindMaxCountOfDiffSymbols(char*, char*);
int32_t FindCountOfStrWithMaxDiff(char*, char*);
void FillArrayOfMaxDiffWords(char**&, char*, char* );
void OutputArrayOfMaxDiffWords(char**&, int32_t);

#endif 