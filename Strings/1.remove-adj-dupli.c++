// You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

// We repeatedly make duplicate removals on s until we no longer can.

// Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

 

// Example 1:

// Input: s = "abbaca"
// Output: "ca"
// Explanation: 
// For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
// Example 2:

// Input: s = "azxxzy"
// Output: "ay"
class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.length();
        string ans="";
        for(int i=0;i<n;i++){
            char curr=s[i];
            if(ans.empty()){
                ans.push_back(curr);
            }
            else if(curr!=ans.back()){
                ans.push_back(curr);

            }
            else if(curr==ans.back()){
                ans.pop_back();
            }
        }

        return ans;
    }
};
//TC-O(n) and SC-O(n)
// You should also mention that this is essentially a stack simulation, 
// and the string ans is working as the stack here. 
// That shows understanding of the approach.

//more optimized approach SC-O(1)
//here j acts as a pointer and helps in overwriting the original string
class Solution {
public:
    string removeDuplicates(string s) {
        int j=0;
        for(int i=0;i<s.length();i++){
            if(j>0&&s[i]==s[j-1]){
                j--;
            }
            else{
                s[j]=s[i];
                j++;
            }
        }
        return s.substr(0,j);
    }
};
// Why overwrite in the same string (s)?

// Instead of using an extra stack, we just reuse the input string s as a stack.

// We keep a pointer j → length of current valid result.

// When pushing, write at s[j] and move j++.

// When popping, just move j--.

// At the end, valid string is s.substr(0, j).

// Intuition in one line:

// 👉 “Keep building a stack of characters. Push if different, pop if same.”

// This works because duplicates must be adjacent. 
//If they’re not adjacent, they will only become adjacent after some cancellations, and the process naturally handles that.