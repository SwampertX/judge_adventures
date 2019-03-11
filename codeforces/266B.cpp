#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,t; while(cin>>n>>t){
        char people[50]; for(int i=0; i<n; i++){
            cin>>people[i];
        } for(int i=0; i<t; i++){
            for(int j=0; j<n-1; j++){
                if(people[j]=='B' and people[j+1]=='G'){
                    people[j]='G'; people[j+1]='B'; j++;
                }
            }
        }
        for(int i=0; i<n; i++){
            cout<<people[i];
        }
    }
}
