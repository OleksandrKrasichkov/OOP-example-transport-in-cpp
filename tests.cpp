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
        }catch (const std::runtime_error&) {
                thrown = true;
        }
        assert(thrown);
        Car* t2 = new Toyota();
        assert (t2->hoursBeforeEmpty() == 6.25);          
        assert (t2->moneyPerTime(10) == 240);
        assert (t2->wageToPersonnel() == 1000);

        delete t2;
}



int main()
{
        std::cout<<std::fixed<<std::setprecision(2);

        test_Toyota();
return 0;
}





