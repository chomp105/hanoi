#include <iostream>
#include <stdlib.h>
using namespace std;

void print(const int towers[3][5]);
void move(int towers[3][5]);
int tower_top_checker(int towers[3][5], int tower);
bool check_won(const int towers[3][5]);

int main(void) {
	system("clear");
	int towers[3][5] = {
		{5, 4, 3, 2, 1},
		{0},
		{0}
	};
	bool done {false};
	while(!done) {
		system("clear");
		print(towers);
		move(towers);
		done = check_won(towers);
	}
	system("clear");
	print(towers);
	system("figlet WINNER!!!");
	return 0;
}
void print(const int towers[3][5]) {
	for(int i {4}; i >= 0; i--) {
		for(int j {0}; j < 3; j++) {
			for(int k {0}; k < towers[j][i]; k++) {
				cout << "\033[" << towers[j][i] + 30 << "m▓\033[0m";
			}
			for(int k {0}; k < 6 - towers[j][i]; k++) {
				cout << " ";
			}
		}
		cout << endl;
	}
	cout << "\033[90m▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\033[0m" << endl;
}

void move(int towers[3][5]) {
	int tower1 , tower2, tower1_top, tower2_top;
	cout << "Which tower do you want to take a ring from: ";
	cin >> tower1;
	cout << "Where do you want to put the ring: ";
	cin >> tower2;
	tower1--, tower2--;
	if(tower1 < 3 && tower2 < 3 && tower1 >= 0 && tower2 >= 0) {
		tower1_top = tower_top_checker(towers, tower1);
		tower2_top = tower_top_checker(towers, tower2);
		if(towers[tower1][tower1_top] < towers[tower2][tower2_top]) {
			towers[tower2][tower2_top + 1] = towers[tower1][tower1_top];
			towers[tower1][tower1_top] = 0;
		} else if(towers[tower2][tower2_top] == 0) {
			towers[tower2][tower2_top] = towers[tower1][tower1_top];
			towers[tower1][tower1_top] = 0;
		}
	} else if (cin.fail()) {
		cin.clear();
		cin.ignore();
		system("clear");
		print(towers);
		move(towers);
	}
}

int tower_top_checker(int towers[3][5], int tower) {
	for(int i {0}; i < 5; i++) {
		if(towers[tower][i] == 0) {
			if(i == 0) {
				return 0;
			}
			return i - 1;
		}
		if(i == 4) {
			return 4;
		}
	}
	return 0;
}

bool check_won(const int towers[3][5]) {
	for(int i {0}; i < 5; i++) {
		if(towers[2][i] == 0) {
			return false;
		}
	}
	return true;
}
