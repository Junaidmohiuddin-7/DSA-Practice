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




class Solution {
public:
    int calc(vector<int>& nums, int i) {

        if (i >= nums.size()) {
            return 0;
        }

        int rob = nums[i] + calc(nums, i + 2);
        int skip = 0 + calc(nums, i + 1);
        int anss = max(rob, skip);
        return anss;
    }

    int rob(vector<int>& nums) {
        int i = 0;
        int ans = calc(nums, i);
        return ans;
    }
};