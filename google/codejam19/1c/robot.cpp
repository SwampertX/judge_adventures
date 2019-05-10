#include <bits/stdc++.h>

using namespace std;

int t, a;
string prog[255];

int main() {
    cin>>t;
    for(int tt=1; tt<=t; tt++) {
        cin>>a;
        for(int i=0; i<a; i++) {
            cin>>prog[i];
        } string ans;
        bool impos = false, finish = false;
        bool beaten[255]; fill(beaten, beaten+255, false);
        int beatencount = 0;

        // loop through characters 
        for(int i=0; !impos && !finish && beatencount!=a; i++) {
            //cout<<"round "<<i+1<<endl;
            bool p(false), r(false), s(false);
            int count = 0;

            // loop through strings that are alive
            //cout<<"survivors: ";
            for(int j=0; j<a; j++) {
                if(beaten[j]) continue;
                else {
                    //cout<<j;
                    switch (prog[j][i%prog[j].length()]) {
                        case 'P':
                            if(!p) { p = true; count++; } break;
                        case 'S':
                            if(!s) { s = true; count++; } break;
                        case 'R':
                            if(!r) { r = true; count++; } break;
                    }
                    if(count == 3) { //cout<<"have all three\n";
                        impos = true; break; }
                }
            }
            //cout<<endl<<"sanity: count should not be 1: "<<count<<endl;

            switch (count) {
                // all strings beaten
                case 0: finish = true; break;
                // beat all surviving strings
                case 1: ans += (p? 'S': s? 'R': 'P'); finish = true; break;
                // only beat the selected strings
                case 2: ans += (p&&r? 'P': p&&s? 'S': 'R'); 
                        char lost = (p&&r? 'R': p&&s? 'P': 'S'); 
                        //cout<<"losing char is "<<lost<<endl;
                        for(int j=0; j<a; j++) {
                            if(beaten[j]) continue;
                            else if(prog[j][i%prog[j].length()] == lost) {
                                beaten[j] = true; //cout<<j;
                            }
                        } //cout<<endl; 
                        break;
            }
        }
        cout<<"Case #"<<tt<<": "<<(impos? "IMPOSSIBLE": ans)<<endl;
    }
}
