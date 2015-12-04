#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;


void next_position(int i, int j, int& I, int& J, vector<vector<int> >& arr, int b, int w, char& dir){
	switch(dir){
		case 'r':
			if(i + 1 < b && arr[i+1][j] == 0){
				I = i+1;
				J = j;
				dir = 'd';
			}
			else if(j + 1 < w && arr[i][j+1] == 0){
				I = i;
				J = j+1;
				dir = 'r';
			}
			else if(i-1 >= 0 && arr[i-1][j] == 0){
				I = i -1;
				J = j;
				dir = 'u';
			}
			else if(j-1 >= 0 && arr[i][j-1] == 0){
				I = i;
				J = j-1;
				dir = 'l';
			}
			else{
				cout << "BUG" << endl;	
			}
			break;

		case 'l':
			if(i - 1 >= 0 && arr[i-1][j] == 0){
				I = i-1;
				J = j;
				dir = 'u';
			}
			else if(j - 1 >= 0 && arr[i][j-1] == 0){
				I = i;
				J = j-1;
				dir = 'l';
			}
			else if(i+1 < b && arr[i+1][j] == 0){
				I = i +1;
				J = j;
				dir = 'd';
			}
			else if(j+1 < w && arr[i][j+1] == 0){
				I = i;
				J = j+1;
				dir = 'r';
			}
			else{
				cout << "BUG" << endl;	
			}
			break;

		case 'u':
			if(j + 1 < w && arr[i][j+1] == 0){
				I = i;
				J = j+1;
				dir = 'r';
			}
			else if(i - 1 >= 0 && arr[i-1][j] == 0){
				I = i-1;
				J = j;
				dir = 'u';
			}
			else if(j-1 >= 0 && arr[i][j-1] == 0){
				I = i;
				J = j-1;
				dir = 'l';
			}
			else if(i+1 < b && arr[i+1][j] == 0){
				I = i+1;
				J = j;
				dir = 'd';
			}
			else{
				cout << "BUG" << endl;	
			}
			break;

		case 'd':
			if(j - 1 >= 0 && arr[i][j-1] == 0){
				I = i;
				J = j-1;
				dir = 'l';
			}
			else if(i + 1 < b && arr[i+1][j] == 0){
				I = i+1;
				J = j;
				dir = 'd';
			}
			else if(j+1 < w && arr[i][j+1] == 0){
				I = i;
				J = j+1;
				dir = 'r';
			}
			else if(i-1 >= 0 && arr[i-1][j] == 0){
				I = i-1;
				J = j;
				dir = 'u';
			}
			else{ 
				cout << "BUG" << endl;	
			}
			break;
	}
}

void get_counts(int& zero, int& one, int& two, int& three, int& four, vector<vector<int> >& ans, int b, int w){
	for(int i = 0; i < b; i++){
		for(int j = 0; j < w; j++){
			switch(ans[i][j]){
				case 0:
					zero++;
					break;
				case 2:
					one++;
					break;
				case 4:
					two++;
					break;
				case 6:
					three++;
					break;
				case 8:
					four++;
					break;
			}
		}
	}
}

int main(){
	int b, w;

	while((cin >> b >> w) && b != 0 && w != 0){
		char ch;
		int blocked_count = 0;
		vector<vector<int> > arr(b);
		vector<vector<int> > ans(b);
		for(int i = 0; i < b; i++){
			arr[i].resize(w);
			ans[i].resize(w);
		}

		for(int i = 0; i < b; i++){
			for(int j = 0; j < w; j++){
				cin >> ch;
				arr[i][j] = ch - '0';
				if(arr[i][j] == 1)
					blocked_count++;
			}
		}

		int i = b-1, j = 0;
		char dir = 'r';
		while(true){
			ans[i][j]++;// leaving the cell
			int I, J;
			next_position(i, j, I, J, arr, b , w, dir);
			ans[I][J]++;// entering a cell	
			if(I == b-1 && J == 0)
				break;
			i = I;
			j = J;
		}
		int zero = 0, one = 0, two = 0, three = 0, four = 0;
		get_counts(zero, one, two, three, four, ans, b, w);
		printf("%*d%*d%*d%*d%*d\n", 3, zero-blocked_count, 3, one, 3, two, 3, three, 3, four);
		//cout << " " << zero-blocked_count << " " << one << " " << two << " " << three << " " << four << endl;
	}
	return 0;
}
