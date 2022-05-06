#include<iostream>
#include<time.h>
#include"../inc/field.hpp"
#include"../inc/bunny.hpp"

using _Bunny::Bunny;

// --- TO-DO ---
// - remove AddBunny()? Use Initialise() and Breed() methods only?


int main()
{   srand(time(NULL)); // seed rand()

    Field F;
    F.Initialise();

    char input = 'z';
    while(input != 'q' && F.GetBunnyCount() > 0)
    {
        F.PrintBunnies();
        F.IncrementAges();
        F.Breed();

        std::cout << "Press any key to advance (q to quit):\n";
        std::cin >> input;
    }
    std::cout<< "All Bunnies have died.\n";


    return 0;
}