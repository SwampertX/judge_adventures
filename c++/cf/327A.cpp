#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, temp, sum(0);
    int maxFar(0), maxHere(0);
    bool allone=true;
    cin>>n;
    while(n--){
        cin>>temp;
        sum+=temp;
        if(temp==1) temp=-1;
        else {temp=1; allone=false;}
        maxHere=max(maxHere+temp, 0);
        maxFar=max(maxFar, maxHere);
    }
    cout<<(allone?sum-1:sum+maxFar);
}
