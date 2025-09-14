class Solution {
public:
    int robber(vector<int>& nums, int i) {
        if (i >= nums.size()) {
            return 0;
        }
        int currans = nums[i] + robber(nums, i + 2);
        int altans = 0 + robber(nums, i + 1);
        return max(currans, altans);
    }
    int rob(vector<int>& nums) {
        int index = 0;
        return robber(nums, index);
    }
};