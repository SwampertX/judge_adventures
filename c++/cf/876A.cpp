#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; while(cin>>n)
    {
        string s=to_string(n);
        int len=s.length();
        vector<int> ans; int co(0), i(n-9*len);
        while(i<n)
        {
            string temp=to_string(i); int state(0);
            for(int j=temp.length()-1; j>=0; j--)
            {
                short digit=temp[j]-'0';
                state+=digit+digit*pow(10,temp.length()-1-j);
            }
            if (state==n){
                co++; ans.push_back(i);
            }
            i++;
        }
        cout<<co<<endl;
        for (auto x:ans) cout<<x<<endl;
    }
}
