class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i=0;
        int j=s.length()-1;
        
        while(i<=j){
if(!(s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
i++;
        }
        else if(!(s[j]>='a'&&s[j]<='z')||(s[j]>='A'&&s[j]<='Z')){
        j--;
    }
    else{
        swap(s[i],s[j]);
        i++;
        j--;
    }
    }
    return s;
}
};


class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<=j){
if(!(isalpha(s[i]))){
    i++;
}
else if(!(isalpha(s[j]))){
    j--;
}
else {
    swap(s[i],s[j]);
    i++;
    j--;

}





        }
        return s;
        
    }
};