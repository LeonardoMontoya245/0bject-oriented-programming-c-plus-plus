
#include <iostream> 
#include "RPG.h"

using namespace std; 

/**
 * @brief prints both player's name and their health. 
 * Example Output for name Wiz and NPC
 * Wiz health: 75 NPC health: 100\n  
 * 
 * @param player1 
 * @param player2 
 */
void displayStats(RPG player1, RPG player2){ 


    printf("%s Health: %i ", player1.getName().c_str(), player1.getHealth()); 

    printf("%s Health: %i ", player2.getName().c_str(), player2.getHealth()); 
} 

/**
 * @brief Display who wins based on who is alive. use an if statement to check wether
 * Player 1 is alive. if so, print that they win else player 2 won. 
 *  
 * Example Output: 
 * Wiz defeated NPC! Good game!\n 
 * 
 * @param player1
 * @param player2 
 */
void displayEnd(RPG player1, RPG player2){ 

    if (player1.isAlive()){
        printf("%s defeated %s", player1.getName().c_str(), player2.getName().c_str()); 
    } else {
        printf("%s defeated %s", player2.getName().c_str(), player1.getName().c_str());   
     }
}
/**
 * @brief uses a while loop to check whether both player are alive 
 * if so, it calls displayStats((*player1), (*player2)) 
 * Inside the while loop it: 
 * then call (*player1).useSkill(player2)
 * then print "---------------\n"
 * 
 * repeat the process for player 2 acting on player 1 inside the same while loop
 * then prints the name of player to to say that it their turn 
 * then call (*player2).useSkill(player1)
 * then print "---------------\n"
 * 
 * Refer to the role playing game part two instructions for the 
 * example output 
 * 
 * @param player1 
 * @param player2 
 */
void gameLoop(RPG * player1, RPG * player2){

    while (player1->isAlive() && player2->isAlive()){
         
        displayStats((*player1), (*player2)); 

        (*player1).useSkill(player2); 

        printf("---------------\n");  

        displayStats((*player1), (*player2)); 
        
        (*player2).useSkill(player1); 

         printf("---------------\n"); 

    }   


}

int main() {

    RPG p1 = RPG("Wiz", 70, 45, 5, "mage"); 
    RPG p2 = RPG(); 

    gameLoop(&p1, &p2); 
    displayEnd(p1, p2);

    return 0; 
}

