#include <iostream>
#include <vector>
#include <math.h>
#include <cstdio>
#include "polynomial.h"

using namespace std;

    Polynomial::Polynomial(short power,std::vector<short> coefficients){
        if(coefficients.size() - 1 != power) {
            std::cout << "Uncorrect\n";
            exit(1);
        }
        this->power = power;
        this->coefficients = coefficients;
    }

    Polynomial::Polynomial(Polynomial* second_p){
        this->power = second_p->power;
        this->coefficients = second_p->coefficients;
    }

    Polynomial::Polynomial(short power){
        this->power = power;
        std::vector<short> new_vector(power + 1,0);
        this->coefficients = new_vector;
    }

    Polynomial::Polynomial(){

    }

    std::istream& operator>> (std::istream &in,Polynomial &pol){
    try{
        in >> pol.power;
        std::vector<short> pol_vector(pol.power + 1);
        for(short i = 0;i < pol_vector.size();++i){
            in >> pol_vector[i];
        }
        pol.coefficients = pol_vector;
    }
    catch(const char* exception){
        std::cerr << exception;
    }
    }


    std::ostream& operator<< (std::ostream &out,const Polynomial &pol){
        for(short i = 0;i <= pol.power;++i)out << pol.coefficients[i] << " ";

    }


    short& Polynomial::operator [] (const int number){
        if(number >= this->coefficients.size()) {
            std::cout << "Invalid number\n";
            exit(1);
        }
        return this->coefficients[number];
    }


    int Polynomial::operator()(const int x_value){
        int result_value = 0;
        for(short tmp_power = 0;tmp_power <= this->power;tmp_power++){
            result_value += (this->coefficients)[tmp_power] * (std::pow(x_value,tmp_power));
        }
        return result_value;
    }

    bool Polynomial::operator==(Polynomial* second_p){
        if(second_p->power != this->power) return false;
        if(this->coefficients != second_p->coefficients) return false;
        return true;
    }

    bool Polynomial::operator!=(Polynomial* second_p){
        if(!(*this == second_p)) return true;
        return false;
    }

    Polynomial* Polynomial::operator + (Polynomial* second_p){
        Polynomial* result_pol = new Polynomial();
        if(this->power < second_p->power){
                for(short tmp_power = this->power;tmp_power < second_p->power;tmp_power++){
                   this->coefficients.push_back(0);
                }
                this->power = second_p->power;
        }
        else{
            for(short tmp_power = second_p->power;tmp_power < this->power;tmp_power++){
                second_p->coefficients.push_back(0);
                }
            second_p->power = this->power;
        }
        result_pol->power = this->power;
        std::vector<short> result_vector(result_pol->power + 1);
        result_pol->coefficients = result_vector;
        for(short tmp_power = 0; tmp_power <= this->power;tmp_power++){
            result_pol->coefficients[tmp_power] = this->coefficients[tmp_power] + second_p->coefficients[tmp_power];
        }
        return result_pol;
    }
    Polynomial& Polynomial::operator += (Polynomial* second_p)
    {
        if(this->power < second_p->power){
                for(short tmp_power = this->power;tmp_power < second_p->power;tmp_power++){
                   this->coefficients.push_back(0);
                }
                this->power = second_p->power;
        }
        else{
            for(short tmp_power = second_p->power;tmp_power < this->power;tmp_power++){
                second_p->coefficients.push_back(0);
                }
            second_p->power = this->power;
        }

        for(short tmp_power = 0; tmp_power <= this->power;tmp_power++){
            this->coefficients[tmp_power] += second_p->coefficients[tmp_power];
        }
        return *this;
    }
    Polynomial* Polynomial::operator - (Polynomial* second_p){
        Polynomial* result_pol = new Polynomial();
        if(this->power < second_p->power){
                for(short tmp_power = this->power;tmp_power < second_p->power;tmp_power++){
                   this->coefficients.push_back(0);
                }
                this->power = second_p->power;
        }
        else{
            for(short tmp_power = second_p->power;tmp_power < this->power;tmp_power++){
                second_p->coefficients.push_back(0);
                }
            second_p->power = this->power;
        }
        result_pol->power = this->power;
        std::vector<short> result_vector(result_pol->power + 1);
        result_pol->coefficients = result_vector;
        for(short tmp_power = 0; tmp_power <= this->power;tmp_power++){
            result_pol->coefficients[tmp_power] = this->coefficients[tmp_power] - second_p->coefficients[tmp_power];
        }
        return result_pol;
    }
    Polynomial& Polynomial::operator -= (Polynomial* second_p){
        if(this->power < second_p->power){
                for(short tmp_power = this->power;tmp_power < second_p->power;tmp_power++){
                   this->coefficients.push_back(0);
                }
                this->power = second_p->power;
        }
        else{
            for(short tmp_power = second_p->power;tmp_power < this->power;tmp_power++){
                second_p->coefficients.push_back(0);
                }
            second_p->power = this->power;
        }

        for(short tmp_power = 0; tmp_power <= this->power;tmp_power++){
            this->coefficients[tmp_power] -= second_p->coefficients[tmp_power];
        }
        return *this;
    }
    Polynomial* Polynomial::operator * (Polynomial* second_p){
        Polynomial* result_polynomial = new Polynomial();
        result_polynomial->power = this->power + second_p->power;
        std::vector<short> result_vector(this->power + second_p->power + 1,0);
        result_polynomial->coefficients = result_vector;
        for(short first_power = 0;first_power <= this->power;first_power++){
            for(short second_power = 0;second_power <= second_p->power;second_power++){
                result_polynomial->coefficients[first_power + second_power ] += this->coefficients[first_power]*second_p->coefficients[second_power];
            }
        }
        return result_polynomial;
    }

    Polynomial& Polynomial::operator *= (Polynomial* second_p){
        std::vector<short> result_vector(this->power + second_p->power + 1,0);
        for(short first_power = 0;first_power <= this->power;first_power++){
            for(short second_power = 0;second_power <= second_p->power;second_power++){
                result_vector[first_power + second_power ] += this->coefficients[first_power]*second_p->coefficients[second_power];
            }
        }
        this->coefficients = result_vector;
        this->power += second_p->power;
        return *this;
    }


    Polynomial* Polynomial::operator / (Polynomial* second_p){
        Polynomial* from_which_we_subtract = new Polynomial(this);
        Polynomial* result_polynomial = new Polynomial(this->power - second_p->power,std::vector<short>(this->power - second_p->power + 1));
        Polynomial* what_we_subtract = new Polynomial();
        for(short tmp_power = result_polynomial->power; tmp_power >= 0;--tmp_power){
            result_polynomial->coefficients[tmp_power] = from_which_we_subtract->coefficients[from_which_we_subtract->power - result_polynomial->power + tmp_power] / second_p->coefficients[second_p->power];
            what_we_subtract->power = tmp_power;
            std::vector<short> tmp_vector(what_we_subtract->power + 1,0);
            tmp_vector[what_we_subtract->power] = result_polynomial->coefficients[tmp_power];
            what_we_subtract->coefficients = tmp_vector;
            *what_we_subtract *= second_p;
            if(from_which_we_subtract->power >= second_p->power) *from_which_we_subtract -= what_we_subtract;
            else break;
        }
        return result_polynomial;
    }

    Polynomial& Polynomial::operator /= (Polynomial* second_p){
        Polynomial* from_which_we_subtract = new Polynomial(this);
        Polynomial* result_polynomial = new Polynomial(this->power - second_p->power,std::vector<short>(this->power - second_p->power + 1));
        Polynomial* what_we_subtract = new Polynomial();
        for(short tmp_power = result_polynomial->power; tmp_power >= 0;--tmp_power){
            result_polynomial->coefficients[tmp_power] = from_which_we_subtract->coefficients[from_which_we_subtract->power - result_polynomial->power + tmp_power] / second_p->coefficients[second_p->power];
            what_we_subtract->power = tmp_power;
            std::vector<short> tmp_vector(what_we_subtract->power + 1,0);
            tmp_vector[what_we_subtract->power] = result_polynomial->coefficients[tmp_power];
            what_we_subtract->coefficients = tmp_vector;
            *what_we_subtract *= second_p;
            if(from_which_we_subtract->power >= second_p->power) *from_which_we_subtract -= what_we_subtract;
            else break;
        }
        this->coefficients = result_polynomial->coefficients;
        this->power = result_polynomial->power;
        return *this;
    }
