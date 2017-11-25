#include<iostream>
#include <random>
#include<string.h>
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


void Advisor:: Conference()
{
	double PresThresh = 100;//Define a prestige threshold to determine what kind of conferences can one attend.
	int MoneyLevel[6];
	int StuTakenToConference[6];
	int LevelState[6];//To determine if a user can choose this conference
	for (int i = 0; i < 6; i++) { MoneyLevel[i] = 5000 * (i+1); LevelState[i] = 0; }
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
	if (Prestige > 1 * PresThresh) {
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
	for (int i = 0; i < 6; i++) {
		if (people[i].state== 1) {
			//Print personality so that the user knows who to choose from
			people[i].PrintPersonality();
			//numAvailable++;
		}
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
		printf("%d,\t",i);
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
			double ResearchChangevalue = 0.5*base*(k + 4)+10;
			double HappinessChangevalue = 0.3*base*(k + 4) + 20;
			people[i].ModifyHappinessValue(ResearchChangevalue);
			people[i].ModifyResearchValue(HappinessChangevalue);

			printf("Your student[%d] has gained %f points happiness and %f pointes research!\n",i, HappinessChangevalue, ResearchChangevalue);
		
			//!!!Balance issue: do I change the happiness and research level or happiness and research dT
		}
	}
	//Make Students that are taken to conference happier and research-good--End
}
