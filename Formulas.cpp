#include<vector>
#include"Formulas.hpp"
#include<iostream>
// git init
// git add file.cpp anotherfile.cpp file.hpp 
// git commit -a(vse file) -m "Initial commit"
// git ls-files
// git log
// git remote add origin <url>
// git push
// git git git giiiiiiiit
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
void Polynom::get_derivative()
{
//	std::cout<<"kek"<<_coefficients.size()<<"kek"<<std::endl;
	std::vector<double> derivative_coefficients;
	for (int i =0; i<_coefficients.size(); i++)
		std::cout<<_coefficients[i]*i<<std::endl;
//		derivative_coefficients.push_back(_coefficients[i]*i);
//	Polynom D(derivative_coefficients);
}
