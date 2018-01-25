#include <iostream> 	// for cout, cin, etc
#include <vector>		// for vectors
#include <algorithm>

using namespace std;

class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		/*
		 * Find the max sum of the mins of each pair 
		 *
		 * type	nums	:	vector<int>
		 * rtype 		:	int
		*/

		// A variable to hold the sum
		int sum = 0;

		// Sort the vector
		sort(nums.begin(), nums.end());

		// create an integer to keep track of the index
		int i = 0;

		// loop through the vectors and only add the even index to the overall sum
		while(i < nums.size()) {
			// add the value to the sum
			sum += nums[i];

			// add 2 to the index to make sure only the even values are reached
			i += 2;
		}

		return sum;
	}
}; 

int main() {
	// Create a instance of Solution class
	Solution *sol = new Solution();

	// Create a sample array to test, all arrays will have 2n integers
	vector<int> test = {1, 4, 3, 2};

	// Get the max sum of the min of pairs
	int ans = sol->arrayPairSum(test);

	// print the answer
	cout << "Max Sum: " << ans << endl;

	return 0;
}