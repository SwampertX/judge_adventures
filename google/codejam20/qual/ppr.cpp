#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

int t, s, e, n;

int main(){
    /* ios_base::sync_with_stdio(false); */
    cin.tie(NULL);

    cin>>t;
    for(int tt=0;tt<t;tt++) {
        cin>>n;
        bool j[60*24+5];
        bool c[60*24+5];
        string res = "";
        for(int i=0;i<60*24+5;i++) {
            j[i]=true;
            c[i]=true;
        }
        for(int nn=0;nn<n;nn++) {
            cin>>s>>e;
            if(res=="IMPOSSIBLE") {
                continue;
            }
            bool jcan=true, ccan=true;
            for(int i=s; i<e;i++) {
                jcan &= j[i];
                ccan &= c[i];
            }

            if(!(jcan || ccan)) {
                res="IMPOSSIBLE";
            } else if (jcan) {
                for(int i=s;i<e;i++) {
                    j[i] = false;
                }
                res.append("J");
            } else {
                for(int i=s;i<e;i++) {
                    c[i] = false;
                }
                res.append("C");
            }
        }
        printf("Case #%d: ", tt+1);
        cout<<res<<'\n';
    }


    return 0;
}
