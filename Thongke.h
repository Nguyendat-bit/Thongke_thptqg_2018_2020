#pragma once
#include<iostream>
#include<list>
#include<sstream>
#include<algorithm>
#include<Windows.h>

#define Width 100
using namespace std;



// default color 15 14 yellow  11 light blue
#define Default 15
#define Yellow 14
#define Light_blue 11
#define Default_nen	15
#define Yellow_nen 14
#define Light_blue_nen  11
#define Green 9

template<class T = vector<double>>
class Thongke
{
private:
	T current;
	T current_2;
	T current_3;
	vector<string> till;
	size_t num1;
public:
 double	round1(double a) {
		if (((int)(a * 10)) % 10 >= 5)
		{
			return ((double)((int)(a))) + 1;
		}
		else
		{
			return ((double)((int)(a * 10))) / 10;
		}
	}
	void color(int color) {
		HANDLE hConsoleColor;
		hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsoleColor, color);
	}
	void push_name(vector<string> list) {
		size_t max_size = 0;
		this->num1 = list.size() ;
		for (const auto it : list) {

			if (max_size < it.size())max_size = it.size();
		}
		for (auto &it : list) {
			string temp_list = it; 
			for (size_t i = 1; i <= max_size - it.size(); i++) {
				temp_list.push_back(' ');
			}
			this->till.push_back(temp_list);
		}
	}
	void graphic(int i, T temp) {
		T temp_current = temp;
		double max_value = 0; 
		for (const auto& item : temp) {
			if (item > max_value)max_value = item;
		}
		if (temp_current[i] == max_value) {
			color(Green);
			for (int j = 1; j <= Width; j++)cout << '|';
			color(Yellow);
			cout << " 100%   ";
			color(Default);
		}
		else {
			color(Green);
			double width = round1((temp_current[i] / max_value) * Width);
			for (int j = 1; j <= width; j++)cout << '|';
			color(Yellow);
			cout << " " << (temp_current[i] / max_value) * 100 << "%   "; 
			color(Default);

		}
	}
	~Thongke() {
		this->till.clear();
	}
	// update 1:27 am 6/11/20
	void IN_1() {
		for (int i = 0; i < num1; i++) {

			cout << till[i] << "  ";
			graphic(i, this->current);
			color(Light_blue);
			cout << "  " << this->current[i] << endl;
			color(Default);
			
		}
		this->till.clear();
	}



	void IN_2() {
		for (int i = 1; i <= num1; i++) {

			cout << till[i] << "  ";
			color(Yellow);
			graphic(i, this->current);
			color(Default);
			cout << "  " << this->current[i] << endl;
			graphic(i, this->current_2);
			cout << "  " << this->current_2[i] << endl;

		}
	}
	void IN_3() {
		for (int i = 1; i <= num1; i++) {

			cout << till[i] << "  ";
			color(Light_blue);
			graphic(i, this->current);
			color(Default);
			cout << "  " << this->current[i] << endl;
			color(Yellow);
			graphic(i, this->current_2);
			color(Default);
			cout << "  " << this->current_2[i] << endl;
			graphic(i, this->current_3);
			cout << "  " << this->current_3[i] << endl;

		}
	}







	void point(T pointer) {
		this->current = pointer;
	}
	void point(T pointer, T pointer_2, T pointer_3) {
		this->current = pointer;
		this->current_2 = pointer_2;
		this->current_3 = pointer_3;
	}
	void point(T pointer, T pointer_2) {
		this->current = pointer;
		this->current_2 = pointer_2;
	}






	// update 1:31 am 6/11/20
	void SS(string status, T pointer, vector<string> list) {
		this->point(pointer);
		this->push_name(list);
		this->IN_1();
		cout << status << "  ";
		color(Green);
		cout << "||||" << endl;
		color(Default);

	}
	void SS(string status, string status2, T pointer, T pointer_2, vector<string> list) {
		this->point(pointer, pointer_2);
		this->push_name(list);
		this->IN_2();
		cout << status << "  ";
		color(Yellow_nen);
		cout << "___" << endl;
		color(Default);
		cout << status2 << "  ";
		color(Default_nen);
		cout << "___" << endl;
		color(Default);
	}
	void SS(string status, string status2, string status3, T pointer, T pointer_2, T pointer_3, vector<string> list) {
		this->point(pointer, pointer_2, pointer_3);
		this->push_name();
		this->IN_3();
		cout << status << "  ";
		color(Light_blue);
		cout << "___" << endl;
		color(Default);
		cout << status2 << "  ";
		color(Yellow_nen);
		cout << "___" << endl;
		color(Default);
		cout << status3 << "  ";
		color(Default_nen);
		cout << "___" << endl;
		color(Default);
	}

};