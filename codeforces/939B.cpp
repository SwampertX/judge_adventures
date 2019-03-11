#include <bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long n,k, temp, leastleft=numeric_limits<unsigned long long>::max(), record, number;
    cin>>n>>k;
    for(int i=0; i<k; i++){
        cin>>temp; unsigned long long leftover;
        leftover=n%temp;
        if(leftover<leastleft){record=i; leastleft=leftover; number=n/temp;}
    } cout<<record+1<<' '<<number;
}
