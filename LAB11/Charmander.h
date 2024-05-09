#include <string> 
#include <vector> 
#include "pokemon.h"
using namespace std; 

 class Charmander : public pokemon{ 
    public: 
        // ----------- Constructors -------------
        Charmander(); 
        Charmander(string name, int hp, int att, int def, vector<string> t, vector< string> s ); 
        // ----------- Mutator Funcation ----------
        void speak(); /*override*/
        void printStats(); /*override*/ 
    private: 
        vector<string> skills; 
        
}; 
