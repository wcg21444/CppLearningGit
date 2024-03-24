#include <iostream>
#include "custom_vector.h"
#include <vector>

int main()
{
	vector<float> vec = {1.14,2.2,3.2,4,5,6.5};	//concept constraints


	std::cout << vec[2]<<std::endl;

	std::cout << vec[5] << std::endl;

	vec.extend(4);

	std::cout << vec[5] << std::endl;

	vec.append(4);

	std::cout << vec.end() << std::endl;

	vec.push_out(2);
	std::cout << vec[2] << std::endl;

	vec.cut(14);

	return 0;
}