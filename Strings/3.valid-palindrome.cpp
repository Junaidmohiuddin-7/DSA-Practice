
// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

 

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:

// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
// Example 3:

// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.
//here TC-(O(n)) and SC-O(n) tpp because of the ans
class Solution {
public:
    bool isPalindrome(string s) {
    string ans="";
        for(int i=0;i<s.length();i++){
            if((s[i]>='A'&&s[i]<='Z')){
                ans.push_back(s[i]-'A'+'a');
            }
            else if((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')){
                ans.push_back(s[i]);
            }
        }
        int i=0;
        int j=ans.length()-1;
        while(i<=j){
if(ans[i]==ans[j]){
    i++;
    j--;
}
else{
    return false;
}
        }
        return true;
    }
};

//optimized version where SC-O(1) by 2 pointers approach and
//some strings inbuilt functions which helps solving this problem easily
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        while (i <= j) {
            if (!(isalnum(s[i]))) {
                i++;
            } else if (!(isalnum(s[j]))) {
                j--;
            }

            else if (tolower(s[i]) != tolower(s[j])) {
                return false;
            } else {
                i++;
                j--;
            }
        }
        return true;
    }
};
//(isalnum(s[i])) it will check if the index is alpha or numeric
// if it is it will return true otherwise false;