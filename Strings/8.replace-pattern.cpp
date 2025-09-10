// Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.

// A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

// Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

// Example 1:

// Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
// Output: ["mee","aqq"]
// Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}.
// "ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.
// Example 2:

// Input: words = ["a","b","c"], pattern = "a"
// Output: ["a","b","c"]
class Solution
{
public:
    string normalise(string word)
    {
        unordered_map<char, char> map;
        string ans = "";
        char ch = 'a';
        for (int i = 0; i < word.length(); i++)
        {
            if (map.find(word[i]) == map.end())
            {
                map[word[i]] = ch;
                ch++;
            }
            ans = ans + map[word[i]];
        }
        return ans;
    }
    vector<string> normalising(vector<string> &words, string pattern)
    {
        vector<string> ans;
        string normalisedword = normalise(pattern);
        for (int i = 0; i < words.size(); i++)
        {
            if (normalise(words[i]) == normalisedword)
            {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }

    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> ans = normalising(words, pattern);
        return ans;
    }
};