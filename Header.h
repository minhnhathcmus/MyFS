#pragma once
#include "main.h"

class Header
{
private:
	string password;
	unsigned int entrySize;
	unsigned long long dataSize;
	unsigned long long volumeSize;
public:
	Header();
	Header(string _password);
	~Header();
	string getPassword();
	unsigned int getEntrySize();
	unsigned long long getDataSize();
	unsigned long long getVolumeSize();
	void setPassword(string _password);
	void setEntrySize(unsigned int _entrySize);
	void setDataSize(unsigned long long _dataSize);
	void setVolumeSize(unsigned long long _volumeSize);
};