#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; while(cin>>n){
        int max=0, streak=0, current=0, temp;
        for(int i=0; i<n; i++){
            cin>>temp; if(temp>=current){
                streak++;
            } else streak=1;
            if (streak>max) max=streak;
            current=temp;
        }
        cout<<max<<endl;
    }
}
