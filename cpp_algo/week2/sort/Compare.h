#ifndef _Compare_h
#define _Compare_h

// operator> �� operator== �� �����ϸ� 
// >= != <= < �����ڸ� �� �� �ֵ���  ����. 

template <class TYPE> bool operator<(const TYPE& a, const TYPE& b)
{
	return b > a;
}

template <class TYPE> bool operator>=(const TYPE& a, const TYPE& b)
{
	return (a > b || a == b);
}

template <class TYPE> bool operator<=(const TYPE& a, const TYPE& b)
{
	return (b > a || a == b);
}

template <class TYPE> bool operator!=(const TYPE& a, const TYPE& b)
{
	return !(a == b);
}	


#endif