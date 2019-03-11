#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    while (cin>>n)
    {
        int cplates[n], sum(0);
        for (int i=0; i<n; i++)
        {
            int temp; cin>>temp;
            sum += temp;
            cplates[i] = sum;
        }
        int hi,lo,mid,k;
        cin>>m;
        for (int i=0; i<m; i++)
        {
            lo=0; hi=n-1;
            int quest; cin>> quest;
            while (lo<hi)
            {
                mid=lo+(hi-lo)/2;
                if (cplates[mid]>=quest)
                    hi=mid;
                else lo=mid+1;
            }
            cout<<lo+1<<endl;
        }

    }
}
