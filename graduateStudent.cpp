//
//  graduateStudent.cpp
//  Hamerschlag Hall
//
//  Created by Adarsh Dave on 11/4/17.
//  Copyright © 2017 Adarsh Dave. All rights reserved.
//

#include "Paper_and_personality.h"
#include "graduateStudent.h"
#include <random>
#include <iostream>
using namespace std;

int generateRand1(void){
    return rand();
}

int generateRand1(int val){
    return rand()%val;
}

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
    if(nullptr!=haircolor){
        delete [] haircolor;
        haircolor = nullptr;
        }
    if(nullptr!=eyecolor){
        delete [] eyecolor;
        eyecolor = nullptr;
        }
    if(nullptr!=skincolor){
        delete [] skincolor;
        skincolor = nullptr;
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
    if(nullptr!=rout){
        delete rout;
        rout = nullptr;
    }
    year = 0;
    focus = 0;
}

GradStudent::GradStudent(float knowledge, float prestige, float mentoring){
   
    name = nullptr;
    namelength = 0;
    year = 0;
    focus = 0;
    personality = nullptr;
    currpaper = nullptr;
    happiness = nullptr;
    rout = nullptr;
    
    
    this->AssignPersonality(knowledge,prestige,mentoring);
	this->GenerateName();
    this->GenerateSkinColor();
    this->GenerateHairColor();
    this->GenerateEyeColor();
}

GradStudent::GradStudent(void) {
	name = nullptr;
	namelength = 0;
	year = 0;
	focus = 0;
	color = nullptr;
	personality = nullptr;
	currpaper = nullptr;
	happiness = nullptr;
	rout = nullptr;
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
    if(from.rout!=nullptr){
        rout = new Counter;
        rout->SetValue(from.rout->value);
        rout->SetCurrdT(from.rout->currdt);
        rout->SetBasedT(from.rout->basedt);
        
    }
    else{
        rout = new Counter();
    }
    if(from.haircolor!=nullptr){
        haircolor = new int[3];
        for(int i=0;i<3;i++){
            haircolor[i]=from.haircolor[i];
        }
    }
    else{
        haircolor = nullptr;
    }
    if(from.skincolor!=nullptr){
        skincolor = new int[3];
        for(int i=0;i<3;i++){
            skincolor[i]=from.skincolor[i];
        }
    }
    else{
        skincolor = nullptr;
    }
    if(from.eyecolor!=nullptr){
        eyecolor = new int[3];
        for(int i=0;i<3;i++){
            eyecolor[i]=from.eyecolor[i];
        }
    }
    else{
        eyecolor = nullptr;
    }
    currpaper = nullptr;
    year = 0;
    focus = 0;
}

GradStudent &GradStudent::operator=(const GradStudent &from){
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
    if(from.rout!=nullptr){
        rout = new Counter;
        rout->SetValue(from.rout->value);
        rout->SetCurrdT(from.rout->currdt);
        rout->SetBasedT(from.rout->basedt);
        
    }
    else{
        rout = new Counter();
    }
    if(from.haircolor!=nullptr){
        haircolor = new int[3];
        for(int i=0;i<3;i++){
            haircolor[i]=from.haircolor[i];
        }
    }
    else{
        haircolor = nullptr;
    }
    if(from.eyecolor!=nullptr){
        eyecolor = new int[3];
        for(int i=0;i<3;i++){
            eyecolor[i]=from.eyecolor[i];
        }
    }
    else{
        eyecolor = nullptr;
    }
    if(from.skincolor!=nullptr){
        skincolor = new int[3];
        for(int i=0;i<3;i++){
            skincolor[i]=from.skincolor[i];
        }
    }
    else{
        skincolor = nullptr;
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
    rout = new Counter;
    rout->basedt = this->personality->getIntelligence()/2;
    rout->currdt = rout->basedt;
    happiness = new Counter;
    float dt = this->personality->getOptimism();
    happiness->basedt = -1*(100-dt)/3;
    happiness->currdt = happiness->basedt;
    happiness->value = 100;
    rout-> value = 0;
}
void GradStudent::PrintPersonality(){
    cout<<"Personality: intelligence="<<personality->getIntelligence()<<" | optimism="<<personality->getOptimism()<<" | stamina="<<personality->getStamina()<<endl;
}

void GradStudent::CreatePaper(){
    Paper *pape = new Paper;
    currpaper = pape;
}


void GradStudent::GeneratePaperAfterSuccess(){
    currpaper->GeneratePaperAfterSuccess(personality->getIntelligence(),focus);
}

void GradStudent::SetResearchFocus(int focustoset){
    //Set focus int to one of x research focuses, buff/neg relevant counters
    if(focustoset != focus){ //only do something if desired focus if different from current focus
        focus = focustoset;
        if(focus==0){
            rout->basedt *= 2;
        }
        if(focus==1){
            rout->basedt *= 1/2;
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
    cout<<"Vitals: year="<<year<<" | happiness="<<happiness->value<<" | research="<<rout->value<<endl;
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
    rout->value += amount;
}
void GradStudent::ModifyResearchdT(float amount){
    rout->currdt += amount;
}

void GradStudent::ModifyHappinessBasedT(float amount){
    happiness->basedt += amount;
}

void GradStudent::ModifyResearchBasedT(float amount){
    rout->basedt += amount;
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
    for(int i=0;i<namelength;i++){
        cout<<name[i];
    }
}


int GradStudent::GetYear(){
    return year;
}

int GradStudent::GetFocus(){
    return focus;
}

void GradStudent::turn(){
    happiness->turn();
    rout->turn();
}

float GradStudent::GetResearchVal() {
	return rout->value;
}

float GradStudent::GetHappinessVal() {
	return happiness->value;
}

void GradStudent::GenerateName(){
    char *tobenamed = new char[256];
    int first_len = 17;
    char first[][30] = {"Ali","Addie","Benyamin", "Bey","Carla","Carlo","Denver", "Darlene", "Frankie", "Felicia","Yian", "Maurice", "Mohammed","Misty", "Jie",
        "Hochen", "Zulu"};
    int last_len = 17;
    char last[][30] = {"Gurer","Malone","Spilsbury", "Johnson", "Peroni", "Wang", "Ray", "Harris", "Parks","Xi","Zhang","Kotha","Viswanathan","Gates","Wean","Cohen","Hamerschlag"};
    
    // test structure
    strcpy(tobenamed, first[generateRand1(first_len)]);
    strcat(tobenamed, " ");
    strcat(tobenamed, last[generateRand1(last_len)]);
    
    if(this->name!=NULL){
        delete [] name;
        name = NULL;
        namelength = 0;
    }
    
    this->name = tobenamed;
    namelength = strlen(tobenamed);
    //cout<<'\n'<<strlen(tobenamed)<<'\n';
    //cout<<name;
}

void GradStudent::SetHairColor(int arr[]){
    haircolor = new int[3];
    for(int i=0;i<3;i++){
        haircolor[i] = arr[i];
    }
}
void GradStudent::SetEyeColor(int arr[]){
    eyecolor = new int[3];
    for(int i=0;i<3;i++){
        eyecolor[i] = arr[i];
    }
}
void GradStudent::SetSkinColor(int arr[]){
    skincolor = new int[3];
    for(int i=0;i<3;i++){
        skincolor[i] = arr[i];
    }
}
void GradStudent::GetHairColor(int result[]){
    for(int i=0;i<3;i++){
        result[i]=haircolor[i];
    }
}
void GradStudent::GetEyeColor(int result[]){
    for(int i=0;i<3;i++){
        result[i]=eyecolor[i];
    }
}
void GradStudent::GetSkinColor(int result[]){
    for(int i=0;i<3;i++){
        result[i]=skincolor[i];
    }
}


void GradStudent::GenerateHairColor(){
    int i = generateRand(255);
    int j = generateRand(255);
    int k = generateRand(255);
    int colorarr[3]={i,j,k};
    this->SetHairColor(colorarr);
}
void GradStudent::GenerateEyeColor(){
    int i = generateRand(255);
    int j = generateRand(255);
    int k = generateRand(255);
    int colorarr[3]={i,j,k};
    this->SetEyeColor(colorarr);
}
void GradStudent::GenerateSkinColor(){
    int s = generateRand(6);
    int colorarr[3]={0,0,0};
    switch (s) {
        case 0: {
            colorarr[0]=141;
            colorarr[1]=85;
            colorarr[2]=36;
            break;
        }
        case 1:{
            colorarr[0]=198;
            colorarr[1]=134;
            colorarr[2]=66;
            break;
        }
        case 2:{
            colorarr[0]=224;
            colorarr[1]=172;
            colorarr[2]=105;
            break;
        }
        case 3:{
            colorarr[0]=241;
            colorarr[1]=194;
            colorarr[2]=125;
            break;
        }
        case 4:{
            colorarr[0]=255;
            colorarr[1]=219;
            colorarr[2]=172;
            break;
        }
        case 5:{
            colorarr[0]=255;
            colorarr[1]=205;
            colorarr[2]=148;
            break;
        }
    }
    this->SetSkinColor(colorarr);
}

