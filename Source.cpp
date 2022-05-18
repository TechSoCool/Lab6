// Sterling Gerard
// Date: April 8, 2022
// Practice this virtual function program, change, the program to have differentd data type

#include<iostream>
using namespace std;
// Ship class

class Ship {

private:

    string name; // Ship name

    string yearBuilt; // Year it was built

public: // Constructor
    Ship(string n, string y) {
        name = n;

        yearBuilt = y;

    }

    // Accessors

    string getName() { return name; }

    string getYearBuilt() { return yearBuilt; } // print function

    virtual void print() {

        cout << "Name: " << name << endl << "Year built: " << yearBuilt << endl;
    }

};
//CruiseShip class
class CruiseShip :public Ship
{
private:
    int numberOFPassenger;
public:
    //Constructor
    CruiseShip(string n, string y, int p) :
        Ship(n, y)
    {
        numberOFPassenger = p;
    }
    //getter and setter
    int getNumberOfPassenger()
    {
        return numberOFPassenger;
    }
    void setNumberOfPassenger(int n)
    {
        numberOFPassenger = n;
    }
    void print() {

        Ship::print();
        cout << "Number of Passenger on Cruise Ship: " << numberOFPassenger << endl;
    }
};
//CargoShip class
class CargoShip : public Ship
{
private:
    int maxLoad;
public:
    //constrcutor
    CargoShip(string n, string y, int l) :Ship(n, y)
    {
        maxLoad = l;
    }
    //getter and setter
    int getMAxLoad() const
    {
        return maxLoad;
    }
    void setMaxLoad(int l)
    {
        maxLoad = l;
    }

    void print() {

        Ship::print();
        cout << "Max Load of Cargo Ship: " << maxLoad << endl;
    }

};

// Use this Main for the program

int main() {

    // Create an array of Ship pointers, initialized with the addresses of 3 dynamically allocated objects.

    Ship* ships[3] = { new Ship("Lolipop", "1960"), new CruiseShip("Disney Magic", "1998", 2400), new CargoShip("Black Pearl", "1800", 50000) };

    // Call each object's print function.

    for (int index = 0; index < 3; index++) {

        ships[index]->print();

        cout << "----------------------------\n";

    }

    return 0;

}