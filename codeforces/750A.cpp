#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    while (cin>>n>>k)
    {
        int a,b,m; a=0; b=n-1; m=n;
        int sum= 5*m*(m+1)/2 + k;
        int check=sum-1;
        while (check!=sum)
        {
            check = sum;
            if (sum>240) b=m-1;
            else a=m+1;
            m=(a+b)/2;
            sum= 5*m*(m+1)/2 + k;
        }
        cout<<m<<endl;
    }
}
