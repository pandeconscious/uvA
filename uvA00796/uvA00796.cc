#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

void DFSbridges(int node, int parent, int** mat, int n, int *disc, int *low, vector<pair<int, int> >& critical_links, int& t){
	disc[node] = t;
	low[node] = t;
	t++;
	for(int node2 = 0; node2 < n; node2++){
		if(mat[node][node2] == 1 && node2 != parent){
			if(disc[node2] == -1){//tree edge
				DFSbridges(node2, node, mat, n, disc, low, critical_links, t);	
				low[node] = min(low[node], low[node2]);
				if(low[node2] > disc[node]){
					critical_links.push_back(make_pair(min(node, node2), max(node, node2)));
				}
			}
			else{//back edge
				low[node] = min(low[node], disc[node2]);
			}
		}
	}
}

int main(){
	int n;
	
	while(cin >> n){
		int** mat = new int*[n];
		for(int i = 0; i < n; i++){
			mat[i] = new int[n];
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				mat[i][j] = 0;
			}
		}
		for(int s = 1; s <= n; ++s){
			int u; 
			cin >> u;
			char paren;
			cin >> paren;
			int nbrs;
			cin >> nbrs;
			cin >> paren;

			for(int t = 1; t <= nbrs; ++t){
				int v;
				cin >> v;
				mat[u][v] = mat[v][u] = 1;
			}
		}
		vector<pair<int, int> > critical_links;
		int* disc = new int[n];
		for(int i = 0; i < n; i++){
			disc[i] = -1;
		}
		int* low = new int[n];
		int t = 0;
		for(int node = 0; node < n; node++){
			if(disc[node] == -1){
				DFSbridges(node, -1, mat, n, disc, low, critical_links, t);
			}
		}
		sort(critical_links.begin(), critical_links.end());
		cout << critical_links.size() << " critical links" << endl;
		for(int i = 0; i < critical_links.size(); ++i){
			cout << critical_links[i].first << " - " << critical_links[i].second << endl;
		}
		cout << endl;
	}
	return 0;
}
