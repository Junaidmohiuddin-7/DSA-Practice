
// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

// Example 1:

// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
// Example 2:

// Input: triangle = [[-10]]
// Output: -10


class Solution {
public:
    check(vector<vector<int>>& triangle, int sum, int& ans, int i, int j) {
        if (i > triangle.size() - 1) {
            ans = min(ans, sum);
            return;
        }

        check(triangle, sum + triangle[i][j], ans, i + 1, j);
        check(triangle, sum + triangle[i][j], ans, i + 1, j + 1);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans = INT_MAX;
        int sum = 0;
        int i = 0;
        int j = 0;
        check(triangle, sum, ans, i, j);
        return ans;
    }
};