#include<iostream>
#include<algorithm>
#include"../inc/field.hpp"


// --- constructors ---
Field::Field() {}


// --- getters/setters ---
int Field::GetBunnyCount() const { return bunnyCount; }
void Field::SetBunnyCount(int input) { bunnyCount = input; }
list<unique_ptr<Bunny>>& Field::GetBunnyList() { return bunnyList; }


// ---add/remove ---
void Field::AddBunny()
{
    GetBunnyList().push_front(std::make_unique<Bunny>(idCount));
    bunnyCount++;
    idCount++;
}

void Field::RmBunny(int id)
{
    list<unique_ptr<Bunny>>& bList = GetBunnyList();
    bList.erase(std::remove_if(begin(bList), end(bList), 
        [id](const unique_ptr<Bunny>& u_ptr) { return (*u_ptr).GetID() == id; }), end(bList));
}


// --- advance methods ---
void Field::IncrementAge()
{
    for(unique_ptr<Bunny>& u_ptr : GetBunnyList())
    {
        u_ptr->SetAge(u_ptr->GetAge() + 1);
        if( (!u_ptr->GetIsMutant() && u_ptr->GetAge() > 10) || (u_ptr->GetIsMutant() && u_ptr->GetAge() > 49) ) 
        { 
            RmBunny(u_ptr->GetID()); 
        }
    }
}

void Field::Breed()
{

}


// --- utility ---
void Field::Initialise()
{
    list<unique_ptr<Bunny>>& bList = GetBunnyList();
    for(int i=0; i<5; i++) { AddBunny(); }
}

void Field::PrintBunnies()
{
    for(unique_ptr<Bunny>& u_ptr : GetBunnyList())
        std::cout << "Bunny number " << u_ptr->GetID() << " is in the field." << std::endl; 
}