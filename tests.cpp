#include<iostream>
#include<vector>
#include"Formulas.hpp"
#include<tuple>
void polynoms_print();
void degree_print();
void divider_print();
void predicate_print();

int main()
{
//	polynoms_print();
//	degree_print();
//	predicate_print();
	divider_print();
	return 0;

}
void predicate_print()
{
	double a = 1;
	double b = 10;
	double c = 1;
	std::vector<Predicate*> predicats;
	Lesser_predicate pred1(0,1,Polynom(std::vector<double>{-4*a*c,0.0,b*b}),0);
	predicats.push_back(&pred1);
	Equality_predicate pred2(0,1,Polynom(std::vector<double>{a}),1);
	predicats.push_back(&pred2);
	Conjunct two_roots(predicats);
	std::cout<<two_roots.calculate()<<std::endl;
}
void polynoms_print()
{
	std::vector<double> a{1,-8,5,-1,2};
	std::vector<double> b{1,-1,1};
	std::vector<double> c{4,1,2};
	Polynom A(a);
	Polynom B(b);
	Polynom C(c);
	std::cout<<"Polynom creation checking..."<<std::endl;
	std::cout<<"Polynom A is : "<<std::endl;
	A.print();
	std::cout<<"Polynom B is : "<<std::endl;
	B.print();
	std::cout<<"Polynom C is : "<<std::endl;
	std::cout<<"Polynom creation ended..."<<std::endl;
	C.print();	
}

void degree_print()
{
	std::vector<double> a{1,-8,5,-1,2};
	std::vector<double> b{1,-1,1};
	std::vector<double> c{4,1,2};
	Polynom A(a);
	Polynom B(b);
	Polynom C(c);
	std::cout<<"Polynom deg checking..."<<std::endl;
	std::cout<<" deg(A) is "<<A.get_degree()<<std::endl;
	std::cout<<" deg(B) is "<<B.get_degree()<<std::endl;
	std::cout<<" deg(C) is "<<C.get_degree()<<std::endl;
	std::cout<<"Polynom deg ended..."<<std::endl;
}

void divider_print()
{
	std::vector<double> a{1,1,0,1};
	std::vector<double> b{1,0,3};
	Polynom A(a);
	Polynom B(b);
	std::cout<<"Polynom dividing checking..."<<std::endl;
	std::cout<<"Divident is";
	A.print();
	std::cout<<"Divider is";
	B.print();
	std::pair<Polynom,Polynom> c=A.divide(A,B);
	std::cout<<"remainder is "<<std::endl;
	c.first.print();
	std::cout<<"quotient is"<<std::endl;
	c.second.print();
	std::cout<<"Polynom dividing ended"<<std::endl;
}
