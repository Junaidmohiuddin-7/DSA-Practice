class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>maps;
        for(int i=0;i<nums.size();i++){
            int need=target-nums[i];
            if(maps.find(need)!=maps.end()){
return {maps[need],i};
            }
            maps[nums[i]]=i;
        }
        return {};
    }
};