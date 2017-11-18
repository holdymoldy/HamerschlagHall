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
    void generatePersonality(float knowledge, float prestige, float mentoring);
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
    Paper(float intelligence, int focus, float risk);
    ~Paper();
    int generateCitations(float intelligence, int focus, float risk);
    int getCitations();
    string getJournal();
    
private:
    int citations;
    string journal;
    string journals[10] = {"The Tartan",
                            "Buzzfeed News",
                            "Journal of Tourism Research and Hospitality",
                            "Magazine of Concrete Research",
                            "arXiv",
                            "Proceedings of the Royal Society",
                            "Reviews of Modern Science",
                            "Cell",
                            "Science",
                            "Nature"};
};

#endif /* Paper_and_personality_hpp */
