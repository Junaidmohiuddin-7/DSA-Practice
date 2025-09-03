// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and using only constant extra space.

 

// Example 1:

// Input: nums = [1,3,4,2,2]
// Output: 2
// Example 2:

// Input: nums = [3,1,3,4,2]
// Output: 3
// Example 3:

// Input: nums = [3,3,3,3,3]
// Output: 3
 
//brute force with very high complexity
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i<nums.size()-1&&nums[i]==nums[i+1]){
                ans=nums[i];
            }
        }
        return ans;
    }
};

//optimized version of TC-O(n) and SC-O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
int ans;
        for(int i=0;i<nums.size();i++){

            int index=abs(nums[i]);
            if(nums[index]<0){
                ans=index;
            }
            


            nums[index]=nums[index]*-1;
        }
        return ans;
        
    }
};