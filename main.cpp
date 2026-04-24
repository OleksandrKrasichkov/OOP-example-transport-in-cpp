#include <iostream>
class Transport
{
private:
        std::string typeOfFuel;
        double amountOfFuel;
        double maxSpeed;        
        int numberOfPassengers;
public:
        Transport(std::string typeOfFuel_, double amountOfFuel_, double maxSpeed_,
        int numberOfPassengers_)
        :typeOfFuel(typeOfFuel_),amountOfFuel(amountOfFuel_),maxSpeed(maxSpeed_),
        numberOfPassengers(numberOfPassengers_){}

        std::string getTypeOfFuel(){return typeOfFuel;}
        double getAmountOfFuel(){return amountOfFuel;}
        double getMaxSpeed(){return maxSpeed;}  
        int getNumberOfPassengers(){return numberOfPassengers;}

};

class RoadTransport: public Transport
{
private:
        int numberOfTires;
private:
        RoadTransport(int numberOfTires_)
        :numberofTires(numberOfTires_){}

        int getNumberOfTires(){return numberOfTires;}             
};

class Car: public RoadTransport
{
private:

public:
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















