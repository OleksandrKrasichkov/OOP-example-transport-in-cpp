#include <iostream>
#include <vector>
#include <algorithm>
class Transport
{
private:
        std::string typeOfFuel;
        double amountOfFuel;
        double maxSpeed;        
        int numberOfPassengers;
        std::vector<std::string> allowedFuel = 
        {"Gasoline","Diesel","Electric","Kerosene"};
public:
        Transport(std::string typeOfFuel_, double amountOfFuel_, double maxSpeed_,
        int numberOfPassengers_)
        :typeOfFuel(typeOfFuel_),amountOfFuel(amountOfFuel_),maxSpeed(maxSpeed_),
        numberOfPassengers(numberOfPassengers_){}

        std::string getTypeOfFuel() const {return typeOfFuel;}
        double getAmountOfFuel() const {return amountOfFuel;}
        double getMaxSpeed() const {return maxSpeed;}  
        int getNumberOfPassengers() const {return numberOfPassengers;}

        void setTypeOfFuel(std::string typeOfFuel_)
        {
                if(std::find(allowedFuel.begin(),allowedFuel.end(),typeOfFuel_)
                != allowedFuel.end())
                {typeOfFuel = typeOfFuel_;}
        }
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

        int getNumberOfTires() const {return numberOfTires;}             
};

class AirTransport: public Transport
{
private:
        int numberOfPilots;
public:
        AirTransport(double amountOfFuel_, float maxSpeed_,int numberOfPassengers_,
        int numberOfPilots_)
        :Transport("Kerosene",amountOfFuel_, maxSpeed_,numberOfPassengers_),
        numberOfPilots(numberOfPilots_) {}
        
        int getNumberOfPilots() const {return numberOfPilots;}      
};

class Car: public RoadTransport
{
private:

public:
        Car(std::string typeOfFuel_, double amountOfFuel_, double maxSpeed_,
        int numberOfPassengers_)
        :RoadTransport(typeOfFuel_,amountOfFuel_,maxSpeed_, numberOfPassengers_,4){}

        virtual void honk() const {std::cout<<"Car honks"<<std::endl;}
        virtual ~Car(){}
};
class Jet: public AirTransport
{
private:
public:
        Jet(double amountOfFuel_=3000,double maxSpeed_=1200,
        int numberOfPassengers_=8,int numberOfPilots_=2)
        :AirTransport(amountOfFuel_, maxSpeed_, numberOfPassengers_, numberOfPilots_)
        {}

};
class Toyota: public Car
{
private:

public:
        
        Toyota(std::string typeOfFuel_="Gasoline", double amountOfFuel_=50,
        double maxSpeed_=180)
        :Car(typeOfFuel_,amountOfFuel_,maxSpeed_,4){}
        void honk() const {std::cout<<"Toyota honks"<<std::endl;}
};


int main()
{
Car *tayota = new Toyota();
(*tayota).honk();
std::cout<<(*tayota).getNumberOfTires();
tayota->setTypeOfFuel("Kerosene");
std::cout<<tayota->getTypeOfFuel();
delete tayota;
return 0;
}















