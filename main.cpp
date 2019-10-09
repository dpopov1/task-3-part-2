#include <iostream>
#include"Header.h"

using std::cout;
using std::endl;

void pr(std::vector<double> a, const char* b)
{
	cout <<b<< a[0] << " " << a[1] << " " << a[2]<<endl;
}

int main()
{
	std::string filename = "data.txt";
	int comparison = 5;
	if (geterror(filename))
	{
		const Md a(filename);
		a.print();
		pr(a.getMax(), "max: ");
		pr(a.getMin(), "min: ");
		cout << "midle: " << a.midle() << endl << "midsq: " << a.midsq() << endl << "kol-vo el-ov | norm(vector) > "<<comparison<<" : "<<a.countLarger(comparison) << endl;
	}
	system("pause");
}