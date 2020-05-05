#include<iostream>
using namespace std;
int a[100][100];
int prim(int x)
{
    int i;
    if(x==0||x==1) return 0;
    if(x==2) return 1;
    if(x%2==0) return 0;
    for(i=3; i*i<=x; i=i+2)
        if(x%i==0)return 0;
    return 1;
}
int nextprim(int x)
{
    int p=x+1;
    while(prim(p)==0)
        p++;
    return p;
}
void generare(int n,int m)
{
    int i, j;
    int nrPrim = 1;
    for (i = 0; i < (n / 2) + (n % 2); i++)
    {
        for (j = i; j < m - i; j++)
        {
            nrPrim = nextprim(nrPrim);
            a[i][j] = nrPrim;
        }
        for (j = 1 + i; j < n - i; j++)
        {
            nrPrim = nextprim(nrPrim);
            a[j][m - i - 1] = nrPrim;
        }
        for (j = m - i - 2; j >= i; j--)
        {
            nrPrim = nextprim(nrPrim);
            a[n - i - 1][j] = nrPrim;
        }
        for (j = n - i - 2; j >= i + 1; j--)
        {
            nrPrim = nextprim(nrPrim);
            a[j][i] = nrPrim;
        }
    }
}
void citire(int &n,int &m)
{
    cin>>n>>m;
}
void afisare(int n,int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    int n,m;
    citire(n,m);
    generare(n,m);
    afisare(n,m);
}
