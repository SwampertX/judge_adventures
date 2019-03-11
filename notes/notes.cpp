//to check if input contains any char in string given
//codeforces 118a
#include <bits/stdc++.h>>
using namespace std;
int main() {
char s;
while (cin>>s){
    if(!strchr("AEIOUYaeiouy",s))//here
        cout<<'.'<<(char)tolower(s)<<endl;//question
}
}
//to convert base 10, use stol(string input,0,base of input)

Binary search:
    take note of
    1. [all true], [all false]
    2. check for the first true/false instead of last true/false (if not the bounds die)
    3. extreme cases: 1/0 element vector
