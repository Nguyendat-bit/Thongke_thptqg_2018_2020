#pragma once

#include"Realtime.h";
#include"Import data.h";
Find FIND1;
using namespace std;
#pragma region Begin
EMTY_OR_VALUE VALUE; 
Realtime R;
BASE_MATH_LATE BEGIN;
typedef BASE_MATH_LATE_ON_SCREEN SCREEN;

SCREEN A;

DATA_FROM_FILE_MARk M;

#pragma endregion

class Mainwindow {
private:
	string tillte[11]; 
public:
	void SetWindowSize(SHORT width, SHORT height)
	{
		HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

		SMALL_RECT WindowSize;
		WindowSize.Top = 0;
		WindowSize.Left = 0;
		WindowSize.Right = width;
		WindowSize.Bottom = height;

		SetConsoleWindowInfo(hStdout, 1, &WindowSize);
	}
	// Chinh sua cua so buffer
	void SetScreenBufferSize(SHORT width, SHORT height)
	{
		HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

		COORD NewSize;
		NewSize.X = width;
		NewSize.Y = height;

		SetConsoleScreenBufferSize(hStdout, NewSize);
	}
	// Chan user thay doi kich thuoc
	void DisableResizeWindow()
	{
		HWND hWnd = GetConsoleWindow();
		SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
	}
	// xoa nut min,max,close
	void DisableCtrButton(bool Close, bool Min, bool Max)
	{
		HWND hWnd = GetConsoleWindow();
		HMENU hMenu = GetSystemMenu(hWnd, false);

		if (Close == 1)
		{
			DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
		}
		if (Min == 1)
		{
			DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
		}
		if (Max == 1)
		{
			DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
		}
	}
	// an hien 2 thanh cuon  
	// Cho = 0
	void ShowScrollbar(BOOL Show)
	{
		HWND hWnd = GetConsoleWindow();
		ShowScrollBar(hWnd, SB_BOTH, Show);
	}
	// Thay doi tilte



	// An hien con tro = 0
	void ShowCur(bool CursorVisibility)
	{
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO ConCurInf;

		ConCurInf.dwSize = 10;
		ConCurInf.bVisible = CursorVisibility;

		SetConsoleCursorInfo(handle, &ConCurInf);
	}
	Mainwindow() {
		SetConsoleTitle(L"Tool_Diemthi_THPTQG");
		this->SetWindowSize(150, 65);
		this->SetScreenBufferSize(150, 9999999);
		this->DisableResizeWindow();
		this->DisableCtrButton(0, 0, 1);
		this->ShowScrollbar(0);
		this->ShowCur(0);
	}
	void set() {
		this->tillte[0] = "                          = 1 - Xem diem THPTQG                                        =";
		this->tillte[1] = "                          = 2 - Thong ke THPTQG                                        =";
		this->tillte[2] = "                          = 3 - Pho diem cua tung khoi thi                             =";
		this->tillte[3] = "                          = 4 - Pho diem cua tung mon thi                              =";
		this->tillte[4] = "                          = 5 - Tim diem thi thi sinh theo diem duoc nhap              =";
		this->tillte[5] = "                          = 6 - Tim diem liet cua thi sinh                             =";
		this->tillte[6] = "                          = 7 - Tim diem toi da cua thi sinh                           ="; 
		this->tillte[7] = "                          = 8 - Tim kiem diem thi cua thi sinh theo mon                =";
		this->tillte[8] = "                          = 9 - Tim kiem diem thi cua thi sinh theo ma tinh            =";
		this->tillte[9] = "                          = 10 - Tim kiem diem thi cua thi sinh theo mon theo ma tinh  =";
		this->tillte[10] = "                          = 11 - Thoat ra man hinh chinh                               =";

	}
	void menu1() {
		//
		int pick = 0; double diem1 , diem2 , diem3 ;
		int n, k  ; 
		M.PROCESS_DATA_WITH_ID();
		if (!M.get_sele()) {
			R.set_n(M.KHOII());
			R.nhap();
			R.set_diemxet(M.SAP_DATA(R.check_num(R.get_khoi())));
			R.process_data(M.get_temp());
			n = R.check_num(R.get_khoi());
			M.Data_Diem(n, diem1, diem2, diem3, k);
			R.Diemtrungbinh(k, n, diem1, diem2, diem3);
			cout << "Ban co muon chon lai khoi xet tuyen khong (1/0) ? "; 
			cin >> pick; 
			if (pick > 1)pick = 1;
			else if (pick < 0)pick = 0;
			if (pick == 1) {

				R.set_n(M.KHOII());
				R.nhap();
				R.set_diemxet(M.SAP_DATA(R.check_num(R.get_khoi())));
				R.process_data(M.get_temp());
				n = R.check_num(R.get_khoi());
				M.Data_Diem(n, diem1, diem2, diem3, k);
				R.Diemtrungbinh(k, n, diem1, diem2, diem3);
			}
		}
		else if (M.get_sele()) {
			cout << "Thi sinh khong du dieu kien tot nghiep" << endl; 
		}
	}
	
	void menu2() {
		system("cls");
		int i = 0; bool turn = true;
		string tilt[3];
		tilt[0] = "1. Chon nam (2018 -> 2020)";
		tilt[1] = "2. Quay lai";
		
		do {
			system("cls");
			this->windows_m(2, tilt);
			cout << "Xin moi chon: ";
			cin >> i;
			if (i != 1 && i != 2 )cout << "Moi nhap lai: ";
			cin.ignore();
			
			switch (i) {
			case 1: {
				// Bang so lieu 
				
				A.nhap();
				string til[13]; 
				til[0] = "1. Top 10 tinh thanh co nhieu diem toi da nhat";
				til[1] = "2. Top 10 tinh thanh co nhieu diem liet nhat";
				til[2] = "3. Thong ke so diem toi da cua cac mon";
				til[3] = "4. Thong ke so diem liet cua moi mon";
				til[4] = "5. Thong ke diem trung binh cac mon";
				til[5] = "6. Top 10 thu khoa tren toan quoc";
				til[6] = "7. Top 10 thu khoa cua cac khoi";
				til[7] = "8. Thong ke so thi sinh du thi moi tinh";
				til[8] = "9. Thong ke tat ca tinh thanh co diem toi da";
				til[9] = "10. Thong ke tat ca tinh thanh co diem liet";
				til[10] = "11. Pho diem thi cua moi khoi thi";
				til[11] = "12. Pho diem thi cua moi mon thi";
				til[12] = "13. Quay lai";
				
				int c = 0; bool boop = true;
				
				do {
					system("cls");
					this->windows_m(13, til);
					cout << "Xin moi chon: ";
					cin >> c; 
					if (c != 1 && c != 2 && c != 3 && c != 4 && c != 5 && c != 6 && c != 7 && c != 8 && c != 9 && c != 10 && c != 11 && c != 12 && c!= 13 )cout << "Moi nhap lai: ";
					cin.ignore();
					switch (c)
					{
					case 1:A.THONGKE_BANG_10(1); break;
					case 2:A.THONGKE_BANG_MUST_OUT(1); break;
					case 3:A.THONGKE_DIEM10(1); break;
					case 4:A.THONGKE_OUT_MARK(1); break;
					case 5:A.THONGKE_DIEM_TB(1); break;
					case 7:A.THONGKE_THU_KHOA(); break;
					case 6:A.THONGKE_THUKHOA_TQ(); break; 
					case 8:A.THONGKE_THISINH_TINH(); break;
					case 9:A.THONGKE_FULL_BANG_10(); break;
					case 10:A.THONGKE_FULL_BANG_MUST_OUT(); break;
					case 11:A.nhap_thongke_phodiem(); break;
					case 12:A.THONGKE_PHODIEM_mon(); break;
					case 13:boop = false;
					}
				} while (boop);
			 
			}break;
			case 2: turn = false;
			}
		} while (turn);
	}
	
	void windows_m(int n,string tillte[]) {
		cout << "                          ====================================================\n";
		for (int i = 0; i < n; i++)
		{
			cout << tillte[i] << endl;
		}
	}
	void windows() {
		cout << "                          ====================================================\n";
		for (int i = 0; i < 11; i++)
		{
			cout << tillte[i] << endl; 
		}
	}
	void menu7() {
		A.nhap();
		A.THONGKE_PHODIEM_mon();
	}
	void menu6() {
		A.nhap();
		A.nhap_thongke_phodiem();
	}
	void menu3() {
		FIND1.Find_xet_nam();
		FIND1.Find_diem();
	}
	void menu4() {
		FIND1.Find_xet_nam();
		FIND1.Find_diemliet();
	}
	void menu5() {
		FIND1.Find_xet_nam();
		FIND1.Find_diemtoida();
	}
	void menu9() {
		FIND1.Find_xet_nam();
		FIND1.Find_diem_matinh();
	}
	void menu10() {
		FIND1.Find_xet_nam();
		FIND1.Find_diem_both_ma_mon();
	}
	void menu8() {
		FIND1.Find_xet_nam();
		FIND1.Find_diem_mon();
	}
	void menu()
	{
		int i; bool turn = true; 
		
		do {
			system("cls");
			this->windows();
			cout << "                          Xin moi chon: ";
			cin >> i;
			cin.ignore();
			if (i != 1 && i != 2 && i != 3 && i != 4 && i != 5 && i!= 6 && i != 7 && i != 8 && i != 9 && i != 10 && i != 11)cout << "                          Moi nhap lai: ";
			
			switch (i) {
			case 1: {
				this->menu1();
			}break;
			case 2: {
				this->menu2();
			}break;
			case 3:this->menu6(); break;
			case 4:this->menu7(); break;
			case 5:this->menu3(); break;
			case 6:this->menu4(); break;
			case 7:this->menu5(); break;
			case 8:this->menu8(); break;
			case 9:this->menu9(); break;
			case 10:this->menu10(); break;
			case 11: exit(1);
			}
		} while (turn);
	}
};