

#include <iostream> 
#include "RPG.h"

using namespace std; 

int main() 
{
    RPG p1 = RPG("wiz", 70, 45, 15,"mage");
    RPG p2 = RPG(); 

    printf("%s Current stats\n", p1.getname().c_str());
    printf("Health: %i\t Strengh: %i\t Defense: %i\t", p1.getHealth(), p1.getStrengh(), p1.getDefense()); 

    printf("%s Current states\n", p2.getName().c_str());
    printf("Health: %i\t Strengh: %i\t Defense: %i\t", p2.getHealth(), p2.getStrengh(), p2.getDefense());

    p1.updateHealth(0); 
    
    printf(p1.getHealth()); 

    p1.isAlive();
    p2.isAlive();  

    return 0; 
}