#include "Header.h"
#include<string>
void main() 
{
	MyString a;
	a = "0123456789";
	MyString b = "abcdef";
//	a.resize(8);
	a.insert(5,"huhu");
	cout << a;
	system("pause");
}