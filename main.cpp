#include <iostream>
class Transport
{
private:
        std::string typeOfFuel;
        double amountOfFuel;
        double speed;        
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
        int getNumberOfPassengers(){return nymberOfPassengers;}
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
        void honk(){std::cout<<"Toyota honks"<<std::endl;}
}

















