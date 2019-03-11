#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ull n, a[1000000], tall, tallin,c;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(tall<a[i]){
            tall=a[i]; tallin=i;
        }
    }
    //left of tallin
    tall=0;
    for(int i=tallin-1; i<tallin; i--){
        if(a[i]>tall){
            tall=a[i]; c++;
        }
    }
    //right of tallin
    tall=0;
    for(int i=tallin+1; i<n; i++){
        if(a[i]>tall){
            tall=a[i]; c++;
        }
    }
    cout<<c;
    return 0;
}
