/*
ID: tanyeej1
TASK: gift1
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
void submit() {
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);
}

int main() {
    submit();
    int np; while(cin>>np){
        map<string,int> acc;
        vector<string> order;
        for(int i=0; i<np; i++){
            string temp; cin>>temp;
            acc[temp]=0;
            order.push_back(temp);
        }
        for(int i=0; i<np;i++){
            string giver; int amt,ppl;
            cin>>giver>>amt>>ppl;
            if(ppl==0) continue;
            acc[giver]+=(abs(amt%ppl)-amt);
            for (int j=0; j<ppl; j++){
                string name; cin>>name;
                acc[name]+=amt/ppl;
            }
        }
        for (auto x:order){
            cout<<x<<' '<<acc[x]<<endl;
        }
    }
    return 0;
}
