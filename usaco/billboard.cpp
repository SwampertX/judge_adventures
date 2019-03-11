#include <bits/stdc++.h>
using namespace std;

void submit() {
    freopen("billboard.in","r",stdin);
    freopen("billboard.out","w",stdout);
}

int main() {
    submit();
    short x[6],y[6];
    for(int i=0; i<6; i++){
        cin>>x[i]>>y[i];
    }
    int loss1,loss2,ori1,ori2;
    if(x[4]>=x[1] || y[4]>=y[1] || y[5]<=y[0] || x[5]<=x[0]) loss1=0;
    else loss1=(min(y[5],y[1])-max(y[4],y[0]))*(min(x[5],x[1])-max(x[4],x[0]));
    ori1=(x[1]-x[0])*(y[1]-y[0]);
    if(x[4]>=x[3] || y[4]>=y[3] || y[5]<=y[2] || x[5]<=x[2]) loss2=0;
    else loss2=(min(y[5],y[3])-max(y[4],y[2]))*(min(x[5],x[3])-max(x[4],x[2]));
    ori2=(x[3]-x[2])*(y[3]-y[2]);
    cout<<ori1+ori2-loss1-loss2<<endl;
}
