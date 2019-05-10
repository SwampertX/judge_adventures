#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> primes;
bool isprime[100001];

void sieve() {
    fill(isprime, isprime+n, true);
    isprime[0] = false;
    isprime[1] = false;
    for(int i=2; i<=n && isprime[n]; i++) {
        primes.push_back(i);
        for(int k=2; k*i<=n; k++) {
            isprime[k] = false;
        }
    }
}

int main() {
    cin>>n;
    sieve();
    int t; cin>>t;
    for(int tt=0; tt<t; tt++) {
        int up, l; cin>>up>>l;
        int arr[l];
        for(int ll=0; ll<l; ll++) {
            cin>>arr[ll];
        }
    }
}
