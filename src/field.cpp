#include<iostream>
#include<algorithm>
#include"../inc/field.hpp"


// --- getters/setters ---
int Field::GetBunnyCount() const { return bunnyCount; }
void Field::SetBunnyCount(int input) { bunnyCount = input; }
list<unique_ptr<Bunny>>& Field::GetBunnyList() { return bunnyList; }


// --- add/remove ---
void Field::AddBunny()
{
    GetBunnyList().push_front(std::make_unique<Bunny>());
    list<unique_ptr<Bunny>>::iterator it = GetBunnyList().begin();
    if((*it)->GetIsMutant())
    {
        std::cout << "Radioactive Mutant Vampire Bunny " << (*it)->GetName() << " was born!\n";
    } 
    else
    { 
        std::cout << "Bunny " << (*it)->GetName() << " was born!\n";
    }
     SetBunnyCount(GetBunnyCount() + 1);
}
void Field::AddBunny(string colour)
{
    GetBunnyList().push_front(std::make_unique<Bunny>(colour));
    list<unique_ptr<Bunny>>::iterator it = GetBunnyList().begin();
    if((*it)->GetIsMutant())
    {
        std::cout << "Radioactive Mutant Vampire Bunny " << (*it)->GetName() << " was born!\n";
    } 
    else
    { 
        std::cout << "Bunny " << (*it)->GetName() << " was born!\n";
    }
     SetBunnyCount(GetBunnyCount() + 1);
}

/* void Field::RmBunny(unique_ptr<Bunny>& u_ptr)
{
    if(u_ptr->GetIsMutant())
    {
        std::cout << "Radioactive Mutant Vampire Bunny " << u_ptr->GetName() << " died!\n";
    } 
    else
    { 
        std::cout << "Bunny " << u_ptr->GetName() << " died!\n";
    }
    GetBunnyList().remove(u_ptr);
    SetBunnyCount(GetBunnyCount() - 1); 
} */
void Field::RmBunny(list<unique_ptr<Bunny>>::iterator& it)
{
    const unique_ptr<Bunny>& u_ptr = *it;
    if(u_ptr->GetIsMutant())
    {
        std::cout << "Radioactive Mutant Vampire Bunny " << u_ptr->GetName() << " died!\n";
    } 
    else
    { 
        std::cout << "Bunny " << u_ptr->GetName() << " died!\n";
    }
    bunnyList.erase(it++);
    bunnyCount--;
}


// --- utility ---
void Field::Initialise()
{
    for(int i=0; i<initCount; i++) { AddBunny(); }
}

bool Field::CheckBreedMalesExist()
{
    for(unique_ptr<Bunny>& u_ptr : GetBunnyList())
    {
        if((u_ptr->GetSex() == /*SexesMap[Sexes::Male]*/"Male") && (u_ptr->GetAge() >= adultAge) && !(u_ptr->GetIsMutant()) )
            return true;
    }
    return false;
}

void Field::PrintBunnies()
{
    std::cout << "\nList of Bunnies in the field:\n";
    std::cout << "-----------------------------\n";
    for(unique_ptr<Bunny>& u_ptr : GetBunnyList())
    {
        string status = (u_ptr->GetIsMutant()) ? "Radioactive Mutant Vampire Bunny " : "Bunny ";
        string name = u_ptr->GetName();
        int age = u_ptr->GetAge();
        string sex = u_ptr->GetSex();
        string colour = u_ptr->GetColour();

        std::cout << status << name << " (Age: " << age << ", Sex: " << sex << ", Colour: " << colour << ")\n";
    }
    std::cout << "\n";
}


// --- advance ---
void Field::IncrementAges()
{
/*     for(unique_ptr<Bunny>& u_ptr : GetBunnyList())
    {
        u_ptr->SetAge(u_ptr->GetAge() + 1); 
        if(!u_ptr->GetIsMutant() && u_ptr->GetAge() > lifespan) 
        { 
            RmBunny(u_ptr);
            break; 
        }
        else if(u_ptr->GetIsMutant() && u_ptr->GetAge() > mutantLifespan)
        { 
            RmBunny(u_ptr);
            break;
        }
    }  */ 
    list<unique_ptr<Bunny>>::iterator it = bunnyList.begin();
    while(it!=bunnyList.end())
    {
        const unique_ptr<Bunny>& u_ptr = *it;
        u_ptr->SetAge(u_ptr->GetAge() + 1); 
        if(!u_ptr->GetIsMutant() && u_ptr->GetAge() > lifespan) 
        { 
            RmBunny(it);
            continue; 
        }
        else if(u_ptr->GetIsMutant() && u_ptr->GetAge() > mutantLifespan)
        { 
            RmBunny(it);
            continue;
        }
        ++it;
    }
}

void Field::Breed()
{
    if(!CheckBreedMalesExist()) { return; }
    for(unique_ptr<Bunny>& u_ptr : GetBunnyList())
    {
        if(u_ptr->GetSex() == /*SexesMap[Sexes::Female]*/"Female" && u_ptr->GetAge() >= adultAge && !u_ptr->GetIsMutant())
        {
            AddBunny(u_ptr->GetColour());
        }
    }
}
