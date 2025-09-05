// Given a string s, return the number of palindromic substrings in it.

// A string is a palindrome when it reads the same backward as forward.

// A substring is a contiguous sequence of characters within the string.

 

// Example 1:

// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
// Example 2:

// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
//brute force
class Solution {
public:
    bool ispalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                if (ispalindrome(s, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};
//this is a optimised version called as expand around center
class Solution {
public:
    int ispalindrome(string s, int i, int j) {
        int count=0;
        while (i >= 0 && j < s.length()&& s[i] == s[j]) {
            
            count++;
            i--;
            j++;
        }
        return count;
    }

    int countSubstrings(string s) {
         int totalpalindromes=0;
        for (int center = 0; center < s.length(); center++) {
            int i = center;
            int j = center;
            //odd means odd substring
            int odd = ispalindrome(s, i, j);
            i = center;
            j = center + 1;
            int even = ispalindrome(s, i, j);
             totalpalindromes=totalpalindromes+even+odd;
        }
        return totalpalindromes;
    }
};