/*
ID: egor_ga1
PROG: barn1
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");
	int m, s, c;
	fin >> m >> s >> c;
	int cows[c];
	for(int i = 0; i < c; i++){
		fin >> cows[i];	
	}
	sort(cows, cows + c);
	vector<pair<int, int>> spaces;
	for(int x = c - 1; x > 0; x--){
		if((cows[x] - cows[x - 1]) > 1){
			spaces.push_back(make_pair(cows[x] - cows[x - 1], x));
		}
	}
	sort(spaces.begin(), spaces.end());
	reverse(spaces.begin(), spaces.end());
	vector<int> sep;
	for(int i = 0; i < (m - 1); i++){	
		sep.push_back(spaces[i].second);
		if(i == spaces.size() - 1){
			break;
		}
	}
	int ans = 0;
	int l = cows[0];
	sort(sep.begin(), sep.end());
	for(int i = 0; i < sep.size(); i++){
		cout << cows[sep[i] - 1] << endl;
	}
	for(int i = 0; i < sep.size(); i++){
		ans += cows[sep[i] - 1] - l + 1;
		l = cows[sep[i]];
	}
	ans += cows[c - 1] - l;
	ans++;
	fout << ans << endl;
	return 0;
}
