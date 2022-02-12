#include<vector>

class Polynom
{
private:
	std::vector<double> _coefficients;
public:
	Polynom(std::vector<double>);
	Polynom get_derivative();
	double get_value(double);
};
