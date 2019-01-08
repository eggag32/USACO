/*
ID: egor_ga1
PROG: crypt1
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");
	int n;
	fin >> n;
	vector<int> num;
	for(int i = 0; i < n; i++){
		int l;
		fin >> l;
		num.push_back(l);
	}	
	int ans = 0;
	for(int i = 111; i < 1000; i++){
		string x = to_string(i);
                bool p = true;
                for(int j = 0; j < x.size(); j++){
			int tm = x[j] - '0';
                        if(find(num.begin(), num.end(), tm) == num.end()){
                                p = false;
                        }
		}
		if(p == true){
		   for(int a = 11; a < 100; a++){
			bool m = true;
			string f = to_string(a);
			for(int s = 0; s < f.size(); s++){
				int te = f[s] - '0';
				if(find(num.begin(), num.end(), te) == num.end()){
					m = false;
				}
			}
			char q = f[0];
			int h = q - '0';
			int w = i * h;
			int sum = 0;
			sum += w;
			string y = to_string(w);
			for(int s = 0; s < y.size(); s++){
				int tr = y[s] - '0';
                                if(find(num.begin(), num.end(), tr) == num.end()){
                                        m = false;
                                }
                        }
			if(y.size() > 3){
				m = false;
			}
			char qq = f[1];
			int hh = qq - '0';
			int ww = i * hh;
			sum += ww * 10;
			string yy = to_string(ww);
                        for(int s = 0; s < yy.size(); s++){
				int ts = yy[s] - '0';
                                if(find(num.begin(), num.end(), ts) == num.end()){
                                        m = false;
                                }
                        }
			if(yy.size() > 3){
                                m = false;
                        }
			string yyy = to_string(sum);
                        for(int s = 0; s < yyy.size(); s++){
				int tb = yyy[s] - '0';
                                if(find(num.begin(), num.end(), tb) == num.end()){
                                        m = false;
                                }
                        }
			if(m == true){
				ans++;
			}
		  }
	       }
	}
	fout << ans << endl;
	return 0;
}
