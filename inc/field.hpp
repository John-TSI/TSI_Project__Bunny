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
        int bunnyCount = 0, idCount = 0;
        list<unique_ptr<Bunny>> bunnyList = {};

    public:
        Field();

        // --- getters/setters ---
        int GetBunnyCount() const;
        void SetBunnyCount(int);
        list<unique_ptr<Bunny>>& GetBunnyList();

        // --- add/remove ---
        void AddBunny();
        void RmBunny(int);
        void RmBunny(unique_ptr<Bunny>&);

        // --- advance methods ---
        void IncrementAge();
        void Breed();

        // --- utility ---
        void Initialise();
        void PrintBunnies();

};

#endif