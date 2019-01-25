/*
ID: egor_ga1
PROG: sprime
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

bool is_prime(int h){
	for(int i = 2; i <= sqrt(h); i++){
		if(h % i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	freopen("sprime.in", "r", stdin);
	freopen("sprime.out", "w", stdout);
	int n;
	cin >> n;
	vi temp;
	vi temp1;
	for(int i = 2; i < 9; i++){
		if(is_prime(i)){
			temp.pb(i);
		}
	}
	for(int i = 1; i < n; i++){
		for(int a = 0; a < temp.size(); a++){
			for(int j = 0; j <= 9; j++){
				int N = temp[a] * 10 + j;
				if(is_prime(N)){
					temp1.pb(N);
				}
			}
		}
		temp.clear();
		temp = temp1;
		temp1.clear();	
	}
	for(int i = 0; i < temp.size(); i++){
		cout << temp[i] << endl;
	}
	return 0;
}
