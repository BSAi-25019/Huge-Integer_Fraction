#include "BSAI25019_Fraction.h"



Fraction::Fraction()
{
	w.asg("0");
	d.asg("1");
	n.asg("0");

}

Fraction::Fraction(HI wl,HI nm, HI dm)
{
	d = dm;
	n = nm;
	w = wl;

}
Fraction::Fraction(const Fraction& F)
{
	this->d = F.d;
	this->w = F.w;
	this->n = F.n;
}

void Fraction::toNormalFraction()
{
		if (w != HI("0"))
		{
			n = w * d + n; 
			w = HI("0");
		}
}
void Fraction::toImproperFraction()
{
	if (w == HI("0") && (!n) > d)
	{
		w = n / d;
		n = n - (w * d);
	}
}

void Fraction::simplify()
{
	HI g = gcd(!n, !d);
	if (g != HI("1"))
	{
		n = n / g;
		d = d / g;
	}
	if (d<HI("0"))
	{
		n = -n;
		d = -d;
	}


}


Fraction Fraction::operator+(const Fraction& F)
{
	Fraction R = *this; 
	R.toNormalFraction();
	Fraction t = F;
	t.toNormalFraction();
	HI C = gcd(!R.d, !t.d);

	Fraction y;
	y.d = (R.d / C) * t.d;
	HI k = (y.d / R.d) * R.n;
	HI k1 = (y.d / t.d) * t.n;
	y.n = k + k1;

	y.simplify();
	y.toImproperFraction();
	return y;
}

Fraction Fraction::operator-(const Fraction& F)
{
	Fraction R(w, n, d);
	R.toNormalFraction();
	/*R.simplify();*/

	Fraction t(F.w, F.n, F.d);
	t.toNormalFraction();
	Fraction y;
	Fraction e(*this);
	HI k = t.d * R.n, k1 = R.d * t.n;
	y.n = k - k1;
	y.d = R.d * t.d;
	y.simplify();
	y.toImproperFraction();
	return y;
}
Fraction Fraction::operator*(const Fraction& F)
{
	Fraction R(w, n, d);
	R.toNormalFraction();
	/*R.simplify();*/

	Fraction t(F.w, F.n, F.d);
	t.toNormalFraction();
	Fraction y;
	y.n = R.n * t.n;
	y.d = R.d * t.d;
	y.simplify();
	y.toImproperFraction();
	return y;
}

Fraction Fraction::operator/(const Fraction& F)
{
	Fraction R(w, n, d);
	R.toNormalFraction();
	/*R.simplify();*/

	Fraction t(F.w, F.n, F.d);
	t.toNormalFraction();
	Fraction y;
	y.n = R.n * t.d;
	y.d = R.d * t.n;
	y.simplify();
	y.toImproperFraction();
	return y;
}

void Fraction::print() const
{
	///if (w == n && w < HI("0"))
		///cout << "-";
	
	if (!n==!d)
	{
		cout << n ;
	}
	else if (w == HI("0") && n != HI("0"))
		{
			cout << n << "/" << d;
		}
	else if (n == HI("0"))
		{
			cout <<w;
		}
	else
		{
			cout << "(" << !w << ") " << !n << "/" << !d;
		}
}

HI Fraction::getWhole()const
{
	return w;
}
HI Fraction::getNumerator()const
{
	return n;
}
HI Fraction::getDenominator()const
{
	return d;
}
void Fraction::setwhole(HI e)
{
	this->w = e;
}
void Fraction::setNumt(HI e)
{
	this->n = e;
}
void Fraction::setdenomt(HI e)
{
	this->d = e;
}

Fraction Fraction::operator+=(const Fraction& F)
{
	return *this + F;
}
Fraction Fraction::operator-=(const Fraction& F)
{
	return *this - F;

}
Fraction Fraction::operator/=(const Fraction& F)
{
	return *this / F;
}
Fraction Fraction::operator*=(const Fraction& F)
{

	return *this * F;
}
 bool Fraction::operator==(const Fraction& F)
{
	 Fraction t = *this, G = F;
	 t.toNormalFraction();
	 G.toNormalFraction();
	 return ((t.n * G.d) == (t.d * G.n));
}
bool Fraction::operator!=(const Fraction& F)
{
	return !(*this==F);
}
bool Fraction::operator<(const Fraction& F)
{
	Fraction t = *this, G = F;
	t.toNormalFraction();
	G.toNormalFraction();
	return ((t.n * G.d) < (t.d * G.n));
}
bool Fraction::operator<=(const Fraction& F)
{
	return (*this<F || *this==F);
}
bool Fraction::operator>(const Fraction& F)
{
	return !(*this < F);
}
bool Fraction::operator>=(const Fraction& F)
{
	return (*this>F || *this==F);
}
Fraction Fraction::operator-()
{
	Fraction t = *this;
	if(t.n!=HI("0"))
	-t.n;
	return t;
}
Fraction Fraction::operator=(const Fraction& F)
{

	this->d = F.d;
	this->w = F.w;
	this->n = F.n;
	return *this;

}


istream& operator>>(istream& in, Fraction& f) 
{
	string s;
	if (!(in >> s))
		return in;

	string N = "", Recd = "", D = "";
	int dot = -1, pp = -1, st = 0;
	bool isNeg = false; 

	if (s[0] == '-') 
	{
		isNeg = true;
		st = 1;
	}

	for (int i = st; i < s.length(); i++)
	{
		if (s[i] == '.') 
			dot = i;
		else if (s[i] == '(')
		{
			pp = i;
			Recd = N;
		}
		else if (s[i] == ')') 
			continue;
		else
			N += s[i];
	}

	///SImple caase
	if (pp == -1) 
	{
		f.n = HI(N);
		D = "1";
		if (dot != -1)
		{
			int ct = (s.length() - 1) - dot;

			for (int i = 0; i < ct; i++)
				D += '0';
		}
	}
	else 
	{
		///parethesis case
		if (Recd == "")
			Recd = "0";
		if (N == "")
			N = "0";

		///Numerater builfing
		f.n = HI(N) - HI(Recd);

		///Denominator hundered
		int rdl = (s.length() - 1) - pp - 1, nrdl = 0;
		if (dot != -1) 
		{
			nrdl = pp - dot - 1;
		}

		for (int i = 0; i < rdl; i++)
			D += '9';

		for (int i = 0; i < nrdl; i++)
			D += '0';
	}

	f.d = HI(D);
	if (isNeg) f.n = -f.n;///sign case
	f.n.trim();
	f.w = HI("0");
	f.simplify(); 
	f.toImproperFraction();

	return in;
}


ostream& operator<<(ostream& out, const Fraction& f)
{
	f.print();
	return out;
 }