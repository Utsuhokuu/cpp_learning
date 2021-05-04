#ifndef __SALES_DATA_H__ 
#define __SALES_DATA_H__
#include <string>
#include <iostream>

class Sales_data {
//ΪSales_data�ķǳ�Ա������������Ԫ����	
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);

public:	
	Sales_data() = dafault;//Ĭ�Ϲ��캯�� 
	//���캯����ʼ��
	Sales_data(const std::string &s): 
			   bookNo(s), units_sold(0), revenue(0) { }
	Sales_data(const std::string &s, unsigned cnt, double rev):
			   bookNo(s), units_solds(cnt), revenue(rev*cnt){ }
	// ����read������ʼ�����캯�� 
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

// Sales_data�ķǳ�Ա�ӿ� 
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

inline
Sales_data& Sales_data::combine(const Sales_data &rhs) {
	units_sold += rhs.units_sold; // ��rhs�ĳ�Ա�ӵ�this����ĳ�Ա��
	revenue += rhs.revenue;
	return *this;
} 

// read��������is�ж�ȡһ��������ϢȻ�����item������ 
inline
istream &read(istream &is, Sales_data &item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

// print��������item�е���Ϣͨ��os��ӡ���� 
inline
ostream &print(ostream &os, const Sales_data &item) {
	os << item.isbn() << " " << item.units_sold << " "
	   << item.revenue << " " << item.avg_price();
	return os;
}

// add����������lhs��rhs����Sales_data���󣬲��ҷ��ظ���������ĺ� 
Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}// ���ڷ���local data���ʷ���������value������reference
  
Sales_data::Sales_data(std::istream &is) {
	read(is, *this);
}
 
 

#endif // __SALES_DATA_H__ 
