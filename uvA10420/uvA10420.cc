#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
	map<string, int> my_map;
	string line;
	getline(cin, line);
	while(getline(cin, line)){
		int index = line.find_first_of(" ");
		string country = line.substr(0, index);
		map<string,int>::iterator itr = my_map.find(country);
		if(itr == my_map.end()){
			my_map[country] = 1;
		}
		else{
			my_map[country] = my_map[country]+1;
		}

	}
	for(map<string,int>::iterator itr = my_map.begin(); itr != my_map.end(); itr++){
		cout << itr->first << " " << itr->second << endl;
	}
	return 0;
}
