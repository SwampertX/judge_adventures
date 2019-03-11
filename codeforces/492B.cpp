#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int main() {
    int n,l; double d(0.0);
    while (cin>>n>>l) {
        set<int> input; int temp(0);
        for (int i=0; i<n; i++) {
            cin>>temp;
            input.insert(temp);
        }
        vector<int> light;
        copy(input.begin(), input.end(), back_inserter(light));
        sort(light.begin(), light.end());
        d = max(light.front(), l-light.back());
        for (int i=0; i< light.size()-1; i++) {
            double k; k= (light[i+1] - light[i])/2.0;
            if (k > d) {
                d = k;
            }
        }
        cout<<setprecision(15)<<fixed<<d<<endl;
    }
}
