/*
ID: egor_ga1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	int NP, amoney, people, a;
	int name, rem, give, c;
	string giver, recipient;
	ofstream fout ("gift1.out");
	ifstream fin ("gift1.in");
	fin >> NP;
	string names[NP];
	for(int i = 0;i < NP;++i){
		fin >> names[i];
	}
	int balance[NP];
	for (int d = 0;d < NP;++d){
		balance[d] = 0;
	}
	for(int u = 0; u < NP; u++){
		fin >> giver;
		fin >> amoney >> people;
		if (people > 0){
			rem = amoney % people;
			give = amoney / people;
			for(a = 0;a < NP;++a){
		 		if (names[a] == giver){
			    	balance[a] -= amoney;
		        	balance[a] += rem;
		        	break;
				}
	    	}
			for(int w = 0;w < people;++w){
		 		fin >> recipient;
		 		for(c = 0;c < NP;c++){
		 			if (names[c] == recipient){
		 				balance[c] += give;
				 	}
			 	}
			}
		}
	}
	for(int n = 0;n < NP;n++){
		fout << names[n]<<" "<< balance[n]<<endl;
	}
	return 0;
}
