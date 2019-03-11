#include <iostream>
using namespace std;
int main() {
    int n,k; cin>>n>>k;
    int sum=0;
    int temp(0),temp2,i=0;
    while (i<n && sum<k){
            cin>>temp2;
            temp+=temp2;
            sum+=min(temp,8);
            if (sum<k){
                i++;
                temp-=min(temp,8);
            }
            else
                break;
    }
    if  (k>8*n)
        cout<<-1<<endl;
    else if (sum<k){cout<<-1<<endl;}
    else {cout<<i+1<<endl;}
}
