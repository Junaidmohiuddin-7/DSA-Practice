// You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.

// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:

// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.

 

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:

// Input: nums = [2,3,0,1,4]
// Output: 2


class Solution {
public:
    int check(vector<int>& nums, int i) {
        if (i == nums.size() - 1) {
            return 0;
        }
        if (i > nums.size() - 1) {
            return INT_MAX;
        }

        int mini = INT_MAX;
        for (int j = 1; j <= nums[i]; j++) {
            int recans = check(nums, i + j);
            if (recans != INT_MAX) {
                int minjump = 1 + recans;
                mini = min(mini, minjump);
            }
        }
        return mini;
    }

    int jump(vector<int>& nums) { return check(nums, 0); }
};