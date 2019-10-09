#include <vector>
#include <algorithm>
#include<fstream>
#include<iostream>
#include "Header.h"
#include<iterator>
#include<functional>
#include<algorithm>
#include<numeric>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::istream_iterator;
using std::string;



Md::~Md(){
	auto x = [](auto a) {a.clear(); };
	for_each(&arr[0], &arr[n], x);
	if (arr != nullptr)
	delete[] arr;
}

int Md::size() const
{
	return n;
}

vector <double> *getarr(const string filename)
{
	std::ifstream a(filename);
	int n;
	a >> n;
	vector <double> * b = new vector<double> [n];
	istream_iterator<double> it(a);
	istream_iterator<double> end;
	vector <double> c;
	int i = 0;
	auto x = [&b, &i, &c](auto t) {
		c.push_back(t); 
		if (!((i + 1) % 3)) 
		{ 
			b[(i - 2) / 3] = c; 
			c.clear(); 
		}
		i++; 
	};
	for_each(it, end, x);
	a.close();
	auto y = [](auto a, auto b) {return std::inner_product(a.begin(), a.end(), a.begin(), 0) < std::inner_product(b.begin(), b.end(), b.begin(), 0); };
	sort(&b[0], &b[n], y);
	return b;
}

vector <double> Md::getMin() const {
	return arr[0];
}

vector <double> Md::getMax()const {
	return arr[n - 1];
}

int getn(const string filename)
{
	int n;
	std::ifstream a(filename);
	a >> n;
	istream_iterator<double> it(a);
	istream_iterator<double> end;
	if (!a.is_open())
		throw 2;
	if (end == it)
		throw 3;
	a.close();
	return n;
}

Md::Md(const string filename) :arr(getarr(filename)), n(getn(filename)) {}

//void geterror0(const string filename)
//{
//	int n = getn(filename);
//	vector<int> b = getarr(filename);
//	if (n != b.size())
//		throw 1;
//	else
//		if (n == 0)
//			throw 0;
//}
//
//double Md::midsq() const
//{
//	int a = std::inner_product(arr.begin(), arr.end(), arr.begin(), 0);
//	return 1.0*a / n - midle()*midle();
//}
//
double Md::midle() const
{
	auto x = [](double a, auto b) {double k = sqrt(std::inner_product(b.begin(), b.end(), b.begin(), 0)); return a + k; };
	double m = std::accumulate(&arr[0], &arr[n],0.0, x);//???????????как-то получаются инты
	return m / n;
}

void Md::print() const {
	int i = 1;
	auto x = [](auto t) {cout << t<<" ";};
	cout << "v poradce vozrastania:" << endl;
	auto y = [&x, &i](auto u) {cout << "arr"<<i<<": "; for_each(u.begin(), u.end(), x); cout << endl; i++; };
	for_each(&arr[0], &arr[n], y);
}

//size_t Md::countLarger(const int a) const
//{
//	auto x = [&a](int i) {return i - a > 0; };
//	return std::count(arr.begin(), arr.end(), a);
//}
//
//bool geterror(const string filename)
//{
//	bool error = 1;
//	try {
//		geterror0(filename);
//	}
//	catch (int a)
//	{
//		if (a == 1)
//			std::cout << "N!=n" << std::endl;
//		if (a == 0)
//			std::cout << "n=0" << std::endl;
//		if (a == 2)
//			std::cout << "file not found" << std::endl;
//		if (a == 3)
//			std::cout << "file cliar" << std::endl;
//		error = 0;
//	}
//	return error;
//}