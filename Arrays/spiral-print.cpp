
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rowsize = matrix.size();
        int colsize = matrix[0].size();
        int totalcount = (rowsize * colsize);
        int rowstart = 0;
        int rowend = rowsize - 1;
        int colstart = 0;
        int colend = colsize - 1;
        int count = 0;
        while (count < totalcount) {
            for (int i = colstart; i <= colend && count < totalcount; i++) {
                ans.push_back(matrix[rowstart][i]);
                count++;
            }
            rowstart++;

            for (int i = rowstart; i <= rowend && count < totalcount; i++) {
                ans.push_back(matrix[i][colend]);
                count++;
            }
            colend--;
            for (int i = colend; i >= colstart && count < totalcount; i--) {
                ans.push_back(matrix[rowend][i]);
                count++;
            }
            rowend--;
            for (int i = rowend; i >= rowstart && count < totalcount; i--) {
                ans.push_back(matrix[i][colstart]);
                count++;
            }
            colstart++;
        }

        return ans;
    }
};