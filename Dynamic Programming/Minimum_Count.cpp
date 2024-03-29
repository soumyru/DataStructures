/*
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
Input format :
The first and the only line of input contains an integer value, 'N'.
 Output format :
Print the minimum count of numbers required.
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
12
Sample Output 1 :
3
Explanation of Sample Output 1 :
12 can be represented as : 
A) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)

B) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)  + (2 ^ 2)

C) (1^2) + (1^2) + (1^2) + (1^2) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1*/

#include<bits/stdc++.h>
using namespace std;

//dynamic programming
int minCount ( int n)
{
    if ( sqrt (n) -floor(sqrt(n))==0)  return 1;
    
      int arr[n+1];
    arr[0]=0;
    arr[1]=1;
    arr[2]=2;
    arr[3]=3;
    
    for(int i=4 ;i<=n ;i++)
    {
      	  
        arr[i] = i; 
  
        for (int x = 1; x <= ceil(sqrt(i)); x++) { 
            int temp = x * x; 
            if (temp > i) 
                break; 
            else
                arr[i] = min(arr[i], 1 + arr[i - temp]); 
           }
    }
    return arr[n];
    
}


//memoization
/*
int mincount ( int n , int *arr)
{

    if( sqrt (n) -floor(sqrt(n))==0)
    {   arr[n]=1;
        return arr[n];
    }
    if(n <=3)
    {  arr[n]=n;
        return n;
    }
    int ans= n;
    if(arr[n] != 0) return arr[n];
    for(int i=1 ; i*i<=n ; i++)
    {   
       
       arr[n] =ans= min(ans , 1 + mincount(n-i*i,arr));
    }
    
    return arr[n];
}

int minCount(int n){
    int arr [n+1];
    for(int i=0 ;i<=n ;i++)
        arr[i]=0;
    return mincount(n , arr); 

}

*/

// brute force 
/*
int minCount(int n){

    if( sqrt (n) -floor(sqrt(n))==0)
       return 1;
    if(n <=3)
        return n;
   int ans= n;
    for(int i=1 ; i*i<=n ; i++)
    {
      ans = min(ans , 1 + minCount(n-i*i));
    }


   return ans;

}*/

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}