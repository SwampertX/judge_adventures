#include <iostream>
using namespace std;
typedef long long ll;
int main(){
ll i,j;
while (cin>>i>>j){
ll longest=0;
for (ll k=min(i,j);k<=max(i,j);k++){
    ll co=0;
    ll temp=k;
    while (temp!=1){
        if (temp%2==0){temp=temp/2; co++;}
        else {temp=3*temp+1; co++;}
    }
    if (co>longest)
        longest=co;
}
cout<<i<<' '<<j<<' '<<longest+1<<endl;
}
}
