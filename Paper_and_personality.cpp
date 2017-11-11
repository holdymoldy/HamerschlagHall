#include <random>
#include "Paper_and_personality.hpp"

using namespace std;


Personality::Personality(){
    
}

Personality::~Personality(){
    
}


//void Personality::generatePersonality(const Advisor &advisor){
//
//    // This function will need to be changed for game balancing
//    float int_mean=50 + (advisor.Knowledge*0.1) + (advisor.Prestige*0.2) + (advisor.Mentoring*0.15);
//    float stam_mean=50;
//    float opt_mean = 50 + (advisor.Mentoring*0.2);
//    float int_dev=10, stam_dev=10, opt_dev=10;
//
//    default_random_engine generator;
//    normal_distribution<float> int_distribution(int_mean, int_dev);
//    normal_distribution<float> stam_distribution(stam_mean, stam_dev);
//    normal_distribution<float> opt_distribution(opt_mean, opt_dev);
//
//    float intelligence = int_distribution(generator);
//    float stamina = stam_distribution(generator);
//    float optimism = opt_distribution(generator);
//
//    float attrs[3] = {intelligence, stamina, optimism};
//    for(int i=0; i<3; i+=1){
//        if(attrs[i] > 100){
//            attrs[i] = 100;
//        }
//        else if(attrs[i]<0){
//            attrs[i] = 0;
//        }
//    }
//}

// getter for personality value. This getter should be used by the Student class
// The personality value should affect changes in mood, GPA, etc., in a student
float Personality::getIntelligence(){
    return intelligence;
}

float Personality::getOptimism(){
    return optimism;
}

float Personality::getStamina(){
    return stamina;
}


Paper::Paper(){}

//Paper::Paper(const GradStudent &student, float risk){
//    // constructor for paper class based on attributes of student
//    // should call Paper::generateCitations class method
//
//}
//
//void Paper::generateCitations(const GradStudent &student){
//    // generates number of citations based on student's attributes
//    // also generates journal to which it was accepted
//}

int Paper::getCitations(){
    // getter for number of citations
    return citations;
}

string Paper::getJournal(){
    // getter for name of journal
    return journal;
}

