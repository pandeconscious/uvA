#include<iostream>
#include<string>
#include<sstream>

using namespace std;

string tostring(int a){
	stringstream s;
	s << a;
	return s.str();
}

string get_string(int a, int n){
	if(a > n)
		return "Blank"; 
	else
		return tostring(a);
}

int main(){
	int n;
	while((cin >> n) && n){
		int N = n/4;
		int R = n%4;
		if(R > 0){
			N++;
		}
		cout << "Printing order for " << n << " pages:" << endl;
		for(int i = 1; i <= N; i++){
			string F1 = get_string(2*i-1, n);
			string F2 = get_string(4*N-2*i+2, n);
			string B1 = get_string(2*i, n);
			string B2 = get_string(4*N-2*i+1, n);
			if(F1 != "Blank" || F2 != "Blank"){
				cout << "Sheet " << i << ", front: " << F2 << ", " << F1 << endl;
			}
			if(B1 != "Blank" || B2 != "Blank"){
				cout << "Sheet " << i << ", back : " << B1 << ", " << B2 << endl;
			}
		}

	}
	return 0;
}
