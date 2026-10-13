```cpp
#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
    string brand;
    string model;
    int year;

public:
    Vehicle()
    {
        brand = "Unknown";
        model = "Unknown";
        year = 0;
    }

    Vehicle(string b, string m, int y)
    {
        brand = b;
        model = m;
        year = y;
    }

    void displayVehicle()
    {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

class Car : public Vehicle
{
protected:
    int numberOfDoors;
    string fuelType;

public:
    Car() : Vehicle()
    {
        numberOfDoors = 4;
        fuelType = "Petrol";
    }

    Car(string b, string m, int y, int doors, string fuel)
        : Vehicle(b, m, y)
    {
        numberOfDoors = doors;
        fuelType = fuel;
    }

    void displayCar()
    {
        displayVehicle();
        cout << "Number of Doors: " << numberOfDoors << endl;
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class ElectricCar : public Car
{
private:
    int batteryCapacity;
    int range;

public:
    ElectricCar() : Car()
    {
        batteryCapacity = 0;
        range = 0;
    }

    ElectricCar(string b, string m, int y, int doors,
                string fuel, int battery, int r)
        : Car(b, m, y, doors, fuel)
    {
        batteryCapacity = battery;
        range = r;
    }

    void displayElectricCar()
    {
        displayCar();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
        cout << "Range: " << range << " km" << endl;
    }
};

int main()
{
    ElectricCar e("Tesla", "Model 3", 2025, 4,
                  "Electric", 75, 500);

    e.displayElectricCar();

    return 0;
}
```
