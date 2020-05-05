#include<iostream>
using namespace std;
int main()
{
    int x,y,nr=0,prim=0,doi=0;
    while(nr<3)
    {
        cin>>x>>y;
        if(x!=y)
        {
            nr++;
            if((y==1&&x==0)||(y==2&&x==1)||(y==0&&x==2)) doi++;
            else prim++;
        }
    }
    if(prim>doi) cout<<"Primul a castigat";
    else cout<<"Al doilea a castigat";
}
