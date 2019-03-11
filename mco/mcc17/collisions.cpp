#include <iostream>
using namespace std;

int main() {
    string Balls_direction[10] = {"L", "R", "L", "L", "R", "L", "R", "L", "R", "R"};



    int c(0),m(0);
    while (true){
        int i;
        while (i=0; i<(Balls_direction[].size()-1); i++) {//bubble sort loop
            if (Balls_direction[i]+Balls_direction[i+1]=="RL") {//if RL swap, count++
                Balls_direction[i]="L"; Balls_direction[i+1]="R";
                c++;
            }
        }
        if (m==c) break;
        else m=c;
    }
    cout<<c<<endl;return 0;
}
