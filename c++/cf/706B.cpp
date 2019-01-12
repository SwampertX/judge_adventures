#include <bits/stdc++.h>
using namespace std;
int binarysearch(vector<int> x, int money)
{
    int n=x.size();
    int hi=n-1; int lo=0; int mid; bool flag=true;
    if (money>=x[n-1])
    {
        lo=n; flag=false;
    }
    while(hi>lo && flag)
    {
        mid=lo+(hi-lo)/2;
        if (x[mid]>money)
            hi=mid;
        else lo=mid+1;
    }
    return lo;
}
int main()
{
    int n;
    while (cin>>n)
    {
        vector<int> x;
        for (int i=0; i<n; i++)
        {
            int current; cin>>current;
            x.push_back(current);
        }
        sort(x.begin(), x.end());
        int q; cin>>q;
        for (int i=0; i<q; i++)
        {
            int quest; cin>>quest;
//            cout<<binarysearch(x, quest)<<endl;
            cout<<upper_bound(x.begin(), x.end(), quest)-x.begin()<<endl;
        }
    }
}
