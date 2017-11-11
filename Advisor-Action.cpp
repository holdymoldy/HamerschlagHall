#include<iostream>
#include <random>

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
	void RandomEvent(Money, GradStudent &student, Paper &paper, Drawing &draw);
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

void Advisor::WriteGrant(Drawing & draw) {
	if (Semester % 3 == 1 && Draw.CheckMouseWriteGrand() == 1) {  //Draw.CheckMouseWriteGrand() is in the drawing function and checks if the user is clicking WriteGrand button. 
		double inherent_probability = Prestige * (Knowledge + Experience);// This math needs tuning to fall in (1,2)
		double accept_probability = (double)rand() / (double)RAND_MAX;         //We will add the weight of the level of the grand to it so that this also falls to 1 to 2, and the higher the level, the harder it is to get 

		char LevelInput[2];
		int levelmoneyA = 10000, levelmoneyB = 50000, levelmoneyC = 100000, levelmoneyD = 500000;
		printf("What grant do you want to apply for this year?\n Level A: Neighborhood Support Foundation\t Grant Amount: %d\nLevel B: Small Company Research Foundation\t Grant Amount: %d\nLevel C:  the United States Department of Energy\t Grant Amount: %d\nLevel D: National Science Foudation\t Grant Amount: %d", levelmoneyA, levelmoneyB, levelmoneyC, levelmoneyD);
		fgets(LevelInput, 1, stdin);
		while (LevelInput[0] != 'A' && LevelInput[0] != 'a' && LevelInput[0] != 'B'&&LevelInput[0] != 'b' && LevelInput[0] != 'C' && LevelInput[0] != 'c' && LevelInput[0] != 'D' && LevelInput[0] != 'd') {
			printf("Hey yo man, what are you thinking. That is not a founding in the pool. Go choose another one!>");
			fgets(LevelInput, 1, stdin);
		}
		if (LevelInput[0] == 'A' || LevelInput[0] == 'a') {
			accept_probability += 0.2;
			if (inherent_probability> accept_probability) {
				Money += levelmoneyA;
			}
		}
		if (LevelInput[0] == 'B' || LevelInput[0] == 'b') {
			accept_probability += 0.4;
			if (inherent_probability> accept_probability) {
				Money += levelmoneyB;
			}
		}

		if (LevelInput[0] == 'C' || LevelInput[0] == 'c') {
			accept_probability += 0.6;
			if (inherent_probability> accept_probability) {
				Money += levelmoneyC;
			}
		}

		if (LevelInput[0] == 'D' || LevelInput[0] == 'd') {
			accept_probability += 0.8;
			if (inherent_probability> accept_probability) {
				Money += levelmoneyD;
			}
		}
	}
}
void Advisor::Recruit(GradStudent &student, Drawing &draw) {
	char Selection[255];
	if (Semester % 3 == 0 && Draw.CheckMouseRecruit == 1) {
		int j = Prestige / 20 + rand() % 2;  //If Prestige is out of 100;
		GradStudent Hire[j];
		for (int i = 0; i < j; i++) {
			Hire[i].AssignPersonality;
			Hire.PrintAttributes(); //Graduate Student class is responsible for printing attributes.
		}
		fgets(Selection, 255, stdin);
		for (int i = 0; i < 255; i++) {}
		if (Selection == 0) {
			break;
		}
		if (Selection >= 97 && Selection <= 103) {
			Hire[Selection - 97]
		}
	}
}
void Advisor::UpgradeLab(GradStudent &student, int LabState[6]) {
	char LevelInput[2];
	int levelmoneyA = 10000, levelmoneyB = 20000, levelmoneyC = 50000, levelmoneyD = 100000, levelmoneyE = 200000, levelmoneyF = 500000;
	printf("How do you like to upgrade your lab?\n Level A: Just buy a staper\t Investment Amount: %d\nLevel B: A coffee machine\t Investment Amount: %d\nLevel C: A 3D printer\t Investment Amount: %d\nLevel D: !!!NAME FORGOTTEN\t Investment Amount: %d\nLevel E: !!! Name Forgotten again-A time machine\t Investment Amount: %d\n\nLevel F: A clone machine\t Investment Amount: %d\n", levelmoneyA, levelmoneyB, levelmoneyC, levelmoneyD, levelmoneyE, levelmoneyF);
	fgets(LevelInput, 1, stdin);
	while (LevelInput[0] != 'A' && LevelInput[0] != 'a' && LevelInput[0] != 'B'&&LevelInput[0] != 'b' && LevelInput[0] != 'C' && LevelInput[0] != 'c' && LevelInput[0] != 'D' && LevelInput[0] != 'd' && LevelInput[0] != 'E' && LevelInput[0] != 'e'&&LevelInput[0] != 'F' && LevelInput[0] != 'f') {
		printf("!!!Uhuh, bro, That I cannot help you. Go choose another one!>");
		fgets(LevelInput, 1, stdin);
	}
	if (LevelInput[0] == 'A' || LevelInput[0] == 'a') {
		LabState[0] = 1;//This is for Drawing Class!
		//Increase GradStudent happiness and research a little. From A to F, the increment increase.
		//!!!BUT I DON'T KNOW HOW TO CALL GRADSTUDENT HAPPINESS COUNTER! (Same for the next 5 lines.)
		Money -= levelmoneyA;
	}
	if (LevelInput[0] == 'B' || LevelInput[0] == 'b') {
		LabState[1] = 1;//This is for Drawing Class!
		Money -= levelmoneyB;
	}
	if (LevelInput[0] == 'C' || LevelInput[0] == 'c') {
		LabState[2] = 1;//This is for Drawing Class!
		Money -= levelmoneyC;
	}
	if (LevelInput[0] == 'D' || LevelInput[0] == 'd') {
		LabState[3] = 1;//This is for Drawing Class!
		Money -= levelmoneyD;
	}
	if (LevelInput[0] == 'E' || LevelInput[0] == 'e') {
		LabState[4] = 1;//This is for Drawing Class!
		Money -= levelmoneyE;
	}
	if (LevelInput[0] == 'F' || LevelInput[0] == 'f') {
		LabState[5] = 1;//This is for Drawing Class!
		Money -= levelmoneyF;
	}
}
void Advisor::Party(GradStudent &student) {
	//Increase GradStudent happiness for some amount. 
	//!!!Not sure how to call GradStudent counter happiness.
	Money -= 50000;
}
void Advisor::Conference(GradStudent &student) {
	double PresThresh=100;//Define a prestige threshold to determine what kind of conferences can one attend.
	int MoneyLevel[6];
	int LevelState[6];//To determine if a user can choose this conference
	for (int i = 0; i < 6; i++) { MoneyLevel[i] = 5000*i; LevelState[i] = 0; }
	char LevelInput[2];
	int k = 0;//This is to record the conference level
	int NumofStu=0;//Number of students to be taken to conference
	char ConferenceLevel[6][255];
	strcpy(ConferenceLevel[0], "A: Neighborhood conference on good-looking food delivery guy.\n");
	strcpy(ConferenceLevel[1], "B: City conference of the mayer's dog.\n");
	strcpy(ConferenceLevel[2], "C: State conference of the traffic light change.\n");
	strcpy(ConferenceLevel[3], "D: National conference of heat and mass that don't wanna move.\n");
	strcpy(ConferenceLevel[4], "E: International conference of \"Chill, man, just sit down and chat, no harm done\".\n");
	strcpy(ConferenceLevel[5], "F: Interstellar conference of where has my spaceship gone! I just parked it here.\n");
	if (Prestige > 0.5*PresThresh) {
		LevelState[0] = 1;
	}
	if (Prestige > 0.7*PresThresh) {
		LevelState[0] = 1;
		LevelState[1] = 1;
	}
	if (Prestige > 1*PresThresh) {
		LevelState[0] = 1;
		LevelState[1] = 1;
		LevelState[2] = 1;
	}
	if (Prestige > 1.4 * PresThresh) {
		LevelState[0] = 1;
		LevelState[1] = 1;
		LevelState[2] = 1;
		LevelState[4] = 1;
	}
	if (Prestige > 1.9 * PresThresh) {
		LevelState[0] = 1;
		LevelState[1] = 1;
		LevelState[2] = 1;
		LevelState[4] = 1;
		LevelState[5] = 1;
	}
	printf("What kind of conference do you want to go to?\n");
	for (int i = 0; i < 6; i++) {
		if (LevelState[i] == 1) {
			printf("%c\t, which will cost you %d.\n",ConferenceLevel[i],MoneyLevel[i]);
		}
	}
	fgets(LevelInput, 1, stdin);
	char CheckInput[12] = { 'A','a','B','b','C','c','D','d','E','e','F','f' };
	int checkwrong = 12;
	//!!!There is actually a bug: if the user can only choose from A to C but chooses D, this "checkwrong" process won't captrue it.
	//I will come back and deal with this when the whole thing is working.
	while(checkwrong==12){
		checkwrong = 0;
		for (int i = 0; i < 12; i++) {
			if (CheckInput[i] != LevelInput[0]) {
				checkwrong++;
			}
		}
		if (checkwrong < 12) break;
		printf("Come on, bro! Do you know how hard it is to put this game together? Don't fool me and type only within the range shown!\n");
		fgets(LevelInput, 1, stdin);
	}
	for (int i = 0; i < 12; i++) {
		if (CheckInput[i] == LevelInput[0])k = i;//This is to mark the user's choice.
	}
	scanf("How many students do you want to take with you?%d\n",&NumofStu);
	Money -= NumofStu*MoneyLevel[k];
	//!!!How do I call and select which student to take from the GradStudent class?
	//Make students taken a little happier and research point go up(according to the conference level).
}

