#pragma once
#include "main.h"

class Header
{
private:
	unsigned int entrySize;
	unsigned long long dataSize;
	unsigned long long volumeSize;
public:
	Header();
	~Header();
	unsigned int getEntrySize();
	unsigned long long getDataSize();
	unsigned long long getVolumeSize();
	void setEntrySize(unsigned int _entrySize);
	void setDataSize(unsigned long long _dataSize);
	void setVolumeSize(unsigned long long _volumeSize);
};