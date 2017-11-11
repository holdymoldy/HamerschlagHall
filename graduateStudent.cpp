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
    char name[32];
    int year;
    int color[3];
    Personality personality;
    Counter happiness,GPA,out;
    int focus;

public:
    GradStudent();
    void AssignPersonality;
    void SetResearchFocus();
    void CheckIn();
    void IncYear();
};

GradStudent::GradStudent(){
    //Initialize all with null values
    /*
     Name = NULL char array of length 32
     Year = 0
     Color = 0,0,0
     Focus = 0
     */
}

GradStudent::AssignPersonality(){
    //Initialize personality object AND initialize 3 counters with values
}

GradStudent::SetResearchFocus(){
    //Set focus int to one of x research focuses, buff/neg relevant counters
}

GradStudent::CheckIn(){
    //Get student vitals + imp. att. on interaction
}

GradStudent::IncYear(){
    //Increment year of student after 3 semesters
}

class Counter {
private:
    float currval,baseval,dt;

public:
    Counter();
    void decay();
}

Counter::Counter(){
    //Initialize each counter attribute to null
}

Counter::decay(){
    //Decays currval of counter closer to baseval (in either direction)
}

