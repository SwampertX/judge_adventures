#include <bits/stdc++.h>

using namespace std;

int t, n, pos, neg;
int main() {
    cin>>t;
    while(t--){
        cin>>n;
        pos = 0;
        neg = 0;
        while(n--) {
            int temp; cin>>temp;
            temp > 0? pos++: neg++;
        }
        if(pos*neg==0) cout<<pos+neg<<' '<<pos+neg<<'\n';
        else cout<<max(pos, neg)<<' '<<min(pos, neg)<<'\n';
    }
    return 0;
}
