/*
User ID: egor_ga1
PROG: namenum
LANG: C++11
*/
#include <bits/stdc++.h>
#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string number(const string &in){
	string ret = "";
	for(int i = 0; i < in.size(); i++){
		if(in[i] < 'Q'){
			ret += (in[i] - 'A')/3 + '2';
		}
		else{
			ret += (in[i] - 'Q')/3 + '7';
		}
	}
	return ret;
}

int main(){
	ofstream fout("namenum.out");
	ifstream fin("namenum.in");
	ifstream fdict("dict.txt");
	string num;
	fin >> num;
	bool found = false;
	string entry;
	while(fdict >> entry){
		if(num.size() == entry.size() && num == number(entry)){
			fout << entry << endl;
			found = true;
		}
	}	
	if(found == false){
		fout << "NONE" << endl;
	}
	return 0;
}
