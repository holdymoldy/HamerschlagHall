#ifndef graduateStudent_h
#define graduateStudent_h

#include "Paper_and_personality.h"

class Counter {
public:
    Counter();
    Counter copy();
    float value,currdt, basedt;
    void turn();
};



class GradStudent {
protected:

    int year;
    int *color;
    Counter *happiness,*out;
    int focus;
    
public:
    GradStudent();
    GradStudent* copy();
    // GradStudent(const GradStudent &from);
    // GradStudent &operator=(const GradStudent &from);
    void CleanUp();
    ~GradStudent();
    
    char *name;
    int namelength;
    Personality *personality;
    Paper *currpaper;

    void AssignPersonality(float knowledge, float prestige, float mentoring);     //Initialize personality object AND initialize 2 counters with values
    void PrintPersonality();
    void SetResearchFocus(int focus);    //Set focus int to one of x research focuses, buff/neg relevant counters
    void CheckIn();     //Get student vitals + imp. att. on interaction
    void IncYear();     //Increment year of student after 3 semesters
    void ModifyHappinessValue(float amount);
    void ModifyHappinessdT(float amount);
    void ModifyHappinessBasedT(float amount);
    void ModifyResearchValue(float amount);
    void ModifyResearchdT(float amount);
    void ModifyResearchBasedT(float amount);
    void CreatePaper();
    int SubmitPaper(float risk); //1 if successful, paper returned, out returned to zero, then currpaper is null. 0 if not successful.
    void GeneratePaperAfterSuccess(float risk); //after success
};


#endif

