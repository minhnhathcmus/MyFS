#include "main.h"
#include <ctime>

int readBlock(void* buffer, FILE*& f)
{
	return fread(buffer, 1, SECTOR_SIZE, f);//Tra ve so byte doc duoc
}
int writeBlock(void* buffer, int block_count, FILE*& f)
{
	return fwrite(buffer, 1, block_count, f);
}
int showFormatMenu() //Ham xuat menu khi chon chuc nang dinh dang volume
{
	cout << "1. Dinh dang cho volume (full format)\n";
	cout << "2. Dinh dang nhanh (quick format)\n";
	cout << "0. Quay lai\n";
	int option;
	do
	{
		cout << "Nhap vao lua chon cua ban: ";
		cin >> option;
	} while (!(option == 1 || option == 2 || option == 0));
	return option;
}
void hashFunction(string& content, int n) //Ham bam 1 chuoi
{
	for (int i = 0; i < (int)content.length(); i++)
		content[i] = content[i] + n;
}
string getFileNameFromPath(string path)
{
	int pos = path.find_last_of('\\');
	string fileName = path.substr(pos + 1);
	return fileName;
}
void traverse(Entry entry)
{
	string fileName = getFileNameFromPath(entry.getFileName());
	cout << fileName << '\t';
	cout << entry.getDataSize() << '\t';
	Date last_modified_date = entry.getDate();
	cout << last_modified_date.day << '/' << last_modified_date.month << '/' << last_modified_date.year << '\t';
	Time last_modified_time = entry.getTime();
	cout << last_modified_time.hour << '/' << last_modified_time.minute << '/' << last_modified_time.second << '\n';
}
Date getCurrentDate()
{
	Date currentDate;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	currentDate.day = ltm->tm_mday;
	currentDate.month = ltm->tm_mon + 1;
	currentDate.year = ltm->tm_year + 1900;
	return currentDate;
}
Time getCurrentTime()
{
	Time currentTime;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	currentTime.hour = ltm->tm_hour;
	currentTime.minute = ltm->tm_min;
	currentTime.second = ltm->tm_sec;
	return currentTime;
}
void writeEntryTable(vector<Entry> entryList, FILE*& f)
{
	int writen_block_count;
	for (int i = 0; i < (int)entryList.size(); i++)
	{
		writen_block_count = sizeof(entryList[i]) / SECTOR_SIZE;
		for (int j = 0; j < writen_block_count; j++)
			writeBlock(&entryList[i], SECTOR_SIZE, f);
		writeBlock(&entryList[i], sizeof(entryList[i]) % SECTOR_SIZE, f);
	}
<<<<<<< Updated upstream
=======
}
void login() {
	Volume volume;
	volume.create(); // Neu volume co san thi doc volume do
	Header header = volume.getHeader();
	string currPass = header.getPassword();
	string pass;


	string volPath = volume.getPath();
	FILE* f = fopen(volPath.c_str(), "wb");

	if (header.getPassword() == "") {
		createPassword(f);
	}
	else {
		cout << "Nhap mat khau";
		cin >> pass;
		if (pass == currPass) {
			// Dang nhap thanh cong

			// Option doi mat khau
			changePassword(f, header);
		}
	}
	fclose(f);
}

void launch() {
	do {
		int choice;
		cout << "1. Truy cap volume." << endl;
		cout << "0. Thoat chuong trinh." << endl;
		cin >> choice;
		if (choice == 1) {
			login();
			return;
		}
		else if (choice == 0)
			return;

	} while (1);
}

void createPassword(FILE* f) {
	string password;
	cout << "Tao mat khau: ";
	cin >> password;

	hashFunction(password, 3);

	fseek(f, 0, SEEK_SET);
	fwrite(0, sizeof(password), 1, f);
}

void changePassword(FILE* f, Header header) {
	string password;
	cout << "Dat mat khau moi: ";
	cin >> password;

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
int showMainMenu()
{
	system("cls");
	cout << "1. Tao volume " << VOLUME_NAME << '\n';
	cout << "2. Dinh dang volume " << VOLUME_NAME << '\n';
	cout << "3. Thiet lap mat khau truy xuat volume " << VOLUME_NAME << '\n';
	cout << "4. Doi mat khau truy xuat volume " << VOLUME_NAME << '\n';
	cout << "5. Liet ke danh sach cac tap tin trong volume " << VOLUME_NAME << '\n';
	cout << "0. Thoat chuong trinh\n";
	int option;
	do
	{
		cout << "Nhap vao so tuong ung voi chuc nang: ";
		cin >> option;
	} while (!(0 <= option && option <= 5));
	return option;
>>>>>>> Stashed changes
}