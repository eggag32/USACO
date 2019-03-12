/*
ID: egor_ga1
PROG: runround
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

bool runaround(int m){
	string num = to_string(m);
	int cur = num[0] - '0';
	int index = 0;
	int freq[10];
	memset(freq, 0, sizeof(freq));
	int len = num.size();
	for(int i = 1; i <= len; i++){
		index = (index + cur) % len;
		cur = num[index] - '0';
		freq[cur]++;
		if(freq[cur] > 1) return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("runround.in", "r", stdin);
        freopen("runround.out", "w", stdout);
	int n;
	cin >> n;
	while(true){
		n++;
		if(runaround(n)){
			cout << n << endl;
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
