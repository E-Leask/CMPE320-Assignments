#pragma once
//C++ Fraction class designed to hold fractions.
//For example 1 / 10 would be stored as two values, 1 and 10, not 0.1.
//You should store a fraction in a normalized state.3/15->1/5
//GCD, of the two numbers

using namespace std;
class Fraction {
public:
	Fraction();					//Default constructor
	Fraction(int num);				//One input Constructor
	Fraction(int num, int den);	//Two input 
	int numerator();
	int denominator();
	int GCD(int num, int den);
	friend Fraction operator<<(ostream& out, const Fraction input);

private:
	int denom;
	int numer;
};