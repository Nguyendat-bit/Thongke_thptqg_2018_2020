#pragma once
//File FILE_KHOI.txt
//
/*fe
Khoi A: Toan, Vat ly, Hoa Hoc
A1: Toan, Vat ly, Tieng Anh
A2 : Toan, Vat Ly, Sinh Hoc
Khoi B.txt : Toan, Hoa hoc, Sinh hoc
Khoi C.txt : Ngu van, Lich su, Dia ly
Khoi D.txt : Ngu van, Toan con mon Ngoai ngu se khac nhau :
KHOI\\D1.txt: Ngu van, Toan, Tieng Anh
KHOI\\D2.txt : Ngu van, Toan, Tieng Nga
KHOI\\D3.txt : Ngu van, Toan, Tieng Phap
KHOI\\D4.txt : Ngu van, Toan, Tieng Trung
KHOI\\D5.txt : Ngu van, Toan, Tieng Duc
KHOI\\D6.txt : Ngu van, Toan, Tieng Nhat
KHOI\\D7.txt : Toan, Hoa Hoc, Tieng Anh
KHOI\\D8.txt : Toan, Sinh Hoc, Tieng Anh
KHOI\\C01.txt: Ngu van, Toan, Vat li
KHOI\\C02.txt: Ngu van, Toan, Hoa hoc
KHOI\\C03.txt: Ngu van, Toan, Lich su
KHOI\\C04.txt: Ngu van, Toan, Dia li
KHOI\\C05.txt: Ngu van, Vat li, Hoa hoc
KHOI\\C06.txt: Ngu van, Vat li, Sinh hoc
KHOI\\C07.txt: Ngu van, Vat li, Lich su
KHOI\\C08.txt: Ngu van, Hoa hoc, Sinh
*/
#include"Setdata.h"; 

double round2(double a)
{
	if (((int)(a * 1000)) % 10 >= 5)
	{
		return ((double)((int)(a * 100 + 1))) / 100;
	}
	else
	{
		return ((double)((int)(a * 100))) / 100;
	}
}
class Realtime
{
private:
	int n = 21,i = 0; 
	string file_dtb = "Thong_Ke\\dtb.txt";
	string diemxet;
	string file; 
	string temp;
	string a[3]{ "2018", "2019", "2020" };
	 string file_csv[3]{ "2018.csv","2019.csv","2020.csv" };
	double diem =0,diem1 =0,diem2 = 0,diem3 =0;
	string khoi[21]{ "A00","A01","A02","B00","D00","D01","D02","D03","D04","D05","D07","D08","C00","C01","C02","C03","C04","C05","C06","C07","C08"};
	string PATH_FILE[3]{ PATH_1, PATH_2,PATH_3 };
	string FILE[14]{ "KHOI\\A.txt","KHOI\\A1.txt","KHOI\\A2.txt","KHOI\\B.txt","KHOI\\D.txt","KHOI\\C.txt","KHOI\\C01.txt","KHOI\\C02.txt","KHOI\\C03.txt","KHOI\\C04.txt","KHOI\\C05.txt","KHOI\\C06.txt","KHOI\\C07.txt","KHOI\\C08.txt"};
public:
	bool checkFileWithFstream(string path) {
		ifstream isf(path);
		return isf.good();
	} 
	inline void Diemtrungbinh(int i,int j,double diem1,double diem2,double diem3) {
		string FILE_DTB = "Thong_Ke\\dtb.txt";
		double diem_file1[9], diem_file2[9], diem_file3[9], diemm ;
		string file_i1, file_i2,file_i3 = this->PATH_FILE[i] + FILE_DTB;
		string line, token;
		int pet1, pet2;
		switch (i)
		{
		case 0: {
			file_i1 = this->PATH_FILE[1] + FILE_DTB;
			file_i2 = this->PATH_FILE[2] + FILE_DTB;
			pet1 = 1;
			pet2 = 2;
		}break;
		case 1: {
			file_i1 = this->PATH_FILE[0] + FILE_DTB;
			file_i2 = this->PATH_FILE[2] + FILE_DTB;
			pet1 = 0;
			pet2 = 2;
		}break;
		case 2: {
			file_i1 = this->PATH_FILE[0] + FILE_DTB;
			file_i2 = this->PATH_FILE[1] + FILE_DTB;
			pet1 = 0;
			pet2 = 1;
		}break;
		}
		ifstream myfile1(file_i1, ios::in);
		while (!myfile1.eof()) {
			getline(myfile1, line);
			if (line != "") {
				istringstream stm(line);
				getline(stm, token, ',');
				stringstream ss(token);
				ss >> diem_file1[0];
				getline(stm, token);
				stringstream ss1(token);
				ss1 >> diem_file1[1];
				getline(stm, token, ',');
				stringstream ss2(token);
				ss2 >> diem_file1[2];
				getline(stm, token, ',');
				stringstream ss3(token);
				ss3 >> diem_file1[3];
				getline(stm, token, ',');
				stringstream ss4(token);
				ss4 >> diem_file1[4];
				getline(stm, token, ',');
				stringstream ss5(token);
				ss5 >> diem_file1[5];
				getline(stm, token, ',');
				stringstream ss6(token);
				ss6 >> diem_file1[6];
				getline(stm, token, ',');
				stringstream ss7(token);
				ss7 >> diem_file1[7];
				getline(stm, token, ',');
				stringstream ss8(token);
				ss8 >> diem_file1[8];
			}
		}



		ifstream myfile2(file_i2, ios::in);
		while (!myfile2.eof()) {
			getline(myfile2, line);
			if (line != "") {
				istringstream stm(line);
				getline(stm, token, ',');
				stringstream ss(token);
				ss >> diem_file2[0];
				getline(stm, token);
				stringstream ss1(token);
				ss1 >> diem_file2[1];
				getline(stm, token, ',');
				stringstream ss2(token);
				ss2 >> diem_file2[2];
				getline(stm, token, ',');
				stringstream ss3(token);
				ss3 >> diem_file2[3];
				getline(stm, token, ',');
				stringstream ss4(token);
				ss4 >> diem_file2[4];
				getline(stm, token, ',');
				stringstream ss5(token);
				ss5 >> diem_file2[5];
				getline(stm, token, ',');
				stringstream ss6(token);
				ss6 >> diem_file2[6];
				getline(stm, token, ',');
				stringstream ss7(token);
				ss7 >> diem_file2[7];
				getline(stm, token, ',');
				stringstream ss8(token);
				ss8 >> diem_file2[8];
			}
		}

		ifstream myfile3(file_i3, ios::in);
		while (!myfile3.eof()) {
			getline(myfile3, line);
			if (line != "") {
				istringstream stm(line);
				getline(stm, token, ',');
				stringstream ss(token);
				ss >> diem_file3[0];
				getline(stm, token);
				stringstream ss1(token);
				ss1 >> diem_file3[1];
				getline(stm, token, ',');
				stringstream ss2(token);
				ss2 >> diem_file3[2];
				getline(stm, token, ',');
				stringstream ss3(token);
				ss3 >> diem_file3[3];
				getline(stm, token, ',');
				stringstream ss4(token);
				ss4 >> diem_file3[4];
				getline(stm, token, ',');
				stringstream ss5(token);
				ss5 >> diem_file3[5];
				getline(stm, token, ',');
				stringstream ss6(token);
				ss6 >> diem_file3[6];
				getline(stm, token, ',');
				stringstream ss7(token);
				ss7 >> diem_file3[7];
				getline(stm, token, ',');
				stringstream ss8(token);
				ss8 >> diem_file3[8];
			}
		}
		for (int k = 0; k < 9; k++) {
				diem_file1[k] = diem_file1[k] - diem_file3[k];
				diem_file2[k] = diem_file2[k] - diem_file3[k];
		}
		double first, second, third;
		//toan / count1 << ',' << van / count2 << ',' << anh / count3 << ',' << ly / count4 << ',' << hoa / count5 << ',' << sinhhoc / count6 << ',' << su / count7 << ',' << dia / count8 << ',' << cd / count9
		switch (j) {
		case 0: {
			first = diem1 + diem_file1[0];
			second = diem2 + diem_file1[3];
			third = diem3 + diem_file1[4];
			out << "Diem xet tuyen khoi " << this->temp << " so voi nam " << this->a[pet1] << ": " << round2(first + second + third) << endl;
			out << "Toan: " << round2(first) << "  " << " Vat Li: " << round2(second) << "  " << " Hoa hoc: " << round2(third) << endl;
			first = diem1 + diem_file2[0];
			second = diem2 + diem_file2[3];
			third = diem3 + diem_file2[4];
			out << "Diem xet tuyen khoi " << this->temp << " so voi nam " << this->a[pet2] << ": " << round2(first + second + third) << endl;
			out << "Toan: " << round2(first) << "  " << " Vat Li: " << round2(second) << "  " << " Hoa hoc: " << round2(third) << endl;

		}; break;
		case 1: {
			first = diem1 + diem_file1[0];
			second = diem2 + diem_file1[3];
			third = diem3 + diem_file1[2];
			out << "Diem xet tuyen khoi " << this->temp << " so voi nam " << this->a[pet1] << ": " << round2(first + second + third) << endl;
			out << "Toan: " << round2(first) << "  " << " Vat Li: " << round2(second) << "  " << " Ngoai ngu: " << round2(third) << endl;
			first = diem1 + diem_file2[0];
			second = diem2 + diem_file2[3];
			third = diem3 + diem_file2[2];
			out << "Diem xet tuyen khoi " << this->temp << " so voi nam " << this->a[pet2] << ": " << round2(first + second + third) << endl;
			out << "Toan: " << round2(first) << "  " << " Vat Li: " << round2(second) << "  " << " Ngoai ngu: " << round2(third) << endl;
		}break;
		case 2: {
			first = diem1 + diem_file1[0];
			second = diem2 + diem_file1[3];
			third = diem3 + diem_file1[5];
			out << "Diem xet tuyen khoi " << this->temp << " so voi nam " << this->a[pet1] << ": " << round2(first + second + third) << endl;
			out << "Toan: " << round2(first) << "  " << " Vat Li: " << round2(second) << "  " << " Sinh hoc: " << round2(third) << endl;
			first = diem1 + diem_file1[0];
			second = diem2 + diem_file1[3];
			third = diem3 + diem_file1[5];
			out << "Diem xet tuyen khoi " << this->temp << " so voi nam " << this->a[pet2] << ": " << round2(first + second + third) << endl;
			out << "Toan: " << round2(first) << "  " << " Vat Li: " << round2(second) << "  " << " Sinh hoc: " << round2(third) << endl;
		}break;
		case 3: {
			first = diem1 + diem_file1[0];
			second = diem2 + diem_file1[4];
			third = diem3 + diem_file1[5];
			out << "Diem xet tuyen khoi " << this->temp << " so voi nam " << this->a[pet1] << ": " << round2(first + second + third) << endl;
			out << "Toan: " << round2(first) << "  " << " Hoa hoc: " << round2(second) << "  " << " Sinh hoc: " << round2(third) << endl;
			first = diem1 + diem_file2[0];
			second = diem2 + diem_file2[4];
			third = diem3 + diem_file2[5];
			out << "Diem xet tuyen khoi " << this->temp << " so voi nam " << this->a[pet2] << ": " << round2(first + second + third) << endl;
			out << "Toan: " << round2(first) << "  " << " Hoa hoc: " << round2(second) << "  " << " Sinh hoc: " << round2(third) << endl;
		}break;
		case 4: {
			first = diem1 + diem_file1[0];
			second = diem2 + diem_file1[1];
			third = diem3 + diem_file1[2];
			out << "Diem xet tuyen khoi " << this->temp << " so voi nam " << this->a[pet1] << ": " << round2(first + second + third) << endl;
			out << "Toan: " << round2(first) << "  " << " Ngu Van: " << round2(second) << "  " << " Ngoai ngu: " << round2(third) << endl;
			first = diem1 + diem_file2[0];
			second = diem2 + diem_file2[1];
			third = diem3 + diem_file2[2];
			out << "Diem xet tuyen khoi " << this->temp << " so voi nam " << this->a[pet2] << ": " << round2(first + second + third) << endl;
			out << "Toan: " << round2(first) << "  " << " Ngu Van: " << round2(second) << "  " << " Ngoai ngu: " << round2(third) << endl;
		}break;
		case 5: {
			first = diem1 + diem_file1[1];
			second = diem2 + diem_file1[6];
			third = diem3 + diem_file1[7];
			out << "Diem xet tuyen khoi " << this->temp << " so voi nam " << this->a[pet1] << ": " << round2(first + second + third) << endl;
			out << "Ngu van: " << round2(first) << "  " << " Lich su: " << round2(second) << "  " << " Dia ly: " << round2(third) << endl;
			first = diem1 + diem_file2[1];
			second = diem2 + diem_file2[6];
			third = diem3 + diem_file2[7];
			out << "Diem xet tuyen khoi " << this->temp << " so voi nam " << this->a[pet2] << ": " << round2(first + second + third) << endl;
			out << "Ngu van: " << round2(first) << "  " << " Lich su: " << round2(second) << "  " << " Dia ly: " << round2(third) << endl;
		}break;
		case 6: {
			first = diem1 + diem_file1[1];
			second = diem2 + diem_file1[0];
			third = diem3 + diem_file1[3];
			out << "Diem xet tuyen khoi " << this->temp << " so voi nam " << this->a[pet1] << ": " << round2(first + second + third) << endl;
			out << "Ngu van: " << round2(first) << "  " << " Toan: " << round2(second) << "  " << " Vat li: " << round2(third) << endl;
			first = diem1 + diem_file2[1];
			second = diem2 + diem_file2[0];
			third = diem3 + diem_file2[3];
			out << "Diem xet tuyen khoi " << this->temp << " so voi nam " << this->a[pet2] << ": " << round2(first + second + third) << endl;
			out << "Ngu van: " << round2(first) << "  " << " Toan: " << round2(second) << "  " << " Vat li: " << round2(third) << endl;
		}break;
		case 7: {
			first = diem1 + diem_file1[1];
			second = diem2 + diem_file1[0];
			third = diem3 + diem_file1[4];
			out << "Diem xet tuyen khoi " << this->temp << " so voi nam " << this->a[pet1] << ": " << round2(first + second + third) << endl;
			out << "Ngu van: " << round2(first) << "  " << " Toan: " << round2(second) << "  " << " Hoa hoc: " << round2(third) << endl;
			first = diem1 + diem_file2[1];
			second = diem2 + diem_file2[0];
			third = diem3 + diem_file2[4];
			out << "Diem xet tuyen khoi " << this->temp << " so voi nam " << this->a[pet2] << ": " << round2(first + second + third) << endl;
			out << "Ngu van: " << round2(first) << "  " << " Toan: " << round2(second) << "  " << " Hoa hoc: " << round2(third) << endl;
		}break;
		case 8: {
			first = diem1 + diem_file1[1];
			second = diem2 + diem_file1[0];
			third = diem3 + diem_file1[6];
			out << "Diem xet tuyen khoi " << this->temp << " so voi nam " << this->a[pet1] << ": " << round2(first + second + third) << endl;
			out << "Ngu van: " << round2(first) << "  " << " Toan: " << round2(second) << "  " << " Lich su: " << round2(third) << endl;
			first = diem1 + diem_file2[1];
			second = diem2 + diem_file2[0];
			third = diem3 + diem_file2[6];
			out << "Diem xet tuyen khoi " << this->temp << " so voi nam " << this->a[pet2] << ": " << round2(first + second + third) << endl;
			out << "Ngu van: " << round2(first) << "  " << " Toan: " << round2(second) << "  " << " Lich su: " << round2(third) << endl;
		}break;
		case 9: {
			first = diem1 + diem_file1[1];
			second = diem2 + diem_file1[0];
			third = diem3 + diem_file1[7];
			out << "Diem xet tuyen khoi " << this->temp << " so voi nam " << this->a[pet1] << ": " << round2(first + second + third) << endl;
			out << "Ngu van: " << round2(first) << "  " << " Toan: " << round2(second) << "  " << " Dia ly: " << round2(third) << endl;
			first = diem1 + diem_file2[1];
			second = diem2 + diem_file2[0];
			third = diem3 + diem_file2[7];
			out << "Diem xet tuyen khoi " << this->temp << " so voi nam " << this->a[pet2] << ": " << round2(first + second + third) << endl;
			out << "Ngu van: " << round2(first) << "  " << " Toan: " << round2(second) << "  " << " Dia ly: " << round2(third) << endl;
		}break;
		case 10: {
			first = diem1 + diem_file1[1];
			second = diem2 + diem_file1[3];
			third = diem3 + diem_file1[4];
			out << "Diem xet tuyen khoi " << this->temp << " so voi nam " << this->a[pet1] << ": " << round2(first + second + third) << endl;
			out << "Ngu van: " << round2(first) << "  " << " Vat Li: " << round2(second) << "  " << " Hoa hoc: " << round2(third) << endl;
			first = diem1 + diem_file2[1];
			second = diem2 + diem_file2[3];
			third = diem3 + diem_file2[4];
			out << "Diem xet tuyen khoi " << this->temp << " so voi nam " << this->a[pet2] << ": " << round2(first + second + third) << endl;
			out << "Ngu van: " << round2(first) << "  " << " Vat Li: " << round2(second) << "  " << " Hoa hoc: " << round2(third) << endl;
		}break;
		case 11: {
			first = diem1 + diem_file1[1];
			second = diem2 + diem_file1[3];
			third = diem3 + diem_file1[5];
			out << "Diem xet tuyen khoi " << this->temp << " so voi nam " << this->a[pet1] << ": " << round2(first + second + third) << endl;
			out << "Ngu van: " << round2(first) << "  " << " Vat Li: " << round2(second) << "  " << " Sinh hoc: " << round2(third) << endl;
			first = diem1 + diem_file2[1];
			second = diem2 + diem_file2[3];
			third = diem3 + diem_file2[5];
			out << "Diem xet tuyen khoi " << this->temp << " so voi nam " << this->a[pet2] << ": " << round2(first + second + third) << endl;
			out << "Ngu van: " << round2(first) << "  " << " Vat Li: " << round2(second) << "  " << " Sinh hoc: " << round2(third) << endl;
		}break;
		case 12: {
			first = diem1 + diem_file1[1];
			second = diem2 + diem_file1[3];
			third = diem3 + diem_file1[6];
			out << "Diem xet tuyen khoi " << this->temp << " so voi nam " << this->a[pet1] << ": " << round2(first + second + third) << endl;
			out << "Ngu van: " << round2(first) << "  " << " Vat Li: " << round2(second) << "  " << " Lich su: " << round2(third) << endl;
			first = diem1 + diem_file2[1];
			second = diem2 + diem_file2[3];
			third = diem3 + diem_file2[6];
			out << "Diem xet tuyen khoi " << this->temp << " so voi nam " << this->a[pet2] << ": " << round2(first + second + third) << endl;
			out << "Ngu van: " << round2(first) << "  " << " Vat Li: " << round2(second) << "  " << " Lich su: " << round2(third) << endl;
		}break;
		case 13: {
			first = diem1 + diem_file1[1];
			second = diem2 + diem_file1[4];
			third = diem3 + diem_file1[5];
			out << "Diem xet tuyen khoi " << this->temp << " so voi nam " << this->a[pet1] << ": " << round2(first + second + third) << endl;
			out << "Ngu van: " << round2(first) << "  " << " Hoa hoc: " << round2(second) << "  " << " Sinh hoc: " << round2(third) << endl;
			first = diem1 + diem_file2[1];
			second = diem2 + diem_file2[4];
			third = diem3 + diem_file2[5];
			out << "Diem xet tuyen khoi " << this->temp << " so voi nam " << this->a[pet2] << ": " << round2(first + second + third) << endl;
			out << "Ngu van: " << round2(first) << "  " << " Hoa hoc: " << round2(second) << "  " << " Sinh hoc: " << round2(third) << endl;
		}break;
		}
		system("pause");
	}
	Realtime() {
		for (int i = 0; i < 13; i++)
		{
			if (!checkFileWithFstream(PATH_1 + this->FILE[i])) {
				out << PATH_1 + this->FILE[i] << " does not exits" << endl; 
				out << "Wait" << endl; 
				this->file = file_csv[0];
				switch (i)
				{
				case 0:this->Set_A(PATH_1 + this->FILE[i]); break;
				case 1:this->Set_A1(PATH_1 + this->FILE[i]); break;
				case 2:this->Set_A2(PATH_1 + this->FILE[i]); break;
				case 3:this->Set_B(PATH_1 + this->FILE[i]); break;
				case 5:this->Set_C(PATH_1 + this->FILE[i]); break;
				case 6:this->Set_C1(PATH_1 + this->FILE[i]); break;
				case 7:this->Set_C2(PATH_1 + this->FILE[i]); break;
				case 8:this->Set_C3(PATH_1 + this->FILE[i]); break;
				case 9:this->Set_C4(PATH_1 + this->FILE[i]); break;
				case 10:this->Set_C5(PATH_1 + this->FILE[i]); break;
				case 11:this->Set_C6(PATH_1 + this->FILE[i]); break;
				case 12:this->Set_C7(PATH_1 + this->FILE[i]); break;
				case 13:this->Set_C8(PATH_1 + this->FILE[i]); break;
				case 4:this->Set_D(PATH_1 + this->FILE[i]); break;
				}
				out << "Complete !!!" << endl; 
			}
			if (!checkFileWithFstream(PATH_2 + this->FILE[i])) {
				out << PATH_2 + this->FILE[i] << " does not exits" << endl;
				out << "Wait" << endl;
				this->file = file_csv[1];
				switch (i)
				{
				case 0:this->Set_A(PATH_2 + this->FILE[i]); break;
				case 1:this->Set_A1(PATH_2 + this->FILE[i]); break;
				case 2:this->Set_A2(PATH_2 + this->FILE[i]); break;
				case 3:this->Set_B(PATH_2 + this->FILE[i]); break;
				case 5:this->Set_C(PATH_2 + this->FILE[i]); break;
				case 6:this->Set_C1(PATH_2 + this->FILE[i]); break;
				case 7:this->Set_C2(PATH_2 + this->FILE[i]); break;
				case 8:this->Set_C3(PATH_2 + this->FILE[i]); break;
				case 9:this->Set_C4(PATH_2 + this->FILE[i]); break;
				case 10:this->Set_C5(PATH_2 + this->FILE[i]); break;
				case 11:this->Set_C6(PATH_2 + this->FILE[i]); break;
				case 12:this->Set_C7(PATH_2 + this->FILE[i]); break;
				case 13:this->Set_C8(PATH_2 + this->FILE[i]); break;
				case 4:this->Set_D(PATH_2 + this->FILE[i]); break;
				}
				out << "Complete !!!" << endl;
			}
			if (!checkFileWithFstream(PATH_3 + this->FILE[i])) {
				out << PATH_3 + this->FILE[i] << " does not exits" << endl;
				out << "Wait" << endl;
				this->file = file_csv[2];
				switch (i)
				{
				case 0:this->Set_A(PATH_3 + this->FILE[i]); break;
				case 1:this->Set_A1(PATH_3 + this->FILE[i]); break;
				case 2:this->Set_A2(PATH_3 + this->FILE[i]); break;
				case 3:this->Set_B(PATH_3 + this->FILE[i]); break;
				case 5:this->Set_C(PATH_3 + this->FILE[i]); break;
				case 6:this->Set_C1(PATH_3 + this->FILE[i]); break;
				case 7:this->Set_C2(PATH_3 + this->FILE[i]); break;
				case 8:this->Set_C3(PATH_3 + this->FILE[i]); break;
				case 9:this->Set_C4(PATH_3 + this->FILE[i]); break;
				case 10:this->Set_C5(PATH_3 + this->FILE[i]); break;
				case 11:this->Set_C6(PATH_3 + this->FILE[i]); break;
				case 12:this->Set_C7(PATH_3 + this->FILE[i]); break;
				case 13:this->Set_C8(PATH_3 + this->FILE[i]); break;
				case 4:this->Set_D(PATH_3 + this->FILE[i]); break;
				}
				out << "Complete !!!" << endl;
			}
		}
	}
	void Set_A(string path) {
		ifstream myfile(this->file, ios::in);
		ofstream myfile_o(path, ios::app);
		string line, token;
		string ID;
		int count = 0;
		while (!myfile.eof())
		{
			getline(myfile, line);
			count++;
			if (count != 1 && line != "")
			{
				istringstream stm(line);

				getline(stm, token, ',');
				getline(stm, token, ',');
				//id
				ID = token;
				getline(stm, token, ',');
				//diali
				getline(stm, token, ',');
				//gdcd
				getline(stm, token, ',');
				//
				//hoahoc
				if (token != "") {
					stringstream ss2(token);
					ss2 >> this->diem3;
				}
				getline(stm, token, ',');
				//khtn
				getline(stm, token, ',');
				//khxh
				getline(stm, token, ',');
				//lichsu
				getline(stm, token, ',');
				//
				//NGOAI_NGU = token;
				getline(stm, token, ',');
				//NGU_VAN = token;
				getline(stm, token, ',');
				//sinhhoc

				getline(stm, token, ',');
				//TOAN = token;
				if (token != "") {
					stringstream ss(token);
					ss >> this->diem1;
				}
				getline(stm, token, ',');
				//vatli
				if (token != "") {
					stringstream ss1(token);
					ss1 >> this->diem2;
				}
				myfile_o << round2(this->diem1 + this->diem2 + this->diem3) << ',' << ID  << endl; 
			}
		}
	}
	void Set_A1(string path) {
		ifstream myfile(this->file, ios::in);
		ofstream myfile_o(path, ios::app);
		string line, token,ID;
		int count = 0;
		while (!myfile.eof())
		{
			getline(myfile, line);
			count++;
			if (count != 1&&line != "")
			{
				istringstream stm(line);

				getline(stm, token, ',');
				getline(stm, token, ',');
				//id
				ID = token;
				getline(stm, token, ',');
				//diali
				getline(stm, token, ',');
				//gdcd
				getline(stm, token, ',');
				//
				//hoahoc
				
				getline(stm, token, ',');
				//khtn
				getline(stm, token, ',');
				//khxh
				getline(stm, token, ',');
				//lichsu
				getline(stm, token, ',');
				//
				//NGOAI_NGU = token;
				if (token != "") {
					stringstream ss2(token);
					ss2 >> this->diem3;
				}
				getline(stm, token, ',');
				//NGU_VAN = token;
				getline(stm, token, ',');
				//sinhhoc

				getline(stm, token, ',');
				//TOAN = token;
				if (token != "") {
					stringstream ss(token);
					ss >> this->diem1;
				}
				getline(stm, token, ',');
				//vatli
				if (token != "") {
					stringstream ss1(token);
					ss1 >> this->diem2;
				}
				myfile_o << round2(this->diem1 + this->diem2 + this->diem3)<< ',' << ID << endl;
			}
		}
	}
	void Set_A2(string path) {
		ifstream myfile(this->file, ios::in);
		ofstream myfile_o(path, ios::app);
		string line, token,ID;
		int count = 0;
		while (!myfile.eof())
		{
			getline(myfile, line);
			count++;
			if (count != 1 && line != "")
			{
				istringstream stm(line);

				getline(stm, token, ',');
				getline(stm, token, ',');
				//id
				ID = token;
				getline(stm, token, ',');
				//diali
				getline(stm, token, ',');
				//gdcd
				getline(stm, token, ',');
				//
				//hoahoc

				getline(stm, token, ',');
				//khtn
				getline(stm, token, ',');
				//khxh
				getline(stm, token, ',');
				//lichsu
				getline(stm, token, ',');
				//
				//NGOAI_NGU = token;
				
				getline(stm, token, ',');
				//NGU_VAN = token;
				getline(stm, token, ',');
				//sinhhoc
				if (token != "") {
					stringstream ss2(token);
					ss2 >> this->diem3;
				}
				getline(stm, token, ',');
				//TOAN = token;
				if (token != "") {
					stringstream ss(token);
					ss >> this->diem1;
				}
				getline(stm, token, ',');
				//vatli
				if (token != "") {
					stringstream ss1(token);
					ss1 >> this->diem2;
				}
				myfile_o << round2(this->diem1 + this->diem2 + this->diem3) << ',' << ID << endl;
			}
		}
	}
	void Set_B(string path) {
		ifstream myfile(this->file, ios::in);
		ofstream myfile_o(path, ios::app);
		string line, token,ID;
		int count = 0;
		while (!myfile.eof())
		{
			getline(myfile, line);
			count++;
			if (count != 1 && line != "")
			{
				istringstream stm(line);

				getline(stm, token, ',');
				getline(stm, token, ',');
				//id
				ID = token;
				getline(stm, token, ',');
				//diali
				getline(stm, token, ',');
				//gdcd
				getline(stm, token, ',');
				//
				//hoahoc
				if (token != "") {
					stringstream ss1(token);
					ss1 >> this->diem2;
				}
				getline(stm, token, ',');
				//khtn


				getline(stm, token, ',');
				//khxh


				getline(stm, token, ',');
				//lichsu



				getline(stm, token, ',');
				//
				//NGOAI_NGU = token;


				getline(stm, token, ',');
				//NGU_VAN = token;


				getline(stm, token, ',');
				//sinhhoc
				if (token != "") {
					stringstream ss2(token);
					ss2 >> this->diem3;
				}


				getline(stm, token, ',');
				//TOAN = token;
				if (token != "") {
					stringstream ss(token);
					ss >> this->diem1;

				}

				getline(stm, token, ',');
				//vatli

				myfile_o << round2(this->diem1 + this->diem2 + this->diem3) << ',' << ID << endl;
			}
		}
	}
	void Set_C(string path) {
		ifstream myfile(this->file, ios::in);
		ofstream myfile_o(path, ios::app);
		string line, token,ID;
		int count = 0;
		while (!myfile.eof())
		{
			getline(myfile, line);
			count++;
			if (count != 1 && line != "")
			{
				istringstream stm(line);

				getline(stm, token, ',');
				getline(stm, token, ',');
				//id
				ID = token;
				getline(stm, token, ',');
				//diali
				if (token != "") {
					stringstream ss1(token);
					ss1 >> this->diem3;
				}
				getline(stm, token, ',');
				//gdcd



				getline(stm, token, ',');
				//
				//hoahoc
				
				getline(stm, token, ',');
				//khtn







				getline(stm, token, ',');
				//khxh






				getline(stm, token, ',');
				//lichsu

				if (token != "") {
					stringstream ss2(token);

					ss2 >> this->diem2;

				}


				getline(stm, token, ',');
				//NGOAI_NGU = token;







				getline(stm, token, ',');
				//NGU_VAN = token;

				if (token != "") {

					stringstream ss(token);
					ss >> this->diem1;

				}

				getline(stm, token, ',');
				//sinhhoc
				






				getline(stm, token, ',');
				//TOAN = token;






				getline(stm, token, ',');
				//vatli





				myfile_o << round2(this->diem1 + this->diem2 + this->diem3) << ',' << ID << endl;
			}
		}
	}
	void Set_C1(string path) {
		ifstream myfile(this->file, ios::in);
		ofstream myfile_o(path, ios::app);
		string line, token,ID;
		int count = 0;
		while (!myfile.eof())
		{
			getline(myfile, line);
			count++;
			if (count != 1 && line != "")
			{
				istringstream stm(line);

				getline(stm, token, ',');
				getline(stm, token, ',');
				//id
				ID = token;
				getline(stm, token, ',');
				//diali
				getline(stm, token, ',');
				//gdcd
				getline(stm, token, ',');
				//
				//hoahoc
				
				getline(stm, token, ',');
				//khtn


				getline(stm, token, ',');
				//khxh


				getline(stm, token, ',');
				//lichsu



				getline(stm, token, ',');
				//
				//NGOAI_NGU = token;


				getline(stm, token, ',');
				//NGU_VAN = token;
				if (token != "") {
					stringstream ss1(token);
					ss1 >> this->diem2;
				}
				getline(stm, token, ',');
				//sinhhoc
				



				getline(stm, token, ',');
				//TOAN = token;
				if (token != "") {
					stringstream ss(token);
					ss >> this->diem1;
				}


				getline(stm, token, ',');
				//vatli
				if (token != "") {
					stringstream ss2(token);
					ss2 >> this->diem3;
				}
				myfile_o << round2(this->diem1 + this->diem2 + this->diem3)<< ',' << ID << endl;
			}
		}
	}
		//KHOI\\C01.txt: Ngu van, Toan, Vat li
		//KHOI\\C02.txt: Ngu van, Toan, Hoa hoc
		//KHOI\\C03.txt: Ngu van, Toan, Lich su
		///KHOI\\C04.txt: Ngu van, Toan, Dia li
		//KHOI\\C05.txt: Ngu van, Vat li, Hoa hoc
		//KHOI\\C06.txt: Ngu van, Vat li, Sinh hoc
		//KHOI\\C07.txt: Ngu van, Vat li, Lich su
		//KHOI\\C08.txt: Ngu van, Hoa hoc, Sinh
	void Set_C2(string path) {
		ifstream myfile(this->file, ios::in);
		ofstream myfile_o(path, ios::app);
		string line, token,ID;
		int count = 0;
		while (!myfile.eof())
		{
			getline(myfile, line);
			count++;
			if (count != 1 && line != "")
			{
				istringstream stm(line);

				getline(stm, token, ',');
				getline(stm, token, ',');
				//id
				ID = token;
				getline(stm, token, ',');
				//diali
				getline(stm, token, ',');
				//gdcd
				getline(stm, token, ',');
				//
				//hoahoc

				if (token != "") {
					stringstream ss2(token);
					ss2 >> this->diem3;
				}
				getline(stm, token, ',');
				//khtn


				getline(stm, token, ',');
				//khxh


				getline(stm, token, ',');
				//lichsu



				getline(stm, token, ',');
				//
				//NGOAI_NGU = token;


				getline(stm, token, ',');
				//NGU_VAN = token;
				if (token != "") {
					stringstream ss1(token);
					ss1 >> this->diem2;
				}
				getline(stm, token, ',');
				//sinhhoc




				getline(stm, token, ',');
				//TOAN = token;
				if (token != "") {
					stringstream ss(token);
					ss >> this->diem1;
				}


				getline(stm, token, ',');
				//vatli
				

				myfile_o << round2(this->diem1 + this->diem2 + this->diem3) << ',' <<ID<< endl;
			}
		}
	}
	void Set_C3(string path) {
		ifstream myfile(this->file, ios::in);
		ofstream myfile_o(path, ios::app);
		string line, token,ID;
		int count = 0;
		while (!myfile.eof())
		{
			getline(myfile, line);
			count++;
			if (count != 1 && line != "")
			{
				istringstream stm(line);

				getline(stm, token, ',');
				getline(stm, token, ',');
				//id
				ID = token;
				getline(stm, token, ',');
				//diali
				getline(stm, token, ',');
				//gdcd
				getline(stm, token, ',');
				//
				//hoahoc

				getline(stm, token, ',');
				//khtn


				getline(stm, token, ',');
				//khxh


				getline(stm, token, ',');
				//lichsu
				if (token != "") {
					stringstream ss2(token);
					ss2 >> this->diem3;
				}
				getline(stm, token, ',');
				//
				//NGOAI_NGU = token;


				getline(stm, token, ',');
				//NGU_VAN = token;
				if (token != "") {
					stringstream ss1(token);
					ss1 >> this->diem2;
				}
				getline(stm, token, ',');
				//sinhhoc




				getline(stm, token, ',');
				//TOAN = token;
				if (token != "") {
					stringstream ss(token);
					ss >> this->diem1;
				}



				getline(stm, token, ',');
				//vatli
				

				myfile_o << round2(this->diem1 + this->diem2 + this->diem3)<< ',' << ID << endl;
			}
		}
	}
	void Set_C4(string path) {
		ifstream myfile(this->file, ios::in);
		ofstream myfile_o(path, ios::app);
		string line, token,ID;
		int count = 0;
		while (!myfile.eof())
		{
			getline(myfile, line);
			count++;
			if (count != 1 && line != "")
			{
				istringstream stm(line);

				getline(stm, token, ',');
				getline(stm, token, ',');
				//id
				ID = token;
				getline(stm, token, ',');
				//diali
				if (token != "") {
					stringstream ss2(token);
					ss2 >> this->diem3;
				}
				getline(stm, token, ',');
				//gdcd
				getline(stm, token, ',');
				//
				//hoahoc

				getline(stm, token, ',');
				//khtn


				getline(stm, token, ',');
				//khxh


				getline(stm, token, ',');
				//lichsu

				

				getline(stm, token, ',');
				//
				//NGOAI_NGU = token;


				getline(stm, token, ',');
				//NGU_VAN = token;
				if (token != "") {
					stringstream ss1(token);
					ss1 >> this->diem2;
				}
				getline(stm, token, ',');
				//sinhhoc




				getline(stm, token, ',');
				//TOAN = token;
				if (token != "") {
					stringstream ss(token);
					ss >> this->diem1;
				}


				getline(stm, token, ',');
				//vatli


				myfile_o << round2(this->diem1 + this->diem2 + this->diem3)<< ',' << ID << endl;
			}
		}
	}
	void Set_C5(string path) {
		ifstream myfile(this->file, ios::in);
		ofstream myfile_o(path, ios::app);
		string line, token,ID;
		int count = 0;
		while (!myfile.eof())
		{
			getline(myfile, line);
			count++;
			if (count != 1 && line != "")
			{
				istringstream stm(line);

				getline(stm, token, ',');
				getline(stm, token, ',');
				//id
				ID = token;
				getline(stm, token, ',');
				//diali
				
				getline(stm, token, ',');
				//gdcd
				getline(stm, token, ',');
				//
				//hoahoc
				if (token != "") {
					stringstream ss(token);
					ss >> this->diem1;
				}
				getline(stm, token, ',');
				//khtn


				getline(stm, token, ',');
				//khxh


				getline(stm, token, ',');
				//lichsu



				getline(stm, token, ',');
				//
				//NGOAI_NGU = token;


				getline(stm, token, ',');
				//NGU_VAN = token;
				if (token != "") {
					stringstream ss1(token);
					ss1 >> this->diem2;
				}
				getline(stm, token, ',');
				//sinhhoc




				getline(stm, token, ',');
				//TOAN = token;
				



				getline(stm, token, ',');
				//vatli
				if (token != "") {
					stringstream ss2(token);
					ss2 >> this->diem3;
				}
				myfile_o << round2(this->diem1 + this->diem2 + this->diem3) << ',' << ID << endl;
			}
		}
	}
	void Set_C6(string path) {
		ifstream myfile(this->file, ios::in);
		ofstream myfile_o(path, ios::app);
		string line, token,ID;
		int count = 0;
		while (!myfile.eof())
		{
			getline(myfile, line);
			count++;
			if (count != 1 && line != "")
			{
				istringstream stm(line);

				getline(stm, token, ',');
				getline(stm, token, ',');
				//id
				ID = token;
				getline(stm, token, ',');
				//diali

				getline(stm, token, ',');
				//gdcd
				getline(stm, token, ',');
				//
				//hoahoc
				
				getline(stm, token, ',');
				//khtn


				getline(stm, token, ',');
				//khxh


				getline(stm, token, ',');
				//lichsu



				getline(stm, token, ',');
				//
				//NGOAI_NGU = token;


				getline(stm, token, ',');
				//NGU_VAN = token;
				if (token != "") {
					stringstream ss1(token);
					ss1 >> this->diem2;
				}
				getline(stm, token, ',');
				//sinhhoc

				stringstream ss(token);
				ss >> this->diem1;


				getline(stm, token, ',');
				//TOAN = token;




				getline(stm, token, ',');
				//vatli
				if (token != "") {
					stringstream ss2(token);
					ss2 >> this->diem3;
				}
				myfile_o << round2(this->diem1 + this->diem2 + this->diem3)<< ',' << ID << endl;
			}
		}
	}
	void Set_C7(string path) {
		ifstream myfile(this->file, ios::in);
		ofstream myfile_o(path, ios::app);
		string line, token,ID;
		int count = 0;
		while (!myfile.eof())
		{
			getline(myfile, line);
			count++;
			if (count != 1 && line != "")
			{
				istringstream stm(line);

				getline(stm, token, ',');
				getline(stm, token, ',');
				//id
				ID = token;
				getline(stm, token, ',');
				//diali

				getline(stm, token, ',');
				//gdcd
				getline(stm, token, ',');
				//
				//hoahoc

				getline(stm, token, ',');
				//khtn


				getline(stm, token, ',');
				//khxh


				getline(stm, token, ',');
				//lichsu
				if (token != "") {
					stringstream ss(token);
					ss >> this->diem1;
				}
				getline(stm, token, ',');
				//
				//NGOAI_NGU = token;


				getline(stm, token, ',');
				//NGU_VAN = token;
				if (token != "") {
					stringstream ss1(token);
					ss1 >> this->diem2;
				}
				getline(stm, token, ',');
				//sinhhoc

				


				getline(stm, token, ',');
				//TOAN = token;


				getline(stm, token, ',');
				//vatli
				if (token != "") {
					stringstream ss2(token);
					ss2 >> this->diem3;
				}
				myfile_o << round2(this->diem1 + this->diem2 + this->diem3)<< ',' << ID << endl;
			}
		}
	}
	void Set_C8(string path) {
		ifstream myfile(this->file, ios::in);
		ofstream myfile_o(path, ios::app);
		string line, token,ID;
		int count = 0;
		while (!myfile.eof())
		{
			getline(myfile, line);
			count++;
			if (count != 1 && line != "")
			{
				istringstream stm(line);

				getline(stm, token, ',');
				getline(stm, token, ',');
				//id
				ID = token;
				getline(stm, token, ',');
				//diali

				getline(stm, token, ',');
				//gdcd
				getline(stm, token, ',');
				//
				//hoahoc
				if (token != "") {
					stringstream ss(token);
					ss >> this->diem1;
				}
				getline(stm, token, ',');
				//khtn


				getline(stm, token, ',');
				//khxh


				getline(stm, token, ',');
				//lichsu

				

				getline(stm, token, ',');
				//
				//NGOAI_NGU = token;


				getline(stm, token, ',');
				//NGU_VAN = token;
				if (token != "") {
					stringstream ss1(token);
					ss1 >> this->diem2;
				}


				getline(stm, token, ',');
				//sinhhoc
				if (token != "") {
					stringstream ss2(token);
					ss2 >> this->diem3;
				}


				getline(stm, token, ',');
				//TOAN = token;


				getline(stm, token, ',');
				//vatli
				

				myfile_o << round2(this->diem1 + this->diem2 + this->diem3)<< ',' << ID << endl;
			}
		}
	}
	double to_double(string diem) {
		double k = 0;
		stringstream ss(diem);
		ss >> k;
		return k;
	}
	void Set_D(string path) {
		ifstream myfile(this->file, ios::in);
		ofstream myfile_o(path, ios::app);
		string line, token,ID;
		int count = 0;
		while (!myfile.eof())
		{
			getline(myfile, line);
			count++;
			if (count != 1 && line != "")
			{
				istringstream stm(line);

				getline(stm, token, ',');
				getline(stm, token, ',');
				//id
				ID = token;
				getline(stm, token, ',');
				//diali

				getline(stm, token, ',');
				//gdcd
				getline(stm, token, ',');
				//
				//hoahoc
				
				getline(stm, token, ',');
				//khtn


				getline(stm, token, ',');
				//khxh


				getline(stm, token, ',');
				//lichsu



				getline(stm, token, ',');
				//
				//NGOAI_NGU = token;
				if (token != "") {
					stringstream ss2(token);
					ss2 >> this->diem3;
				}

				getline(stm, token, ',');
				//NGU_VAN = token;
				if (token != "") {
					stringstream ss1(token);
					ss1 >> this->diem2;

				}

				getline(stm, token, ',');
				//sinhhoc
				



				getline(stm, token, ',');
				//TOAN = token;
				if (token != "") {
					stringstream ss(token);
					ss >> this->diem1;
				}
				getline(stm, token, ',');
				//vatli


				myfile_o << round2(this->diem1 + this->diem2 + this->diem3) << ',' << ID << endl;
			}
		}
	}
	double GET(string path,string diem_xet,double &xeph, double &duoihang,double &thisinh) {
		int count = 0; 
		double dem = 0,diem__,_diem_,xephang = 0,duoi = 0,a , b;
		string new_diem = diem_xet.substr(0, 4);
		string token,line;
		ifstream myfile(path, ios::in);
		stringstream ss(diem_xet);
		ss >> diem__;
		a = round2(diem__);
		while (!myfile.eof())
		{
			getline(myfile, line);
			
			if (line != "") {
				count++;
				istringstream stm(line);
				getline(stm, token, ',');
				if (token == new_diem)dem++;
				stringstream ss1(token);
				ss1 >> b;
				if (a > b)xephang++;
				if (a < b)duoi++;
			}
		}
		thisinh = count;
		xeph = count - xephang;
		duoihang = duoi;
		return dem;
	}
	void set_n(int n) {
		if (n == 0) {
			this->n = 12;
			this->i = 0;
		}
		else if (n == 1) {
			this->i = 4;
			this->n = 21;
		}
		else if (n == 2) {
			this->i = 0;
			this->n = 21;
		}
	}
	
	bool check(string po) {
		
		int i = this->i, n = this->n;
		for (i; i < n; i++) {
			if (po == this->khoi[i]) {
				this->temp = po;
				return true;
			}
		}
		return false;

	}
	int check_nam(string namthi) {
		int i = 0;
		while (i != 3) {
			if (namthi == this->a[i]) {
				return i;
			}
			i++;
		}
	}
	int check_num(string po){
		
		while (this->i != this->n) {
			if (po == this->khoi[i]) {
				switch (i)
				{
				case 0:return 0;
				case 1:return 1;
				case 2:return 2;
				case 3:return 3;
				case 4:case 5:case 6: case 7: case 8:case 9:case 10:case 11:return 4;
				case 12:return 12;
				case 13:return 13;
				case 14:return 14;
				case 15:return 15;
				case 16:return 16;
				case 17:return 17;
				case 18:return 18;
				case 19:return 19;
				case 20:return 20;
				}
			}
			this->i++;
		}
	}
	string get_khoi() {
		return this->temp;
	}
	void set_diemxet(string diem) {
		this->diemxet = diem;
	}
	string get_diemxet() {

	}
	void process_data(string namthi){
		double xephang = 0,duoihang = 0,thisinh = 0; 
		string path = this->PATH_FILE[this->check_nam(namthi)] + this->FILE[this->check_num(this->temp)];
		double n = this->GET(path, this->diemxet, xephang, duoihang,thisinh);
		out << "Diem xet tuyen khoi " << this->temp << ": " << this->diemxet << endl;
		out << "Diem so cua ban xep hang: " << xephang << '/' << thisinh << endl; 
		out << "Co " << duoihang << " nguoi co diem cao hon ban" << endl; 
		out << "Co " << n << " nguoi co diem bang ban" << endl; 

		
	}
	void nhap() {
		int i = this->i;
		int n = this->n;
		string khoi1; 
		for (i;i < n; i++) {
			cout << this->khoi[i] << "  "; 
		}
		out << "\nKhoi Thi: "; 
		getline(cin, khoi1);
		while (!check(khoi1)) {
			out << "Khoi thi khong ton tai !" << endl; 
			out << "Khoi thi: "; 
			getline(cin, khoi1);	
		}
	}
	
};