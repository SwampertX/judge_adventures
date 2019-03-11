#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,t; while(cin>>n>>t)
    {
        t--; while(n!=1 && t>0)
        {
            if (n%2==0) n/=2;
            else n=3*n+1; t--;
        }
        if (t==0) cout<<n<<endl;
        else cout<<-1<<endl;
    }
}
