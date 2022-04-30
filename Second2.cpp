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
    Country(const Country& Object)
    {
        this->area = Object.area;
        this->population = Object.population;
        strcpy_s(this->name, 100, Object.name);
    }
    ~Country();
    void setName(const char* name);
    void setName(char* name);
    void setArea(double area);
    void setPopulation(long long population);
    char* getName() const;
    double getArea() const;
    long long getPopulation() const;

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
    if (name != NULL) 
    {
        delete[] name;
    }
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

char* Country::getName() const
{
    return this->name;
}

double Country::getArea() const
{
    return this->area;
}
long long Country::getPopulation() const
{
    return this->population;
}

Country& largestArea(Country countries[], size_t Size)
{
    double max = 0;
    for (size_t i = 0; i < Size; i++)
    {
        if (countries[i].getArea() > max) max = countries[i].getArea();
    }

    for (size_t i = 0; i < Size; i++)
    {
        if (max == countries[i].getArea()) return countries[i];
    }
}

Country& largestPopulation(Country countries[], size_t Size)
{
    size_t max = 0;
    for (size_t i = 0; i < Size; i++)
    {
        if (countries[i].getPopulation() > max) max = countries[i].getPopulation();
    }

    for (size_t i = 0; i < Size; i++)
    {
        if (max == countries[i].getPopulation()) return countries[i];
    }
}

Country& largestPopulationDensity(Country countries[], size_t Size)
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
            return countries[i];
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

    Country largestPop = largestPopulation(countries, SIZE);
    Country largest_area = largestArea(countries, SIZE);
    Country largestPopDen = largestPopulationDensity(countries, SIZE);


    cout << "\n\nThe largest population of all countries goes to: "
        << largestPop.getName() << " with " << largestPop.getPopulation()
		<< " people in " << largestPop.getArea() << "km." << endl;
    cout << "The largest area of all countries goes to: "
        << largest_area.getName() << " having " << largest_area.getArea()
		<< "km which contains " << largest_area.getPopulation() << " people." << endl;
    cout << "The largest population density goes to: "
        << largestPopDen.getName() << " which has " << largestPopDen.getPopulation()
		<< " people in " << largestPopDen.getArea() << "km." << endl;

    delete[] countries;
    return 0;
}
