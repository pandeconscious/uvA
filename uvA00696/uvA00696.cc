#include<iostream>

using namespace std;

int extra_knights(int n){
	int r = n%4;
	if(r == 1)
		return 2;
	else if(r == 2 || r == 3)
		return 4;
	else return 0;
}

int main(){
	int m, n, ans;
	bool swapped = false;

	while(cin >> m && cin >> n){
		swapped = false;
		if(m == 0 && n == 0){
			break;
		}
		if(m > n){
			swap(m, n);
			swapped = true;
		}
		if(m == 1){
			ans = n;
		}
		else if(m == 2){
			ans = (n/4)*4 + extra_knights(n);
		}
		else{
			ans = (m*n +1)/2;
		}
		
		if(swapped){
			cout << ans << " knights may be placed on a " << n << " row " << m << " column board." << endl;
		}
		else{
			cout << ans << " knights may be placed on a " << m << " row " << n << " column board." << endl;
		}


	}
}
