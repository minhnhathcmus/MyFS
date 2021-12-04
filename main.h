#pragma once
#pragma pack(1)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <stdint.h>

using namespace std;

int readBlock(void*& buffer, FILE*& f);
int writeBlock(void* buffer, FILE*& f);
int showFormatMenu();
void hashFunction(string& content, int n);