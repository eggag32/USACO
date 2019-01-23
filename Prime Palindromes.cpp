/*
ID: egor_ga1
PROG: pprime
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

vi palindromes;

bool is_prime(int h){
	for(int i = 3; i <= sqrt(h); i++){
		if(h % i == 0){
			return false;
		}
	}
	return true;
}

void genpals(){
	//generate palindromes of different lengths
	for(int i = 1; i <= 9; i += 2){
		palindromes.pb(i);
	}
	for(int i = 1; i <= 9; i += 2){
		palindromes.pb(i * 10 + i);
	}
	for(int i = 1; i <= 9; i += 2){
		for(int a = 0; a <= 9; a++){
			palindromes.pb(i * 100 + a * 10 + i);
		}
	}
	for(int i = 1; i <= 9; i += 2){
		for(int a = 0; a <= 9; a++){
			palindromes.pb(i * 1000 + a * 100 + a * 10 + i);
		}
	}
	for(int i = 1; i <= 9; i += 2){
		for(int a = 0; a <= 9; a++){
			for(int j = 0; j <= 9; j++){
				palindromes.pb(i * 10000 + a * 1000 + j * 100 + a * 10 + i);
			}
		}
	}
	for(int i = 1; i <= 9; i += 2){
                for(int a = 0; a <= 9; a++){
                        for(int j = 0; j <= 9; j++){
                                palindromes.pb(i * 100000 + a * 10000 + j * 1000 + j * 100 + a * 10 + i);
                        }
                }
        }
	for(int i = 1; i <= 9; i += 2){
                for(int a = 0; a <= 9; a++){
                        for(int j = 0; j <= 9; j++){
                                for(int x = 0; x <= 9; x++){
					palindromes.pb(i * 1000000 + a * 100000 + j * 10000 + x * 1000 + j * 100 + a * 10 + i);
				}
                        }
                }
        }
	for(int i = 1; i <= 9; i += 2){
                for(int a = 0; a <= 9; a++){
                        for(int j = 0; j <= 9; j++){
                                for(int x = 0; x <= 9; x++){
                                        palindromes.pb(i * 10000000 + a * 1000000 + j * 100000 + x * 10000 + x * 1000 + j * 100 + a * 10 + i);
                                }
                        }
                }
        }
	for(int i = 1; i <= 9; i += 2){
                for(int a = 0; a <= 9; a++){
                        for(int j = 0; j <= 9; j++){
                                for(int x = 0; x <= 9; x++){
					for(int y = 0; y <= 9; y++){
						palindromes.pb(i * 100000000 + a * 10000000 + j * 1000000 + x * 100000 + y * 10000 + x * 1000 + j * 100 + a * 10 + i);
					}
                                }
                        }
                }
        }
}

int main(){
	freopen("pprime.in", "r", stdin);
        freopen("pprime.out", "w", stdout);
	int a, b;
	cin >> a >> b;
	genpals();
	for(int x : palindromes){
		if(x >= a && x <= b){
			if(is_prime(x)){
				cout << x << endl;
			}
			if(x > b){
				return 0;
			}
		}
	}
	return 0;
}
