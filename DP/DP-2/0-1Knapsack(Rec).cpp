#include <iostream>
#include<vector>
using namespace std;
int knapsackRec(vector<int> val,vector<int> wt,int W,int n){
    if(n==0 || W==0) {
        return 0;
    }
    int itemwt=wt[n-1];
    int itemVal=val[n-1];

    if(itemwt<=W) {  //valid
       //include 
       int ans1=knapsackRec(val,wt,W-itemwt,n-1) +itemVal;

       //exclude
       int ans2=knapsackRec(val,wt,W,n-1);
       return max(ans1,ans2);
    }
    else{
        return knapsackRec(val,wt,W,n-1);
    }
}

int main(){
    vector<int> val={16,14,10,45,30};
    vector<int> wt={2,5,1,3,4};
    int W=7;
    int n=5;
    int ans=knapsackRec(val,wt,W,n);
    cout<<ans;
    return 0;
}