#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; int n; while(cin>>n>>s){
        bool inParen=false, prevIsChar=false;
        int currentlen=0; length=0; wordInParen=0;
        for(int i=0; i<n; i++){
            if(s[i]=='(') inParen=true;
            else if(prevIsChar && s[i]==)
            if(inParen&&prevIsChar){
                if(s[i]=='_' || s[i]==')'){
                    wordInParen++; inParen=false;
                }
            }
        }
    }
}
