/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void subarr(int arr[],int size,int start,int end){
    
    if(end==size){
        return ;
        
    }
    for(int i=start;i<=end;i++ ){
        cout<<arr[i];
    }
    cout<<endl;
   
    subarr(arr,size,start,end+1);
}
void starts(int arr[],int size){
    
       for( int start=0;start<size;start++){
            int end=start;
            subarr(arr,size,start,end);
            
        }
}
int main()
{
int arr[]={1,2,3,4,5};
int size=5;
int i=0;
int j=0;
starts(arr,size);



    return 0;
}