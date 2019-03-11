/*
ID: tanyeej1
TASK: friday
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

void submit(){
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);
}

int main(){
    //submit();
    int n; while(cin>>n){
        int days[7], last(6);
        fill_n(days,7,0);
        //first one
        days[last]+=1;
        int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        for(int i=0; i<n;i++){
            for(int j=0; j<12; j++){
                if(!(i==n-1 && j==11)){
                    last+=months[j];
                    if(j==1){
                       if((1900+i)%100==0){
                        if((1900+i)%400==0)last++;
                       } else if ((1900+i)%4==0){last++;}
                    }
                    last%=7;
                    days[last]+=1;
                }
            }
        }
        int order[7]={6,0,1,2,3,4,5};
        for(int i=0; i<7; i++){
            cout<<days[order[i]];
            if(i==6) cout<<endl;
            else cout<<' ';
        }
    }
}
