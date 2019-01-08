/*
ID: egor_ga1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	bool leap;
	int year = 1900, add, day, current = 13;
	ofstream fout ("friday.out");
	ifstream fin ("friday.in");
	fin >> add;
	int months_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int months_days_leap[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	int friday_13[7] = {0,0,0,0,0,0,0};
	for(int i = 1; i <= add; i++){
		int year_pa = 1900 + (i - 1);
		if (year_pa % 100 != 0){
		    if (year_pa % 4 == 0){
			    leap = true;
		    }
		    else{
			    leap = false;
		    }
	    }
	    else{
			if (year_pa % 400 == 0){
				leap = true;
			}
			else{
				leap = false;
			}
		}
		for (int start = 0; start <= 11;start++){
			day = current % 7;
			if (day == 0){
				friday_13[6] += 1;
			}
			else{
				friday_13[day - 1] += 1;
			}
			if (leap == false){
				current += months_days[start];
			}
			else{
				current += months_days_leap[start];
			}
		}
	}
	fout << friday_13[5]<<" "<< friday_13[6]<<" "<< friday_13[0]<<" "<< friday_13[1]<<" "<< friday_13[2]<<" "<< friday_13[3]<<" "<< friday_13[4]<<endl;
}


