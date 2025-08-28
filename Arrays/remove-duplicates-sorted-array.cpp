
//this is a LC-26 question done with 2 pointers approach
//used i for only swapping and j for checking the whole array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=1;
        int k=1;
        while(j<nums.size()){
            if(nums[i]==nums[j]){
                j++;
            }
            else if(nums[i]!=nums[j]){
                i++;
                swap(nums[i],nums[j]);
                j++;
                k++;
            }
        }
        return k;

    }
};
//Time Complexity: O(n) 
//and Space complexity: O(1);