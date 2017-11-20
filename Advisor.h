#ifndef Advisor_h
#define Advisor_h
#include "graduateStudent.h"
#include "Drawing.h"

class Advisor {
public:
	Advisor();
	~Advisor();
	int LabState[6]; // utilities in the lab
	int Semester;
	float Money = 10000;
	void WriteGrant();//double &Money, double &Prestige, double Knowledge, double Experience
	void Recruit(GradStudent student[], int StudentCounter);//GradStudent student[], will be added after copy const.
	void UpgradeLab(GradStudent student[], Upgrade upgrade[], Person people[], int StudentCounter); //Drawing class get the lab state information from advisor class//
	void Party(GradStudent student[], int StudentCounter);
	void Conference(GradStudent student[], int StudentCounter);
	void SendtoCompany(GradStudent student[]);
	void Push(double &Prestige, GradStudent &student, double mentoring);
	void SetResearchFocus(GradStudent student[], int StudentCounter);
	//void RandomEvent(double Money, GradStudent &student, Paper &paper, Drawing &draw);
	void Time(); //if advisor-door is True, next semester.
				 //void GetFunding();
	float GetExperience();
	float GetPrestige();
	float GetKnowledge();
	float GetMentoring();
	
private:
	float Knowledge;
	float Experience;
	float Prestige;
	float Mentoring;
};
#endif