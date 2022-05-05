#include<iostream>
#include<algorithm>
#include"../inc/field.hpp"
//#include"../inc/attributes.hpp" // ???


// --- getters/setters ---
list<unique_ptr<Bunny>>& Field::GetBunnyList() { return bunnyList; }


// ---add/remove ---
void Field::AddBunny(/* unique_ptr<Bunny>& u_ptr */)
{
   /*  (u_ptr == NULL) ? GetBunnyList().push_front(std::make_unique<Bunny>())
        : GetBunnyList().push_front(std::make_unique<Bunny>(u_ptr->GetColour())); */
    GetBunnyList().push_front(std::make_unique<Bunny>());
    // use iterator pointing to first bunny in list to output a birth statement here
    bunnyCount++;
}

void Field::RmBunny(unique_ptr<Bunny>& u_ptr)
{
    (u_ptr->GetIsMutant()) ? std::cout << "Radioactive Mutant Vampire Bunny " << u_ptr->GetName() << " died!\n" 
        : std::cout << "Bunny " << u_ptr->GetName() << " died!\n";
    GetBunnyList().remove(u_ptr);
    bunnyCount--;
}


// --- advance ---
void Field::IncrementAges()
{
    for(unique_ptr<Bunny>& u_ptr : GetBunnyList())
    {
        u_ptr->SetAge(u_ptr->GetAge() + 1);
/*         if(u_ptr->GetSex() == SexesMap[Sexes::Male] && u_ptr->GetAge() >= adultAge && !u_ptr->GetIsMutant())
            adultMaleExists = true; */
        if(!u_ptr->GetIsMutant() && u_ptr->GetAge() > lifespan) 
            RmBunny(u_ptr); 
        else if(u_ptr->GetIsMutant() && u_ptr->GetAge() > mutantLifespan)
            RmBunny(u_ptr);
    }
}

/* void Field::Breed()
{
    if(!adultMaleExists) { return; }
    for(unique_ptr<Bunny>& u_ptr : GetBunnyList())
    {
        if(u_ptr->GetSex() == SexesMap[Sexes::Female] && u_ptr->GetAge() >= adultAge && !u_ptr->GetIsMutant())
        {

        }
    }
}
 */

// --- utility ---
void Field::Initialise()
{
    for(int i=0; i<initCount; i++) { AddBunny(/*NULL*/); }
}

void Field::PrintBunnies()
{
    for(unique_ptr<Bunny>& u_ptr : GetBunnyList())
        std::cout << "Bunny " << u_ptr->GetName() << " is in the field.\n"; 
}