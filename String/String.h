#ifndef __MY_STRING_H__
#define __MY_STRING_H__

class String 
{
public:
	String(const char* cstr = 0); // Ĭ�Ϲ��캯�� 
	String(const String& str); // �������캯�� 
	String& operator=(const String& str); //������ֵ�����
	~String(); // �������� 
	char* get_c_str() const { return m_data; }
private:
	char* m_data;
};

#include <cstring> 
// ���캯��
inline 
String::String(const char* cstr)
{
	if (cstr) {
		m_data = new char[strlen(cstr) + 1]; // +1�������ַ�����β��'/0'������ 
		strcpy(m_data, cstr);
	}
	else { //δָ����ֵ 
		m_data = new char[1];
		*m_data = '\0';
	}
}

// �������� 
inline 
String::~String()
{
	delete[] m_data; //�������array deleta��ԭ�������湹�캯��ʹ����array new 
}

// �������� 
inline 
String::String(const String& str)
{
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);
}

// ������ֵ 
inline
String& String::operator=(const String& str) //�˴�'&'Ϊ���÷��� 
{
	if (this == &str) // �ж��Ƿ����Ҹ�ֵ���˴�'&'Ϊȡ��ַ�� 
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

#endif
