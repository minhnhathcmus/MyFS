#define _CRT_SECURE_NO_WARNINGS
#include "Volume.h"

Volume::Volume()
{
	path = "";
	header = Header();
	entryTable;
}
Volume::~Volume()
{

}
string Volume::getPath()
{
	return path;
}
Header Volume::getHeader()
{
	return header;
}
vector<Entry> Volume::getEntryTable()
{
	return entryTable;
}
int Volume::create()
{
	system("cls");
	string inputPath;
	cout << "Nhap vao duong dan den noi muon tao volume: ";
	cin.ignore();
	getline(cin, inputPath);
	string volumePath = inputPath + VOLUME_NAME;
	FILE* f = fopen(volumePath.c_str(), "rb");
	if (f != NULL)
	{
		cout << "Volume da ton tai, khong the tao volume moi!\n";
		fclose(f);
		return 1; //Ma loi 1: volume da ton tai
	}
	f = fopen(volumePath.c_str(), "wb");
	if (f == NULL)
	{
		cout << "Duong dan khong ton tai hoac co loi khong xac dinh, khong the tao volume!\n";
		return 2; //Ma loi 2: khong the tao volume
	}
	string password;
	createPassword(f, header);

	path = volumePath;
	header = Header(password);
	entryTable;
	int writen_block_count = sizeof(header) / SECTOR_SIZE;
	for (int i = 0; i < writen_block_count; i++)
	{
		if (writeBlock(&header, SECTOR_SIZE, f) != SECTOR_SIZE)
		{
			cout << "Khong the ghi du lieu thanh cong, tao volume that bai!\n";
			fclose(f);
			return 3; //Ma loi 3: khong the ghi du lieu thanh cong
		}
	}
	if (writeBlock(&header, sizeof(header) % SECTOR_SIZE, f) != sizeof(header) % SECTOR_SIZE)
	{
		cout << "Khong the ghi du lieu thanh cong, tao volume that bai!\n";
		fclose(f);
		return 3; //Ma loi 3: khong the ghi du lieu thanh cong
	}
	cout << "Tao volume thanh cong.\n";
	fclose(f);
	return 0; //Ma 0: tao volume thanh cong
}
int Volume::fullFormat()
{
	FILE* f = fopen(path.c_str(), "wb");
	if (f == NULL)
	{
		cout << "Khong the dinh dang volume!\n";
		return 1; //Ma loi 1: khong the xoa volume cu de tao volume moi
	}
	header = Header(header.getPassword());
	entryTable.clear();
	int writen_block_count = sizeof(header) / SECTOR_SIZE;
	for (int i = 0; i < writen_block_count; i++)
	{
		if (writeBlock(&header, SECTOR_SIZE, f) != SECTOR_SIZE)
		{
			cout << "Khong the ghi du lieu thanh cong, dinh dang volume that bai!\n";
			fclose(f);
			return 3; //Ma loi 3: khong the ghi du lieu thanh cong
		}
	}
	if (writeBlock(&header, sizeof(header) % SECTOR_SIZE, f) != sizeof(header) % SECTOR_SIZE)
	{
		cout << "Khong the ghi du lieu thanh cong, dinh dang volume that bai!\n";
		fclose(f);
		return 3; //Ma loi 3: khong the ghi du lieu thanh cong
	}
	cout << "Dinh dang volume thanh cong.\n";
	fclose(f);
	return 0; //Ma 0: dinh dang volume thanh cong
}
int Volume::quickFormat()
{
	Header temp_header = header;
	FILE* f = fopen(path.c_str(), "wb");
	if (f == NULL)
	{
		cout << "Khong the dinh dang volume!\n";
		return 1; //Ma loi 1: khong the xoa volume cu de tao volume moi
	}
	header = temp_header;
	entryTable.clear();
	int writen_block_count = sizeof(header) / SECTOR_SIZE;
	for (int i = 0; i < writen_block_count; i++)
	{
		if (writeBlock(&header, SECTOR_SIZE, f) != SECTOR_SIZE)
		{
			cout << "Khong the ghi du lieu thanh cong, dinh dang volume that bai!\n";
			fclose(f);
			return 3; //Ma loi 3: khong the ghi du lieu thanh cong
		}
	}
	if (writeBlock(&header, sizeof(header) % SECTOR_SIZE, f) != sizeof(header) % SECTOR_SIZE)
	{
		cout << "Khong the ghi du lieu thanh cong, dinh dang volume that bai!\n";
		fclose(f);
		return 3; //Ma loi 3: khong the ghi du lieu thanh cong
	}
	cout << "Dinh dang volume thanh cong.\n";
	fclose(f);
	return 0; //Ma 0: dinh dang volume thanh cong
}
int Volume::format()
{
	system("cls");
	int option = showFormatMenu();
	switch (option)
	{
	case 0:
		return 0; //Ma 0: quay lai, khong dinh dang
	case 1:
	{
		fullFormat();
		return 1; //Ma 1: dinh dang cho volume (full format)
	}
	case 2:
	{
		quickFormat();
		return 2; //Ma 2: dinh dang nhanh (quick format)
	}
	default:
	{
		cout << "Loi khong xac dinh, khong the dinh dang.\n";
		return 3; //Ma 3: loi khong xac dinh, khong the dinh dang.
	}
	}
}
void Volume::list(vector<Entry> listOfEntryInRoot)
{//Liet ke danh sach tap tin/thu muc trong volume
	system("cls");
	cout << "Danh sach tap tin trong " << VOLUME_NAME << ":\n";
	for (int i = 0; i < (int)listOfEntryInRoot.size(); i++)
	{
		cout << i + 1 << '.\t';
		traverse(listOfEntryInRoot[i]);
	}
}
int Volume::importFile()
{
	system("cls");
	string sourceFilePath;
	cout << "Nhap duong dan den tap tin muon chep vao " << VOLUME_NAME << ": ";
	//cin.ignore();
	getline(cin, sourceFilePath);
	FILE* fi = fopen(sourceFilePath.c_str(), "rb");
	if (fi == NULL)
	{
		cout << "Duong dan khong ton tai hoac co loi khong xac dinh, khong the chep tap tin!\n";
		return 1; //Ma loi 1: duong dan khong ton tai hoac co loi khong xac dinh
	}
	else
	{
		string fileName = sourceFilePath.substr(sourceFilePath.find_last_of('\\') + 1); //Lay ten tap tin can chep
		string destinationFilePath = getPath() + fileName;

		for (int i = 0; i < entryTable.size(); i++)
		{
			if (entryTable[i].getFileName() == destinationFilePath)
			{
				cout << "Tap tin da ton tai trong thu muc nay, khong the chep tap tin!";
				return 2; //Ma loi 2: tap tin da ton tai trong thu muc
			}
		}

		FILE* fo = fopen(getPath().c_str(), "ab");
		if (fo == NULL)
		{
			cout << "Khong the truy xuat volume " << VOLUME_NAME << " de chep tap tin!\n";
			return 3; //Ma loi 3: khong the mo volume de chep tap tin
		}
		else
		{
			unsigned int fileSize;
			fseek(fi, 0, SEEK_END);
			fileSize = ftell(fi); //Lay duoc kich thuoc tap tin can chep
			fseek(fi, 0, SEEK_SET);
			int writen_block_count = fileSize / SECTOR_SIZE;
			if (fileSize % SECTOR_SIZE != 0)
				writen_block_count++;

			int block_count;
			char* buf = new char[SECTOR_SIZE];
			for (int i = 0; i < writen_block_count; i++)
			{
				block_count = readBlock(buf, fi);
				writeBlock(buf, block_count, fo);
			}
			delete[]buf;
			fclose(fi);

			Entry newEntry = Entry(getCurrentDate(), getCurrentTime(), fileSize,
				(unsigned short)destinationFilePath.length(), (unsigned short)0, header.getVolumeSize(),
				destinationFilePath, "");
			entryTable.push_back(newEntry);

			header.setEntrySize(header.getEntrySize() + sizeof(newEntry));
			header.setDataSize(header.getDataSize() + fileSize);
			header.setVolumeSize(header.getVolumeSize() + sizeof(newEntry) + fileSize);

			fseek(fo, 0, SEEK_SET);
			writen_block_count = sizeof(header) / SECTOR_SIZE;
			for (int i = 0; i < writen_block_count; i++)
				writeBlock(&header, SECTOR_SIZE, fo);
			writeBlock(&header, sizeof(header) % SECTOR_SIZE, fo);

			writeEntryTable(entryTable, fo);

			cout << "Chep tap tin vao volume " << VOLUME_NAME << " thanh cong.\n";
			fclose(fo);
			return 0;
		}
	}
}
void Volume::createPassword(FILE*& f, Header& header) {
	string password;
	cout << "Tao mat khau: ";
	getline(cin, password);
	cin.ignore();
	hashFunction(password, 3);
	header.setPassword(password);
	/*string buffer[] = { password };

	fseek(f, 0, SEEK_SET);
	fwrite(buffer, sizeof(password), sizeof(buffer), f);*/
}

void Volume::changePassword(FILE*& f, Header& header) {
	string password;
	cout << "Dat mat khau moi: ";
	getline(cin, password);
	cin.ignore();

	hashFunction(password, 3);
	header.setPassword(password); // Tao header moi roi chen vao

	if (f == NULL)
	{
		cout << "Khong the doi mat khau!\n";
		return;
	}

	int writen_block_count = sizeof(header) / SECTOR_SIZE;
	if (sizeof(header) % SECTOR_SIZE != 0)
		writen_block_count++;
	if (writeBlock(&header, writen_block_count, f) != 1)
	{
		cout << "Khong the ghi du lieu thanh cong, doi mat khau that bai!" << endl;
		fclose(f);
		return;
	}
	cout << "Doi mat khau thanh cong." << endl;
}