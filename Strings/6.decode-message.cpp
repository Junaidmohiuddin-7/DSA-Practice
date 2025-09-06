// Input: key = "the quick brown fox jumps over the lazy dog", message = "vkbs bs t suepuv"
// Output: "this is a secret"
// Explanation: The diagram above shows the substitution table.
// It is obtained by taking the first appearance of each letter in "the quick brown fox jumps over the lazy dog".

class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char>map;
        char current='a';
        char spacech=' ';
        map[' ']=' ';
        for(int i=0;i<key.length();i++){
        if(map.find(key[i])==map.end()){
            map[key[i]]=current;
            current++;
        }
        }
        string ans="";
        for(int i=0;i<message.length();i++){
ans.push_back(map[message[i]]);
        }
        return ans;
    }
};