#ifndef POKEMON_H 
#define POKEMON_H 

#include <string> 
#include <vector> 
using namespace std; 

class pokemon{

    public: 
        // ------------- Constructors ------------
        pokemon(); 
        pokemon(string name, int hp, int att, int def, vector<string> type ); 
        // -------------- mutator Funcations ------------
        virtual void speak(); 
        virtual void printStats(); 
        // ------------- Accessor Funcations ------------

    private:
        string name; 
        int hp; 
        int attack; 
        int defense; 
        vector<string> type; 
}; 
#endif
