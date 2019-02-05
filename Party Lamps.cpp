/*
ID: egor_ga1
PROG: lamps
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(),v.end() 
#define mp make_pair
#define pb push_back
#define f first
#define s second

vector<string> ans;
vector<vi> pos;

vi cnt;

int c;
int u;

void dfs(int x, int y){
	if(y == u){
		pos.pb(cnt);
		fill(all(cnt), 0);
		return;
	}
	for(int i = 1; i <= 4; i++){
		if(i != x){
			cnt[x]++;
			dfs(i, y + 1);
			cnt[x]--;
			dfs(i, y + 1);
		}
	}	
}

bool cmp(string& x, string& y){
	for(int i = 0; i < x.size(); i++){
		if(x[i] == '1' && y[i] == '0'){
			return false;
		}
		if(y[i] == '1' && x[i] == '0'){
			return true;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("lamps.in", "r", stdin);
        freopen("lamps.out", "w", stdout);
	int l;
	cin >> l;
	cin >> c;
	vi on, off;
	while(true){
		int f;
		cin >> f;
		if(f == -1){
			break;
		}
		else{
			on.pb(f);
		}
	}
	while(true){
		int g;
		cin >> g;
		if(g == -1){
			break;
		}
		else{
			off.pb(g);
		}
	}
	if(c == 0){
		if(off.size() == 0){
			for(int i = 0; i < l; i++){
				cout << "1";
			}
			cout << endl;
			return 0;
		}
		else{
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
	}
	for(int i = 0; i <= 5; i++){
		cnt.pb(0);
	}
	u = c % 4;
	if(c >= 4){
		u = 4;	
	}
	fill(cnt.begin(), cnt.end(), 0);
	dfs(1, 0);
	for(int i = 0; i < pos.size(); i++){
		string f;
		for(int j = 0; j < l; j++){
			f += '1';
		}
		vi x = pos[i];
		if(x[1] == 1){
			for(int a = 0; a < f.size(); a++){
				if(f[a] == '1'){
					f[a] = '0';
				}
				else{
					f[a] = '1';
				}
			}
		}
		if(x[2] == 1){
			for(int a = 0; a < f.size(); a += 2){
                                if(f[a] == '1'){
                                        f[a] = '0';
                                }
                                else{
                                        f[a] = '1';
                                }
                        }
		}
		if(x[3] == 1){
			for(int a = 1; a < f.size(); a += 2){
                                if(f[a] == '1'){
                                        f[a] = '0';
                                }
                                else{
                                        f[a] = '1';
                                }
                        }
		}
		if(x[4] == 1){
			for(int a = 0; a < f.size(); a += 3){
                                if(f[a] == '1'){
                                        f[a] = '0';
                                }
                                else{
                                        f[a] = '1';
                                }
                        }
		}
		ans.pb(f);
	}
	vector<string> fans;
	for(int i = 0; i < ans.size(); i++){
		string l = ans[i];
		bool x = true;
		for(int a = 0; a < on.size(); a++){
			if(l[on[a] - 1] != '1'){
				x = false;
			}
		}	
		for(int a = 0; a < off.size(); a++){
			if(l[off[a] - 1] != '0'){
				x = false;
			}
		}
		if(x){
			if(find(all(fans), l) == fans.end()){
				fans.pb(l);
			}
		}
	}
	sort(all(fans), cmp);
	for(int i = 0; i < fans.size(); i++){
		cout << fans[i] << endl;
	}
	if(fans.size() == 0){
		cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
*/
