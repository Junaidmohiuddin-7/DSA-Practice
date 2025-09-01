// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.

// A substring is a contiguous sequence of characters in a string.

 

// Example 1:

// Input: s = "daabcbaabcbc", part = "abc"
// Output: "dab"
// Explanation: The following operations are done:
// - s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
// - s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
// - s = "dababc", remove "abc" starting at index 3, so s = "dab".
// Now s has no occurrences of "abc".
this is a 

class Solution {
public:
    string removeOccurrences(string s, string part) {
int n=part.length();
        while(s.find(part)!=string::npos){
            s.erase(s.find(part),n);

        }
        
        return s;
    }
};//TC-O(n²) and SC-O(1)


//optimized version where TC-O(n) and SC-O(n)

class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans="";
        int n=part.length();
    
    for (auto ch:s){
        ans.push_back(ch);
        if(ans.size()>=n && (ans.substr(ans.size()-n)==part)){
            ans.erase(ans.size()-n,ans.size());
        }
    }
    return ans;
    }
};

// Think:
// 👉 Stack behavior (push characters, pop when pattern matches).

// Here string ans works as a stack.

//more optimized solution where space complexity O(1)
//j as pointer like last solution
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = part.size();
        int j = 0; // write pointer

        for (int i = 0; i < s.size(); i++) {
            s[j++] = s[i]; // copy current char forward

            // check if last n chars match "part"
            if (j >= n && s.substr(j - n, n) == part) {
                j -= n; // remove them (like popping from stack)
            }
        }

        return s.substr(0, j); // final valid string
    }
};
