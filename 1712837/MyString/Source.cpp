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

MyString & MyString::insert(size_t pos, const char * Data, size_t n)
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		size_t newDoDai;
		int p;
		int length = 0;
		while (Data[length] != '\0')
			length++;
		if (n > length)
		{
			newDoDai = DoDai + length;
			p = pos + length;
		}
		else
		{
			newDoDai = DoDai + n;
			p = pos + n;
		}
		char*temp = new char[newDoDai + 1];
		for (int i = 0; i < pos; i++)
		{
			temp[i] = Chuoi[i];
		}
		for (int i = 0; i < newDoDai - DoDai; i++)
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

MyString & MyString::insert(size_t pos, size_t n, char c)
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		size_t newDoDai = DoDai + n;
		int p = pos + n;
		char*temp = new char[newDoDai + 1];
		for (int i = 0; i < pos; i++)
		{
			temp[i] = Chuoi[i];
		}
		for (int i = 0; i < n; i++)
		{
			temp[pos + i] = c;
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

MyString & MyString::erase(size_t pos, size_t len)
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		size_t newDoDai;
		int p = pos + len;
		int q;
		if (p > DoDai)
		{
			q = 0;
			newDoDai = pos;
		}
		else
		{
			q = DoDai - p;
			newDoDai = DoDai - len;
		}
		char*temp = new char[newDoDai + 1];
		for (int i = 0; i < pos; i++)
		{
			temp[i] = Chuoi[i];
		}
		for (int i = 0; i < q; i++)
		{
			temp[pos + i] = Chuoi[p + i];
		}
		temp[newDoDai] = '\0';
		delete[]Chuoi;
		Chuoi = temp;
		DoDai = newDoDai;
		return *this;
	}
}

MyString & MyString::replace(size_t pos, size_t len, const MyString & Data)
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		erase(pos, len);
		insert(pos, Data);
		return *this;
	}
}

MyString & MyString::replace(size_t pos, size_t len, const MyString & Data, size_t subpos, size_t sublen)
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		erase(pos, len);
		insert(pos, Data, subpos, sublen);
		return *this;
	}
}

MyString & MyString::replace(size_t pos, size_t len, const char * Data)
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		erase(pos, len);
		insert(pos, Data);
		return *this;
	}
}

MyString & MyString::replace(size_t pos, size_t len, const char * Data, size_t n)
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		erase(pos, len);
		insert(pos, Data, n);
		return *this;
	}
}

MyString & MyString::replace(size_t pos, size_t len, size_t n, char c)
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		erase(pos, len);
		insert(pos, n, c);
		return *this;
	}
}

void MyString::swap(MyString &Data)
{
	MyString temp;
	temp = *this;
	*this = Data;
	Data = temp;
	temp.~MyString();
}

void MyString::pop_back()
{
	DoDai = DoDai - 1;
	char*temp = new char[DoDai + 1];
	for (int i = 0; i < DoDai; i++)
	{
		temp[i] = Chuoi[i];
	}
	temp[DoDai] = '\0';
	delete[]Chuoi;
	Chuoi = temp;
}

const char * MyString::c_str() const noexcept
{
	return Chuoi;
}

const char * MyString::data() const noexcept
{
	return Chuoi;
}

size_t MyString::copy(char *Data, size_t len, size_t pos) const
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		int p, q = len + pos;
		if (q > DoDai) p = DoDai - pos;
		else p = len;
		for (int i = 0; i < p; i++)
		{
			Data[i] = Chuoi[pos + i];
		}
		return p;
	}
}

size_t MyString::find(const MyString & Data, size_t pos) const noexcept
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		if (pos + Data.DoDai <= DoDai)
		{
			int dem = 0;
			for (int i = 0; i <= DoDai - Data.DoDai - pos; i++)
			{
				if (Data.Chuoi[dem] == Chuoi[pos + i])
				{
					dem++;
					for (int j = i + 1; j < DoDai - pos; j++)
					{
						if (Data.Chuoi[dem] == Chuoi[pos + j])
						{
							dem++;
						}
						else
						{
							break;
						}
					}
					if (dem == Data.DoDai)
					{
						return pos + i;
					}
					else
					{
						dem = 0;
					}
				}
			}
			return -1;
		}
		else
		{
			return -1;
		}
	}
}

size_t MyString::find(const char *Data, size_t pos) const
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		int length = 0;
		while (Data[length] != '\0')
			length++;
		if (pos + length <= DoDai)
		{
			int dem = 0;
			for (int i = 0; i <= DoDai - length - pos; i++)
			{
				if (Data[dem] == Chuoi[pos + i])
				{
					dem++;
					for (int j = i + 1; j < DoDai - pos; j++)
					{
						if (Data[dem] == Chuoi[pos + j])
						{
							dem++;
						}
						else
						{
							break;
						}
					}
					if (dem == length)
					{
						return pos + i;
					}
					else
					{
						dem = 0;
					}
				}
			}
			return -1;
		}
		else
		{
			return -1;
		}
	}
}

size_t MyString::find(const char *Data, size_t pos, size_t n) const
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		int length = 0, p;
		while (Data[length] != '\0')
			length++;
		if (n > length) p = length;
		else p = n;
		if (pos + p <= DoDai)
		{
			int dem = 0;
			for (int i = 0; i <= DoDai - p - pos; i++)
			{
				if (Data[dem] == Chuoi[pos + i])
				{
					dem++;
					for (int j = i + 1; j < DoDai-pos; j++)
					{
						if (Data[dem] == Chuoi[pos + j])
						{
							dem++;
						}
						else
						{
							break;
						}
						if (dem == p)
						{
							return pos + i;
						}
					}
					if (dem == p)
					{
						return pos + i;
					}
					else
					{
						dem = 0;
					}
				}
			}
			return -1;
		}
		else
		{
			return -1;
		}
	}
}

size_t MyString::find(char c, size_t pos) const noexcept
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		for (int i = pos; i < DoDai; i++)
		{
			if (Chuoi[i] == c) return i;
		}
		return -1;
	}
}

size_t MyString::rfind(const MyString &Data, size_t pos) const noexcept
{
	int flag = -1;
	if (pos<0 || pos>DoDai) throw;
	else
	{
		if (pos + Data.DoDai <= DoDai)
		{
			for (int i = 0; i <= DoDai - Data.DoDai - pos; i++)
			{
				int dem = 0;
				if (Data.Chuoi[0] == Chuoi[pos + i])
				{
					dem++;
					for (int j = 1; j < Data.DoDai; j++)
					{
						if (Data.Chuoi[j] == Chuoi[pos + i + j])
							dem++;
						else break;
					}
					if (dem == Data.DoDai) flag = pos + i;
				}
			}
			return flag;
		}
		else return -1;
	}
}

size_t MyString::rfind(const char *Data, size_t pos) const
{
	int flag = -1;
	if (pos<0 || pos>DoDai) throw;
	else
	{
		int length = 0;
		while (Data[length] != '\0')
			length++;
		if (pos + length<= DoDai)
		{
			for (int i = 0; i <= DoDai - length - pos; i++)
			{
				int dem = 0;
				if (Data[0] == Chuoi[pos + i])
				{
					dem++;
					for (int j = 1; j < length; j++)
					{
						if (Data[j] == Chuoi[pos + i + j])
							dem++;
						else break;
					}
					if (dem == length) flag = pos + i;
				}
			}
			return flag;
		}
		else return -1;
	}
}

size_t MyString::rfind(const char *Data, size_t pos, size_t n) const
{
	int flag = -1, p;
	if (pos<0 || pos>DoDai) throw;
	else
	{
		int length = 0;
		while (Data[length] != '\0')
			length++;
		if (n > length) p = length;
		else p = n;
		if (pos + p<= DoDai)
		{
			for (int i = 0; i <= DoDai - p - pos; i++)
			{
				int dem = 0;
				if (Data[0] == Chuoi[pos + i])
				{
					dem++;
					for (int j = 1; j < p; j++)
					{
						if (Data[j] == Chuoi[pos + i + j])
							dem++;
						else break;
					}
					if (dem == p) flag = pos + i;
				}
			}
			return flag;
		}
		else return -1;
	}
}

size_t MyString::rfind(char c, size_t pos) const noexcept
{
	int flag = -1;
	if (pos<0 || pos>DoDai) throw;
	else
	{
		for (int i = 0; i <= DoDai - pos; i++)
		{
			if (Chuoi[i] == c) flag = i;
		}
		return flag;
	}
}

size_t MyString::find_first_of(const MyString &Data, size_t pos) const noexcept
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		for (int i = pos; i < DoDai; i++)
		{
			for (int j = 0; j < Data.DoDai; j++)
			{
				if (Chuoi[i] == Data.Chuoi[j])
					return i;
			}
		}
		return -1;
	}
}

size_t MyString::find_first_of(const char * Data, size_t pos) const
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		int length = 0;
		while (Data[length] != '\0')
			length++;
		for (int i = pos; i < DoDai; i++)
		{
			for (int j = 0; j < length; j++)
			{
				if (Chuoi[i] == Data[j])
					return i;
			}
		}
		return -1;
	}
}

size_t MyString::find_first_of(const char * Data, size_t pos, size_t n) const
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		int length = 0, p;
		while (Data[length] != '\0')
			length++;
		if (n > length)p = length;
		else p = n;
		for (int i = pos; i < DoDai; i++)
		{
			for (int j = 0; j < p; j++)
			{
				if (Chuoi[i] == Data[j])
					return i;
			}
		}
		return -1;
	}
}

size_t MyString::find_first_of(char c, size_t pos) const noexcept
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		for (int i = pos; i < DoDai; i++)
		{
			if (Chuoi[i] == c)
				return i;
		}
		return -1;
	}
}

size_t MyString::find_last_of(const MyString & Data, size_t pos) const noexcept
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		int flag = -1;
		for (int i = pos; i < DoDai; i++)
		{
			for (int j = 0; j < Data.DoDai; j++)
			{
				if (Chuoi[i] == Data.Chuoi[j])
					flag = i;
			}
		}
		return flag;
	}
}

size_t MyString::find_last_of(const char * Data, size_t pos) const
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		int length = 0, flag = -1;
		while (Data[length] != '\0')
			length++;
		for (int i = pos; i < DoDai; i++)
		{
			for (int j = 0; j < length; j++)
			{
				if (Chuoi[i] == Data[j])
					flag = i;
			}
		}
		return flag;
	}
}

size_t MyString::find_last_of(const char * Data, size_t pos, size_t n) const
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		int length = 0, flag = -1, p;
		while (Data[length] != '\0')
			length++;
		if (n > length)p = length;
		else p = n;
		for (int i = pos; i < DoDai; i++)
		{
			for (int j = 0; j < p; j++)
			{
				if (Chuoi[i] == Data[j])
					flag = i;
			}
		}
		return flag;
	}
}

size_t MyString::find_last_of(char c, size_t pos) const noexcept
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		int flag = -1;
		for (int i = pos; i < DoDai; i++)
		{
			if (Chuoi[i] == c)
				flag = i;
		}
		return flag;
	}
}

size_t MyString::find_first_not_of(const MyString & Data, size_t pos) const noexcept
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		for (int i = pos; i < DoDai; i++)
		{
			int dem = 0;
			for (int j = 0; j < Data.DoDai; j++)
			{
				if (Chuoi[i] != Data.Chuoi[j])
					dem++;
			}
			if (dem == Data.DoDai)
				return i;
		}
		return -1;
	}
}

size_t MyString::find_first_not_of(const char * Data, size_t pos) const
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		int length = 0;
		while (Data[length] != '\0')
			length++;
		for (int i = pos; i < DoDai; i++)
		{
			int dem = 0;
			for (int j = 0; j < length; j++)
			{
				if (Chuoi[i] != Data[j])
					dem++;
			}
			if (dem == length) return i;
		}
		return -1;
	}
}

size_t MyString::find_first_not_of(const char * Data, size_t pos, size_t n) const
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		int length = 0, p;
		while (Data[length] != '\0')
			length++;
		if (n > length)p = length;
		else p = n;
		for (int i = pos; i < DoDai; i++)
		{
			int dem = 0;
			for (int j = 0; j < p; j++)
			{
				if (Chuoi[i] != Data[j])
					dem++;
			}
			if (dem == length) return i;
		}
		return -1;
	}
}

size_t MyString::find_first_not_of(char c, size_t pos) const noexcept
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		for (int i = pos; i < DoDai; i++)
		{
			if (Chuoi[i] != c)
				return i;
		}
		return -1;
	}
}

size_t MyString::find_last_not_of(const MyString & Data, size_t pos) const noexcept
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		int flag = -1;
		for (int i = pos; i < DoDai; i++)
		{
			int dem = 0;
			for (int j = 0; j < Data.DoDai; j++)
			{
				if (Chuoi[i] != Data.Chuoi[j])
					dem++;
			}
			if (dem == Data.DoDai) flag = i;
		}
		return flag;
	}
}

size_t MyString::find_last_not_of(const char * Data, size_t pos) const
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		int length = 0, flag = -1;
		while (Data[length] != '\0')
			length++;
		for (int i = pos; i < DoDai; i++)
		{
			int dem = 0;
			for (int j = 0; j < length; j++)
			{
				if (Chuoi[i] != Data[j])
					dem++;
			}
			if (dem == length) flag = i;
		}
		return flag;
	}
}

size_t MyString::find_last_not_of(const char * Data, size_t pos, size_t n) const
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		int length = 0, flag = -1, p;
		while (Data[length] != '\0')
			length++;
		if (n > length)p = length;
		else p = n;
		for (int i = pos; i < DoDai; i++)
		{
			int dem = 0;
			for (int j = 0; j < p; j++)
			{
				if (Chuoi[i] != Data[j])
					dem++;
			}
			if (dem == length) flag = i;
		}
		return flag;
	}
}

size_t MyString::find_last_not_of(char c, size_t pos) const noexcept
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		int flag = -1;
		for (int i = pos; i < DoDai; i++)
		{
			if (Chuoi[i] != c)
				flag = i;
		}
		return flag;
	}
}

MyString MyString::substr(size_t pos, size_t len) const
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		int p;
		if (pos + len > DoDai) p = DoDai - pos;
		else p = len;
		char* temp = new char[p+1];
		for (int i = 0; i < p; i++)
		{
			temp[i] = Chuoi[pos + i];
		}
		temp[p] = '\0';
		MyString Con(temp);
		return Con;
	}
}

int MyString::compare(const MyString &Data) const noexcept
{
	if (DoDai > Data.DoDai)
	{
		for (int i = 0; i < Data.DoDai; i++)
		{
			if (Chuoi[i] > Data.Chuoi[i]) return 1;
			else if (Chuoi[i] < Data.Chuoi[i]) return -1;
		}
		return 1;
	}
	else if (DoDai < Data.DoDai)
	{
		for (int i = 0; i < DoDai; i++)
		{
			if (Chuoi[i] > Data.Chuoi[i]) return 1;
			else if (Chuoi[i] < Data.Chuoi[i]) return -1;
		}
		return -1;
	}
	return 0;
}

int MyString::compare(size_t pos, size_t len, const MyString &Data) const
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		if (pos+len > DoDai) len = DoDai-pos;
		if (Data.DoDai > len)
		{
			for (int i = 0; i < len; i++)
			{
				if (Chuoi[pos+i] > Data.Chuoi[i]) return 1;
				else if (Chuoi[pos+i] < Data.Chuoi[i]) return -1;
			}
			return -1;
		}
		else if (Data.DoDai < len)
		{
			for (int i = 0; i < Data.DoDai; i++)
			{
				if (Chuoi[pos+i] > Data.Chuoi[i]) return 1;
				else if (Chuoi[pos+i] < Data.Chuoi[i]) return -1;
			}
			return 1;
		}
		return 0;
	}
}

int MyString::compare(size_t pos, size_t len, const MyString & Data, size_t subpos, size_t sublen) const
{
	if (pos<0 || pos>Data.DoDai || subpos<0 || subpos>DoDai) throw;
	else
	{
		if (pos + len > DoDai) len = DoDai - pos;
		if (subpos + sublen > Data.DoDai) sublen = Data.DoDai - subpos;
		if (pos + len > DoDai) len = DoDai - pos;
		if (sublen > len)
		{
			for (int i = 0; i < len; i++)
			{
				if (Chuoi[pos + i] > Data.Chuoi[subpos + i]) return 1;
				else if (Chuoi[pos + i] < Data.Chuoi[subpos + i]) return -1;
			}
			return -1;
		}
		else if (sublen < len)
		{
			for (int i = 0; i < sublen; i++)
			{
				if (Chuoi[pos + i] > Data.Chuoi[subpos + i]) return 1;
				else if (Chuoi[pos + i] < Data.Chuoi[subpos + i]) return -1;
			}
			return 1;
		}
		return 0;
	}
}

int MyString::compare(const char *Data) const
{
	int length = 0;
	while (Data[length] != '\0')
		length++;
	if (DoDai > length)
	{
		for (int i = 0; i < length; i++)
		{
			if (Chuoi[i] > Data[i]) return 1;
			else if (Chuoi[i] < Data[i]) return -1;
		}
		return 1;
	}
	else if (DoDai < length)
	{
		for (int i = 0; i < DoDai; i++)
		{
			if (Chuoi[i] > Data[i]) return 1;
			else if (Chuoi[i] < Data[i]) return -1;
		}
		return -1;
	}
	return 0;
}

int MyString::compare(size_t pos, size_t len, const char *Data) const
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		int length = 0;
		while (Data[length] != '\0')
			length++;
		if (pos + len > DoDai) len = DoDai - pos;
		if (length > len)
		{
			for (int i = 0; i < len; i++)
			{
				if (Chuoi[pos + i] > Data[i]) return 1;
				else if (Chuoi[pos + i] < Data[i]) return -1;
			}
			return -1;
		}
		else if (length < len)
		{
			for (int i = 0; i < length; i++)
			{
				if (Chuoi[pos + i] > Data[i]) return 1;
				else if (Chuoi[pos + i] < Data[i]) return -1;
			}
			return 1;
		}
		return 0;
	}
}

int MyString::compare(size_t pos, size_t len, const char *Data, size_t n) const
{
	if (pos<0 || pos>DoDai) throw;
	else
	{
		int length = 0;
		while (Data[length] != '\0')
			length++;
		if (pos + len > DoDai) len = DoDai - pos;
		if (n > length) n = length;
		if (n > len)
		{
			for (int i = 0; i < len; i++)
			{
				if (Chuoi[pos + i] > Data[i]) return 1;
				else if (Chuoi[pos + i] < Data[i]) return -1;
			}
			return -1;
		}
		else if (n < len)
		{
			for (int i = 0; i < n; i++)
			{
				if (Chuoi[pos + i] > Data[i]) return 1;
				else if (Chuoi[pos + i] < Data[i]) return -1;
			}
			return 1;
		}
		return 0;
	}
}

MyString& operator+(const MyString & L, const MyString & R)
{
	MyString temp(L);
	temp.append(R);
	return temp;
}

MyString operator+(const MyString & L, const char * R)
{
	MyString temp(L);
	temp.append(R);
	return temp;
}

MyString & operator+(const char * L, const MyString & R)
{
	MyString temp(L);
	temp.append(R);
	return temp;
}

MyString operator+(const MyString & L, char R)
{
	MyString temp(L);
	temp.append(1,R);
	return temp;
}

MyString & operator+(char L, const MyString & R)
{
	MyString temp(1,L);
	temp.append(R);
	return temp;
}

bool operator==(const MyString & L, const MyString & R)
{
	if (L.compare(R) == 0) return true;
	return false;
}

bool operator==(const char * L, const MyString & R)
{
	if (R.compare(L) == 0) return true;
	return false;
}

bool operator==(const MyString & L, const char * R)
{
	if (L.compare(R) == 0) return true;
	return false;
}

bool operator!=(const MyString & L, const MyString & R)
{
	if (L.compare(R) != 0) return true;
	return false;
}

bool operator!=(const char * L, const MyString & R)
{
	if (R.compare(L) != 0) return true;
	return false;
}

bool operator!=(const MyString & L, const char * R)
{
	if (L.compare(R) != 0) return true;
	return false;
}

bool operator<(const MyString & L, const MyString & R)
{
	if (L.compare(R) < 0) return true;
	return false;
}

bool operator<(const char * L, const MyString & R)
{
	if (R.compare(L) > 0) return true;
	return false;
}

bool operator<(const MyString & L, const char * R)
{
	if (L.compare(R) < 0) return true;
	return false;
}

bool operator<=(const MyString & L, const MyString & R)
{
	if (L.compare(R) <= 0) return true;
	return false;
}

bool operator<=(const char * L, const MyString & R)
{
	if (R.compare(L) >= 0) return true;
	return false;
}

bool operator<=(const MyString & L, const char * R)
{
	if (L.compare(R) <= 0) return true;
	return false;
}

bool operator>(const MyString & L, const MyString & R)
{
	if (L.compare(R) > 0) return true;
	return false;
}

bool operator>(const char * L, const MyString & R)
{
	if (R.compare(L) < 0) return true;
	return false;
}

bool operator>(const MyString & L, const char * R)
{
	if (L.compare(R) > 0) return true;
	return false;
}

bool operator>=(const MyString & L, const MyString & R)
{
	if (L.compare(R) >= 0) return true;
	return false;
}

bool operator>=(const char * L, const MyString & R)
{
	if (R.compare(L) <= 0) return true;
	return false;
}

bool operator>=(const MyString & L, const char * R)
{
	if (L.compare(R) >= 0) return true;
	return false;
}

void swap(MyString & x, MyString & y)
{
	MyString temp(x);
	x = y; y = temp;
	temp.~MyString();
}

istream & getline(istream & is, MyString&Data, char delim)
{
	char* temp = new char[256];
	is.get(temp, 256, delim);
	Data.append(temp);
	return is;
}

istream & getline(istream & is, MyString & Data)
{
	char* temp = new char[256];
	is.get(temp, 256);
	Data.append(temp);
	return is;
}










