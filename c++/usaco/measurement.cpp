#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

void submit() {
    freopen("measurement.in","r",stdin);
    freopen("measurement.out","w",stdout);
}


int main() {
    submit();
    int n; while(cin>>n){
        vector<tuple<char,string,short>> entries;
        for(int i=0; i<n; i++){
            char a; string b; short c;
            cin>>a>>b>>c;
            entries.push_back(make_tuple(a,b,c));
        }
        sort(entries.begin(),entries.end());
        map<string,short> milk={{"Bessie",7},{"Elsie",7},{"Mildred",7}};
        short max(7); set<string> fame={"Bessie", "Elsie", "Mildred"};
        short actions(0);
        for(auto x: entries){//x1 is cow, x2 is change
            milk[get<1>(x)]+=get<2>(x);
            if(fame.count(get<1>(x))){//check if the current cow is in set
                if(get<2>(x) > 0){//clear, new cow only
                    fame.clear(); fame.insert(get<1>(x)); max=milk[get<1>(x)]; actions++;
                } else if (get<2>(x) <0){//kick the cow out
                    fame.erase(find(fame.begin(),fame.end(),get<1>(x))); actions++;
                    if(fame.size()==0){//search for new cows
                        //very complicated
                        if(milk["Bessie"]==milk["Elsie"]){//first two same
                            fame.insert("Bessie"); fame.insert("Elsie");
                            if(milk["Elsie"]==milk["Mildred"]){//3rd also same
                                fame.insert("Mildred");
                            } else if (milk["Elsie"]<milk["Mildred"]){//3rd more
                                fame.clear(); fame.insert("Mildred");
                            }//else skip
                        } else if (milk["Bessie"]>milk["Elsie"]){
                            fame.insert("Bessie");
                            if(milk["Bessie"]==milk["Mildred"]){//3rd also same
                                fame.insert("Mildred");
                            } else if (milk["Bessie"]<milk["Mildred"]){//3rd more
                                fame.clear(); fame.insert("Mildred");
                            }//else skip
                        } else {
                            fame.insert("Elsie");
                            if(milk["Elsie"]==milk["Mildred"]){//3rd also same
                                fame.insert("Mildred");
                            } else if (milk["Elsie"]<milk["Mildred"]){//3rd more
                                fame.clear(); fame.insert("Mildred");
                            }//else skip
                        }
                    }
                }
            } else {//current cow not in set
                if(milk[get<1>(x)]>max){//clear, new cow only
                    fame.clear(); fame.insert(get<1>(x)); max=milk[get<1>(x)]; actions++;
                } else if (milk[get<1>(x)]==max){
                    fame.insert(get<1>(x)); actions++;
                }
            }
        }
        cout<<actions<<endl;
    }
}
