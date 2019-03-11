#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    bool flag=true;
    while (cin>>n) {
        char c, cp;
        for (int i=0; i<n && flag; i++) {
            string temp; cin>>temp;
            if (i==0) {
                c=temp[0];
                cp=temp[1];
            }
            if (c==cp) {
                flag=false;
                cout<<"NO"<<endl;
                break;
            }
            for (int j=0; j<n; j++){
                if (j==i or j==(n-1-i)){
                    if (temp[j]!=c) {
                        cout<<"NO"<<endl;
                        flag=false;
                        break;
                    }
                } else if (temp[j]!=cp) {
                    cout<<"NO"<<endl;
                    flag=false;
                    break;
                }
            }
            if (i==n-1 && flag) cout<<"YES"<<endl;
        }

    }
}
