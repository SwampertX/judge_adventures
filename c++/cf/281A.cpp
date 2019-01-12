#include <iostream>
using namespace std;
int main(){
    string s;
    while (cin>>s){
        cout<<(char)toupper(s[0])<<s.substr(1)<<endl;
    }

}
