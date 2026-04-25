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
public:
        RoadTransport(std::string typeOfFuel_, double amountOfFuel_, double maxSpeed_,
        int numberOfPassengers_, int numberOfTires_)
        :Transport(typeOfFuel_,amountOfFuel_,maxSpeed_, numberOfPassengers_),
        numberOfTires(numberOfTires_){}

        int getNumberOfTires(){return numberOfTires;}             
};

class AirTransport: public Transport
{
private:
        int amountOfPilots;
public:
        AirTransport(double amountOfFuel_, float maxSpeed_,int numberOfPassengers_,
        int numberOfTires_, int amountOfPilots_)
        :Transport("Kerosene",amountOfFuel_, maxSpeed_,numberOfPassengers_),
        amountOfPilots(amountOfPilots_) {}
        
        int getAmountOfPilots(){return amountOfPilots;}      
};

class Car: public RoadTransport
{
private:

public:
        Car(std::string typeOfFuel_, double amountOfFuel_, double maxSpeed_,
        int numberOfPassengers_, int numberOfTires_)
        :RoadTransport(typeOfFuel_,amountOfFuel_,maxSpeed_, numberOfPassengers_,
        numberOfTires_){}

        virtual void honk(){std::cout<<"Car honks"<<std::endl;}
        virtual ~Car(){}
};
class Jet: public AirTransport
{

};
class Toyota: public Car
{
private:

public:
        
        Toyota()
        :Car("None",0,0,0,0){}
        Toyota(std::string typeOfFuel_, double amountOfFuel_, double maxSpeed_,
        int numberOfPassengers_, int numberOfTires_)
        :Car(typeOfFuel_,amountOfFuel_,maxSpeed_, numberOfPassengers_,
        numberOfTires_){}
        void honk(){std::cout<<"Toyota honks"<<std::endl;}
};


int main()
{
Car *tayota = new Toyota();
(*tayota).honk();
std::cout<<(*tayota).getNumberOfTires();
return 0;
}















