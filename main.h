#pragma once
#pragma pack(1)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include "Entry.h"

using namespace std;

struct EntryNode
{
	Entry item; //Chua entry cua node hien tai
	EntryNode* parent;
	vector<EntryNode*> childrenList; //Chua danh sach cac entry quan ly cac tap tin/thu muc con
									//thuoc node neu node nay la thu muc, chua danh sach rong neu node la tap tin
};

int readBlock(void*& buffer, FILE*& f);
int writeBlock(void* buffer, FILE*& f);
int showFormatMenu();
void hashFunction(string& content, int n);
string getFileNameFromPath(string path);
unsigned long long calculateDataSize(EntryNode* node);
void printTab(int number_of_tab);
void traverse(EntryNode* node/*, int number_of_tab*/);