#pragma once
#pragma pack(1)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include "Entry.h"
#include "Header.h"
#define VOLUME_NAME "MyFS.Dat"
#define SECTOR_SIZE 512


using namespace std;

int readBlock(void* buffer, FILE*& f);
int writeBlock(void* buffer, int writen_block_count, FILE*& f);
int showFormatMenu();
int showMainMenu();
void hashFunction(string& content, int n);
string getFileNameFromPath(string path);
void traverse(Entry entry);
Date getCurrentDate();
Time getCurrentTime();
void writeEntryTable(vector<Entry> entryList, FILE*& f);