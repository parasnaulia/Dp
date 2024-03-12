#include<iostream>
#include<vector>
using namespace std;
int fiboo(int n,vector<int> &dp)
{
      if(n<=1)
      {
            return n;
      }
      if(dp[n]!=-1)
      {
            return dp[n];
      }
      return dp[n]=fiboo(n-1,dp)+fiboo(n-2,dp);
}
int main()
{
      int n;
      cout<<"Enter The Value of n"<<endl;
      cin>>n;
      vector<int> dp(n+1,-1);
      int ans=fiboo(n,dp);
      cout<<"The Fiboo is "<<ans<<endl;
      return 0;

}
