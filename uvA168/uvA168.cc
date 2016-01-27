#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

void Traverse(char* adj[255], int len[255], bool lit[255], char M_pos, char T_pos, int k){
	bool trapped = false;
	int step = 0;
	while(!trapped){
		if(step == k){
			cout << T_pos << " ";
			lit[T_pos-0] = true;
			step = 0;
		}
		trapped = true;
		for(int i = 0; i < len[M_pos-0]; ++i){
			char nbr = adj[M_pos-0][i];
			if(nbr != T_pos && !lit[nbr-0]){
				step++;
				T_pos = M_pos;
				M_pos = nbr;
				trapped = false;
				break;
			}
		}
	}
	cout << "/" << M_pos << endl;
}

void Simulate(string& line){
	char* adj[255];
	bool lit[255];
	int len[255];
	memset(len, 0, 255*sizeof(int));
	memset(lit, false, 255*sizeof(int));
	char M_pos, T_pos;
	int k;
	size_t semi_colon_ind = -1;
	size_t last_semi_colon_ind = -1;
	while((semi_colon_ind = line.find_first_of(";", last_semi_colon_ind+1)) != string::npos){
		string node_links = line.substr(last_semi_colon_ind+1, semi_colon_ind-last_semi_colon_ind-1);
		int n = node_links.size();
		adj[node_links[0]-0] = new char[n-2];
		len[node_links[0]-0] = n-2;
		for(int i = 2; i < n; ++i){
			adj[node_links[0]-0][i-2] = node_links[i];	
		}
		last_semi_colon_ind = semi_colon_ind;
	}
	size_t dot_ind = line.find_first_of(".", last_semi_colon_ind+1);
	string last_node_links = line.substr(last_semi_colon_ind+1, dot_ind-last_semi_colon_ind-1);
	int n = last_node_links.size();
	adj[last_node_links[0]-0] = new char[n-2];
	len[last_node_links[0]-0] = n-2;
	for(int i = 2; i < n; ++i){
		adj[last_node_links[0]-0][i-2] = last_node_links[i];	
	}

	M_pos = line[dot_ind+2];
	T_pos = line[dot_ind+4];
	
	stringstream sin;
	sin << line.substr(dot_ind+6, line.size()-dot_ind+6);
	sin >> k;
	Traverse(adj, len, lit, M_pos, T_pos, k);
}

int main(){
	string line;
	while(getline(cin, line) && line != "#"){
		Simulate(line);	
	}
}
