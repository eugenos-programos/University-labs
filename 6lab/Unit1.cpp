//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop
#include <conio.h>
#include <iostream>

//---------------------------------------------------------------------------
#pragma argsused
void main()
{
double **a,s;     
int i,j,n,m,tmp;



printf(" Input size N,M: ");      
scanf("%d%d",&n,&m);

double *b = new double[n];          

a = new double*[n];                  
for(i=0;i<n;i++)      a[i] = new double[n];          


puts("\n Input Massiv A:");
for(i=0;i<n;i++)for(j = 0;j<m;j++)scanf("%lf",&a[i][j]);
 for(i=0;i<n;i++){
 tmp = 0;
 for(j = 0;j<m-1;j++){
 if(a[i][j] > a[i][j + 1]) tmp+=1;
 }
 if(tmp == m-1)b[i] = 0;
 else b[i] = 1;
 }


puts("Massiv B:");                               
for(i = 0;i<n;i++)printf(" %3.0lf",b[i]);



for(i = 0;i<n;i++) delete []a[i];
delete []a;
delete []b;
puts("\nDelete...\nPress any key...");            
getch();
}
//---------------------------------------------------------------------------
