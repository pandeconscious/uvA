#include<iostream>
#include<vector>

using namespace std;

int last = 13;

int solve(int N){
	for(int m = 1; m <= N-1; m++){
		vector<bool> arr(N+1, true);
		int r = 1;
		int count = 1;
		arr[1] = false;
	
		while(1){
			if(r == last){
				if(count == N)
					return m;
				else
					break;
			}
			else{
				int M = m;
				while(M){
					r  = r%N + 1;
					if(arr[r]){
						M--;
					}
				}
				arr[r] = false;
				count++;
			}

		}
	}
}

int main(){
	int N;
	while(cin >> N){
		if(!N)
			break;
		cout << solve(N) << endl;
	}
	return 0;
}
