#include <iostream>
#include <math.h>
using namespace std;

/*Написать и отладить программу поиска всех
корней функции f(x) на отрезке [a, b] в соответствии с вариантом (табл. 6.1).
 Метод нахождения корня оформить в виде отдельной функции, алгоритм которой описать блок-схемой. */

 //x^2 - 10 * sin ^ 2(x) + 2  ... a = -1 ... b = 3 ... Метод Ньютона
/*x≈-2.17806
x≈-0.493435
x≈0.493435
x≈2.17806*/


double proizv_func(double x){
    double y;
    y = 2*x - 20*sin(x)*cos(x);
    return y;
}

 double func(double x){
     double y;
     y = x*x - 10*(sin(x))*(sin(x)) + 2;
     return y;
 }

 double find_(double x,double eps){
     do{
        x = x - (func(x) / proizv_func(x));
     }while(fabs(func(x)) > eps);
     cout << x << endl;
 }

int main()
{
    find_(3,0.00001);
    find_(0.7,0.00001);
    find_(-0.1,0.00001);
    system("\nPause");
}
