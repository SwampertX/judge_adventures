#include <iostream>
using namespace std;
int main() {
    int n;
    while (cin>>n) {
        int total(0),cap(0);
        for (int i=0; i<n; i++) {
            int in(0),out(0); cin>>out>>in;
            total += in; total -= out;
            cap = max(total, cap);
        }
        cout<<cap<<endl;
    }
}
