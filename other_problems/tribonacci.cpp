#include<iostream>
using namespace std;
void citire(int &n,long a[])
{
    n=0;
    long x;
    cin>>x;
    while(x>0)
    {
        a[n++]=x;
        cin>>x;
    }

}
void afis(int &n,long a[])
{
    if(n==0) cout<<"nu s-a gasit";
    else
        for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}
void urmtri(long &t1,long &t2,long &t3,long &t4)
{
    t4=t3+t2+t1;
    t1=t2;
    t2=t3;
    t3=t4;
}
bool verif(long val,long trival,int &len,int &i)
{
    if(val==trival)
    {
        len++;
        i++;
        return 1;
    }
    return 0;
}
int detlung(long a[],int n,int i)
{
    int  l=0;
    long t1,t2,t3,t4;
    t1=0;t2=t3=1;
    verif(a[i],t1,l,i);
    verif(a[i],t2,l,i);
    urmtri(t1,t2,t3,t4);
    while(i<n&&a[i]>t3&&!verif(a[i],t3,l,i))
        urmtri(t1,t2,t3,t4);
    while(i<n&&a[i]==t3&&verif(a[i],t3,l,i))
        urmtri(t1,t2,t3,t4);
    return l;
}
void tribo(long t[],int n)
{
    t[0]=0;
    t[1]=t[2]=1;
    for(int i=3;i<=n;i++)
    t[i]=t[i-1]+t[i-2]+t[i-3];
}
