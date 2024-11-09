#include <iostream>
#include <vector>
using namespace std;

//example of unbounded knapsack 
int rodCutting(vector<vector<int>>dp, vector<int> price , vector<int> length, int n, int rodlen){
    //using tabulation

    for(int i=1;i<n+1;i++){
        for(int j=1;j<rodlen+1;j++){
            if(length[i-1]<=j){
                dp[i][j]=max(price[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[n][rodlen];
}

int main(){
    vector<int> price={1,5,8,9,10,17,17,20};
    vector<int> length={1,2,3,4,5,6,7,8};
    int rodLength=8;
    int n=length.size();
    //initialization
    vector<vector<int>> dp(n+1,vector<int> (rodLength+1,0));
    int ans=rodCutting(dp,price,length,n,rodLength);
    cout<<"Rod cutting max profit is "<<ans;
    return 0;
}