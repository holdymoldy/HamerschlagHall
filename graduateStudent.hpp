#ifndef graduateStudent_hpp
#define graduateStudent_hpp

#include <stdio.h>
#include "Paper_and_personality.hpp"


class Counter {
private:
    float currval,baseval,currdt, basedt;
public:
    Counter();
    void decay();
};


class GradStudent {
protected:
    char name[32];
    int year;
    int color[3];
    Personality personality;
    Counter happiness, GPA, out;
    int focus;
    
public:
    GradStudent();
    GradStudent(GradStudent &from);
    void AssignPersonality();
    void PrintPersonality();
    void SetResearchFocus();
    void CheckIn();
    void IncYear();
    void ChangeHappinessLevel(float amount);
    void ChangeHappinessdT(float amount);
};



#endif /* graduateStudent_hpp */
