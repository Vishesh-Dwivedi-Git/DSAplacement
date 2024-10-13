#include <iostream>
#include <vector>
using namespace std;

//recursion
int climb(int n){
    if(n==0 || n==1) return 1;
    return climb(n-1)+climb(n-2);
}

//memoization DP
int climbDp(int n,vector<int>&f){
    if(n==0 || n==1) return 1;
    else if(f[n]!=-1) return f[n];
    else {
        f[n]=climbDp(n-1,f)+ climbDp(n-2,f);
        return f[n];
    }
}

//Tabulation Dp
int climbTab(int n){
    vector<int>f(n+1);
    f[0]=1;
    f[1]=1;
    for(int i=2;i<=n;i++){
        f[i]=f[i-1]+f[i-2];
    }
    return f[n];
}

//3 at a time memoization DP
int climbDp(int n,vector<int>&f){
    if(n==0 || n==1) return 1;
    else if(n==2) return 2;
    else if(f[n]!=-1) return f[n];
    else {
        f[n]=climbDp(n-1,f)+ climbDp(n-2,f)+ climbDp(n-3,f);
        return f[n];
    }
}
int main(){
    int n;
    vector<int>f(n+1,-1);
    int ans=climbDp(n,f);
    cout<<ans<<endl;
    return 0;
}