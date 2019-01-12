#include <iostream>
using namespace std;
int main() {
    int n;

    while (cin>>n){
        for (int nume=n/2; nume>0; nume--) {//for every combi
            bool irre=true;
            for (int fac=2; fac<=nume; fac++) {//iterating factors
                if (nume%fac==0 && (n-nume)%fac==0) {//if common factor
                    irre=false;
                }
            }
            if (irre) {//if it still remains irre
                cout<<nume<<' '<<n-nume<<endl;
                break;
            }
        }
    }
}
