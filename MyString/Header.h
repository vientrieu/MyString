#ifndef __HEADER_H__
#define __HEADER_H__
#include <iostream>
using namespace std;
#include<string>
class MyString
{
private:
	char*Chuoi;
	size_t DoDai;
public:
	MyString();
	MyString(const MyString&Data);
	MyString(const MyString&Data,size_t n);
	MyString(const MyString&Data,size_t ViTri,size_t n);
	MyString(const char*Data);
	MyString(size_t n, char c);
	~MyString();
	friend ostream& operator<<(ostream& os, MyString&Data);
	friend istream& operator>>(istream& is, MyString&Data);
	MyString& operator=(const MyString&Data);
	MyString& operator=(const char*Data);
	MyString& operator=(char c);
	size_t size();
	size_t length();
	//max_size();
	void resize(size_t n, char c);
	void resize(size_t n);
	size_t capacity();
	void reserve(size_t n);
	void clear();
	bool empty();
	void shrink_to_fit();
	char& operator[] (size_t pos);
	char& at(size_t pos);
	char& back();
	char& front();
	MyString& operator+= (const MyString&Data);
	MyString& operator+= (const char*Data);
	MyString& operator+= (char c);
	MyString& append(const MyString&Data);
	MyString& append(const MyString&Data, size_t subpos, size_t sublen);
	MyString& append(const char*Data);
	MyString& append(const char*Data, size_t n);
	MyString& append(size_t n, char c);
	void push_back(char c);
	MyString& assign(const MyString &Data);
	MyString& assign(const MyString &Data, size_t subpos, size_t sublen);
	MyString& assign(const char*Data);
	MyString& assign(const char*Data, size_t n);
	MyString& assign(size_t n, char c);
	MyString& insert(size_t pos, const MyString&Data);
	MyString& insert(size_t pos, const MyString&Data, size_t subpos, size_t sublen);
	MyString& insert(size_t pos, const char*Data);
	//MyString& insert(size_t pos, const char*Data, size_t n);
	//MyString& insert(size_t pos, size_t n, char c);
	/*void insert(iterator p, size_t n, char c);*/
};
#endif

