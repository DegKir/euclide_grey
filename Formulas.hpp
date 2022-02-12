#include<vector>

class Polynom
{
private:
	std::vector<double> _coefficients;
public:
	Polynom(std::vector<double>);
	void get_derivative();
	double get_value(double);
};
