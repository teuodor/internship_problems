#include<iostream>
using namespace std;
const int p=666013;
struct mat2x2
{
    long x[2][2];
    mat2x2(long x00,long x01,long x10,long x11)
    {
        x[0][0]=x00%p;
        x[0][1]=x01%p;
        x[1][0]=x10%p;
        x[1][1]=x11%p;
    }
};
mat2x2 unitate()
{
    return mat2x2(1,0,0,1);
}
mat2x2 inmultire(mat2x2 X,mat2x2 Y)
{
    return mat2x2(X.x[0][0]*Y.x[0][0]+X.x[0][1]*Y.x[1][0],
                  X.x[0][0]*Y.x[0][1]+X.x[0][1]*Y.x[1][1],
                  X.x[1][0]*Y.x[0][0]+X.x[1][1]*Y.x[1][0],
                  X.x[1][0]*Y.x[0][1]+X.x[1][1]*Y.x[1][1]);
}
mat2x2 adunare(mat2x2 X,mat2x2 Y)
{
    return mat2x2(X.x[0][0]+Y.x[0][0],
                  X.x[0][1]+Y.x[0][1],
                  X.x[1][0]+Y.x[1][0],
                  X.x[1][1]+Y.x[1][1]);
}
mat2x2 ridicalaputere(mat2x2 X,long ex)
{
    if(ex==0)
        return unitate();
    mat2x2 jum=ridicalaputere(X,ex/2);
    mat2x2 jum2=inmultire(jum,jum);
    if(ex%2==0)
        return jum2;
    return inmultire(jum2,X);
}
mat2x2 calcS(mat2x2 X,long n)
{
    if(n==1) return X;
    long k=n/2;
    mat2x2 jum=calcS(X,k);
    mat2x2 un=adunare(unitate(),jum);
    mat2x2 tot=inmultire(un,jum);
    if(n%2==0)
    {
        return tot;
    }
    return adunare(tot,ridicalaputere(X,n));
}
mat2x2 citire()
{
   mat2x2 X(0,0,0,0);
   for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
        cin>>X.x[i][j];
   return X;
}
void afisare(mat2x2 X)
{
    cout<<X.x[0][0]<<" "<<X.x[0][1]<<endl<<X.x[1][0]<<" "<<X.x[1][1];
}
int main()
{
    mat2x2 X=citire();
    long n;
    cin>>n;
    afisare(calcS(X,n));
}
