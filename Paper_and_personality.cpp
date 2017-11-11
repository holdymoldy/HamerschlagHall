#include<iostream>
#include <random>

using namespace std;

class Student{};

// Personalities will be owned by Student but will be generated outside of Student class
class Personality{
public:
    Personality();
    ~Personality();
    void generatePersonality(const Advisor &advisor);
    float getIntelligence();
    float getOptimism();
    float getStamina();
    
private:
    float intelligence;
    float optimism;
    float stamina;
};

void Personality::generatePersonality(const Advisor &advisor){
    
    // This function will need to be changed for game balancing
    float int_mean=50 + (advisor.knowledge*0.1) + (advisor.prestige*0.2) + (advisor.mentoring*0.15)
    float stam_mean=50;
    float opt_mean = 50 + (advisor.mentoring*0.2);
    float int_dev=10, stam_dev=10, opt_dev=10;
    
    default_random_engine generator;
    normal_distribution<float> int_distribution(int_mean, int_dev);
    normal_distribution<float> stam_distribution(stam_mean, stam_dev);
    normal_distribution<float> opt_distribution(opt_mean, opt_dev);
    
    intelligence = int_distribution(generator);
    stamina = stam_distribution(generator);
    optimism = opt_distribution(generator);

    int attrs[3] = {intelligence, stamina, optimism};
    for(int i=0; i<3; i+=1){
        if attrs[i] > 100:
            attrs[i] = 100;
        else if attrs[i]<0:
            attrs[i] = 0;
    }
}

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

class Paper{
public:
    Paper();
    Paper(const Student &student);
    ~Paper();
    void generateCitations(const Student &student);
    int getCitations();
    string getJournal();
    
private:
    int citations;
    string journal;
};

Paper::Paper(){}

Paper::Paper(const Student &student, float risk){
    // constructor for paper class based on attributes of student
    // should call Paper::generateCitations class method
    
    
    
}

void Paper::generateCitations(const Student &student){
    // generates number of citations based on student's attributes
    // also generates journal to which it was accepted
}

int Paper::getCitations(){
    // getter for number of citations
    return citations;
}

string Paper::getJournal(){
    // getter for name of journal
    return journal;
}
