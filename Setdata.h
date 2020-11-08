#pragma once
// class EMTY_OR_VALUE class MATH 
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<Windows.h>

using namespace std;


#define out std::cout
#define sbd  "SBD :"
#define PATH_1  "FILE\\2018\\"
#define	PATH_2  "FILE\\2019\\"
#define PATH_3	"FILE\\2020\\"

#define Tb_liet "Khong Tot Nghiep THPT do co diem liet mon "
#define Tb_diem "Khong Tot Nghiep THPT do con thieu "



// FILE 2018->2020
// START 

//

//
class EMTY_OR_VALUE
{
private:
	string file_csv[3]{ "2018.csv","2019.csv","2020.csv" };
	string file; 
	
public:
	bool checkFileWithFstream(string path) {
		ifstream isf(path);
		return isf.good();
	}
	
	EMTY_OR_VALUE() //CHECK FILE IF IT'S NOT EXITS WITH 1 FILE 
	{
		
		int count = 0; 
		for(const auto &item:file_csv)
		if (!checkFileWithFstream(item))
		{
			out << item << ": FILE does not exits" << endl;
			count++; 
		}
		if (count) {
			system("pause");
			
			exit(1);
		}
		this->sEMTY_OR_VALUE();
	}
	void sEMTY_OR_VALUE()
	{
		string T[4] = { "FILE_ID.txt" ,"FILE_MARK_KHTN.txt","FILE_MARK_KHXH.txt" ,"FILe_BAT_BUOC.txt"};
		for (int i = 0 ; i < 4; i++)
		{
			if (!checkFileWithFstream(PATH_1 + T[i])) {
				out << PATH_1 + T[i] << " does not exits" << endl;
				out << "Wait" << endl; 
				this->file = "2018.csv";
				switch (i)
				{
				case 0: {
					this->INPUT_CODE_ID(PATH_1 + T[i]);
				}break;
				case 1: {
					this->INPUT_FILE_KHTN(PATH_1 + T[i]);
				}break;
				case 2: {
					this->INPUT_FILE_KHXH(PATH_1 + T[i]);
				}break;
				case 3: {
					this->INPUT_FILE_BAT_BUOC(PATH_1 + T[i]);
				}break;
				}
				out << "Complete !!!" << endl;
			}
		
			if (!checkFileWithFstream(PATH_2 + T[i])) {
				out << PATH_2 + T[i] << " does not exits" << endl;
				this->file = "2019.csv";
				out << "Wait" << endl;
				switch (i)
				{
				case 0: {
					this->INPUT_CODE_ID(PATH_2 + T[i]);
				}break;
				case 1: {
					this->INPUT_FILE_KHTN(PATH_2 + T[i]);
				}break;
				case 2: {
					this->INPUT_FILE_KHXH(PATH_2 + T[i]);
				}break;
				case 3: {
					this->INPUT_FILE_BAT_BUOC(PATH_2 + T[i]);
				}break;
				}
				out << "Complete !!!" << endl;
			}
		
			if (!checkFileWithFstream(PATH_3 + T[i])) {
				out << PATH_3 + T[i] << " does not exits" << endl;
				this->file = "2020.csv";
				out << "Wait" << endl;
				switch (i)
				{
				case 0: {
					this->INPUT_CODE_ID(PATH_3 + T[i]);
				}break;
				case 1: {
					this->INPUT_FILE_KHTN(PATH_3 + T[i]);
				}break;
				case 2: {
					this->INPUT_FILE_KHXH(PATH_3 + T[i]);
				}break;
				case 3: {
					this->INPUT_FILE_BAT_BUOC(PATH_3 + T[i]);
				}break;
				}
				out << "Complete !!!" << endl;
			}
		}
		
	}
	void INPUT_CODE_ID(string path ); 
	void INPUT_FILE_KHTN(string path); 
	void INPUT_FILE_KHXH(string path); 
	void INPUT_FILE_BAT_BUOC(string path);
};
inline void EMTY_OR_VALUE::INPUT_FILE_BAT_BUOC(string path)
{
	int count = 0;
	string  NGU_VAN, TOAN, NGOAI_NGU, ID;
	ofstream myfile_o(path , ios::app);
	ifstream myfile(this->file, ios::in);
	string line,token;
	while (!myfile.eof())
	{
		getline(myfile, line);
		count++;
		if (count != 1 && line != "")
		{
			istringstream stm(line);
		
			getline(stm, token, ',');
			getline(stm, token, ',');
			ID = token;
			getline(stm, token, ',');
			getline(stm, token, ',');
			getline(stm, token, ',');
			//
			
			getline(stm, token, ',');
			
			getline(stm, token, ',');
			getline(stm, token, ',');
			getline(stm, token, ',');
			NGOAI_NGU = token;
			getline(stm, token, ',');
			NGU_VAN = token;
			getline(stm, token, ',');
			//
			
			getline(stm, token, ',');
			TOAN = token;
			getline(stm, token, ',');
			//
			
			myfile_o << ID << ',' <<TOAN << ',' << NGU_VAN<< ',' << NGOAI_NGU << endl;
		}
	}
}
 inline void EMTY_OR_VALUE:: INPUT_CODE_ID(string path)              // ID -> FILE (ID)
{
	int count = 0;
	string id,TT,khtn,khxh;
	ofstream myfile_o(path , ios::app );
	
		ifstream myfile(this->file, ios::in);
		string line,token;
		while (!myfile.eof()) {
			getline(myfile, line);
			count++;
			if (count != 1 && line != "")
			{
				istringstream stm(line);
				string token;
				getline(stm, token, ',');
				getline(stm, token, ',');
				id = token; 
				getline(stm, token, ',');
				getline(stm, token, ',');
				getline(stm, token, ',');
				getline(stm, token, ',');
				khtn = token;
				getline(stm, token, ',');
				khxh = token; 
				myfile_o << id; 
				if (khtn == "" && khxh != "") {
					myfile_o << ',' << '2' ;
				}else if (khtn != "" && khxh == "") {
					myfile_o << ',' << '1' ;
				}else if (khtn != "" && khxh != "") {
					myfile_o << ',' << '3';
				}else if (khtn == "" && khxh == "") {
					myfile_o << ',' << '4';
				}
				getline(stm, token, ',');
				getline(stm, token, ',');
				getline(stm, token, ',');
				getline(stm, token, ',');
				getline(stm, token, ',');

				getline(stm, token, ',');
				getline(stm, token, ',');
				
				myfile_o << ',' << token << endl; 
			}
		}
}
inline void EMTY_OR_VALUE:: INPUT_FILE_KHTN(string path )
{
	int count = 0; 
	string VAT_LY,HOA_HOC,SINH_HOC,ID,KHTN; 
	ofstream myfile_o(path , ios::app);
	ifstream myfile(this->file, ios::in);
	string line,token;
	while (!myfile.eof())
	{
		getline(myfile, line);
		count++;
		if (count != 1 && line != "")
		{
			istringstream stm(line);
		
			getline(stm, token, ',');
			getline(stm, token, ',');
			ID = token;
			getline(stm, token, ',');
			getline(stm, token, ',');
			getline(stm, token, ',');
			//
			HOA_HOC = token;
			getline(stm, token, ',');
			KHTN = token;
			getline(stm, token, ',');
			getline(stm, token, ',');
			getline(stm, token, ',');
			getline(stm, token, ',');
			getline(stm, token, ',');
			//
			SINH_HOC = token;
			getline(stm, token, ',');

			getline(stm, token, ',');
			//
			VAT_LY = token; 
			myfile_o << ID << ',' << KHTN << ',' << VAT_LY << ',' << HOA_HOC << ',' << SINH_HOC << endl;
		}
	}
}
inline void EMTY_OR_VALUE::INPUT_FILE_KHXH(string path )
{
	int count = 0;
	
	string DIA_LI, GDCD, LICH_SU,KHXH,ID; 
	ofstream myfile_o(path,  ios::app);
	ifstream myfile(this->file, ios::in);
	string line,token;
	while (!myfile.eof())
	{
		getline(myfile, line);
		count++;
		if (count != 1 && line != "")
		{
			istringstream stm(line);
			
			getline(stm, token, ',');
			getline(stm, token, ',');
			ID = token;
			getline(stm, token, ',');
			DIA_LI = token;
			getline(stm, token, ',');
			GDCD = token;
			getline(stm, token, ',');
			//
			
			getline(stm, token, ',');
			
			getline(stm, token, ',');
			KHXH = token;
			getline(stm, token, ',');
			LICH_SU = token;
			//
			
			myfile_o << ID << ',' << KHXH << ',' << DIA_LI << ',' << GDCD << ',' << LICH_SU << endl;
		}
	}
}
typedef string Score;
typedef string Person;
class DATA_FROM_FILE_MARk
{
private:
	Score TOAN, VAT_Li, HOA_HOC, SINH_HOC, NGU_VAN,NGOAI_NGU = "" , DIA_LY, GDCD, LICH_SU, KHTN ="", KHXH ="",ma_nn = "";
	Person STUDENT_CODE_ID;
	int selection = 0; 
	string temp;
	string file[3]{ "2018.csv","2019.csv","2020.csv" };
	string a[3]{ "2018", "2019", "2020" };
	string PATH_FILE[3]{ PATH_1, PATH_2,PATH_3 };
	int k  = 0;
public:
	double to_double(string diem) {
		double k = 0; 
		stringstream ss(diem);
		ss >> k; 
		return k; 
	}
	bool check(string pathh) {
		for (int i = 0; i < 3; i++) {
			if (pathh == this->a[i]) {
				this->k = i;
				this->temp = pathh;
				return true;
			}
		}
		return false;
	}
	void nhap() {
		string pathh;
		out << "Nhap nam (2018 -> 2020): ";
		getline(cin, pathh);
		while (!this->check(pathh)) {
			out << "Moi nhap lai nam (2018 -> 2020): " << endl;
			getline(cin, pathh);
		}
	}
	string get_temp() {
		return this->temp;
	}
	void TOT_NGHIEP(double tb12,int nam = 0,int selection = 0,double khuyenkhich = 0, double uu_tien = 0) {
		double toan= 0, van = 0, anh= 0,ly =0 ,hoa = 0,sinhhoc = 0 ,su =0 ,dia = 0,cd = 0, khtn = 0, khxh = 0 ,totnghiep = 0,totnghiep1 = 0;
		int count = 0;
		// bat buoc toan van anh 
		if (this->TOAN != "") {
			toan = to_double(this->TOAN);
			totnghiep += toan;
			totnghiep1 += toan;
			if (toan <= 1) {
				count++;
				string tb = Tb_liet;
				cout << tb + " Toan" << endl;
			}
			
		}
		if (this->NGU_VAN != "") {
			van = to_double(this->NGU_VAN);
			totnghiep += van;
			totnghiep1 += van;
			if (van <= 1) {
				count++;
				string tb = Tb_liet;
				cout << tb + " Ngu Van" << endl;
			
			}
			
		}
		if(this->NGOAI_NGU != ""){
			anh = to_double(this->NGOAI_NGU);
			totnghiep += anh;
			if (anh <= 1) {
			count++;
			string tb = Tb_liet;
			cout << tb + " Ngoai ngu" << endl;
			
			}
			
		}
		
		if (this->KHXH == "" && this->KHTN == "") {
			su = to_double(this->LICH_SU);
			dia = to_double(this->DIA_LY);
			if (this->LICH_SU == "" && this->DIA_LY != "") {
				totnghiep1 += dia;
				if (dia <= 1) {
					count++;
					string tb = Tb_liet;
					cout << tb + " Dia li" << endl;
				}
			}else
			if (this->LICH_SU != "" && this->DIA_LY == "") {
				totnghiep1 += su;
				if (su <= 1) {
					count++;
					string tb = Tb_liet;
					cout << tb + " Lich Su" << endl;
				}
			}
			if (this->LICH_SU != "" && this->DIA_LY != "") {
				double temppp = 0; 
				if (su > dia)temppp = su;
				else if (dia > su)temppp = dia;
				totnghiep1 += temppp;
				if (dia <= 1 && su <= 1) {
					count++;
					string tb = Tb_liet;
					cout << tb + " Dia li" << endl;
					cout << tb + " Lich Su" << endl;
				}
			}
		}
		if (this->KHXH == "" && this->KHTN == "")
		{
			khtn = to_double(this->KHTN);
			khxh = to_double(this->KHXH);
			if (khtn > khxh) {
				totnghiep += khtn;
				ly = to_double(this->VAT_Li);
				if (ly <= 1) {
					count++;
					string tb = Tb_liet;
					cout << tb + " Vat ly" << endl;
				}
				hoa = to_double(this->HOA_HOC);
				if (hoa <= 1) {
					count++;
					string tb = Tb_liet;
					cout << tb + " Hoa Hoc" << endl;
				}
				sinhhoc = to_double(this->SINH_HOC);
				if (sinhhoc <= 1) {
					count++;
					string tb = Tb_liet;
					cout << tb + " Sinh Hoc" << endl;
				}

			}
			else if (khxh > khtn) {
					totnghiep += khxh;
					cd = to_double(this->GDCD);
					if (cd <= 1) {
						count++;
						string tb = Tb_liet;
						cout << tb + " GDCD" << endl;
					}
					if (dia <= 1) {
						count++;
						string tb = Tb_liet;
						cout << tb + " Dia li" << endl;
					}
					if (su <= 1) {
						count++;
						string tb = Tb_liet;
						cout << tb + " Lich Su" << endl;
					}
			}
		}
		if (this->KHTN != "" && this->KHXH == "") {
			khtn = to_double(this->KHTN);
			totnghiep += khtn;
			ly = to_double(this->VAT_Li);
			if (ly <= 1) {
				count++;
				string tb = Tb_liet;
				cout << tb + " Vat ly" << endl;
			}
			hoa = to_double(this->HOA_HOC);
			if (hoa <= 1) {
				count++;
				string tb = Tb_liet;
				cout << tb + " Hoa Hoc" << endl;
			}
			sinhhoc = to_double(this->SINH_HOC);
			if (sinhhoc <= 1) {
				count++;
				string tb = Tb_liet;
				cout << tb + " Sinh Hoc" << endl;
				
			}
			
		}
		if (this->KHXH != "" && this->KHTN == "") {
			khxh = to_double(this->KHXH);
			totnghiep += khxh;
			cd = to_double(this->GDCD);
			if (cd <= 1) {
				count++;
				string tb = Tb_liet;
				cout << tb + " GDCD" << endl;
			}
			if (dia <= 1) {
				count++;
				string tb = Tb_liet;
				cout << tb + " Dia li" << endl;
			}
			if (su <= 1) {
				count++;
				string tb = Tb_liet;
				cout << tb + " Lich Su" << endl;
			}
		}
		//
		if (1) {

			//2020
			if (nam == 0) {
				// Tot nghiep voi thi sinh thuong 
				totnghiep += khuyenkhich;
				if (selection == 0) {
					totnghiep = (totnghiep / 4) * 0.7 + 0.3 * tb12 + uu_tien;
					if (totnghiep < 5) {
						out << "Ban con thieu " << 5 - totnghiep << " diem de du dieu kien tot nghiep" << endl;
					}
					else out << "Ban da tot nghiep voi so diem " << totnghiep << endl;
				}

				// Tot nghiep voi thi sinh GDTX

				if (selection == 1) {
					totnghiep1 = ((totnghiep1 / 3) + (khuyenkhich / 4)) * 0.7 + tb12 * 0.3 + uu_tien;
					if (totnghiep1 < 5) {
						out << "Ban con thieu " << 5 - totnghiep1 << " diem de du dieu kien tot nghiep" << endl;
					}
					else out << "Ban da tot nghiep voi so diem " << totnghiep1 << endl;
				}
			}
			// 2018
			if (nam == 1) {

				// Tot nghiep voi thi sinh thuong 
				totnghiep += khuyenkhich;
				if (selection == 0) {
					totnghiep = (totnghiep / 4) * 0.5 + tb12 * 0.5 + uu_tien;
					if (totnghiep < 5) {
						out << "Ban con thieu " << 5 - totnghiep << " diem de du dieu kien tot nghiep" << endl;
					}
					else out << "Ban da tot nghiep voi so diem " << totnghiep << endl;
				}

				// Tot nghiep voi thi sinh GDTX

				if (selection == 1) {
					totnghiep1 = ((totnghiep1 / 3) + (khuyenkhich / 4)) * 0.5 + tb12 * 0.5 + uu_tien;
					if (totnghiep1 < 5) {
						out << "Ban con thieu " << 5 - totnghiep1 << " diem de du dieu kien tot nghiep" << endl;
					}
					else out << "Ban da tot nghiep voi so diem " << totnghiep1 << endl;
				}
			}
		}
		 if (count)this->selection = 0;
		// tuy chon khtn // khxh 
		//if (totnghiep < 5)out << "Ban con thieu " << 5 - totnghiep << " diem de du dieu kien tot nghiep" << endl;
		//else out << "Ban da tot nghiep voi so diem " << totnghiep << endl; 
		
	}
	bool inline CHECK_ID_(string ID)
	{
		
		ifstream myfile(this->file[this->k], ios::in);
		string line, token;
		int count = 0;
		while (!myfile.eof()) {
			getline(myfile, line);
			count++;
			if (count != 1 && line != "") {
				istringstream stm(line);
				getline(stm, token, ',');
				getline(stm, token, ',');
				//
				if (token == ID) {
					this->STUDENT_CODE_ID = ID;
					getline(stm, token, ',');
					if (token != "") {
						this->DIA_LY = token;
					}
					getline(stm, token, ',');
					if (token != "") {
						this->GDCD = token;
					}
					getline(stm, token, ',');
					if (token != "") {
						this->HOA_HOC = token;
					}
					getline(stm, token, ',');
					//
					if (token != "") {
						this->KHTN = token;
					}
					getline(stm, token, ',');
					//
					if (token != "") {
						this->KHXH = token;
					}
					getline(stm, token, ',');
					if (token != "") {
						this->LICH_SU = token;
					}
					getline(stm, token, ',');
					if (token != "") {
						this->NGOAI_NGU = token;
					}
					getline(stm, token, ',');

					if (token != "") {
						this->NGU_VAN = token;
					}
					getline(stm, token, ',');
					if (token != "") {
						this->SINH_HOC = token;
					}
					getline(stm, token, ',');
					if (token != "") {
						this->TOAN = token;
					}
					getline(stm, token, ',');
					if (token != "") {
						this->VAT_Li = token;
					}
					getline(stm, token, ',');
					getline(stm, token, ',');
					if (this->NGOAI_NGU != "") {
						this->ma_nn = token; 
					}
					//
					return true; 
				}
			}
		}
		return false; 
	}
	
	int get_sele() {
		return this->selection; 
	}
	int  get_k() {
		return this->k;
	}
	//"FILE_ID.txt", "FILE_MARK_KHTN.txt", "FILE_MARK_KHXH.txt", "FILe_BAT_BUOC.txt"
	void PROCESS_DATA_WITH_ID()
	{
		
		string cache; int n; 
		string NameFile,NameFile_1;
		string ID;
		out << "SBD: "; 
		getline(cin, ID);
		this->nhap();
		out << "Vui long doi !" << endl;
		string path = this->PATH_FILE[this->k];
		while (!CHECK_ID_(ID))
		{
			out << "SBD khong ton tai ! \nMoi nhap lai SBD !\n";
			getline(cin, ID);
			this->nhap();
			path = this->PATH_FILE[this->k];
		}
		
		this->OUTPUT_ON_SCREEN();
		double dieem = 0,kk = 0 ,uu = 0; 
		int sele = 0;
		cout << "Nhap diem trung binh nam lop 12: "; 
		cin >> dieem; 
		cout << "Nhap diem khuyen khich: "; 
		cin >> kk;
		if (kk < 0)kk = 0; 
		cout << "Nhap diem uu tien: "; 
		cin >> uu; 
		if (uu < 0)uu = 0;
		if (this->KHTN == "" && this->KHXH == "")sele = 1;
		else{
			out << "1. Thi sinh THPT" << endl;
			out << "2. Thi sinh GDTX" << endl;
			out << "Xin moi chon: ";
			cin >> sele;
			if (sele >= 2)sele = 1;
			if (sele <= 1)sele = 0;
		}
		this->selection = sele;
		cin.ignore();
		int nam = 0;
		if (this->k == 1 || this->k == 2)nam = 0;
		else if (this->k == 0)nam = 1; 
		this->TOT_NGHIEP(dieem, nam, sele, kk, uu);
	} 
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
	string inline SAP_DATA(int i) {
		double toan = 0, ly = 0, hoa = 0, sinhhoc = 0, van = 0, anh = 0, su = 0, dia = 0, cd  =0;
		stringstream ss(this->TOAN);
		ss >> toan; 
		stringstream ss1(this->VAT_Li);
		ss1 >> ly;
		stringstream ss2(this->HOA_HOC);
		ss2 >> hoa;
		stringstream ss3(this->SINH_HOC);
		ss3 >> sinhhoc;
		stringstream ss4(this->NGU_VAN);
		ss4 >> van;
		stringstream ss5(this->NGOAI_NGU);
		ss5 >> anh;
		stringstream ss6(this->LICH_SU);
		ss6 >> su;
		stringstream ss7(this->DIA_LY);
		ss7 >> dia;
		stringstream ss8(this->GDCD);
		ss8 >> cd;
		double diemkhoi[14];
		diemkhoi[0] = toan + ly + hoa;
		diemkhoi[1] = toan + ly + anh;
		diemkhoi[2] = toan + ly + sinhhoc;
		diemkhoi[3] = toan + hoa + sinhhoc;
		diemkhoi[4] = toan + van + anh;
		diemkhoi[5] = van + su + dia;
		diemkhoi[6] = van + toan + ly;
		diemkhoi[7] = van + toan + hoa;
		diemkhoi[8] = van + toan + su;
		diemkhoi[9] = van + toan + dia;
		diemkhoi[10] = van + ly + hoa;
		diemkhoi[11] = van + ly + sinhhoc;
		diemkhoi[12] = van + ly + su;
		diemkhoi[13] = van + hoa + sinhhoc;
		int j = 0;
		while (j != 14) {
			if (i == j) {
				return to_string(diemkhoi[j]);
			}
			j++;
		}
	}
	void Data_Diem(int i, double &diem1, double &diem2, double &diem3,int &k) {
		double diemm1 = 0, diemm2 = 0, diemm3 = 0;
		string score1, score2, score3;
		switch (i)
		{
		case 0: {
			score1 = this->TOAN;
			score2 = this->VAT_Li;
			score3 = this->HOA_HOC;
		}break;
		case 1: {
			score1 = this->TOAN;
			score2 = this->VAT_Li;
			score3 = this->NGOAI_NGU;
		}break;
		case 2: {
			score1 = this->TOAN;
			score2 = this->VAT_Li;
			score3 = this->SINH_HOC;
		}break;
		case 3: {
			score1 = this->TOAN;
			score2 = this->HOA_HOC;
			score3 = this->SINH_HOC;
		}break;
		case 4: {
			score1 = this->TOAN;
			score2 = this->NGU_VAN;
			score3 = this->NGOAI_NGU;
		}break;
		case 5: {
			score1 = this->NGU_VAN;
			score2 = this->LICH_SU;
			score3 = this->DIA_LY;
		}break;
		case 6: {
			score2 = this->TOAN;
			score1 = this->NGU_VAN;
			score3 = this->VAT_Li;
		}break;
		case 7: {
			score2 = this->TOAN;
			score1 = this->NGU_VAN;
			score3 = this->HOA_HOC;
		}break;
		case 8: {
			score2 = this->TOAN;
			score1 = this->NGU_VAN;
			score3 = this->LICH_SU;
		}break;
		case 9: {
			score2 = this->TOAN;
			score1 = this->NGU_VAN;
			score3 = this->DIA_LY;
		}break;
		case 10: {
			score1 = this->NGU_VAN;
			score2 = this->VAT_Li;
			score3 = this->HOA_HOC;
		}break;
		case 11: {
			score1 = this->NGU_VAN;
			score2 = this->VAT_Li;
			score3 = this->SINH_HOC;
		}break;
		case 12: {
			score1 = this->NGU_VAN;
			score2 = this->VAT_Li;
			score3 = this->LICH_SU;
		}break;
		case 13: {
			score1 = this->NGU_VAN;
			score2 = this->HOA_HOC;
			score3 = this->SINH_HOC;
		}break;
		}
		stringstream ss(score1);
		ss >> diemm1;
		stringstream ss1(score2);
		ss1 >> diemm2;
		stringstream ss2(score3);
		ss2 >> diemm3;
		diem1 = diemm1;
		diem2 = diemm2;
		diem3 = diemm3;
		k = this->k;
	}
	int KHOII() {
		if (this->KHTN != "" && this->KHXH == "")return 0; 
		if (this->KHXH != "" && this->KHTN == "")return 1; 
		if (this->KHXH != "" && this->KHTN != "")return 2; 
		
	}
	inline  void OUTPUT_ON_SCREEN()
	{
		out << sbd << STUDENT_CODE_ID << endl;
		if(this->TOAN != "")out << "Toan: " << this->TOAN << "   " << "Van: " << this->NGU_VAN;
		if (this->NGOAI_NGU != "")out << "   " << "Ngoai ngu: " << this->NGOAI_NGU; out << endl;
		if (this->KHTN != "" && this->KHXH  != "")
		{
			out << "KHTN: " << this->KHTN << "   " << "Vat li: " << this->VAT_Li << "   " << "Hoa Hoc: " << this->HOA_HOC << "   " << "Sinh hoc: " << this->SINH_HOC << endl;
			out << "KHXH: " << this->KHXH << "   " << "Lich Su: " << this->LICH_SU << "   " << "Dia Ly: " << this->DIA_LY << "   " << "GDCD: " << this->GDCD << endl; 
		}
		else if (this->KHTN != "" && this->KHXH == "")
		{
			out << "KHTN: " << this->KHTN << "   " << "Vat li: " << this->VAT_Li << "   " << "Hoa Hoc: " << this->HOA_HOC << "   " << "Sinh hoc: " << this->SINH_HOC << endl;
		}
		else if (KHTN == "" &&KHXH != "") {
			cout << "KHXH: " << KHXH << "   " << "Lich su: " << LICH_SU << "   " << "Dia Ly: " << DIA_LY << "   " << "GDCD: " << GDCD << endl;
		}
		else if (this->KHTN == "" && this->KHXH == "") {
			if (this->DIA_LY != "")out << "Dia Ly: " << this->DIA_LY << "   ";
			if(this->LICH_SU != "")out << "Lich su: " << this->LICH_SU << "   ";
			cout << endl; 
		}
	}
};
// 

