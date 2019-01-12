#include <bits/stdc++.h>
#include <sstream>
using namespace std;

int main(){
    int m,n;
    while(cin>>n>>m){
        int nx=n, ny=m, temp;
        vector<int>x,y;
        for(int i=0; i<n; i++){
            cin>>temp; x.push_back(temp);
        } for(int i=0; i<m; i++){
            cin>>temp; y.push_back(temp);
        }
        int vx=x[0],vy=y[0],py(0),px(0),files(0);
        while(px!=nx and py!=ny){
            if(vx==vy){
                files++;
                px++; py++;
                if(px==nx or py==ny) break;
                vx=x[px]; vy=y[py];
            } else if(vx>vy){
                vy+=y[++py];
            } else{vx+=x[++px];}
        }
        cout<<files<<endl;
    }
}
