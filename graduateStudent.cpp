//
//  graduateStudent.cpp
//  Hamerschlag Hall
//
//  Created by Adarsh Dave on 11/4/17.
//  Copyright © 2017 Adarsh Dave. All rights reserved.
//

#include <stdio.h>
#include <math.h>

class GradStudent {
protected:

    int year;
    int color[3];
    Personality personality;
    Counter happiness,out;
    Paper currpaper;
    int focus;

public:
    GradStudent();
    GradStudent(const GradStudent &from);
    GradStudent &operator=(const GradStudent &from);
    void CleanUp();
    ~GradStudent();
    
    void AssignPersonality();     //Initialize personality object AND initialize 2 counters with values
    void PrintPersonality(); 
    void SetResearchFocus();    //Set focus int to one of x research focuses, buff/neg relevant counters
    void CheckIn();     //Get student vitals + imp. att. on interaction
    void IncYear();     //Increment year of student after 3 semesters
    void ChangeHappinessLevel(float amount);
    void ChangeHappinessdT(float amount);
    void ChangeResearchLevel(float amount);
    void ChangeResearchdT(float amount);
    void CreatePaper();
    int SubmitPaper(float risk); //1 if successful, paper returned, out returned to zero, then currpaper is null. 0 if not successful.
    void GeneratePaperAfterSuccess(float risk); //aftersuccess
    char GetName();
};

char GradStudent::GetName(){
    return name;
}

int GradStudent::GetNameLength(){
    return namelength;
}

void GradStudent::CleanUp(){
    if (nullptr != name){
        delete [] name;
        name = nullptr;
        year = 0;
        color = {0,0,0};
        focus = 0;
    }
}

GradStudent::GradStudent(){
    //Initialize all with null/zero values
    name = nullptr;
    namelength = 0;
    year = 0;
    color = {0,0,0}
    focus = 0;
}

GradStudent::GradStudent(const GradStudent &from){
    if(from.GetName() != this->name){
        name = new char [from.GetNameLength()];
        for(int i=0; i<from.GetNameLength();i++){
            name[i]=from.GetName()[i];
        }
        namelength = from.GetNameLength();
    }
}

GradStudent &GradStudent::operator=(const GradStudent &from){
    if(from.GetName() !=this->name){
        CleanUp();
        for(int i=0; i<from.GetNameLength();i++){
            name[i]=from.GetName()[i];
        }
        namelength = from.GetNameLength();
    }
    return *this;
}

GradStudent::~GradStudent(){
    CleanUp();
}

void GradStudent::AssignPersonality(float knowledge, float prestige, float mentoring){
    //Initialize personality object AND initialize 2 counters with values
    Personality newpersonality = Personality();
    newpersonality.generatePersonality(knowledge,prestige,mentoring);
    this->personality = newpersonality;
    out = Counter();
    out.basedt = this->personality.getIntelligence();
    out.currdt = out.basedt;
    happiness = Counter();
    happiness.basedt = this->personality.getOptimism();
    happiness.currdt = happiness.basedt;
}

void GradStudent::CreatePaper(){
    Paper pape = Paper();
    currpaper = pape;
}

int GradStudent::SubmitPaper(float risk){
    return currpaper(Personality.getIntelligence(),focus,risk);
}

void GradStudent::SetResearchFocus(){
    //Set focus int to one of x research focuses, buff/neg relevant counters
}

void GradStudent::CheckIn(){
    //Get student vitals + imp. att. on interaction
}

void GradStudent::IncYear(){
    //Increment year of student after 3 semesters
}

void GradStudent::ChangeHappinessLevel(float amount){
    
}

class Counter {
public:
    Counter();
    float value,currdt, basedt;
    void turn();
};

Counter::Counter(){
    value=0;
    currdt=0;
    basedt=0;
}

void Counter::turn(){
    value += currdt;
    if(currdt>basedt){
        currdt -= 5;
        if((currdt-basedt)<5){
            currdt = basedt;
        }
    }
    if(currdt<basedt){
        currdt += 5;
        if((currdt-basedt)<5){
            currdt=basedt;
        }
    }
    
}

