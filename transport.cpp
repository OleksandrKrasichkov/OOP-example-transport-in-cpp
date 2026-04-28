#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stdexcept>
#include <iomanip>

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
                {"Electric", 1.1},
                {"Kerosene", 2}
        };
        std::unordered_map<std::string, double>wagesTable =
        {
                {"Driver", 1000},
                {"Pilot", 3000},
                {"Crew", 1500}
        };
public:
        Transport(std::string typeOfFuel_, double amountOfFuel_,
        double litersPerHour_, double maxSpeed_,int numberOfPassengers_)
        {
                setTypeOfFuel(typeOfFuel_);
                setAmountOfFuel(amountOfFuel_);
                setLitersPerHour(litersPerHour_);
                setMaxSpeed(maxSpeed_);
                setNumberOfPassengers(numberOfPassengers_);
        }

        std::string getTypeOfFuel() const {return typeOfFuel;}
        double getAmountOfFuel() const {return amountOfFuel;}
        double getLitersPerHour() const {return litersPerHour;}
        double getMaxSpeed() const {return maxSpeed;}  
        int getNumberOfPassengers() const {return numberOfPassengers;}
        double getFuelPrice(std::string type) const
        {return fuelPrices.at(type);}
        double getWage(std::string type) const
        {return wagesTable.at(type);}
        void setTypeOfFuel(std::string typeOfFuel_)
        {
                if(std::find(allowedFuel.begin(),allowedFuel.end(),typeOfFuel_)
                != allowedFuel.end())
                {typeOfFuel = typeOfFuel_;}
                else{throw std::runtime_error("This type of fuel doesn't exist.");}
        }
        void setAmountOfFuel(double amountOfFuel_)
        {
                if(amountOfFuel_ >= 0)
                {
                        amountOfFuel = amountOfFuel_;
                }else {throw std::runtime_error("Too little fuel.");}
        }
        void setLitersPerHour(double litersPerHour_)
        {
                if(litersPerHour_ >= 0)
                {litersPerHour = litersPerHour_;}
                else{throw std::runtime_error("Too slow consumption of fuel.");}
        }
        void setMaxSpeed(double maxSpeed_)
        {
                if(maxSpeed_ >= 0)
                {
                        maxSpeed = maxSpeed_;  
                }else {throw std::runtime_error("Too slow");}      
        }
        void setNumberOfPassengers( int numberOfPassengers_)
        {
                if(numberOfPassengers_ >= 0)
                {
                        numberOfPassengers = numberOfPassengers_;
                }else {throw std::runtime_error("Too few passengers");}
        }
        
        virtual double moneyPerTime (double time) const
        {
                return ((time * litersPerHour) * fuelPrices.at(typeOfFuel));
        }

        virtual double wageToPersonnel() const
        {
                throw std::runtime_error("This transport doesnt have personnel");
        }
        
        virtual double hoursBeforeEmpty() const
        {
                return (getAmountOfFuel() / getLitersPerHour());
        }
        virtual void move() const {std::cout<<"Transport moves."<<std::endl;}
        virtual ~Transport() {}
};

class RoadTransport: public Transport
{
private:
        int numberOfDrivers;
public:
        RoadTransport(std::string typeOfFuel_, double amountOfFuel_,
        double litersPerHour_, double maxSpeed_,
        int numberOfPassengers_, int numberOfDrivers_)
        :Transport(typeOfFuel_,amountOfFuel_,litersPerHour_,
        maxSpeed_, numberOfPassengers_)
        {
                setNumberOfDrivers(numberOfDrivers_);
        }

        int getNumberOfDrivers() const {return numberOfDrivers;}

        void setNumberOfDrivers(int num)
        {
                if(num >= 0)
                {numberOfDrivers = num;}
                else{throw std::runtime_error("Too few drivers");}
        }
        double wageToPersonnel() const override
        {
                return (numberOfDrivers * getWage("Driver"));
        }
};

class RoadTransportWithTires: public RoadTransport
{
private:
        int numberOfTires;
public:
        RoadTransportWithTires(std::string typeOfFuel_, double amountOfFuel_,
        double litersPerHour_, double maxSpeed_,
        int numberOfPassengers_, int numberOfDrivers_, int numberOfTires_)
        :RoadTransport(typeOfFuel_,amountOfFuel_,litersPerHour_,
        maxSpeed_, numberOfPassengers_, numberOfDrivers_)
        {
                setNumberOfTires(numberOfTires_);
        }
        int getNumberOfTires() const {return numberOfTires;}             
        void setNumberOfTires(int numberOfTires_)
        {
                if(numberOfTires_ >= 0)
                {numberOfTires = numberOfTires_;}
                else{throw std::runtime_error("Too few tires");}
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
        numberOfPassengers_)
        {
                setNumberOfPilots(numberOfPilots_);
        }
        
        int getNumberOfPilots() const {return numberOfPilots;}
        
        void setNumberOfPilots(int numberOfPilots_)
        {
                if(numberOfPilots_ >= 0) 
                {numberOfPilots = numberOfPilots_;}
                else{throw std::runtime_error("Too few pilots");}
        }    
        double wageToPersonnel() const override
        {return (numberOfPilots * getWage("Pilot"));}
        //virtual ~AirTransport() {} dont have to write cause i have it in 
        //Transport 
};

class WaterTransport: public Transport
{
private:
        int numberOfCrew;
public:
        WaterTransport(double amountOfFuel_, double litersPerHour_,
        double maxSpeed_,
        int numberOfPassengers_,int numberOfCrew_)
        :Transport("Diesel", amountOfFuel_, litersPerHour_, maxSpeed_,
        numberOfPassengers_)
        {
                setNumberOfCrew(numberOfCrew_);
        }
        
        int getNumberOfCrew() const {return numberOfCrew;}

        void setNumberOfCrew(int num) 
        {
                if(num >=0)
                {numberOfCrew = num;}
                else {throw std::runtime_error("Too few crew members.");}
        }
        double wageToPersonnel() const override
        {return (numberOfCrew * getWage("Crew"));}
};

class Car: public RoadTransportWithTires
{
private:

public:
        Car(std::string typeOfFuel_, double amountOfFuel_, double litersPerHour_,
        double maxSpeed_, int numberOfPassengers_)
        :RoadTransportWithTires(typeOfFuel_,amountOfFuel_, litersPerHour_, 
        maxSpeed_, numberOfPassengers_,1,4){}

        virtual bool isElectric() const {return false;}
        virtual double getBatteryCapacity() const 
        {throw std::runtime_error("Not an electric car.");}
        virtual double getKWPerHour() const
        {throw std::runtime_error("Not an electric car.");}


        void move() const override {std::cout<<"Car drives 🚗"<<std::endl;}
        
        virtual void honk() const {std::cout<<"Car honks."<<std::endl;}
        virtual void setBatteryCapacity(double num)
        {throw std::runtime_error("There is no battery.");}

        virtual void setKWPerHour(double num)
        {throw std::runtime_error("This car doesn't run on electricity.");}

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
        
        void move() const override {std::cout<<"Jet flies 🛩️"<<std::endl;}
};
class Helicopter: public AirTransport
{
private:
public:
        Helicopter(double amountOfFuel_=600, double litersPerHour_=180,
        double maxSpeed_=250,
        int numberOfPassengers_=3,int numberOfPilots_=1)
        :AirTransport(amountOfFuel_, litersPerHour_, maxSpeed_,
        numberOfPassengers_, numberOfPilots_){}
        
        void move() const override {std::cout<<"Helicopter flies 🚁"<<std::endl;}

};
class Ferry: public WaterTransport
{
private:
public:
        Ferry(double amountOfFuel_=5000, double litersPerHour_=150,
        double maxSpeed_=35,
        int numberOfPassengers_=200,int numberOfCrew_=12)
        :WaterTransport(amountOfFuel_, litersPerHour_, maxSpeed_,
        numberOfPassengers_, numberOfCrew_){}
        
        void move() const override {std::cout<<"Ferry sails ⛴️ "<<std::endl;}

};
class Toyota: public Car
{
private:

public:
        
        Toyota(std::string typeOfFuel_="Gasoline",
        double amountOfFuel_=50,double litersPerHour_=8, double maxSpeed_=180)
        :Car(typeOfFuel_,amountOfFuel_,litersPerHour_, maxSpeed_,4){}
        void honk() const override {std::cout<<"Toyota honks"<<std::endl;}
};
class Tesla: public Car
{
private:
        double batteryCapacity;
        double kWPerHour;
public:
        Tesla(double batteryCapacity_=80, double kWPerHour_=18, double maxSpeed_=300)
        :Car("Electric",0,0,maxSpeed_,4)//type,amount,lph,maxsp,passsengers
        {
                setBatteryCapacity(batteryCapacity_);
                setKWPerHour(kWPerHour_);
        }

        double getBatteryCapacity() const override {return batteryCapacity;}
        double getKWPerHour() const override {return kWPerHour;}

        bool isElectric() const override {return true;}
        void honk() const override {std::cout<<"Tesla HONKS!"<<std::endl;}
        double moneyPerTime(double time) const override
        {return ((time * kWPerHour) * getFuelPrice(getTypeOfFuel()));}
        void setBatteryCapacity(double num) override
        {
                if(num>=0){batteryCapacity = num;}
                else{throw std::runtime_error("Too low battery capacity.");}
        }

        void setKWPerHour(double num) override
        {
                if(num>=0){kWPerHour = num;}
                else{throw std::runtime_error("Too low consumption.");}
        }
        double hoursBeforeEmpty() const override
        {
                return (getBatteryCapacity() / getKWPerHour());
        }
};
               
