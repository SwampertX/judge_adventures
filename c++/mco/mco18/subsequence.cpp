#include <bits/stdc++.h>
#define INF 2e9
#define MOD 1000000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int n;
int a[200005];
int cp;
vector<int> c(1000000005);
vector<int> tree(1000000005);


int mod(int n){return n%MOD;}

void add(int k, int x){
    while(k<=n){
        tree[k] += x;
        tree[k] = mod(tree[k]);
        k+= k&-k;
    }
}

int sum(int k) {
    int s=0;
    while(k>=1){
        s+=tree[k];
        s = mod(s);
        k-= k&-k;
    }
    return s;
}


int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int l=0, r=l;

    int cur_round(0), latest(0), ans(0);
    for(l; l<n; l++){
        r=l;
        fill(c.begin(), c.end(), 0);
        fill(tree.begin(), tree.end(), 0);
        cur_round=0; latest=0;
        for(r; r<n; r++){
            latest=mod(sum(a[r]-1)+1);
            add(a[r], latest);
            cur_round = mod(cur_round+latest);
            ans = mod(cur_round+ans);
        }
    }
    cout<<ans;
    return 0;
}
