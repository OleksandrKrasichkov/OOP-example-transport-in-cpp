#include <iostream>
class Transport
{
private:
        std::string typeOfFuel;
        double amountOfFuel;
        double maxSpeed;        
public:
        std::string getTypeOfFuel(){return typeOfFuel;}
        double getAmountOfFuel(){return amountOfFuel;}
        double getSpeed(){return speed;}        

        //virtual ~Transport() {}
};

class RoadTransport: public Transport
{
private:
        int numberOfTires;
        int numberOfPassengers;
private:
        int getNumberOfTires(){return numberOfTires;}             
        int getNumberOfPassengers(){return numberOfPassengers;}
};

class Car: public RoadTransport
{
private:

public:
        Car(float maxSpeed_):maxSpeed(maxSpeed_){}

        virtual void honk(){std::cout<<"Car honks"<<std::endl;}
        virtual ~Car(){}
};
class Toyota: public Car
{
private:

public:
        
        Toyota()
        :typeOfFuel("None"),amountOfFuel(0),Car(0),numberOfTires(0),
        numberOfPassengers(0) {}
        Toyota(std::string typeOfFuel_, double amountOfFuel_, float maxSpeed_,
        int numberOfTires_, int numberOfPassengers_)
        :typeOfFuel(typeOfFuel_),amountOfFuel(amountOfFuel_),
        Car(maxSpeed_),numberOfTires(numberOfTires_),
        numberOfPassengers(numberOfPassengers_){}
        void honk(){std::cout<<"Toyota honks"<<std::endl;}
};


int main()
{
Car *tayota = new Toyota();
(*tayota).honk();
return 0;
}















