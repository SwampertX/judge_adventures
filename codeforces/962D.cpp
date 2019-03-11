#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int n;
ull a[150005];
set<pair<ull, int> > b;
vector<pair<int, ull> > k;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        ull temp; cin>>temp;
        a[i]=temp;
        b.insert(make_pair(temp, i));
    }
    while(b.size()>1){
        auto itr=b.begin();
        auto c=*itr; advance(itr, 1); auto d=*itr;
        if(c.first==d.first){
            b.erase(c), b.erase(d);
            b.insert(make_pair(c.first*2, d.second));
        } else{
            b.erase(c);
            k.push_back(make_pair(c.second, c.first));
        }
    }
    auto itr=b.begin(); auto c=*itr;
    k.push_back(make_pair(c.second, c.first));
    sort(k.begin(),k.end());
    cout<<k.size()<<endl;
    for(auto x:k){
        cout<<x.second<<' ';
    }
}
