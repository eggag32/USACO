/*
ID: egor_ga1
PROG: skidesign
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ifstream fin("skidesign.in");
	ofstream fout("skidesign.out");
	int n;
	fin >> n;
	int hills[n];
	for(int i = 0; i < n; i++){
		fin >> hills[i];
	}
	int ans = INT_MAX;
	for(int i = 0; i <= 83; i++){
		int total = 0;
		for(int j = 0; j < n; j++){
			if(hills[j] < i){
				total += (i - hills[j]) * (i - hills[j]);
			}
			if(hills[j] > (i + 17)){
				total += (hills[j] - (i + 17)) * (hills[j] - (i + 17));
			}
		}
		ans = min(total, ans);
	}
	fout << ans  << endl;
	return 0;
}
