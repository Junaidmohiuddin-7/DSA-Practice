class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
       sort(t.begin(),t.end());
       if(s==t){
        return true;
       }
       return false;
        
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>map;
        for(int i=0;i<s.size();i++){
          map[s[i]]++;;
    }
    unordered_map<char,int>mapt;
        for(int i=0;i<t.size();i++){
          mapt[t[i]]++;;
    }
  if(map==mapt){
    return true;
  }
  
return false;
    }
};



class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[256]={0};
        for(int i=0;i<s.size();i++){
            arr[s[i]]++;
        }
        for(int j=0;j<t.size();j++){
            arr[t[j]]--;
        }
        for(int i=0;i<256;i++){
            if(arr[i]!=0){
                return false;
            }

        }
        return true;
        
    }
};