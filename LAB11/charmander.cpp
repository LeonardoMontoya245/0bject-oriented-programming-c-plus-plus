#include <iostream>
#include <stdio.h>
#include "Charmander.h" 
/**
 * @brief construct a new Charmander:: Charmander object 
 * 
 * 
 */
Charmander:: Charmander() : pokemon(){ 
    type.push_back("Fire"); 
    skills.push_back("Growl"); 
    skills.push_back("Scratch"); 

    cout << "Default Constructor (Charmander)\n"; 

}

/**
 * @brief construct a new Charmander :: Charmander object 
 * 
 * @param name 
 * @param hp 
 * @param att 
 * @param def 
 * @param t 
 * 
 */
Charmander::Charmander(string name, int hp, int att, int def, vector<string> t, vector<string> s) : 
 pokemon(name, hp, att, def, t){
        type = t; 
        skills = s;
        cout << "Overloaded Constructor (Charmander)\n"; 

    } 

/**
 * @brief says what a charmander says 
 * 
 * 
 */
void Charmander::speak(){
    cout << "Charmander - char\n"; 
}

/**
 * @brief calls printStats from the parent class (pokemom) and appends the skills used for charmander 
 * 
 * 
 */
void Charmander::printStats(){
    pokemon::printStats();
    cout << "Skills: "; 
    for(int i = 0; i < skills.size(); i++){
        cout << skills[i] << "\t"; 
    }
}



