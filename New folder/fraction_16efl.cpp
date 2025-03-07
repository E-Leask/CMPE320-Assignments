// fraction_16efl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream> 
#include <algorithm>  
#include <numeric>
#include "fraction_16efl.h"
using namespace std;

Fraction::Fraction()					//Default constructor
{
	numer = 0;
	denom = 1;
};
Fraction::Fraction(int num)			//One input Constructor
{
	numer = num;
	denom = 1;
};
Fraction::Fraction(int num, int den)	//Two input Constructor
{
	int i = GCD(num, den);
	numer = num / i;
	denom = den / i;
};
int Fraction::numerator() {
	return numer;
}
int Fraction::denominator() {
	return denom;
}
int Fraction::GCD(int num, int den) {
	while (num != den) {
		if (num > den) 
			num -= den;
		else
			den -= num;
	}
	return num;
}
Fraction operator<<(ostream& out, const Fraction input) {
	out << input.numer << "/" << input.denom;
}