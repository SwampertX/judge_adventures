#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h,u,d,f;
    while (cin>>h>>u>>d>>f)
    {
        if (u==0) break;
        else
        {
            int day(1); double up,loc(0);
            up = u*(100-f*(day-1))/100.0;
            if (up<0) up=0;
            loc+=up; if (loc<h) loc-=d; if (loc==0) day++;
            while(loc>0 && loc<h)
            {
                day+=1;
                up = u*(100-f*(day-1))/100.0;
                if (up<0) up=0;
//                cout<<up<<' ';
                loc+=up; if (loc>h) break; loc-=d; if (loc==0) day++;
//                cout<<loc<<endl;
            }
            if (loc<=0) cout<<"failure on day "<<day<<endl;
            else cout<<"success on day "<<day<<endl;
        }
    }
}
