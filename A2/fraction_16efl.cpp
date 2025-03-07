// fraction_16efl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//#define EXPORTING_DLL
#include <iostream> 
#include <fstream>
#include <algorithm>  
#include <numeric>
#include <cmath>
#include "fraction_16efl.h"
#include <Windows.h>
using namespace std;

BOOL APIENTRY DllMain(HANDLE,
	DWORD ul_reason_for_call,
	LPVOID)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}


Fraction& Fraction::operator+=(const Fraction& right) {
	numer =right.numer*denom+right.denom*numer;
	denom = denom * right.denom;
	return *this;
}

bool operator==(const Fraction& left, const Fraction& right) {
	return (left.numer == right.numer && left.denom == right.denom);
}
bool operator!=(const Fraction& left, const Fraction& right) {
	return ((left.numer != right.numer) || (left.denom != right.denom));
}
bool operator>(const Fraction& left, const Fraction& right) {
	return (left.numer*right.denom > right.numer*left.denom);
}
bool operator<(const Fraction& left, const Fraction& right) {
	return (left.numer*right.denom < right.numer*left.denom);
}
bool operator>=(const Fraction& left, const Fraction& right) {
	return (left.numer*right.denom >= right.numer*left.denom);
}
bool operator<=(const Fraction& left, const Fraction& right) {
	return (left.numer*right.denom <= right.numer*left.denom);
}

Fraction& Fraction::operator-() {
	numer = numer*(-1);
	return *this;
}
Fraction& Fraction::operator++() {
	numer = numer + denom;
	return *this;
}
Fraction Fraction::operator++(int val) {
	Fraction temp = *this;
	numer = numer + denom;
	return temp;
}

Fraction operator+(const Fraction& left, const Fraction& right) {

	Fraction retVal(left.numer*right.denom +right.numer*left.denom, left.denom*right.denom);

	return retVal;
}
Fraction operator-(const Fraction& left, const Fraction& right) {

	Fraction retVal(left.numer*right.denom - right.numer*left.denom, left.denom*right.denom);

	return retVal;
}
Fraction operator*(const Fraction& left, const Fraction& right) {

	Fraction retVal(left.numer*right.numer, right.denom*left.denom);

	return retVal;
}
Fraction operator/(const Fraction& left, const Fraction& right) {

	Fraction retVal(left.numer*right.denom, right.numer*left.denom);

	return retVal;
}
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
	if (den == 0) 
	{
		throw FractionException("Halt, You've violated the law");
	}
	if (den < 0) {
		den = den * (-1);
			num = num * (-1);
	}
	int i = GCD(abs(num), abs(den));
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
	if (den <= num && num%den == 0) {
		return den;
	}else if(num<den){
		return GCD(den, num);
	}else {
		return GCD(den, num%den);
	}
}
FractionException::FractionException(const string & m) : message(m) {}
string FractionException::what() const {
	return message;
}
ostream& operator<<(ostream& out, const Fraction& input) {
	out << input.numer << "/" << input.denom;
	return out;
}
istream& operator>>(istream& in, Fraction& input) {
	int num,den;
	char val;
	in >> num;
	val = in.peek();
	
	if (val=='/') {
		in >> val;
		in >> den;
		input = Fraction(num, den);
	}
	else {
		input = Fraction(num);
	}
	return in;
}