#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(cin>>n)
    {
        vector<int> v;
        for (int i=0; i<n; i++)
        {
            int temp; cin>>temp;
            v.push_back(temp);
        }
        sort(v.begin(), v.end());
        int current(0), record(0);
        for (int i=0; i<v.size(); i++)
        {
            int canbuy = (lower_bound(v.begin(), v.end(), v[i])-v.begin())-1;
            current = v[i]*(n - canbuy);
            cout<<canbuy<<' '<<current<<' ';
            record = max(current, record);
        }
        cout<<record<<endl;
    }
}
