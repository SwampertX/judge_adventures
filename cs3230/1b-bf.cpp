#include <bits/stdc++.h>
using namespace std;

// brute force
long long int s[1000005];
long long int p, n;
bool useful(long long int m) {
    map<long long int, long long int> freq;
    freq[m] = 1;
    int take = n - 1;
    while(true) {
        while(take >= 0 && freq.count(s[take]) == 1 && freq[s[take]] > 0) {
            freq[s[take]]--;
            if (freq.count(s[take]) == 0 ) {
                freq.erase(s[take]);
            }
            take -= 1;
        }
        if(take < 0) {
            break;
        }
        if(freq.size() < 1) {
            break;
        }
        if(freq.size() == 1 && freq.begin()->first == 1) {
            break;
        }
        auto lastit = freq.end();
        lastit--;
        if(lastit->first == 1) {
            break;
        }
        long long int lastitnum = lastit->first;
        long long int lastitfreq = lastit->second;
        freq.erase(lastit);
        if(lastitfreq == 0) {
            continue;
        }
        if(lastitnum % 2 == 1) {
            long long int size = lastitnum / 2;
            freq[size] += lastitfreq;
            freq[size + 1] += lastitfreq;
        } else {
            freq[lastitnum / 2] += lastitfreq * 2;
        }
    }
    return take < 0;
}

int main () {
    long long int m, maxs = 0;
    cin>>p;
    cin>>n;
    if(p == 1) cin>>m;
    for(int i = 0;i < n;i++) {
        cin>>s[i];
        maxs = max(maxs, s[i]);
    }

    sort(s, s+n);
    if(p == 1) {
        if(useful(m)) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    } else {
        for (int i=1; i<1000000;i++) {
            if (useful(i)) {
                cout << i << endl;
                break;
            }
        }
    }
}
