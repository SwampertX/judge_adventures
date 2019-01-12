#include <bits/stdc++.h>
using namespace std;
int ceilIndex(vector<int> &v, vector<int> &tail, int hi, int key)
{
    int lo(0), m=lo+(hi-lo)/2;
    while (hi!=lo)
    {
        if(v[tail[m]]>=key)
            hi=m;
        else lo=m+1;
        m=lo+(hi-lo)/2;
    }
    return hi;
}
int main()
{
    int n; while(cin>>n)
    {
        vector<int> v, tail(n,0), res(n,-1); int temp;
        for (int i=0; i<n; i++)
        {
            cin>>temp; v.push_back(temp);
        }
        int len(0);
        for(int i=1; i<n; i++)
        {
            if(v[i]<=v[tail[0]])//less than least, replace
            {
                tail[0]=i;
            }
            else if (v[i]>v[tail[len]])
            {
                len++; tail[len]=i; res[len]=tail[len-1];
            }
            else
            {
                int c=ceilIndex(v,tail,len,v[i]);
                tail[c]=i; res[c]=tail[c-1];
            }
        }
        cout<<len+1<<endl;
    }
}
