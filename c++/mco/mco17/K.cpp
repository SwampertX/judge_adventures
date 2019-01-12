#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

string s,t;
vector<int> a;
int q;

int main(){
    cin>>s>>t>>q;
    ull len(0);
    for(int i=0; i<t.length(); i++){
        len++;
        if(i==0 and t[i]!=s[0]) {a.push_back(-1);}
        else if(i==0 and t[i]==s[0]) {a.push_back(1);}
        else if(t[i]==s[0] && t.substr(i-len,len+1) == s.substr(0,len+1) ) {
            a.push_back(2);
        }else if(t[i]==s[0]){len=0; a.push_back(1); printf("1 ");}
        else if( t.substr(i-len,len+1) == s.substr(0,len+1) ){a.push_back(0); printf("3 ");}
        else {len=0; a.push_back(-1); printf("4 ");}
    } cout<<endl;
    for(auto x: a) cout<<x<<' ';
    cout<<endl;


    while(q--){
        ull l,r; cin>>l>>r;
        if(find(a.begin()+l-1, a.begin()+r, -1)!=a.begin()+r){
            cout<<"NO, contains -1"<<endl;
        } else if(a[l-1]==0) {cout<<"NO, 1st letter cmi"<<endl;}
        else cout<<"YES only 10000"<<endl;
    }
    return 0;
}
