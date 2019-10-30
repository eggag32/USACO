/*
ID: egor_ga1
PROG: fracdec
LANG: C++11
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define sq(x) ((x) * (x))

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi num1(1000005, 0);

void print(string s){
	int cnt = -1;
	rep(i, s.size()){
		cout << s[i], cnt++;
		if(cnt == 75){
			cout << endl;
			cnt = -1;
		}
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("fracdec.in", "r", stdin);
	freopen("fracdec.out", "w", stdout);
	int num, den;
	cin >> num >> den;
	int d = num / den;
	string ans = to_string(d);
	ans += '.';
	if(num % den == 0){
		ans += '0';
		cout << ans << endl;
		return 0;
	}
	num -= den * d;
	map<int, pi> m;
	int prev;
	while(1){
		int cnt = 0;
		int it1 = 0;
		while(num < den){
			num *= 10;
			if(cnt) ans += '0', it1++;
			cnt++;
		}
		if(m[num].fi){
			string ret = "";
			rep(i, ans.size()){
				if(i == m[num].se) ret += '(';
				ret += ans[i];
			}
			if(num1[num]) while(num1[num]--) ret.pop_back();
			ret += ')';
			print(ret);
			return 0;
		}
		if(!m[num].fi){
			m[num].fi = 1;
			m[num].se = ans.size() - it1;
			num1[num] = it1;
		}
		if(num % den == 0){
			ans += (num / den) + '0';
			break;
		}
		int n = (num / den) * den;
		int rem = num - n;
		if(m[rem].fi){
			if(rem != prev) ans += (num / den) + '0';
			string ret = "";
			rep(i, ans.size()){
				if(i == m[rem].se) ret += '(';
				ret += ans[i];
			}
			if(num1[rem]) while(num1[rem]--) ret.pop_back();
			ret += ')';
			print(ret);
			return 0;
		}
		ans += (num / den) + '0';
		num = rem;
		prev = rem;
		m[rem].fi = 1;
		m[rem].se = ans.size() - it1;
	}
	print(ans);
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

