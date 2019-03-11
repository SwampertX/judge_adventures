#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

typedef unsigned long long ull;

int n,q, a[500005], BIT[500005];

void mod(int & modulant){modulant=modulant%MOD;}

void update(int n, int k){//add n to a[k]
    for(; k<=n; k+= k&-k){
        BIT[k] += n;
        mod(BIT[k]);
    }
}

int sum(int k){//prefix sum given index k
    int s=0;
    for(; k>=1; k-= k&-k){
        s+=BIT[k];
        mod(s);
    } return s;
}

vector<int> d;
void gen_divisors(int n){
    d.clear(); d.push_back(1), d.push_back(n);
    for(int i=2; i*i<=n; i++){
        if(n%i==0) {
            d.push_back(i);
            if(i*i!=n)d.push_back(n/i);
        }
    }
}

vector<int> p;
void gen_primes(){
    bool is_prime[500005]; fill(is_prime, is_prime+500005, true);
    for(int i=2; i*i<=500000; i++){
        if(is_prime[i]){
            for(int j=i*i; j<=500000; j+=i){is_prime[j]=false;}
        }
    } for(int i=2; i<=500000; i++){if(is_prime[i]) p.push_back(i);}
}

//product of all (1-1/p) s.t. p|(n/d) given n/d
int n_big_pi(int n, int j){
    ull ann=n;
    for(auto x: p){
        if(x>j) return int(ann);
        if(j%x==0) {
        ann*=(x-1); ann/=x;}
        ann=ann%MOD;
    } return int(ann);
}

int gcd(int a, int b){
    int big=max(a,b), small=min(a,b);
    if(small==0) return big;
    else return gcd(small, big%small);
}

int pillai(int n){//sum of gcd(k,n) for all +ve k at most n
    gen_divisors(n);
    int s=0;
    for(auto x: d){
        int wtv= n_big_pi(n, n/x);
        s+= wtv; mod(s);
    }return s;
}



int main(){
    gen_primes();
    cin>>n;
    for(int i=1; i<=n; i++){
        int temp; cin>>temp;
        //solution by totient
        a[i]=pillai(temp);
        /* pure euclid method
        for(int j=1; i<=temp; j++){
            a[i]+=gcd(j,temp); a[i]=mod(a[i]);
        }*/
        update(a[i], i);
    }

    cin>>q; while(q--){
        char s; int x,y;
        cin>>s>>x>>y;
        if(s=='U'){
            update(pillai(y)-a[x], x);
        } else{
            cout<<sum(y)-sum(x-1)<<endl;
        }
    }
    return 0;
}
