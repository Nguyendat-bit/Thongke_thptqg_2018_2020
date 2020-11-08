#pragma once
	//SAP XEP TINH THANH THEO SO DIEM 10 2018 -> 2020
	//SAP XEP TINH THANH THEO SO THI SINH BI DIEM LIET 2018 -> 2020
	// TOP THU KHOA CAC KHOI 
	//LIET KE TONG SO  DIEM 10 TUNG MON
	//LIET KE DIEM TB CAC MON 2018 -> 2020 THEO BIEU DO DANG COT
	//   ^
	//	 |	
	//	MENU
//"FILE_ID.txt" ,"FILE_MARK_KHTN.txt","FILE_MARK_KHXH.txt" ,"FILe_BAT_BUOC.txt"

#include<vector>
#include"Thongke.h";
#include<sstream>
#include<algorithm>
#include"Search_tool.h";
#include"Setdata.h";
struct MARK
{
	double i = 0; 
	double  score = 0; 
};
struct Ma_tinH
{
	int ma_tinh; 
	double count_thisinh = 0;
};
struct MODD
{
	double score = 0; 
	string ID; 
};


#pragma region "Thong_Ke\\Diem10.txt","Thong_Ke\\Diemliet.txt","Thong_Ke\\tong10tungmon.txt","Thong_Ke\\top10thukhoa.txt","Thong_Ke\\dtb.txt"



class BASE_MATH_LATE
{
private:
	string File[7]{"Thong_Ke\\Diem10.txt","Thong_Ke\\Diemliet.txt","Thong_Ke\\tong10tungmon.txt","Thong_Ke\\top10thukhoa.txt","Thong_Ke\\dtb.txt","Thong_Ke\\thisinhtinh.txt","Thong_Ke\\diemliettungmon.txt"};
public:
	bool checkFileWithFstream(string path) {
		ifstream isf(path);
		return isf.good();
	}
	double to_double(string diem) {
		double k = 0;
		stringstream ss(diem);
		ss >> k;
		return k; 
	}
	BASE_MATH_LATE() {
		for (int i = 0; i < 7; i++) {
			if (!checkFileWithFstream(PATH_1 + File[i])) {
				out << PATH_1 + File[i] << " does not exits" << endl;
				out << "Wait" << endl;
				switch (i)
				{
				case 0: this->GET_MARK10_FROM_FILE(PATH_1 + File[i], 0); break;
				case 1: this->GET_MARK_MUST_OUT_FILE(PATH_1 + File[i], 0); break;
				case 2: this->GET_COUNT_MARK(PATH_1 + File[i], 0); break;
				case 4: this->GET_TB_FILE(PATH_1 + File[i], 0); break;
				case 3: this->GET_MAX(PATH_1 + File[i], 0); break;
				case 5: this->THI_SINH_TINH(PATH_1 + File[i], 0); break;
				case 6: this->GET_OUT_MARK(PATH_1 + File[i], 0); break;
				}
				out << "Complete !!!" << endl;
			}
			if (!checkFileWithFstream(PATH_2 + File[i])) {
				out << PATH_2 + File[i] << " does not exits" << endl;
				out << "Wait" << endl;
				switch (i)
				{
				case 0: this->GET_MARK10_FROM_FILE(PATH_2 + File[i], 1); break;
				case 1: this->GET_MARK_MUST_OUT_FILE(PATH_2 + File[i], 1); break;
				case 2: this->GET_COUNT_MARK(PATH_2 + File[i], 1); break;
				case 4: this->GET_TB_FILE(PATH_2 + File[i], 1); break;
				case 3: this->GET_MAX(PATH_2 + File[i], 1); break;
				case 5: this->THI_SINH_TINH(PATH_2 + File[i], 1); break;
				case 6: this->GET_OUT_MARK(PATH_2 + File[i], 1); break;
				}
				out << "Complete !!!" << endl;
			}
			if (!checkFileWithFstream(PATH_3 + File[i])) {
				out << PATH_3 + File[i] << " does not exits" << endl;
				out << "Wait" << endl;
				switch (i)
				{
				case 0: this->GET_MARK10_FROM_FILE(PATH_3 + File[i], 2); break;
				case 1: this->GET_MARK_MUST_OUT_FILE(PATH_3 + File[i], 2); break;
				case 2: this->GET_COUNT_MARK(PATH_3 + File[i], 2); break;
				case 4: this->GET_TB_FILE(PATH_3 + File[i], 2); break;
				case 3: this->GET_MAX(PATH_3 + File[i], 2); break;
				case 5: this->THI_SINH_TINH(PATH_3 + File[i], 2); break;
				case 6: this->GET_OUT_MARK(PATH_3 + File[i], 2); break;
				}
				out << "Complete !!!" << endl;
			}
		}
	}
	bool  Diem_liet(string diem)
	{
		double aka = 0;
		stringstream ss(diem);
		ss >> aka;
		if (aka <= 1)return true;
		return false;
	}
	void GET_MARK10_FROM_FILE(string path,int i) {
		int count = 0,cout_10 = 0,templace ,bien = 0; 
		MARK temp;
		vector<MARK>code(100);
		string a[3]{ "2018.csv","2019.csv","2020.csv" };
		ifstream myfile(a[i], ios::in);
		ofstream myfile_o(path, ios::app);
		string line, token;
		while (!myfile.eof()) {
			getline(myfile, line);
			count++;
			if (count != 1 && line != "") {
				
				istringstream stm(line);
				
					getline(stm, token, ',');
					getline(stm, token, ',');
					//
					getline(stm, token, ',');
					if (token != "" && to_double(token) == 10)cout_10++;
					getline(stm, token, ',');
					if (token != "" && to_double(token) == 10)cout_10++;
					getline(stm, token, ',');
					if (token != "" && to_double(token) == 10)cout_10++;
					getline(stm, token, ',');
					//
					getline(stm, token, ',');
					//
					getline(stm, token, ',');
					if (token != "" && to_double(token) == 10)cout_10++;
					getline(stm, token, ',');
					if (token != "" && to_double(token) == 10)cout_10++;
					getline(stm, token, ',');
					if (token != "" && to_double(token) == 10)cout_10++;
					getline(stm, token, ',');
					if (token != "" && to_double(token) == 10)cout_10++;
					getline(stm, token, ',');
					if (token != "" && to_double(token) == 10)cout_10++;
					getline(stm, token, ',');
					if (token != "" && to_double(token) == 10)cout_10++;
					getline(stm, token, ',');
					stringstream ss1(token);
					ss1 >> templace;
					
					if (cout_10 > 0) {
						
						code[templace].i += cout_10;
						code[templace].score = templace;
					}
					cout_10 = 0;
			}
		}
		for (auto j = code.begin(); j != code.end() - 1; j++)
			for (auto k = j + 1; k != code.end(); k++) {
				if (k->i > j->i) {
					swap(*k, *j);
				}
			}
		for (int j = 0; j < 100; j++)
		{
			if (code[j].score == 0)
			{
				size_t k = j;
				code.resize(k);
				break;
			}
		}
		for (auto it = code.begin(); it != code.end(); it++) {
			myfile_o << it->score << ',' << it->i << endl;
		}
	}
	void GET_MARK_MUST_OUT_FILE(string path, int i)
	{

		int Pointleave; 
		MARK temp;
		int count = 0,count_liet = 0,templace = 0;
		vector<MARK> code(100);
		string a[3]{ "2018.csv","2019.csv","2020.csv" };
		ofstream myfile_o(path, ios::app);
		ifstream myfile(a[i], ios::in);
		string line, token; 
		while (!myfile.eof())
		{
			getline(myfile, line);
			count++;
			if (count != 1 && line != "") {
				istringstream stm(line);

				getline(stm, token, ',');
				getline(stm, token, ',');
				//
				getline(stm, token, ',');
				if (token != "" && this->Diem_liet(token))count_liet++;
				getline(stm, token, ',');
				if (token != "" && this->Diem_liet(token))count_liet++;
				getline(stm, token, ',');
				if (token != "" && this->Diem_liet(token))count_liet++;
				getline(stm, token, ',');
				//
				getline(stm, token, ',');
				//
				getline(stm, token, ',');
				if (token != "" && this->Diem_liet(token))count_liet++;
				getline(stm, token, ',');
				//
				stringstream ss8(token);
				if (token != "" && this->Diem_liet(token))count_liet++;
				getline(stm, token, ',');
				if (token != "" && this->Diem_liet(token))count_liet++;
				
				getline(stm, token, ',');
				if (token != "" && this->Diem_liet(token))count_liet++;
				getline(stm, token, ',');
				if (token != "" && this->Diem_liet(token))count_liet++;
				getline(stm, token, ',');
				if (token != "" && this->Diem_liet(token))count_liet++;
				getline(stm, token, ',');
				stringstream ss(token);
				ss >> templace;
				if (count_liet) {
				
						code[templace].i += count_liet;
						code[templace].score = templace;
					
					count_liet = 0;
				}

			}
		}
		for (auto j = code.begin(); j != code.end() - 1; j++)
			for (auto k = j + 1; k != code.end(); k++) {
				if (k->i > j->i) {
					swap(*k, *j);
				}
			}
		for (int j = 0; j < 100; j++)
		{
			if (code[j].score == 0)
			{
				size_t k = j;
				code.resize(k);
				break;
			}
		}
		for (auto it = code.begin(); it != code.end(); it++) {
			myfile_o << it->score << ',' << it->i << endl;
		}
	}
	void THI_SINH_TINH(string path, int i) {
		string ID,line,token;
		int ma;
		vector<Ma_tinH>ma_tinh(100); 
		ofstream myfile_o(path, ios::app);
		int Ma_Tinh[63]{ 1,2,4,6,8,10,11,12,14,15,17,19,20,22,24,25,26,27,30,31,33,34,35,36,37,38,40,42,44,
		45,46,48,49,51,52,54,56,58,60,62,64,66,67,68,70,72,74,75,77,79,80,82,83,84,86,87,89,91,92,93,94,95,96 };
		string a[3]{ "2018.csv","2019.csv","2020.csv" };
		ifstream myfile(a[i], ios::in);
		while (!myfile.eof()) {
			getline(myfile, line);
			if (line != "") {
				istringstream stm(line);
				getline(stm, token, ',');
				getline(stm, token, ',');
					getline(stm, token, ',');
					
					getline(stm, token, ',');
					
					getline(stm, token, ',');
					
					getline(stm, token, ',');
					//
					
					getline(stm, token, ',');
					
					getline(stm, token, ',');
					
					getline(stm, token, ',');
					
					getline(stm, token, ',');

					getline(stm, token, ',');
					
					getline(stm, token, ',');
	
					getline(stm, token, ',');
					getline(stm, token, ',');
				stringstream ss(token);
				ss >> ma; 
				if (ma != 0) {
					ma_tinh[ma].ma_tinh = ma;
					ma_tinh[ma].count_thisinh += 1;
				}
				
			}
		}
		for(auto it = ma_tinh.begin();it != ma_tinh.end() - 1; it++)
			for (auto jt = it + 1; jt != ma_tinh.end(); jt++)
			{
				if(jt->count_thisinh > it->count_thisinh)swap(*it, *jt);
			}
		for (int j = 0; j < 100; j++) {
			if (ma_tinh[j].ma_tinh == 0) {
				ma_tinh.resize(j);
				break; 
			}
		}
		for (auto it = ma_tinh.begin(); it != ma_tinh.end(); it++) {
			myfile_o << it->ma_tinh << ',' << it->count_thisinh << endl; 
		}
	}
	void GET_OUT_MARK(string path, int i) {
		int toan = 0, van = 0, anh = 0, ly = 0, hoa = 0, sinhhoc = 0, su = 0, dia = 0, cd = 0;
		string PATHH[3]{ PATH_1,PATH_2,PATH_3 };
		string PATH_FILE[3]{ "FILE_MARK_KHTN.txt","FILE_MARK_KHXH.txt" ,"FILe_BAT_BUOC.txt" };
		string line, token;
		{
			ifstream myfile(PATHH[i] + PATH_FILE[0], ios::in); // KHTN
			while (!myfile.eof())
			{

				getline(myfile, line);
				if (line != "") {
					istringstream stm(line);
					getline(stm, token, ',');
					getline(stm, token, ',');
					getline(stm, token, ',');
					if (token != "" && this->Diem_liet(token))ly++;
					getline(stm, token, ',');
					if (token != "" && this->Diem_liet(token))hoa++;
					getline(stm, token, ',');
					if (token != "" && this->Diem_liet(token))sinhhoc++;
				}
			}
		}
		{
			ifstream myfile1(PATHH[i] + PATH_FILE[1], ios::in); // KHTN
			while (!myfile1.eof())
			{

				getline(myfile1, line);
				if (line != "") {
					istringstream stm(line);
					getline(stm, token, ',');
					getline(stm, token, ',');
					getline(stm, token, ',');
					if (token != "" && this->Diem_liet(token))dia++;
					getline(stm, token, ',');
					if (token != "" && this->Diem_liet(token))cd++;
					getline(stm, token, ',');
					if (token != "" && this->Diem_liet(token))su++;
				}
			}
		}
		{
			ifstream myfile2(PATHH[i] + PATH_FILE[2], ios::in); // KHTN
			while (!myfile2.eof())
			{

				getline(myfile2, line);
				if (line != "") {
					istringstream stm(line);
					getline(stm, token, ',');
					getline(stm, token, ',');
					if (token != "" && this->Diem_liet(token))toan++;
					getline(stm, token, ',');
					if (token != "" && this->Diem_liet(token))van++;
					getline(stm, token, ',');
					if (token != "" && this->Diem_liet(token))anh++;
				}
			}
		}
		ofstream myfile_o(path, ios::app);
		myfile_o << "Toan" << ',' << "Ngu van" << ',' << "Ngoai ngu" << ',' << "Vat li" << ',' << "Hoa hoc" << ',' << "Sinh hoc" << ',' << "GDCD" << ',' << "Lich su" << ',' << "Dia ly" << endl;
		myfile_o << toan << ',' << van << ',' << anh << ',' << ly << ',' << hoa << ',' << sinhhoc << ',' << cd << ',' << su << ',' << dia;
	}
	//"FILE_ID.txt" ,"FILE_MARK_KHTN.txt","FILE_MARK_KHXH.txt" ,"FILe_BAT_BUOC.txt"
	void GET_COUNT_MARK(string path, int i) {
		int toan = 0, van = 0, anh = 0, ly = 0, hoa = 0, sinhhoc = 0, su = 0, dia = 0, cd = 0;
		string PATHH[3]{ PATH_1,PATH_2,PATH_3 };
		string PATH_FILE[3]{ "FILE_MARK_KHTN.txt","FILE_MARK_KHXH.txt" ,"FILe_BAT_BUOC.txt" };
		string line, token;
		{
			ifstream myfile(PATHH[i] + PATH_FILE[0], ios::in); // KHTN
			while (!myfile.eof())
			{
				
					getline(myfile, line);
					if (line != "") {
					istringstream stm(line);
					getline(stm, token, ',');
					getline(stm, token, ',');
					getline(stm, token, ',');
					if (token != "" && to_double(token) == 10)ly++;
					getline(stm, token, ',');
					if (token != "" && to_double(token) == 10)hoa++;
					getline(stm, token, ',');
					if (token != "" && to_double(token) == 10)sinhhoc++;
					}
			}
		}
		{
			ifstream myfile1(PATHH[i] + PATH_FILE[1], ios::in); // KHTN
			while (!myfile1.eof())
			{
				
					getline(myfile1, line);
					if (line != "") {
					istringstream stm(line);
					getline(stm, token, ',');
					getline(stm, token, ',');
					getline(stm, token, ',');
					if (token != "" && to_double(token) == 10)dia++;
					getline(stm, token, ',');
					if (token != "" && to_double(token) == 10)cd++;
					getline(stm, token, ',');
					if (token != "" && to_double(token) == 10)su++;
					}
			}
		}
		{
			ifstream myfile2(PATHH[i] + PATH_FILE[2], ios::in); // KHTN
			while (!myfile2.eof())
			{
				
					getline(myfile2, line);
					if (line != "") {
					istringstream stm(line);
					getline(stm, token, ',');
					getline(stm, token, ',');
					if (token != "" && to_double(token) == 10)toan++;
					getline(stm, token, ',');
					if (token != "" && to_double(token) == 10)van++;
					getline(stm, token, ',');
					if (token != "" && to_double(token) == 10)anh++;
				}
			}
		}
		ofstream myfile_o(path, ios::app);
		myfile_o << "Toan" << ',' << "Ngu van" << ',' << "Ngoai ngu" << ',' << "Vat li" << ',' << "Hoa hoc" << ',' << "Sinh hoc" << ',' << "GDCD" << ',' << "Lich su" << ',' << "Dia ly" << endl;
		myfile_o << toan << ',' << van << ',' << anh << ',' << ly << ',' << hoa << ',' << sinhhoc << ',' << cd << ',' << su << ',' << dia;
	}
	void GET_TB_FILE(string path, int i) {
		double toan = 0, van = 0, anh = 0, ly = 0, hoa = 0, sinhhoc = 0, su = 0, dia = 0, cd = 0;
		int count1 = 0, count2 = 0, count3 = 0,count4 = 0,count5 =0 , count6 = 0,count7 = 0,count8 = 0, count9 = 0,temp;
		string PATHH[3]{ PATH_1,PATH_2,PATH_3 };
		string PATH_FILE[3]{ "FILE_MARK_KHTN.txt","FILE_MARK_KHXH.txt" ,"FILe_BAT_BUOC.txt" };
		string line, token;
		{
			ifstream myfile(PATHH[i] + PATH_FILE[0], ios::in); // KHTN
			while (!myfile.eof())
			{
				
					getline(myfile, line);
					if (line != "") {
					istringstream stm(line);
					getline(stm, token, ',');
					getline(stm, token, ',');
					getline(stm, token, ',');
					if (token != "") {
						istringstream ss(token);
						ss >> temp;
						ly += temp;
						count4++;
					}
					getline(stm, token, ',');
					if (token != "") {
						istringstream ss1(token);
						ss1 >> temp;
						hoa += temp;
						count5++;
					}
					getline(stm, token, ',');
					if (token != "") {
						istringstream ss2(token);
						ss2 >> temp;
						sinhhoc += temp;
						count6++;
					}
				}
			}
		}
		{
			ifstream myfile1(PATHH[i] + PATH_FILE[1], ios::in); // KHxh
			while (!myfile1.eof())
			{
				
					getline(myfile1, line);
					if (line != "") {
						istringstream stm(line);
						getline(stm, token, ',');
						getline(stm, token, ',');
						getline(stm, token, ',');
						if (token != "") {
							istringstream ss3(token);

							ss3 >> temp;
							dia += temp;
							count8++;
						}
						getline(stm, token, ',');
						if (token != "") {
							istringstream ss4(token);
							ss4 >> temp;
							cd += temp;
							count9++;
						}
						getline(stm, token, ',');
						if (token != "") {
							istringstream ss5(token);
							ss5 >> temp;
							su += temp;
							count7++;
						}
					}
			}
		}
		{
			ifstream myfile2(PATHH[i] + PATH_FILE[2], ios::in); // KHTN
			while (!myfile2.eof())
			{
				
					getline(myfile2, line);
					if (line != "") {
					istringstream stm(line);
					getline(stm, token, ',');
					getline(stm, token, ',');
					if (token != "") {
						stringstream ss6(token);
						ss6 >> temp;
						toan += temp;
						count1++;
					}
					getline(stm, token, ',');
					if (token != "") {
						istringstream ss7(token);
						ss7 >> temp;
						van += temp;
						count2++;
					}
					getline(stm, token, ',');
					if (token != "") {
						istringstream ss8(token);
						ss8 >> temp;
						anh += temp;
						count3++;
					}
				}
			}
		}
		ofstream myfile_o(path, ios::app);
		myfile_o << "Toan" << ',' << "Ngu van" << ',' << "Ngoai ngu" << ',' << "Vat li" << ',' << "Hoa hoc" << ',' << "Sinh hoc" << ',' << "Lich su" << ',' << "Dia ly" << ',' << "GDCD" << endl;
		myfile_o << toan / count1 << ',' << van /count2 << ',' << anh/count3 << ',' << ly/count4 << ',' << hoa/count5 << ',' << sinhhoc/count6 << ',' << su/count7 << ',' << dia/count8 << ',' << cd/count9 << endl; 
	}
	//"FILE_ID.txt" ,"FILE_MARK_KHTN.txt","FILE_MARK_KHXH.txt" ,"FILe_BAT_BUOC.txt"
	void GET_MAX_D(string path, int i) {
		vector<MODD>code;
		string PATH[3]{ PATH_1,PATH_2,PATH_3 };
		string Path_file = "KHOI\\D.txt", line, token, ID;
		ifstream myfile(PATH[i] + Path_file, ios::in);
		double diem;
		while (!myfile.eof()) {
			getline(myfile, line);
			if (line != "") {
				istringstream stm(line);
				getline(stm, token, ',');
				stringstream ss(token);
				ss >> diem;
				getline(stm, token, ',');
				ID = token;
				if (diem >= 26) {
					MODD temp;
					temp.ID = ID;
					temp.score = diem;
					code.push_back(temp);
				}
			}
		}
		for (auto j = code.begin(); j != code.end() - 1; j++)
			for (auto k = j + 1; k != code.end(); k++) {
				if (k->score > j->score) {
					swap(*k, *j);
				}
			}
		code.resize(10);
		//
		ofstream myfile_o(path, ios::app);
		for (auto it = code.begin(); it != code.end(); it++) {
			myfile_o << it->ID << ',' << it->score << ',' << "D01" << endl;
		}
	
	}
	void GET_MAX_A00(string path, int i) {
		vector<MODD>code;
		string PATH[3]{ PATH_1,PATH_2,PATH_3 };
		string Path_file = "KHOI\\A.txt",line,token,ID;
		ifstream myfile(PATH[i] + Path_file, ios::in);
		double diem; 
		while (!myfile.eof()) {
			getline(myfile, line);
			if (line != "") {
				istringstream stm(line);
				getline(stm, token, ',');
				stringstream ss(token);
				ss >> diem;
				getline(stm, token, ',');
				ID = token;
				if (diem >= 26) {
					MODD temp;
					temp.ID = ID;
					temp.score = diem;
					code.push_back(temp);
				}
			}
		}
		for (auto j = code.begin(); j != code.end() - 1; j++)
			for (auto k = j + 1; k != code.end(); k++) {
				if (k->score > j->score) {
					swap(*k, *j);
				}
			}
		code.resize(10);
		//
		ofstream myfile_o(path, ios::app);
		for (auto it = code.begin(); it != code.end(); it++) {
			myfile_o << it->ID << ',' << it->score << ',' << "A00" << endl;
		}
	}
	void GET_MARK_A01(string path, int i) {
		vector<MODD>code;
		string PATH[3]{ PATH_1,PATH_2,PATH_3 };
		string Path_file = "KHOI\\A1.txt", line, token, ID;
		ifstream myfile(PATH[i] + Path_file, ios::in);
		double diem;
		while (!myfile.eof()) {
			getline(myfile, line);
			if (line != "") {
				istringstream stm(line);
				getline(stm, token, ',');
				stringstream ss(token);
				ss >> diem;
				getline(stm, token, ',');
				ID = token;
				if (diem >= 26) {
					MODD temp;
					temp.ID = ID;
					temp.score = diem;
					code.push_back(temp);
				}
			}
		}
		for (auto j = code.begin(); j != code.end() - 1; j++)
			for (auto k = j + 1; k != code.end(); k++) {
				if (k->score > j->score) {
					swap(*k, *j);
				}
			}
		code.resize(10);
		//
		ofstream myfile_o(path, ios::app);
		for (auto it = code.begin(); it != code.end(); it++) {
			myfile_o << it->ID << ',' << it->score << ',' << "A01" << endl;
		}
	}
	void GET_MARK_B00(string path, int i) {
		vector<MODD>code;
		string PATH[3]{ PATH_1,PATH_2,PATH_3 };
		string Path_file = "KHOI\\B.txt", line, token, ID;
		ifstream myfile(PATH[i] + Path_file, ios::in);
		double diem;
		while (!myfile.eof()) {
			getline(myfile, line);
			if (line != "") {
				istringstream stm(line);
				getline(stm, token, ',');
				stringstream ss(token);
				ss >> diem;
				getline(stm, token, ',');
				ID = token;
				if (diem >= 26) {
					MODD temp;
					temp.ID = ID;
					temp.score = diem;
					code.push_back(temp);
				}
			}
		}
		for (auto j = code.begin(); j != code.end() - 1; j++)
			for (auto k = j + 1; k != code.end(); k++) {
				if (k->score > j->score) {
					swap(*k, *j);
				}
			}
		code.resize(10);
		//
		ofstream myfile_o(path, ios::app);
		for (auto it = code.begin(); it != code.end(); it++) {
			myfile_o << it->ID << ',' << it->score << ',' << "B00" << endl;
		}
	}
	void GET_MARK_C00(string path, int i) {
		vector<MODD>code;
		string PATH[3]{ PATH_1,PATH_2,PATH_3 };
		string Path_file = "KHOI\\C.txt", line, token, ID;
		ifstream myfile(PATH[i] + Path_file, ios::in);
		double diem;
		while (!myfile.eof()) {
			getline(myfile, line);
			if (line != "") {
				istringstream stm(line);
				getline(stm, token, ',');
				stringstream ss(token);
				ss >> diem;
				getline(stm, token, ',');
				ID = token;
				if (diem >= 26) {
					MODD temp;
					temp.ID = ID;
					temp.score = diem;
					code.push_back(temp);
				}
			}
		}
		for (auto j = code.begin(); j != code.end() - 1; j++)
			for (auto k = j + 1; k != code.end(); k++) {
				if (k->score > j->score) {
					swap(*k, *j);
				}
			}
		code.resize(10);
		//
		ofstream myfile_o(path, ios::app);
		for (auto it = code.begin(); it != code.end(); it++) {
			myfile_o << it->ID << ',' << it->score << ',' << "C00" << endl;
		}
	}
	void GET_MAX(string path, int i) {
		this->GET_MAX_D(path, i);
		//this->GET_MAX_A00(path, i);
		this->GET_MARK_A01(path, i);
		this->GET_MARK_B00(path, i);
		this->GET_MARK_C00(path, i);
	}
	
};
#pragma endregion
#define PATH_1_TINH "FILE\\2018\\Tinh\\"
#define PATH_2_TINH "FILE\\2019\\Tinh\\"
#define PATH_3_TINH "FILE\\2020\\Tinh\\"
#pragma region HienThi ra man hinh
class BASE_MATH_LATE_ON_SCREEN
{

private:
	string Tinh[64]{ "Ha Noi","Ho - Chi - Minh" ,"Hai Phong","Da Nang","Ha Giang","Cao Bang","Lai Chau","Lao Cai","Tuyen Quang","Lang Son","Bac Kan","Thai Nguyen","Yen Bai","Son La","Phu Tho",
		"Vinh Phuc","Quang Ninh","Bac Giang","Bac Ninh","Hai Duong","Hung Yen","Hoa Binh","Ha Nam","Nam Dinh",
	"Thai Binh","Ninh Binh", "Thanh Hoa","Nghe An","Ha Tinh","Quang Binh","Quang Tri","Thua Thien Hue","Quang Nam","Quang Ngai"
		,"Kon Tum","Binh Dinh","Gia Lai","Phu Yen","Dak Lak","Khanh Hoa","Lam Dong","Binh Phuoc","Binh Duong","Ninh Thuan","Tay Ninh","Binh Thuan",
		"Dong Nai","Long An","Dong Thap","An Giang","Ba Ria - Vung Tau","Tien Giang","Kien Giang","Can Tho","Ben Tre","Vinh Long","Tra Vinh","Soc Trang",
		"Bac Lieu","Ca Mau","Dien Bien","Dak Nong","Hau Giang" };
	
	
	string FILE[3]{ "2018.csv","2019.csv","2020.csv" };
	int Ma_Tinh[63]{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,
		45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64};
	string File[7]{ "Thong_Ke\\Diem10.txt","Thong_Ke\\Diemliet.txt","Thong_Ke\\tong10tungmon.txt","Thong_Ke\\top10thukhoa.txt","Thong_Ke\\dtb.txt","Thong_Ke\\thisinhtinh.txt","Thong_Ke\\diemliettungmon.txt" };
	string a[3]{ "2018", "2019", "2020" };
	string khoi[21]{ "A00","A01","A02","B00","D00","D01","D02","D03","D04","D05","D07","D08","C00","C01","C02","C03","C04","C05","C06","C07","C08" };
	string KHOI[9]{ "Toan","Ngu van","Ngoai ngu","Vat li","Hoa hoc","Sinh hoc","Lich su","Dia ly","GDCD"};
	string PATH_FILE[3]{ PATH_1,PATH_2,PATH_3 };
	int k,temp_khoithi,selection;

public:
	double to_double(string diem) {
		double k = 0 ; 
		stringstream ss(diem);
		ss >> k; 
		return k;
	}
	bool checkFileWithFstream(string path) {
		ifstream isf(path);
		return isf.good();
	}
	int to_int(string num) {
		int temp;
		stringstream ss(num);
		ss >> temp;
		return temp;
	}
	void Data_Tinh(string path,int j,int i) {
		string TOAN = "", VAT_Li = "", HOA_HOC = "", SINH_HOC = "", NGU_VAN = "", NGOAI_NGU = "", DIA_LY = "", GDCD = "", LICH_SU = "", KHTN = "", KHXH = "", ID;
		string line, token, ma_tinh, ma_nn;
		ofstream myfile_o(path, ios::app); 
		myfile_o << "Sbd" << ',' << "Dia ly" << ',' << "GDCD" << ',' << "Hoa hoc" << ',' << "KHTN" << ',' << "KHXH" << ',' << "Lich Su" << ',' << "Ngoai ngu" << ',' << "Ngu van" << ',' << ',' << "Sinh hoc" << ',' << "Toan" << ',' << "Vat li" << ',' << "Ma tinh"  << endl;
		ifstream myfile(this->FILE[j], ios::in);
		while (!myfile.eof()) {
			getline(myfile, line);
			if (line != "") {
				istringstream stm(line);
				getline(stm, token, ',');
				getline(stm, token, ',');
				//
				ID = token;
				getline(stm, token, ',');
				DIA_LY = token;
				getline(stm, token, ',');
				GDCD = token;
				getline(stm, token, ',');
				HOA_HOC = token;
				getline(stm, token, ',');
				//
				KHTN = token;
				getline(stm, token, ',');
				//	
				KHXH = token;
				getline(stm, token, ',');
				LICH_SU = token;
				getline(stm, token, ',');
				NGOAI_NGU = token;
				getline(stm, token, ',');
				NGU_VAN = token;
				getline(stm, token, ',');
				SINH_HOC = token;
				getline(stm, token, ',');
				TOAN = token;
				getline(stm, token, ',');
				VAT_Li = token;
				getline(stm, token, ',');
				ma_tinh = token;
				getline(stm, token, ',');
				if (NGOAI_NGU != "")
				{
					ma_nn = token;
				}
				if(to_int(ma_tinh) == this->Ma_Tinh[i])
				myfile_o << ID << ',' << DIA_LY << ',' << GDCD << ',' << HOA_HOC << ',' << KHTN << ',' << KHXH << ',' << LICH_SU << ',' << NGOAI_NGU << ',' << NGU_VAN << ',' << ',' << SINH_HOC << ',' << TOAN << ',' << VAT_Li << ',' << ma_tinh << ',' << ma_nn << endl;
			}
		}
	}
	BASE_MATH_LATE_ON_SCREEN() {
		for (int i = 0; i < 63; i++) {
			if (!this->checkFileWithFstream(PATH_1_TINH + this->Tinh[i] + ".txt")) {
				out << PATH_1_TINH + this->Tinh[i] + ".txt" << " does not exits " << endl;
				this->Data_Tinh(PATH_1_TINH + this->Tinh[i] + ".txt", 0,i);
				out << "Complete !!!" << endl;
			}
			if (!this->checkFileWithFstream(PATH_2_TINH + this->Tinh[i] + ".txt")) {
				out << PATH_2_TINH + this->Tinh[i] + ".txt" << " does not exits " << endl;
				this->Data_Tinh(PATH_2_TINH + this->Tinh[i] + ".txt", 1,i);
				out << "Complete !!!" << endl;
			}
			if (!this->checkFileWithFstream(PATH_3_TINH + this->Tinh[i] + ".txt")) {
				out << PATH_3_TINH + this->Tinh[i] + ".txt" << " does not exits " << endl;
				this->Data_Tinh(PATH_3_TINH + this->Tinh[i] + ".txt", 2,i);
				out << "Complete !!!" << endl;
			}
		}
	}
	bool check(string pathh) {
		for (int i = 0; i < 3; i++) {
			if (pathh == this->a[i]) {
				this->k = i; 
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
			out << "Moi nhap lai nam: (2018 -> 2020): "; 
			getline(cin, pathh);
		}
	}
	int get_k() {
		return k;
	}



	void nhap_khoithi() {
		int n = 21;
		string khoi1;
		for (int i = 0; i < n; i++) {
			cout << this->khoi[i] << "  ";
		}
		out << "\nKhoi Thi: ";
		getline(cin, khoi1);
		while (!check_khoithi(khoi1)) {
			out << "Khoi thi khong ton tai !" << endl;
			out << "Khoi thi: ";
			getline(cin, khoi1);
		}
	}
	bool check_khoithi(string po) {

		
		for (int i = 0; i < 21; i++) {
			if (po == this->khoi[i]) {
				this->temp_khoithi = i;
				return true;
			}
		}
		return false;

	}

	//"Toan","Ngu van","Ngoai ngu","Vat li","Hoa hoc","Sinh hoc","Lich su","Dia ly","GDCD"
	string get_diemtb(int i) {
		string line, token;
		int count = 0;
		ifstream myfile(this->PATH_FILE[this->k] + this->File[4], ios::in);
		while (!myfile.eof()) {
			getline(myfile, line);
			count++;
			if (line != "" && count != 1) {
				istringstream stm(line);
				getline(stm, token, ',');
				if (i == 0)return token;
				getline(stm, token, ',');
				if (i == 1)return token;
				getline(stm, token, ',');
				if (i == 2)return token;
				getline(stm, token, ',');
				if (i == 3)return token;
				getline(stm, token, ',');
				if (i == 4)return token;
				getline(stm, token, ',');
				if (i == 5)return token;
				getline(stm, token, ',');
				if (i == 6)return token;
				getline(stm, token, ',');
				if (i == 7)return token;
				getline(stm, token, ',');
				if (i == 8)return token;
			}
		}
	}
	void Phodiemmon1(string path,int selec);
	void Phodiemmon2(string path,int selec);
	bool check1111(string khoi) {
		int i = 0;
		while (i != 9) {
			if (this->KHOI[i] == khoi) {
				this->selection = i;
				return true;

			}
			i++;
		}
		return false;
	}
	void nhap_khoi() {
		string khoi;
		cout << "Nhap mon thi ma ban chon (Vd: Toan; Sinh hoc;GDCD): ";
		getline(cin, khoi);
		while (!check1111(khoi)) {
			cout << "Sai dinh dang, vui long nhap lai (Vd: Hoa hoc): ";
			getline(cin, khoi);
		}
	}
	

	// Thong ke
	void THONGKE_BANG_10(int selec);
	void THONGKE_BANG_MUST_OUT(int selec);
	void THONGKE_DIEM10(int selec);
	void THONGKE_DIEM_TB(int selec);
	void THONGKE_THU_KHOA();
	void THONGKE_THUKHOA_TQ(); 
	void THONGKE_THISINH_TINH();
	void THONGKE_FULL_BANG_MUST_OUT();
	void THONGKE_FULL_BANG_10();
	void THONGKE_OUT_MARK(int selec);
	void THONGKE_PHODIEM(string path);
	void nhap_thongke_phodiem();
	void THONGKE_PHODIEM_mon();
	
	///
	/// 
	///	  |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| 74 	
	/// 
	/// A ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	///	  |
	///   |
	///	X ||||||||||||||||||||||
	///   |
	///		 74 ~ 100 %
	///		 i / A	
	/// 
	///	wqndnqw |||||
	/// dwd      
	/// 
	/// 
	/// 

	string MaTinh(string code);


	

	//Bieu DO
	//
	//
	//
	
};
#pragma endregion