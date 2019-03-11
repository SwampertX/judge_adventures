#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

void submit() {
    freopen("shuffle.in","r",stdin);
    freopen("shuffle.out","w",stdout);
}

/*
int main() {
    submit();
    char n; while(cin>>n){
        vector<pair<char,string>> cows;
        vector<pair<char,char>> rev;
        char temp;
        for(char i=0; i<n; i++){
            cin>> temp;
            rev.push_back(make_pair(temp,i));
        }
        sort(rev.begin(),rev.end());
        char shuffle[100];
        char r=0;
        for(auto x:rev) {shuffle[r]=x.second;r++;}
        string t;
        for(char i=0; i<n; i++){
            cin>>t;
            cows.push_back(make_pair(shuffle[i],t));
        }
        for(char i=0; i<2; i++){
            sort(cows.begin(), cows.end());
            char j=0;
            for(auto &x: cows){
                x.first=shuffle[j];
                j++;
            }
        }
        sort(cows.begin(), cows.end());
        for(auto x: cows){
            cout<<x.second<<endl;
        }
    }
}
*/


int main() {
    submit();
    int n, ori[101], now[101], a[101]; cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    for(int i=1; i<=n; i++){
        cin>>now[i];
    }
    for(int i=0; i<3; i++){
        for(int j=1; j<=n; j++){//reverse
            ori[j]=now[a[j]];
        }
        for(int j=1; j<=n; j++){//prepare
            now[j]=ori[j];
        }
    }
    for(int i=1; i<=n; i++){
        cout<<ori[i]<<endl;
    }
    return 0;
}


/*
#include <fstream>
const int MAX_N = 100;
using namespace std;

int A[MAX_N+1];
int order[MAX_N+1];
int original_order[MAX_N+1];

int main(void)
{
  ifstream fin ("1.in");
  ofstream fout ("shuffle.out");

  int N;

  fin >> N;
  for (int i=1; i<=N; i++)
    fin >> A[i];
  for (int i=1; i<=N; i++)
    fin >> order[i];

  for (int iter=0; iter<3; iter++) {
    for (int i=1; i<=N; i++) original_order[i] = order[A[i]];
    for (int i=1; i<=N; i++) order[i] = original_order[i];
  }

  for (int i=1; i<=N; i++)
    fout << order[i] << "\n";
  return 0;
}
*/
