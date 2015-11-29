#include<iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		int x, y;
		cin >> x >> y;
		if(x < y || (x+y)%2 != 0)
			cout << "impossible" << endl;
		else
			cout << (x+y)/2 << " " << (x-y)/2 << endl;
	}
	return 0;
}
