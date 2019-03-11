#include <bits/stdc++.h>
using namespace std;

void submit(){
    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);
}

int main(){
    //submit();
    int n, a[101];cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a, a+n);
    int d[101]; for(int i=0; i<n-1; i++){
        d[i]=a[i+1]-a[i];
    }
    int balls(1); char state=' ';
    for(int i=n-2; i>=1; i--){
        if(state==' '){
            if(d[i]>d[i-1]) state='d';
            else if(d[i]<d[i-1]) state='a';
        } else if(state=='d'){
            if(d[i]>=d[i-1]) continue;
            else{state=' '; balls++;}
        } else if(state=='a'){
            if(d[i]<=d[i-1]) continue;
            else{state=' '; balls++;}
        }
    }
    cout<<balls;
}

