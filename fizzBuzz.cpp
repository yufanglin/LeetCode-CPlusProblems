#include <iostream>	// for cout, cin, etc
#include <vector>	// for vectors
#include <string>	// for strings

using namespace std;


class Solution {
public:
	vector<string> fizzBuzz(int n) {
		/*
		 * Function creates a string vector with n elements where every:
		 *		integer divisible by 3 is replaced with "Fizz"
		 *		integer divisible by 5 is replaced with "Buzz"
		 *		integer divisible by both 3 & 5 is replaced with "FizzBuzz"
		 *		integer not divisible by 3 or 5 is just the integer itself
		 *
		 * type	n 	: integer
		 * rtype	: vector<string>
		*/

		// Create a vector storage
		vector<string> fbVector;

		for(int i = 1; i <= n; i++) {
			// Check if the integer is divisible by both 3 & 5
			if (i % 15 == 0) {
				fbVector.push_back("FizzBuzz");
				continue;
			}
			else if (i % 3 == 0) {
				fbVector.push_back("Fizz");
				continue;
			}
			else if (i % 5 == 0) {
				fbVector.push_back("Buzz");
				continue;
			}
			else {
				fbVector.push_back(to_string(i));
				continue;
			}
		}

		return fbVector;
	}
};


int main() {

	// Intro message
	cout << "\n-----	FIZZ BUZZ 	-----\n";
	// Create a Solution object
	Solution *sol = new Solution();

	// Tell user to input integer
	cout << "Enter an integer: ";

	// Save the user input
	int usrInput;
	cin >> usrInput;

	// get the result
	vector<string> result = sol->fizzBuzz(usrInput);

	// print out the solution
	cout << "\nResult: ";

	for(int i = 0; i < result.size(); i++) {
		cout << result.at(i) << " ";
	}
	cout << endl;

	return 0;
}