#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

int arr[100001], last[100001], b4[100001], n, rec;

int ceil_index(int rec, int val){
    int l=1, r=rec+1, m=(l+r)/2;
    while(l<r){
        if(arr[last[m]]<val) l=m+1;
        else r=m;
        m=(l+r)/2;
    } return m;
}

int main(){
    while(cin>>n){
        memset(last, -1, sizeof(last));
        memset(b4, -1, sizeof(last));
        rec=0;
        for(int i=0; i<n; i++) cin>>arr[i];
        for(int i=0; i<n; i++){
            int append_len=ceil_index(rec, arr[i]);
            last[append_len]=i; b4[i]=last[append_len-1];
            rec=max(rec, append_len);
        } cout<<rec<<'\n';
        stack<int> lis;
        int k=last[rec];
        while(k!=-1){
            lis.push(k);
            k=b4[k];
        }while(!lis.empty()) {cout<<lis.top()<<' '; lis.pop();}
        cout<<'\n';
    }
    return 0;
}
