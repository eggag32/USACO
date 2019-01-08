/*
ID: egor_ga1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	ofstream fout ("ride.out");
    ifstream fin ("ride.in");
	string s1;
	string s2;
    string s3;
	fin >> s1 >> s2;
	int prod1 = 1;
	for (int i=0;i<s1.size();++i){
		prod1 *= s1[i]-'A'+1;
	}
	int prod2 = 1;
	for (int i=0;i<s2.size();++i){
		prod2 *= s2[i]-'A'+1;
	}
    if (prod1%47 == prod2%47){
        s3 = "GO";
    }
    if (prod1%47 != prod2%47){
        s3 = "STAY";
    }
	fout << s3 << endl;
	return 0;
}
