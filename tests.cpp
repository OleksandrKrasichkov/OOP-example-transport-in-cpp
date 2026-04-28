#include "transport.cpp"
#include <cassert>

void test_Toyota()
{
        Toyota t;
        assert (t.getTypeOfFuel() == "Gasoline");
        Toyota t1("Kerosene");
        assert (t1.getTypeOfFuel() == "Kerosene");
        t = t1;
        assert (t.getTypeOfFuel() == "Kerosene");
        bool thrown = false;
        try{
                Toyota t1("Crow",-10, -1);
        }catch (const std::runtime_error &e) {
                thrown = true;
        }
        assert(thrown);
        Car* t2 = new Toyota();
        assert (t2->hoursBeforeEmpty() == 6.25);          
        assert (t2->moneyPerTime(10) == 240);
        assert (t2->wageToPersonnel() == 1000);

        delete t2;
}
void test_Tesla()
{
        Tesla t1;
        assert(t1.getBatteryCapacity() == 80);
        Tesla t11;
        t11.setBatteryCapacity(1000);
        assert (t11.getBatteryCapacity() == 1000);
        t1 = t11;
        assert (t1.getBatteryCapacity() == 1000);
        bool thrown = false;
        try
        {Tesla t2(-1);}
        catch (const std::runtime_error &e){thrown = true;}
        assert(thrown);
        Car *t2 = new Tesla();
        assert(t2->hoursBeforeEmpty() - 4.44 < 0.01);
        assert(t2->moneyPerTime(10)-198 < 0.01);
        assert(t2->wageToPersonnel() == 1000);
        delete t2;
}
void test_Jet()
{ 
        Jet t1;
        assert(t1.getTypeOfFuel() == "Kerosene");
        Jet t11;
        t11.setTypeOfFuel("Diesel");
        assert (t11.getTypeOfFuel() == "Diesel");
        t1 = t11;
        assert (t1.getTypeOfFuel() == "Diesel");
        bool thrown = false;
        try
        {Jet t2(1, -1);}
        catch (const std::runtime_error &e){thrown = true;}
        assert(thrown);
        AirTransport *t2 = new Jet();
        assert(t2->hoursBeforeEmpty() - 3.75 < 0.01);
        assert(t2->moneyPerTime(10)-16000 < 0.01);
        assert(t2->wageToPersonnel() == 6000);
        delete t2;
}
void test_Ferry()
{

        Ferry t1;
        assert(t1.getTypeOfFuel() == "Diesel");
        Ferry t11;
        t11.setTypeOfFuel("Gasoline");
        assert (t11.getTypeOfFuel() == "Gasoline");
        t1 = t11;
        assert (t1.getTypeOfFuel() == "Gasoline");
        bool thrown = false;
        try
        {Ferry t2(-1);}
        catch (const std::runtime_error &e){thrown = true;}
        assert(thrown);
        WaterTransport *t2 = new Ferry();
        assert(t2->hoursBeforeEmpty() - 33.33 < 0.01);
        assert(t2->moneyPerTime(10)-5250 < 0.01);
        assert(t2->wageToPersonnel()-18000 < 0.01);
        delete t2;
}



int main()
{
        std::cout<<std::fixed<<std::setprecision(2);

        test_Toyota();
        test_Tesla();
        test_Jet();
        test_Ferry();
return 0;
}





