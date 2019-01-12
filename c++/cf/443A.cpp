#include <iostream>
#include <set>
using namespace std;
int main()
{
    set<char> letters;
    string temp; while(cin>>temp)
    {
        if(temp[temp.length()-1]=='}')//reinitialize co, clear letters
            {
                if ((temp.length()==2 && temp[0]!='{') || temp.length()==3) letters.insert(temp[temp.length()-2]);
                cout<<letters.size()<<endl;
                letters.clear();
            }
        else if (temp[0]=='{') letters.insert(temp[1]);
        else letters.insert(temp[0]);
    }
}
