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
	istream_iterator<double> it(a);
	istream_iterator<double> end;
	if (end == it)
		throw 4;
	vector <double> * b = new vector<double> [n];
	vector <double> c;
	int i = 0;
	auto x = [&b, &i, &c, &n](auto t) {
		c.push_back(t); 
		if (!((i+1) % 3)) 
		{ 
			if(3*n>i)
			b[(i - 2) / 3] = c; 
			c.clear(); 
		}
		i++; 
	};
	for_each(it, end, x);
	if (n == 0)
		throw 0;
	if (i % 3)
		throw 0;
	else
		if (i/ 3 != n)
			throw 1;
	a.close();
	auto y = [](auto a, auto b) {
		auto k = std::inner_product(a.begin(), a.end(), a.begin(), 0);
		auto c = std::inner_product(b.begin(), b.end(), b.begin(), 0);
		return k < c;
	};
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
	if (!a.is_open())
		throw 3;
	a >> n;
	istream_iterator<double> it(a);
	istream_iterator<double> end;
	a.close();
	return n;
}

Md::Md(const string filename) :arr(getarr(filename)), n(getn(filename)) {}

void geterror0(const string filename)
{
	int n = getn(filename);
	auto b = getarr(filename);
}

double Md::midsq() const
{
	auto x = [](double a, auto b) {double k = (std::inner_product(b.begin(), b.end(), b.begin(), 0)); return a + k; };
	double a = std::accumulate(&arr[0], &arr[n], 0.0, x);
	return sqrt(1.0*a / n - midle()*midle());
}

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
	auto p = arr[0];
	auto y = [&x, &i](auto u) {cout << "arr"<<i<<": "; for_each(u.begin(), u.end(), x); cout << endl; i++; };
	for_each(&arr[0], &arr[n], y);
}

size_t Md::countLarger(const int a) const
{
	auto x = [&a](auto b) {return sqrt(std::inner_product(b.begin(), b.end(), b.begin(), 0)) - a > 0; };
	return std::count_if(&arr[0], &arr[n], x);
}

bool Md:: geterror(const string filename)
{
	bool error = 1;
	try {
		geterror0(filename);
	}
	catch (int a)
	{
		if (a == 0||a==1)
			std::cout << "file not correct" << std::endl;
		if (a == 3)
			std::cout << "file not found" << std::endl;
		if (a == 4)
			std::cout << "file cliar" << std::endl;
		error = 0;
	}
	return error;
}