#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<list>
#include<sstream>
#define PATH_1_TINH "FILE\\2018\\Tinh\\"
#define PATH_2_TINH "FILE\\2019\\Tinh\\"
#define PATH_3_TINH "FILE\\2020\\Tinh\\"
using namespace std;
struct Data {
	string TOAN ="", VAT_Li ="", HOA_HOC ="", SINH_HOC="", NGU_VAN ="", NGOAI_NGU ="", DIA_LY ="", GDCD ="", LICH_SU ="", KHTN = "", KHXH = "",ma_nn ="";
	string STUDENT_CODE_ID;
};

class search_tool
{

private:
	string Tinh[64]{ "Ha Noi","Ho - Chi - Minh" ,"Hai Phong","Da Nang","Ha Giang","Cao Bang","Lai Chau","Lao Cai","Tuyen Quang","Lang Son","Bac Kan","Thai Nguyen","Yen Bai","Son La","Phu Tho",
		"Vinh Phuc","Quang Ninh","Bac Giang","Bac Ninh","Hai Duong","Hung Yen","Hoa Binh","Ha Nam","Nam Dinh",
	"Thai Binh","Ninh Binh", "Thanh Hoa","Nghe An","Ha Tinh","Quang Binh","Quang Tri","Thua Thien Hue","Quang Nam","Quang Ngai"
		,"Kon Tum","Binh Dinh","Gia Lai","Phu Yen","Dak Lak","Khanh Hoa","Lam Dong","Binh Phuoc","Binh Duong","Ninh Thuan","Tay Ninh","Binh Thuan",
		"Dong Nai","Long An","Dong Thap","An Giang","Ba Ria - Vung Tau","Tien Giang","Kien Giang","Can Tho","Ben Tre","Vinh Long","Tra Vinh","Soc Trang",
		"Bac Lieu","Ca Mau","Dien Bien","Dak Nong","Hau Giang" };

	string FILE_TINH[3]{ PATH_1_TINH,PATH_2_TINH,PATH_3_TINH };

	int Ma_Tinh[63]{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,
		45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64 };
	string nam[3]{ "2018","2019","2020" };
	string FILE[3]{ "2018.csv", "2019.csv", "2020.csv" };
	string dir[3]{ "FILE\\2018\\","FILE\\2019\\","FILE\\2020\\" };
	Data Student;
	vector<string> label;//0   1            2         3        4          5       6        7        8      9      10
	string KHOI[11]{ "Toan","Ngu van","Ngoai ngu","Hoa hoc","Sinh hoc","Vat li","Dia ly","Lich su","GDCD","KHTN","KHXH" };
	int selection; 
	int  m;
	int k; 
public:
	double to_double(string diem) {
		double k = 0;
		stringstream ss(diem);
		ss >> k;
		return k;
	}
	bool check_diemthi(string diem) {
		double diem_thi = 0; 
		istringstream ss(diem);
		ss >> diem_thi;
		if (0 <= diem_thi && diem_thi <= 10)return true;
		return false;
	}
	bool check(string khoi) {
		int i = 0; 
		while (i != 11) {
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
		while (!check(khoi)) {
			cout << "Sai dinh dang, vui long nhap lai (Vd: Hoa hoc): ";
			getline(cin, khoi);
		}
	}
	bool Check_get_data_by_id(string id)
	{
		string line, token; 
		int count = 0; 
		ifstream myfile(this->FILE[this->k], ios::in);
		while (!myfile.eof()) {
			getline(myfile, line);
			count++;
			if (count != 1 && line != "") {
				istringstream stm(line);
				getline(stm, token, ',');
				getline(stm, token, ',');
				//
				if (token == id) {
					Student.STUDENT_CODE_ID = id;
					getline(stm, token, ',');
					if (token != "") {
						Student.DIA_LY = token;
					}
					getline(stm, token, ',');
					if (token != "") {
						Student.GDCD = token;
					}
					getline(stm, token, ',');
					if (token != "") {
						Student.HOA_HOC = token;
					}
					getline(stm, token, ',');
					//
					if (token != "") {
						Student.KHTN = token;
					}
					getline(stm, token, ',');
					//
					if (token != "") {
						Student.KHXH = token;
					}
					getline(stm, token, ',');
					if (token != "") {
						Student.LICH_SU = token;
					}
					getline(stm, token, ',');
					if (token != "") {
						Student.NGOAI_NGU = token;
					}
					getline(stm, token, ',');

					if (token != "") {
						Student.NGU_VAN = token;
					}
					getline(stm, token, ',');
					if (token != "") {
						Student.SINH_HOC = token;
					}
					getline(stm, token, ',');
					if (token != "") {
						Student.TOAN = token;
					}
					getline(stm, token, ',');
					if (token != "") {
						Student.VAT_Li = token;
					}
					if (Student.NGOAI_NGU != "") {
						getline(stm, token, ',');
						Student.ma_nn = token;
					}
					//
					return true;
				}
			}
		}
		return false;
	}
	int to_int(string num) {
		int temp; 
		stringstream ss(num);
		ss >> temp; 
		return temp; 
	}
	bool inline Diem_liet(string diem)
	{
		double aka = 0;
		stringstream ss(diem);
		ss >> aka;
		if (aka <= 1)return true;
		return false;
	}
	void Set_data_diemliet_theo_matinh(size_t n = 0, string ma = "") {
		size_t i = 0;
		int count = 0;
		string TOAN = "", VAT_Li = "", HOA_HOC = "", SINH_HOC = "", NGU_VAN = "", NGOAI_NGU = "", DIA_LY = "", GDCD = "", LICH_SU = "", KHTN = "", KHXH = "", ID;
		string line, token, ma_tinh, ma_nn;
		ifstream myfile(this->FILE_TINH[this->k] + this->Tinh[this->m] + ".txt", ios::in);
		while (!myfile.eof())
		{
			getline(myfile, line);
			count++;
			if (count != 1 && line != "") {
				istringstream stm(line);
				

				getline(stm, token, ',');
				//
				ID = token;
				getline(stm, token, ',');
				DIA_LY = token;
				if (token != "") {
					
					if (this->Diem_liet(token))i++;
				}
				getline(stm, token, ',');
				GDCD = token;
				if (token != "") {
					
					if (this->Diem_liet(token))i++;
				}
				getline(stm, token, ',');
				HOA_HOC = token;
				if (token != "") {
					
					if (this->Diem_liet(token))i++;
				}
				getline(stm, token, ',');
				//
				KHTN = token;
				if (token != "") {
					
					if (this->Diem_liet(token))i++;
				}
				getline(stm, token, ',');
				//
				KHXH = token;
				if (token != "") {
					
					if (this->Diem_liet(token))i++;
				}
				getline(stm, token, ',');
				LICH_SU = token;
				if (token != "") {
					
					if (this->Diem_liet(token))i++;
				}
				getline(stm, token, ',');
				NGOAI_NGU = token;
				if (token != "") {
					
					if (this->Diem_liet(token))i++;
				}
				getline(stm, token, ',');
				NGU_VAN = token;
				if (token != "") {
					
					if (this->Diem_liet(token))i++;
				}
				getline(stm, token, ',');
				SINH_HOC = token;
				if (token != "") {
					
					if (this->Diem_liet(token))i++;
				}
				getline(stm, token, ',');
				TOAN = token;
				if (token != "") {
					
					if (this->Diem_liet(token))i++;
				}
				getline(stm, token, ',');
				VAT_Li = token;
				if (token != "") {
					
					if (this->Diem_liet(token))i++;
				}
				getline(stm, token, ',');
				ma_tinh = token;
				getline(stm, token, ',');
				if (NGOAI_NGU != "") {
					ma_nn = token;
				}
				if (  i == n) {
					Student.STUDENT_CODE_ID = ID;
					Student.TOAN = TOAN;
					Student.NGU_VAN = NGU_VAN;
					Student.NGOAI_NGU = NGOAI_NGU;
					Student.KHTN = KHTN;
					Student.KHXH = KHXH;
					Student.LICH_SU = LICH_SU;
					Student.DIA_LY = DIA_LY;
					Student.GDCD = GDCD;
					Student.VAT_Li = VAT_Li;
					Student.SINH_HOC = SINH_HOC;
					Student.HOA_HOC = HOA_HOC;
					Student.ma_nn = token;
					return; 
				}
				

			}
		}
	}
	void Set_data_diemliet_theo_mon(size_t n = 0) {
		size_t i = 0;
		string diem_thi;
		int count = 0;
		string TOAN = "", VAT_Li = "", HOA_HOC = "", SINH_HOC = "", NGU_VAN = "", NGOAI_NGU = "", DIA_LY = "", GDCD = "", LICH_SU = "", KHTN = "", KHXH = "", ID;
		string line, token, ma_nn;
		//this->nhap_khoi();
		ifstream myfile(FILE[this->k], ios::in);
		//,Code,Diali,GDCD,Hoahoc,KHTN,KHXH,LichSu,Ngoaingu,Nguvan,Sinhhoc,Toan,Vatli,city
		while (!myfile.eof())
		{
			getline(myfile, line);
			count++;
			if (count != 1 && line != "") {
				istringstream stm(line);
				getline(stm, token, ',');

				getline(stm, token, ',');
				//
				ID = token;
				getline(stm, token, ',');
				DIA_LY = token;
				if (this->selection == 6) {
					if (token != "") {

						if (this->Diem_liet(token))i++;
					}
				}
				getline(stm, token, ',');
				GDCD = token;
				if (this->selection == 8) {
					if (token != "") {

						if (this->Diem_liet(token))i++;
					}
				}
				getline(stm, token, ',');
				HOA_HOC = token;
				if (this->selection == 3) {
					if (token != "") {

						if (this->Diem_liet(token))i++;
					}
				}
				getline(stm, token, ',');
				//
				KHTN = token;
				if (this->selection == 9) {
					if (token != "") {

						if (this->Diem_liet(token))i++;
					}
				}
				getline(stm, token, ',');
				//
				KHXH = token;
				if (this->selection == 10) {
					if (token != "") {

						if (this->Diem_liet(token))i++;
					}
				}
				getline(stm, token, ',');
				LICH_SU = token;
				if (this->selection == 7) {
					if (token != "") {

						if (this->Diem_liet(token))i++;
					}
				}
				getline(stm, token, ',');
				NGOAI_NGU = token;
				if (this->selection == 2) {
					if (token != "") {

						if (this->Diem_liet(token))i++;
					}
				}
				getline(stm, token, ',');
				NGU_VAN = token;
				if (this->selection == 1) {
					if (token != "") {

						if (this->Diem_liet(token))i++;
					}
				}
				getline(stm, token, ',');
				SINH_HOC = token;
				if (this->selection == 4) {
					if (token != "") {

						if (this->Diem_liet(token))i++;
					}
				}
				getline(stm, token, ',');
				TOAN = token;
				if (this->selection == 0) {
					if (token != "") {

						if (this->Diem_liet(token))i++;
					}
				}
				getline(stm, token, ',');
				VAT_Li = token;
				if (this->selection == 5) {
					if (token != "") {

						if (this->Diem_liet(token))i++;
					}
				}
				getline(stm, token, ',');
				
				getline(stm, token, ',');
				if (NGOAI_NGU != "") {
					ma_nn = token;
				}
				if (i == n) {
					Student.STUDENT_CODE_ID = ID;
					Student.TOAN = TOAN;
					Student.NGU_VAN = NGU_VAN;
					Student.NGOAI_NGU = NGOAI_NGU;
					Student.KHTN = KHTN;
					Student.KHXH = KHXH;
					Student.LICH_SU = LICH_SU;
					Student.DIA_LY = DIA_LY;
					Student.GDCD = GDCD;
					Student.VAT_Li = VAT_Li;
					Student.SINH_HOC = SINH_HOC;
					Student.HOA_HOC = HOA_HOC;
					Student.ma_nn = ma_nn;
					return; 
				}
				if (i > n) {
					cout << "Khong ton tai ho so diem cua thi sinh " << endl; 
					return;
				}
			}
		}
	}
	void Set_data_diemliet_theo_mon_matinh(size_t n = 0, string ma = "") {
		size_t i = 0;
		int count = 0;
		string TOAN = "", VAT_Li = "", HOA_HOC = "", SINH_HOC = "", NGU_VAN = "", NGOAI_NGU = "", DIA_LY = "", GDCD = "", LICH_SU = "", KHTN = "", KHXH = "", ID;
		string line, token, ma_tinh, ma_nn;
		//this->nhap_khoi();
		ifstream myfile(this->FILE_TINH[this->k] + this->Tinh[this->m] + ".txt", ios::in);
		//,Code,Diali,GDCD,Hoahoc,KHTN,KHXH,LichSu,Ngoaingu,Nguvan,Sinhhoc,Toan,Vatli,city
		while (!myfile.eof())
		{
			getline(myfile, line);
			count++;
			if (count != 1 && line != "") {
				istringstream stm(line);
				getline(stm, token, ',');

				getline(stm, token, ',');
				//
				ID = token;
				getline(stm, token, ',');
				DIA_LY = token;
				if (this->selection == 6) {
					if (token != "") {

						if (this->Diem_liet(token))i++;
					}
				}
				getline(stm, token, ',');
				GDCD = token;
				if (this->selection == 8) {
					if (token != "") {

						if (this->Diem_liet(token))i++;
					}
				}
				getline(stm, token, ',');
				HOA_HOC = token;
				if (this->selection == 3) {
					if (token != "") {

						if (this->Diem_liet(token))i++;
					}
				}
				getline(stm, token, ',');
				//
				KHTN = token;
				if (this->selection == 9) {
					if (token != "") {

						if (this->Diem_liet(token))i++;
					}
				}
				getline(stm, token, ',');
				//
				KHXH = token;
				if (this->selection == 10) {
					if (token != "") {

						if (this->Diem_liet(token))i++;
					}
				}
				getline(stm, token, ',');
				LICH_SU = token;
				if (this->selection == 7) {
					if (token != "") {

						if (this->Diem_liet(token))i++;
					}
				}
				getline(stm, token, ',');
				NGOAI_NGU = token;
				if (this->selection == 2) {
					if (token != "") {

						if (this->Diem_liet(token))i++;
					}
				}
				getline(stm, token, ',');
				NGU_VAN = token;
				if (this->selection == 1) {
					if (token != "") {

						if (this->Diem_liet(token))i++;
					}
				}
				getline(stm, token, ',');
				SINH_HOC = token;
				if (this->selection == 4) {
					if (token != "") {

						if (this->Diem_liet(token))i++;
					}
				}
				getline(stm, token, ',');
				TOAN = token;
				if (this->selection == 0) {
					if (token != "") {

						if (this->Diem_liet(token))i++;
					}
				}
				getline(stm, token, ',');
				VAT_Li = token;
				if (this->selection == 5) {
					if (token != "") {

						if (this->Diem_liet(token))i++;
					}
				}
				getline(stm, token, ',');

				getline(stm, token, ',');
				if (NGOAI_NGU != "") {
					ma_nn = token;
				}
				if ( i == n) {
					Student.STUDENT_CODE_ID = ID;
					Student.TOAN = TOAN;
					Student.NGU_VAN = NGU_VAN;
					Student.NGOAI_NGU = NGOAI_NGU;
					Student.KHTN = KHTN;
					Student.KHXH = KHXH;
					Student.LICH_SU = LICH_SU;
					Student.DIA_LY = DIA_LY;
					Student.GDCD = GDCD;
					Student.VAT_Li = VAT_Li;
					Student.SINH_HOC = SINH_HOC;
					Student.HOA_HOC = HOA_HOC;
					Student.ma_nn = ma_nn;
					return;
				}

			}
		}
	}
	void Set_data_diemliet() {
		list<string> temp;
		string line, token, ID;
		bool switvh = true;
		int selec;
		double dem = 0, count = 0, macdinh = 1, temp_macdinh;
		int co = 0;
		cout << "Vui long doi trong vai giay " << endl; 
		ifstream myfile(this->FILE[this->k], ios::in);
		while (!myfile.eof()) {
			getline(myfile, line);
			co++;
			if (co != 1 && line != "") {
				istringstream stm(line);
				getline(stm, token, ',');

				getline(stm, token, ',');
				ID = token;
				getline(stm, token, ',');
				if (token != "" && this->Diem_liet(token))dem++;
				getline(stm, token, ',');
				if (token != "" && this->Diem_liet(token))dem++;
				getline(stm, token, ',');
				if (token != "" && this->Diem_liet(token))dem++;
				getline(stm, token, ',');
				//
				if (token != "" && this->Diem_liet(token))dem++;
				getline(stm, token, ',');
				//
				if (token != "" && this->Diem_liet(token))dem++;
				getline(stm, token, ',');
				if (token != "" && this->Diem_liet(token))dem++;
				getline(stm, token, ',');
				if (token != "" && this->Diem_liet(token))dem++;
				getline(stm, token, ',');
				if (token != "" && this->Diem_liet(token))dem++;
				getline(stm, token, ',');
				if (token != "" && this->Diem_liet(token))dem++;
				getline(stm, token, ',');
				if (token != "" && this->Diem_liet(token))dem++;
				getline(stm, token, ',');
				if (token != "" && this->Diem_liet(token))dem++;
				if (dem) {
					temp.push_back(line);
					count++;
				}
				dem = 0; 
			}
		}
		auto it = temp.begin();
		do {
			temp_macdinh = macdinh;
			system("cls");
			cout << "Dang duyet nam " << this->nam[this->k] << endl;
			cout << "Co tat ca " << count << " ket qua" << endl;
			cout << "Xem truoc ket qua " << macdinh << endl;
			this->Process_befor_PR_diemliet(*it);
			cout << "\n1. Ban muon xem chi tiet ? " << endl;
			cout << "2. Tuy chon ket qua muon xem ? " << endl;
			cout << "3. Lui lai ket qua truoc ? " << endl;
			cout << "4. Tiep den ket qua tiep theo ? " << endl;
			cout << "5. Quay lai" << endl;
			cout << "Xin moi chon: ";
			cin >> selec;
			cin.ignore();
			if (selec != 1 && selec != 2 && selec != 3 && selec == 4 && selec == 5) {
				cout << "Moi nhap lai: " << endl;
			}
			switch (selec)
			{
			case 1: {
				this->Data_set_form_line(*it);
				this->Get_data();
			}; break;
			case 2: {
				int n;
				cout << "Ban muon xem ket qua o vi tri: ";
				cin >> n;
				cin.ignore();
				if (n < count) {
					if (temp_macdinh < n) {
						for (double i = temp_macdinh; i < n; i++)it++;
					}
					else if (temp_macdinh > n) {
						for (double i = temp_macdinh; i > n; i--)it--;
					}
					macdinh = n;
				}
				else {
					cout << "Vi pham gioi han !!" << endl;
					system("pause");
				}
			}break;
			case 3: {
				if (it != temp.begin()) {
					it--;
					macdinh--;

				}
				else {
					cout << "Khong co cai gi o phia truoc ca " << endl;
					system("pause");
				}
			}break;
			case 4: {
				it++;
				macdinh++;
			}break;
			case 5:switvh = false;
			}
		} while (switvh);

	
	}
	void Process_befor_PR_diemliet(string line) {
		string token, ID;
		string diem_liet[11];
		int diem_token[11];
		for (auto& item : diem_token)item = 11;
		istringstream stm(line);
		getline(stm, token, ',');
		getline(stm, token, ',');
		ID = token;
		getline(stm, token, ',');
		if (token != "" && this->Diem_liet(token)) {
			diem_token[0] = 6;
			diem_liet[0] = token;
		}
		getline(stm, token, ',');
		if (token != "" && this->Diem_liet(token)) {
			diem_token[1] = 8;
			diem_liet[1] = token;
		}
		getline(stm, token, ',');
		if (token != "" && this->Diem_liet(token)) {
			diem_token[2] = 3;
			diem_liet[2] = token;
		}
		getline(stm, token, ',');
		//
		if (token != "" && this->Diem_liet(token)) {
			diem_token[3] = 9;
			diem_liet[3] = token;
		}
		getline(stm, token, ',');
		//
		if (token != "" && this->Diem_liet(token)) {
			diem_token[4] = 10;
			diem_liet[4] = token;
		}
		getline(stm, token, ',');
		if (token != "" && this->Diem_liet(token)) {
			diem_token[5] = 7;
			diem_liet[5] = token;
		}
		getline(stm, token, ',');
		if (token != "" && this->Diem_liet(token)) {
			diem_token[6] = 2;
			diem_liet[6] = token;
		}
		getline(stm, token, ',');
		if (token != "" && this->Diem_liet(token)) {
			diem_token[7] = 1;
			diem_liet[7] = token;
		}
		getline(stm, token, ',');
		if (token != "" && this->Diem_liet(token)) {
			diem_token[8] = 4;
			diem_liet[8] = token;
		}
		getline(stm, token, ',');
		if (token != "" && this->Diem_liet(token)) {
			diem_token[9] = 0;
			diem_liet[9] = token;
		}
		getline(stm, token, ',');
		if (token != "" && this->Diem_liet(token)) {
			diem_token[10] = 5;
			diem_liet[10] = token;
		}
		this->Preview_liet(ID, diem_token[0], diem_token[1], diem_token[2], diem_token[3], diem_token[4], diem_token[5], diem_token[6], diem_token[7], diem_token[8], diem_token[9], diem_token[10], diem_liet[0], diem_liet[1], diem_liet[2], diem_liet[3], diem_liet[4], diem_liet[5], diem_liet[6], diem_liet[7], diem_liet[8], diem_liet[9], diem_liet[10]);
	}
	void Preview_liet(string ID, int x1, int x2, int x3, int x4, int x5, int x6, int x7, int x8, int x9, int x10, int x11,string d1 = "",string d2 = "",string d3 = "",string d4 = "",string d5 = "",string d6 = "", string d7 = "",string d8 = "",string d9 = "",string d10 = "",string d11 ="") {
		cout << "SBD: " << ID << endl;
		if (x1 != 11)cout << this->KHOI[x1] << ": " << d1 << "  ";
		if (x2 != 11)cout << this->KHOI[x2] << ": " << d2 << "  ";
		if (x3 != 11)cout << this->KHOI[x3] << ": " << d3 << "  ";
		if (x4 != 11)cout << this->KHOI[x4] << ": " << d4 << "  ";
		if (x5 != 11)cout << this->KHOI[x5] << ": " << d5 << "  ";
		if (x6 != 11)cout << this->KHOI[x6] << ": " << d6 << "  ";
		if (x7 != 11)cout << this->KHOI[x7] << ": " << d7 << "  ";
		if (x8 != 11)cout << this->KHOI[x8] << ": " << d8 << "  ";
		if (x9 != 11)cout << this->KHOI[x9] << ": " << d9 << "  ";
		if (x10 != 11)cout << this->KHOI[x10] << ": " << d10 << "  ";
		if (x11 != 11)cout << this->KHOI[x11] << ": " << d11 << "  ";
	}
	void Set_data_by_diem_not_mon_theo_matinh( string diem1 , size_t n = 0, string ma = "") //
	{
		size_t i = 0; 
		int count = 0; 
		double diem = to_double(diem1);
		string TOAN = "", VAT_Li = "", HOA_HOC = "", SINH_HOC = "", NGU_VAN = "", NGOAI_NGU = "", DIA_LY = "", GDCD = "", LICH_SU = "", KHTN = "", KHXH = "",ID;
		string line, token,ma_tinh,ma_nn;
		ifstream myfile(this->FILE_TINH[this->k] + this->Tinh[this->m] + ".txt", ios::in);
		while (!myfile.eof())
		{
			getline(myfile, line); 
			count++;
			if (count != 1 && line != "") {
				istringstream stm(line);
			
				
				getline(stm, token, ',');
				//
				ID = token;
					getline(stm, token, ',');
					
						DIA_LY = token;
						if (to_double(token) == diem)i++;
					
					getline(stm, token, ',');
						GDCD = token;
						if (to_double(token) == diem)i++;
					getline(stm, token, ',');
						HOA_HOC = token;
						if (to_double(token) == diem)i++;
					getline(stm, token, ',');
					//
						KHTN = token;
						if (to_double(token) == diem)i++;
					getline(stm, token, ',');
					//
						KHXH = token;
						if (to_double(token) == diem)i++;
					getline(stm, token, ',');
						LICH_SU = token;
						if (to_double(token) == diem)i++;
					getline(stm, token, ',');
						NGOAI_NGU = token;
						if (to_double(token) == diem)i++;
					getline(stm, token, ',');
						NGU_VAN = token;
						if (to_double(token) == diem)i++;
					getline(stm, token, ',');
						SINH_HOC = token;
						if (to_double(token) == diem)i++;
					getline(stm, token, ',');
						TOAN = token;
						if (to_double(token) == diem)i++;
					getline(stm, token, ',');
						VAT_Li = token;
						if (to_double(token) == diem)i++;
					getline(stm, token, ',');
					ma_tinh = token;
					getline(stm, token, ',');
					if (NGOAI_NGU != "") {
						ma_nn = token;
					}
					if ( i == n) {
						Student.STUDENT_CODE_ID = ID;
						Student.TOAN = TOAN;
						Student.NGU_VAN = NGU_VAN;
						Student.NGOAI_NGU = NGOAI_NGU;
						Student.KHTN = KHTN;
						Student.KHXH = KHXH;
						Student.LICH_SU = LICH_SU;
						Student.DIA_LY = DIA_LY;
						Student.GDCD = GDCD;
						Student.VAT_Li = VAT_Li;
						Student.SINH_HOC = SINH_HOC;
						Student.HOA_HOC = HOA_HOC;
						Student.ma_nn = token; 
						return; 
					}
			}
		}
	}
	void Set_data_by_diem_theo_mon_theo_matinh(string diem1, size_t n = 0, string ma = "") {
		size_t i = 0;
		int count = 0;
		double diem = to_double(diem1);
		string TOAN = "", VAT_Li = "", HOA_HOC = "", SINH_HOC = "", NGU_VAN = "", NGOAI_NGU = "", DIA_LY = "", GDCD = "", LICH_SU = "", KHTN = "", KHXH = "", ID;
		string line, token,ma_tinh, ma_nn;
		this->nhap_khoi();
		ifstream myfile(this->FILE_TINH[this->k] + this->Tinh[this->m] + ".txt", ios::in);
		//,Code,Diali,GDCD,Hoahoc,KHTN,KHXH,LichSu,Ngoaingu,Nguvan,Sinhhoc,Toan,Vatli,city
		while (!myfile.eof())
		{
			getline(myfile, line);
			count++;
			if (count != 1 &&line != "") {
				istringstream stm(line);
				

				getline(stm, token, ',');
				//
				ID = token;
				getline(stm, token, ',');
				DIA_LY = token;
				if (this->selection == 6) {

					if (to_double(token) == diem)i++;
				}
				getline(stm, token, ',');
				GDCD = token;
				if (this->selection == 8) {


					if (to_double(token) == diem)i++;

				}
				getline(stm, token, ',');
				HOA_HOC = token;
				if (this->selection == 3) {


					if (to_double(token) == diem)i++;

				}
				getline(stm, token, ',');
				//
				KHTN = token;
				if (this->selection == 9) {


					if (to_double(token) == diem)i++;

				}
				getline(stm, token, ',');
				//
				KHXH = token;
				if (this->selection == 10) {


					if (to_double(token) == diem)i++;

				}
				getline(stm, token, ',');
				LICH_SU = token;
				if (this->selection == 7) {


					if (to_double(token) == diem)i++;

				}
				getline(stm, token, ',');
				NGOAI_NGU = token;
				if (this->selection == 2) {


					if (to_double(token) == diem)i++;

				}
				getline(stm, token, ',');
				NGU_VAN = token;
				if (this->selection == 1) {


					if (to_double(token) == diem)i++;

				}
				getline(stm, token, ',');
				SINH_HOC = token;
				if (this->selection == 4) {


					if (to_double(token) == diem)i++;

				}
				getline(stm, token, ',');
				TOAN = token;
				if (this->selection == 0) {


					if (to_double(token) == diem)i++;

				}
				getline(stm, token, ',');
				VAT_Li = token;
				if (this->selection == 5) {


					if (to_double(token) == diem)i++;

				}
				getline(stm, token, ',');
				getline(stm, token, ',');
				if (NGOAI_NGU != "")
				{
					ma_nn = token;
				}
				if ( i == n) {
					Student.STUDENT_CODE_ID = ID;
					Student.TOAN = TOAN;
					Student.NGU_VAN = NGU_VAN;
					Student.NGOAI_NGU = NGOAI_NGU;
					Student.KHTN = KHTN;
					Student.KHXH = KHXH;
					Student.LICH_SU = LICH_SU;
					Student.DIA_LY = DIA_LY;
					Student.GDCD = GDCD;
					Student.VAT_Li = VAT_Li;
					Student.SINH_HOC = SINH_HOC;
					Student.HOA_HOC = HOA_HOC;
					Student.ma_nn = ma_nn;
					return;
				}
			
			}
		}
	}
	void Set_data_by_id(){
		string id;
		cout << "SBD: ";
		getline(cin, id);
		while (!this->Check_get_data_by_id(id)) {
			cout << "SBD khong ton tai \nMoi nhap lai SBD: " << endl;
			getline(cin, id);
		}
	}
	void Process_before_PR(string line,string diem1) {
		string token,ID; 
		int diem_token[11];
		double diem = to_double(diem1);
		for (auto& item : diem_token)item = 11; 
		istringstream stm(line);
		getline(stm, token, ',');
		getline(stm, token, ',');
		ID = token;
		getline(stm, token, ',');
		if (token != "" && to_double(token) == diem) {
			diem_token[0] = 6;
		}
		getline(stm, token, ',');
		if (token != "" && to_double(token) == diem) {
			diem_token[1] = 8;
		
		}
		getline(stm, token, ',');
		if (token != "" && to_double(token) == diem) {
			diem_token[2] = 3;
			
		}
		getline(stm, token, ',');
		//
		if (token != "" && to_double(token) == diem) {
			diem_token[3] = 9;
			
		}
		getline(stm, token, ',');
		//
		if (token != "" && to_double(token) == diem) {
			diem_token[4] = 10;
			
		}
		getline(stm, token, ',');
		if (token != "" && to_double(token) == diem) {
			diem_token[5] = 7;
			
		}
		getline(stm, token, ',');
		if (token != "" && to_double(token) == diem) {
			diem_token[6] = 2;
			
		}
		getline(stm, token, ',');
		if (token != "" && to_double(token) == diem) {
			diem_token[7] = 1;
			
		}
		getline(stm, token, ',');
		if (token != "" && to_double(token) == diem) {
			diem_token[8] = 4;
			
		}
		getline(stm, token, ',');
		if (token != "" && to_double(token) == diem) {
			diem_token[9] = 0;
			
		}
		getline(stm, token, ',');
		if (token != "" && to_double(token) == diem) {
			diem_token[10] = 5;
			
		}
		this->Preview(ID, diem_token[0], diem_token[1], diem_token[2], diem_token[3], diem_token[4], diem_token[5], diem_token[6], diem_token[7], diem_token[8], diem_token[9], diem_token[10], diem1);
	}
	void Preview(string ID,int x1,int x2,int x3,int x4,int x5,int x6,int x7,int x8,int x9,int x10,int x11,string diem) {
		// 
		cout << "SBD: " << ID << endl;
		if (x1 != 11)cout << this->KHOI[x1] << ": " << diem << "  ";
		if (x2 != 11)cout << this->KHOI[x2] << ": " << diem << "  ";
		if (x3 != 11)cout << this->KHOI[x3] << ": " << diem << "  ";
		if (x4 != 11)cout << this->KHOI[x4] << ": " << diem << "  ";
		if (x5 != 11)cout << this->KHOI[x5] << ": " << diem << "  ";
		if (x6 != 11)cout << this->KHOI[x6] << ": " << diem << "  ";
		if (x7 != 11)cout << this->KHOI[x7] << ": " << diem << "  ";
		if (x8 != 11)cout << this->KHOI[x8] << ": " << diem << "  ";
		if (x9 != 11)cout << this->KHOI[x9] << ": " << diem << "  ";
		if (x10 != 11)cout << this->KHOI[x10] << ": " << diem << "  ";
		if (x11 != 11)cout << this->KHOI[x11] << ": " << diem << "  ";
	}
	void Data_set_form_line(string line) {
		string token;
		istringstream stm(line);
		getline(stm, token, ',');
		getline(stm, token, ',');
		//
		Student.STUDENT_CODE_ID = token;
			getline(stm, token, ',');
			
				Student.DIA_LY = token;
			
			getline(stm, token, ',');
			
				Student.GDCD = token;
			
			getline(stm, token, ',');
		
				Student.HOA_HOC = token;
			
			getline(stm, token, ',');
			//
			
				Student.KHTN = token;
			
			getline(stm, token, ',');
			//
			
				Student.KHXH = token;
			
			getline(stm, token, ',');
			
				Student.LICH_SU = token;
			
			getline(stm, token, ',');
			
				Student.NGOAI_NGU = token;
			
			getline(stm, token, ',');

			
				Student.NGU_VAN = token;
			
			getline(stm, token, ',');
			
				Student.SINH_HOC = token;
			
			getline(stm, token, ',');
			
				Student.TOAN = token;
			
			getline(stm, token, ',');
			
				Student.VAT_Li = token;
				getline(stm, token, ',');
			if (Student.NGOAI_NGU != "") {
				getline(stm, token, ',');
				Student.ma_nn = token;
			}
	}
	void Set_data_by_diem_nothing(string diem1){
		list<string> temp; 
		double diem = to_double(diem1);
		string line, token,ID; 
		bool switvh = true;
		int selec;
		double dem = 0, count = 0, macdinh = 1;
		int co = 0;
		cout << "Vui long doi trong vai giay " << endl;
		ifstream myfile(this->FILE[this->k], ios::in);
		while (!myfile.eof()) {
			getline(myfile, line);
			co++;
			if (co != 1 && line != "") {
				istringstream stm(line);
				getline(stm, token, ',');

				getline(stm, token, ',');
				ID = token; 
				getline(stm, token, ',');
				if (token != "" && to_double(token) == diem) {
					dem++;
				}
				getline(stm, token, ',');
				if (token != "" && to_double(token) == diem) {
					dem++;
				}
				getline(stm, token, ',');
				if (token != "" && to_double(token) == diem) {
					dem++;
				}
				getline(stm, token, ',');
				//
				if (token != "" && to_double(token) == diem) {
					dem++;
				}
				getline(stm, token, ',');
				//
				if (token != "" && to_double(token) == diem) {
					dem++;
				}
				getline(stm, token, ',');
				if (token != "" && to_double(token) == diem) {
					dem++;
				}
				getline(stm, token, ',');
				if (token != "" && to_double(token) == diem) {
					dem++;
				}
				getline(stm, token, ',');
				if (token != "" && to_double(token) == diem) {
					dem++;
				}
				getline(stm, token, ',');
				if (token != "" && to_double(token) == diem) {
					dem++;
				}
				getline(stm, token, ',');
				if (token != "" && to_double(token) == diem) {
					dem++;
				}
				getline(stm, token, ',');
				if (token != "" && to_double(token) == diem) {
					dem++;
				}
				if (dem) {
					temp.push_back(line);
					count++;
				}
				dem = 0; 
			}
		}
		auto it = temp.begin();
		do {
			
			system("cls");
			cout << "Dang duyet nam " << this->nam[this->k] << endl;
			cout << "Co tat ca " << count << " ket qua" << endl;
			cout << "Xem truoc ket qua " << macdinh << endl;
			Process_before_PR(*it,diem1);
			cout << "\n1. Ban muon xem chi tiet ? " << endl;
			cout << "2. Tuy chon ket qua muon xem ? " << endl;
			cout << "3. Lui lai ket qua truoc ? " << endl;
			cout << "4. Tiep den ket qua tiep theo ? " << endl;
			cout << "5. Quay lai" << endl;
			cout << "Xin moi chon: ";
			cin >> selec;
			cin.ignore();
			if (selec != 1 && selec != 2 && selec != 3 && selec == 4 && selec == 5){
				cout << "Moi nhap lai: " << endl;
			}
			switch (selec)
			{
			case 1: {
				this->Data_set_form_line(*it);
				this->Get_data();
			}; break;
			case 2: {
				int n;
				cout << "Ban muon xem ket qua o vi tri: ";
				cin >> n;
				cin.ignore();
				if (n < count) {
					if (macdinh < n) {
						for (double i = macdinh; i < n; i++)it++;
					}
					else if (macdinh > n) {
						for (double i = macdinh; i > n; i--)it--;
					}
					macdinh = n;
				}
				else {
					cout << "Vi pham gioi han !!" << endl; 
					system("pause");
				}
				
			}break;
			case 3: {
				if (it != temp.begin()) {
					it--;
					macdinh--;
					
				}
				else {
					cout << "Khong co cai gi o phia truoc ca " << endl;
					system("pause");
				}
			}break;
			case 4: {
				it++;
				macdinh++;
			
			}break; 
			case 5:switvh = false;
			}
		} while (switvh);

	}
	void Set_data_by_diem_theo_mon_ko_matinh(string diem1, size_t n = 0) {
		size_t i = 0;
		int count = 0;
		double diem = to_double(diem1);
		string TOAN = "", VAT_Li = "", HOA_HOC = "", SINH_HOC = "", NGU_VAN = "", NGOAI_NGU = "", DIA_LY = "", GDCD = "", LICH_SU = "", KHTN = "", KHXH = "", ID;
		string line, token, ma_nn;
		ifstream myfile(FILE[this->k], ios::in);
		//,Code,Diali,GDCD,Hoahoc,KHTN,KHXH,LichSu,Ngoaingu,Nguvan,Sinhhoc,Toan,Vatli,city
		while (!myfile.eof())
		{
			getline(myfile, line);
			count++;
			if (count != 1 && line != "") {
				istringstream stm(line);
				getline(stm, token, ',');

				getline(stm, token, ',');
				//
				ID = token;
				getline(stm, token, ',');
				DIA_LY = token;
				if (this->selection == 6) {
						if (to_double(DIA_LY) == diem)i++;
				}
				getline(stm, token, ',');
				GDCD = token;
				if (this->selection == 8) {
					if (to_double(GDCD) == diem)i++;
				}
				getline(stm, token, ',');
				HOA_HOC = token;
				if (this->selection == 3) {
					
						
					if (to_double(HOA_HOC) == diem)i++;
					
				}
				getline(stm, token, ',');
				//
				KHTN = token;
				if (this->selection == 9) {
					
						
					if (to_double(KHTN) == diem)i++;
					
				}
				getline(stm, token, ',');
				//
				KHXH = token;
				if (this->selection == 10) {
					
						
					if (to_double(KHXH) == diem)i++;
					
				}
				getline(stm, token, ',');
				LICH_SU = token;
				if (this->selection == 7) {
					
						
					if (to_double(LICH_SU) == diem)i++;
					
				}
				getline(stm, token, ',');
				NGOAI_NGU = token;
				if (this->selection == 2) {
					
						
					if (to_double(NGOAI_NGU) == diem)i++;
					
				}
				getline(stm, token, ',');
				NGU_VAN = token;
				if (this->selection == 1) {
					
						
					if (to_double(NGU_VAN) == diem)i++;
					
				}
				getline(stm, token, ',');
				SINH_HOC = token;
				if (this->selection == 4) {
					
					
					if (to_double(SINH_HOC) == diem)i++;
					
				}
				getline(stm, token, ',');
				TOAN = token;
				if (this->selection == 0) {
					
						
					if (to_double(TOAN) == diem) {
						
						i++;
					}
					
				}
				getline(stm, token, ',');
				VAT_Li = token;
				if (this->selection == 5) {
					
						
					if (to_double(VAT_Li) == diem)i++;
					
				}
				getline(stm, token, ',');
				getline(stm, token, ',');
				if (NGOAI_NGU != "")
				{
					ma_nn = token;
				}
				if ( i == n) {
					Student.STUDENT_CODE_ID = ID;
					Student.TOAN = TOAN;
					Student.NGU_VAN = NGU_VAN;
					Student.NGOAI_NGU = NGOAI_NGU;
					Student.KHTN = KHTN;
					Student.KHXH = KHXH;
					Student.LICH_SU = LICH_SU;
					Student.DIA_LY = DIA_LY;
					Student.GDCD = GDCD;
					Student.VAT_Li = VAT_Li;
					Student.SINH_HOC = SINH_HOC;
					Student.HOA_HOC = HOA_HOC;
					Student.ma_nn = ma_nn;
					return; 
				}
			}
		} 
	}//
	void Get_data() {
		cout << "SBD: " << Student.STUDENT_CODE_ID << endl;
		if (Student.TOAN != "")cout << "Toan: " << Student.TOAN << "   ";
		if(Student.NGU_VAN != "")cout << "Van: " << Student.NGU_VAN;
		if (Student.NGOAI_NGU != "")cout << "   " << "Ngoai ngu: " << Student.NGOAI_NGU; cout << endl;
		if (Student.KHTN != "" && Student.KHXH != "")
		{
			cout << "KHTN: " << Student.KHTN << "   " << "Vat li: " << Student.VAT_Li << "   " << "Hoa Hoc: " << Student.HOA_HOC << "   " << "Sinh hoc: " << Student.SINH_HOC << endl;
			cout << "KHXH: " << Student.KHXH << "   " << "Lich Su: " << Student.LICH_SU << "   " << "Dia Ly: " << Student.DIA_LY << "   " << "GDCD: " << Student.GDCD << endl;
		}
		else if (Student.KHTN != "" && Student.KHXH == "")
		{
			cout << "KHTN: " << Student.KHTN << "   " << "Vat li: " << Student.VAT_Li << "   " << "Hoa Hoc: " << Student.HOA_HOC << "   " << "Sinh hoc: " << Student.SINH_HOC << endl;
		}
		else if (Student.KHTN == "" && Student.KHXH != "") {
			cout << "KHXH: " << Student.KHXH << "   " << "Lich su: " << Student.LICH_SU << "   " << "Dia Ly: " << Student.DIA_LY << "   " << "GDCD: " << Student.GDCD << endl; 
		}
		else if (Student.KHTN == "" && Student.KHXH == "") {
			if (Student.DIA_LY != "")cout << "Dia Ly: " << Student.DIA_LY << "   ";
			if (Student.LICH_SU != "")cout << "Lich su: " << Student.LICH_SU << "   ";
		}
		system("pause");
	}
	bool check_matinh(int ma_tinh) {
		for (int i = 0; i < 63; i++) {
			if (ma_tinh == this->Ma_Tinh[i]) {
				this->m = i;
				return true;
			}
		}
		return false; 
	}
	void nhap_matinh() {
		int ma_tinh;
		cout << "Nhap ma tinh (VD: 1): ";
		cin >> ma_tinh;
		cin.ignore();
		while (!this->check_matinh(ma_tinh)) {
			cout << "Ma tinh khong hop le ! Moi nhap lai (VD: 1): ";
			cin >> ma_tinh;
			cin.ignore();
		}
	}
	string sothisinh() {
		string line, token,ma = to_string(this->Ma_Tinh[this->m]); 
		ifstream myfile(this->dir[this->k] + "Thong_Ke\\thisinhtinh.txt",ios::in);
		while (!myfile.eof()) {
			getline(myfile, line);
			if (line != "") {
				istringstream stm(line);
				getline(stm, token,',');
				if (token == ma) {
					getline(stm, token, ',');
					return token;
				}
			}
		}
	}
	void Process_with_Xemdiemthisinh_n_matinh(double n , string size) {
		double size_ss = 0; 
		double count = 0;
		
		string line, token, ma_tinh, ma_nn;
		istringstream ss(size); ss >> size_ss;
		while (n > size_ss || n < 0) {
			cout << "So ban vua nhap vi pham gioi han \nVui long nhap lai: " << endl; 
			cin >> n; 
			cin.ignore();
		}
		ifstream myfile(this->FILE_TINH[this->k] + this->Tinh[this->m] + ".txt", ios::in);
		while (!myfile.eof()) {
			getline(myfile, line);
			count++;
			if (line != "" && count - 1 == n) {
				istringstream stm(line);
				

				getline(stm, token, ',');
				//
				Student.STUDENT_CODE_ID = token;
				getline(stm, token, ',');
				Student.DIA_LY = token;
				getline(stm, token, ',');
				Student.GDCD = token;
				getline(stm, token, ',');
				Student.HOA_HOC = token;
				getline(stm, token, ',');
				//
				Student.KHTN = token;
				getline(stm, token, ',');
				//
				Student.KHXH = token;
				getline(stm, token, ',');
				Student.LICH_SU = token;
				getline(stm, token, ',');
				Student.NGOAI_NGU = token;
				getline(stm, token, ',');
				Student.NGU_VAN = token;
				getline(stm, token, ',');
				Student.SINH_HOC = token;
				getline(stm, token, ',');
				Student.TOAN = token;
				getline(stm, token, ',');
				Student.VAT_Li = token;
				getline(stm, token, ',');
				ma_tinh = token;
				getline(stm, token, ',');
				if (Student.NGOAI_NGU != "")
				{
					Student.ma_nn = token;
				}
			}
		}
	}
	void Xemdiemthisinh_n_matinh() {
		this->nhap_matinh();
		double n; 
		cout << "Dang duyet nam " << this->nam[this->k] << endl;
		cout << "Dang duyet theo tinh thanh " << this->Tinh[this->m] << endl;
		cout << "Tinh thanh " << this->Tinh[this->m] << " co: " << this->sothisinh() << " thi sinh" << endl; 
		cout << "Ban muon xem diem thi sinh thu: ";
		cin >> n; 
		cin.ignore();
		cout << "Vui long doi trong vai giay " << endl;
		this->Process_with_Xemdiemthisinh_n_matinh(n, this->sothisinh());
		this->Get_data();
	}





	// Tim kiem ho so thi sinh theo diem liet cua tung mon 

	void Search_diemliet_theomon() {
		size_t n;
		this->nhap_khoi();
		cout << "Ban muon xem diem thi sinh thu: ";
		cin >> n;
		cin.ignore();
		cout << "Vui long doi trong vai giay " << endl;
		this->Set_data_diemliet_theo_mon(n);
		this->Get_data();
		system("pause");
	}
	// Tim kiem ho so  thi sinh theo diem liet cua tung ma tinh
	void Search_diemliet_theomatinh() {
		size_t n;
		string ma;
		this->nhap_matinh();
		ma = to_string(this->Ma_Tinh[this->m]);
		
		cout << "Ban muon xem diem thi sinh thu: ";
		cin >> n;
		cin.ignore();
		cout << "Vui long doi trong vai giay " << endl;
		this->Set_data_diemliet_theo_matinh(n, ma);
		this->Get_data();
		system("pause");
	}
	// Tim kiem ho so thi sinh theo diem liet cua tung mon va ma tinh 
	void Search_diemliet_theo_matinhmon() {
		size_t n;
		string ma;
		this->nhap_matinh();
		ma = to_string(this->Ma_Tinh[this->m]);
		this->nhap_khoi();
		cout << "Ban muon xem diem thi sinh thu: ";
		cin >> n;
		cin.ignore();
		cout << "Vui long doi trong vai giay " << endl;
		this->Set_data_diemliet_theo_mon_matinh(n, ma);
		this->Get_data();
		system("pause");
	}
	// Tim kiem ho so thi sinh theo diem liet 
	void Search_diemliet_() {
		this->Set_data_diemliet();
	}


	// Tim kiem ho so thi sinh theo diem toi da
	void Search_diemtoida_theomon() {
		size_t n;
		this->nhap_khoi();
		cout << "Ban muon xem diem thi sinh thu: ";
		cin >> n;
		cin.ignore();
		cout << "Vui long doi trong vai giay " << endl;
		this->Set_data_by_diem_theo_mon_ko_matinh("10.0", n);
		this->Get_data();
		
	}
	void Search_diemtoida_theomatinh() {
		size_t n;
		string ma;
		this->nhap_matinh();
		ma = to_string(this->Ma_Tinh[this->m]);

		cout << "Ban muon xem diem thi sinh thu: ";
		cin >> n;
		cin.ignore();
		cout << "Vui long doi trong vai giay " << endl;
		this->Set_data_by_diem_not_mon_theo_matinh("10.0", n, ma);
		this->Get_data();

	}
	void Search_diemtoida_theo_matinhmon() {
		size_t n;
		string ma;
		this->nhap_matinh();
		ma = to_string(this->Ma_Tinh[this->m]);
		this->nhap_khoi();
		cout << "Ban muon xem diem thi sinh thu: ";
		cin >> n;
		cin.ignore();
		cout << "Vui long doi trong vai giay " << endl;
		this->Set_data_by_diem_theo_mon_theo_matinh("10.0", n, ma);
		this->Get_data();
	}
	void Search_diemtoida() {
		this->Set_data_by_diem_nothing("10.0");
	}



	bool namthi(string nam) {
		int i = 0; 
		while (i != 3) {
			if (nam == this->nam[i]) {
				this->k = i;
				return true;
				
			}
			i++;
		}
	}

	void nhapnamxet() {
		string nam;
		cout << "Nhap nam (2018 -> 2020) : ";
		getline(cin, nam);
		while (!namthi(nam))
		{
			cout << "Moi nhap lai nam: (2018 -> 2020)" << endl;
			getline(cin, nam);
		}
	}


	// Tim kiem ho so sinh vien qua  qua id 
	void Search_data_id() {
		this->Set_data_by_id();
	}

	//
	void set_k(int k) {
		this->k = k;
	}
	//


	// Tim kiem ho so sinh vien theo diem nhap cua ma tinh 
	void Search_diemthi_theoma() {
		size_t n;
		string diem_thi;
		string ma;
		this->nhap_matinh();
		ma = to_string(this->Ma_Tinh[this->m]);
		
		cout << "Ban muon xem diem thi sinh thu: ";
		cin >> n;
		cin.ignore();
		cout << "Nhap so diem ma ban can tim kiem: ";
		getline(cin, diem_thi);
		while (!this->check_diemthi(diem_thi)) {
			cout << "So diem ban nhap vi pham gioi han " << endl;
			cout << "Xin nhap lai diem ma ban cam tim kiem: ";
			getline(cin, diem_thi);
		}
		cout << "Vui long doi trong vai giay " << endl;
		this->Set_data_by_diem_not_mon_theo_matinh(diem_thi,n,ma);
		this->Get_data();
	}
	//  Tim kiem ho so sinh vien theo diem nhap cua mon
	void Search_diemthi_theomon() {
		size_t n;
		string diem_thi;
		this->nhap_khoi();
		cout << "Ban muon xem diem thi sinh thu: ";
		cin >> n;
		cin.ignore();
		cout << "Nhap so diem ma ban can tiem kiem: ";
		getline(cin, diem_thi);
		while (!this->check_diemthi(diem_thi)) {
			cout << "So diem ban nhap vi pham gioi han " << endl;
			cout << "Xin nhap lai diem ma ban cam tim kiem: ";
			getline(cin, diem_thi);
		}
		cout << "Vui long doi trong vai giay " << endl;
		this->Set_data_by_diem_theo_mon_ko_matinh(diem_thi, n);
		
	}
	// Tim kiem ho so thi sinh theo diem nhap cua mon va theo ma tinh 
	void Search_diemthi_theomon_matinh()
	{
		size_t n;
		string diem_thi;
		string ma; 
		this->nhap_matinh();
		ma = to_string(this->Ma_Tinh[this->m]);
		this->nhap_khoi();
		cout << "Ban muon xem diem thi sinh thu: ";
		cin >> n;
		cin.ignore();
		cout << "Nhap so diem ma ban can tim kiem: ";
		getline(cin, diem_thi);
		while (!this->check_diemthi(diem_thi)) {
			cout << "So diem ban nhap vi pham gioi han " << endl;
			cout << "Xin nhap lai diem ma ban cam tim kiem: ";
			getline(cin, diem_thi);
		}
		cout << "Vui long doi trong vai giay " << endl;
		this->Set_data_by_diem_theo_mon_theo_matinh(diem_thi, n, ma);
		this->Get_data();
	}
	// Tim kiem ho so thi sinh theo diem nhap khong phu thuoc yeu to 
	void Search_diemthi_nothing() {
		string diem_thi;
		cout << "Nhap diem thi: "; 
		getline(cin, diem_thi);
		while (!this->check_diemthi(diem_thi)) {
			cout << "So diem ban nhap vi pham gioi han " << endl;
			cout << "Xin nhap lai diem ma ban cam tim kiem: ";
			getline(cin, diem_thi);
		}
		
		this->Set_data_by_diem_nothing(diem_thi);
	}




	// Tim kiem ho so thi sinh theo thu tu sinh vien theo ma tinh
	void Search_diemthi_thisinh_matinh() {
		this->Xemdiemthisinh_n_matinh();
	}
};
class Searr :private search_tool
{
public:
	void Find_Set_k(int k) {
		this->set_k(k);
	}
	// Find diemliet 
	void Find_diemliet_mon() {
		this->Search_diemliet_theomon();
		this->Get_data();
	}
	void Find_diemliet_matinh() {
		this->Search_diemliet_theomatinh();
		this->Get_data();
	}
	void Find_diemliet_both_ma_mon() {
		this->Search_diemliet_theo_matinhmon();
		this->Get_data();
	}
	void Find_diemliet() {
		this->Search_diemliet_();
	}



	// Find diem nhap tu ban phim 
	void Find_diem_mon() {
		this->Search_diemthi_theomon();
		this->Get_data();
	}
	void Find_diem_matinh() {
		this->Search_diemthi_theoma();
		this->Get_data();
	}
	void Find_diem_both_ma_mon() {
		this->Search_diemthi_theomon_matinh();
		this->Get_data();
	}
	void Find_diem() {
		this->Search_diemthi_nothing();
	}
	// Find ho so thi sinh 
	void Find_SBD() {
		this->Search_data_id();
		this->Get_data();
	}

	void Find_xet_nam() {
		this->nhapnamxet();
	}

	// Find ho so thi sinh theo thu tu sinh vien theo  ma
	void Find_thutu_matinh() {
		this->Search_diemthi_thisinh_matinh();
	}


	// Find ho so thi sinh theo diem toi da
	void Find_diemtoida() {
		this->Search_diemtoida();
	}
	void Find_diemtoida_mon() {
		this->Search_diemtoida_theomon();
	}
	void Find_diemtoida_matinh() {
		this->Search_diemtoida_theomatinh();
		this->Get_data();
	}
	void Find_diemtoida_both_ma_mon() {
		this->Search_diemtoida_theo_matinhmon();
		this->Get_data();
	}
};
typedef Searr Find;