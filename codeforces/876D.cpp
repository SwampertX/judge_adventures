#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; while(cin>>n)
    {
        vector<int> v; for(int i=0; i<n; i++){
        int temp; cin>>temp; v.push_back(temp);}
        short coins[300000]; for(int i=0; i<n; i++) coins[i]=0;
        cout<<1<<' '; int tail(n-1); int repeat(0);
        for (int i=0; i<n; i++){
            if (coins[v[i]-1]==1) repeat++;
            coins[v[i]-1]=1; while(coins[tail])tail--;
            int res=1+i+1-(n-1-tail)-repeat;
            cout<<res; if(i!=n-1) cout<<' ';
        }
    }
}
