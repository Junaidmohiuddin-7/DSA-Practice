//dutch national flag algorithm it is a 3 pointer approach takes Time complexity:O(n)
//SC:O(1)
// here the first pointer which is i is for only if we get '0' 
//pointer m is for scanning thoughout the array and helps in swapping with i and j
// we swap j if only  we get 2 and decrement it 

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int m=0;
        while(m<=j){
            if(nums[m]==0){
                swap(nums[i],nums[m]);
                i++;
                m++;
            }
            else if(nums[m]==1){
                m++;
            }
            else if(nums[m]==2){
                swap(nums[m],nums[j]);
                j--;
            }
        }
        return ;
    }
};
