/*
Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - ­1) ,
2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  
Write brute-force recursive solution for this.
Input format :
The first and the only line of input contains an integer value, 'n'.
Output format :
Print the minimum number of steps.
Constraints :
1 <= n <= 200

Time Limit: 1 sec
Sample Input 1 :
4
Sample Output 1 :
2 
Explanation of Sample Output 1 :
For n = 4
Step 1 :  n = 4 / 2  = 2
Step 2 : n = 2 / 2  =  1 
Sample Input 2 :
7
Sample Output 2 :
3
Explanation of Sample Output 2 :
For n = 7
Step 1 :  n = 7 ­- 1 = 6
Step 2 : n = 6  / 3 = 2 
Step 3 : n = 2 / 2 = 1  
*/
#include<iostream>
using namespace std;
#include <bits/stdc++.h>

int minSteps1(int n)
{
    //base case
    if(n<=1)
    return 0;

    //recursive call
    int x=minSteps1(n-1);

    int y=INT_MAX,z=INT_MAX;
    if(n%2==0)
    y=minSteps1(n/2);

    if(n%3==0)
    z=minSteps1(n/3);

    int ans=min(x,min(y,z))+1;

    return ans;
}


//Optimised Code: Using Memoization 
int minStepsHelper(int n,int * ans)
{
    //base case
    if(n<=1)
    return 0;

    //check if ans already exists
    if(ans[n]!=-1)
    return ans[n];

    //calcuate ans
    int x=minStepsHelper(n-1,ans);

    int y=INT_MAX,z=INT_MAX;
    if(n%2==0)
    y=minStepsHelper(n/2,ans);

    if(n%3==0)
    z=minStepsHelper(n/3,ans);

    int output=min(x,min(y,z))+1;

    //save output for future use
    ans[n]=output;

    return output;
}

int minSteps2(int n)
{
    int *ans=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        ans[i]=-1;
    }

    return minStepsHelper(n,ans);
}

//minSteps1: brute force approach :O(2^n or 3^n) 
//minSteps2: memoization approach :O(n)
int main()
{
    int n;
    cin>>n; //7
    // cout<<minSteps1(n)<<endl; //3
    cout<<minSteps2(n)<<endl; //3
}

