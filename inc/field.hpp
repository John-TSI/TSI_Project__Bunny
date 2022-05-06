#ifndef FIELD_HPP
#define FIELD_HPP

#include<list>
#include<memory>
#include<string>
#include<map>
#include"bunny.hpp"


using std::list; using std::unique_ptr; using _Bunny::Bunny;


class Field
{
    private:
        const int initCount = 5, maxCount = 1000;
        const int adultAge = 2, lifespan = 10, mutantLifespan = 49;
        int bunnyCount = 0;
        bool adultMaleExists = false;
        list<unique_ptr<Bunny>> bunnyList = {};

    public:
        // --- getters/setters ---
        int GetBunnyCount() const;
        void SetBunnyCount(int);
        list<unique_ptr<Bunny>>& GetBunnyList();

        // --- add/remove ---
        void AddBunny();
        void AddBunny(string);
        //void RmBunny(unique_ptr<Bunny>&);
        void RmBunny(list<unique_ptr<Bunny>>::iterator&);

        // --- utility ---
        void Initialise();
        bool CheckBreedMalesExist();
        void PrintBunnies();

        // --- advance ---
        void IncrementAges();
        void Breed();
};

#endif