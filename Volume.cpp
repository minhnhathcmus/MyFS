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
	string path;
	cout << "Nhap vao duong dan den noi muon tao volume: ";
	getline(cin, path);
	string volumePath = path + VOLUME_NAME;
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
	return 0;//Ma 0: tao volume thanh cong
}