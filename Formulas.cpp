#include<vector>
#include<tuple>
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

std::vector<double> Polynom::get_coefficients()
{
	return _coefficients;
}

void Polynom::print()
{
	int size=_coefficients.size();
	for (int i = 0; i < size-1;i++)
		std::cout<<_coefficients[i]<<"x^"<<i<<"+";
	std::cout<<_coefficients[size-1]<<"x^"<<size-1<<std::endl;
}

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
//	std::cout<<"kek"<<_coefficients.size()<<"kek"<<std::endl;
	std::vector<double> derivative_coefficients;
	for (int i =1; i<_coefficients.size(); i++)
	{
//		std::cout<<_coefficients[i]*i<<std::endl;
		derivative_coefficients.push_back(_coefficients[i]*i);
	}
	return Polynom(derivative_coefficients);
}


int Polynom::get_degree()
{
	return _coefficients.size()-1;
}

std::pair<Polynom,Polynom> Polynom::divide(Polynom Pdivident,Polynom Pdivider)
{
	std::vector<double> divident = Pdivident.get_coefficients();
	std::vector<double> divider = Pdivider.get_coefficients();
	std::vector<double> remainder=divident;
	std::vector<double> quotient;
//check if degree of divider is bigger then degree of divident
	if (Pdivider.get_degree() > Pdivident.get_degree())
		std::cout<<"degree of divider is bigger then degree of divident"<<std::endl;
	while (remainder.size()>=divider.size())
	{
//		if (remainder.size()==divider.size())
//			if(remainder.back()<divider.back())
//				break;
		//deleting elder zeros if they exists		
		if (remainder.back()==0)
		{
			remainder.pop_back();
			continue;
		}
		std::vector<double> deduct(remainder.size(),0);
		std::vector<double> temp_quotient;
		double q = remainder.back()/divider.back();
		//adding coefficient into remainder
		quotient.push_back(q);

		int size_dif=remainder.size()-divider.size();

		//calculating deduction vector
		for(int i=0;i<remainder.size();i++)
		{
			if (i>=size_dif)
				deduct[i]=q*divider[i-size_dif];
			if (i<size_dif)
				deduct[i]=0;
		}
		//checking deduction 
		std::cout<<"deduct:"<<std::endl;
		for (int i =0;i<deduct.size();i++)
			std::cout<<i<<":"<<deduct[i]<<std::endl;
		//deduction itself
		std::cout<<"resultnig:"<<std::endl;
		//std::cout<<remainder[3]-deduct[3]<<std::endl;
		std::cout<<remainder.size()<<std::endl;
		for(int i =0; i<remainder.size();i++)
		{
			temp_quotient.push_back(remainder[i]-deduct[i]);
			std::cout<<i<<":"<<temp_quotient[i]<<std::endl;
		}
		
		//looping
		remainder=temp_quotient;
	}
	//need to reverse quotient vector
	std::vector<double> reversed_quotient;
	for (int i=quotient.size()-1;i>=0;i--)
		reversed_quotient.push_back(quotient[i]);
	std::pair<Polynom, Polynom> result{Polynom(remainder),Polynom(reversed_quotient)};
	return result;
}

Predicate::Predicate(double constant, double point, Polynom polynom, bool negative):_constant(constant),_point(point),_polynom(polynom),_negative(negative){}
Predicate::~Predicate(){}
Polynom Predicate::get_polynom()
{
	return _polynom;
}
double Predicate::get_point()
{
	return _point;
}
double Predicate::get_constant()
{
	return _constant;
}
double Predicate::polynom_in_point()
{
	return this->get_polynom().get_value(this->get_point());
}

bool Predicate::get_negative()
{
	return _negative;
}
//bool Predicate::calculate()
//{
//	return true;
//}
Equality_predicate::Equality_predicate(double constant, double point, Polynom polynom,bool negative) : Predicate(constant,point,polynom,negative){}
Equality_predicate::~Equality_predicate(){}

bool Equality_predicate::calculate()
{
	bool negative=this->get_negative();
	if (this->get_constant()==this->polynom_in_point())
		return true*(!negative);
	return !(true*(!negative));
}

Lesser_predicate::Lesser_predicate(double constant, double point, Polynom polynom, bool negative) : Predicate(constant,point,polynom,negative){}
Lesser_predicate::~Lesser_predicate(){}

bool Lesser_predicate::calculate()
{
	bool negative=this->get_negative();
	//if polynom leq then constant
	if (this->polynom_in_point()>=this->get_constant())
		return true*(!negative);
	return !(false*(!negative));
}

Conjunct::Conjunct(std::vector<Predicate*> predicats): _predicats(predicats) {}

bool Conjunct::calculate()
{
	for (auto predicate : _predicats)
	{
//		std::cout<<predicate->calculate()<<std::endl;
		if (predicate->calculate()==false)
			return false;
	}
	return true;
}

void Conjunct::add_predicate(Predicate * predicate)
{
	_predicats.push_back(predicate);
}

DNF::DNF(std::vector<Conjunct> conjuncts) : _conjuncts(conjuncts){}
bool DNF::calculate()
{
	bool result = false;
	for (auto  predicate: _conjuncts)
		if (predicate.calculate()==true)
			return true;
	return false;
}
void DNF::add_conjunct(Conjunct conjunct)
{
	_conjuncts.push_back(conjunct);
}



