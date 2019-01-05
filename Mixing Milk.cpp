/*
ID: egor_ga1
PROG: milk
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ofstream fout("milk.out");
	ifstream fin("milk.in");
	int n, m;
	fin >> n >> m;
	vector<pair<int, int>> milk;
	for(int i = 0; i < m; i++){
		int a, b;
		fin >> a >> b;
		milk.push_back(make_pair(a, b));
	}	
	int ans = 0;
	int ans1 = 0;
	sort(milk.begin(), milk.end());
	int i = 0;
	while(ans < n){
		if((n - ans - milk[i].second) >= 0){
			ans += milk[i].second;
			ans1 += milk[i].first * milk[i].second;
			i++;		
		}
		else{
                        ans1 += milk[i].first * (n - ans);
			ans = n;
                }
	}
	fout << ans1 << endl;
	return 0;
}
