#include<iostream>
#include<cmath>
#include<vector>
#include<string>


using namespace std;

//if perfect square the square root is stored in n
bool perfect_square(int N, int & n){
	if(N == 0){
		n = 0;
		return true;
	}
	if(N == 1){
		n = 1;
		return true;
	}
	int approx_sq = (int)sqrt(N);
	for(int i = approx_sq - 1; i <= approx_sq + 1; i++){
		if(i*i == N){
			n = i;
			return true;
		}
	}
	n = -1;
	return false;
}

//this condition checks equality of ith row and ith column 
bool equality1(vector<char>& a, int n){
	for(int i = 0; i < n; i++){
		for(int k =0; k < n; k++){
			if(a[i*n + k] != a[k*n + i]) // indexing as if 2-D table
				return false;
		}
	}
	return true;
}

//this coniditon checks equality of ith row and (n-i-1)th reverse column
bool equality2(vector<char>& a, int n){
	for(int i = 0; i < n; i++){
		for(int k = 0; k < n; k++){
			if(a[i*n + k] != a[(n-k-1)*n + (n-i-1)])
				return false;
		}
	}
	return true;
}

int main(){
	int T;
	cin >> T;
	string dummy;
	getline(cin, dummy);
	for(int i = 1; i <= T; i++){
		string s;
		vector<char> table;

		cout << "Case #" << i << ":" << endl;
		getline(cin, s);
		for(string::iterator itr = s.begin(); itr != s.end(); itr++){
			if(isalpha(*itr)){
				table.push_back(*itr);
			}
		}
		
		int N = table.size();
		int n;
		if(!perfect_square(N, n)){
			cout << "No magic :(" << endl;	
			continue;
		}
		
		if(!equality1(table,n) || !equality2(table,n)){
			cout << "No magic :(" << endl;	
			continue;
		}
		cout << n << endl;
	}
	
	return 0;
}
