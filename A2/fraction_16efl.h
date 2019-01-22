#pragma once
//C++ Fraction class designed to hold fractions.
//For example 1 / 10 would be stored as two values, 1 and 10, not 0.1.
//You should store a fraction in a normalized state.3/15->1/5
//GCD, of the two numbers


using namespace std;
#include "stdio.h"
#include <string>
#include <iostream>
#include <sstream>
#include <string.h>


//#ifdef EXPORTING_DLL
class __declspec(dllexport) Fraction {
public:
	Fraction();					//Default constructor
	Fraction(int num);				//One input Constructor
	Fraction(int num, int den);	//Two input 
	int denom;
	int numer;
	
	int numerator();	//Return numer
	int denominator();	//Reutrn denom
	int GCD(int num, int den);	//Recursively find greatest common divisor
	
	//Mathematic operators
	friend Fraction operator+(const Fraction& left, const Fraction& right); //  (a/b)+(c/d) numer=a*d+c*b	denom=b*d
	friend Fraction operator-(const Fraction& left, const Fraction& right); //  (a/b)-(c/d) numer=a*d-c*b	denom=b*d
	friend Fraction operator*(const Fraction& left, const Fraction& right);	//	(a/b)*(c/d) numer=a*c		denom=b*d
	friend Fraction operator/(const Fraction& left, const Fraction& right);	//	(a/b)/(c/d) numer=a*d		denom=c*b

	//Binary operators
	friend bool operator==(const Fraction& left, const Fraction& right);	//	(a/b) (c/d) check if a=c & b=d
	friend bool operator!=(const Fraction& left, const Fraction& right);	//	(a/b) (c/d) check if a!=c or b!=d
	friend bool operator>=(const Fraction& left, const Fraction& right);	//	(a/b) (c/d) check if a*d>=c*b
	friend bool operator>(const Fraction& left, const Fraction& right);		//	(a/b) (c/d) check if a*d>c*b
	friend bool operator<=(const Fraction& left, const Fraction& right);	//	(a/b) (c/d) check if a*d<=c*b
	friend bool operator<(const Fraction& left, const Fraction& right);		//	(a/b) (c/d) check if a*d<c*b

	//Unary operators
	Fraction& operator-();							//	(a/b) a=a*(-1)
	Fraction& operator++();							//	(a/b) numer=a+b 
	Fraction operator++(int val);					//	(a/b) clone (a/b), numer of original=a+b, return clone
	Fraction& operator+=(const Fraction& right);	//	same as +  however second fraction is the one which called the overloaded operator

};
class __declspec(dllexport) FractionException {
public:
	FractionException(const string&);
	string what() const;
private:
 string message;
};

__declspec(dllexport) ostream& operator<<(ostream& out, const Fraction& input);	//return numer + "/" + denom
__declspec(dllexport) istream& operator>>(istream& out, Fraction& input);			//if a/b format input use Fraction(a,b) constructor, else use Fraction(a) constructor and return input
