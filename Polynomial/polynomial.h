#ifndef POLYNOMIAL_H_INCLUDED
#define POLYNOMIAL_H_INCLUDED

/*!
	\brief Class,which realize polynomial

	This class realize math polynomial in one variable.

	\author Znenya Samchuk
	\version 1.0
	\date September'21

*/

class Polynomial{
private:
    short power;
    std::vector<short> coefficients;
public:
    Polynomial(short power,std::vector<short> coefficients);
    Polynomial(short power);
    Polynomial(Polynomial* second_p);
    Polynomial();
    friend std::istream& operator>> (std::istream &in,Polynomial &pol);
    friend std::ostream& operator<< (std::ostream &out,const Polynomial &pol);
    short& operator[](const int number);
    int operator()(const int x_value);
    bool operator == (Polynomial* second_p);
    bool operator != (Polynomial* second_p);
    Polynomial* operator + (Polynomial* second_p);
    Polynomial& operator += (Polynomial* second_p);
    Polynomial* operator - (Polynomial* second_p);
    Polynomial& operator -= (Polynomial* second_p);
    Polynomial* operator * (Polynomial* second_p);
    Polynomial& operator *= (Polynomial* second_p);
    Polynomial* operator / (Polynomial* second_p);
    Polynomial& operator /= (Polynomial* second_p);
};

#endif // POLYNOMIAL_H_INCLUDED
