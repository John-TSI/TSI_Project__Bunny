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
        bool initialTurn = true, adultMaleExists = false, allInfected = false, populationLimited = true;
        list<unique_ptr<Bunny>> bunnyList = {};

    public:
        // --- constructor ---
        Field();
        
        // --- getters/setters ---
        int GetBunnyCount() const;
        void SetPopulationLimit();

        // --- add/remove ---
        void AddBunny(const unique_ptr<Bunny>&);
        void RmBunny(list<unique_ptr<Bunny>>::iterator&);

        // --- utility ---
        bool BreedMaleExists();
        void MassCull(const bool);

        // --- advance ---
        void SpreadInfection();
        void IncrementAges();
        void Breed();
        void PrintBunnies();
        char Advance();
};

#endif