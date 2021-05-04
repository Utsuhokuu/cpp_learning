#ifndef __MY_COMPLEX_H__
#define __MY_COMPLEX_H__

class complex
{
public:
	// 默认构造函数,非指针类不需要考虑Big Three 
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
	friend complex& __doami (complex *, const complex&);
	friend complex& __doaml (complex *, const complex&);
	friend complex& __doadi (complex *, const complex&);
};

inline complex&
__doapl(complex* ths, const complex& r)
{
	ths->re += r.re;
	ths->im += r.im;
	return *ths;
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
	return *ths;
}

inline complex& 
complex::operator -= (const complex& r)
{
	return __doami (this, r);
}

inline complex&
__doaml(complex* ths, const complex& r)
{
	double f = ths->re * r.re - ths->im * r.im;
	ths->im = ths->re * r.im + ths->im * r.re;
	ths->re = f; 
	return *ths;
}

inline complex& 
complex::operator *= (const complex& r)
{
	return __doaml (this, r);
}

inline complex&
__doadi(complex* ths, const complex& r)
{
	double g = (ths->im * r.re - ths->re * r.im) / (r.re * r.re + r.im * r.im);
	ths->re = (ths->re * r.re + ths->im * r.im) / (r.re * r.re + r.im * r.im);
	ths->im = g; 
	return *ths;
}

inline complex& 
complex::operator /= (const complex& r)
{
	return __doadi (this, r);
}

inline double
imag (const complex& x)
{
	return x.imag ();
}

inline double
real (const complex& x)
{
	return x.real ();
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

inline complex
operator + (const complex& x)
{
	return x;
}

inline complex
operator - (const complex& x, const complex& y)
{
	return complex (real (x) - real (y), imag (x) - imag (y));
}

inline complex
operator - (const complex& x, double y)
{
	return complex (real (x) - y, imag (x));
}

inline complex
operator - (double x, const complex& y)
{
	return complex (x - real (y), - imag (y));
}

inline complex
operator - (const complex& x)
{
	return complex (-real (x), -imag (x));
}

inline complex
operator * (const complex& x, const complex& y)
{
	return complex (real (x) * real (y) - imag (x) * imag (y),
				 real (x) * imag (y) + imag (x) * real (y));
}

inline complex
operator * (const complex& x, double y)
{
	return complex (real (x) * y, imag (x) * y);
}

inline complex
operator * (double x, const complex& y)
{
	return complex (x * real (y), x * imag (y));
}

inline complex
operator / (const complex& x, const complex& y)
{
	return complex ((real (x) * real (y) + imag (x) * imag (y)) / (real (y) * real (y) + imag (y) * imag(y)),
				 (imag (x) * real (y) - real (x) * imag (y)) / (imag (x) * imag (x) + imag (y) * imag(y)));
}

inline complex
operator / (const complex& x, double y)
{
	return complex (real (x) / y, imag (x) / y);
}

inline complex
operator / (double x, const complex& y)
{
	return complex ((x * real (y)) / (real (y) * real (y) + imag (y) * imag(y)),
				 (-(x * imag (y)) / (real (y) * real (y) + imag (y) * imag(y))));
}

inline bool
operator == (const complex& x, const complex& y)
{
	return real(x) == real (y) && imag (x) == imag (y); 
}

inline bool
operator == (const complex& x, double y)
{
	return real(x) == y && imag (x) == 0; 
}

inline bool
operator == (double x, const complex& y)
{
	return x == real (y) && imag (y) == 0; 
}

inline bool
operator != (const complex& x, const complex& y)
{
	return real(x) != real (y) || imag (x) != imag (y); 
}

inline bool
operator != (const complex& x, double y)
{
	return real(x) != y || imag (x) != 0; 
}

inline bool
operator != (double x, const complex& y)
{
	return x != real (y) || imag (y) != 0; 
}

#include <cmath>

inline complex
polar (double r, double t)
{
	return complex (r * cos (t), r * sin (t));
}

inline complex
conj (const complex& x)
{
	return complex (real (x), -imag (x));
}

inline double
norm (const complex& x)
{
	return real (x) * real (x) + imag (x) * imag (x);
}

#endif  //__MY_COMPLEX_H__
