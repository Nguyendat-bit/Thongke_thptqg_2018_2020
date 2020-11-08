#include"Import data.h";
#include"Thongke.h";

Find FIND;


///
/// string a[3]{ "2018", "2019", "2020" };
///	string PATH_FILE[3]{ PATH_1, PATH_2,PATH_3 };
/// string File[5]{"Thong_Ke\\Diem10.txt","Thong_Ke\\Diemliet.txt","Thong_Ke\\tong10tungmon.txt","Thong_Ke\\top10thukhoa.txt","Thong_Ke\\dtb.txt"};

Thongke<> POW;

// THONG KE RA MAN HINH 
struct Thu_Khoa {
	string ID; 
	double Diem; 
	string Khoi;
};
string BASE_MATH_LATE_ON_SCREEN::MaTinh(string code) {
	int bien;
	int i = 0;
	stringstream ss(code);
	ss >> bien;
	while (i != 63) {
		if (this->Ma_Tinh[i] == bien)return this->Tinh[i];
		i++;
	}
	return this->Tinh[i];
	
}
void BASE_MATH_LATE_ON_SCREEN::THONGKE_THISINH_TINH()
{
	vector<double> point;
	vector<string>  list;
	system("cls");
	string line, token,ma,count_thisinh; 
	ifstream myfile(this->PATH_FILE[this->k] + this->File[5], ios::in); 
	out << "             THONG KE SO THI SINH DU THI TREN TUNG TINH THANH NAM " << this->a[this->k] << endl; 
	while (!myfile.eof()) {
		getline(myfile, line);
		if (line != "") {
			istringstream stm(line); 
			getline(stm, token, ',');
			ma = token; 
			getline(stm, token, ',');
			count_thisinh = token;
			out << this->MaTinh(ma) << "(" << ma << ")" << "  " << count_thisinh << endl; 
			list.push_back(this->MaTinh(ma));
			point.push_back(to_double(count_thisinh));
		}
	}
	cout << endl; 
	POW.SS(this->a[this->k], point, list);
	FIND.Find_Set_k(this->get_k());
	{
		cout << "\n                         =========== SEARCH TOOL ===========\n";
		bool key = true;
		int c;
		do {
			
			cout << "\n1. Tim diem thi thi sinh theo SBD\n";
			cout << "2. Tim diem thi thi sinh theo so thu tu dua tren ma tinh \n";
			cout << "3. Tim diem thi thi sinh theo diem duoc nhap\n";
			cout << "4. Khong quan tam\n";
			cout << "Xin moi chon: ";
			cin >> c; 
			cin.ignore();
			if (c != 1 && c != 2 && c != 3 && c != 4)cout << "Xin moi nhap lai: ";
			switch (c) {
			case 1: {
				FIND.Find_SBD();
				this->THONGKE_THISINH_TINH();
			}break;
			case 2: {
				FIND.Find_thutu_matinh();
				this->THONGKE_THISINH_TINH();
			}break;
			case 3: {
				FIND.Find_diem();
				this->THONGKE_THISINH_TINH();
			}break;
			case 4:key = false;
			}
		} while (key);
	}
}
void BASE_MATH_LATE_ON_SCREEN::THONGKE_OUT_MARK(int selec)
{
	int count = 0; 
	system("cls");
	ifstream myfile(this->PATH_FILE[this->k] + this->File[6], ios::in);
	double diem;
	vector<double> point;
	vector<string>  list;
	list.push_back("Toan");
	list.push_back("Ngu Van");
	list.push_back("Ngoai Ngu");
	list.push_back("Vat Ly");
	list.push_back("Hoa Hoc");
	list.push_back("Sinh Hoc");
	list.push_back("GDCD");
	list.push_back("Lich Su");
	list.push_back("Dia li");
	string line, token;

	//myfile_o << toan << ',' << van << ',' << anh << ',' << ly << ',' << hoa << ',' << sinhhoc << ',' << cd << ',' << su << ',' << dia;
	while (!myfile.eof())
	{
		
		getline(myfile, line);
		count++;
		if (count != 1 && line != "")
		{
			istringstream stm(line);
			getline(stm, token, ',');
			stringstream ss(token);
			ss >> diem;
			point.push_back(diem);
			getline(stm, token, ',');
			stringstream ss1(token);
			ss1 >> diem;
			point.push_back(diem);
			getline(stm, token, ',');
			stringstream ss2(token);
			ss2 >> diem;
			point.push_back(diem);
			getline(stm, token, ',');
			stringstream ss3(token);
			ss3 >> diem;
			point.push_back(diem);
			getline(stm, token, ',');
			stringstream ss4(token);
			ss4 >> diem;
			point.push_back(diem);
			getline(stm, token, ',');
			stringstream ss5(token);
			ss5 >> diem;
			point.push_back(diem);
			getline(stm, token, ',');
			stringstream ss6(token);
			ss6 >> diem;
			point.push_back(diem);
			getline(stm, token, ',');
			stringstream ss7(token);
			ss7 >> diem;
			point.push_back(diem);
			getline(stm, token, ',');
			stringstream ss8(token);
			ss8 >> diem;
			point.push_back(diem);
		}
	}
	if (selec == 1 || selec == 3) {

		out << "		             THONG KE DIEM LIET TUNG MON NAM " << this->a[this->k]  << endl;
		out << "Toan: " << point[0] << endl;
		out << "Van: " << point[1] << endl;
		out << "Ngoai Ngu: " << point[2] << endl;
		out << "Vat ly: " << point[3] << endl;
		out << "Hoa Hoc: " << point[4] << endl;
		out << "Sinh hoc: " << point[5] << endl;
		out << "Lich Su: " << point[6] << endl;
		out << "Dia li: " << point[7] << endl;
		out << "GDCD: " << point[8] << endl;
	}
	
	if (selec == 1 || selec == 2) {
		cout << endl;
		POW.SS(this->a[this->k], point, list);
	}
	FIND.Find_Set_k(this->get_k());
	{
		cout << "\n                        =========== SEARCH TOOL ===========\n";
		bool key = true;
		int c;
		do {

			cout << "\n1. Tim diem thi thi sinh theo SBD\n";
			cout << "2. Tim diem thi thi sinh theo diem liet tung mon \n";
			cout << "3. Tim diem liet cua thi sinh\n";
			cout << "4. Tim diem thi thi sinh theo diem duoc nhap \n";
			cout << "5. Khong quan tam\n";
			cout << "Xin moi chon: ";
			cin >> c;
			cin.ignore();
			if (c != 1 && c != 2 && c != 3 && c != 4 && c != 5)cout << "Xin moi nhap lai: ";
			switch (c) {
			case 1: {
				FIND.Find_SBD();
				this->THONGKE_OUT_MARK(1);
			}break;
			case 2: {
				FIND.Find_diemliet_mon();
				this->THONGKE_OUT_MARK(1);
			}break;
			case 3: {
				FIND.Find_diemliet();
				this->THONGKE_OUT_MARK(1);
			}break;
			case 4: {
				FIND.Find_diem();
				this->THONGKE_OUT_MARK(1);
			}break;
			case 5:key = false;
			}
		} while (key);
	}
	
}
void BASE_MATH_LATE_ON_SCREEN::THONGKE_FULL_BANG_10()
{
	vector<double> point; 
	vector<string> list;
	system("cls");
	string line, token,ma,count_diem10;
	ifstream myfile(this->PATH_FILE[this->k] + this->File[0], ios::in);
	out << "		             THONG KE SO DIEM TOI DA TUNG TINH THANH NAM " << this->a[this->k] << endl;
	while (!myfile.eof()) {
		getline(myfile, line);
		if (line != "") {
			istringstream stm(line);
			getline(stm, token, ',');
			ma = token; 
			getline(stm, token, ',');
			count_diem10 = token;
			out << this->MaTinh(ma) << "(" << ma << ")" << "  " << count_diem10 << endl;
			list.push_back(MaTinh(ma));
			point.push_back(to_double(count_diem10));
		}
	}
	cout << endl; 
	cout << endl; 
	POW.SS(this->a[this->k], point, list);
	FIND.Find_Set_k(this->get_k());
	{
		cout << "\n                          =========== SEARCH TOOL ===========\n";
		bool key = true;
		int c;
		do {

			cout << "\n1. Tim diem thi thi sinh theo SBD\n";
			cout << "2. Tim diem thi toi da cua thi sinh theo so thu tu dua tren ma tinh \n";
			cout << "3. Tim diem thi toi da cua thi sinh\n";
			cout << "4. Tim diem thi thi sinh theo diem duoc nhap \n";
			cout << "5. Khong quan tam\n";
			cout << "Xin moi chon: ";
			cin >> c;
			cin.ignore();
			if (c != 1 && c != 2 && c != 3 && c != 4 && c != 5)cout << "Xin moi nhap lai: ";
			switch (c) {
			case 1: {
				FIND.Find_SBD();
				this->THONGKE_FULL_BANG_10();
			}break;
			case 2: {
				FIND.Find_diemtoida_matinh();
				this->THONGKE_FULL_BANG_10();
			}break;
			case 3: {
				FIND.Find_diemtoida();
				this->THONGKE_FULL_BANG_10();
			}break;
			case 4: {
				FIND.Find_diem();
				this->THONGKE_FULL_BANG_10();
			}break;
			case 5:key = false;
			}
		} while (key);
	}
}
void BASE_MATH_LATE_ON_SCREEN::THONGKE_FULL_BANG_MUST_OUT()
{
	vector<string> list;
	vector<double> point;
	system("cls");
	string line, token, ma, count_liet; 
	out << "		             THONG KE SO DIEM LIET TUNG TINH THANH NAM " << this->a[this->k] << endl;
	ifstream myfile(this->PATH_FILE[this->k] + this->File[1], ios::in);
	while (!myfile.eof())
	{
		getline(myfile, line);
		if (line != "")
		{
			istringstream stm(line);
			getline(stm, token, ',');
			ma = token;
			getline(stm, token, ',');
			count_liet = token; 
			out << this->MaTinh(ma) << "(" << ma << ")" << "  " << count_liet << endl;
			list.push_back(MaTinh(ma));
			point.push_back(to_double(count_liet));

		}
	}
	cout << endl;
	cout << endl; 
	POW.SS(this->a[this->k], point, list);
	FIND.Find_Set_k(this->get_k());
	{
		cout << "\n                          =========== SEARCH TOOL ===========\n";
		bool key = true;
		int c;
		do {

			cout << "\n1. Tim diem thi thi sinh theo SBD\n";
			cout << "2. Tim diem liet cua thi sinh theo so thu tu dua tren ma tinh \n";
			cout << "3. Tim diem liet cua thi sinh\n";
			cout << "4. Tim diem thi thi sinh theo diem duoc nhap \n";
			cout << "5. Khong quan tam\n";
			cout << "Xin moi chon: ";
			cin >> c;
			cin.ignore();
			if (c != 1 && c != 2 && c != 3 && c != 4 && c != 5)cout << "Xin moi nhap lai: ";
			switch (c) {
			case 1: {
				FIND.Find_SBD();
				this->THONGKE_FULL_BANG_MUST_OUT();
			}break;
			case 2: {
				FIND.Find_diemliet_matinh();
				this->THONGKE_FULL_BANG_MUST_OUT();
			}break;
			case 3: {
				FIND.Find_diemliet();
				this->THONGKE_FULL_BANG_MUST_OUT();
			}break;
			case 4: {
				FIND.Find_diem();
				this->THONGKE_FULL_BANG_MUST_OUT();
			}break;
			case 5:key = false;
			}
		} while (key);
	}
}
 void BASE_MATH_LATE_ON_SCREEN::THONGKE_BANG_10(int selec = 0)
{
	// this->nhap();
	 system("cls");
	 int i = 0;
	 vector<double> point;
	 vector<string> list;
	 string ma_tinh,diem; 
	 double diemthat;
	 string line, token; 
	 ifstream myfile(this->PATH_FILE[this->k] + this->File[0], ios::in);
	 out << "		             TOP 10 TINH THANH CO NHIEU DIEM TOI DA NHAT NAM " << this->a[this->k] << endl;
	 while (i != 10) {
		 getline(myfile, line);
		 istringstream stm(line);
		 getline(stm, token, ',');
		 ma_tinh = token;
		 getline(stm, token, ',');
		 diem = token;
			 if(selec == 1 || selec == 3)
				 out << this->MaTinh(ma_tinh) << "(" << ma_tinh << ")" << "  " << diem << endl;
			 stringstream ss(diem);
			 ss >> diemthat;
			 point.push_back(diemthat);
			 list.push_back(this->MaTinh(ma_tinh));
			 i++;
	 }
	
	 point.resize(10);
	 list.resize(10);
	 if (selec == 1 || selec == 2) {
		 out << endl;
		POW.SS(this->a[this->k], point, list);
	 }
	 FIND.Find_Set_k(this->get_k());
	 {
		 cout << "\n                          =========== SEARCH TOOL ===========\n";
		 bool key = true;
		 int c;
		 do {

			 cout << "\n1. Tim diem thi thi sinh theo SBD\n";
			 cout << "2. Tim diem thi toi da cua thi sinh theo so thu tu dua tren ma tinh \n";
			 cout << "3. Tim diem thi toi da cua thi sinh\n";
			 cout << "4. Tim diem thi thi sinh theo diem duoc nhap \n";
			 cout << "5. Khong quan tam\n";
			 cout << "Xin moi chon: ";
			 cin >> c;
			 cin.ignore();
			 if (c != 1 && c != 2 && c != 3 && c != 4 && c != 5)cout << "Xin moi nhap lai: ";
			 switch (c) {
			 case 1: {
				 FIND.Find_SBD();
				 this->THONGKE_BANG_10(1);
			 }break;
			 case 2: {
				 FIND.Find_diemtoida_matinh();
				 this->THONGKE_BANG_10(1);
			 }break;
			 case 3: {
				 FIND.Find_diemtoida();
				 this->THONGKE_BANG_10(1);
			 }break;
			 case 4: {
				 FIND.Find_diem();
				 this->THONGKE_BANG_10(1);
			 }break;
			 case 5:key = false;
			 }
		 } while (key);
	 }
}
 void BASE_MATH_LATE_ON_SCREEN::THONGKE_BANG_MUST_OUT(int selec = 0) {
	// this->nhap(); 
	 system("cls");
	 int i = 0;
	vector<double> point;
	vector<string> list;
	 string ma_tinh, diem;
	 double diemthat;
	 string line, token;
	 ifstream myfile(this->PATH_FILE[this->k] + this->File[1], ios::in);
	 out << "		             TOP 10 TINH CO NHIEU DIEM LIET NHAT NAM " << this->a[this->k] << endl;
	 while (i != 10) {
		 getline(myfile, line);
		 istringstream stm(line);
		 getline(stm, token, ',');
		 ma_tinh = token;
		 getline(stm, token, ',');
		 diem = token;
		 if(selec ==1 || selec == 3)out << this->MaTinh(ma_tinh) << "(" << ma_tinh << ")" << "  " << diem << endl;
		 stringstream ss(diem);
		 ss >> diemthat;
		 point.push_back(diemthat);
		 list.push_back(this->MaTinh(ma_tinh));
		 i++;
	 }
	 point.resize(10);
	 list.resize(10);
	 if (selec == 1 || selec == 2)
	 {
		 out  << endl;
		 POW.SS(this->a[this->k], point, list);
	 }
	 FIND.Find_Set_k(this->get_k());
	 {
		 cout << "\n                          =========== SEARCH TOOL ===========\n";
		 bool key = true;
		 int c;
		 do {
			
			 cout << "\n1. Tim diem thi thi sinh theo SBD\n";
			 cout << "2. Tim diem liet cua thi sinh theo so thu tu dua tren ma tinh \n";
			 cout << "3. Tim diem liet cua thi sinh\n";
			 cout << "4. Tim diem thi thi sinh theo diem duoc nhap \n";
			 cout << "5. Khong quan tam\n";
			 cout << "Xin moi chon: ";
			 cin >> c;
			 cin.ignore();
			 if (c != 1 && c != 2 && c != 3 && c != 4 && c != 5)cout << "Xin moi nhap lai: ";
			 switch (c) {
			 case 1: {
				 FIND.Find_SBD();
				 this->THONGKE_BANG_MUST_OUT(1);
			 }break;
			 case 2: {
				 FIND.Find_diemliet_matinh();
				 this->THONGKE_BANG_MUST_OUT(1);
			 }break;
			 case 3: {
				 FIND.Find_diemliet();
				 this->THONGKE_BANG_MUST_OUT(1);
			 }break;
			 case 4: {
				 FIND.Find_diem();
				 this->THONGKE_BANG_MUST_OUT(1);
			 }break;
			 case 5:key = false;
			 }
		 } while (key);
	 }
 }
 void BASE_MATH_LATE_ON_SCREEN::THONGKE_DIEM10(int selec = 0) {
	// this->nhap(); 
	 system("cls");
	 int count = 0; 
	 ifstream myfile(this->PATH_FILE[this->k] + this->File[2], ios::in);
	 double diem; 
	 vector<double> point;
	 vector<string>  list;
	 list.push_back("Toan");
	 list.push_back("Ngu Van");
	 list.push_back("Ngoai Ngu");
	 list.push_back("Vat Ly");
	 list.push_back("Hoa Hoc");
	 list.push_back("Sinh Hoc");
	 list.push_back("GDCD");
	 list.push_back("Lich Su");
	 list.push_back("Dia li");
	 string line, token;
	
	 //myfile_o << toan << ',' << van << ',' << anh << ',' << ly << ',' << hoa << ',' << sinhhoc << ',' << cd << ',' << su << ',' << dia;
	 while (!myfile.eof())
	 {
		 getline(myfile, line);
		 count++;
		 if (count != 1 && line != "")
		 {
			 istringstream stm(line);
			 getline(stm, token, ',');
			 stringstream ss(token);
			 ss >> diem;
			 point.push_back(diem);
			 getline(stm, token, ',');
			 stringstream ss1(token);
			 ss1 >> diem;
			 point.push_back(diem);
			 getline(stm, token, ',');
			 stringstream ss2(token);
			 ss2 >> diem;
			 point.push_back(diem);
			 getline(stm, token, ',');
			 stringstream ss3(token);
			 ss3 >> diem;
			 point.push_back(diem);
			 getline(stm, token, ',');
			 stringstream ss4(token);
			 ss4 >> diem;
			 point.push_back(diem);
			 getline(stm, token, ',');
			 stringstream ss5(token);
			 ss5 >> diem;
			 point.push_back(diem);
			 getline(stm, token, ',');
			 stringstream ss6(token);
			 ss6 >> diem;
			 point.push_back(diem);
			 getline(stm, token, ',');
			 stringstream ss7(token);
			 ss7 >> diem;
			 point.push_back(diem);
			 getline(stm, token, ',');
			 stringstream ss8(token);
			 ss8 >> diem;
			 point.push_back(diem);
		 }
	 }
	 if (selec == 1 || selec == 3) {
		
		 out << "		             TONG SO DIEM TOI DA MOI MON NAM " << this->a[this->k] << endl;
		 out << "Toan: " << point[0] << endl;
		 out << "Van: " << point[1] << endl;
		 out << "Ngoai Ngu: " << point[2] << endl;
		 out << "Vat ly: " << point[3] << endl;
		 out << "Hoa Hoc: " << point[4] << endl;
		 out << "Sinh hoc: " << point[5] << endl;
		 out << "Lich Su: " << point[6] << endl;
		 out << "Dia li: " << point[7] << endl;
		 out << "GDCD: " << point[8] << endl;
	 }
	 if ( selec == 1 ||selec == 2) {
		 out  << endl;
		 POW.SS(this->a[this->k], point, list);
	 }
	 FIND.Find_Set_k(this->get_k());
	 {
		 cout << "\n                          =========== SEARCH TOOL ===========\n";
		 bool key = true;
		 int c;
		 do {
			
			 cout << "\n1. Tim diem thi thi sinh theo SBD\n";
			 cout << "2. Tim diem thi toi da cua thi sinh theo mon \n";
			 cout << "3. Tim diem thi toi da cua thi sinh\n";
			 cout << "4. Tim diem thi thi sinh theo diem duoc nhap \n";
			 cout << "5. Khong quan tam\n";
			 cout << "Xin moi chon: ";
			 cin >> c;
			 cin.ignore();
			 if (c != 1 && c != 2 && c != 3 && c != 4 && c != 5)cout << "Xin moi nhap lai: ";
			 switch (c) {
			 case 1: {
				 FIND.Find_SBD(); 
				 this->THONGKE_DIEM10(1);
			 }break;
			 case 2: {
				 FIND.Find_diemtoida_mon();
				 this->THONGKE_DIEM10(1);
			 }break;
			 case 3: {
				 FIND.Find_diemtoida();
				 this->THONGKE_DIEM10(1);
			 }break;
			 case 4: {
				 FIND.Find_diem();
				 this->THONGKE_DIEM10(1);
			 }break;
			 case 5:key = false;
			 }
		 } while (key);
	 }
 }
 void BASE_MATH_LATE_ON_SCREEN::THONGKE_THUKHOA_TQ() {
	 system("cls");
	 Thu_Khoa temp;
	 vector<Thu_Khoa> a;
	 ifstream myfile(this->PATH_FILE[this->k] + this->File[3], ios::in);
	 double diem; 
	 string line, token, ID, DIEM, KHOI_temp;
	 while (!myfile.eof()) {
		 getline(myfile, line);
		 if (line != "") {
			 istringstream stm(line);
			
			 getline(stm, token, ',');
			 ID = token;
			 getline(stm, token, ',');
			 DIEM = token;
			 getline(stm, token, ',');
			 KHOI_temp = token;
			 stringstream ss(DIEM);
			 ss >> diem; 
			 temp.Diem = diem; 
			 temp.ID = ID;
			 temp.Khoi = KHOI_temp;
			 a.push_back(temp);
		 }
	 }
	 for(auto it = a.begin(); it != a.end() - 1; it++)
		 for (auto jt = it + 1; jt != a.end(); jt++)
		 {
			 if (jt->Diem > it->Diem) {
				 swap(*jt, *it);
			 }
		 }
	 a.resize(10);
	 out << "             THONG KE TOP 10 THU KHOA TOAN QUOC: " << endl; 
	 for (int i = 0; i < 10; i++) {
		 out << "Ma Thi Sinh: " << a[i].ID << " So Diem: " << a[i].Diem << "  " << a[i].Khoi << endl;
	 }
	 FIND.Find_Set_k(this->get_k());
	 {
		 cout << "\n                          =========== SEARCH TOOL ===========\n";
		 bool key = true;
		 int c;
		 do {

			 cout << "\n1. Tim diem thi thi sinh theo SBD\n";
			 cout << "2. Tim diem thi thi sinh theo diem duoc nhap \n";
			 cout << "3. Khong quan tam\n";
			 cout << "Xin moi chon: ";
			 cin >> c;
			 cin.ignore();
			 if (c != 1 && c != 2 && c != 3)cout << "Xin moi nhap lai: ";
			 switch (c) {
			 case 1: {
				 FIND.Find_SBD(); 
				 this->THONGKE_THUKHOA_TQ();
			 } break;
			 case 2: {
				 FIND.Find_diem();
				 this->THONGKE_THUKHOA_TQ();
			 }break;
			 case 3:key = false;
			 }
		 } while (key);
	 }
 }
 void BASE_MATH_LATE_ON_SCREEN::THONGKE_THU_KHOA(){
	 //this->nhap();
	 system("cls");
	 ifstream myfile(this->PATH_FILE[this->k] + this->File[3], ios::in);
	 string line, token,ID,DIEM,KHOI ="",KHOI_temp;
	 while (!myfile.eof()) {
		 getline(myfile, line);
		 if (line != "") {
			 istringstream stm(line);
			 getline(stm, token, ',');
			 ID = token;
			 getline(stm, token, ',');
			 DIEM = token;
			 getline(stm, token, ',');
			 KHOI_temp = token;
			 if (KHOI_temp != KHOI) {
				 KHOI = KHOI_temp;
				 out << "			             TOP 10 THU KHOA KHOI " << KHOI << endl;
			 }
			 out << "Ma Thi Sinh: " << ID << " So Diem: " << DIEM << "  " << KHOI << endl;
		 }
	 }
	 FIND.Find_Set_k(this->get_k());
	 {
		 cout << "\n                          =========== SEARCH TOOL ===========\n";
		 bool key = true;
		 int c;
		 do {

			 cout << "\n1. Tim diem thi thi sinh theo SBD\n";
			 cout << "2. Tim diem thi thi sinh theo diem duoc nhap \n";
			 cout << "3. Khong quan tam\n";
			 cout << "Xin moi chon: ";
			 cin >> c;
			 cin.ignore();
			 if (c != 1 && c != 2 && c != 3)cout << "Xin moi nhap lai: ";
			 switch (c) {
			 case 1: {
				 FIND.Find_SBD();
				 this->THONGKE_THUKHOA_TQ();
			 } break;
			 case 2: {
				 FIND.Find_diem();
				 this->THONGKE_THUKHOA_TQ();
			 }break;
			 case 3:key = false;
			 }
		 } while (key);
	 }
 }
 void BASE_MATH_LATE_ON_SCREEN::THONGKE_DIEM_TB(int selec = 0) {
	// this->nhap();
	 int count = 0; 
	 string toan, van, anh, ly, hoa, sinhhoc, su, dia, cd;
	 ifstream myfile(this->PATH_FILE[this->k] + this->File[4], ios::in);
	 string line, token, ID, DIEM, KHOI = "", KHOI_temp;
	 vector<double> point;
	 double diem;
	 vector<string>  list;
	 istringstream ss(token);
	 list.push_back("Toan");
	 list.push_back("Ngu Van");
	 list.push_back("Ngoai Ngu");
	 list.push_back("Vat Ly");
	 list.push_back("Hoa Hoc");
	 list.push_back("Sinh Hoc");
	 list.push_back("GDCD");
	 list.push_back("Lich Su");
	 list.push_back("Dia li");
	 while (!myfile.eof()) {
		 getline(myfile, line);
		 count++;
		 if (line != "" && count != 1) {
			 istringstream stm(line);
			 getline(stm, token, ',');
			 toan = token;
			 istringstream ss(token);
			 ss >> diem;
			 point.push_back(diem);
			 getline(stm, token, ',');
			 van = token;
			 istringstream ss1(token);
			 ss1 >> diem;
			 point.push_back(diem);
			 getline(stm, token, ',');
			 anh = token;
			 istringstream ss2(token);
			 ss2 >> diem;
			 point.push_back(diem);
			 getline(stm, token, ',');
			 ly = token;
			 istringstream ss3(token);
			 ss3 >> diem;
			 point.push_back(diem);
			 getline(stm, token, ',');
			 hoa = token;
			 istringstream ss4(token);
			 ss4 >> diem;
			 point.push_back(diem);
			 getline(stm, token, ',');
			 sinhhoc = token;
			 istringstream ss5(token);
			 ss5 >> diem;
			 point.push_back(diem);
			 getline(stm, token, ',');
			 su = token;
			 istringstream ss6(token);
			 ss6 >> diem;
			 point.push_back(diem);
			 getline(stm, token, ',');
			 dia = token;
			 istringstream ss7(token);
			 ss7 >> diem;
			 point.push_back(diem);
			 getline(stm, token, ',');
			 cd = token;
			 istringstream ss8(token);
			 ss8 >> diem;
			 point.push_back(diem);
		 }
	 }
	 if (selec == 1) {
		 system("cls");
		 out << "			             DIEM TRUNG BINH CAC MON NAM " << this->a[this->k] << endl;
		 out << "Toan: " << toan << endl;
		 out << "Van: " << van << endl;
		 out << "Ngoai Ngu: " << anh << endl;
		 out << "Vat ly: " << ly << endl;
		 out << "Hoa Hoc: " << hoa << endl;
		 out << "Sinh hoc: " << sinhhoc << endl;
		 out << "Lich Su: " << su << endl;
		 out << "Dia li: " << dia << endl;
		 out << "GDCD: " << cd << endl;
		
	 }
	 if (selec == 1 || selec == 2) {
		 out << endl;
		 POW.SS(this->a[this->k], point, list);
	 }
	 FIND.Find_Set_k(this->get_k());
	 {
		 cout << "\n                          =========== SEARCH TOOL ===========\n";
		 bool key = true;
		 int c;
		 do {

			 cout << "\n1. Tim diem thi thi sinh theo SBD\n";
			 cout << "2. Tim diem thi thi sinh theo diem duoc nhap \n";
			 cout << "3. Tim diem thi thi sinh theo mon\n";
			 cout << "3. Khong quan tam\n";
			 cout << "Xin moi chon: ";
			 cin >> c;
			 cin.ignore();
			 if (c != 1 && c != 2 && c != 3 && c != 4)cout << "Xin moi nhap lai: ";
			 switch (c) {
			 case 1: {
				 FIND.Find_SBD();
				 this->THONGKE_DIEM_TB(1);
			 } break;
			 case 2: {
				 FIND.Find_diem();
				 this->THONGKE_DIEM_TB(1);
			 }break;
			 case 3: {
				 FIND.Find_diem_mon();
				 this->THONGKE_DIEM_TB(1);
			 }break;
			 case 4:key = false;
			 }
		 } while (key);
	 }
 }
 // Update 6/11/20 1:19
 void BASE_MATH_LATE_ON_SCREEN::THONGKE_PHODIEM(string path) {
	 system("cls");
	 cout << "Vui long doi !" << endl;
	 string pho_diem[30]{ "<=1", "<=2","<=3","<=4","<=5" ,"<=6" ,"<=7" ,"<=8" ,"<=9" ,"<=10" ,"<=11"
		 ,"<=12" ,"<=13" ,"<=14" ,"<=15" ,"<=16" ,"<=17" ,"<=18" ,"<=19" ,"<=20" ,"<=21" ,"<=22"
		 ,"<=23" ,"<=24" ,"<=25" ,"<=26" ,"<=27" ,"<=28" ,"<=29" ,"<=30" },line,token;
	 vector<string> list;
	 vector<double> point(30);
	 for (auto& itemk : point)itemk = 0;
	 for (auto& item : pho_diem)list.push_back(item);
	 ifstream myfile(path, ios::in);
	 while (!myfile.eof()) {
		 getline(myfile, line);
		 if (line != "") {
			 istringstream stm(line);
			 getline(stm, token, ',');
			 double temp = to_double(token);
			 for (double i = 1; i <= 30; i++) {
				 if (i - 1 < temp && temp <= i) {
					 point[i-1] += 1;
				 }
			 }
		 }
	 }
	
	 cout << "                  PHO DIEM KHOI " << this->khoi[this->temp_khoithi] << " NAM " << this->a[this->k] << endl;
	 POW.SS(this->a[this->k], point, list);
	 FIND.Find_Set_k(this->get_k());
	 {
		 cout << "\n                          =========== SEARCH TOOL ===========\n";
		 bool key = true;
		 int c;
		 do {

			 cout << "\n1. Tim diem thi thi sinh theo SBD\n";
			 cout << "2. Tim diem thi thi sinh theo diem duoc nhap \n";
			 cout << "3. Khong quan tam\n";
			 cout << "Xin moi chon: ";
			 cin >> c;
			 cin.ignore();
			 if (c != 1 && c != 2 && c != 3)cout << "Xin moi nhap lai: ";
			 switch (c) {
			 case 1: {
				 FIND.Find_SBD();
				
			 } break;
			 case 2: {
				 FIND.Find_diem();
				 
			 }break;
			 case 3:key = false;
			 }
		 } while (key);
	 }

 }
 void BASE_MATH_LATE_ON_SCREEN::nhap_thongke_phodiem() {
	 system("cls");
	 string FILE1[14]{ "KHOI\\A.txt","KHOI\\A1.txt","KHOI\\A2.txt","KHOI\\B.txt","KHOI\\D.txt","KHOI\\C.txt","KHOI\\C01.txt","KHOI\\C02.txt","KHOI\\C03.txt","KHOI\\C04.txt","KHOI\\C05.txt","KHOI\\C06.txt","KHOI\\C07.txt","KHOI\\C08.txt" };
	 this->nhap_khoithi();
	 this->THONGKE_PHODIEM(this->PATH_FILE[this->k] + FILE1[this->temp_khoithi]);
 }





 // Update 6/11/20 7:32 pm
 // toan - 0 van - 1 anh - 2
 void BASE_MATH_LATE_ON_SCREEN::Phodiemmon1(string path,int selec) {
	 string line, token;
	 double pho_dien[52]{ 0, 0.2,0.4,0.6,0.8,1, 1.2,1.4,1.6,1.8,2, 2.2,2.4,2.6,2.8,3,
		 3.2,3.4,3.6,3.8,4, 4.2,4.4,4.6,4.8,5, 5.2,5.4,5.6,5.8,6, 6.2,6.4,6.6,6.8,7,
		 7.2,7.4,7.6,7.8,8, 8.2,8.4,8.6,8.8,9, 9.2,9.4,9.6,9.8,10 };
	 string pho_diem[52]{ "0", "0.2","0.4","0.6","0.8","1", "1.2","1.4","1.6","1.8","2", "2.2","2.4","2.6","2.8","3",
		 "3.2","3.4","3.6","3.8","4", "4.2","4.4","4.6","4.8","5", "5.2","5.4","5.6","5.8","6", "6.2","6.4","6.6","6.8","7",
		 "7.2","7.4","7.6","7.8","8", "8.2","8.4","8.6","8.8","9", "9.2","9.4","9.6","9.8","10" };
	 vector<string> list;
	 vector<double> point(52);
	 double sothisinh = 0;
	 for (auto& item : pho_diem)list.push_back(item);
	 for (auto& itemk : point)itemk = 0;
	 ifstream myfile(path, ios::in);
	 while (!myfile.eof()) {
		 getline(myfile, line);
		 if (line != "") {
			 istringstream stm(line);
			 getline(stm, token, ',');
			 // id 
			 // toan
			 getline(stm, token, ',');
			 if (token != "" && selec == 0) {
				 sothisinh++;
				 double temp = to_double(token);
				 for (int i = 0; i < 52; i++) {
					 if (pho_dien[i] == temp)point[i]++;
				}
			 }
			 // Ngu van
			 getline(stm, token, ',');
			 if (token != "" && selec == 1) {
				 sothisinh++;
				 double temp = to_double(token);
				 for (int i = 0; i < 52; i++) {
					 if (pho_dien[i] == temp)point[i]++;
				 }
			 }
			 // ngoai ngu
			 getline(stm, token, ',');
			 if (token != "" && selec == 2) {
				 sothisinh++;
				 double temp = to_double(token);
				 for (int i = 0; i < 52; i++) {
					 if (pho_dien[i] == temp)point[i]++;
				 }
			 }
		}
	 }
	 double duoitrungbinh = 0,maxping = 0;
	 int ddd = 0;
	 for (int i = 0; i < 25; i++)duoitrungbinh += point[i];
	 for (int k = 0; k < 52; k++) {
		 if (maxping < point[k]) {
			 ddd = k;
			 maxping = point[k];
		 }
	 }
	 cout << "                    PHO DIEM MON " << this->KHOI[this->selection] << " NAM: " << this->a[this->k] << endl;
	 POW.SS(this->a[this->k], point, list);
	 cout << "\n\n==================================\n";
	 cout << "Tong so thi sinh: " << sothisinh << endl;
	 cout << "So thi sinh dat diem duoi <= 1: " << (point[0] + point[1] + point[2] + point[3] + point[4] + point[5]) << " (" << ((point[0] + point[1] + point[2] + point[3] + point[4] + point[5]) / sothisinh) * 100 << "%)" << endl;
	 cout << "So thi sinh dat diem duoi trung binh (<5): " << duoitrungbinh << " (" << (duoitrungbinh / sothisinh) * 100 << "%)" << endl;
	 cout << "Diem so co nhieu thi sinh dat nhat: " << list[ddd] << " (" << maxping << ")" << endl;
 }
 // ly - 0 hoa - 1 sinh -2 su -3 dia -4 cd -5
 void BASE_MATH_LATE_ON_SCREEN::Phodiemmon2(string path, int selec) {
	 double pho_dien[41]{ 0, 0.25,0.5,0.75,1, 1.25,1.5,1.75,2, 2.25,2.5,2.75,3, 3.25,3.5,3.75,4,
		 4.25,4.5,4.75,5, 5.25,5.5,5.75,6, 6.25,6.5,6.75,7, 7.25,7.5,7.75,8, 8.25,8.5,8.75,9, 9.25,9.5,9.75,10};
	 string pho_diem[41]{ "0", "0.25","0.5","0.75","1", "1.25","1.5","1.75","2", "2.25","2.5","2.75","3", "3.25","3.5","3.75","4",
		 "4.25","4.5","4.75","5", "5.25","5.5","5.75","6", "6.25","6.5","6.75","7", "7.25","7.5","7.75","8", "8.25","8.5","8.75","9", "9.25","9.5","9.75","10" };
	 vector<string> list;
	 vector<double> point(41);
	 double sothisinh = 0;
	 for (auto& itemk : point)itemk = 0;
	 for (auto& item : pho_diem)list.push_back(item);
	 string line, token;
	 ifstream myfile(path, ios::in);
	 while (!myfile.eof()) {
		 getline(myfile, line);
		 if (line != "") {
			 istringstream stm(line);
			 getline(stm, token, ',');
			 // id 
			 // toan
			 if (selec != 10) {
				 getline(stm, token, ',');
			 }
			 getline(stm, token, ',');
			 if (token != "" && (selec == 0 || selec == 4)) {
				 sothisinh++;
				 double temp = to_double(token);
				 for (int i = 0; i < 41; i++) {
					 if (pho_dien[i] == temp)point[i]++;
				 }
			 }
			 // Ngu van
			 getline(stm, token, ',');
			 if (token != "" && (selec == 1 || selec == 5 || selec == 10)) {
				 sothisinh++;
				 double temp = to_double(token);
				 for (int i = 0; i < 41; i++) {
					 if (pho_dien[i] == temp)point[i]++;
				 }
			 }
			 // ngoai ngu
			 getline(stm, token, ',');
			 if (token != "" && (selec == 2 || selec == 3)) {
				 sothisinh++;
				 double temp = to_double(token);
				 for (int i = 0; i < 41; i++) {
					 if (pho_dien[i] == temp)point[i]++;
				 }
			 }
		 }
	 }
	 double duoitrungbinh = 0,maxping = 0;
	 int ddd = 0;
	 for (int i = 0; i < 20; i++)duoitrungbinh += point[i];
	 for (int k = 0; k < 41; k++) {
		 if (maxping < point[k]) {
			 ddd = k;
			 maxping = point[k];
		 }
	 }
	 cout << "                    PHO DIEM MON " << this->KHOI[this->selection] << " NAM: " << this->a[this->k] << endl;
	 POW.SS(this->a[this->k], point, list);
	 cout << "\n\n==================================\n";
	 cout << "Tong so thi sinh: " << sothisinh << endl;
	 cout << "So thi sinh dat diem duoi <= 1: " << (point[0] + point[1] + point[2] + point[3] + point[4] ) << " (" << ((point[0] + point[1] + point[2] + point[3] + point[4] ) / sothisinh) * 100 << "%)" << endl;
	 cout << "So thi sinh dat diem duoi trung binh (<5): " << duoitrungbinh << " (" << (duoitrungbinh / sothisinh) * 100 << "%)" << endl;
	 cout << "Diem so co nhieu thi sinh dat nhat: " << list[ddd] << " (" << maxping << ")" << endl;
 }
 void BASE_MATH_LATE_ON_SCREEN::THONGKE_PHODIEM_mon() {
	 system("cls");
	 this->nhap_khoi();
	 cout << "Vui long doi !" << endl;
	 //"Toan","Ngu van","Ngoai ngu","Vat li","Hoa hoc","Sinh hoc","Lich su","Dia ly","GDCD"           ,"FILE_MARK_KHTN.txt","FILE_MARK_KHXH.txt" ,"FILe_BAT_BUOC.txt"
	 switch (this->selection) {
	 case 0: {
		 this->Phodiemmon1(this->PATH_FILE[this->k] + "FILe_BAT_BUOC.txt", 0);
		 cout << "Diem trung binh: " << this->get_diemtb(0) << endl;
	 }break;
	 case 1: {
		 this->Phodiemmon2(this->PATH_FILE[this->k] + "FILe_BAT_BUOC.txt", 10);
		 cout << "Diem trung binh: " << this->get_diemtb(1) << endl;
	 }break;
	 case 2: {
		 this->Phodiemmon1(this->PATH_FILE[this->k] + "FILe_BAT_BUOC.txt", 2);
		 cout << "Diem trung binh: " << this->get_diemtb(2) << endl;
	 }break;
	 case 3: {
		 this->Phodiemmon2(this->PATH_FILE[this->k] + "FILE_MARK_KHTN.txt", 0);
		 cout << "Diem trung binh: " << this->get_diemtb(3) << endl;
	 }break;
	 case 4: {
		 this->Phodiemmon2(this->PATH_FILE[this->k] + "FILE_MARK_KHTN.txt", 1);
		 cout << "Diem trung binh: " << this->get_diemtb(4) << endl;
	 }break;
	 case 5: {
		 this->Phodiemmon2(this->PATH_FILE[this->k] + "FILE_MARK_KHTN.txt", 2);
		 cout << "Diem trung binh: " << this->get_diemtb(5) << endl;
	 }break;
	 case 6: {
		 this->Phodiemmon2(this->PATH_FILE[this->k] + "FILE_MARK_KHXH.txt", 3);
		 cout << "Diem trung binh: " << this->get_diemtb(6) << endl;
	 }break;
	 case 7: {
		 this->Phodiemmon2(this->PATH_FILE[this->k] + "FILE_MARK_KHXH.txt", 4);
		 cout << "Diem trung binh: " << this->get_diemtb(7) << endl;
	 }break;
	 case 8: {
		 this->Phodiemmon2(this->PATH_FILE[this->k] + "FILE_MARK_KHXH.txt", 5);
		 cout << "Diem trung binh: " << this->get_diemtb(8) << endl;
	 }break;
	 }
	 // Toan Van Ngoai ngu Ly Hoa Sinh GDCD SU Dia 
	 // Toan Van Ngoai ngu File Bat buoc 
	 // Ly hoa sinh  FIle KHTN
	 // GDCD Su dia File khxh 
	 //"FILE_MARK_KHTN.txt","FILE_MARK_KHXH.txt" ,"FILe_BAT_BUOC.txt"
	 FIND.Find_Set_k(this->get_k());
	 {
		 cout << "\n                          =========== SEARCH TOOL ===========\n";
		 bool key = true;
		 int c;
		 do {

			 cout << "\n1. Tim diem thi thi sinh theo SBD\n";
			 cout << "2. Tim diem thi thi sinh theo diem duoc nhap \n";
			 cout << "3. Khong quan tam\n";
			 cout << "Xin moi chon: ";
			 cin >> c;
			 cin.ignore();
			 if (c != 1 && c != 2 && c != 3)cout << "Xin moi nhap lai: ";
			 switch (c) {
			 case 1: {
				 FIND.Find_SBD();
				
			 } break;
			 case 2: {
				 FIND.Find_diem();
				 
			 }break;
			 case 3:key = false;
			 }
		 } while (key);
	 }

 }
 ///
 /// 
 /// BIEU DO 
 /// 
 /// /// string File[5]{"Thong_Ke\\Diem10.txt","Thong_Ke\\Diemliet.txt","Thong_Ke\\tong10tungmon.txt","Thong_Ke\\top10thukhoa.txt","Thong_Ke\\dtb.txt"};
 /// 

	//Bieu DO
	//
	//
	//
 
 //
 //
 //
 //
 //
 //
