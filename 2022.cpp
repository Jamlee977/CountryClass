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

class Country {
private:
    char* name = new char[100];
    long long int population;
    double area;
public:
    Country();
    Country(const char*, long long, double);
    Country(char*, long long, double);
    ~Country();
    void setName(const char* name);
    void setName(char* name);
    void setArea(double area);
    void setPopulation(long long population);
    char* getName();
    double getArea();
    long long getPopulation();
    static char* largestArea(Country[], size_t);
    static char* largestPopulation(Country[], size_t);
    static char* largestPopulationDensity(Country[], size_t);

};
Country::Country() {
    strcpy_s(this->name, 100, "");
    this->population = 0;
    this->area = 0;
}
Country::Country(const char* name, long long population, double area) {
    strcpy_s(this->name, 100, name);
    this->population = population;
    this->area = area;
}

Country::Country(char* name, long long population, double area) {
    strcpy_s(this->name, 100, name);
    this->population = population;
    this->area = area;
}

Country::~Country() {
    delete[] name;
}

void Country::setName(const char* name)
{
    strcpy_s(this->name, 100, name);
}

void Country::setName(char* name)
{
    strcpy_s(this->name, 100, name);
}

void Country::setArea(double area)
{
    this->area = area;
}
void Country::setPopulation(long long population)
{
    this->population = population;
}

char* Country::getName()
{
    return this->name;
}

double Country::getArea()
{
    return this->area;
}
long long Country::getPopulation()
{
    return this->population;
}

char* Country::largestArea(Country countries[], size_t Size)
{
    double max = 0;
    for (size_t i = 0; i < Size; i++)
    {
        if (countries[i].getArea() > max) max = countries[i].getArea();
    }

    for (size_t i = 0; i < Size; i++)
    {
        if (max == countries[i].getArea()) return countries[i].getName();
    }
}

char* Country::largestPopulation(Country countries[], size_t Size)
{
    size_t max = 0;
    for (size_t i = 0; i < Size; i++)
    {
        if (countries[i].getPopulation() > max) max = countries[i].getPopulation();
    }

    for (size_t i = 0; i < Size; i++)
    {
        if (max == countries[i].getPopulation()) return countries[i].getName();
    }
}

char* Country::largestPopulationDensity(Country countries[], size_t Size)
{
    double max = 0;
    for (size_t i = 0; i < Size; i++)
    {
        if ((countries[i].getPopulation() / countries[i].getArea()) > max)
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
    input("Please enter the number of countries you want: ", SIZE);
    Country* countries = new Country[SIZE];
    char nameOfCountry[100];
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

    cout << "The largest population of all countries goes to: "
        << Country::largestPopulation(countries, SIZE) << endl;
    cout << "The largest area of all countries goes to: "
        << Country::largestArea(countries, SIZE) << endl;
    cout << "The largest population density goes to: "
        << Country::largestPopulationDensity(countries, SIZE) << endl;

    delete[] countries;
    return 0;
}
