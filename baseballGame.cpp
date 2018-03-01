/*
 * Baseball Game
 * Yufang Lin
 *
 * My Solution to leetCode problem called, "Baseball Game":
 * https://leetcode.com/problems/baseball-game/description/
*/

#include <iostream>		// For cout, cin, etc
#include <string>		// For strings
#include <vector>		// For vectors
#include <stdlib.h>		// For atoi

using namespace std;


class Solution {
public:
	int calPoints(vector<string>& ops) {
		/*
		 * Find the some of valid scores
		 * 		integer	: valid integer score
		 *			+	: sum of last two valid points
		 *			D 	: Double last valid score
		 *			C 	: Last valid score is no longer valid
		 *
		 * type	ops		: vector<string>
		 * rtype 		: int
		*/

		// Check to see if vector is empty
		if (ops.empty()) {
			return 0;
		}

		// Create a storage for the sum
		int sum = 0;

		// create a storage of 
		vector<int> validScores;

		// loop through the score
		for(int i = 0; i < ops.size(); i++) {
			// cout << "current Sum: " << sum << endl;
			// Check if the previous score wasn't valid
			if (ops[i] == "C") {
				// Check if there are any valid scores to remove
				if (!ops.empty()) {
					// subtract the last valid score from sum
					sum -= validScores.back();
					// cout << "remove last valid score: " << validScores.back() << endl;
					// remove the last score
					validScores.pop_back();
					// skip to next score
					continue;
				}
				// no scores to remove, continue to next score
				continue;
			}
			// check if to double the last valid score
			else if (ops[i] == "D") {
				// Check if there are any valid score to double
				if (!ops.empty()) {
					// double score
					int score = (validScores.back() * 2);
					// cout << "last score: " << validScores[validScores.size()-1] << endl;
					// cout << "double score: " << score << endl;
					// add the double score to sum
					sum += score;
					// add the double score to valid scores
					validScores.push_back(score);
					// continue to next score
					continue;
				}

				// no scores to double, continue to next score
				continue;
			}
			// Check if to find the sum of the last two valid scores
			else if (ops[i] == "+") {
				// Check if there are any valid scores to add
				if (!ops.empty()) {
					int addScores = validScores.back();
					// check if there are 2 or more scores to add
					if (ops.size() >= 2) {
						// Add the second to last score to valid scores
						addScores += validScores.end()[-2];
						// cout << "last two valid scores: " << validScores.back() << ", " << validScores.end()[-2] << endl;
						// add the score to sum
						sum += addScores;
						// add the score to the valid scores
						validScores.push_back(addScores);

						// cout << "add last two valid scores: " << addScores <<endl;
						// continue to next score
						continue;
					}
					else {
						// only one score to add 
						sum += addScores;
						// add the score to valid scores
						validScores.push_back(addScores);
						// continue to next score
						continue;
					}

				}
				// no scores to add, continue to next score
				continue;
			}
			// An integer
			else {
				// change the string to integer
				int score = atoi(ops[i].c_str());
				// cout << "valid score this round: " << score << endl;
				// add integer to sum
				sum += score;
				// add the score to valid scores
				validScores.push_back(score);
				// continue to next score
				continue;
			}

		}

		// cout << endl;

		return sum;
	}
};

int main() {

	// Create an instance of the Solution class
	Solution* sol = new Solution();

	// Create score examples
	vector<string> score1, score2;
	score1.push_back("5");
	score1.push_back("2");
	score1.push_back("C");
	score1.push_back("D");
	score1.push_back("+");

	score2.push_back("5");
	score2.push_back("-2");
	score2.push_back("4");
	score2.push_back("C");
	score2.push_back("D");
	score2.push_back("9");
	score2.push_back("+");
	score2.push_back("+");


	// get the sum of score 1
	int sum1 = sol->calPoints(score1);

	// get the sum of score 2
	int sum2 = sol->calPoints(score2);

	// Print out solution
	cout << "Sum1: " << sum1 << endl;
	cout << "Sum2: " << sum2 << endl;

	return 0;
}