#include <bits/stdc++.h>
using namespace std;
int main()
{
    string n;
    while (cin>>n)
    {
        cout<<n;
        reverse(n.begin(), n.end());
        cout<<n<<endl;
    }
}
