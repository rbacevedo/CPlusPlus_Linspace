#include <iostream>
#include <vector>

template <typename T>
std::vector<double> linspace(const T & T_start, const T & T_stop, const T & T_num)
{
	double start = static_cast<double> (T_start);
	double stop = static_cast<double> (T_stop);
	double num = static_cast<double> (T_num);

	if (num < 1) return std::vector<double>();

	double distance = stop - start;
	double chunk = 0;

	try
	{
		chunk = distance / (num-1);
	}

	catch (...)
	{
		std::cerr << "Sorry cannot devide by 0";
		return std::vector<double>();
	}

	std::vector<double> vect;
	vect.resize(size_t(num));
	//inserting the first element
	vect[0] = start;
	for (int i = 1; i < num; ++i)
	{
		vect[i] = vect[i - 1] + chunk;
	}

	return vect;
}

//test it on main
int main()
{
	std::vector<double> vect = linspace(25.7, 27.9, 2.0);

	for (auto i : vect)
	{
		std::cout << i << " ";
	}

	system("pause");
	return 0;
}
