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

const double eps = 0.00001;

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

 double find_(double x){
     do{
        x = x - (func(x) / proizv_func(x));
     }while(fabs(func(x)) > eps);
     return x;
 }

double main_func(double a , double b){
    double tmp = a,h = 0.1;
    while(tmp < b){
        if(func(tmp)*func(tmp+h) < 0)
            if(trunc(func(find_(tmp))*100000.0)/100000.0 == 0)
                cout << find_(tmp) << endl;
        tmp += h;
    }
}

int main()
{
    main_func(-1,3);
    system("\nPause");
}
