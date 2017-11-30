#include "graduateStudent.h"
#include "Advisor.h"
#include <random>
#include <string>
#include <time.h>
#include "Drawing.h"

char *MyFgets(char str[], int limit, FILE *fp)
{
	if (nullptr != fgets(str, 255, fp))
	{
		int l = 0;
		for (l = 0; 0 != str[l]; ++l)
		{
		}
		for (l = l - 1; 0 <= l; --l)
		{
			if ('\n' == str[l] || '\r' == str[l])
			{
				str[l] = 0;
			}
			else
			{
				break;
			}
		}
		return str;
	}
	else
	{
		return nullptr;
	}
}

Advisor::Advisor()
{
	//Experience = 70;
	//Prestige = 90;
	//Knowledge = 80;
	//Mentoring = 90;
	//Semester = 0;
	printf("You have 300 points to distribute to advisor`s personalities, write down the distribution in a range of 0-100\n  Experience\n  Prestige\n  Knowledge\n  Mentoring\n");
	printf("If you try to exceed 300, the rest will be assigned as 0\n");
	printf("After Entering number, Press ENTER\n");
	char Exp[5];
	MyFgets(Exp, 4, stdin);
	Experience = atof(Exp);
	printf("%f LEFT to Distribute\n", 300 - Experience);
	char Pres[5];
	MyFgets(Pres, 4, stdin);
	Prestige = atof(Pres);
	printf("%f LEFT to Distribute\n", 300 - (Prestige+Experience));
	char Know[5];
	MyFgets(Know, 4, stdin);
	Knowledge = atof(Know);
	printf("%f LEFT to Distribute\n",300-(Knowledge+Prestige+Experience));
	char Ment[5];
	MyFgets(Ment, 4, stdin);
	Mentoring = 300 - (Knowledge + Prestige + Experience);
	printf("Experience:%f\n", Experience);
	printf("Prestige:%f\n", Prestige);
	printf("Knowledge:%f\n", Knowledge);
	printf("Mentoring:%f\n", Mentoring);

}
Advisor::~Advisor()
{

}
float Advisor::GetExperience() {
	return Experience;
}
float Advisor::GetPrestige() {
	return Prestige;
}

float Advisor::GetKnowledge() {
	return Knowledge;
}
float Advisor::GetMentoring() {
	return Mentoring;
}

void Advisor::AddPrestige(float p){
	Prestige += p;
}

void Advisor::WriteGrant() {
	
	
		//Draw.CheckMouseWriteGrand() is in the drawing function and checks if the user is clicking WriteGrand button.
		double inherent_probability = Prestige * (Knowledge + Experience);// This math needs tuning to fall in (1,2)
		double accept_probability = (double)rand() / (double)RAND_MAX;         //We will add the weight of the level of the grand to it so that this also falls to 1 to 2, and the higher the level, the harder it is to get
		printf("Initial_Money:%f\n", Money);
		char LevelInput[10];
		int levelmoneyA = 10000, levelmoneyB = 50000, levelmoneyC = 100000, levelmoneyD = 500000;
		printf("What grant do you want to apply for this year?\n Level A: Neighborhood Support Foundation\t Grant Amount: %d\nLevel B: Small Company Research Foundation\t Grant Amount: %d\nLevel C:  the United States Department of Energy\t Grant Amount: %d\nLevel D: National Science Foudation\t Grant Amount: %d\n", levelmoneyA, levelmoneyB, levelmoneyC, levelmoneyD);
		MyFgets(LevelInput, 9, stdin);
		while (LevelInput[0] != 'A' && LevelInput[0] != 'a' && LevelInput[0] != 'B' && LevelInput[0] != 'b' && LevelInput[0] != 'C' && LevelInput[0] != 'c' && LevelInput[0] != 'D' && LevelInput[0] != 'd') {
			printf("Hey yo man, what are you thinking. That is not a founding in the pool. Go choose another one!>");
			MyFgets(LevelInput, 9, stdin);
		}
		if (LevelInput[0] == 'A' || LevelInput[0] == 'a') {
			accept_probability += 0.2;
			if (inherent_probability > accept_probability) {
				Money += levelmoneyA;
				printf("Congrates! The proposal isaccepted!\n");
			}
			else printf("Ooops! Empty shot.  :(");

		}
		if (LevelInput[0] == 'B' || LevelInput[0] == 'b') {
			accept_probability += 0.4;
			if (inherent_probability > accept_probability) {
				Money += levelmoneyB;
				printf("Congrates! The proposal isaccepted!\n");
			}
			else printf("Ooops! Empty shot.  :(");
		}

		if (LevelInput[0] == 'C' || LevelInput[0] == 'c') {
			accept_probability += 0.6;
			if (inherent_probability > accept_probability) {
				Money += levelmoneyC;
				printf("Congrates! The proposal isaccepted!\n");
			}
			else printf("Ooops! Empty shot.  :(");
		}

		if (LevelInput[0] == 'D' || LevelInput[0] == 'd') {
			accept_probability += 0.8;
			if (inherent_probability > accept_probability) {
				Money += levelmoneyD;
				printf("Congrates! The proposal isaccepted!\n");
			}
			else printf("Ooops! Empty shot.  :(");
		}
		printf("Updated_Money:%f\n", Money);
	
	
}
void Advisor::Recruit(GradStudent student[], int StudentCounter) { 
	char Selection[3];
	char A = 'A';

		int j = 3;     //Prestige / 25 + rand() % 2;  //If Prestige is out of 100;   
		GradStudent Hire[3];
		for (int i = 0; i < j; i++) {
			Hire[i] = GradStudent(Knowledge, Prestige, Mentoring);
			printf("%c:", A);
			Hire[i].PrintPersonality(); //Graduate Student class is responsible for printing attributes. //ask ady when he is done, so we can implement that class!!
			A++;
		}
		MyFgets(Selection, 2, stdin);
            if (Selection[0] == 'A' || Selection[0] == 'B' || Selection[0] == 'C' || Selection[0] == 'D' || Selection[0] == 'E' || Selection[0] == 'F' || Selection[0] == 'G') {
                student[StudentCounter] = Hire[Selection[0] - 65];
				printf("Congrats, you selected: Student %c \n", Selection[0]);
        }
}

void Advisor::UpgradeLab(GradStudent student[], Upgrade upgrade[], Person people[], int StudentCounter) {
	char LevelInput[100];
	int levelmoney[6] = { 10000,20000,50000,100000,200000,500000};
	printf("How do you like to upgrade your lab?\n Level A: Just buy a coffee machine\t Investment Amount: %d\nLevel B: A Printer\t Investment Amount: %d\nLevel C: Chemicals\t Investment Amount: %d\nLevel D: CNC machine\t Investment Amount: %d\nLevel E: Computer Servers\t Investment Amount: %d\nLevel F: A clone machine\t Investment Amount: %d\n", levelmoney[0], levelmoney[1], levelmoney[2], levelmoney[3], levelmoney[4], levelmoney[5]);
	MyFgets(LevelInput, 99, stdin);
	while (LevelInput[0] != 'A' && LevelInput[0] != 'a' && LevelInput[0] != 'B'&&LevelInput[0] != 'b' && LevelInput[0] != 'C' && LevelInput[0] != 'c' && LevelInput[0] != 'D' && LevelInput[0] != 'd' && LevelInput[0] != 'E' && LevelInput[0] != 'e'&&LevelInput[0] != 'F' && LevelInput[0] != 'f') {
		printf("!!!Uhuh, bro, That I cannot help you. Go choose another one!>");
		MyFgets(LevelInput, 99, stdin);
	}
	if (Money > levelmoney[65 - LevelInput[0]]) {
		if (LevelInput[0] == 'F' || LevelInput[0] == 'f') {
			upgrade[0].state = 1;//This is for Drawing Class!
								 //Increase GradStudent happiness and research a little. From A to F, the increment increase.
			Money -= levelmoney[5];
			for (int i = 0; i < StudentCounter; i++) {		//Because people[0] is advisor
				if (people[i + 1].state_person == 1) {
					student[i].ModifyHappinessValue(100.0);
					student[i].ModifyResearchdT(12.0);
				}
			}
		}
		if (LevelInput[0] == 'E' || LevelInput[0] == 'e') {
			upgrade[5].state = 1;//This is for Drawing Class!
			Money -= levelmoney[4];
			for (int i = 0; i < StudentCounter; i++) {		//Because people[0] is advisor
				if (people[i + 1].state_person == 1) {
					student[i].ModifyHappinessValue(80.0);
					student[i].ModifyResearchdT(10.0);
				}
			}
		}
		if (LevelInput[0] == 'D' || LevelInput[0] == 'd') {
			upgrade[2].state = 1;//This is for Drawing Class!
			Money -= levelmoney[3];
			for (int i = 0; i < StudentCounter; i++) {		//Because people[0] is advisor
				if (people[i + 1].state_person == 1) {
					student[i].ModifyHappinessValue(40.0);
					student[i].ModifyResearchdT(7.0);
				}
			}
		}
		if (LevelInput[0] == 'C' || LevelInput[0] == 'c') {
			upgrade[4].state = 1;//This is for Drawing Class!
			Money -= levelmoney[2];
			for (int i = 0; i < StudentCounter; i++) {		//Because people[0] is advisor
				if (people[i + 1].state_person == 1) {
					student[i].ModifyHappinessValue(30.0);
					student[i].ModifyResearchdT(4.0);
				}
			}
		}
		if (LevelInput[0] == 'B' || LevelInput[0] == 'b') {
			upgrade[1].state = 1;//This is for Drawing Class!
			Money -= levelmoney[1];
			for (int i = 0; i < StudentCounter; i++) {		//Because people[0] is advisor
				if (people[i + 1].state_person == 1) {
					student[i].ModifyHappinessValue(10.0);
					student[i].ModifyResearchdT(5.0);
				}
			}
		}
		if (LevelInput[0] == 'A' || LevelInput[0] == 'a') {
			upgrade[3].state = 1;//This is for Drawing Class!
			Money -= levelmoney[0];
			for (int i = 0; i < StudentCounter; i++) {		//Because people[0] is advisor
				if (people[i + 1].state_person == 1) {
					student[i].ModifyHappinessValue(6.0);
					student[i].ModifyResearchdT(6.0);
				}
			}
		}
	}
	else {
		printf("Sorry!! You and your students need to work harder to buy it\n");
	}
}
void Advisor::Party(GradStudent student[], int StudentCounter) {
	//Increase GradStudent happiness for some amount.
	for (int i = 0; i <StudentCounter; i++) {		//Because people[0] is advisor
		student[i].ModifyHappinessValue(20);
		student[i].ModifyResearchdT(2.0);
	}
	Money -= 5000;
}
void Advisor::Conference(GradStudent people[],int StudentCounter)
{
	double PresThresh = 100;//Define a prestige threshold to determine what kind of conferences can one attend.
	int MoneyLevel[6];
	int StuTakenToConference[6];
	int LevelState[6];//To determine if a user can choose this conference
	for (int i = 0; i < 6; i++) { MoneyLevel[i] = 5000 * (i + 1); LevelState[i] = 0; }
	char LevelInput[3];
	int k = 0;//This is to record the conference level
	int NumofStu = 0;//Number of students to be taken to conference
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
		LevelState[1] = 1;
	}
	if (Prestige > 0.98 * PresThresh) {
		LevelState[2] = 1;
	}
	if (Prestige > 1.3 * PresThresh) {
		LevelState[3] = 1;
	}
	if (Prestige > 1.6 * PresThresh) {
		LevelState[4] = 1;
	}
	if (Prestige > 1.9 * PresThresh) {
		LevelState[5] = 1;
	}
	for (int i = 0; i < 6; i++) {
		if (LevelState[i] == 1) {
			printf("%s\t \t\t\t \t\t which will cost you %d.\n", ConferenceLevel[i], MoneyLevel[i]);
		}
	}
	printf("What kind of conference do you want to go to?\n");
	MyFgets(LevelInput, 2, stdin);

	//From here on, I am checking the user input
	//!!!Causion: would this check work if the user can only choose from A to C but chooses D?
	char CheckInput[12] = { 'A','a','B','b','C','c','D','d','E','e','F','f' };
	int checkwrong, available = 0;
	for (int i = 0; i < 6; i++) {
		if (LevelState[i] == 1)available++;
	}
	available = available * 2;
	checkwrong = 0;
	for (int j = 0; j < available; j++) {
		if (CheckInput[j] != LevelInput[0]) {
			checkwrong++;
		}
	}
	while (checkwrong == available) {
		printf("Come on, bro! Do you know how hard it is to put this game together? Don't fool me and type only within the range shown!\n");
		MyFgets(LevelInput, 2, stdin);

		checkwrong = 0;
		for (int j = 0; j < available; j++) {
			if (CheckInput[j] != LevelInput[0]) {
				checkwrong++;
			}
		}
		if (checkwrong < available) break;
	}
	//Check input End

	//--Mark User Choice Begins
	for (int i = 0; i < 12; i++) {
		if (CheckInput[i] == LevelInput[0])k = i;//This is to mark the user's choice.
	}
	k = (k - (k % 2)) / 2;//This is the index of the user's choice.
						  //--Mark User Choice End
	printf("You chose the NO.%d\n Conference", k);

	//--Take NumofStu to conference
	NumofStu = 0;
	//We alreay have StudentCounter for this int numAvailable = 0;	//Records the number of students that are already there (recruited)
	for (int i = 0; i < StudentCounter; i++) {
		
			//Print personality so that the user knows who to choose from
			people[i].PrintPersonality();
			//numAvailable++;
		
	}
	printf("How many students do you want to take with you?\n");
	scanf("%d", &NumofStu);
	while (NumofStu<1 || NumofStu>StudentCounter) {
		printf("Requirement denied. Sorry sir, but I cannot take someone that is not there to conference.\n");
		printf("So, how many students do you want to take with you?\n");
		scanf("%d", &NumofStu);
	}
	Money -= NumofStu*MoneyLevel[k];
	//---From here we are taking selected students to conference
	printf("Money, %d", Money);
	for (int i = 0; i < 6; i++) {
		StuTakenToConference[i] = 0;
		printf("%d,\t", i);
	}

	int ithTaken;
	for (int i = 0; i < NumofStu; i++) {
		printf("Who do you want to take with? >");
		scanf("%d", &ithTaken);

		while (0 > ithTaken || ithTaken >= StudentCounter || StuTakenToConference[ithTaken] == 1) {
			// This is to check in case the user wants to take a student out of range 
			// or wants to take someone that is already taken.
			if (ithTaken >= StudentCounter) {
				printf("Uh,I don't think he is there. Who do you want to take with? >");
				scanf("%d", &ithTaken);
			}
			if (StuTakenToConference[ithTaken] == 1) {
				printf("Uh,You have taken him already. Who do you want to take with? >");
				scanf("%d", &ithTaken);
			}

		}
		StuTakenToConference[ithTaken] = 1;
	}
	//--Take NumofStu to conference End

	//Make Students that are taken to conference happier and more research-good--Begin
	int base = 10;// this is for balancing, 
				  //the minimum happiness and research change in accordance with the conference level
	printf("This is a successful conference!\n");

	for (int i = 0; i < 6; i++) {
		if (StuTakenToConference[i] == 1) {
			double ResearchChangevalue = 0.5*base*(k + 4) + 10;
			double HappinessChangevalue = 0.3*base*(k + 4) + 20;
			people[i].ModifyHappinessValue(ResearchChangevalue);
			people[i].ModifyResearchValue(HappinessChangevalue);

			printf("Your student[%d] has gained %f points happiness and %f pointes research!\n", i, HappinessChangevalue, ResearchChangevalue);

			//!!!Balance issue: do I change the happiness and research level or happiness and research dT
		}
	}
	//Make Students that are taken to conference happier and research-good--End
}

void Advisor::SetResearchFocus(GradStudent student[], int inter) {
	int focus;
	int ChosenStu;

	

		//  !!! student[inter].CheckIn();   !!!  INCLUDE
	
	/*scanf("Whose focus do you want to set? %d\n", &ChosenStu);*/
	/*while (ChosenStu<0 || ChosenStu > StudentCounter) {
		scanf("No, please choose a real student in your group! %d\n", &ChosenStu);
	}*/
	printf("Which focuse do you want to set this student's focus on?\n");
	printf("0: Experiment\n");
	printf("1: Theory\n");
	scanf("> %d\n", &focus);
	student[inter].SetResearchFocus(focus);
}

void Advisor::SendtoCompany(GradStudent student[],int inter) {
	// we should decide on Students Gains.
	printf("Which company would you like your student to be working in during summer term\n");
	printf("A: Your student works in GOOGLE to create AI that might destroy the humanity.\nB: Your student works in UBER for Self-driving cars in Pittsburgh.\nHe can also be an UBER driver for some extra bucks.\nC: Your Student will takea part in a super secret CIA project even you don't know.\n");
	printf("D: TESLA needs some fast-charging, lightweight batteries for the cars.\nE: SPACEX is looking for Rocket drivers.\nF: Your student seems to need a vacation. Give him a Mars trip with NASA.\n");
	printf("G: FACEBOOK needs more advertisement and news-feed algorithms to alienate people.\nH: Let's save the planet with Wind and Solar Power.\nI: Wants to be a librarian in AMAZON.\n");
	printf("J: You are just sick of student's question and want not to see him at least a semester, so anywhere is ok.\nK: Let's do some Fusion Energy.\nL: CERN is looking for geniuses.\n");
		char decision[10];
		MyFgets(decision, 9, stdin);
		char CheckInput[24] = { 'A','a','B','b','C','c','D','d','E','e','F','f','G','g','H','h','I','i','J','j','K','k','L','l' };
		student[inter].ModifyHappinessValue(80.0);
		}
	