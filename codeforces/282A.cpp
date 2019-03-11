#include <iostream>
using namespace std;
int main() {
int n;
while (cin>>n){
    int x(0);
    for (int i=0;i<n;i++){
        string k; cin>>k;
        if (k[1]=='+')
            x++;
        else
            x--;
    }
    cout<<x<<endl;
}
}
