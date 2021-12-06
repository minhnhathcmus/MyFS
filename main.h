<<<<<<< Updated upstream
#pragma once
#pragma pack(1)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include "Entry.h"
#define VOLUME_NAME "MyFS.Dat"
#define SECTOR_SIZE 512


using namespace std;

int readBlock(void* buffer, FILE*& f);
int writeBlock(void* buffer, int block_count, FILE*& f);
int showFormatMenu();
void hashFunction(string& content, int n);
string getFileNameFromPath(string path);
void traverse(Entry entry);
Date getCurrentDate();
Time getCurrentTime();
=======
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

struct EntryNode
{
	Entry item; //Chua entry cua node hien tai
	EntryNode* parent;
	vector<EntryNode*> childrenList; //Chua danh sach cac entry quan ly cac tap tin/thu muc con
									//thuoc node neu node nay la thu muc, chua danh sach rong neu node la tap tin	
};

int readBlock(void* buffer, FILE*& f);
int writeBlock(void* buffer, int writen_block_count, FILE*& f);
int showFormatMenu();
int showMainMenu();
void hashFunction(string& content, int n);
string getFileNameFromPath(string path);
void traverse(Entry entry);
Date getCurrentDate();
Time getCurrentTime();
void launch();
void createPassword(FILE* f);
void changePassword(FILE* f, Header header);
>>>>>>> Stashed changes
void writeEntryTable(vector<Entry> entryList, FILE*& f);