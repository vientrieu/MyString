#include "Iterator.h"

StringIterator::StringIterator() :Iterator() {}
StringIterator::StringIterator(char * myString, long current) : Iterator(), _myString(myString), _current(current) {}
StringIterator & StringIterator::operator=(StringIterator & stringIterator)
{
	*this = stringIterator;
	return *this;
}

void StringIterator::First()
{
	_current = 0;
}

void StringIterator::Last()
{
	_current = strlen(_myString) - 1;
}

void StringIterator::Next()
{
	_current++;
}

void StringIterator::nNext(size_t n)
{
	_current += n;
}

void StringIterator::Previous()
{
	_current--;
}

void StringIterator::nPrevious(size_t n)
{
	_current -= n;
}

bool StringIterator::IsDone()
{
	if (_current >= strlen(_myString) || _current < 0)
	{
		return true;
	}
	return false;
}

char& StringIterator::CurrentItem()
{
	return _myString[_current];
}

size_t StringIterator::get_Current()
{
	return this->_current;
}
