#ifndef FIELD_HPP
#define FIELD_HPP

#include<list>
#include"bunny.hpp"

using std::list; using std::unique_ptr; using _Bunny::Bunny;


class Field
{
    private:
        static const int initCount = 5, maxCount = 1000;
        static const int adultAge = 2, lifespan = 10, infectedLifespan = 49;
        int bunnyCount = 0, infectedCount = 0;
        bool initialTurn = true, adultMaleExists = false, allInfected = false;
        list<unique_ptr<Bunny>> bunnyList = {};

    public:
        // --- getters/setters ---
        int GetBunnyCount() const;

        // --- add/remove ---
        void AddBunny(const unique_ptr<Bunny>&);
        void RmBunny(list<unique_ptr<Bunny>>::iterator&);

        // --- utility ---
        void Initialise();
        bool CheckBreedMaleExists();
        void MassCull();

        // --- advance ---
        void SpreadInfection();
        void IncrementAges();
        void Breed();
        void PrintBunnies();
        char Advance();
};

#endif