/*
ID: egor_ga1
PROG: ariprog
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	freopen("ariprog.in", "r", stdin);
	freopen("ariprog.out", "w", stdout);
	int n;
	int m;
	cin >> n;
	cin >> m;
	vector<pair<int, int>> ans;
	int bsq[250 * 250 * 4];
	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= m; j++){
			bsq[i * i + j * j] = 1;
		}
	}
	int an = 0;
	int limit = 2 * m * m;
	for(int a = 0; a <= limit; a++){
	        if(bsq[a]){
			for(int diff = 1; a + diff * (n - 1) <= limit; diff++){
				int len = 1;
				int next = a + diff;
				while(bsq[next] && len < n){
					next += diff;
					len++;
				}
				if(len == n){
					an++;
					ans.push_back(make_pair(diff, a));		
				}
			}
		}
	}
	sort(ans.begin(), ans.end());
	if(an == 0){
		cout << "NONE" << endl;
		return 0;
	}
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i].second << " " << ans[i].first << endl;
	}
	return 0;
}
