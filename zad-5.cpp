#include <iostream>
#include "Para.h"
using namespace std;

template <class T, class U>
void napisz(Para<T, U> a)
{
	a.wypisz();
}

int main()
{
	Para<double, int> p1;
	p1.wpisz(3.4, 5);
	p1.wypisz();

	Para<string, int> p2;
	p2.wpisz("test", 10);
	p2.wypisz();

	Para<int, int> p3;
	p3.wpisz(9, 10, 11);
	p3.wypisz();

	Para<string, string> p4;
	p4.wpisz("napis 1", "napis 2");
	p4.wypisz();

	napisz(p3);
	napisz(p4);

	cout << p3.zabierz() << endl;
	cout << p4.zabierz();
}


// Para.h

#include <iostream>
using namespace std;

#pragma once
template<class T, class U>
class Para
{
	T x;
	U y;
public:
	void wpisz(T valX, U valY);
	void wypisz();
	T zabierz();
};

template<class T, class U>
inline void Para<T, U>::wpisz(T valX, U valY)
{
	x = valX;
	y = valY;
}

template<class T, class U>
inline void Para<T, U>::wypisz()
{
	cout << "x: " << x << " | y: " << y << endl;
}

template<class T, class U>
inline T Para<T, U>::zabierz()
{
	return x;
}

// ******** Specjalizacja ********

#pragma once
template<>
class Para<int, int>
{
	int x;
	int y;
	int z;
public:
	void wpisz(int valX, int valY, int valZ);
	void podaj_z(int valZ);
	void wypisz();
	int zabierz();
};

inline void Para<int, int>::wpisz(int valX, int valY, int valZ)
{
	x = valX;
	y = valY;
	z = valZ;
}

inline void Para<int, int>::podaj_z(int valZ)
{
	z = valZ;
}

inline void Para<int, int>::wypisz()
{
	cout << "x: " << x << " | y: " << y << " | z: " << z << endl;
}

template<>
inline void Para<string, string>::wypisz()
{
	cout << "Mamy dwa napisy: x: " << x << " | y: " << y << endl;
}


inline int Para<int, int>::zabierz()
{
	return x;
}


