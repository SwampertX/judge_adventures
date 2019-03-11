#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

string to_binary(int n){
    string r;
    while(n!=0) {r=(n%2==0 ?'0':'1')+r; n/=2;}
    return r;
}

bool is_palin(string s){
    int l=s.length();
    if(l%2==0) return s.substr(0, l/2)==s.substr(l/2, l/2);
    else return s.substr(0, l/2)==s.substr(l/2+1, l/2);
}

vector<string> gen_palin(int k){
    //we need the mth (1-indexed) binary string of length k
    //print out the string in decimal integer
    vector<string> ans;
    if(k%2==0){
        for(int i=pow(2, k/2-1); i<pow(2, k/2); i++){
            string t1=to_binary(i), t2=t1;
            reverse(t2.begin(), t2.end());
            ans.push_back(t1+t2);
        }
    } else{
        for(int i=pow(2, k/2); i<pow(2, k/2+1); i++){
            string t1=to_binary(i), t2=t1.substr(0, t1.length()-1);
            reverse(t2.begin(), t2.end());
            ans.push_back(t1+t2);
        }
    } sort(ans.begin(), ans.end());
    return ans;
}

long gen_ans(int k, int m){
    //we need the mth (1-indexed) binary string of length k
    //print out the string in decimal integer
    string t1, t2;
    if(k%2==0){
        int i=pow(2, k/2-1)+m-1;
        t1=to_binary(i); t2=t1;
        reverse(t2.begin(), t2.end());
    } else{
        int i=pow(2, k/2)+m-1;
        t1=to_binary(i); t2=t1.substr(0, t1.length()-1);
        reverse(t2.begin(), t2.end());
    }
    return stol(t1+t2, nullptr, 2);
}

void sol_1(int k, int m){
    vector<string> ans=gen_palin(k);
    cout<<'\n';
    cout<<stol(ans[m-1], nullptr, 2);
}

void sol_2(int k, int m){
    cout<<gen_ans(k,m);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m; cin>>m;
    int k;
    for(int i=1; i<=50000; i++){
        int temp=pow(2, (i-1)/2);
        if(m<=temp) {k=i; break;}
        m-=temp;
    }
    sol_2(k,m);
    return 0;
}
