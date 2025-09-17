class Solution {
public:
void addstr(string &num1,int i,string &num2,int j,string &ans,int &carry){

    if(i<0&&j<0){
        if (carry > 0) {
        ans.push_back(carry + '0');
    }
        return ;
    }
int n1=(i>=0) ? num1[i]-'0':0;
int n2=(j>=0) ? num2[j]-'0':0;
int sum=n1+n2+carry;
ans.push_back((sum%10)+'0');
carry=sum/10;
addstr(num1,i-1,num2,j-1,ans,carry);

    
}
    string addStrings(string num1, string num2) {
        int i=num1.size()-1;
        int j=num2.size()-1;
        int carry=0;
        string ans="";
        addstr(num1,i,num2,j,ans,carry);
        reverse(ans.begin(),ans.end());
        return ans;

    }
};