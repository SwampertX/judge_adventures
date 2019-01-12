#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ull n,m, r[100001], p[100001];
ull cp[100001];
double ans;

bool gtr(int a, int b){return a>b;}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>r[i];
    }
    for(int i=0; i<m; i++){
        cin>>p[i];
    }
    sort(r,r+n, gtr);
    sort(p, p+m);
    for(int i=m-1; i>=0; i--){
        cp[i]=p[i]+cp[i+1];
    }

    int stu_ptr(0), sch_ptr(0);
    while(stu_ptr<n && sch_ptr<m){
        if((n-stu_ptr)-1<=cp[sch_ptr+1]){
            ans+=r[stu_ptr];
            stu_ptr++; sch_ptr++;
        } else{
            double temp(0);
            int taking=(n-stu_ptr)-cp[sch_ptr+1];
            for(int j=stu_ptr; j<stu_ptr+taking; j++){
                temp+=r[j];
            } temp/=taking;
            ans+=temp;
            stu_ptr+=taking; sch_ptr++;
        }
    }
    cout<<setprecision(17)<<fixed<<ans/double(m);
    return 0;
}
