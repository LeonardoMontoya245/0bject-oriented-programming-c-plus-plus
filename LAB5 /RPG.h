
#include <string> 
#ifndef RPG_H
#define RPG_H  
using namespace std; 

const int SKILL_SIZE = 2; 

class RPG{
    public: 
        //constructors 
        RPG(); 
        RPG(string name, int health, int strength, int defense, string type);

        // complete the rest
        void getName(string name);
        void getHealth(int health); 
        void getStrengh(int strength);  
        void getDefense(int defense); 
        void setSkills(); 
        void printAction(string skill, RPG opponent); 
        
        

        string getName() const;  
        int getHealth() const;
        int getStrengh() const;
        int getDefense() const; 
        void updateHealth(int); 
        bool isAlive() const; 
        



    private: 
        // complete the rest 
        string name; 
        int health; 
        int strength; 
        int defense; 
        string type; // warrior, mage, thief, archer
        string skills[SKILL_SIZE]; 
};  
#endif 