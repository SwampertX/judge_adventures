#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

int n, g;
ull c;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++) {
        set<ull> tickets;
        cin>>g;
        ull curr;
        while(g--) {
            cin >> curr;
            auto cit = tickets.find(curr);
            if (cit == tickets.end())
                tickets.insert(curr);
            else tickets.erase(cit);
        }

        printf("Case #%d: %llu\n",i+1, *tickets.begin());
    }

    return 0;
}
