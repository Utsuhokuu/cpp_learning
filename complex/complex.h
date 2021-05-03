#ifndef __MY_COMPLEX_H__
#define __MY_COMPLEX_H__

class complex
{
public:
	complex (double r = 0, double i = 0):  re (r), im (i) { }
	complex& operator += (const complex&);
	complex& operator -= (const complex&);
 	complex& operator *= (const complex&);
	complex& operator /= (const complex&);
	double real () const { return re; }
	double imag () const { return im; }

private:
	double re, im;
	
	friend complex& __doapl (complex *, const complex&);
};

inline complex&
__doapl(complex* ths, const complex& r)
{
	ths->re += r.re;
	ths->im += r.im;
	return *ths
}

inline complex& 
complex::operator += (const complex& r)
{
	return __doapl (this, r);
}

inline complex&
__doami(complex* ths, const complex& r)
{
	ths->re -= r.re;
	ths->im -= r.im;
	return *ths
}

inline complex& 
complex::operator -= (const complex& r)
{
	return __doami (this, r);
}



inline complex&
__doaml(complex* ths, const complex& r)
{
	ths->re *= r.re;
	ths->im *= r.im;
	return *ths
}

inline complex&
__doaml(complex* ths, const complex& r)
{
	double f = 0.0;
	f = ths->re + r.re;
	ths->im -= r.im;
	return *ths
}

inline complex& 
complex::operator *= (const complex& r)
{
	return __doaml (this, r);
}




//把+操作符定义在类外，使得类可以应付复数加实数的情况，对- * /,同理 
inline complex
operator + (const complex& x, const complex& y)
{
	return complex (real (x) + real (y), imag (x) + imag (y));//local object
}

inline complex
operator + (const complex& x, double y)
{
	return complex (real (x) + y, imag (x));
}

inline complex
operator + (double x, const complex& y)
{
	return complex (x + real (y), imag (y));
}

#include <iostream>
ostream&
operator << (ostream& os, const complex& x)
{
	return os << '(' << real (x) << ',' << imag (x) << ')';
} 


#endif
