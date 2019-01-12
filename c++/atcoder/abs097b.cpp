#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

int x;

bool is_pp(int x){
    int cp=x;
    for(int a=2; a*a<=x; a++){
        if(x%a!=0) continue;
        while(x%a==0){x/=a;}
        if(x==1) return true;
        else x=cp;
    } return false;
}

int largest_pp[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>x;
    largest_pp[1]=1;
    for(int i=2; i<=x; i++){
        if(is_pp(i)) largest_pp[i]=i;
        else largest_pp[i]=largest_pp[i-1];
    } cout<<largest_pp[x];

    return 0;
}
