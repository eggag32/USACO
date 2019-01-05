/*
ID: egor_ga1
PROG: palsquare
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ofstream fout("palsquare.out");
ifstream fin("palsquare.in");

vector<int> to_base(int a, int c){
        vector<int> e;
        while(a > 0){
                int g = a % c;
		e.push_back(g);
                a /= c;
        }
	reverse(e.begin(), e.end());
        return e;
}

bool palindrome(vector<int> b){
        for(int i = 0; i < (b.size()/2); i++){
                if(b[i] != b[b.size() - i - 1]){
                        return false;
                }
        }
        return true;
}

int main(){
	int b;
	fin >> b;
	char chars[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	for(int i = 1; i <= 300; i++){
		int s = i * i;
		if(palindrome(to_base(s, b)) == true){
			vector<int> a = to_base(i, b);
			for(int j = 0; j < a.size(); j++){
				if(a[j] > 9){
					fout << chars[a[j] - 10];
				}
				else{
					fout << a[j];
				}
			}		
			fout << " ";
			vector<int> o = to_base(s, b);  
                        for(int j = 0; j < o.size(); j++){
                                if(o[j] > 9){
                                        fout << chars[o[j] - 10];
                                }
                                else{
                                        fout << o[j];
                                }

                        }
			fout << endl;	
		}
	}
	return 0;	
}
