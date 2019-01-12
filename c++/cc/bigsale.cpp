#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; double temp; vector<double> price,quan,disc;
        cin>>n; for(int i=0; i<n; i++){
            cin>>temp; price.push_back(temp);
            cin>>temp; quan.push_back(temp);
            cin>>temp; disc.push_back(temp);
        } double offer, accloss(0.0);
        for(int i=0; i<n; i++){
            offer = price[i]*(1+disc[i]/100.0)*(1-disc[i]/100.0);
            accloss+= (price[i]-offer)*quan[i];
        }
        printf("%9f\n", accloss);
    }
}
