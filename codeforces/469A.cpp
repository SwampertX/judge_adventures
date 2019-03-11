#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; while(cin>>n){
        set<int> levels;
        int x,y,temp; cin>>x;
        for(int i=0; i<x; i++){
            cin>>temp; levels.insert(temp);
        }
        cin>>y;
        for(int i=0; i<y; i++){
            cin>>temp; levels.insert(temp);
        }
        if(levels.size()==n) cout<<"I become the guy.";
        else cout<<"Oh, my keyboard!";
    }
}
