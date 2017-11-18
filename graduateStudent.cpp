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
    Counter(const Counter &from);
    float value,currdt, basedt;
    void turn();
};

Counter::Counter(){
    value=0;
    currdt=0;
    basedt=0;
}

Counter::Counter(const Counter &from){
    //value = from.value;
    value = 0 //Value never copied!
    currdt = from.currdt;
    basedt = from.basedt;
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
    Counter *happiness,*out;
    int focus;
    
public:
    GradStudent();
    GradStudent(const GradStudent &from);
    GradStudent &operator=(const GradStudent &from);
    void CleanUp();
    ~GradStudent();
    
    char *name;
    int namelength;
    Personality *personality;
    Paper *currpaper;

    void AssignPersonality(float knowledge, float prestige, float mentoring);     //Initialize personality object AND initialize 2 counters with values
    void PrintPersonality();
    void SetResearchFocus();    //Set focus int to one of x research focuses, buff/neg relevant counters
    void CheckIn();     //Get student vitals + imp. att. on interaction
    void IncYear();     //Increment year of student after 3 semesters
    void ModifyHappinessValue(float amount);
    void ModifyHappinessdT(float amount);
    void ModifyResearchValue(float amount);
    void ModifyResearchdT(float amount);
    void ModifyHappinessBasedT(float amount);
    void ModifyResearchBasedT(float amount);


    void CreatePaper();
    int SubmitPaper(float risk); //1 if successful, paper returned, out returned to zero, then currpaper is null. 0 if not successful.
    void GeneratePaperAfterSuccess(float risk); //after success
};



void GradStudent::CleanUp(){
    if (nullptr != name){
        delete [] name;
        name = nullptr;
    }
    
    if(nullptr!=color){
        delete [] color;
        color = nullptr;
    }
    if(nullptr!=personality){
        delete [] personality;
        personality = nullptr;
    }
    if(nullptr!=currpaper){
        delete [] currpaper;
        currpaper = nullptr;
    }
    if(nullptr!=happiness){
        delete [] happiness;
        happiness = nullptr;
    }
    if(nullptr!=out){
        delete [] out;
        out = nullptr;
    }
    year = 0;
    focus = 0;
}

GradStudent::GradStudent(){
    //Initialize all with null/zero values
    name = nullptr;
    namelength = 0;
    year = 0;
    focus = 0;
    color = new int[3];
    for(int i=0; i<3; i+=1){
        color[i] = 0;
    }
    personality = nullptr;
    currpaper = nullptr;
    happiness = nullptr;
    out = nullptr;
}

GradStudent::GradStudent(const GradStudent &from){
    if(from.name != this->name){
        name = new char [from.namelength];
        for(int i=0; i<from.namelength;i++){
            name[i]=from.name[i];
        }
        namelength = from.namelength;
    }
    if(from.personality != this->personality){
        Personality *personality = new Personality;
        //personality = Personality(&from.personality); //use Personality setters instead
        personality.setIntelligence(from.personality.getIntelligence());
        personality.setOptimism(from.personality.getOptimism());
        personality.setStamina(from.personality.getStamina());
    }
    /*
    if(from.currpaper != this->currpaper){
        Paper *currpaper = new Paper;
        currpaper = Paper(&from.currpaper); //use Paper class copy constructor
    }*/ //no copying of papers ever - always null until instantiated by Paper methods.
    if(from.happiness != this->happiness){
        Counter *happiness = new Counter;
        happiness = Counter(&from.happiness); //use Counter class copy constructor
    }
    if(from.out != this->out){
        Counter *out = new Counter;
        out = Counter(&from.out); //use Counter class copy constructor
    }
    if(from.color != this->color){
        color = new int [3];
        for(int i=0; i<3; i+=1){
            color[i] = from.color[i];
        }
    }
    year = from.year;
    focus = from.focus;
}

GradStudent &GradStudent::operator=(const GradStudent &from){
    if(from.name !=this->name){
        CleanUp();
        for(int i=0; i<from.namelength;i++){
            name[i]=from.name[i];
        }
        namelength = from.namelength;
        Personality *personality = new Personality;
        //personality = Personality(&from.personality); //use Personality class copy constructor
        personality.setIntelligence(from.personality.getIntelligence());
        personality.setOptimism(from.personality.getOptimism());
        personality.setStamina(from.personality.getStamina());
        
        //Paper *currpaper = new Paper; // PAPERS ARE NEVER COPIED
        //currpaper = Paper(&from.currpaper); //use Paper class copy constructor
        
        Counter *happiness = new Counter;
        happiness = Counter(&from.happiness); //use Counter class copy constructor
        
        Counter *out = new Counter;
        out = Counter(&from.out); //use Counter class copy constructor
        
        color = new int [3];
        for(int i=0; i<3; i+=1){
            color[i] = from.color[i];
        }
        year = from.year;
        focus = from.focus;
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
void GradStudent::PrintPersonality(){
    cout<<"Personality: intelligence="<<personality.getIntelligence()<<" | optimism="<<personality.getOptimism()<<" | stamina="<<personality.getStamina()<<endl;
}

void GradStudent::CreatePaper(){
    Paper pape = Paper();
    currpaper = pape;
}

int GradStudent::SubmitPaper(float risk){
    return currpaper.SubmitPaper(personality.getIntelligence(),focus,risk);
}

void GeneratePaperAfterSuccess(float risk){
    currpaper.GeneratePaperAfterSuccess(personality.getIntelligence(),focus,risk);
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
    cout<<"Research focus is";
    if(focus==1){
        cout<<" Theory."<<endl;
    }
    else{
        cout<<" Experiment."<<endl;
    }
    cout<<"Personality: intelligence="<<personality.getIntelligence()<<" | optimism="<<personality.getOptimism()<<" | stamina="<<personality.getStamina()<<endl;
}

void GradStudent::IncYear(){
    //Increment year of student after 3 semesters
    year += 1;
}

void GradStudent::ModifyHappinessValue(float amount){
    happiness.value += amount;
}
void GradStudent::ModifyHappinessdT(float amount){
    happiness.currdt += amount;
}
void GradStudent::ModifyResearchValue(float amount){
    out.value += amount;
}
void ModifyResearchdT(float amount){
    out.currdt += amount;
}

void GradStudent::ModifyHappinessBasedT(float amount){
    happiness.basedt += amount;
}

void GradStudent::ModifyResearchBasedT(float amount){
    out.basedt += amount;
}


