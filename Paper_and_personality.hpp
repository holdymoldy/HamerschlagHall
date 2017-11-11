//
//  Paper_and_personality.hpp
//  Eng_Comp
//
//  Created by Holden Parks on 11/11/17.
//  Copyright © 2017 Holden Parks. All rights reserved.
//

#ifndef Paper_and_personality_hpp
#define Paper_and_personality_hpp

#include <stdio.h>
#include<iostream>
//#include "Advisor-Action.hpp"
//#include "graduateStudent.hpp"

using namespace std;


// Personalities will be owned by Student but will be generated outside of Student class
class Personality{
public:
    Personality();
    ~Personality();
//    void generatePersonality(const Advisor &advisor);
    float getIntelligence();
    float getOptimism();
    float getStamina();
    
private:
    float intelligence;
    float optimism;
    float stamina;
};

class Paper{
public:
    Paper();
//    Paper(const GradStudent &student);
    ~Paper();
//    void generateCitations(const GradStudent &student);
    int getCitations();
    string getJournal();
    
private:
    int citations;
    string journal;
};

#endif /* Paper_and_personality_hpp */
