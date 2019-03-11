#include <iostream>
using namespace std;
//page 8 "trivial" problems
//q1
long q1 (string x, int base){
return stol(x,0,base);
}
int main(){
cout<<"now doing q1"<<endl;
cout<<"enter a number and then its base:"<<endl;
string s; cin>>s;
int b; cin>>b;
cout<<"in base 10, the number is "<<q1(s,b)<<endl;
return 0;
}
