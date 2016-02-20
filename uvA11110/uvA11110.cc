#include<iostream>
#include<sstream>

using namespace std;

int rowDel[] = {0, 0, 1, -1};
int colDel[] = {-1, 1, 0, 0};

bool isValidindex(int i, int j, int N){
	return i >= 0 && i < N && j >= 0 && j < N;
}

void DFS(int i, int j, int** mat, bool** visited, int N){
	visited[i][j] = true;
	int indDel = 0;
	while(indDel < 4){
		int nbrI = i + rowDel[indDel];
		int nbrJ = j + colDel[indDel];
		if(isValidindex(nbrI, nbrJ, N) && mat[i][j] == mat[nbrI][nbrJ] && visited[nbrI][nbrJ] == false){
			DFS(nbrI, nbrJ, mat, visited, N);
		}
		indDel++;
	}
}

int DFSconnectedComponents(int** mat, int N){
	bool** visited = new bool*[N];		
	for(int i = 0; i < N; ++i){
		visited[i] = new bool[N];
	}
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			visited[i][j] = false;			
		}
	}
	int count = 0;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(visited[i][j] == false){
				DFS(i, j, mat, visited, N);	
				count++;
			}
		}
	}
	return count;
}

int main(){
	int N;
	while(cin >> N && N != 0){
		int** mat = new int*[N];
		for(int i = 0; i < N; i++){
			mat[i] = new int[N];	
		}
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < N; ++j){
				mat[i][j] = -1;
			}
		}

		string s;
		getline(cin, s);
		
		for(int k = 1; k < N; ++k){
			getline(cin, s);
			stringstream sin;
			sin << s;
			int i, j;
			while(sin >> i && sin >> j){
				mat[i-1][j-1] = k;	
			}

		}

		if(DFSconnectedComponents(mat, N) == N){
			cout << "good" << endl;
		}
		else{
			cout << "wrong" << endl;
		}
	}
}
