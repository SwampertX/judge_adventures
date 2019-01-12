#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; while(cin>>s){
        vector<int> zero,one;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='0')zero.push_back(i);
            else one.push_back(i);
        }
        if(one.size()>=zero.size()){cout<<-1;}
        else{
            int z=zero.size(), o=one.size();
            cout<<z-o<<endl;//no of lines
            int x=z-o;
            int pz=0, po=0;
            for(int i=0; i<x; i++){
                cout<<o+1<<' '<<zero[pz++]+1;
                int c=o;
                while(c--){
                    cout<<' '<<one[po++]+1; o--;
                    cout<<' '<<zero[pz++]+1;
                }
                cout<<endl;
            }
        }
    }
}
