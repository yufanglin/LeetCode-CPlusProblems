#include <iostream>		// for cout, cin, etc
#include <string>		// for strings
#include <vector>		// for vectors
#include <fstream> 		// for file i/o input

using namespace std;	

int main() {

	vector <int> lotteryNumVect(10);

	int lotteryNumArray[5] = {4, 13, 14, 24, 34};

	// Insert the first three elements in the array
	lotteryNumVect.insert(lotteryNumVect.begin(), lotteryNumArray, lotteryNumArray+3);

	// Insert 44 to the fifth element in array
	lotteryNumVect.insert(lotteryNumVect.begin()+5, 44);

	cout << "Third lottery Number: " << lotteryNumVect.at(2) << endl;

	// add an element at the end of the vector
	lotteryNumVect.push_back(64);

	// Find final value
	cout << "Final lotery value: " << lotteryNumVect.back() << endl;

	// Remove final value
	lotteryNumVect.pop_back();

	// First value:
	cout << "First Value:  " << lotteryNumVect.front() << endl;

	// Check if vector is empty
	cout << "Is Vector empty? (false=0, true =1): " << lotteryNumVect.empty() << endl;

	// Get size of vector
	cout << "Size of vector: " << lotteryNumVect.size() << endl;
	return 0;
}