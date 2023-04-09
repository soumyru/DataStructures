/*
A thief robbing a store can carry a maximal weight of W into his knapsack. There are N items, and i-th item weigh 'Wi' and the value being 'Vi.' What would be the maximum value V, that the thief can steal?
Input Format :
The first line of the input contains an integer value N, which denotes the total number of items.

The second line of input contains the N number of weights separated by a single space.

The third line of input contains the N number of values separated by a single space.

The fourth line of the input contains an integer value W, which denotes the maximum weight the thief can steal.
Output Format :
Print the maximum value of V that the thief can steal.
Constraints :
1 <= N <= 20
1<= Wi <= 100
1 <= Vi <= 100

Time Limit: 1 sec
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output 1 :
13
Sample Input 2 :
5
12 7 11 8 9
24 13 23 15 16
26
Sample Output 2 :
51
*/
#include<iostream>
using namespace std;

int knapsack(int *w,int *value ,int n,int maxW)
{
    //base ccase
    if(n==0 ||maxW==0)
    return 0;

    if(w[0]>maxW)
    return knapsack(w+1,value+1,n-1,maxW);

    //recursive calls
    int x=knapsack(w+1,value+1,n-1,maxW-w[0]) + value[0];
    int y=knapsack(w+1,value+1,n-1,maxW);

    return max(x,y);
}

int main()
{
    int n;
    int weight[]={5,1,8,9,2};
    int value[]={4,10,2,3,1};
    int maxW=15;
    cout<<knapsack(weight,value,5,maxW)<<endl; //17
}