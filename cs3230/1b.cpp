#include <bits/stdc++.h>
using namespace std;

long long int ss[1000005];
long long int p, nn;

bool useful(long long int m, long long int sum, long long int n, long long int* s) {
    if (m < sum) {
        return false;
    }
    map<long long int, long long int> freq;
    freq[m] = 1;
    int take = n - 1;
    while(true) {
        while(take >= 0 && freq.count(s[take]) == 1 && freq[s[take]] > 0) {
            freq[s[take]]--;
            if(freq[s[take]] == 0) {
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
        //if(lastit->first == 1)lastit++;
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
        while(freq.size() > 0 && freq.begin()->first < s[0]) {
            //cout<<freq.begin()->first<<' '<<freq.begin()->second<<endl;
            freq.erase(freq.begin());
        }
    }
    return take < 0;
}

int main () {
    long long int m, maxs = 0;
    long long int sum = 0;
    cin>>p;
    cin>>nn;
    if(p == 1) cin>>m;
    for(int i = 0;i < nn;i++) {
        cin>>ss[i];
        maxs = max(maxs, ss[i]);
        sum += ss[i];
    }

    sort(ss, ss+nn);
    if(p == 1) {
        if(useful(m, sum, nn, ss)) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    } else {
        long long int minrock = 1000000000000000000LL;
        /*for(long long int i = 1000000000000000000LL - 200;i < 1000000000000000000LL + 200LL;i++) {
            reached.clear();
            if(useful(i, true, reached)) {
                unordered_set<long long int> reached2;
                for(auto value : reached) {
                    if(useful(value, false, reached2)) {
                        minrock = min(minrock, value);
                    }
                }
            }
            }*/
        long long int x = ((int)(log2((long double)nn)) + 1);
        long long int trymax = maxs;
        long long int trymin = maxs;
        long long int range = 1;
        for(int j = 0;j <= x + 1; j++){
            //cout<<' '<<trymin<<' '<<trymax<<' '<<sum<<endl;
            for(long long int i = trymin - range/2 - 1; i <= trymin + range/2 + 1;i++) {
                if(useful(i, sum, nn, ss)) {
                    minrock = i;
                    break;
                }
            }
            if(minrock < 1000000000000000000LL)break;
            trymin = trymin * 2;
            trymax = trymax * 2 + 1;
            range = range * 2;
        }
        /*long long int x = 1<<((int)(log2((long double)n)) + 1);
        long long int tryfrom = max(1LL, s[n-1] * x - x - 1);
        long long int tryto = s[n-1] * x + x + 1;//max(sum, s[n-1] * 2 - 1);
        while(!useful(tryfrom, false, reached) && tryfrom <= tryto)
            tryfrom++;
        if(tryfrom <= tryto) {
            reached.clear();
            minrock = tryfrom;
            useful(minrock, true, reached);
            for(auto i : reached) {
                if(useful(i, false, reached)) {
                    minrock = min(i, minrock);
                }
            }*/
            if(minrock == 1000000000000000000LL) {
                cout<<"IMPOSSIBLE"<<endl;
            } else {
                cout<<minrock<<endl;
            }
        /*} else{
            cout<<"IMPOSSIBLE"<<endl;

            }*/
    }
}
