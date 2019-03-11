#include <bits/stdc++.h>
using namespace std;

void submit(){
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
}

/*
int main(){
    submit();
    int x[4], y[4];
    for(int i=0; i<4; i++){
        cin>>x[i]>>y[i];
    }
    int area=0;
    if(x[2]>=x[1] or x[3]<=x[0] or y[2]>=y[1] or y[3]>=y[0]){//no intersection
        area= (x[1]-x[0])*(y[1]-y[0]);
    } else if(x[2]<=x[0] and y[2]<=y[0] and x[3]>=x[1] and y[3]>=y[1]){//fully covers
        area=0;
    } else if (y[2]<=y[0] and y[3]<=y[1]){//covers top or bottom
        if(x[2]>x[0]){area= (x[2]-x[0]) * (y[1]*y[0]);}
        else{area= (x[1]-x[3]) * (y[1]*y[0]);}
    } else if (x[2]<=x[0] and x[3]<=x[1]){//covers left or right
        if(y[2]>y[0]){area= (y[2]-y[0]) * (x[1]*x[0]);}
        else{area= (y[1]-y[3]) * (x[1]*x[0]);}
    } else{ area= (x[1]-x[0])*(y[1]-y[0]);}
    cout<<area;

}
*/

int main(){
    submit();
    int x[4], y[4];
    for(int i=0; i<4; i++){
        cin>>x[i]>>y[i];
    }
    int area=0;
    if(x[2]>=x[1] or x[3]<=x[0] or y[2]>=y[1] or y[3]<=y[0]){//no intersection.ok
        area= (x[1]-x[0])*(y[1]-y[0]);
    } else if (y[2]<=y[0] and y[3]>=y[1]){//covers left/right
        if(x[2]>=x[0]){area= (x[2]-x[0]) * (y[1]-y[0]);}
        else{area= (x[1]-x[3]) * (y[1]-y[0]);}
    } else if (x[2]<=x[0] and x[3]>=x[1]){//covers top/bottom
        if(y[2]>=y[0]){area= (y[2]-y[0]) * (x[1]-x[0]);}
        else{area= (y[1]-y[3]) * (x[1]-x[0]);}
    } else{ area= (x[1]-x[0])*(y[1]-y[0]);}//ok
    cout<<area;

}
