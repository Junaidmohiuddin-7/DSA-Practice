class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = stoi(num1);
        int n2 = stoi(num2);
        int ans = n1 + n2;
        string s = to_string(ans);
        return s;
    }
};




class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1;
        int j=num2.size()-1;
        int carry=0;
        string ans="";
        while(i>=0||j>=0||carry){

int n1=(i>=0) ? num1[i]-'0':0;
int n2=(j>=0) ? num2[j]-'0':0;
int sum=n1+n2+carry;
int digit=sum%10;
ans.push_back(digit+'0');
carry=sum/10;
i--;
j--;

        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};