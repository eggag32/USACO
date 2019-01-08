/*
ID: egor_ga1
PROG: combo
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

bool close1(int a, int b){
	return ((abs(a - b) <= 2) || (abs(a - b) >= n - 2));
}

bool close(int a, int b, int c, int d[]){
	return (close1(a, d[0]) && close1(b, d[1]) && close1(c, d[2]));
}

int main(){
	ofstream fout("combo.out");
	ifstream fin("combo.in");
	fin >> n;
	int fj[3], mas[3];
	for(int i = 0; i < 3; i++){
		fin >> fj[i];
	}
	for(int i = 0; i < 3; i++){
		fin >> mas[i];
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				if(close(i, j, k, fj) || close(i, j, k, mas)){
					ans++;
				}
			}
		}
	}
	fout << ans << endl;
	return 0;	
}
