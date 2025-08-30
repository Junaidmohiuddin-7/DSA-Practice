
//this is just a brute force solution Time Complexity: O(nlogn) sort function takes O(nlogn)
//                                    Space Complexity: O(log n)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=i){
                    return i;
                }
            }
                    return nums.size();

        }
};
//optimized approach (XOR) method
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //taking xor of the nums first
        int ans=0;
        for(int i=0;i<nums.size();i++){
ans=ans^nums[i];
        }
        
        for(int i=0;i<=nums.size();i++){
            ans=ans^i;
        }
        return ans;
        
    }
};
Time Complexity: O(n)
Space Complexity: O(1)
//Another O(n)TC method which is a swapping method
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n){
            int correctindex=nums[i];
            if(correctindex<n&&nums[i]!=nums[correctindex]){
                swap(nums[i],nums[correctindex]);
            }
            else{
                i++;
            }

        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                return i;
            }

        }
        return n;
    }
};
//what we are doing here is we are just swapping the element of array to its matching  index(matching the index and the element)



