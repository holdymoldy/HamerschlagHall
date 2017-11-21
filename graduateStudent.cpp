//
//  graduateStudent.cpp
//  Hamerschlag Hall
//
//  Created by Adarsh Dave on 11/4/17.
//  Copyright © 2017 Adarsh Dave. All rights reserved.
//

#include "Paper_and_personality.h"
#include "graduateStudent.h"
#include <iostream>
using namespace std;


Counter::Counter(){
    value=0;
    currdt=0;
    basedt=0;
}
void Counter::SetValue(float i){
    value = i;
}
void Counter::SetCurrdT(float i){
    currdt = i;
}
void Counter::SetBasedT(float i){
    basedt = i;
}

//Counter Counter::copy(){
//    Counter toReturn;
//    toReturn.value = 0;
//    toReturn.currdt = currdt;
//    toReturn.basedt = basedt;
//
//    return toReturn;
//}

//Counter::Counter(const Counter &from){
//    value = 0;
//    currdt = from.currdt;
//    basedt = from.basedt;
//}



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
        delete personality;
        personality = nullptr;
    }
    if(nullptr!=currpaper){
        delete currpaper;
        currpaper = nullptr;
    }
    if(nullptr!=happiness){
        delete happiness;
        happiness = nullptr;
    }
    if(nullptr!=out){
        delete out;
        out = nullptr;
    }
    year = 0;
    focus = 0;
}

GradStudent::GradStudent(){
    //Initialize all with null/zero values
	
	name = nullptr;       //!!!! for TRIAL
    namelength = 1;
    year = 300;
    focus = 100;
    color = nullptr;     //// !!!! for TRIAL
    personality = nullptr;
    currpaper = nullptr;
    happiness = nullptr;
    out = nullptr;
}

 GradStudent::GradStudent(const GradStudent &from){
    
     if(from.name != this->name){
         if(from.name!=nullptr){
             name = new char [from.namelength];
             for(int i=0; i<from.namelength;i++){
                 name[i]=from.name[i];
             }
             namelength = from.namelength;
         }
         else{
             name = nullptr;
         }
     }
     if(from.personality != this->personality){
         if(from.personality!=nullptr){
             personality = new Personality;
             personality->setIntelligence(from.personality->getIntelligence());
             personality->setOptimism(from.personality->getOptimism());
             personality->setStamina(from.personality->getStamina());
         }
         else{
             personality = nullptr;
         }
     }
     if(from.happiness!=nullptr){
         happiness = new Counter;
         happiness->SetValue(from.happiness->value);
         happiness->SetCurrdT(from.happiness->currdt);
         happiness->SetBasedT(from.happiness->basedt);
     }
     else{
         happiness = new Counter();
     }
     if(from.out!=nullptr){
         out = new Counter;
         out->SetValue(from.out->value);
         out->SetCurrdT(from.out->currdt);
         out->SetBasedT(from.out->basedt);

     }
     else{
         out = new Counter();
     }
     if(from.color!=nullptr){
         color = new int[3];
         for(int i=0;i<3;i++){
             color[i]=from.color[i];
         }
     }
     else{
         color = nullptr;
     }
     currpaper = nullptr;
     year = 0;
     focus = 0;
 }

 GradStudent &GradStudent::operator=(const GradStudent &from){
     //cout<<"copy operator called"<<endl;
     CleanUp();
     if(from.name != this->name){
         if(from.name!=nullptr){
             name = new char [from.namelength];
             for(int i=0; i<from.namelength;i++){
                 name[i]=from.name[i];
             }
             namelength = from.namelength;
         }
         else{
             name = nullptr;
         }
     }
     if(from.personality != this->personality){
         if(from.personality!=nullptr){
             personality = new Personality;
             personality->setIntelligence(from.personality->getIntelligence());
             personality->setOptimism(from.personality->getOptimism());
             personality->setStamina(from.personality->getStamina());
         }
         else{
             personality = nullptr;
         }
     }
     if(from.happiness!=nullptr){
         happiness = new Counter;
         happiness->SetValue(from.happiness->value);
         happiness->SetCurrdT(from.happiness->currdt);
         happiness->SetBasedT(from.happiness->basedt);
     }
     else{
         happiness = new Counter();
     }
     if(from.out!=nullptr){
         out = new Counter;
         out->SetValue(from.out->value);
         out->SetCurrdT(from.out->currdt);
         out->SetBasedT(from.out->basedt);
         
     }
     else{
         out = new Counter();
     }
     if(from.color!=nullptr){
         color = new int[3];
         for(int i=0;i<3;i++){
             color[i]=from.color[i];
         }
     }
     else{
         color = nullptr;
     }
     currpaper = nullptr;
     year = 0;
     focus = 0;
     return *this;
 }

GradStudent::~GradStudent(){
    CleanUp();
}

void GradStudent::AssignPersonality(float knowledge, float prestige, float mentoring){
    //Initialize personality object AND initialize 2 counters with values
    Personality *newpersonality = new Personality;
    newpersonality->generatePersonality(knowledge,prestige,mentoring);
    this->personality = newpersonality;
    out = new Counter;
    out->basedt = this->personality->getIntelligence();
    out->currdt = out->basedt;
    happiness = new Counter;
    happiness->basedt = this->personality->getOptimism();
    happiness->currdt = happiness->basedt;
}
void GradStudent::PrintPersonality(){
    cout<<"Personality: intelligence="<<personality->getIntelligence()<<" | optimism="<<personality->getOptimism()<<" | stamina="<<personality->getStamina()<<endl;
}

void GradStudent::CreatePaper(){
    Paper *pape = new Paper;
    currpaper = pape;
}

int GradStudent::SubmitPaper(float risk){
    return currpaper->SubmitPaper(personality->getIntelligence(),focus,risk);
}

void GradStudent::GeneratePaperAfterSuccess(float risk){
    currpaper->GeneratePaperAfterSuccess(personality->getIntelligence(),focus,risk);
}

void GradStudent::SetResearchFocus(int focustoset){
    //Set focus int to one of x research focuses, buff/neg relevant counters
    if(focustoset != focus){ //only do something if desired focus if different from current focus
        focus = focustoset;
        if(focus==0){
            out->basedt *= 2;
        }
        if(focus==1){
            out->basedt *= 1/2;
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
    cout<<"Vitals: year="<<year<<" | happiness="<<happiness->value<<" | research="<<out->value<<endl;
    cout<<"Research focus is";
    if(focus==1){
        cout<<" Theory."<<endl;
    }
    else{
        cout<<" Experiment."<<endl;
    }
    cout<<"Personality: intelligence="<<personality->getIntelligence()<<" | optimism="<<personality->getOptimism()<<" | stamina="<<personality->getStamina()<<endl;
}

void GradStudent::IncYear(){
    //Increment year of student after 3 semesters
    year += 1;
}

void GradStudent::ModifyHappinessValue(float amount){
    happiness->value += amount;
}
void GradStudent::ModifyHappinessdT(float amount){
    happiness->currdt += amount;
}
void GradStudent::ModifyResearchValue(float amount){
    out->value += amount;
}
void GradStudent::ModifyResearchdT(float amount){
    out->currdt += amount;
}

void GradStudent::ModifyHappinessBasedT(float amount){
    happiness->basedt += amount;
}

void GradStudent::ModifyResearchBasedT(float amount){
    out->basedt += amount;
}

void GradStudent::PrintHappiness(){
    cout<<happiness->value<<','<<happiness->currdt<<','<<happiness->basedt<<endl;
}

void GradStudent::NameStudent(char *desired, int desiredlength){
    if(name==nullptr){
        name = new char[desiredlength];
        for(int i=0; i<desiredlength;i++){
            name[i]=desired[i];
        }
        namelength = desiredlength;
    }
    else{
        cout<<"ERROR NameStudent(): Student already named!"<<endl;
    }
}

void GradStudent::PrintName(){
    cout<<"\n";
    for(int i=0;i<namelength;i++){
        cout<<name[i];
    }
    cout<<endl;
}
void GradStudent::SetColor(int arr[]){
    color = new int[3];
    for(int i=0;i<3;i++){
        color[i] = arr[i];
    }
}

void GradStudent::GetColor(int result[]){
    for(int i=0;i<3;i++){
        result[i]=color[i];
    }
}

int GradStudent::GetYear(){
    return year;
}

int GradStudent::GetFocus(){
    return focus;
}

