#include "transport.cpp"

int main()
{
        std::cout<<std::fixed<<std::setprecision(2);

        Car *t10 = new Tesla();
        std::cout<<t10->moneyPerTime(10);
        double totalBatteryCapacity = 0;
        std::vector<Car *> garage = {};
        Car *t = new Toyota();
        Car *te = new Tesla();
        Car *te1 = new Tesla();
        garage.insert(garage.end(), {t, te, te1});
        for(int i = 0; i < garage.size(); ++i)
        {
                garage[i]->honk();
                if(garage[i]->isElectric())
                {
                        totalBatteryCapacity+=garage[i]->getBatteryCapacity();
                }
        }
        std::cout<<"Total battery capacity in my garage: "<<totalBatteryCapacity
                <<std::endl;

        delete t; delete te; delete te1;
        
return 0;
}











