#include <iostream>
#include <math.h>
#include <string>
using namespace std;

template <class T> // T - тип
class Vector
{
	T* v; // внутрішній масив
	int size; // кількість елементів
public:
	Vector(int newsize); 
	Vector(Vector&); 
	~Vector(); 
	
	void Fill(int a);
	bool Equal(void);

	Vector& operator = (const Vector&); 
	friend ostream& operator << <>(ostream&, const Vector&);
	friend istream& operator >> <>(istream&, Vector&);
};

template <class T>
Vector<T>::Vector(int newsize) 
{
	v = new T[size = newsize]; 
	for (int i = 0; i < size; i++) 
		v[i] = T();
}

template <class T>
Vector<T>::Vector(Vector<T>& x)
{
	v = new T[size = x.size]; 
	for (int i = 0; i < size; i++) 
		v[i] = x.v[i];
}

template <class T>
Vector<T>::~Vector()
{
	delete[] v; 
}

template <class T>
bool Vector<T>::Equal(void) 
{
	for (int i = 0; i < size; i++)
	{
		if (v[i] == v[i + 1])
			return true;
	}
	return false;
}

template <class T>
void Vector<T>::Fill(int a)
{
	for (int i = 0; i < size; i++) // присвоєння нульових значень елементам
		v[i] = a;
}

template <class T>
Vector<T>& Vector<T>::operator = (const Vector<T>& x)
{
	if (this != &x)
	{
		delete[] v;
		v = new T[size = x.size];
		for (int i = 0; i < size; i++)
			v[i] = x.v[i];
	}
	return *this;
}

template<class T>
istream& operator >> (istream& in, Vector<T>& x)
{
	cout << "Input " << x.size << " elements of vector " << endl;
	for (int i = 0; i < x.size; i++) {
		cout << "element[" << i << "] = ";
		in >> x.v[i];
	}
	cout << endl;
	return in;
}

template <class T>
ostream& operator << (ostream& os, const Vector<T>& x)
{
	for (int i = 0; i < x.size; i++)
		os << x.v[i] << ' ';
	os << endl;
	return os;
}
int main()
{
	try
	{
		Vector<int> V(5), U(5);
		cin >> U;
		cin >> V;

		cout << "U = " << U << endl;
		cout << "V = " << V << endl;

		cout << "U:\t" << (U.Equal() ? "containes " : "doesn't contain ") << "same neighboring parts" << endl;
		cout << "V:\t" << (V.Equal() ? "containes " : "doesn't contain ") << "same neighboring parts" << endl;
	}
	catch (exception e)
	{
		cerr << e.what() << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}
 