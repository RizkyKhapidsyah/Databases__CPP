#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

class Mahasiswa
{
public:
	string nama;
	string NIM;
	string jurusan;

	Mahasiswa(string nama, string NIM, string jurusan) {
		Mahasiswa::nama = nama;
		Mahasiswa::NIM = NIM;
		Mahasiswa::jurusan = jurusan;
	}

	string stringify() {
		return "\n" + nama + " " + NIM + " " + jurusan;
	}

};

class DBase
{
public:
	ifstream in;
	ofstream out;
	string fileName;

	DBase(const char* fileName) {
		DBase::fileName = fileName;
	}

	void save(Mahasiswa data) {
		cout << data.nama << endl;
		cout << data.NIM << endl;
		cout << data.jurusan << endl;

		DBase::out.open(DBase::fileName, ios::app);
		DBase::out << data.stringify();
		DBase::out.close();
	}

	void showAll() {
		DBase::in.open(DBase::fileName, ios::in);
		string nama, NIM, jurusan;
		int index = 1;

		while (!DBase::in.eof())
		{
			DBase::in >> nama;
			DBase::in >> NIM;
			DBase::in >> jurusan;

			cout << index++ << ".\t";
			cout << nama << "\t";
			cout << NIM << "\t";
			cout << jurusan << endl;
		}
		DBase::in.close();
	}
};

int main()
{
	//Input User
	string nama, NIM, jurusan;
	
	cout << "--------------------" << endl;
	cout << "Input Data Mahasiswa" << endl;
	cout << "--------------------" << endl;
	cout << "Nama      : "; cin >> nama;
	cout << "NIM       : "; cin >> NIM;
	cout << "Jurusan   : "; cin >> jurusan;

	//Membuat Object-Object Yang Dibutuhkan
	cout << "\nData Yang Telah Dibuat\n";
	Mahasiswa dataMahasiswa = Mahasiswa("Rizky Khapidsyah", "832746823", "Tata Boga");
	DBase database = DBase("Data.txt");

	//Save Data ke database
	database.save(dataMahasiswa);

	//Tampilkan seluruh data di database
	cout << "\nData Ditampilkan\n";
	database.showAll();


	_getch();
	return 0;
}