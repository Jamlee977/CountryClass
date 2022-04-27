#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

template<typename T>
void input(string str, T& varInput) {
	cout << str;
	cin >> varInput;
}

class Country
{
	string name;
	long long population;
	double area;
public:
	Country();
	Country(string, long long, double);
	~Country();
	void setName(string);
	void setPopulation(long long);
	void setArea(double);
	string getName();
	long long getPopulation();
	double getArea();
	static string largestArea(Country[], size_t);
	static string largestPopulation(Country[], size_t);
	static string largestPopulationDensity(Country[], size_t);
};

Country::Country()
{
	name = "";
	population = 0;
	area = 0;
}

Country::Country(string name, long long population, double area)
{
	this->name = name;
	this->population = population;
	this->area = area;
}

Country::~Country()
{
}

void Country::setName(string name)
{
	this->name = name;
}

void Country::setArea(double area)
{
	this->area = area;
}

void Country::setPopulation(long long population)
{
	this->population = population;
}

double Country::getArea()
{
	return this->area;
}

long long Country::getPopulation()
{
	return this->population;
}

string Country::getName()
{
	return this->name;
}

string Country::largestArea(Country countries[], size_t Size)
{
	double max = 0;
	for (size_t i = 0; i < Size; i++)
	{
		if (countries[i].getArea() >= max) max = countries[i].getArea();
	}

	for (size_t i = 0; i < Size; i++)
	{
		if (max == countries[i].getArea()) return countries[i].getName();
	}
}

string Country::largestPopulation(Country countries[], size_t Size)
{
	size_t max = 0;
	for (size_t i = 0; i < Size; i++)
	{
		if (countries[i].getPopulation() >= max) max = countries[i].getPopulation();
	}

	for (size_t i = 0; i < Size; i++)
	{
		if (max == countries[i].getPopulation()) return countries[i].getName();
	}
}

string Country::largestPopulationDensity(Country countries[], size_t Size)
{
	double max = 0;
	for (size_t i = 0; i < Size; i++)
	{
		if ((countries[i].getPopulation() / countries[i].getArea()) >= max)
			max = (countries[i].getPopulation() / countries[i].getArea());
	}

	for (size_t i = 0; i < Size; i++)
	{
		if (max == (countries[i].getPopulation() / countries[i].getArea()))
			return countries[i].getName();
	}
}


int main()
{
	size_t SIZE;
	input("Please enter the number of countries that you want: ", SIZE);
	Country* countries = new Country[SIZE];
	string nameOfCountry;
	long long population;
	double area;

	for (size_t i = 0; i < SIZE; i++)
	{
		cout << "Please enter the " << i + 1 << " country's name: ";
		cin >> nameOfCountry;
		countries[i].setName(nameOfCountry);

		cout << "Please enter the " << i + 1 << " country's population: ";
		cin >> population;
		countries[i].setPopulation(population);

		cout << "Please enter the " << i + 1 << " country's area: ";
		cin >> area;
		countries[i].setArea(area);
	}

	cout << "\nThe largest population of all countries goes to: "
		<< Country::largestPopulation(countries, SIZE) << endl;
	cout << "The largest area of all countries goes to: "
		<< Country::largestArea(countries, SIZE) << endl;
	cout << "The largest population density goes to: "
		<< Country::largestPopulationDensity(countries, SIZE) << endl;

	return 1;
}
