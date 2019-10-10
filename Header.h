#pragma once
#pragma once
#include <vector>
class Md
{
	std::vector<double> *arr;
	int n;

public:
	static bool geterror(const std::string filename);
	std::vector<double> getMax() const;
	std::vector<double> getMin() const;
	int size() const;
	~Md();
	Md(const std::string filename);
	double midle() const;
	double midsq() const;
	void print() const;
	size_t countLarger(const int)const;
};
