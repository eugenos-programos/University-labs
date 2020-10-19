//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <iostream>
#include <cstdio>
#pragma hdrstop
//---------------------------------------------------------------------------

#pragma argsused

using namespace std;

int main()
{
int j,k,d,s1,s2,arr1[10],arr2[10],n1,n2,j1,k1;
//
char st[11];                                  //декларация строки и её ввод
puts("Input string ");
gets(st);
//
d=strlen(st);
j=n1=s1=0;
for(int i=0;i<=d;i++){
 if(st[i]=='1')s1++;
 else
 {
  if(s1!=0){
    arr1[j]=s1;
    j++;
    n1++;
    }
  s1=0;
 }
}
k=n2=s2=0;
for(int i=0;i<=d;i++){
 if(st[i]=='0')
 s2++;
 else{
  if(s2!=0){
   arr2[k]=s2;
   k++;
   n2++;
   }
 s2=0;
 }
}
j1=arr1[0];
for(j=0;j<n1;j++){
 if(arr1[j]<j1)
 j1=arr1[j];
 }
k1=arr2[0];
for(k=0;k<n2;k++){
 if(arr2[k]<=k1)
 k1=arr2[k];
 }
puts("min gruppa edinic: ");
for(int s=1;s<=j1;s++) printf("1");
puts("\nmin gruppa nulej: ");
for(int s=1;s<=k1;s++) printf("0");
puts("\nPress any key...");
getch();
return 0;
}
//---------------------------------------------------------------------------
