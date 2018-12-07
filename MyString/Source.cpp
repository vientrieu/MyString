#include"Header.h"
MyString::MyString()
{
	Chuoi = new char;
	Chuoi[0] = '\0';
	DoDai = 0;
}
MyString::MyString(const MyString&Data)
{
	DoDai = Data.DoDai;
	Chuoi = new char[DoDai + 1];
	for (int i = 0; i < DoDai; i++)
		Chuoi[i] = Data.Chuoi[i];
	Chuoi[DoDai] = '\0';
}
MyString::MyString(const MyString & Data, size_t n)
{
	DoDai = n;
	Chuoi = new char[n + 1];
	for (int i = 0; i <= DoDai; i++)
		Chuoi[i] = Data.Chuoi[i];
	Chuoi[DoDai] = '\0';
}
MyString::MyString(const MyString & Data, size_t ViTri, size_t n)
{
	DoDai = n;
	Chuoi = new char[n + 1];
	for (int i = 0; i < n; i++)
		Chuoi[i] = Data.Chuoi[i+ViTri];
	Chuoi[n] = '\0';
}
MyString::MyString(const char*Data)
{
	int length = 0;
	while (Data[length] != '\0')
		length++;
	DoDai = length;
	Chuoi= new char[DoDai+1];
	for (int i = 0; i < DoDai; i++)
		Chuoi[i] = Data[i];
	Chuoi[DoDai] = '\0';
}
MyString::MyString(size_t n, char c)
{
	DoDai = n;
	for (int i = 0; i < DoDai; i++) Chuoi[i] = c;
}
MyString::~MyString()
{
	if (Chuoi != NULL)
	{
		delete[]Chuoi;
		DoDai = 0;
	}
}
ostream& operator<<(ostream& os, MyString&Data)
{
	os << Data.Chuoi;
	return os;
}
istream& operator>>(istream& is, MyString&Data)
{
	char temp[256];
	int length = 0;
	is >> temp;
	Data.~MyString();
	Data = temp;
	return is;
}
MyString& MyString::operator=(const MyString&Data)
{
	DoDai = Data.DoDai;
	Chuoi = new char[DoDai + 1];
	for (int i = 0; i <= DoDai; i++)
		Chuoi[i] = Data.Chuoi[i];
	Chuoi[DoDai] = '\0';
	return *this;
}
MyString& MyString::operator=(const char*Data)
{
	int length = 0;
	while (Data[length] != '\0')
		length++;
	DoDai = length;
	Chuoi = new char[DoDai + 1];
	for (int i = 0; i < DoDai; i++)
		Chuoi[i] = Data[i];
	Chuoi[DoDai] = '\0';
	return *this;
}
MyString & MyString::operator=(char c)
{
	DoDai = 1;
	Chuoi = new char[2];
	Chuoi[0] = c;
	Chuoi[1] = '\0';
	return *this;
}
size_t MyString::size()
{
	return DoDai;
}
size_t MyString::length()
{
	return DoDai;
}
void MyString::resize(size_t n, char c)
{
	if (n >= 0)
	{
		if (n < DoDai)
		{
			char*temp = new char[n + 1];
			for (int i = 0; i < n; i++)
			{
				temp[i] = Chuoi[i];
			}
			temp[n] = '\0';
			delete[]Chuoi;
			Chuoi = temp;
			DoDai = n;
		}
		else if (n > DoDai)
		{
			char*temp = new char[n + 1];
			for (int i = 0; i < DoDai; i++)
			{
				temp[i] = Chuoi[i];
			}
			for (int i = DoDai; i < n; i++)
			{
				temp[i] = c;
			}
			temp[n] = '\0';
			delete[]Chuoi;
			Chuoi = temp;
			DoDai = n;
		}
		else return;
	}
	else return;
}
void MyString::resize(size_t n)
{
	if (n >= 0)
	{
		if (n < DoDai)
		{
			char*temp = new char[n + 1];
			for (int i = 0; i < n; i++)
			{
				temp[i] = Chuoi[i];
			}
			temp[n] = '\0';
			delete[]Chuoi;
			Chuoi = temp;
			DoDai = n;
		}
		else if (n > DoDai)
		{
			char*temp = new char[n + 1];
			for (int i = 0; i < DoDai; i++)
			{
				temp[i] = Chuoi[i];
			}
			for (int i = DoDai; i < n; i++)
			{
				temp[i] = NULL;
			}
			temp[n] = '\0';
			delete[]Chuoi;
			Chuoi = temp;
			DoDai = n;
		}
		else return;
	}
	else return;
}
size_t MyString::capacity()
{
	int i = 0;
	while (Chuoi[i] != NULL)
	{
		i++;
	}
	return i;
}
void MyString::reserve(size_t n)
{
	if (n > DoDai)
	{
		char*temp = new char[n + 1];
		for (int i = 0; i < DoDai; i++)
		{
			temp[i] = Chuoi[i];
		}
		temp[DoDai] = '\0';
		delete[]Chuoi;
		Chuoi = temp;
	}
}
void MyString::clear()
{
	for (int i = 0; i <= DoDai; i++)
	{
		Chuoi[i] = NULL;
	}
	Chuoi[0] = '\0';
	DoDai = 0;
}
bool MyString::empty()
{
	if (DoDai == 0) return true;
	return false;
}
void MyString::shrink_to_fit()
{
	char*temp = new char[DoDai+1];
	for (int i = 0; i < DoDai; i++)
	{
		temp[i] = Chuoi[i];
	}
	temp[DoDai] = '\0';
	delete[]Chuoi;
	Chuoi = temp;
}

char& MyString::operator[](size_t pos)
{
	if (pos < 0 || pos >= DoDai)
		throw;
	else return Chuoi[pos];
}

char & MyString::at(size_t pos)
{
	if (pos < 0 || pos >= DoDai)
		throw;
	else return Chuoi[pos];
}

char & MyString::back()
{
	return Chuoi[0];
}

char & MyString::front()
{
	return Chuoi[DoDai - 1];
}

MyString& MyString::operator+=(const MyString & Data)
{
	size_t newDoDai = DoDai + Data.DoDai;
	char*temp = new char[newDoDai+1];
	for (int i = 0; i < DoDai; i++)
	{
		temp[i] = Chuoi[i];
	}
	for (int i = 0; i < Data.DoDai; i++)
	{
		temp[DoDai+i] = Data.Chuoi[i];
	}
	temp[newDoDai] = '\0';
	delete[]Chuoi;
	Chuoi = temp;
	DoDai = newDoDai;
	return *this;
}

MyString & MyString::operator+=(const char * Data)
{
	int length = 0;
	while (Data[length] != '\0')
		length++;
	int newDoDai = DoDai + length;
	char*temp = new char[newDoDai + 1];
	for (int i = 0; i < DoDai; i++)
	{
		temp[i] = Chuoi[i];
	}
	for (int i = 0; i < length; i++)
	{
		temp[DoDai + i] = Data[i];
	}
	temp[newDoDai] = '\0';
	delete[]Chuoi;
	Chuoi = temp;
	DoDai = newDoDai;
	return *this;
}

MyString & MyString::operator+=(char c)
{
	char*temp = new char[DoDai + 2];
	for(int i = 0; i < DoDai; i++)
	{
		temp[i] = Chuoi[i];
	}
	DoDai=DoDai+1;
	temp[DoDai] = c;
	temp[DoDai + 1] = '\0';
	return *this;
}

MyString & MyString::append(const MyString & Data)
{
	size_t newDoDai = DoDai + Data.DoDai;
	char*temp = new char[newDoDai + 1];
	for (int i = 0; i < DoDai; i++)
	{
		temp[i] = Chuoi[i];
	}
	for (int i = 0; i < Data.DoDai; i++)
	{
		temp[DoDai + i] = Data.Chuoi[i];
	}
	temp[newDoDai] = '\0';
	delete[]Chuoi;
	Chuoi = temp;
	DoDai = newDoDai;
	return *this;
}

MyString & MyString::append(const MyString & Data, size_t subpos, size_t sublen)
{
	if (subpos<0||subpos >= Data.DoDai) throw;
	else
	{
		int newDoDai;
		int p = subpos + sublen;
		if (p > Data.DoDai) newDoDai = DoDai + Data.DoDai-subpos;
		else newDoDai = DoDai + sublen;
		char*temp = new char[newDoDai + 1];
		for (int i = 0; i < DoDai; i++)
		{
			temp[i] = Chuoi[i];
		}
		for (int i = 0; i < newDoDai-DoDai; i++)
		{
			temp[DoDai + i] = Data.Chuoi[subpos+i];
		}
		temp[newDoDai] = '\0';
		delete[]Chuoi;
		Chuoi = temp;
		DoDai = newDoDai;
		return *this;
	}
}

MyString & MyString::append(const char * Data)
{
	int length = 0;
	while (Data[length] != '\0')
		length++;
	int newDoDai = DoDai + length;
	char*temp = new char[newDoDai + 1];
	for (int i = 0; i < DoDai; i++)
	{
		temp[i] = Chuoi[i];
	}
	for (int i = 0; i < length; i++)
	{
		temp[DoDai + i] = Data[i];
	}
	temp[newDoDai] = '\0';
	delete[]Chuoi;
	Chuoi = temp;
	DoDai = newDoDai;
	return *this;
}

MyString & MyString::append(const char * Data, size_t n)
{
	if (n < 0) throw;
	else if (n == 0) return *this;
	else
	{
		int length = 0;
		while (Data[length] != '\0')
			length++;
		int newDoDai = DoDai + n;
		char*temp = new char[newDoDai + 1];
		for (int i = 0; i < DoDai; i++)
		{
			temp[i] = Chuoi[i];
		}
		for (int i = 0; i < length; i++)
		{
			temp[DoDai + i] = Data[i];
		}
		temp[newDoDai] = '\0';
		delete[]Chuoi;
		Chuoi = temp;
		DoDai = newDoDai;
		return *this;
	}
}

MyString & MyString::append(size_t n, char c)
{
	if (n < 0)throw;
	else if (n == 0) return *this;
	else
	{
		int newDoDai = DoDai + n;
		char*temp = new char[newDoDai + 1];
		for (int i = 0; i < DoDai; i++)
		{
			temp[i] = Chuoi[i];
		}
		for (int i = 0; i < n; i++)
		{
			temp[DoDai + i] = c;
		}
		temp[newDoDai] = '\0';
		delete[]Chuoi;
		Chuoi = temp;
		DoDai = newDoDai;
		return *this;
	}
}

void MyString::push_back(char c)
{
	char*temp = new char[DoDai + 2];
	for (int i = 0; i < DoDai ;i++)
	{
		temp[i] = Chuoi[i];
	}
	temp[DoDai] = c;
	DoDai = DoDai + 1;
	temp[DoDai] = '\0';
}

MyString & MyString::assign(const MyString & Data)
{
	delete[]Chuoi;
	DoDai = Data.DoDai;
	Chuoi = new char[DoDai + 1];
	for (int i = 0; i < DoDai; i++)
		Chuoi[i] = Data.Chuoi[i];
	Chuoi[DoDai] = '\0';
	return *this;
}

MyString & MyString::assign(const MyString & Data, size_t subpos, size_t sublen)
{
	if (subpos < 0 || subpos >= Data.DoDai) throw;
	else
	{
		delete[]Chuoi;
		int p = subpos + sublen;
		if (p > Data.DoDai) DoDai = Data.DoDai-subpos;
		else DoDai = sublen;
		Chuoi = new char[DoDai + 1];
		for (int i = 0; i < DoDai; i++)
		{
			Chuoi[i] = Data.Chuoi[subpos + i];
		}
		Chuoi[DoDai] = '\0';
		return *this;
	}
}

MyString & MyString::assign(const char * Data)
{
	int length = 0;
	while (Data[length] != '\0')
		length++;
	DoDai = length;
	delete[]Chuoi;
	Chuoi = new char[DoDai + 1];
	for (int i = 0; i < DoDai; i++)
	{
		Chuoi[i] = Data[i];
	}
	Chuoi[DoDai] = '\0';
	return *this;
}

MyString & MyString::assign(const char * Data, size_t n)
{
	if (n < 0) throw;
	else
	{
		int length = 0;
		while (Data[length] != '\0')
			length++;
		if (n > length) DoDai = length;
		else DoDai = n;
		delete[]Chuoi;
		Chuoi = new char[DoDai + 1];
		for (int i = 0; i < DoDai; i++)
		{
			Chuoi[i] = Data[i];
		}
		Chuoi[DoDai] = '\0';
		return *this;
	}
}
MyString & MyString::assign(size_t n, char c)
{
	delete[]Chuoi;
	Chuoi = new char[n + 1];
	for (int i = 0; i < n; i++)
		Chuoi[i] = c;
	Chuoi[n] = '\0';
	return *this;
}

MyString & MyString::insert(size_t pos, const MyString & Data)
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		size_t newDoDai = DoDai + Data.DoDai;
		int p = pos + Data.DoDai;
		char*temp = new char[newDoDai + 1];
		for (int i = 0; i < pos; i++)
		{
			temp[i] = Chuoi[i];
		}
		for (int i = 0; i < Data.DoDai; i++)
		{
			temp[pos + i] = Data.Chuoi[i];
		}
		for (int i = 0; i < DoDai - pos; i++)
		{
			temp[p + i] = Chuoi[pos + i];
		}
		temp[newDoDai] = '\0';
		delete[]Chuoi;
		Chuoi = temp;
		DoDai = newDoDai;
		return *this;
	}
}

MyString & MyString::insert(size_t pos, const MyString & Data, size_t subpos, size_t sublen)
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		if (subpos < 0 || subpos >= Data.DoDai) throw;
		else
		{
			size_t newDoDai;
			int q = subpos + sublen, p;
			if (q > Data.DoDai)
			{
				p = pos + Data.DoDai - subpos;
				newDoDai = DoDai + Data.DoDai - subpos;
			}
			else
			{
				p = pos + sublen;
				newDoDai = DoDai + sublen;
			}
			char *temp = new char[newDoDai + 1];
			for (int i = 0; i < pos; i++)
			{
				temp[i] = Chuoi[i];
			}
			for (int i = 0; i < newDoDai - DoDai; i++)
			{
				temp[pos + i] = Data.Chuoi[subpos + i];
			}
			for (int i = 0; i < DoDai - pos; i++)
			{
				temp[p + i] = Chuoi[pos + i];
			}
			temp[newDoDai] = '\0';
			delete[]Chuoi;
			Chuoi = temp;
			DoDai = newDoDai;
			return *this;
		}
	}
}

MyString & MyString::insert(size_t pos, const char * Data)
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		int length = 0;
		while (Data[length] != '\0')
			length++;
		size_t newDoDai = DoDai + length;
		int p = pos + length;
		char*temp = new char[newDoDai + 1];
		for (int i = 0; i < pos; i++)
		{
			temp[i] = Chuoi[i];
		}
		for (int i = 0; i < length; i++)
		{
			temp[pos + i] = Data[i];
		}
		for (int i = 0; i < DoDai - pos; i++)
		{
			temp[p + i] = Chuoi[pos + i];
		}
		temp[newDoDai] = '\0';
		delete[]Chuoi;
		Chuoi = temp;
		DoDai = newDoDai;
		return *this;
	}
}




