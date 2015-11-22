#include<iostream>
#include<vector>

using namespace std;

int main(){
	int T, players, snakes_ladders, rolls;	
	int board_map[101];

	cin >> T;

	for(int t = 1; t <= T; ++t){
		for(int i = 0; i <= 100; i++){
			board_map[i] = i;
		}
		int turn = 1;
		cin >> players >> snakes_ladders >> rolls;
		vector<int> current_position(players+1, 1);
		for(int i = 1; i <= snakes_ladders; i++){
			int head, tail;
			cin >> head >> tail;
			board_map[head] = tail;
		}
		bool just_consume = false;
		for(int d = 1; d <= rolls; d++){
			int die;	
			cin >> die;
			if(just_consume)
				continue;
			
			current_position[turn] += die; 
			if(current_position[turn] > 100){
				current_position[turn] -= die;
			}
			else{
				current_position[turn] = board_map[current_position[turn]];
				if(current_position[turn] == 100){
					just_consume = true;
					continue;
				}
			}
			turn = turn%players + 1;
		}
		for(int p = 1; p <= players; p++){
			cout << "Position of player " << p << " is " << current_position[p] << "." << endl;
		}
	}
	return 0;
}
