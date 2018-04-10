/*
 * Distribute Candies
 * Yufang Lin
 *
 * My Solution to leetCode problem called, "Distribute Candies":
 * https://leetcode.com/problems/distribute-candies/description/
*/

#include <iostream>			// for cout/cin 
#include <vector>			// for vectors
#include <unordered_set>	// for sets (unordered)
#include <algorithm>		// for min

using namespace std;


class Solution {
public:
	int distributeCandies(vector<int>& candies) {
		/*
         * Returns the max number of different kinds of 
         * candies the sister of a brother-sister duo can gain
         * 
         * type candies 	: vector<int>
         * rtype	   		: int
        */

		// create an unordered set so each element will be unique
		unordered_set<int> uniqueCandies;

		// add all the items from candies into the set, which will leave only unique ones
		uniqueCandies.insert(candies.begin(), candies.end());

		// the min of unique cadies size and half of candies will be the max we are looking for
		return min(uniqueCandies.size(), candies.size()/2);
	}
};


int main() {
	// create an instance of the solution class
	Solution *sol = new Solution();

	// Create examples to test solution
	vector<int> candies1, candies2;

	// fill out the first example 
	candies1.push_back(1);
	candies1.push_back(1);
	candies1.push_back(2);
	candies1.push_back(2);
	candies1.push_back(3);
	candies1.push_back(3);


	// fill out the second example
	candies2.push_back(1);
	candies2.push_back(1);
	candies2.push_back(2);
	candies2.push_back(3);


	// find the max number of different candies the sister can get
	int maxTypeForSister1 = sol->distributeCandies(candies1);
	int maxTypeForSister2 = sol->distributeCandies(candies2);

	// print out results
	cout << "Example 1 Results: " << maxTypeForSister1 << endl;
	cout << "Example 2 Results: " << maxTypeForSister2 << endl;

	return 0;
}