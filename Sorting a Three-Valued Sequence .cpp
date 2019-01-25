/*
ID: egor_ga1
PROG: sort3
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	freopen("sort3.in", "r", stdin);
	freopen("sort3.out", "w", stdout);
	int n;
	cin >> n;
	int array[n];
	vector<pair<int, int>> ans;
	int one[3] = {0, 0, 0};
	for(int i = 0; i < n; i++){
		cin >> array[i];
		one[array[i] - 1]++;	
	}
	int c = 0;
	for(int i = 0; i < one[0]; i++){
		if(array[i] == 2){
			for(int a = one[0]; a < n; a++){
				if(array[a] == 1){
					ans.push_back(make_pair(i + 1, a + 1));
					c++;
					array[i] = 1;
					array[a] = 2;
					break;
				}
			}
		}
		if(array[i] == 3){
			for(int a = (n - 1); a >= one[0]; a--){
				if(array[a] == 1){
					ans.push_back(make_pair(i + 1, a + 1));
					c++;
					array[i] = 1;
					array[a] = 3;
					break;
				}
			}
		}
	}
	for(int i = one[0]; i < (one[0] + one[1]); i++){
		if(array[i] == 3){
			for(int a = (n - 1); a >= (one[1] + one[0]); a--){
				if(array[a] == 2){
					ans.push_back(make_pair(i + 1, a + 1));
					c++;
					array[i] = 2;
					array[a] = 3;
					break;
				}
			}
		}
	}
	cout << c << endl;
	//for(int i = 0; i < ans.size(); i++){
        //        cout << ans[i].first << " " <<  ans[i].second << endl;
        //}
	return 0;
}

