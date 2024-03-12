#include<iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int fiboo(int n)
{
      if(n<=1)
      {
            return n;
      }
      return fiboo(n-1)+fiboo(n-2);
}
int main()
{
      int n;
      cout<<"Enter the value of n"<<endl;
      cin>>n;
      int ans=fiboo(n);
      cout<<"The fiboo is"<<ans<<endl;
      return 0;

}

