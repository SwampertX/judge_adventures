#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; while(cin>>n)
    {
        vector <string> full;
        for (int i=0; i<n; i++)
        {
            string temp; cin>>temp;
            full.push_back(temp);
        }
        for (int i=0; i<n; i++)
        {
            if (count(full.begin(),full.begin()+i+1,full[i])>1)
                cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}
