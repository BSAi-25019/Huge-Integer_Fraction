#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

class HI
{
private:
	vector<int> arr;
	int size;
	bool neg;



public:
	HI(int sz=0);
	HI(string s);
	HI(const HI&);
	HI(ifstream& rdr);

	const HI operator=(const HI&);
	const HI operator=(int);
	const HI operator=(string);
	HI asg(string s);
	void trim();
	void rev();
	friend ostream& operator<< (ostream& Z_Kl, const HI& gth);
	friend istream& operator>> (istream& Z_Kl,  HI& gth);
	friend const ofstream& operator<< ( const ofstream& Z_Kl, const HI& gth);
	friend ifstream& operator>> (ifstream& Z_Kl, HI& gth);
	const int operator[](int ikj)const;
	int& operator[](int i);
	const bool operator==(const HI&)const; 
    HI operator-();
	HI operator--(int d);
	HI operator--();
	HI operator++(int d);
	HI operator++();
	HI operator+(const HI&)const;
	HI& operator+=(const HI&);
	HI& operator-=(const HI&);
	HI operator-(const HI&)const;
	HI operator/(const HI&)const;
	HI operator!()const;
	HI operator*(const HI&)const;
	HI operator%(const HI&)const;
	HI& operator/=(const HI&);
	HI& operator*=(const HI&);
	HI& operator%=(const HI&);
	const bool operator!=(const HI&)const;
	const bool operator>(const HI&)const;
	const bool operator<(const HI&)const;
	const bool operator>=(const HI&)const;
	const bool operator<=(const HI&)const;
	HI Add_Qt(const HI&)const;
	HI Sub_Qt(const HI&)const;
	bool less_Qt(const HI&)const;
	bool grt_Qt(const HI&)const;
	bool eql_Qt(const HI&)const;








};

