#include <bits/stdc++.h>
using namespace std;

void submit(){
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
}

int main(){
    submit();
    int n, a[101];
    cin>>n; for(int i=0; i<n; i++){cin>>a[i];}
    bool impos=false;
    a[0]=0; for(int i=n-1; i>0; i--){
        if(a[i]>0){//recorded, write the rest
            for(int j=i-1; j>=i-a[i]; j--){
                if(a[j]!=-1 && a[j]!=a[i]-(i-j)){//incoherent
                    impos==true;
                    break;
                } else{a[j]=a[i]-(i-j);}
            }
        } if(impos) break;
    }
    if(impos){cout<<-1; return 0;}
    else{
        int zeroes(0), conneg(0), neg(0); bool con=false;
        for(int i=0; i<n; i++){
            if(a[i]==0){zeroes++; con=false;}
            else if(a[i]==-1 && !con){con=true; conneg++; neg++;}
            else if(a[i]==-1 && con) {neg++;}
            else con=false;
        }
        //cout<<"a is"; for(int i=0; i<n; i++){cout<<a[i]<<' ';}
        //cout<<endl; printf("zeroes %i, conneg %i, neg%i\n", zeroes, conneg, neg);
        cout<<zeroes<<' '<<zeroes+neg;
    }
}
