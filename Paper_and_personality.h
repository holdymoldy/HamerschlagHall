
#ifndef PapPer_h
#define PapPer_h

class Paper{
public:
    Paper();
    ~Paper();
    char* journal;
    char* title;
    int generateCitations(float intelligence, int focus, float risk);
    int SubmitPaper(float intelligence, int focus, float risk);
    void GeneratePaperAfterSuccess(float intelligence, int focus, float risk);
    void GenerateTitle();
    int getCitations();
    
private:
    int citations;

};

class Personality{
public:
    Personality();
    ~Personality();
    void generatePersonality(float knowledge, float prestige, float mentoring);
    float getIntelligence();
    float getOptimism();
    float getStamina();
    void setIntelligence(float i);
    void setOptimism(float o);
    void setStamina(float s);
    
private:
    float intelligence;
    float optimism;
    float stamina;
};


#endif