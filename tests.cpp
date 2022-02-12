#include<iostream>
#include<vector>
#include"Formulas.hpp"
int main()
{
	std::vector<double> E{1,1,1};
	Polynom P(E);
	std::cout<<P.get_value(2);
	Polynom DP=P.get_derivative();
	return 0;
}
