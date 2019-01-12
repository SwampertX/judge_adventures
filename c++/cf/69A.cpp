#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin>>n)
    {
        int x,y,z,xs(0),ys(0),zs(0);
        for (int i=0; i<n; i++)
        {
            cin>>x>>y>>z;
            xs+=x; ys+=y; zs+=z;
        }
        if (xs==ys && xs==zs && xs==0)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
