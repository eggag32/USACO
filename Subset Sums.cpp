/*
ID: egor_ga1
PROG: subset
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
	freopen("subset.in", "r", stdin);
        freopen("subset.out", "w", stdout);
	ll n;
	cin >> n;
	ll ways[1000];
	ways[0] = 1;
	if(((n * (n + 1)) / 2) % 2 != 0){
		cout << "0" << endl;
		return 0;
	}	
	for(int i = 1; i <= n; i++){
		for(int j = (n * (n + 1))/2; j >= i; j--){
			ways[j] += ways[j - i];
		}
	}
	cout << ways[n * (n + 1)/4]/2 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
