#include <iostream>
#include <vector>

using namespace std;

int fib(int n){
    if(n==0 || n==1){
        return n;
    }
    return fib(n-1) + fib(n-2);
}

int fibDp(int n, vector<int>&f){  //Memoization
     if(n==0 || n==1) return n;    //T.c 0(n) sc-O(n)
     else if(f[n]!=-1) return f[n];
     else{
        f[n]=fibDp(n-1,f)+fibDp(n-2,f);
        return f[n];
     }

}

int fibTab(int n){   //Tabulation
    vector<int>f(n+1); //f(i)-->ith fab 
    f[0]=0;            //T.c 0(n) sc-O(n) can be more optimised 
    f[1]=1;
    for(int i=2;i<=n;i++){
        f[i]=f[i-2] + f[i-1];
    }
    return f[n];
}

int main(){
    int n=6;
    vector<int> f(n+1,-1);
    cout<< fibDp(n,f)<<endl;
    cout<<fibTab(n);
    return 0;
}