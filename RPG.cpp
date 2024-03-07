#include "RPG.H"
#include "RPG.h"

RPG::RPG() 
{
    name = "NPC";
    health = 100;
    strength = 10; 
    defense = 10;
    type = "warrior"; 
    skills[0] = "slash";
    skills[1] = "parry"; 
}

RPG::RPG(string name, int health, int strength, int defense, string type)
{
    this -> name = name; 
    this -> health = health; 
    this -> strength = strength; 
    this -> defense = defense; 
    setSkills(); 

}


void RPG::getName(string name)
{
     name = name; 
}

void RPG::getHealth(int health)
{
    health = health; 
}

void RPG::getStrengh(int strength)
{
    strength = strength; 
}

void RPG::getDefense(int defense)
{
    defense = defense;  
}




/**
 * @brief set the skills based on the RPG's role 
 * 
 */
void RPG::setSkills() 
{
    if (type == "mage"){
        skills[0] = "fire";
        skills [1] = "thunder"; 
    } else if (type == "thief"){
        skills[0] = "pilfer";
        skills[1] = "jab";     
    } else if (type == "archer"){
        skills[0] = "parry";
        skills [1] = "crossbow_attack";
    } else {
        skills[0] = "slash";
        skills[1] = "parry";
    }
    
}
/**
 * @brief prints along tge lines of name used skill on opponent 
 * 
 * @param skill 
 * @param opponent 
 */

void RPG::printAction(string skill, RPG opponent) 
{
    printf("%s used %s on %s\n", name.c_str(), skill.c_str(), opponent.getName().c_str()); 
}


string RPG::getName() const
{
    return name; 
}

int RPG::getHealth() const
{
    return health; 
}

int RPG::getStrengh() const
{
    return strength; 
}

int RPG::getDefense() const 
{
    return defense; 
}

/**
 * @brief updates health into new_health 
 * 
 * @param new_health 
 */ 
void RPG::updateHealth(int new_health){

    health = new_health; 
}

/**
 * @brief return whether health is greater than 0 
 * 
 * @return true 
 * @return false 
 */
bool RPG::isAlive() const {
    if (health > 0) {
        return true;
    } else {
        return false; 
    }
    // return health>0;
    
}