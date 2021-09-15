#include <iostream>
#include <vector>

std::vector<bool> translate_to_direct_code(int number){
    std::vector<bool> binary_number;
    while (number)
    {
        binary_number.emplace(binary_number.begin(),number % 2);
        number /= 2;
    }
    for(int tmp = binary_number.size();tmp < 16;tmp++){
        binary_number.emplace(binary_number.begin(),0);
    }
    binary_number[0] = number < 0 ? 1 : 0;
    return binary_number;
}

bool testing(){
    if(translate_from_decimal_to_binary(4) != std::vector<bool> {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0}) return false;
    if(translate_from_decimal_to_binary(5) != std::vector<bool> {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1}) return false;
    return true;
}

/*vector <bool> to_binary_straight(int num)
{
	vector <bool> res;
	size_t size;
	int num_;
	num_ = abs(num);
	while (num_)
	{
		res.emplace(res.begin(), num_ % 2);
		num_ /= 2;
	}
	size = res.size();
	for (size_t i = 0; i < 16 - size; i++)
	{
		res.emplace(res.begin(), 0);
	}
	if (num < 0)
	{
		res[0] = 1;
	}
	return res;
}
*/

int main(){
    if(testing()) std::cout << "CORRECT\n";
    return 0;
}
