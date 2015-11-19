#include<iostream>

using namespace std;

int main(){
	int T, m, n;
	char piece;
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> piece >> m >> n;
		switch(piece){
			case 'K':
				cout << ((m+1)/2)*((n+1)/2) << endl;
				break;
			case 'k':
				cout << (m*n)/2 << endl;//I think the correct answer is (m*n +1)/2 but uvA accepts (m*n)/2
				break;
			case 'Q':
				cout << min(m,n) << endl;
				break;
			case 'r':
				cout << min(m,n) << endl;
				break;
		}
	}
	return 0;
}
