#pragma once
#pragma once
#include <vector>
class Md
{
	std::vector<double> *arr;
	int n;

public:
	//int getMax() const;
	//int getMin() const;
	int size() const;
	~Md();
	Md(const std::string filename);
	//double midle() const;
	//double midsq() const;
	void print() const;
	//size_t countLarger(const int)const;
};

//bool geterror(const std::string filename);