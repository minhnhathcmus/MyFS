#include "Volume.h"
#define VOLUME_NAME "MyFS.Dat"

Volume::Volume()
{
	
}
Volume::~Volume()
{

}
int Volume::create()
{
	string inputPath;
	cout << "Nhap vao duong dan den noi muon tao volume: ";
	getline(cin, inputPath);
	string volumePath = inputPath + VOLUME_NAME;
	FILE* f = fopen(volumePath.c_str(), "rb");
	if (f != NULL)
	{
		cout << "Volume da ton tai, khong the tao volume moi!" << endl;
		fclose(f);
		return 1; //Ma loi 1: volume da ton tai
	}
	f = fopen(volumePath.c_str(), "wb");
	if (f == NULL)
	{
		cout << "Duong dan khong ton tai hoac co loi khong xac dinh, khong the tao volume!" << endl;
		return 2; //Ma loi 2: khong the tao volume
	}
	path = volumePath;
	header = Header();
	entryTable = EntryTable();
	if (fwrite(&header, sizeof(header), 1, f) != 1)
	{
		cout << "Khong the ghi du lieu thanh cong, tao volume that bai!" << endl;
		fclose(f);
		return 3; //Ma loi 3: khong the ghi du lieu thanh cong
	}
	cout << "Tao volume thanh cong." << endl;
	fclose(f);
	return 0; //Ma 0: tao volume thanh cong
}
int Volume::fullFormat()
{
	FILE* f = fopen(path.c_str(), "wb");
	if (f == NULL)
	{
		cout << "Khong the dinh dang volume!" << endl;
		return 1; //Ma loi 1: khong the xoa volume cu de tao volume moi
	}
	header = Header(header.getPassword());
	entryTable = EntryTable(); //Cho nay can duyet cay de xoa entry table
	if (fwrite(&header, sizeof(header), 1, f) != 1)
	{
		cout << "Khong the ghi du lieu thanh cong, dinh dang volume that bai!" << endl;
		fclose(f);
		return 3; //Ma loi 3: khong the ghi du lieu thanh cong
	}
	cout << "Dinh dang volume thanh cong." << endl;
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
	entryTable = EntryTable(); //Cho nay can duyet cay de xoa entry table
	if (fwrite(&header, sizeof(header), 1, f) != 1)
	{
		cout << "Khong the ghi du lieu thanh cong, dinh dang volume that bai!" << endl;
		fclose(f);
		return 3; //Ma loi 3: khong the ghi du lieu thanh cong
	}
	cout << "Dinh dang volume thanh cong." << endl;
	fclose(f);
	return 0; //Ma 0: dinh dang volume thanh cong
}
int Volume::format()
{
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