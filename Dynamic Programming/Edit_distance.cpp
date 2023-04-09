/*
Given two strings s and t of lengths m and n respectively, find the edit distance between the strings.
Edit Distance
Edit Distance of two strings is minimum number of operations required to make one string equal to other. In order to do so you can perform any of the following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note
Strings don't contain spaces
You need to find the edit distance from input string1 to input string2.
Input Format :
The first line of input contains a string, that denotes the value of s. The following line contains a string, that denotes the value of t.
Output Format :
The first and only line of output contains the edit distance value between the given strings.
Constraints :
1<= m,n <= 10
Time Limit: 1 second
Sample Input 1 :
abc
dc
Sample Output 1 :
2
*/
#include <iostream>
using namespace std;

// Brute Force
int editDistance(string s, string t)
{
    // base case
    if (s.size() == 0 || t.size() == 0)
        return max(s.size(), t.size());

    if (s[0] == t[0])
        return editDistance(s.substr(1), t.substr(1));

    else
    {
        int x = editDistance(s.substr(1), t) + 1;
        int y = editDistance(s, t.substr(1)) + 1;
        int z = editDistance(s.substr(1), t.substr(1)) + 1;

        return min(x, min(y, z));
    }
}

// Memoization
int editDistance2(string s, string t,int **output)
{
    int m=s.size();
    int n=t.size();
    // base case
    if (s.size() == 0 || t.size() == 0)
        return max(s.size(), t.size());

    // check if ans already exists
    if(output[m][n]!=-1)
    return output[m][n];

    int ans;
    if (s[0] == t[0])
        ans= editDistance2(s.substr(1), t.substr(1),output);

    else
    {
        int x = editDistance2(s.substr(1), t,output) + 1;//insert
        int y = editDistance2(s, t.substr(1),output) + 1;//delete
        int z = editDistance2(s.substr(1), t.substr(1),output) + 1;//replace

        ans= min(x, min(y, z));
    }

    //save the ans
    output[m][n]=ans;

    //return ans
    return ans;
}

int editDistance2(string s, string t)
{
    int m=s.size();
    int n=t.size();
    int **ans=new int*[m+1];
    for(int i=0;i<=m;i++)
    {
        ans[i]=new int[n+1];
        for(int j=0;j<=n;j++)
        {
            ans[i][j]=-1;
        }
    }   
    return editDistance2(s,t,ans);
}

//DP
int editDistance3(string s,string t)
{
    int m=s.size();
    int n=t.size();
    int **output=new int *[m+1];
    for(int i=0;i<=m;i++)
    {
        output[i]=new int[n];
    }

    //fill 1st row
    for(int j=0;j<=n;j++)
    {
        output[0][j]=j;
    }

    //fill 1st col
    for(int i=1;i<=m;i++)
    {
        output[i][0]=i;
    }

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[m-i]==t[n-j])
            {
                output[i][j]=output[i-1][j-1];
            }
            else
            {
                int a=output[i-1][j];
                int b=output[i][j-1];
                int c=output[i-1][j-1];
                output[i][j]=min(a,min(b,c))+1;
            }
        }
    }
    return output[m][n];
}

int main()
{
    string s, t;
    cin >> s >> t;                      // s=abc,t=ac
    // cout << editDistance(s, t) << endl; // 1
    // cout << editDistance2(s, t) << endl; // 1
    cout << editDistance3(s, t) << endl; // 1
}