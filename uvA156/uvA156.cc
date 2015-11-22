#include<iostream>
#include<set>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

int main(){
	set<string> output_set;
	map<string, pair<string, bool> > processing_set;
	string curr;
	map<string, pair<string, bool> >::iterator itr;
	while(cin >> curr){
		if(curr == "#"){
			break;
		}
		string curr_lower = "";
		for(string::iterator itr = curr.begin(); itr != curr.end(); ++itr){
			curr_lower.push_back(tolower(*itr));
		}
		sort(curr_lower.begin(), curr_lower.end());
		itr = processing_set.find(curr_lower);

		if(itr == processing_set.end()){
			processing_set[curr_lower] = make_pair(curr, false);
		}
		else{
			processing_set[curr_lower].second = true;
		}
	}
	for(itr = processing_set.begin(); itr != processing_set.end(); ++itr){
		if((itr->second).second == false){
			output_set.insert((itr->second).first);
		}
	}
	for(set<string>::iterator itr = output_set.begin(); itr != output_set.end(); ++itr){
		cout << *itr << endl;
	}
	return 0;
}
