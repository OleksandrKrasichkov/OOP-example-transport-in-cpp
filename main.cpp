#include <iostream>
class Transport()
{
private:
        std::string typeOfFuel;
        double amountOfFuel;
        double speed;        
public:
        virtual std::string getTypeOfFuel(){return typeOfFuel}
        virtual double getAmountOfFuel(){return amountOfFuel}
        virtual double getSpeed(){return speed}

        
}
