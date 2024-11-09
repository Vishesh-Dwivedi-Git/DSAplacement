#include <iostream>
#include <vector>
using namespace std;

//given coins and amt find the no. of the combinations of it 
int coinChange(vector<vector<int>> dp , int amt , vector<int> coins , int n){
    //tabulation
    //initialize the 1st col
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<amt+1;j++){
            //condn
            if(coins[i-1]<=j){
                //include exclude 
                dp[i][j]=dp[i][j-coins[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[n][amt];
}

int main(){
    vector<int> coins={1,2,5};
    int n=coins.size();
    int amt=5;
    vector<vector<int>> dp(n+1,vector<int> (amt+1,0));
    int ans=coinChange(dp,amt,coins,n);
    return 0;
}