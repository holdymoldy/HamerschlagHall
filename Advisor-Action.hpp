#ifndef Advisor_Action_hpp
#define Advisor_Action_hpp

#include <stdio.h>
#include "graduateStudent.hpp"

class Drawing{
    //filler class
};

class Advisor {
public:
    Advisor();
    ~Advisor();
    int LabState[6]; // utilities in the lab
    int Semester = 1;
    double Money;
    void Assign_peculiarities();
    void WriteGrant(Drawing &draw);//double &Money, double &Prestige, double Knowledge, double Experience
    void Recruit(GradStudent &student, Drawing &draw);
    void UpgradeLab(GradStudent &student, int LabState[6]); //Drawing class get the lab state information from advisor class//
    void Party(GradStudent &student);
    void Conference(GradStudent &student);
    void SendtoCompany(double Money, double Prestige, GradStudent &student);
    void Push(double &Prestige, GradStudent &student, double mentoring);
    void SetResearchFocus(GradStudent &student);
    void RandomEvent(double Money, GradStudent &student, Paper &paper, Drawing &draw);
    void Time(Drawing Draw); //if advisor-door is True, next semester.
    //void GetFunding();
    void GetExperience();
    void GetPrestige();
    void GetKnowledge();
    void GetMentoring();
    
private:
    double Knowledge;
    double Experience;
    double Prestige;
    double Mentoring;
};


#endif /* Advisor_Action_hpp */

