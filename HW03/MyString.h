#pragma once
#include<iostream>
using namespace std;

class MyString
{
private:
	char* string_;
	int length_;
public:
	int length() const;
	int KCharLength(const char* str);
	const char* insert(int pos, const char* newStr);
	const char* erase(int pos, int num);
	const char* replace(int pos, int num, const char* str);
	bool find(int pos, const char* str);
	const char* subString(int pos, int num);
	const char* operator+(const MyString& other);
	friend istream& operator >> (istream& input, MyString& str)
	{
		cout << "Enter the length of the string: ";
		input >> str.length_;
		str.string_ = new char[str.length_ + 1];
		cout << "Enter the string: ";
		input >> str.string_;
		return input;
	}
	friend ostream& operator <<(ostream& output, const MyString& str)
	{
		return output << str.string_;
	}
};

