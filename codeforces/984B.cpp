#include <bits/stdc++.h>
#define INF 2e18
#define MOD 10000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

int n,m;
char a[100][100];

bool have_bomb(int i, int j){
    if(i<0 or i>=n or j<0 or j>=m) return false;
    else if(a[i][j]=='*') return true;
    else return false;
}

bool no_no(int i, int j){
    if(i<0 or i>=n or j<0 or j>=m) return false;
    if(a[i][j]-'0'>0 && a[i][j]-'0'<9) return false;
    else return true;
}

bool is_no(int i, int j){
    if(i<0 or i>=n or j<0 or j>=m) return false;
    if(a[i][j]-'0'>0 && a[i][j]-'0'<9) return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int bmbs=a[i][j]-'0';
            if(bmbs>0 and bmbs<=8){
                if(have_bomb(i-1,j-1)) bmbs--;
                if(have_bomb(i-1,j)) bmbs--;
                if(have_bomb(i-1,j+1)) bmbs--;
                if(have_bomb(i,j-1)) bmbs--;
                if(have_bomb(i,j+1)) bmbs--;
                if(have_bomb(i+1,j-1)) bmbs--;
                if(have_bomb(i+1,j)) bmbs--;
                if(have_bomb(i+1,j+1)) bmbs--;
                if(bmbs!=0){cout<<"NO"; return 0;}
            } else if(a[i][j]=='*'){
                if(no_no(i-1,j-1)) {cout<<"NO"; return 0;}
                if(no_no(i-1,j)) {cout<<"NO"; return 0;}
                if(no_no(i-1,j+1)) {cout<<"NO"; return 0;}
                if(no_no(i,j-1)) {cout<<"NO"; return 0;}
                if(no_no(i,j+1)) {cout<<"NO"; return 0;}
                if(no_no(i+1,j-1)) {cout<<"NO"; return 0;}
                if(no_no(i+1,j)) {cout<<"NO"; return 0;}
                if(no_no(i+1,j+1)) {cout<<"NO"; return 0;}
            } else{
                if(is_no(i-1,j-1)) {cout<<"NO"; return 0;}
                if(is_no(i-1,j)) {cout<<"NO"; return 0;}
                if(is_no(i-1,j+1)) {cout<<"NO"; return 0;}
                if(is_no(i,j-1)) {cout<<"NO"; return 0;}
                if(is_no(i,j+1)) {cout<<"NO"; return 0;}
                if(is_no(i+1,j-1)) {cout<<"NO"; return 0;}
                if(is_no(i+1,j)) {cout<<"NO"; return 0;}
                if(is_no(i+1,j+1)) {cout<<"NO"; return 0;}
            }
            if(i==n-1 and j==m-1) cout<<"YES";
        }
    }
    return 0;
}

