#include <bits/stdc++.h>

using namespace std;

int n,h;
int arr[1000];

int main() {
    cin>>n>>h;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    for(int i=1; i<n; i++) {
        sort(arr, arr+i);
        int taken = 0;
        for(int j=0; j<i/2+i%2; j++) {
            taken+=arr[i-1-j*2];
        }
        if(taken>h) {
            cout<<i-1<<endl;
            return 0;
        }
    }
    cout<<n<<endl;
    return 0;
}
