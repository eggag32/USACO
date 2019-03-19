/*
ID: egor_ga1
PROG: ttwo
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

char g[15][15];
int fx, fy, cx, cy, nx, ny;
int fd = 0, cd = 0;

bool ok(int x, int y){
	if(x >= 0 && x < 10 && y >= 0 && y < 10) return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("ttwo.in", "r", stdin);
	freopen("ttwo.out", "w", stdout);
	rep(i, 10){
		rep(j, 10){
			cin >> g[i][j];
			if(g[i][j] == 'C'){
				cx = i, cy = j;			
				g[i][j] = '.';
			}
			if(g[i][j] == 'F'){
				fx = i, fy = j;
				g[i][j] = '.';
			}
		}
	}	
	int ans = 0;
	while(!(fx == cx && fy == cy)){
		ans++;
		nx = fx + dx[fd], ny = fy + dy[fd];
		if(ok(nx, ny) && g[nx][ny] == '.'){
			fx = nx, fy = ny;
		}
		else{
			fd = (fd + 1) % 4;
		}
                nx = cx + dx[cd], ny = cy + dy[cd];
                if(ok(nx, ny) && g[nx][ny] == '.'){
                        cx = nx, cy = ny;
                }
		else{
			cd = (cd + 1) % 4;
		}
		if(ans == 160000){
			cout << "0" << endl;
			return 0;
		}
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
