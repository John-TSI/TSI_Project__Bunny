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
        list<unique_ptr<Bunny>>& GetBunnyList();

        // --- add/remove ---
        void AddBunny(/*unique_ptr<Bunny>&*/);
        void RmBunny(unique_ptr<Bunny>&);

        // --- advance ---
        void IncrementAges();
        void Breed();

        // --- utility ---
        void Initialise();
        void PrintBunnies();

};

#endif