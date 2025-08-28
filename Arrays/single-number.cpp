//this solution is not preferable because its Time Complexity: O(n) but
//Space Complexity: O(n) because of extra memory for the hashmap. i just did it because to build
// the intuition of how hashmap and iterator works 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>maps;
        for(int i=0;i<nums.size();i++){
            maps[nums[i]]++;
        }
        unordered_map<int,int>::iterator it;
        for(it=maps.begin();it!=maps.end();it++){
            if(it->second==1){
                return it->first;

            }
        }
        return -1;
    }
};
//this is an optimized version Time Complexity: O(n) 
//and Space complexity: O(1);

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=ans^nums[i];
        }
        return ans;
    }
};