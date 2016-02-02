#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int findSet(vector<int>& nodesSet, int node){
	if(nodesSet[node] == -1)
		return node;
	nodesSet[node] = findSet(nodesSet, nodesSet[node]);
	return nodesSet[node];
}

void unionSet(vector<int>& nodesSet, int node1, int node2){
	int root1 = findSet(nodesSet, node1);
	int root2 = findSet(nodesSet, node2);
	nodesSet[root1] = root2;
}

int main(){
	int numNodes, numEdges;
	while(cin >> numNodes && cin >> numEdges && numNodes != 0 && numEdges != 0){
		int totalWeight = 0;
		int mstWeight = 0;
		//vector<pair<int, int> > adjList(numNodes);
		vector<pair<int, pair<int, int> > > edgesList;
		vector<int> nodesSet(numNodes, -1);
		for(int i = 1; i <= numEdges; i++){
			int u, v, wt;
			cin >> u >> v >> wt;
			edgesList.push_back(make_pair(wt, make_pair(u, v)));	
			totalWeight += wt;	
			//cout << u << " " << v << " " << wt << endl;
		}
		sort(edgesList.begin(), edgesList.end());
		for(int e = 0; e < edgesList.size(); e++){
			int u = edgesList[e].second.first;
			int v = edgesList[e].second.second;
			if(findSet(nodesSet, u) == findSet(nodesSet, v))
				continue;
			mstWeight += edgesList[e].first;	
			unionSet(nodesSet, u, v);
		}
		cout << totalWeight - mstWeight << endl;
	}
	return 0;
}
