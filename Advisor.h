#ifndef Advisor_h
#define Advisor_h
#include "graduateStudent.h"
#include "Drawing.h"

class Advisor {
public:
	Advisor();
	~Advisor();
	int LabState[6]; // utilities in the lab
	float Money = 800000;
	void WriteGrant();//double &Money, double &Prestige, double Knowledge, double Experience
	void Recruit(GradStudent student[], int &StudentCounter, int &flag);//GradStudent student[], will be added after copy const.
	void UpgradeLab(GradStudent student[], Upgrade upgrade[], Person people[], int StudentCounter); //Drawing class get the lab state information from advisor class//
	void Party(GradStudent student[], int StudentCounter);
	void Conference(GradStudent student[], int StudentCounter);
	void SendtoCompany(GradStudent student[], int inter);
	void RandomEvents(GradStudent student[], int StudentCounter);
	void Push(GradStudent student[],int inter);
	void SetResearchFocus(GradStudent student[], int StudentCounter);
	//void RandomEvent(double Money, GradStudent &student, Paper &paper, Drawing &draw);
	float GetExperience();
	float GetPrestige();
	float GetKnowledge();
	float GetMentoring();

	void AddPrestige(float p);

	void AddExperience(float p);

	void AddKnowledge(float p);

private:
	float Knowledge;
	float Experience;
	float Prestige;
	float Mentoring;
};
#endif
