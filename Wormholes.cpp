/*
ID: egor_ga1
PROG: wormhole
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_N 12

int N;
int partner[MAX_N + 1];
int X[MAX_N + 1], Y[MAX_N + 1];
int next_on_right[MAX_N + 1];

ifstream fin("wormhole.in");
ofstream fout("wormhole.out");

bool cycle_exists(){
	for(int start = 1; start <= N; start++){
		int pos = start;
		for(int count = 0; count < N; count++){
			pos = next_on_right[partner[pos]];
		}
		if(pos != 0){
			return true;
		}
	}
	return false;
}

int solve(){
	int total = 0;
	int i;
	for(i = 1; i <= N; i++){
		if(partner[i] == 0){
			break;
		}
	}
	if(i > N){
		if(cycle_exists()){
			return 1;
		}
		else{
			return 0;	
		}
	}
	for(int j = i + 1; j <= N; j++){
		if(partner[j] == 0){
			partner[i] = j;
			partner[j] = i;
			total += solve();
			partner[i] = partner[j] = 0;	
		}
	}
	return total;
}

int main(){
	fin >> N;
	for(int i = 1; i <= N; i++){
		fin >> X[i] >> Y[i];
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if(Y[i] == Y[j] && X[j] > X[i]){
				if(next_on_right[i] == 0 || 
					(X[j] - X[i]) < (X[next_on_right[i]] - X[i])){
					next_on_right[i] = j;
				}	
			}
		}
	}
	fout << solve() << endl;
	return 0;	
}
