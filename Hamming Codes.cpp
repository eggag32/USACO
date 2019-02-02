/*
ID: egor_ga1
PROG: hamming
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(),v.end() 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int hd(int a, int b){
	int c = a ^ b;
	return __builtin_popcount(c);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hamming.in", "r", stdin);
        freopen("hamming.out", "w", stdout);
	int n, b, d;
	cin >> n >> b >> d;
	vi ans;
	ans.pb(0);
	int l = 0;
	int dest = (1 << b);
	while(ans.size() < n){
		for(int i = l + 1; i < dest; i++){
			bool x = true;
			for(int g : ans){
				if(hd(g, i) < d){
					x = false;
					break;
				}
			}
			if(x){
				l = i;
				ans.pb(i);
				break;
			}
		}
	}
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i];
		if(i == ans.size() - 1 || (i + 1) % 10 == 0){
			cout << endl;
		}
		else{
			cout << " ";
		}
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
*/
