/*
ID: tanyeej1
TASK: ride
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a,b; fin>>a>>b;
//    string a,b; cin>>a>>b;
    int am(1),bm(1);
    for (int i=0; i<a.length(); i++){
        am*=(a[i]-'A'+1);
        am=am%47;
    }
    for (int i=0; i<b.length(); i++){
        bm*=(b[i]-'A'+1);
        bm=bm%47;
    }
    if(am==bm) fout<<"GO"<<endl;
    else fout<<"STAY"<<endl;
    return 0;
}
