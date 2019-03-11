#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
    int n,x; while(cin>>n>>x){
        ull mult[100001], prod(0);
        vector<ull> subjects; ull temp;
        for(int i=0; i<n; i++){
            cin>>temp; subjects.push_back(temp);
            mult[i]=x; if(x>1) x--;
        }
        sort(subjects.begin(),subjects.end());
        for(int i=0; i<n; i++){
            prod+=subjects[i]*mult[i];
        }
        cout<<prod<<endl;
    }
}
