#include <iostream>
using namespace std;
int main(){
    int n,k; cin>>n>>k;
    int arr[n];
    int c=0;
    for(int i=0;i<n;i++)
        cin>>arr[i];//build array
    for(int i=0; i<n; i++){//loop through the arr
        if(arr[k-1]<=arr[i] && arr[i]>0)
            c++;
        else
            break;
        }
    cout<<c<<endl;
    return 0;
    }
