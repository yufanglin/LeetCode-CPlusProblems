/*
 * Island Perimeter
 * Yufang Lin
 * My solution to the leetCode problem, "Island Perimeter": 
 * https://leetcode.com/problems/island-perimeter/description/
*/

#include <iostream> 	// for cout 
#include <vector>		// for vectors

using namespace std;

class Solution {
public: 
	int islandPerimeter(vector<vector<int>>& grid) {
		/* 
		 * The grid is made out of 0's and 1's.
		 * Each 0 is a water cell, while each 1 is a land cell.
		 * Each cell has four sides of length 1.
		 * This method determines the perimeter of connecting land cell.
		 * type	grid	: vector<vector<int>>
		 * rtype		: int
		 *
		*/

		// create a storage for the perimeter
		int perimeter = 0;

		// loop through the rows in the grid
		for (int row = 0; row < grid.size(); row++) {
			// loop through the columns (which is each element in the row)
			for (int col = 0; col < grid.front().size(); col++) {
				// check if the cell is water or land
				if (grid[row][col] == 0) {
					// continue on to the next cell
					continue;
				}

				// Check if the land cell's top is connected to water or out of bounds
				if (row - 1 == -1 || grid[row-1][col] == 0) {
					// increment perimeter
					perimeter++;
				}
				// Check if the land cell's right is connected to water or out of bounds
				if (col + 1 == grid.front().size() || grid[row][col + 1] == 0) {
					// increment perimeter
					perimeter++;
				}
				// Check if the land cell's bottom is connected to water or out of bounds
				if (row + 1 == grid.size() || grid[row + 1][col] == 0) {
					// increment perimeter
					perimeter++;
				}
				// Check if the land cell's left is connected to water or out of bounds
				if (col - 1 == -1 || grid[row][col - 1] == 0) {
					// increment perimeter
					perimeter++;
				}
			}
		}

		return perimeter;
	}
};

int main() {
	// Create an instance of the solution class
	Solution *sol = new Solution();

	// Create an example to test the Solution class
	vector<vector<int>> grid;

	vector<int> firstRow, secondRow, thirdRow, fourthRow;

	// fill out the first row
	firstRow.push_back(0);
	firstRow.push_back(1);
	firstRow.push_back(0);
	firstRow.push_back(0);

	// fill out the second row
	secondRow.push_back(1);
	secondRow.push_back(1);
	secondRow.push_back(1);
	secondRow.push_back(0);

	// fill out the third row
	thirdRow.push_back(0);
	thirdRow.push_back(1);
	thirdRow.push_back(0);
	thirdRow.push_back(0);

	// fill out the fourth row
	fourthRow.push_back(1);
	fourthRow.push_back(1);
	fourthRow.push_back(0);
	fourthRow.push_back(0);

	// add rows to multi-dimensional grid 
	grid.push_back(firstRow);
	grid.push_back(secondRow);
	grid.push_back(thirdRow);
	grid.push_back(fourthRow);


	// example 2
	vector<vector<int>>grid2;
	
	vector<int> fRow;
	fRow.push_back(0);
	fRow.push_back(1);

	grid2.push_back(fRow);


	// test out the example
	int perimeter1 = sol->islandPerimeter(grid);
	int perimeter2 = sol->islandPerimeter(grid2);

	// print out results
	cout << "The Island Perimeter: " << perimeter1 << endl;
	cout << "The Island Perimeter: " << perimeter2 << endl;

	return 0;
}