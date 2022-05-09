#include<iostream>
#include<time.h>
#include"../inc/field.hpp"


int main()
{   
    srand(time(NULL)); // seed rand()
    Field F;
    F.Initialise();

    char input = 'b';
    while(input != 'q' && F.GetBunnyCount() > 0)
    {
        input = F.Advance();
    }
    std::cout<< "All Bunnies have died.\n";

    return 0;
}