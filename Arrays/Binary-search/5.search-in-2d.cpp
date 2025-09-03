// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows=matrix.size();
    int cols=matrix[0].size();
    int totalelements=(rows*cols);
    int s=0;
    int e=totalelements-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        //find rowindex and colindex by using the mid value
int row=mid/cols;
int col=mid%cols;
if(matrix[row][col]==target){
    return true;
}
else if(matrix[row][col]<target){
    s=mid+1;
}
else{
e=mid-1;
}

mid=s+(e-s)/2;

    }
    return false;

        
    }
};
