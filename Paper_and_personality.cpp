#include <random>

using namespace std;

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
    Paper();
    ~Paper();
    int generateCitations(float intelligence, int focus, float risk);
    int SubmitPaper(float intelligence, int focus, float risk);
    void GeneratePaperAfterSuccess(float intelligence, int focus, float risk);
    int getCitations();
    string getJournal();
    
private:
    int citations;
    string journal;
    string title;
};

Personality::Personality(){
    this->intelligence = 0;
    this->optimism = 0;
    this->stamina = 0;
}

Personality::~Personality(){
    
}


//knowledge, prestige, and mentoring all from advisor class
void Personality::generatePersonality(float knowledge, float prestige, float mentoring){

    // This function will need to be changed for game balancing
    float int_mean=50 + (knowledge*0.1) + (prestige*0.2) + (mentoring*0.15);
    float stam_mean=50;
    float opt_mean = 50 + (mentoring*0.2);
    float int_dev=10, stam_dev=10, opt_dev=10;

    default_random_engine generator;
    normal_distribution<float> int_distribution(int_mean, int_dev);
    normal_distribution<float> stam_distribution(stam_mean, stam_dev);
    normal_distribution<float> opt_distribution(opt_mean, opt_dev);

    this->intelligence = int_distribution(generator);
    this->stamina = stam_distribution(generator);
    this->optimism = opt_distribution(generator);

    float attrs[3] = {this->intelligence, this->stamina, this->optimism};
    for(int i=0; i<3; i+=1){
        if(attrs[i] > 100){
            attrs[i] = 100;
        }
        else if(attrs[i]<0){
            attrs[i] = 0;
        }
    }
}

// getter for personality value. This getter should be used by the Student class
// The personality value should affect changes in mood, GPA, etc., in a student
float Personality::getIntelligence(){
    return this->intelligence;
}

float Personality::getOptimism(){
    return this->optimism;
}

float Personality::getStamina(){
    return this->stamina;
}

Paper::~Paper(){
}

int SubmitPaper(float intelligence, float focus, float risk){
    // risk is a value between 0 and 1 (from lowest risk paper submission to highest risk (1 is Nature))
    
    default_random_engine generator;
    float multiplier = 0;
    if(focus){
        multiplier += 0.2;
    }
    // other multipliers here
    
    normal_distribution<float> accept_distribution(intelligence + multiplier*8, 20.0 - risk*5.0);
    float acceptance = accept_distribution(generator);
    if(acceptance > risk*100.0){
        return 1;
    }
    
    return 0;
}

Paper::Paper(){
    this->citations = 0;
    this->journal = "";
    this->title = "";
}

void GeneratePaperAfterSuccess(float intelligence, int focus, float risk){

    this->citations = generateCitations(intelligence, focus, risk);

    if(risk>=0 && risk<0.1){
        this->journal = "The Tartan"
    }
    if(risk>=0.1 && risk<0.2){
        this->journal = "Buzzfeed News";
    }
    if(risk>=0.2 && risk<0.3){
        this->journal = "Journal of Tourism Resarch and Hospitality";
    }
    if(risk>=0.3 && risk<0.4){
        this->journal = "Magazine of Concrete Research";
    }
    if(risk>=0.4 && risk<0.5){
        this->journal = "arXiv";
    }
    if(risk>=0.5 && risk<0.6){
        this->journal = "Proceedings of the Royal Society";
    }
    if(risk>=0.6 && risk<0.7){
        this->journal = "Reviews of Modern Science";
    }
    if(risk>=0.7 && risk<0.8){
        this->journal = "Cell";
    }
    if(risk>=0.8 && risk<0.9){
        this->journal = "Science";
    }
    if(risk>=0.9 && risk<1.0){
        this->journal = "Nature";
    }

}

int Paper::generateCitations(float intelligence, int focus, float risk){
    // will need to be changed later for balancing
    
    default_random_engine generator;
    float mean = intelligence + risk*500;
    if(focus){
        mean *= 2;
    }
    normal_distribution<float> cit_distribution(mean, 20);
    
    return (int)cit_distribution(generator);
}

int Paper::getCitations(){
    // getter for number of citations
    return citations;
}

string Paper::getJournal(){
    // getter for name of journal
    return journal;
}

