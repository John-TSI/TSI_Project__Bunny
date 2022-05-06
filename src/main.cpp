#include<iostream>
#include<time.h>
#include"../inc/field.hpp"


// --- TO-DO ---
// - remove AddBunny()? Use Initialise() and Breed() methods only?


int main()
{   srand(time(NULL)); // seed rand()

    Field F;
    F.Initialise();

    char input = 'z';
    while(input != 'q' && F.GetBunnyCount() > 0)
    {
/*         F.PrintBunnies();
        F.IncrementAges();
        F.Breed();
        F.SpreadInfection(); */

/*         F.IncrementAges();
        F.Breed();
        F.PrintBunnies();
        F.SpreadInfection(); */

        F.Breed();
        F.PrintBunnies();
        F.IncrementAges();
        F.SpreadInfection();

        std::cout << "Press any key to advance (q to quit):\n> ";
        std::cin >> input;
    }
    std::cout<< "All Bunnies have died.\n";

    return 0;
}