/*
ID: egor_ga1
PROG: prefix
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("prefix.in", "r", stdin);
        freopen("prefix.out", "w", stdout);
	vector<string> p;
	while(true){
		string x;
		cin >> x;
		if(x == ".") break;
		p.pb(x);
	}
	string goal, g;
	while(cin >> g){
		goal += g;
	}
	int d[200005];
	memset(d, 0, sizeof(d));
	int ans = 0;
	d[0] = 1;
	for(int i = 0; i <= goal.size(); i++){
		for(string& x : p){
			int start = i - (int)x.size();
			if(start < 0) continue;
			if(!d[start]) continue;
			if(goal.substr(start, (int)x.size()) != x) continue;
			ans = i;
			d[i] = 1;
		}
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
