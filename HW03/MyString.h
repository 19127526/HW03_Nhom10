#pragma once
#include<iostream>
using namespace std;

class MyString
{
private:
	char* string_;
	int length_;
public:
	int length() const
	{
		return length_;
	}
	int KCharLength(const char* str)
	{
		int i;
		for (i = 0; str[i] != '\0'; i++);
		return i;
	}
	const char* insert(int pos, const char* newStr)
	{
		int new_length = length_ + KCharLength(newStr);
		char* str = new char[new_length + 1];
	/*	int i = 0;
		for (i = 0; i < pos; i++)
			str[i] = string_[i];
		for (i = 0; i < KCharLength(newStr); i++)
			str[i + pos] = newStr[i];
		for (i = pos+ KCharLength(newStr); i < length_; i++)
			str[i] = string_[i];
		str[new_length] = '\0';
		delete string_;
		string_ = str;
		length_ = new_length;
		return string_;*/
		/*int k = 0;
		for (int j = pos;j < KCharLength(newStr);j++)
		{
			str[j] = newStr[k];
			k++;
		}*/
		for (int i = 0;i < pos;i++)
		{
			str[i] = string_[i];
		}
		str[pos] = newStr[0];
		int k = pos;
		for (int j = pos + 1;j < new_length;j++)
		{
			str[j] = string_[k];
			k++;
		}
		str[new_length] = '\0';
		return str;

	}
	const char* erase(int pos, int num)
	{
		//char* str = new char];
		char* str = new char[3];
		int k = 0;
		for (int i = num; i < length_; i++)
		{
			str[k] = string_[i];
			k++;
		}
		str[k ] = '\0';
		//cout << "llo";
		return str;
	}
	const char* replace(int pos, const char* str)
	{
		int i;
		for (int i = 0; i < KCharLength(str); i++)
		{
			string_[pos + i] = str[i];
			if (string_[i] == 'l')
			{
				string_[i + 1] = 'l';
				string_[i + 2] = 'o';
				break;
			}
		}
		return string_;
	}
	bool find(int pos, const char* str)
	{
		for (int i = 0; i < KCharLength(str); i++) 
		{
			if (string_[i+pos] != str[i])
			{
				return false;
			}
		}
		return true;
	}
	const char* subString(int pos, int num)
	{
		char* subStr = new char[num+1];
		for (int i = 0; i < num + 1; i++)
			subStr[i] = string_[i + pos];
		subStr[num] = '\0';
		return subStr;
	}
	const char* operator+(const MyString& other)
	{
		int new_length = length_ + other.length();
		char* str = new char[new_length + 1];
		int i;
		for (i = 0; i < length(); i++)
			str[i] = string_[i];
		for (i = 0 ;i < other.length();i++)
			str[i+length_] = other.string_[i];
		str[new_length] = '\0';
		return str;
	}
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

