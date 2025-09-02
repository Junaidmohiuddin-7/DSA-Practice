// You are given an integer array nums consisting of n elements, and an integer k.

// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 

// Example 1:

// Input: nums = [1,12,-5,-6,50,3], k = 4
// Output: 12.75000
// Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
// Example 2:

// Input: nums = [5], k = 1
// Output: 5.00000


//this is brute force which doesnt pass the LC all conditions because its
//TC is very very high
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int j=0;
        int maxi=INT_MIN;
        while(j+k<=nums.size()){
        int  sum=0;
        for(int i=j;i<k+j && j<nums.size();i++){
            sum=sum+nums[i];
        }
        maxi=max(maxi,sum);
        j++;
        
        }
double ma = (double)maxi / k;
        
        return ma;
    }
};


//optimized solution TC-O(n) and SC-O(1)

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0;
        int j=k-1;
        int sum=0;
        int maxi=INT_MIN;
        for(int y=0;y<k;y++){
            sum=sum+nums[y];
        }
        maxi=max(sum,maxi);
        j++;
        while(j<nums.size()){
            sum=sum-nums[i++];
        
            sum=sum+nums[j++];
           maxi=max(sum,maxi);

        }
        double ma=(double)maxi/k;
        return ma;
        
        
    }
};