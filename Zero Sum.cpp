/*
ID: egor_ga1
PROG: zerosum
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

int n;

void dfs(int c, int sum, int num, int sign, string seq){
	if(c == n + 1){
		if(sum + sign * num == 0){
			cout << seq << endl;
		}
		return;
	}
	dfs(c + 1, sum, num * 10 + c, sign, seq + " " + to_string(c));
	dfs(c + 1, sum + sign * num, c, 1, seq + "+" + to_string(c));
	dfs(c + 1, sum + sign * num, c, -1, seq + "-" + to_string(c));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("zerosum.in", "r", stdin);
        freopen("zerosum.out", "w", stdout);
	cin >> n;
	dfs(2, 0, 1, 1, "1");
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
