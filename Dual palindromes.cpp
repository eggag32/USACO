/*
ID: egor_ga1
PROG: dualpal
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string to_base(int a, int c){
	string e = "";
	while(a > 0){
		e += a % c;
		a /= c;
	}
	reverse(e.begin(), e.end());
	return e;
}

bool palindrome(string b){
	for(int i = 0; i < (b.size()/2); i++){
		if(b[i] != b[b.size() - i - 1]){
			return false;
		}
	}
	return true;
}

int main(){
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");
	int n, s;
	fin >> n >> s;
	int j = 0;
	int g = 1;
	int h = 0;
	while(j < n){
		while(h < 2){
			h = 0;
			for(int i = 2; i <= 10; i++){
				if(palindrome(to_base(s + g, i)) == true){
					h++;
					if(h == 2){
						fout << s + g << endl;
						break;
					}
				}
			}
			g++;
		}
		j++;
		h = 0;
	}
}
