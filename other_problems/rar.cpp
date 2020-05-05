#include<iostream>
using namespace std;
struct elem
{
    int linie,coloana,valoare;
};
struct matrar
{
    int nrlin,nrcol;
    int nrelem;
    elem a[100];
};
void citire(matrar &m)
{
    cin>>m.nrlin>>m.nrcol;
    m.nrelem=m.nrlin*m.nrcol;
    for(int i=1;i<=m.nrelem;i++)
    {
        m.a[i].valoare=0;
    }
    elem t;
    while(t.linie!=-1&&t.coloana!=-1&&t.valoare!=-1)
    {
        cin>>t.linie>>t.coloana>>t.valoare;
        m.a[m.nrcol*(t.linie-1)+t.coloana].valoare=t.valoare;
    }
}
void suma(matrar m1,matrar m2,matrar &m3)
{
    m3.nrlin=m1.nrlin;
    m3.nrcol=m1.nrcol;
    m3.nrelem=m1.nrelem;
    for(int i=1;i<=m3.nrelem;i++)
    {
        m3.a[i].valoare=m1.a[i].valoare+m2.a[i].valoare;
    }
}
void afisare(matrar m1)
{
    for(int i=1;i<=m1.nrelem;i++)
    {
        cout<<m1.a[i].valoare<<" ";
        if(i%m1.nrcol==0)
            cout<<endl;
    }
}
int main()
{
    matrar a,b,c;
    citire(a);
    citire(b);
    suma(a,b,c);
    afisare(c);
}
