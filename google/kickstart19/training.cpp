#include <bits/stdc++.h>

using namespace std;

int t,n,p;
int stu[100001], tim[100001];

int main() {
    cin>>t; 
    for(int k=0; k<t; k++){
        cin>>n>>p;
        for(int i=0; i<n; i++){
            cin>>stu[i];
        }
        sort(stu, stu+n);
        for(int i=0; i<n-p+1; i++){
            for(int j=i; j<i+p-1; j++)
                tim[i] += stu[i+p-1] - stu[j];
        }
        int m = (int) 2E9;
        for(int i=0; i<n-p+1; i++){
            m = tim[i] < m? tim[i] : m; 
        }
        printf("Case #%d: %d\n", k+1, m);
        fill(stu, stu+n, 0);
        fill(tim, tim+n-p+1, 0);
    }
    return 0;
}
