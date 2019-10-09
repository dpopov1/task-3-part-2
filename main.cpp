#include <iostream>
#include"Header.h"

using std::cout;
using std::endl;

int main()
{
	std::string filename = "data.txt";
	//int comparison = 5;
	//if (geterror(filename))
	//{
		const Md a(filename);
		a.print();
		//cout << "midle: " << a.midle() << endl << "max: " << a.getMax() << endl << "min: " << a.getMin() << endl << "midsq: " << a.midsq() << endl << a.countLarger(comparison) << endl;
	//}
	system("pause");
}