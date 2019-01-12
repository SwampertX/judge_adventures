#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; while(cin>>n){
        vector<int> cool; int temp;
        for(int i=0; i<n; i++){
            cin>>temp; cool.push_back(temp);
        }
        sort(cool.begin(),cool.end());
        int count=0, i=1;
        for(int i=1; i<n; i++){
            if(cool[i]<=cool[i-1]){
                int add; add=cool[i-1]-cool[i]+1;
                cool[i]+=add;
                count+=add;
            }
        }
        cout<<count<<endl;

        /*solution 2
        int sum=0; for(int i=0; i<n; i++){
            int temp; cin>>temp; sum+=temp;
        }
        cout<<n*(n+1)/2-sum<<endl;*/
    }
}
