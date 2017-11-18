//
//  graduateStudent.cpp
//  Hamerschlag Hall
//
//  Created by Adarsh Dave on 11/4/17.
//  Copyright © 2017 Adarsh Dave. All rights reserved.
//

#include "Paper_and_personality.cpp"
#include <iostream>
using namespace std;

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


class GradStudent {
protected:

    int year;
    int *color;
    Counter happiness,out;
    int focus;
    
public:
    GradStudent();
    GradStudent(const GradStudent &from);
    GradStudent &operator=(const GradStudent &from);
    void CleanUp();
    ~GradStudent();
    
    char *name;
    int namelength;
    Personality personality;
    Paper currpaper;

    void AssignPersonality(float knowledge, float prestige, float mentoring);     //Initialize personality object AND initialize 2 counters with values
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
    void GeneratePaperAfterSuccess(float risk); //after success
};



void GradStudent::CleanUp(){
    if (nullptr != name){
        delete [] name;
        name = nullptr;
        year = 0;
        delete [] color;
        color = nullptr;
        focus = 0;
    }
}

GradStudent::GradStudent(){
    //Initialize all with null/zero values
    name = nullptr;
    namelength = 0;
    year = 0;
    color = new int[3];
    for(int i=0; i<3; i+=1){
        color[i] = 0;
    }
    focus = 0;
}

GradStudent::GradStudent(const GradStudent &from){
    if(from.name != this->name){
        name = new char [from.namelength];
        for(int i=0; i<from.namelength;i++){
            name[i]=from.name[i];
        }
        namelength = from.namelength;
    }
}

GradStudent &GradStudent::operator=(const GradStudent &from){
    if(from.name !=this->name){
        CleanUp();
        for(int i=0; i<from.namelength;i++){
            name[i]=from.name[i];
        }
        namelength = from.namelength;
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
    return currpaper.SubmitPaper(personality.getIntelligence(),focus,risk);
}

void GradStudent::SetResearchFocus(int focustoset){
    //Set focus int to one of x research focuses, buff/neg relevant counters
    if(focustoset != focus){ //only do something if desired focus if different from current focus
        focus = focustoset;
        if(focus==0){
            out.basedt *= 2;
        }
        if(focus==1){
            out.basedt *= 1/2;
        }
    }
}

void GradStudent::CheckIn(){
    //Get student vitals + imp. att. on interaction
    cout << "Checking in with ";
    for(int i=0;i<namelength;i++){
        cout<<name[i];
    }
    cout<<"..."<<endl;
    cout<<"Vitals: year="<<year<<" | happiness="<<happiness.value<<" | research="<<out.value<<endl;
    cout<<"Personality: intelligence="<<personality.getIntelligence()<<" | optimism="<<personality.getOptimism()<<" | stamina="<<personality.getStamina()<<endl;

    
}

void GradStudent::IncYear(){
    //Increment year of student after 3 semesters
    year += 1;
}

void GradStudent::ChangeHappinessLevel(float amount){
    
}


