#include "transport.cpp"
#include <iostream>
#include <cassert>
#include <stdexcept>

void test_Toyota()
{
        Toyota t;
        assert (t.getTypeOfFuel() == "Gasoline");
        bool thrown = false;
        try{
                Toyota t1("Crow",-10, -1);
        }catch (const std::runtime_error&) {
                thrown = true;
        }
        assert(thrown);
}



int main()
{
        test_Toyota();
return 0;
}





