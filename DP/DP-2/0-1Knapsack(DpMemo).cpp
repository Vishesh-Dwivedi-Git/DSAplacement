#include <iostream>
#include <vector>

using namespace std;

int DpMemo(vector<int>val,vector<int>wt,int w, int n, vector<vector<int>> &dp){
    if(n==0 ||w==0) return 0;
    int itemVal=val[n];
    int itemwt=wt[n];
    if(itemwt<=w){
    
        if(dp[n][w]!=-1) return dp[n][w];

          //include 
        int ans1=DpMemo(val,wt,w-itemwt,n-1,dp)+itemVal;

        //exclude
        int ans2=DpMemo(val,wt,w,n-1,dp);
        //store
        dp[n][w]=max(ans1,ans2);
    }
    else{
        dp[n][w]=DpMemo(val,wt,w,n-1,dp);
    }
    return dp[n][w];
}

int main(){
    vector<int> val={15,14,10,45,30};
    vector<int> wt={2,5,1,3,4};

    int w=7;
    int n=5;

    vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
    cout<<DpMemo(val,wt,w,n,dp)<<endl;
    return 0;
}