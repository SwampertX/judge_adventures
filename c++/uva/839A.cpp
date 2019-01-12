#include <iostream>
using namespace std;
int main() {
    int n,k; cin>>n>>k;
    int sum=0;
    int temp,i=0;
    while (i<n && sum<k){
            cin>>temp;
            sum+=temp;
            i++;
    }
    if (8*n<k){cout<<-1<<endl;}
    else if (sum<k){cout<<-1<<endl;}
    else {cout<<i<<endl;}
}
