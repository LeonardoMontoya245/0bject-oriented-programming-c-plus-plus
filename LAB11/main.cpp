#include <iostream> 
#include "Charmander.h" 
using namespace std; 

int main(){

    // Charmander first = charmander() 
    vector<string> pokemonType;  
    pokemonType.push_back("Fire"); 

    vector<string> skills; 
    skills.push_back("Growl"); 
    skills.push_back("Scratch"); 

    cout << "------------- Constructor Created ----------\n"; 
    Charmander charlie = Charmander("Charlie", 100, 4, 4, pokemonType,skills ); 
    // Charmander 

    cout << "\n------------ Direct speak -------------\n"; 
    charlie.speak(); 
    // pokemon pointer to charmander 

    pokemon * p1 = &charlie; 

    cout << "\n----------- Speak called from Pokemon Pointer ---------\n"; 

    (*p1).speak();  

    Charmander * c1 = &charlie; 

    cout << "\n-------- print stats -----------\n"; 

    (*c1).speak(); 

    charlie.printStats(); 


}