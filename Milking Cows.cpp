/*
 ID: egor_ga1
 TASK: milk2
 LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, int> &left, const pair<int, int> &right){
	return (left.first < right.first);
}

int main(){
	ofstream fout("milk2.out");
	ifstream fin("milk2.in");
	int N;
	vector<pair<int, int>> times;
	fin >> N;
	int a, b;
	for(int i = 0; i < N; i++){
		fin >> a >> b;
		times.push_back(make_pair(a, b));
	}
	sort(times.begin(), times.end(), cmp);
	int idle = 0;
	int current_greatest = times[0].second;
	int left = times[0].first;
	int cont = current_greatest - left;
	for(int i = 1; i < N; i++){
		if(times[i].first > current_greatest){
			if(current_greatest - left > cont){
				cont = current_greatest - left;
			}
			if(times[i].first - current_greatest > idle){
				idle = times[i].first - current_greatest;
			}
			current_greatest = times[i].second;
			left = times[i].first;
		}
		if(current_greatest < times[i].second){
			current_greatest = times[i].second;
		}

	}
	fout << cont << " " << idle << endl;
	return 0;
}
