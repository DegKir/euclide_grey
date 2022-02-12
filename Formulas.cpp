#include<vector>
#include"Formulas.hpp"
// git init
// git add file.cpp anotherfile.cpp file.hpp 
// git commit -a(vse file) -m "Initial commit"
// git ls-files
// git log
// git remote add origin <url>
// git push
Polynom::Polynom(std::vector<double> coefficients): _coefficients(coefficients){}
double Polynom::get_value(double point_x)
{
	double sum=0;
	double monom=1;
	for (auto coefficient : _coefficients)
	{
		sum+=coefficient*monom;
		monom*=point_x;
	}
	return sum;
}	
//not actually givint derivative
Polynom Polynom::get_derivative()
{
	std::vector<double> derivative_coefficients;
	for (int i = 1; i++; i<=_coefficients.size())
		derivative_coefficients.push_back(_coefficients[i]*i);
	return Polynom(derivative_coefficients);
}
