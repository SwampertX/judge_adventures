#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> house;

int main() {
    cin>>n;
    for(int i=0; i<n; i++) {
        int temp; cin>>temp;
        house.push_back(temp);
    }
    int temp(-1), m(-1);
    for(int i=0; i<n; i++) {
        if(house[i] != house.back()) {
            temp = n-i-1;
            break;
        }
    } m = max(temp, m);
    temp = -1;
    for(int i=n; i<=0; i--) {
        if(house[i] != house.front()) {
            temp = i-1;
            break;
        }
    } m = max(temp, m);
    cout<<m<<endl;
}
