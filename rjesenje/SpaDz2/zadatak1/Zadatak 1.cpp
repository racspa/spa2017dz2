#include <iostream>
#include <math.h>
#include <vector>
#include <windows.h>

using namespace std;

// constants for board size and board labels
const int X_SIZE = 25;
const int Y_SIZE = 30;

// labels for the cells
const char EMPTY = '-';
const char START = 'A';
const char GOAL = 'B';
const char CURRENT = 'X';

// point structure with all needed variables in one place
// it was more comfortable to work with structure than with a bunch of scattered variables
struct point {
	int xCoord;
	int yCoord;
	char label = EMPTY;
};

point current;
point goal;

point cells[X_SIZE][Y_SIZE];
vector <point> neigbourPoints;

bool startPoint = true;
float getRawDist(point a);
void getNeighbourPoints(point a);
void printBoard();


int main(int argc, const char * argv[]) {

    // setting up the board
	for (int i = 0; i < X_SIZE; i++) {
		for (int j = 0; j < Y_SIZE; j++) {
			cells[i][j].xCoord = i;
			cells[i][j].yCoord = j;
			cells[i][j].label = EMPTY;
		}
	}

	// getting coordinates for the goal and the starting point
	cout << "Enter the starting point X coordinate: ";
	cin >> current.xCoord;
	cout << "Enter the starting point Y coordinate: ";
	cin >> current.yCoord;
	cout << "Enter the goal point X coordinate: ";
	cin >> goal.xCoord;
	cout << "Enter the goal point Y coordinate: ";
	cin >> goal.yCoord;

	cells[goal.xCoord][goal.yCoord].label = GOAL;
	cells[current.xCoord][current.yCoord].label = START;

	while (goal.xCoord != current.xCoord && goal.yCoord != current.yCoord) {

		printBoard();
		getNeighbourPoints(current);

		// here we choose the point that has the minimal raw distance to the goal
		point nextCandidate = neigbourPoints.at(0);
		float minDist = getRawDist(nextCandidate);
		for (int i = 1; i < neigbourPoints.size(); i++) {
			if (getRawDist(neigbourPoints.at(i)) < minDist) {
				minDist = getRawDist(neigbourPoints.at(i));
				nextCandidate = neigbourPoints.at(i);
			}
		}

		// replacing the current point with the next point (the starting point is not replaced)
		cells[current.xCoord][current.yCoord].label = EMPTY;
		if (startPoint) {
			cells[current.xCoord][current.yCoord].label = START;
			startPoint = false;
		}
		current = nextCandidate;
		cells[current.xCoord][current.yCoord].label = CURRENT;
		Sleep(100);
	}

	return 0;
}


// function that calculates the raw distance to the goal
float getRawDist(point a) {

	float distX = abs(goal.xCoord - a.xCoord);
	float distY = abs(goal.yCoord - a.yCoord);

	return sqrt(powf(distX, 2) + powf(distY, 2));
}


// function that gets all the neighbour points for a selected point
// it also takes care of the border cases
void getNeighbourPoints(point a) {

	neigbourPoints.clear();
	if (a.yCoord != 0) {
		neigbourPoints.push_back(cells[a.xCoord][a.yCoord - 1]);
	}
	if (a.xCoord != X_SIZE - 1) {
		neigbourPoints.push_back(cells[a.xCoord + 1][a.yCoord]);
	}
	if (a.yCoord != Y_SIZE - 1) {
		neigbourPoints.push_back(cells[a.xCoord][a.yCoord + 1]);
	}
	if (a.xCoord != 0) {
		neigbourPoints.push_back(cells[a.xCoord - 1][a.yCoord]);
	}
}


// function that displays the board at its current state
void printBoard() {

	for (int i = 0; i < X_SIZE; i++) {
		for (int j = 0; j < Y_SIZE; j++) {
			cout << cells[i][j].label;
		}
		cout << endl;
	}
}

