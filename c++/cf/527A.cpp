#include <iostream>
using namespace std;
int main() {
    long long a,b,ap,bp,co(0);
    while (cin>>a>>b) {
        while(min(a,b) != 0) {
            co += a/b;
            bp = a-((a-a%b)/b)*b;
            ap = b;
            a = ap; b = bp;
        }
        cout<<co<<endl;
    }
}
