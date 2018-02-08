/*
 * My solution to the "Judge Route Circle" problem found here:
 * https://leetcode.com/problems/judge-route-circle/description/
*/

#include <iostream>		// for cout, cin, etc
#include <string>		// for strings

using namespace std;


class Solution {
public:
	bool judgeCircle(string moves) {
		/*
		 * Determine if start point = end point
		 *
		 * type	moves	: string
		 * rtype		: bool
		*/

		// Create displacement trackers
		int vertical = 0;
		int horizontal = 0;

		// Loop through the moves
		for(int i = 0; i < moves.size(); i++) {
			// Determine the placement based on moves
			switch(moves[i]) {
				case 'L':
					horizontal--;
					break;
				case 'R':
					horizontal++;
					break;
				case 'U':
					vertical++;
					break;
				case 'D':
					vertical--;
					break;
				default:
					continue;
			}
		}

		return (vertical == 0) && (horizontal == 0);
	}
};


int main() {
	// Intro message
	string introMessage =
						"\n 			Judge Route: Circle\n"
						"Determine if the route's end destination is the starting point."
						"\n 	Instructions - Enter a string made out of: \n"
						"			- R 	:	Move Right\n"
						"			- L 	:	Move Left\n"
						" 			- U 	:	Move Up\n"
						"			- D 	: 	Move Down\n"
						"		Example: 'UDLR' = 'Move up, down, left, and right.'\n";
	cout << introMessage << endl;

	// Create an instance to Solution class
	Solution *sol = new Solution();

	// Ask the user for input
	cout << "Enter a route: ";
	// Save user input
	string usrRoute;
	cin >> usrRoute;

	// judge the route
	bool result = sol->judgeCircle(usrRoute);

	// Check the result and print out a statement
	if (result) {
		cout << "\nYour route loops back!" << endl;
		cout << "...exiting....\n" << endl;
	}else {
		cout << "\nYour route doesn't loop back." << endl;
		cout << "...exiting....\n" << endl;
	}

	return 0;
}