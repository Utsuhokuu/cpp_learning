#ifndef __MY_STRING_H__
#define __MY_STRING_H__

class String 
{
public:
	String(const char* cstr = 0); // 默认构造函数 
	String(const String& str); // 拷贝构造函数 
	String& operator=(const String& str); //拷贝赋值运算符
	~String(); // 析构函数 
	char* get_c_str() const { return m_data; }
private:
	char* m_data;
};

#include <cstring> 
// 构造函数
inline 
String::String(const char* cstr)
{
	if (cstr) {
		m_data = new char[strlen(cstr) + 1]; // +1考虑了字符串结尾的'/0'结束符 
		strcpy(m_data, cstr);
	}
	else { //未指定初值 
		m_data = new char[1];
		*m_data = '\0';
	}
}

// 析构函数 
inline 
String::~String()
{
	delete[] m_data; //这里采用array deleta的原因是上面构造函数使用了array new 
}

// 拷贝构造 
inline 
String::String(const String& str)
{
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);
}

// 拷贝赋值 
inline
String& String::operator=(const String& str) //此处'&'为引用符号 
{
	if (this == &str) // 判断是否自我赋值，此处'&'为取地址符 
		return *this;
	
	delete[] m_data;
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);
	return *this;
}

#include <iostream>
using namespace std;

ostream& operator << (ostream& os, const String& str)
{
	os << str.get_c_str();
	return os;	
} 

#endif // __MY_STRING_H__ 
