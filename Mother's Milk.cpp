/*
ID: egor_ga1
TASK: milk3
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int A, B, C;

int v[21][21][21];

vector<int> ans;

void dfs(int a, int b, int c){
	if(v[a][b][c]){
		return;
	}
	v[a][b][c] = 1;
	if(a == 0){
		ans.push_back(c);		
	}
	for(int it = 0; it < 6; it++){
		int n;
	    	int x, y, z;
    		if(it == 0){
			n = min(a, B - b);
			x = a - n;
			y = b + n; 
			z = c;
		}
		if(it == 1){
			n = min(a, C - c);
			x = a - n;
			y = b;
			z = c + n;
		}
		if(it == 2){
		        n = min(b, A - a);
			x = a + n;
			y = b - n;
			z = c;
		}
		if(it == 3){
			n = min(b, C - c);
			x = a; 
			y = b - n;
			z = c + n;
		}
		if(it == 4){
			n = min(c, A - a);
			x = a + n;
			y = b;
			z = c - n;
		}
		if(it == 5){
			n = min(c, B - b);
			x = a;	
			y = b + n;
			z = c - n;
		}
		dfs(x, y, z);		
	}
}

int main(){
	freopen("milk3.in", "r", stdin);
	freopen("milk3.out", "w", stdout);
	cin >> A >> B >> C;
	dfs(0, 0, C);
	sort(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++){
		if(i < ans.size() - 1){
			cout << ans[i] << " ";
		}
		else{
			cout << ans[i];
		}
	}
	cout << endl;
	return 0;
}
