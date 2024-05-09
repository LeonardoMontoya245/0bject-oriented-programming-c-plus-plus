#include <iostream>
#include "pokemon.h"

/**
 * @brief construct a new pokemon:: pokemon object 
 * 
 * 
 */
pokemon::pokemon(){
    name = "unidentified"; 
    hp = 0; 
    attack = 0; 
    defense = 0; 
    cout << "Default Constructor (pokemon)\n"; 

}
/**
 * @brief construct a new pokemon:: pokemon object 
 * 
 * @param name 
 * @param hp 
 * @param att 
 * @param def 
 * @param type 
 */
pokemon::pokemon(string name, int hp, int att, int def, vector<string> type){

    this -> name = name; 
    this -> hp = hp; 
    attack = att; 
    defense = def; 
    type = type; 
    cout << "Overloaded Constructor (pokemon)\n"; 
} 
/**
 * @brief says whatever this pokemon normally says 
 * 
 */
void pokemon::speak(){
    cout << "...\n"; 
} 

void pokemon::printStats(){
    printf("Name: %s\t HP: %i\t DEF: %i\t ATT: %i\n", name.c_str(), hp, defense, attack); 
    cout << "Type: "; 
    for(int i = 0; i < type.size(); i++){
        cout << type[i] << "\t"; 
    }
    cout << endl; 
}  




