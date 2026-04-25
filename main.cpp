#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Transport
{
private:
        std::string typeOfFuel;
        double amountOfFuel;
        double litersPerHour;
        double maxSpeed;        
        int numberOfPassengers;
        std::vector<std::string> allowedFuel = 
        {"Gasoline","Diesel","Electric","Kerosene"};
        std::unordered_map<std::string, double> fuelPrices =
        {
                {"Gasoline", 3},
                {"Diesel", 3.5},
                {"Electric", 1.3},
                {"Kerosene", 2}
        };
public:
        Transport(std::string typeOfFuel_, double amountOfFuel_,
        double litersPerHour_, double maxSpeed_,int numberOfPassengers_)
        :typeOfFuel(typeOfFuel_),amountOfFuel(amountOfFuel_),
        litersPerHour(litersPerHour_), maxSpeed(maxSpeed_),
        numberOfPassengers(numberOfPassengers_){}

        std::string getTypeOfFuel() const {return typeOfFuel;}
        double getAmountOfFuel() const {return amountOfFuel;}
        double getLitersPerHour() const {return litersPerHour;}
        double getMaxSpeed() const {return maxSpeed;}  
        int getNumberOfPassengers() const {return numberOfPassengers;}

        void setTypeOfFuel(std::string typeOfFuel_)
        {
                if(std::find(allowedFuel.begin(),allowedFuel.end(),typeOfFuel_)
                != allowedFuel.end())
                {typeOfFuel = typeOfFuel_;}
                else{std::cout<<"This type of fuel doesn't exist."<<std::endl;}
        }
        void setAmountOfFuel(double amountOfFuel_)
        {
                if(amountOfFuel_ >= 0)
                {
                        amountOfFuel = amountOfFuel_;
                }else {std::cout<<"Too little fuel."<<std::endl;}
        }
        void setLitersPerHour(double litersPerHour_)
        {
                if(litersPerHour_ >= 0)
                {litersPerHour = litersPerHour_;}
                else{std::cout<<"Too slow consumption of fuel."<<std::endl;}
        }
        void setMaxSpeed(double maxSpeed_)
        {
                if(maxSpeed_ >= 0)
                {
                        maxSpeed = maxSpeed_;  
                }else {std::cout<<"Too slow"<<std::endl;}      
        }
        void setNumberOfPassengers( int numberOfPassengers_)
        {
                if(numberOfPassengers_ >= 0)
                {
                        numberOfPassengers = numberOfPassengers_;
                }else {std::cout<<"Too few passengers"<<std::endl;}
        }

};

class RoadTransport: public Transport
{
private:
        int numberOfTires;
public:
        RoadTransport(std::string typeOfFuel_, double amountOfFuel_,
        double litersPerHour_, double maxSpeed_,
        int numberOfPassengers_, int numberOfTires_)
        :Transport(typeOfFuel_,amountOfFuel_,litersPerHour_,
        maxSpeed_, numberOfPassengers_),
        numberOfTires(numberOfTires_){}

        int getNumberOfTires() const {return numberOfTires;}             

        void setNumberOfTires(int numberOfTires_)
        {
                if(numberOfTires_ >= 0)
                {numberOfTires = numberOfTires_;}
                else{std::cout<<"Too few tires"<<std::endl;}
        }
};

class AirTransport: public Transport
{
private:
        int numberOfPilots;
public:
        AirTransport(double amountOfFuel_, double litersPerHour_,
        double maxSpeed_,int numberOfPassengers_,
        int numberOfPilots_)
        :Transport("Kerosene",amountOfFuel_, litersPerHour_, maxSpeed_,
        numberOfPassengers_),
        numberOfPilots(numberOfPilots_) {}
        
        int getNumberOfPilots() const {return numberOfPilots;}
        
        void setNumberOfPilots(int numberOfPilots_)
        {
                if(numberOfPilots_ >= 0) 
                {numberOfPilots = numberOfPilots_;}
                else{std::cout<<"Too few pilots"<<std::endl;}
        }      
};

class Car: public RoadTransport
{
private:

public:
        Car(std::string typeOfFuel_, double amountOfFuel_, double litersPerHour_,
        double maxSpeed_, int numberOfPassengers_)
        :RoadTransport(typeOfFuel_,amountOfFuel_, litersPerHour_, 
        maxSpeed_, numberOfPassengers_,4){}

        virtual void honk() const {std::cout<<"Car honks"<<std::endl;}
        virtual ~Car(){}
};
class Jet: public AirTransport
{
private:
public:
        Jet(double amountOfFuel_=3000, double litersPerHour_=800,
        double maxSpeed_=1200,
        int numberOfPassengers_=8,int numberOfPilots_=2)
        :AirTransport(amountOfFuel_, litersPerHour_, maxSpeed_,
        numberOfPassengers_, numberOfPilots_){}

};
class Toyota: public Car
{
private:

public:
        
        Toyota(std::string typeOfFuel_="Gasoline",
        double amountOfFuel_=50,double litersPerHour_=8, double maxSpeed_=180)
        :Car(typeOfFuel_,amountOfFuel_,litersPerHour_, maxSpeed_,4){}
        void honk() const {std::cout<<"Toyota honks"<<std::endl;}
};





double hoursBeforeEmpty(const Transport &);
        






int main()
{
Car *tayota = new Toyota();
(*tayota).honk();
std::cout<<(*tayota).getNumberOfTires();
tayota->setTypeOfFuel("Keosene");
std::cout<<hoursBeforeEmpty(*tayota);
std::cout<<tayota->getTypeOfFuel();
delete tayota;
return 0;
}





double hoursBeforeEmpty(const Transport &t)
{
        return t.getAmountOfFuel() / t.getLitersPerHour();
}









