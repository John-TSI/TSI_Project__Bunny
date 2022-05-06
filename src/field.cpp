#include<iostream>
#include<algorithm>
#include"../inc/field.hpp"
//#include"../inc/attributes.hpp"


// --- getters/setters ---
int Field::GetBunnyCount() const { return bunnyCount; }


// --- add/remove ---
void Field::AddBunny()
{
    bunnyList.push_front(std::make_unique<Bunny>());
    list<unique_ptr<Bunny>>::iterator it = bunnyList.begin();
    if((*it)->GetIsInfected())
    {
        std::cout << "Infected Bunny " << (*it)->GetName() << " was born!\n";
        infectedCount++;
    } 
    else
    { 
        std::cout << "Bunny " << (*it)->GetName() << " was born!\n";
    }
    bunnyCount++;
}
void Field::AddBunny(string colour)
{
    bunnyList.push_front(std::make_unique<Bunny>(colour));
    list<unique_ptr<Bunny>>::iterator it = bunnyList.begin();
    if((*it)->GetIsInfected())
    {
        std::cout << "Infected Bunny " << (*it)->GetName() << " was born!\n";
        infectedCount++;
    } 
    else
    { 
        std::cout << "Bunny " << (*it)->GetName() << " was born!\n";
    }
     bunnyCount++;
}

void Field::RmBunny(list<unique_ptr<Bunny>>::iterator& it)
{
    const unique_ptr<Bunny>& u_ptr = *it;
    if(u_ptr->GetIsInfected())
    {
        std::cout << "Infected Bunny " << u_ptr->GetName() << " died!\n";
        infectedCount--;
    } 
    else
    { 
        std::cout << "Bunny " << u_ptr->GetName() << " died!\n";
    }
    bunnyList.erase(it++); // erase item pointed by it, then advance iterator
    bunnyCount--;
}


// --- utility ---
void Field::Initialise()
{
    for(int i=0; i<initCount; i++) { AddBunny(); }
}

/*SexesMap[Sexes::Male]*/
bool Field::CheckBreedMaleExists()
{
    list<unique_ptr<Bunny>>::iterator it = bunnyList.begin();
    while(it!=bunnyList.end())
    {
        const unique_ptr<Bunny>& u_ptr = *it;
        if((u_ptr->GetSex() == "Male") && (u_ptr->GetAge() >= adultAge) && !(u_ptr->GetIsInfected()) )
        { 
            return true; 
        }
        ++it;
    }
    return false;
}

void Field::PrintBunnies()
{
    std::cout << "\nList of Bunnies in the field:\n";
    std::cout << "-----------------------------\n";
    for(unique_ptr<Bunny>& u_ptr : bunnyList)
    {
        string status = (u_ptr->GetIsInfected()) ? "Infected Bunny " : "Bunny ";
        string name = u_ptr->GetName();
        int age = u_ptr->GetAge();
        string sex = u_ptr->GetSex();
        string colour = u_ptr->GetColour();

        std::cout << status << name << " (Age: " << age << ", Sex: " << sex << ", Colour: " << colour << ")\n";
    }
    std::cout << "\n" << infectedCount << " of " << bunnyCount << " Bunnies are infected.\n";
}


// --- advance ---
void Field::IncrementAges()
{ 
    list<unique_ptr<Bunny>>::iterator it = bunnyList.begin();
    while(it!=bunnyList.end())
    {
        const unique_ptr<Bunny>& u_ptr = *it;
        u_ptr->SetAge(u_ptr->GetAge() + 1); 
        if(!(u_ptr->GetIsInfected()) && (u_ptr->GetAge() > lifespan)) 
        { 
            RmBunny(it);
            continue; // call to RmBunny() will advance iterator
        }
        if((u_ptr->GetIsInfected()) && (u_ptr->GetAge() > infectedLifespan))
        { 
            RmBunny(it);
            continue;
        }
        ++it;
    }
}

void Field::Breed()
{
    if(!(CheckBreedMaleExists()) || allInfected) { return; }
    list<unique_ptr<Bunny>>::iterator it = bunnyList.begin();
    while(it!=bunnyList.end())
    {
        const unique_ptr<Bunny>& u_ptr = *it;
        if((u_ptr->GetSex() == "Female") && (u_ptr->GetAge() >= adultAge) && !(u_ptr->GetIsInfected()))
        {
            AddBunny(u_ptr->GetColour());
        }
        ++it;
    }
}

void Field::SpreadInfection()
{
    if(allInfected)
    {
        std::cout << "All Bunnies have become infected!\n";
        return;
    }
    list<unique_ptr<Bunny>>::iterator it = bunnyList.begin();
    const unique_ptr<Bunny>& u_ptr = *it;
    if(infectedCount >= ((bunnyCount%2 == 0) ? (bunnyCount/2) : (bunnyCount + 1)/2) )
    {
        allInfected = true;
        while(it!=bunnyList.end())
        {
            if(!u_ptr->GetIsInfected()) { u_ptr->SetIsInfected(true); }
            ++it;
        }
        infectedCount = bunnyCount;
        return;
    }

    int newInfected = 0;
    while(newInfected<infectedCount)
    {
        if(!(*it)->GetIsInfected())
        {
            (*it)->SetIsInfected(true);
            newInfected++;
        }
        advance(it,1); 
    }
    infectedCount+=newInfected;
}
