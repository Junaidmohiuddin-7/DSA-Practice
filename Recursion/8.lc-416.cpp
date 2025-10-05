class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int asum = 0;

        for (int i = 0; i < n; i++) {
            asum = asum + nums[i];
        }
        if (asum % 2 > 0) {
            return false;
        }
        int ans = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum = sum + nums[i];
                }
            }
            if (sum == asum / 2) {
                return true;
            }
        }

        return false;
    }
};




class Solution {
public:
bool part(vector<int>&nums,int i,int target){
   if(i>=nums.size()){
    return false;
   }
    if(target==0){
        return true;
    }
    return part(nums,i+1,target-nums[i])|| part(nums,i+1,target);


}

    bool canPartition(vector<int>& nums) {
      int i=0;
        int sum=0;
        for(auto i:nums){
sum=sum+i;
        }
        int target=sum/2;
        if(sum%2>0){
            return false;
        }
        return part(nums,i,target);
        
    }
};