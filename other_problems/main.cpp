#include <iostream>

using namespace std;
int a[100],x,ok,n;
void citire(int &n)
{
    int i=1;
    a[0]=1;
    while(a[i-1]!=0)
    {
        cin>>a[i];
        i++;
    }
    n=i;
}
void afisare()
{
    for(int i=1;i<n;i++)
        cout<<a[i]<<' ';
}
bool prim(int b)
{
    if(b==1||b==0) return 0;
    if(b==2) return 1;
    if(b%2==0) return 0;
    for(int i=3;i*i<=b;i=i+2)
        if(b%i==0) return 0;
    return 1;
}
bool twin(int b,int c)
{
    if(b==c+2||b==c-2)
        if(prim(b)==1&&prim(c)==1)
        return 1;
    return 0;
}
void prog()
{
    for(int i=1;i<n-1;i++)
        for(int j=i+1;j<n;j++)
        if(twin(a[i],a[j]))
    cout<<"{"<<a[i]<<","<<a[j]<<"}";

}
int main()
{

}
