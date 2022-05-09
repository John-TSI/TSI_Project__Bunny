#include<iostream>
#include<iomanip>
#include<algorithm>
#include"../inc/field.hpp"


// --- getters/setters ---
int Field::GetBunnyCount() const { return bunnyCount; }


// --- add/remove ---
void Field::AddBunny(const unique_ptr<Bunny>& u_ptr) // add Bunny object to Field attribute bunnyList
{
    bunnyList.push_front(std::make_unique<Bunny>(u_ptr));
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

void Field::RmBunny(list<unique_ptr<Bunny>>::iterator& it) // remove Bunny object from Field attribute bunnyList
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
void Field::Initialise() // construct initial five Bunny objects
{
    const unique_ptr<Bunny> u_ptr = nullptr;
    for(int i=0; i<initCount; i++) { AddBunny(u_ptr); }
}

bool Field::CheckBreedMaleExists() // returns bool for existence of suitable Male to Breed()
{
    list<unique_ptr<Bunny>>::iterator it = bunnyList.begin();
    while(it!=bunnyList.end())
    {
        const unique_ptr<Bunny>& u_ptr = *it;
        if((u_ptr->GetSex() == _Bunny::Sex::Male) && (u_ptr->GetAge() >= adultAge) && !(u_ptr->GetIsInfected()) )
        { 
            return true; 
        }
        ++it;
    } 
    return false;
}

void Field::MassCull() // removes random half of Bunny objects from Field attribute bunnyList
{
    int deadCount = ( (bunnyCount%2 == 0) ? (bunnyCount/2) : (bunnyCount + 1)/2 );
    for (int i = 0; i < deadCount; i++)
    {
        list<unique_ptr<Bunny>>::iterator it = bunnyList.begin();
        advance(it, rand()%bunnyList.size());
        RmBunny(it);
    }
}


// --- advance ---
void Field::SpreadInfection()
{
    // update infectedCount if all Bunny objects are infected
    if(allInfected)
    {
        infectedCount = bunnyCount;
        return;
    }
    // infect all Bunny objects if at least half of previous turn's population was infected
    list<unique_ptr<Bunny>>::iterator it = bunnyList.begin();
    if(infectedCount >= ( (bunnyCount%2 == 0) ? (bunnyCount/2) : (bunnyCount + 1)/2) )
    {
        allInfected = true;
        while(it!=bunnyList.end())
        {
            const unique_ptr<Bunny>& u_ptr = *it;
            if(!u_ptr->GetIsInfected()) { u_ptr->SetIsInfected(true); }
            ++it;
        }
        infectedCount = bunnyCount;
        return;
    }
    // infect one additional Bunny object for every currently infected
    int newInfected = 0;
    while(newInfected<infectedCount)
    {
        if(!(*it)->GetIsInfected())
        {
            (*it)->SetIsInfected(true);
            newInfected++;
        }
        ++it; 
    }
    infectedCount+=newInfected;
}

void Field::IncrementAges() // increment Bunny.age, remove from bunnyList if too old
{ 
    if(initialTurn) { return; }
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

void Field::Breed() // create one additional Bunny for each suitable Female in the population
{
    if(!(CheckBreedMaleExists()) || allInfected) { return; }
    list<unique_ptr<Bunny>>::iterator it = bunnyList.begin();
    while(it!=bunnyList.end())
    {
        const unique_ptr<Bunny>& u_ptr = *it;
        if((u_ptr->GetSex() == _Bunny::Sex::Female) && (u_ptr->GetAge() >= adultAge) && !(u_ptr->GetIsInfected()))
        {
            AddBunny(u_ptr);
        }
        ++it;
    }
}

void Field::PrintBunnies() // output info to the User
{
    if(initialTurn) { return; }
    std::cout << "\nList of Bunnies in the field:\n";
    std::cout << "-----------------------------\n";
    for(unique_ptr<Bunny>& u_ptr : bunnyList)
    {
        string status = (u_ptr->GetIsInfected()) ? "Infected Bunny " : "Bunny ";
        string name = u_ptr->GetName();
        int age = u_ptr->GetAge();
        string sex = _Bunny::SexesMap[u_ptr->GetSex()];
        string colour = _Bunny::ColoursMap[u_ptr->GetColour()];

        std::cout << status << name << std::setw(16 - name.length()) << " (Age: " << age << ", Sex: " << sex << ", Colour: " << colour << ")\n";
    }
    if(allInfected)
    {
        std::cout << "\nAll " << bunnyCount << " Bunnies are infected!\n";
    }
    else
    {
        std::cout << "\n" << infectedCount << " of " << bunnyCount << " Bunnies are infected.\n";
    }
}

char Field::Advance() // advance program by one turn, return User input to main()
{
    SpreadInfection();
    IncrementAges();
    Breed();
    if(bunnyCount > maxCount)
    { 
        std::cout << "\nMaximum sustainable population exceeded, a food shortage occurs.\n\n";
        MassCull(); 
    }
    PrintBunnies();

    initialTurn = false;
    char input = 'b';
    std::cout << "\nPress k to initiate a mass cull, or any other key to advance (q to quit):\n> ";
    std::cin >> input;
    std::cout << "\n";
    while(input == 'k')
    {
        MassCull();
        std::cout << "\nPopulation has been culled!\n\n";
        std::cout << "\nPress k to initiate another mass cull, or any other key to advance (q to quit):\n> ";
        std::cin >> input;
        std::cout << "\n";
    }
    return input;
}
