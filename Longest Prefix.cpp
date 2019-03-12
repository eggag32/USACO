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

unordered_set<string> k;
int dp[200005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("prefix.in", "r", stdin);
        freopen("prefix.out", "w", stdout);
	string temp;
	while(cin >> temp){
		if(temp == ".") break;
		k.insert(temp);
	}
	string goal, p;
	while(cin >> p) goal += p;
	dp[0] = 1;
	for(int i = 1; i <= (int)goal.size(); i++){
		for(int j = 1; j <= min(i, 11); j++){
			if(dp[i - j]){
				temp = goal.substr(i - j, j);
				if(k.find(temp) != k.end()){
					dp[i] = 1;
					break;
				}
			}
		}
	}
	for(int i = (int)goal.size(); i >= 0; i--){
		if(dp[i]){
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
