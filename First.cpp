// ! Omar Estietie
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

template<typename T>
void input(string str, T &varInput) {
    cout << str;
	cin >> varInput;
}

class Country
{
public:
    Country();
    Country(string name, long long population, double area);
    ~Country();
    void setName(string name);
    void setPopulation(long long population);
    void setArea(double area);
    string getName();
    int getPopulation();
    double getArea();
    string largestArea(Country c1);
    string largestPopulation(Country c1);
    string largestPopulationDensity(Country c1);
private:
    string name;
    long long int population;
    double area;
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
void Country::setName(string name) { this->name = name; }

void Country::setPopulation(long long population) { this->population = population; }

void Country::setArea(double area) { this->area = area; }

string Country::getName() { return name; }

int Country::getPopulation() { return population;}

double Country::getArea() { return area; }

string Country::largestArea(Country c1) {
    if(getArea() > c1.getArea()) return getName();
    return c1.getName();
}
string Country::largestPopulation(Country c1) {
    if(getPopulation() > c1.getPopulation()) return getName();
    return c1.getName();
}
string Country::largestPopulationDensity(Country c1) {
    if((getPopulation() / getArea()) > (c1.getPopulation() / c1.getArea())) return getName();
    return c1.getName();
}

int main() {
    unsigned int size;
    
    input("Please enter the number of countries that you want: ", size);

    Country *countries = new Country[size];
    string nameOfCountry;
    long long population;
    double area;
    unsigned int selectedCountryOne;
    unsigned int selectedCountryTwo;

    for (unsigned int i = 0; i < size; i++) {
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

    input("\nEnter the number of the country that you want to compare (start from zero): ",
         selectedCountryOne);

    input("\nEnter the other country that you want to compare with: ",
         selectedCountryTwo);

    if (selectedCountryOne > size || selectedCountryTwo > size) return 0;

    cout << "\nThe largest population density between 2 countries is: " 
         << countries[selectedCountryOne].largestPopulationDensity(countries[selectedCountryTwo]) << '\n';

    cout << "\nThe largest population between 2 countries is: "
         << countries[selectedCountryOne].largestPopulation(countries[selectedCountryTwo]) << '\n';

    cout << "\nThe largest area between 2 countries is: "
         << countries[selectedCountryOne].largestArea(countries[selectedCountryTwo]) << '\n';

    delete[] countries;
}
