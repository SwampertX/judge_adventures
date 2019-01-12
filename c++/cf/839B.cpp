#include <iostream>
using namespace std;
int main(){
    int n,k; cin>>n>>k;
    int arr[k];
    for (int i=0;i<k;i++){
        cin>>arr[i];
    }
    int co=0,co4=n,co2=2*n,i=0;
    while (i<k && co4>0){//exhaust all 4-seater
        if (arr[i]>=4){
            arr[i]-=4*(arr[i]/4);
            co4-=arr[i]/4;
            i++
        }
        else
            i++
    }
    if (co4==0){
        for (int j=0;j<k;j++){
            if (arr[j]>=4){cout<<"NO"<<endl;break;}
            else {
                    i=0;
                    while (i<k){//exhaust all 4-seater using 3s
                        if (co4<=0){cout<<"NO"<<endl;break;}
                        else if (arr[i]==3){
                            arr[i]=0
                            co4--;
                            i++
                        }
                        else
                            i++
                    }
                    if (co4)
            }
        }
    }
}
