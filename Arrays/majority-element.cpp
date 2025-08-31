// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

//This is an bruteforce approach using hashmap having TC-O(n) but SC-O(n)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>maps;
        int ans=-1;
        for(int i=0;i<nums.size();i++){
maps[nums[i]]++;
        }
        unordered_map<int,int>::iterator it;
        int maxfreq=0;
         int ans=-1;
        for(it=maps.begin();it!=maps.end();it++){
if(it->second>maxfreq){
    maxfreq=it->second;
    ans=it->first;
}
        }
        return ans;
        
    }
};

//optimized approach called Boyer–Moore Majority Vote Algorithm
//algorithm guarantees majority element is more than n/2 times so
//we will find out the majority element for sure if it occus more than n/2
//TC-O(n) and SC-O(1).
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate=nums[0];
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                candidate=nums[i];
            }
            if(candidate==nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        return candidate;
        
    }
};
// "I use Boyer–Moore Majority Vote Algorithm. The intuition is that we keep a running candidate and a count. 
// Every time we see the candidate, we increment the count; otherwise, we decrement it. 
// When the count hits zero, we pick a new candidate.
//  Because the majority element appears more than n/2 times,
// it can never be fully cancelled out, so it will always be the final candidate."
