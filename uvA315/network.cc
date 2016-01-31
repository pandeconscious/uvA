#include<iostream>
#include<cstring>
#include<string>
#include<sstream>

using namespace std;

int AdjMat[101][101];
int StartTime[101];
int LowestStartTimeDescendant[101];
int Parent[101];
int t = 0;
bool rootCanBeArtPoint = false;

int ToInt(string s){
	stringstream sin;
	sin << s;
	int n;
	sin >> n;
	return n;
}

void DFSArtPoint(int u, int N, int& numArtPoints){
	StartTime[u] = ++t;
	LowestStartTimeDescendant[u] = StartTime[u];
	bool isArt = false;//whether u is Art Point or not
	for(int v = 1; v <= N; v++){
		if(AdjMat[u][v] && v != Parent[u]){
			if(StartTime[v] > 0){//already explored edge
				if(StartTime[v] < LowestStartTimeDescendant[u]){
					LowestStartTimeDescendant[u] = StartTime[v];
				}
			}
			else{
				Parent[v] = u;	
				DFSArtPoint(v, N, numArtPoints);
				if(LowestStartTimeDescendant[v] < LowestStartTimeDescendant[u]){
					LowestStartTimeDescendant[u] = LowestStartTimeDescendant[v];
				}
				if(StartTime[u] <= LowestStartTimeDescendant[v]){
					isArt = true;
				}
			}
		}
	}
	if(isArt){
		numArtPoints++;
		if(u == 1){
			rootCanBeArtPoint = true;
		}
	}
}

int CountArtPoints(int N){
	int numArtPoints = 0;
	for(int u = 1; u <= N; u++){
		if(StartTime[u] == 0){//unvisited
			DFSArtPoint(u, N, numArtPoints);
		}
	}
	//check if root has more than one children in the DFS tree
	if(rootCanBeArtPoint){
		int numRootChildren = 0;
		for(int i = 1; i <= N; ++i){
			if(Parent[i] == 1)
				numRootChildren++;
		}
		if(numRootChildren <=1)
			numArtPoints--;
	}
	return numArtPoints;
}

int main(){
	string line;
	while(getline(cin, line) && line != "0"){
		int N = ToInt(line);	
		memset(AdjMat, 0, 101*101*sizeof(int));
		memset(StartTime, 0, 101*sizeof(int));
		memset(LowestStartTimeDescendant, 0, 101*sizeof(int));
		memset(Parent, 0, 101*sizeof(int));
		t = 0;
		rootCanBeArtPoint = false;
		while(getline(cin, line) && line != "0"){
			stringstream sin;	
			sin << line;
			int u, v;
			sin >> u;
			while(sin >> v){
				AdjMat[u][v] = 1;
				AdjMat[v][u] = 1;
			}
		}
		cout << CountArtPoints(N) << endl;
		/*
		cout << endl;
		for(int i = 1; i <= N; ++i){
			cout << "for node " << i << " start time: " << StartTime[i] << " and lowest time: " << LowestStartTimeDescendant[i] << endl; 
		}
		*/
	}
	return 0;
}
