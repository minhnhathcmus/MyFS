#pragma once
#include "main.h"

class EntryTable
{
private:
	vector<Entry> entryList; //Chua cac EntryNode cua cac Entry thuoc thu muc goc
public:
	EntryTable();
	~EntryTable();
	vector<Entry> getEntryList();
	void setEntryList(Entry entry);
};