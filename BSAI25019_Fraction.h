#pragma once
#include <iostream>
#include "BSAI25019_Hugeinteger.h"
using namespace std;

class Fraction 
{
private:
	HI w ;
	HI n ; 
	HI d ; 

	HI gcd(const HI& a, const HI& b)
	{
		HI x = !a, y = !b;

		while (y != HI("0"))
		{
			HI t = y;
			y = x % y;
			x = t;
		}

		return x;
	}

	HI lcm(HI a, HI b)
	{
		return ((!a * !b)/ gcd(a, b));

	}

public:
	
	Fraction();
	Fraction(HI w, HI n, HI d);
	Fraction(const Fraction& F);

	// Conversion and Simplification - DO NOT CHANGE THESE SIGNATURES
	void toNormalFraction();
	void toImproperFraction();
	void simplify();

	// Arithmetic Operations - DO NOT CHANGE THESE SIGNATURES
	Fraction operator+(const Fraction& f);
	Fraction operator-(const Fraction& f);
	Fraction operator*(const Fraction& f);
	Fraction operator/(const Fraction& f);
	Fraction operator+=(const Fraction& f);
	Fraction operator-=(const Fraction& f);
	Fraction operator*=(const Fraction& f);
	Fraction operator/=(const Fraction& f);
	bool operator<(const Fraction& f);
	bool operator>(const Fraction& f);
	bool operator<=(const Fraction& f);
	bool operator>=(const Fraction& f);
	Fraction operator=(const Fraction& f);
	bool operator==(const Fraction& f);
	bool operator!=(const Fraction& f);
	Fraction operator-();

	// Display - DO NOT CHANGE THIS SIGNATURE
	void print() const;
	void setwhole(HI e);
	void setNumt(HI e);
	void setdenomt(HI e);

	// Getters - DO NOT CHANGE THESE SIGNATURES
	HI getWhole() const;
	HI getNumerator() const;
	HI getDenominator() const;

	friend istream& operator>>(istream& in, Fraction& f);
	friend ostream& operator<<(ostream& out, const Fraction& f);
};