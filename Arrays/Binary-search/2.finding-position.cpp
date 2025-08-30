// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:

// Input: nums = [], target = 0
// Output: [-1,-1]



class Solution {
public:
int firstposition(vector<int>&arr,int target){
    int s=0;
    int e=arr.size()-1;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(arr[mid]==target){
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]>target){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
        
        
    }
    return ans;
}
    int secondposition(vector<int>&arr,int target){
    int s=0;
    int e=arr.size()-1;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(arr[mid]==target){
            ans=mid;
            s=mid+1;
        }
        else if(arr[mid]>target){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
        
        
    }
    return ans;
    }
    vector<int> searchRange(vector<int>& arr, int target) {
vector<int>ans;
int ans1=firstposition(arr,target);
ans.push_back(ans1);
int ans2=secondposition(arr,target);
ans.push_back(ans2);
return ans;

        
    }
};
// Time Complexity: O(log n) → because binary search is used.

// Space Complexity: O(1) → no extra memory except a few variables.