/*
ID: egor_ga1
PROG: castle
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

int rn = 0;

int c[51][51];
int v[51][51];
int b[51][51];
int room[3000];

void dfs(int x, int y, int& z){
	if(v[x][y]){
		return;
	}
	v[x][y] = 1;
	b[x][y] = rn;
	z++;
	if(!(c[x][y]&1)){
		dfs(x, y - 1, z);
	}
	if(!(c[x][y]&2)){
		dfs(x - 1, y, z);
	}
	if(!(c[x][y]&4)){
		dfs(x, y + 1, z);
	}
	if(!(c[x][y]&8)){
		dfs(x + 1, y, z);
	}
}

int main(){
	freopen("castle.in", "r", stdin);
        freopen("castle.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			cin >> c[i][j];
		}
	}
	int mx = 0;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(!v[i][j]){
				rn++;
				int crn = 0;
				dfs(i, j, crn);
				room[rn] = crn;
				mx = max(crn, mx);
			}
		}
	}
	int maxr = 0;
	int bx;
	int by;
	char bd;
	for(int j = 1; j <= m; j++){
		for(int i = n; i >= 1; i--){
			if(c[i][j]&2){
				if(b[i - 1][j] && b[i - 1][j] != b[i][j]){
					if((room[b[i][j]] + room[b[i - 1][j]]) > maxr){
						maxr = room[b[i - 1][j]] + room[b[i][j]];
						bd = 'N';
						bx = j;
						by = i;
					}
				}
			}
			if(c[i][j]&4){
				if(b[i][j + 1] && b[i][j + 1] != b[i][j]){
					if((room[b[i][j]] + room[b[i][j + 1]]) > maxr){
						maxr = room[b[i][j]] + room[b[i][j + 1]];
						bd = 'E';
						bx = j;
						by = i;
					}
				}
			}
		}
	}
	cout << rn << endl;
	cout << mx << endl;
	cout << maxr << endl;
	cout << by << " " << bx << " " << bd << endl;
	return 0;	
}
