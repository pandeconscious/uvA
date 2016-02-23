#include<iostream>
#include<cstring>

using namespace std;

int numNodes, numEdges;
int adj[200][200];
int color[200];//0 is unvisited, 1 is red, -1 is black

bool isBipartite(int node, int parentColor){
	color[node] = -parentColor;
	for(int nbr = 0; nbr < numNodes; ++nbr){
		if(adj[node][nbr] == 1){
			if(color[nbr] == color[node])//same color false
				return false;
			if(color[nbr] == 0){//unvisited case
				if(!isBipartite(nbr, color[node]))
					return false;
			}
		}
	}
	return true;
}

int main(){
	while(cin >> numNodes && numNodes != 0){
		memset(adj, 0, 200*200*sizeof(int));
		memset(color, 0, 200*sizeof(int));
		cin >> numEdges;
		for(int i = 1; i <= numEdges; ++i){
			int u, v;
			cin >> u >> v;
			adj[u][v] = adj[v][u] = 1;
		}
		if(isBipartite(0, -1)){
			cout << "BICOLORABLE." << endl;
		}
		else{
			cout << "NOT BICOLORABLE." << endl;
		}
	}
	return 0;
}
