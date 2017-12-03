#ifndef graduateStudent_h
#define graduateStudent_h

#include "Paper_and_personality.h"

class Counter {
public:
    Counter();
    //Counter copy();
    Counter(const Counter &from);
    float value,currdt, basedt;
    void turn();
    void SetValue(float i);
    void SetCurrdT(float i);
    void SetBasedT(float i);
};



class GradStudent {
protected:
    
    int year;
    Counter *happiness,*rout;
    int focus;
    
public:
    GradStudent(float knowledge, float prestige, float mentoring);
	GradStudent();
    //    GradStudent* copy();
    GradStudent(const GradStudent &from);
    GradStudent &operator=(const GradStudent &from);
    void CleanUp();
    ~GradStudent();
    
    char *name;
    int namelength;
    int *haircolor,*eyecolor,*skincolor;
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
	float GetResearchVal();
	float GetHappinessVal();
	void GenerateName();
    void CreatePaper();
    void GeneratePaperAfterSuccess(); //after success
    void NameStudent(char *desired, int desiredlength);
    void PrintName();
    void PrintHappiness();
    void SetHairColor(int arr[]);
    void GetHairColor(int result[]);
    void SetEyeColor(int arr[]);
    void GetEyeColor(int result[]);
    void SetSkinColor(int arr[]);
    void GetSkinColor(int result[]);
    int GetYear();
    int GetFocus();
    void turn();
    void GenerateHairColor();
    void GenerateEyeColor();
    void GenerateSkinColor();
};


#endif

