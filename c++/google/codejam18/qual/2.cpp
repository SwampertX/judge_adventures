#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main(){
    int t; cin>>t;
    for(int iter=0; iter<t; iter++){
        int n; cin>>n;
        vector<ull> odd, even;
        ull temp;
        for(int i=0; i<n; i++){
            cin>>temp;
            if(i%2==0) even.push_back(temp);
            else odd.push_back(temp);
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        vector<ull> all;
        for(int i=0; i<n/2; i++){
            all.push_back(even[i]);
            all.push_back(odd[i]);
        } if(n%2==1) all.push_back(even[(n-1)/2]);
        bool flag=true; int rec;
        for(int i=0; i<n-1; i++){
            if(all[i+1]<all[i]){flag=false; rec=i; break;}
        }
        cout<<"Case #"<<iter+1<<": "<<(flag?"OK":to_string(rec))<<endl;
    }
}
