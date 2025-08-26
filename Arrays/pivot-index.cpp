Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      
        for(int i=0;i<nums.size();i++){
int lsum=0;
int rsum=0;
for(int j=0;j<i;j++){
    lsum=nums[j]+lsum;
}
for(int j=i+1;j<nums.size();j++){
    rsum=rsum+nums[j];
}
if(lsum==rsum){
    return i;
}


        }
        return -1;
    }
};
Time Complexity: O(n²)
Space Complexity: O(1)
//now optimised approach where Time Complexity: O(n)
// but space Complexity: O(n)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int l=0;
        int r=0;
        vector<int>lsum;
        vector<int>rsum;
        for(int i=0;i<nums.size();i++){
            l=l+nums[i];
lsum.push_back(l);
        }
         for(int i=nums.size()-1;i>=0;i--){
            r=r+nums[i];
            rsum.push_back(r);
        }
        reverse(rsum.begin(),rsum.end());
         for(int i=0;i<nums.size();i++){
 if(lsum[i]==rsum[i]){
    return i;
 }
        }
        return -1;
    }
};
//if you want more optimization like space complexity should be O(1) then this 
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        for (int x : nums) totalSum += x; // total sum of array
        
        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int rightSum = totalSum - leftSum - nums[i];
            if (leftSum == rightSum) return i;
            leftSum += nums[i];
        }
        
        return -1;
    }
};
//main intuition behind the right sum formula is
// Great question! 😊 This is where intuition matters, not rote memorization. Let's break it down very clearly and slowly so you can **understand why**
// `rightSum = totalSum - leftSum - nums[i]` makes sense.

// ---

// ### **Goal of Pivot Index Problem**

// We want an index `i` such that:

// ```
// sum of elements on left side of i == sum of elements on right side of i
// ```

// Let's call:

// * `leftSum` = sum of elements before index `i`
// * `rightSum` = sum of elements after index `i`
// * `totalSum` = sum of all elements in the array

// So at any index:

// ```
// totalSum = leftSum + nums[i] + rightSum
// ```

// Because the total sum is everything: left side, current element, and right side.

// Now, rearrange this equation to isolate `rightSum`:

// ```
// rightSum = totalSum - leftSum - nums[i]
// ```

// That's it!
// This formula comes directly from basic math and understanding what totalSum means.

// ---

// ### **How to Build the Intuition Step by Step**

// 1. **First observation:**
//    The sum on the right is basically "everything except left and current element".

// 2. **We already know total sum of the array (easy to compute once):**

//    ```
//    totalSum = sum(nums)
//    ```

// 3. **We know leftSum dynamically as we iterate:**

//    * Initially `leftSum = 0` (nothing before index 0).
//    * After checking index `i`, we add nums\[i] to leftSum before moving forward.

// 4. **Thus, instead of recomputing rightSum with another loop,**
//    we just compute it directly using:

//    ```
//    rightSum = totalSum - leftSum - nums[i]
//    ```

// 5. **Check condition:**

//    ```
//    if leftSum == rightSum, pivot found.
//    ```

// ---

// ### **Why is this smarter?**

// * Normally, you might think of summing right side with another loop (O(n²) brute force).
// * But notice that **total sum is constant**, so if you already know leftSum, the rightSum is just "the rest".

// This trick avoids recomputation and makes the code O(n).

// ---

// ### **How can you discover such formulas in future?**

// When you need:

// * **Sum of left part + sum of right part = total sum**,
//   always consider:

// ```
// right = total - left - current
// ```

// This works for prefix-suffix problems, which appear often.

// ---



