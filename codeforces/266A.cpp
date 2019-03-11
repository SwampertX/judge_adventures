#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    while (cin >> n) {
        string s; cin >> s;
        int co=0; int check=-1;
        while (check != co){
            check = max(co, check);
            for (int i = 0; i < s.length()-1; i++) {
                if (s[i] == s[i+1]) {
                    co++;
                    s.erase(i, 1);
                }
            }
        }
        cout<<co<<endl;
    }
    return 0;
}
