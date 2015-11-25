#include<iostream>
#include<algorithm>
#include<cctype>

using namespace std;

bool comp(char x, char y){
	if(islower(x) && isupper(y)){
		return (x-'a') < (y-'A');
	}
	if(isupper(x) && islower(y)){
		return (x-'A') <= (y-'a');
	}
	return x < y;
}

int main(){
	int T;
	cin >> T;
	for(int i = 1; i <= T; i++){
		string s;
		cin >> s;
		sort(s.begin(), s.end(), comp);
		do{
			cout << s << endl;
		}
		while(next_permutation(s.begin(), s.end(), comp));
	}
	return 0;
}
