#ifndef __SALES_DATA_H__ 
#define __SALES_DATA_H__
#include <string>
#include <iostream>

class Sales_data {
//为Sales_data的非成员函数所做的友元声明	
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);

public:	
	Sales_data() = dafault;//默认构造函数 
	//构造函数初始化
	Sales_data(const std::string &s): 
			   bookNo(s), units_sold(0), revenue(0) { }
	Sales_data(const std::string &s, unsigned cnt, double rev):
			   bookNo(s), units_solds(cnt), revenue(rev*cnt){ }
	// 调用read函数初始化构造函数 
	Sales_data(std::istream &);
		
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	
private:	
	double avg_price() const
		{ return units_sold ? revenue/units_sold : 0; }
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

// Sales_data的非成员接口 
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

inline
Sales_data& Sales_data::combine(const Sales_data &rhs) {
	units_sold += rhs.units_sold; // 把rhs的成员加到this对象的成员上
	revenue += rhs.revenue;
	return *this;
} 

// read函数：从is中读取一条交易信息然后存入item对象当中 
inline
istream &read(istream &is, Sales_data &item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

// print函数：将item中的信息通过os打印出来 
inline
ostream &print(ostream &os, const Sales_data &item) {
	os << item.isbn() << " " << item.units_sold << " "
	   << item.revenue << " " << item.avg_price();
	return os;
}

// add函数：接收lhs与rhs两个Sales_data对象，并且返回该两个对象的和 
Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}// 由于返回local data，故返回类型是value而不是reference
  
Sales_data::Sales_data(std::istream &is) {
	read(is, *this);
}
 
 

#endif // __SALES_DATA_H__ 
