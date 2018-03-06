#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
char t[12][12];
int pyv[10],pxv[10],pyn[10],pxn[10];

void citire(char t[12][12], int n)
{for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
    if(i==0)
        {t[i][j]='_';
        if(j==0 || j==n)
            t[i][j]=' ';}
    else if(j==0)
    t[i][j]='|';
    else if(j==n)
        t[i][j]='|';
    else if(i==n)
        t[i][j]='_';
    else t[i][j]=' ';}
void sarpe(int pyv[10],int pxv[10],int m,char t[12][12])
{int i=1,n;
n=m;
    pxv[m]=1;
pyv[m]=1;
m--;
while(m>=0)
{i++;
   pxv[m]=i;
   pyv[m]=1;
   m--;}
for(int j=1;j<=n;j++)
t[pyv[j]][pxv[j]]='x';
t[1][n]='X';}
void jocul(int pyv[10],int pxv[10],char t[12][12],int pyn[10],int pxn[10],int m)
{char c,ok=5,k=2,mn=0,g=2,a,b;

while(ok>0)
{cin>>c;
cout<<endl;
if(c=='w')
{pyn[1]=pyv[1]-1;
pxn[1]=pxv[1];}
if(c=='s')
 {pyn[1]=pyv[1]+1;
    pxn[1]=pxv[1];}
 if(c=='a')
 {pxn[1]=pxv[1]-1;
 pyn[1]=pyv[1];}
 if(c=='d')
    {pxn[1]=pxv[1]+1;
 pyn[1]=pyv[1];}
if(t[pyn[1]][pxn[1]]=='*')
    {m++;
mn--;
}
k=2;
while(k<=m)
{pxn[k]=pxv[k-1];
pyn[k]=pyv[k-1];
k++;}
if(t[pyn[1]][pxn[1]]=='_' || t[pyn[1]][pxn[1]]=='|' || t[pyn[1]][pxn[1]]=='x' )
    {cout<<"Ai murit"<<endl;
    ok=0;}
else {
if(mn==0)
{a=0;
while(t[a][b]!=' ' || a==0)
    {a=rand()%9;
b=rand()%9;}
t[a][b]='*';
    mn++;
}

for(int i=1;i<=m;i++)
 {t[pyv[i]][pxv[i]]=' ';
  t[pyn[i]][pxn[i]]='x';}
t[pyn[1]][pxn[1]]='X';
k=1;
while(k<=m)
{pxv[k]=pxn[k];
 pyv[k]=pyn[k];
 k++;}
for(int i=0;i<=11;i++)
{for(int j=0;j<=11;j++)
 cout<<t[i][j];
cout<<endl;}
cout<<"              Scor: "<<m-4;
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
}}

}

int main()
{srand(time(NULL));
    citire(t,11);
    sarpe(pyv,pxv,4,t);
jocul(pyv,pxv,t,pyn,pxn,4);
    return 0;

}
