#include<iostream>
#include<cstdio>
#include<sstream>
#include<cmath>

using namespace std;

int to_int(string s){
	stringstream sin(s);
	int n;
	sin >> n;
	return n;
}

int main(){
	string line;
	while(getline(cin, line) && line != "0:00"){
		int h, m;
		int ind = line.find_first_of(":");
		h = to_int(line.substr(0, ind));
		m = to_int(line.substr(ind+1, line.size()-ind-1));
		double angle_m = (double)m*6;
		double angle_h = h == 12 ? 0.0 : (double)h*30;
		angle_h += (double)m/2;
		double diff = fabs(angle_h - angle_m);
		if(diff > 180.0){
			diff = 360.0 - diff;
		}
		printf("%.3f\n", diff);
	}
	return 0;
}

