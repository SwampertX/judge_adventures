#include <iostream>
using namespace std;
int main() {
int n,a,b,c;
while (cin>>n){
    int x=0;
    for (int i=0; i<n;i++){
        cin>>a>>b>>c;
        if (a+b+c>1)
            x++;
    }
    cout<<x<<endl;
}
return 0;
}
