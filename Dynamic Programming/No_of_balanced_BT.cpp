/*
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.
Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.
Constraints :
1 <= h <= 24
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315
*/
#include <iostream>
#include<cmath>
using namespace std;


//Brute Force -> O(2^h)
int balancedBTs(int h)
{
    if(h<=1)
    return 1;

    int mod=(int)(pow(10,9))+7;
    int x=balancedBTs(h-1);
    int y=balancedBTs(h-2);

    int temp1=(int)(((long)(x)*x)%mod);
    int temp2=(int)((2*(long)(x)*y)%mod);

    int ans = (temp1+temp2) % mod;
    return ans;   
     
}

//Using Memoisation -> O(h)
int balancedBTsHelper(int h,int *ans)
{
    if(h<=1)
    return 1;

    if(ans[h]!=-1)
    return ans[h];

    int mod=(int)(pow(10,9))+7;
    int a=balancedBTsHelper(h-1,ans);
    int b=balancedBTsHelper(h-2,ans);
    int temp1=(int)(((long)(a)*a)%mod);
    int temp2=(int)((2*(long)(a)*b)%mod);
    ans[h]=(temp1+temp2)%mod;

    return ans[h];
}

int balancedBTs1(int h)
{
    int * ans=new int[h+1];
    for(int i=0;i<=h;i++)
    {
        ans[i]=-1;
    }
    return balancedBTsHelper(h,ans);
}

//Using DP -> O(n)
int balancedBTs2(int h)
{
    int * ans=new int[h+1];
    ans[0]=1;
    ans[1]=1;
    int mod=(int)(pow(10,9))+7;
    for(int i=2;i<=h;i++)
    {
    int temp1=(int)(((long)(ans[i-1])*ans[i-1])%mod);
    int temp2=(int)((2*(long)(ans[i-1])*ans[i-2])%mod);
    ans[i]=(temp1+temp2)%mod;
    }
return ans[h];
}

int main()
{
    int h;
    cin>>h;//2
    // cout<<balancedBTs(h)<<endl;//3
    // cout<<balancedBTs1(h)<<endl;//3
    cout<<balancedBTs2(h)<<endl;//3
}