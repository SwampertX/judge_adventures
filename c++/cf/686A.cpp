#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main(){
    ull n,x; while(cin>>n>>x){
        char sign; ull d, distress(0);
        for(ull i=0; i<n; i++){
            cin>>sign>>d;
            if(sign=='+'){
                x+=d;
            }else if (sign=='-'){
                if(x>=d) x-=d;
                else distress++;
            }
        }
        cout<<x<<' '<<distress<<endl;
    }
}
