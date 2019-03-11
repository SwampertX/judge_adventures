#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
int main() {
    int n,k;
    while (cin>>n>>k) {
        int ma,mi;
        ma = min(k,n/3)*2-max((k-n/3),0);
        if (k>(n/3)) ma += n%3;
        if (k==n || k==0) mi = 0;
        else mi=1;
        ma = max(0,ma);
        cout<<mi<<' '<<ma<<endl;
    }
}
