// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:

// Input: nums = [1], target = 0
// Output: -1
class Solution {
public:
    int pivotsearch(vector<int>& nums) {
        int s = 0;
        int n = nums.size();
        int e = nums.size() - 1;
        int mid = s + (e - s) / 2;
        while (s <= e) {
            if(s==e){
                return s;
            }
            if (mid + 1 < n && nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (mid - 1 >= 0 && nums[mid] < nums[s]) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }

            mid = s + (e - s) / 2;
        }
        return -1;
    }
    int check(vector<int>& nums, int s,int e,int target) {
       
        int mid = s + (e - s) / 2;
        while (s <= e) {
            if (nums[mid]==target) {
                return mid;
            } 
            else if (nums[mid]<target) {
                s=mid+1;
            } 
            else {
                e = mid -1;
            }

            mid = s + (e - s) / 2;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = pivotsearch(nums);
        if (target >= nums[0] && target <= nums[ans]) {
            int ans1 = check(nums,0,ans, target);
            return ans1;
        }
        else if(ans+1<n&&target>=nums[ans+1]&&target<=nums[n-1]){
            int ans2=check(nums,ans+1,n-1,target);
            return ans2;




        }
        return -1;
    }
};