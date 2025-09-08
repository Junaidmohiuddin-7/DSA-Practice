
//finding the single element in a sorted array of pairs
// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space.

 

// Example 1:

// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2
// Example 2:

// Input: nums = [3,3,7,7,10,11,11]
// Output: 10


class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int s = 0;
        int e = nums.size() - 1;
        int mid = s + (e - s) / 2;
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }
        if (nums[0] != nums[1])
        {
            return nums[0];
        }
        if (nums[n - 1] != nums[n - 2])
        {
            return nums[n - 1];
        }
        while (s <= e)
        {
            if (mid - 1 >= 0 && nums[mid] != nums[mid - 1] && mid + 1 < nums.size() && nums[mid] != nums[mid + 1])
            {
                int ans = nums[mid];
                return ans;
            }
            else if (mid - 1 >= 0 && nums[mid] == nums[mid - 1])
            {
                int indexp = mid - 1;
                if (indexp & 1)
                {
                    e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }
            else if (mid + 1 < nums.size() && nums[mid] == nums[mid + 1])
            {
                int indexp = mid;
                if (indexp & 1)
                {
                    e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }
            mid = s + (e - s) / 2;
        }
        return -1;
    }
};
//BOTH ARE SAME JUST HANDLED THE EDGE CASES DIFFERENTLY

class Solution
{
public:
    int singleNonDuplicate(vector<int> &arr)
    {
        int s = 0;
        int e = arr.size() - 1;
        int mid = s + (e - s) / 2;
        int n = arr.size();
        while (s <= e)
        {

            if (s == e)
            {
                return arr[s];
            }
            int currval = arr[mid];
            int leftval = -1;
            if (mid - 1 >= 0)
            {
                leftval = arr[mid - 1];
            }

            int rightval = -1;
            if (mid + 1 < n)
            {
                rightval = arr[mid + 1];
            }
            if (currval != leftval && currval != rightval)
            {
                return currval;
            }
            if (currval == rightval && currval != leftval)
            {
                int answerindex = mid & 1;
                if (answerindex)
                {
                    e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }
            else if (currval == leftval && currval != rightval)
            {
                int answerindex = (mid - 1) & 1;
                if (answerindex)
                {
                    e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }

            mid = s + (e - s) / 2;
        }

        return -1;
    }
};