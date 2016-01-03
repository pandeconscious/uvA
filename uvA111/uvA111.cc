#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

bool precedes(int a, int b, vector<int>& correct){
	vector<int>::iterator itrA = find(correct.begin(), correct.end(), a);
	vector<int>::iterator itrB = find(correct.begin(), correct.end(), b);
	return itrB - itrA > 0;
}

int score(vector<int>& current, vector<int>& correct){
	int n = current.size();
	vector<int> dp(n,1);	
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			if(precedes(current[j], current[i], correct) && dp[j]+1 > dp[i])
				dp[i] = dp[j]+1;
		}
	}
	return *max_element(dp.begin(), dp.end());
}

int main(){
	int n;
	string s;
	getline(cin, s);
	stringstream ssin(s);
	ssin >> n;
	getline(cin, s);
	stringstream sin(s);
	vector<int> correct(n);
	int el;
	int i = 0;
	while(sin >> el){
		correct[el-1] = i;
		i++;
	}
	while(getline(cin, s)){
		vector<int> current(n);
		stringstream sin(s);
		i = 0;
		while(sin >> el){
			current[el-1] = i;
			i++;
		}
		cout << score(current, correct) << endl;
	}
	return 0;
}
