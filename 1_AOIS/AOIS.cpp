
#include <iostream>
#include <vector>
#include <math.h>

const short _NUMBER_OF_BITS_ = 16;

const std::vector<bool> _ONE_BINARY_ = std::vector<bool> {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};


class float_ {
public:
	std::vector <bool> mantissa;
	std::vector <bool> index;
};


const float_ f_pos_x1 = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 } };
const float_ f_pos_x2 = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 } };


//---------------------------------------------------------------------------

std::vector<bool> translate_to_direct_code(int number){
    std::vector<bool> binary_number;
	int positive_number = abs(number);
    while (positive_number)
    {
        binary_number.emplace(binary_number.begin(),positive_number % 2);
        positive_number /= 2;    
    }
    for(int tmp = binary_number.size();tmp < 16;tmp++){
        binary_number.emplace(binary_number.begin(),0);
    }
    binary_number[0] = number < 0 ? 1 : 0;
    return binary_number;
}

//------------------------------------------------------------------------------

std::vector<bool> translate_to_reverse_code(int number){
	std::vector<bool> binary_number = translate_to_direct_code(number);
	if(number < 0){
		for(int element_index = 1; element_index < binary_number.size(); element_index++){
			binary_number[element_index] = !binary_number[element_index];
		}
		binary_number[0] = 1;
	}
	return binary_number;
}

//-----------------------------------------------------------------------------

std::vector<bool> translate_from_reserve_to_direct_code(std::vector<bool> binary_number){
	if(binary_number[0] == 1){
		for(int element_index = 1;element_index < _NUMBER_OF_BITS_;element_index++){
			binary_number[element_index] = !binary_number[element_index];
		}
	}
	return binary_number;
}


short translate_from_binary_to_decimal(std::vector<bool> binary_number){
	short decimal_number = 0;
	for(int i = 1;i < binary_number.size();i++){
		decimal_number += binary_number[i]*std::pow(2,15 - i);
	}
	decimal_number = binary_number[0] == 1 ? (-1)*decimal_number : decimal_number;
	return decimal_number;
}

//------------------------------------------------------------------------------

std::vector <bool> binary_sum(std::vector<bool> first_vector, std::vector<bool> second_vector)
{
	std::vector <bool> res;
	bool trans = false;
	for (short i = _NUMBER_OF_BITS_; i > 0; i--)
	{
			if (first_vector[i-1] == 0 && second_vector[i-1] == 0 && trans == false)
			{
				res.emplace(res.begin(), 0);
				trans = false;
			}
			else if (first_vector[i-1] == 0 && second_vector[i-1] == 0 && trans == true)
			{
				res.emplace(res.begin(), 1);
				trans = false;
			}
			else if (first_vector[i-1] == 1 && second_vector[i-1] == 0 && trans == false)
			{
				res.emplace(res.begin(), 1);
				trans = false;
			}
			else if (first_vector[i-1] == 1 && second_vector[i-1] == 0 && trans == true)
			{
				res.emplace(res.begin(), 0);
				trans = true;
			}
			else if (first_vector[i-1] == 0 && second_vector[i-1] == 1 && trans == false)
			{
				res.emplace(res.begin(), 1);
				trans = false;
			}
			else if (first_vector[i-1] == 0 && second_vector[i-1] == 1 && trans == true)
			{
				res.emplace(res.begin(), 0);
				trans = true;
			}
			else if (first_vector[i-1] == 1 && second_vector[i-1] == 1 && trans == false)
			{
				res.emplace(res.begin(), 0);
				trans = true;
			}
			else if (first_vector[i-1] == 1 && second_vector[i-1] == 1 && trans == true)
			{
				res.emplace(res.begin(), 1);
				trans = true;
			}
	}
	if(first_vector[0] == 1 && second_vector[0] == 1) res[0] = 1;
	return res;
}

std::vector<bool> binary_sum_for_reserve_code(std::vector<bool> first_binary,std::vector<bool> second_binary){
	std::vector<bool> result = binary_sum(first_binary,second_binary);
	if(first_binary[0] == 1 && second_binary[0] == 1){
		result = binary_sum(first_binary,second_binary);
		result = binary_sum(result,_ONE_BINARY_);
		return translate_from_reserve_to_direct_code(result);
	}
	if(abs(translate_from_binary_to_decimal(translate_from_reserve_to_direct_code(second_binary))) > std::abs(translate_from_binary_to_decimal(first_binary))){
		result = translate_from_reserve_to_direct_code(result);
		result[0] = 1;
		return result;
	}
	else result[0] = 0;
	result = binary_sum(result,_ONE_BINARY_);
	return result;
}


std::vector<bool> binary_difference(std::vector<bool> first_binary,std::vector<bool> second_binary){
	bool tmp_bigger_or_not = false;
	std::vector<bool> res;
	if(first_binary[0] == 1 && second_binary[0] == 1){
		first_binary[0] = second_binary[0] = 0;
		res = binary_sum(first_binary,second_binary);
		res[0] = 1;
		return res;
	}
	else if(std::abs(translate_from_binary_to_decimal(first_binary)) < std::abs(translate_from_binary_to_decimal(second_binary))){
		std::vector<bool> tmp_vector = first_binary;
		first_binary = second_binary;
		second_binary = tmp_vector;
		tmp_bigger_or_not = true;
	}
	for(short i = _NUMBER_OF_BITS_ - 1;i > 0;i--){
		if(first_binary[i] == 1 && second_binary[i] == 1) res.emplace(res.begin(),0);
		else if(first_binary[i] == 1 && second_binary[i] == 0) res.emplace(res.begin(),1);
		else if(first_binary[i] == 0 && second_binary[i] == 0) res.emplace(res.begin(),0);
		else if(first_binary[i] == 0 && second_binary[i] == 1){
			res.emplace(res.begin(),1);
			int tmp_i = i - 1;
			if(first_binary[tmp_i] == 1) first_binary[tmp_i] = 0;
		}
	}
	if(tmp_bigger_or_not) res.emplace(res.begin(),1);
	else res.emplace(res.begin(),0);
	return res;
}

std::vector<bool> translate_to_additional_code(int number)
{
	if(number >= 0) return translate_to_direct_code(number);
 	return binary_sum(_ONE_BINARY_,translate_to_reverse_code(number));
}



void print_binary_number(std::vector<bool> binary_number){
	for(bool element : binary_number) std::cout << element << " ";
	std::cout << std::endl;
}

std::vector<bool> multiplication(std::vector<bool> first_binary,std::vector<bool> second_binary){
	std::vector<bool> result(16,0);
	std::vector<bool> tmp_binary(16,0);
	for(int second_index =  _NUMBER_OF_BITS_ - 1;second_index > 0;second_index--){
		if(second_binary[second_index] == 1){
			int tmp_index = second_index;
			for(int first_index = _NUMBER_OF_BITS_ - 1; first_index > 0;first_index--){
				if(tmp_index > 0){
					tmp_binary[tmp_index] = first_binary[first_index];
					tmp_index--;
				}
				else break;
			}
			result = binary_sum(result,tmp_binary);
		}
		tmp_binary = std::vector<bool> (16,0);
	}
	if(first_binary[0] + second_binary[0] == 0 || first_binary[0] + second_binary[0] == 2) result[0] = 0;
	else if(first_binary[0] + second_binary[0] == 1) result[0] = 1;
	return result;
}



void division(std::vector<bool> first_binary_number,std::vector<bool> second_binary_number){
	bool minus = false;
	if(first_binary_number[0] == 1 && second_binary_number[0] == 0) minus = true;
	if(first_binary_number[0] == 0 && second_binary_number[0] == 1) minus = true;
	first_binary_number[0] = second_binary_number[0] = 0;
	std::vector<bool> result_binary_number;
	for(short division_level = 0; division_level < 2; division_level++){
		if(result_binary_number.size() >= 6) break;
		if(translate_from_binary_to_decimal(first_binary_number) < translate_from_binary_to_decimal(second_binary_number)){
			while(translate_from_binary_to_decimal(first_binary_number) < translate_from_binary_to_decimal(second_binary_number)){
				result_binary_number.push_back(0);
				first_binary_number.push_back(0);
				first_binary_number.erase(first_binary_number.begin());	
			}
		}
		first_binary_number = binary_difference(first_binary_number,second_binary_number);
		result_binary_number.push_back(1);
	}
	if(minus) std::cout << '1';
	else std::cout << '0';
	for(int i = 1;i < 16;i++){
		std::cout << " 0";
	}
	std::cout << ',';
	for(int i = 1;i < 6;i++){
		std::cout << result_binary_number[i] << " ";
	}
	std::cout << std::endl;
}		



void float_addition(float_ a, float_ b)
{
	float_ res;
	bool sign = true;
	while (a.index != b.index)
	{
		a.index = binary_sum(a.index, _ONE_BINARY_);
		a.mantissa.emplace(a.mantissa.begin(), 0);
		a.mantissa.erase(a.mantissa.begin() + 1);
	}
	res.mantissa = binary_sum(a.mantissa, b.mantissa);
	res.index = a.index;

	if (!sign)
	std::cout << "0,";
	for (size_t i = 0; i < res.mantissa.size(); i++)
	{
		std::cout << res.mantissa[i];
	}
	std::cout << "*2^";
	for (size_t i = 0; i < res.index.size(); i++)
	{
		std::cout << res.index[i];
	std::cout << std::endl;
}


bool tests(){
	if(binary_sum(translate_to_direct_code(13),translate_to_direct_code(25)) != translate_to_direct_code(38)) return false;
	if(binary_difference(translate_to_direct_code(13),translate_to_direct_code(-25)) != translate_to_direct_code(-12)) return false;
	if(binary_difference(translate_to_direct_code(25),translate_to_direct_code(-13)) != translate_to_direct_code(12)) return false;
	if(binary_difference(translate_to_direct_code(-25),translate_to_direct_code(-13)) != translate_to_direct_code(-38)) return false;
	if(binary_sum(translate_to_reverse_code(13),translate_to_reverse_code(25)) != translate_to_reverse_code(38)) return false;
	if(binary_sum_for_reserve_code(translate_to_reverse_code(13),translate_to_reverse_code(-25)) != translate_to_direct_code(-12)) return false;
	if(binary_sum_for_reserve_code(translate_to_reverse_code(25),translate_to_reverse_code(-13)) != translate_to_reverse_code(12)) return false;
	if(binary_sum_for_reserve_code(translate_to_reverse_code(-25),translate_to_reverse_code(-13)) != translate_to_direct_code(-38)) return false;
	if(binary_sum(translate_to_additional_code(13),translate_to_additional_code(25)) != translate_to_direct_code(38)) return false;
	if(binary_sum(translate_from_reserve_to_direct_code(binary_sum(translate_to_additional_code(13),translate_to_additional_code(-25))),_ONE_BINARY_) != translate_to_direct_code(-12)) return false;
	if(binary_sum(translate_to_additional_code(25),translate_to_additional_code(-13)) != translate_to_direct_code(12)) return false;
	if(binary_sum(translate_from_reserve_to_direct_code(binary_sum(translate_to_additional_code(-13),translate_to_additional_code(-25))),_ONE_BINARY_) != translate_to_direct_code(-38)) return false;
	if(multiplication(translate_to_direct_code(25),translate_to_direct_code(13)) != translate_to_direct_code(325)) return false;
	if(multiplication(translate_to_direct_code(13),translate_to_direct_code(-25)) != translate_to_direct_code(-325)) return false;
	if(multiplication(translate_to_direct_code(25),translate_to_direct_code(-13)) != translate_to_direct_code(-325)) return false;
	if(multiplication(translate_to_direct_code(-13),translate_to_direct_code(-25)) != translate_to_direct_code(325)) return false;
	return true;
}



int main(){
	short key_number = 1;
	short first_key_number;
	std::cout << "Tests - 1 or operation choosing - 2:\n";
	std::cin >> first_key_number;
	if(first_key_number == 1){
		if(tests()) std::cout << "Correct results!\n";
		else std::cout << "Uncorrect results\n";
	}
	else if(first_key_number == 2){
	while(key_number){
	std::cout << "\n X1 = 13, X2 = 25 | Choose operation:  \nBinary sum: \n || X1 + X2 == in direct code - 1, in reverse code - 5, in additional code - 9 || \n || X1 - X2 == in direct code - 2, in reverse code - 6, in additional code - 10 || \n|| X2 - X1 == in direct code - 3, in reverse code - 7, in additional code - 11 || \n|| -X1 - X2 == in direct code - 4, in reverse code - 8, in additional code - 12 ||\n Binary multipication: \n|| X1*X2 == 13 , (-X1)*(X2) == 14 , X1*(-X2) == 15 , (-X1)*(-X2) == 16 || \n Binary division: \n || X1/X2 == 17 , (-X1)/X2 == 18 , X1/(-X2) == 19 , (-X1)/(-X2) == 20 || \n ";
	std::cout << "Adding floating-point numbers - 21\n";
	std::cout << "0 - EXIT\n";
	std::cin >> key_number;
	switch(key_number){
		case 1:{
			std::cout << "X_1 in direct code - ";
			print_binary_number(translate_to_direct_code(13));
			std::cout << "X_2 in direct code - ";
			print_binary_number(translate_to_direct_code(25));
			std::cout << "X1 + X2 = ";
			print_binary_number(binary_sum(translate_to_direct_code(13),translate_to_direct_code(25)));
			break;
		}
		case 2:{
			std::cout << "X1 in direct code - ";
			print_binary_number(translate_to_direct_code(13));
			std::cout << "X2 in direct code - ";
			print_binary_number(translate_to_direct_code(25));
			std::cout << "X1 - X2 = ";
			print_binary_number(binary_difference(translate_to_direct_code(13),translate_to_direct_code(-25)));
			break;
		}
		case 3:{
			std::cout << "X_1 in direct code - ";
			print_binary_number(translate_to_direct_code(13));
			std::cout << "X_2 in direct code - ";
			print_binary_number(translate_to_direct_code(25));
			std::cout << "X2 - X1 = ";
			print_binary_number(binary_difference(translate_to_direct_code(25),translate_to_direct_code(-13)));
			break;
		}
		case 4:{
			std::cout << "X_1 in direct code - ";
			print_binary_number(translate_to_direct_code(13));
			std::cout << "X_2 in direct code - ";
			print_binary_number(translate_to_direct_code(25));
			std::cout << "-X1 - X2 = "; 
			print_binary_number(binary_difference(translate_to_direct_code(-13),translate_to_direct_code(-25)));
			break;
		}
		case 5:{
			std::cout << "X_1 in reverse code - ";
			print_binary_number(translate_to_reverse_code(13));
			std::cout << "X_2 in reverse code - ";
			print_binary_number(translate_to_direct_code(25));
			std::cout << "X1 + X2 = ";
			print_binary_number(binary_sum(translate_to_reverse_code(13),translate_to_reverse_code(25)));
			break; 
		}
		case 6:{
			std::cout << "X_1 in reverse code - ";
			print_binary_number(translate_to_reverse_code(13));
			std::cout << "X_2 in reverse code - ";
			print_binary_number(translate_to_direct_code(25));
			std::cout << "X1 - X2 = "; 
			print_binary_number(binary_sum_for_reserve_code(translate_to_reverse_code(13),translate_to_reverse_code(-25)));
			break; 
		}
		case 7:{
			std::cout << "X_1 in reverse code - ";
			print_binary_number(translate_to_reverse_code(13));
			std::cout << "X_2 in reverse code - ";
			print_binary_number(translate_to_direct_code(25));
			std::cout << "X2 - X1 = ";
			print_binary_number(binary_sum_for_reserve_code(translate_to_reverse_code(25),translate_to_reverse_code(-13)));
			break; 

		}
		case 8:{
			std::cout << "X_1 in reverse code - ";
			print_binary_number(translate_to_reverse_code(13));
			std::cout << "X_2 in reverse code - ";
			print_binary_number(translate_to_direct_code(25));
			std::cout << "- X1 - X2 = ";
			print_binary_number(binary_sum_for_reserve_code(translate_to_reverse_code(-13),translate_to_reverse_code(-25)));
			break; 

		}
		case 9:{
			std::cout << "X_1 in additional code - ";
			print_binary_number(translate_to_additional_code(13));
			std::cout << "X_2 in additional code - ";
			print_binary_number(translate_to_additional_code(25));
			std::cout << "X1 + X2 = ";
			print_binary_number(binary_sum(translate_to_additional_code(13),translate_to_additional_code(25)));
			break; 

		}
		case 10:{
			std::cout << "X_1 in additional code - ";
			print_binary_number(translate_to_additional_code(13));
			std::cout << "X_2 in additional code - ";
			print_binary_number(translate_to_additional_code(25));
			std::cout << "X1 - X2 = ";
			print_binary_number(binary_sum(translate_from_reserve_to_direct_code(binary_sum(translate_to_additional_code(13),translate_to_additional_code(-25))),_ONE_BINARY_));
			break; 

		}
		case 11:{
			std::cout << "X_1 in additional code - ";
			print_binary_number(translate_to_additional_code(13));
			std::cout << "X_2 in additional code - ";
			print_binary_number(translate_to_additional_code(25));
			std::cout << "X2 - X1 = ";
			print_binary_number(binary_sum(translate_to_additional_code(25),translate_to_additional_code(-13)));
			break; 
		}
		case 12:{
			std::cout << "X_1 in additional code - ";
			print_binary_number(translate_to_additional_code(13));
			std::cout << "X_2 in additional code - ";
			print_binary_number(translate_to_additional_code(25));
			std::cout << "-X2 - X1 = ";
			print_binary_number(binary_sum(translate_from_reserve_to_direct_code(binary_sum(translate_to_additional_code(-13),translate_to_additional_code(-25))),_ONE_BINARY_));
			break; 

		}
		case 13:{
			std::cout << "X_1 in direct code - ";
			print_binary_number(translate_to_direct_code(13));
			std::cout << "X_2 in direct code - ";
			print_binary_number(translate_to_direct_code(25));
			std::cout << "X1*X2 = ";
			print_binary_number(multiplication(translate_to_direct_code(13),translate_to_direct_code(25)));	
			break; 

		}
		case 14:{
			std::cout << "X_1 in direct code - ";
			print_binary_number(translate_to_direct_code(13));
			std::cout << "X_2 in direct code - ";
			print_binary_number(translate_to_direct_code(25));
			std::cout << "(-X1)*X2 = ";
			print_binary_number(multiplication(translate_to_direct_code(25),translate_to_direct_code(-13)));
			break; 

		}
		case 15:{
			std::cout << "X_1 in direct code - ";
			print_binary_number(translate_to_direct_code(13));
			std::cout << "X_2 in direct code - ";
			print_binary_number(translate_to_direct_code(25));
			std::cout << "X1*(-X2) = ";
			print_binary_number(multiplication(translate_to_direct_code(13),translate_to_direct_code(-25)));
			break; 

		}
		case 16:{
			std::cout << "X_1 in direct code - ";
			print_binary_number(translate_to_direct_code(13));
			std::cout << "X_2 in direct code - ";
			print_binary_number(translate_to_direct_code(25));
			std::cout << "(-X1)*(-X2) = ";
			print_binary_number(multiplication(translate_to_direct_code(-13),translate_to_direct_code(-25)));
			break; 

		}
		case 17:{
			std::cout << "X_1 in direct code - ";
			print_binary_number(translate_to_direct_code(13));
			std::cout << "X_2 in direct code - ";
			print_binary_number(translate_to_direct_code(25));
			std::cout << "X1 / X2 = ";
			division(translate_to_direct_code(13),translate_to_direct_code(25));
			break; 
		}
		case 18:{
			std::cout << "X_1 in direct code - ";
			print_binary_number(translate_to_direct_code(13));
			std::cout << "X_2 in direct code - ";
			print_binary_number(translate_to_direct_code(25));
			std::cout << "(-X1)/X2 == ";
			division(translate_to_direct_code(-13),translate_to_direct_code(25));
			break;
		}
		case 19:{
			std::cout << "X_1 in direct code - ";
			print_binary_number(translate_to_direct_code(13));
			std::cout << "X_2 in direct code - ";
			print_binary_number(translate_to_direct_code(25));
			std::cout << "X1/(-X2) == ";
			division(translate_to_direct_code(13),translate_to_direct_code(-25));
			break;
		}
		case 20:{
			std::cout << "X_1 in direct code - ";
			print_binary_number(translate_to_direct_code(13));
			std::cout << "X_2 in direct code - ";
			print_binary_number(translate_to_direct_code(25));
			std::cout << "(-X1)/(-X2) == ";
			division(translate_to_direct_code(-13),translate_to_direct_code(-25));
			break;
		}
		case 21:{
			float_addition(f_pos_x1,f_pos_x2);
		}
		case 0:
			break;
		default:
			std::cout << "Invalid number! \n";
			break;
		}
	}
	}
	else std::cout << "Uncorrect input;";
}
