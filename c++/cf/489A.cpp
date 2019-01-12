#include <bits/stdc++.h>
using namespace std;
int s,l; string min_s="", max_s="";
bool can(int s, int l){
    return s>=0 && s<=9*l;
}
int main(){
    cin>>l>>s; int backup=s;
    if(l==1 and s==0) cout<<"0 0";
    else if (s<1 or s>9*l) cout<<"-1 -1";
    else{
        for(int i=0; i<l; i++){
            for(int j=0; j<=9; j++){
                if(!(i==0 and j==0) and can(s-j, l-i-1)){
                    min_s+=char('0'+j); s-=j;
                    break;
                }
            }
        }s=backup;
        for(int i=0; i<l; i++){
            for(int j=9; j>-1; j--){
                if(!(i==0 and j==0) and can(s-j, l-1-i)){
                    max_s+=char('0'+j); s-=j;
                    break;
                }
            }
        }
        cout<<min_s<<' '<<max_s;
    }
}
