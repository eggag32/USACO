/*
ID: egor_ga1
PROG: frac1
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define mp make_pair
#define pb push_back
#define f first
#define s second

struct frac{
	int num;
	int den;
};

bool nocom(int x, int y){
	int h = min(x, y);
	for(int i = 2; i <= h; i++){
		if(x % i == 0 && y % i == 0){
			return false;
		}	
	}
	return true;
}

bool cmp(struct frac& p, struct frac& q){
	if(q.num * p.den - p.num * q.den > 0){
		return true;
	}
	return false;
}

int main(){
	freopen("frac1.in", "r", stdin);
        freopen("frac1.out", "w", stdout);
	int n;
	cin >> n;
	vector<frac> e;
	for(int i = 1; i <= n; i++){
		for(int a = 1; a <= i; a++){
			if(nocom(i, a)){
				frac k;
				k.num = a;
				k.den = i;
				e.pb(k);
			}
		}
	}
	sort(e.begin(), e.end(), cmp);
	cout << "0/1" << endl;
	for(int i = 0; i < e.size(); i++){
		cout << e[i].num << "/" << e[i].den << endl;
	}
	return 0;	
}
