#include "BSAI25019_Hugeinteger.h"

HI::HI(int kht)
{
	size = kht;
	arr.resize(kht);
	neg = false;
}
HI::HI(string s)
{
	int i = 0;
	if (s[0] == '+' || s[0]=='-')
	{
		i = 1;
		size = s.length()-1 ;
		this->neg = false;
		if (s[0] == '-')
		{
			this->neg = true;
		}
	}
	else
	{
		size = s.length() ;
		this->neg = false;
	}
	
	for ( int j=i ; j<s.length(); j++)
	{
		arr.push_back((s[j]-48));
	}
}
HI::HI(const HI& s)
{
	arr = s.arr;
	size = s.size;
	neg = s.neg;
}
HI::HI(ifstream& rdr )
{
	string s;
	rdr >> s;
	*this = HI(s);
}

const HI HI::operator=(const HI& s)
{
	size = s.size;
	if (s.neg)
		this->neg = true;

	arr = s.arr;
	return *this;

}
const HI HI::operator=(int gt) 
{ 
	*this = HI(to_string(gt));
	return *this;
}

const HI HI::operator=(string s)
{
	int i = 0;
	if (s[0] == '+' || s[0] == '-')
	{
		i = 1;
		size = s.length() - 1;
		this->neg = false;
		if (s[0] == '-')
		{
			this->neg = true;
		}
	}
	else
	{
		size = s.length();
		this->neg = false;
	}

	for (int j = i; j < s.length(); j++)
	{
		arr.push_back((s[j] - 48));
	}
	this->trim();

	return *this;

}

HI HI::asg(string s)
{
	arr.resize(s.length());
	size = s.length();
	for (int i = 0; i < size; i++)
	{
		arr.push_back(s[i]);
	}
	return *this;

}

void HI::trim()
{
	this->rev();
	while (size>1 && arr[size-1] == 0)
	{
		arr.pop_back();
		size--;
	}
	this->rev();
}
void HI::rev()
{
	for (int i = 0; i < size/2; i++)
	{
		swap(arr[i], arr[size - 1 - i]);
	}
}


ostream& operator<< (ostream& Z_Kl, const HI& ght)
{
	cout << ((ght.neg==true) ? "-" : "+");
	for (int i = 0; i < ght.size; i++)
	{
		Z_Kl << ght.arr[i];
	}
	return Z_Kl;
}

istream& operator>>(istream& Z_Kl,  HI& ght)
{
	string s;
	Z_Kl >> s;
	HI gt(s);
	ght = gt;
	return Z_Kl;
}

const ofstream& operator<< (const ofstream& Z_Kl, const HI& gt)
{
	cout << ((gt.neg == true) ? "-" : "+");
	for (int i = 0; i < gt.size; i++)
	{
		Z_Kl << gt.arr[i];
	}
	return Z_Kl;
}

ifstream& operator>> (ifstream& Z_Kl, HI& ght)
{
	string s;
	Z_Kl >> s;
	HI gt(s);
	ght = gt;
	return Z_Kl;
}


const int HI::operator[](int ikj)const
{
	return (ikj < size && ikj >= 0) ? arr[ikj] : throw invalid_argument("LOGICAL ERROR AT ITS PEAK");
}
int& HI::operator[](int i)
{
	return (i< size && i >= 0) ? arr[i] : throw invalid_argument("LOGICAL ERROR AT ITS PEAK");
}

HI HI::Add_Qt(const HI& yt)const
{
	int c = 0;
	HI ght;
	ght.arr.assign(max(yt.size, size) + 1, 0);
	ght.size = max(yt.size, size)+1;
	int rt = ght.size-1,i=size-1,j=yt.size-1;
	while (rt >= 0)
	{
		int sum = 0;
		if (i >= 0)
			sum += arr[i--];
		if (j >= 0)
			sum += yt.arr[j--];

		sum += c;
		if (sum > 9)
		{

			ght[rt--] = sum % 10;
			c = 1;
		}
		else
		{
			ght[rt--] = sum;
			c = 0;
		}

	} 


    ght.trim();
	return ght;
}
HI HI::Sub_Qt(const HI& gt) const 
{
	HI jkl = gt;
	while (jkl.size < this->size)
	{
		jkl.arr.insert(jkl.arr.begin(), 0);
		jkl.size++;
	}
	for (int i = 0; i < jkl.size; i++) 
	{
		jkl.arr[i] = 9 - jkl.arr[i];
	}

	HI ty("1");
	jkl = jkl.Add_Qt(ty);
	if (jkl.size > this->size) ///if complement increaes size like 999  +1 =1000 discard 1
	{
		jkl.arr.erase(jkl.arr.begin());
		jkl.size--;
	}

	HI R = this->Add_Qt(jkl);
	if (R.size > this->size)
	{
		R.arr.erase(R.arr.begin());
		R.size--;
	}

	R.trim();
	return R;
}

const bool HI::operator==(const HI& gt)const
{
	if (neg != gt.neg)
		return false;

	return this->eql_Qt(gt);
	
}
const bool HI::operator!=(const HI& gt)const
{
	return !(*this == gt);
}

const bool HI::operator>=(const HI& gt)const
{
	return !(*this < gt) || *this==gt;
}

const bool HI::operator<=(const HI& gt)const
{
	return  *this < gt || *this == gt;
}

const bool HI::operator<(const HI& gt)const
{
	if (neg == false && gt.neg == true)
		return false;
	if (neg == true && gt.neg == false)
		return true;
	if(neg==gt.neg && neg==false)
	return this->less_Qt(gt);
	if (neg == gt.neg && neg == true)
		return gt.less_Qt(*this);
}

const bool HI::operator>(const HI& gt)const
{
	return gt < *this;

}


HI HI::operator-()
{
	HI R = *this;
	R.neg = !neg;
	return R;
}

HI HI::operator--(int d)
{
	HI ght("1");
	HI tt = *this;
	*this -= ght;
	return tt;


}
HI HI::operator--()
{
	HI ght("1");
	*this -= ght;
	return *this;
}
HI HI::operator++(int d)
{
	HI ght("1");
	HI tt = *this;
	*this += ght;
	return tt;
}
HI HI::operator++()
{
	HI ght("1");
	*this += ght;
	return *this;
}
HI HI::operator+(const HI&gt)const
{
	HI R;
	if (neg == gt.neg)
	{
		R = this->Add_Qt(gt);
		R.neg = neg;
	}
	else if (this->grt_Qt(gt))
	{
		R = this->Sub_Qt(gt);
		R.neg = neg;
	}
	else if (gt.grt_Qt(*this))
	{
		R = gt.Sub_Qt(*this);
		R.neg = gt.neg;
	}
	else
		return HI("0");


	return R;

}
HI HI::operator-(const HI& gt)const
{
	HI t= gt;
	t.neg = !gt.neg;
	return (*this + t);
}
HI& HI::operator+=(const HI& gt)
{
	*this = *this + gt;
	return *this;
}

HI& HI::operator-=(const HI& gt) 
{
	*this = *this - gt;
	return *this;
}


bool HI::less_Qt(const HI&gt)const
{
	if (size < gt.size)
		return true;
	if (size > gt.size)
		return false;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > gt.arr[i] )
			return false;
		 if (arr[i] < gt.arr[i])
			return true;
	}

	return false;
}
bool HI::grt_Qt(const HI&gt)const
{
	return !(this->less_Qt(gt)) && !(this->eql_Qt(gt));
}
bool HI::eql_Qt(const HI&gt)const
{
	if (size != gt.size)
		return false;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != gt.arr[i])
			return false;
	}

	return true;
}
HI HI::operator*(const HI&g5)const
{
	HI R=g5,C("1"), GC("1"), gty("0"),yk = *this;
	if (g5.neg == true)
		R.neg = false;
	if (neg == true)
		yk.neg = false;
	int i = 0;
	while (yk > HI("0"))
	{
		while (C + C <=yk)
		{
			R += R;
			C += C;
			i++;
			
		}
		yk -= C;
		gty += R;
		C = GC;
		R = g5;
		if (g5.neg == true)
			R.neg = false;
	}

	if (g5.neg == neg)
		gty.neg = false;
	else
		gty.neg = true;

	return gty;
}
HI HI::operator!()const
{
	HI R = *this;
	R.neg = false;
	return R;
}
HI HI::operator%(const HI&g5)const
{
	HI R = g5, C("1"), yk = *this;
	if (g5.neg == true)
		R.neg = false;
	if (neg == true)
		yk.neg = false;

	while (yk >= R)
	{
		while (R + R <= yk)
		{
			R += R;
			C += C;
		}
		yk -= R;
		R = g5;
		if (g5.neg == true)
			R.neg = false;
	}

	if (neg == g5.neg)
		yk.neg = false;
	else
	{
		if (neg == true)
			yk.neg = true;
		if (g5.neg == true)
			yk.neg = true;
	}
	return yk;

}
HI& HI::operator/=(const HI&gt)
{
	*this = *this / gt;
	return *this;
}
HI& HI::operator*=(const HI&gt)
{
	*this = *this * gt;
	return *this;
}
HI& HI::operator%=(const HI& gt)
{
	*this = *this % gt;
	return *this;
}


HI HI::operator/(const HI& g5)const
{
	HI R = g5, C("1"), GC("1"), gty("0"), yk = *this;
	if (g5.neg == true)
		R.neg = false;
	if (neg == true)
		yk.neg = false;
	while (yk >= g5)
	{
		while ( R+ R <= yk)
		{
			R += R;
			C += C;
		}
		yk -= R;
		gty += C;
		C = GC;
		R = g5;
		if (g5.neg == true)
			R.neg = false;
	}
	if (g5.neg == neg)
		gty.neg = false;
	else
		gty.neg = true;

	return gty;
}