#include<iostream>
#include <random>
#include "Advisor-Action.hpp"

void Advisor::WriteGrant() {
    if (Semester % 3 == 1) {  //Draw.CheckMouseWriteGrand() is in the drawing function and checks if the user is clicking WriteGrand button.
        double inherent_probability = Prestige * (Knowledge + Experience);// This math needs tuning to fall in (1,2)
        double accept_probability = (double)rand() / (double)RAND_MAX;         //We will add the weight of the level of the grand to it so that this also falls to 1 to 2, and the higher the level, the harder it is to get
        
        char LevelInput[3];
        int levelmoneyA = 10000, levelmoneyB = 50000, levelmoneyC = 100000, levelmoneyD = 500000;
        printf("What grant do you want to apply for this year?\n Level A: Neighborhood Support Foundation\t Grant Amount: %d\nLevel B: Small Company Research Foundation\t Grant Amount: %d\nLevel C:  the United States Department of Energy\t Grant Amount: %d\nLevel D: National Science Foudation\t Grant Amount: %d\n", levelmoneyA, levelmoneyB, levelmoneyC, levelmoneyD);
        fgets(LevelInput, 2, stdin);
        while (LevelInput[0] != 'A' && LevelInput[0] != 'a' && LevelInput[0] != 'B'&&LevelInput[0] != 'b' && LevelInput[0] != 'C' && LevelInput[0] != 'c' && LevelInput[0] != 'D' && LevelInput[0] != 'd') {
            printf("Hey yo man, what are you thinking. That is not a founding in the pool. Go choose another one!>");
            fgets(LevelInput, 2, stdin);
        }
        if (LevelInput[0] == 'A' || LevelInput[0] == 'a') {
            accept_probability += 0.2;
            if (inherent_probability> accept_probability) {
                Money += levelmoneyA;
				printf("Congrats! The proposal you just wrote has gotten approved by the authorities!\n");
            }
			else printf("Ooops, it got denied... Thank you for trying though");
        }
        if (LevelInput[0] == 'B' || LevelInput[0] == 'b') {
            accept_probability += 0.4;
            if (inherent_probability> accept_probability) {
                Money += levelmoneyB;
				printf("Congrats! The proposal you just wrote has gotten approved by the authorities!\n");
			}
			else printf("Ooops, it got denied... Thank you for trying though");
        }
        
        if (LevelInput[0] == 'C' || LevelInput[0] == 'c') {
            accept_probability += 0.6;
            if (inherent_probability> accept_probability) {
                Money += levelmoneyC;
				printf("Congrats! The proposal you just wrote has gotten approved by the authorities!\n");
			}
			else printf("Ooops, it got denied... Thank you for trying though");
        }
        
        if (LevelInput[0] == 'D' || LevelInput[0] == 'd') {
            accept_probability += 0.8;
            if (inherent_probability> accept_probability) {
                Money += levelmoneyD;
				printf("Congrats! The proposal you just wrote has gotten approved by the authorities!\n");
			}
			else printf("Ooops, it got denied... Thank you for trying though");
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
void Advisor::UpgradeLab(GradStudent &student[], Drawing &draw) {
    char LevelInput[2];
    int levelmoneyA = 10000, levelmoneyB = 20000, levelmoneyC = 50000, levelmoneyD = 100000, levelmoneyE = 200000, levelmoneyF = 500000;
    printf("How do you like to upgrade your lab?\n Level A: Just buy a staper\t Investment Amount: %d\nLevel B: A coffee machine\t Investment Amount: %d\nLevel C: A 3D printer\t Investment Amount: %d\nLevel D: !!!NAME FORGOTTEN\t Investment Amount: %d\nLevel E: !!! Name Forgotten again-A time machine\t Investment Amount: %d\n\nLevel F: A clone machine\t Investment Amount: %d\n", levelmoneyA, levelmoneyB, levelmoneyC, levelmoneyD, levelmoneyE, levelmoneyF);
    fgets(LevelInput, 1, stdin);
    while (LevelInput[0] != 'A' && LevelInput[0] != 'a' && LevelInput[0] != 'B'&&LevelInput[0] != 'b' && LevelInput[0] != 'C' && LevelInput[0] != 'c' && LevelInput[0] != 'D' && LevelInput[0] != 'd' && LevelInput[0] != 'E' && LevelInput[0] != 'e'&&LevelInput[0] != 'F' && LevelInput[0] != 'f') {
        printf("!!!Uhuh, bro, That I cannot help you. Go choose another one!>");
        fgets(LevelInput, 1, stdin);
    }
    if (LevelInput[0] == 'A' || LevelInput[0] == 'a') {
        draw.upgrade[0].state = 1;//This is for Drawing Class!
        //Increase GradStudent happiness and research a little. From A to F, the increment increase.
        Money -= levelmoneyA;
		for (int i = 1; i < 7; i++){		//Because people[0] is advisor
			if (draw.people[i].state_person==1)	{
				student.ChangeHappinessLevel(10);
				student.ChangeResearchdT(1.0);
			}		
		}
    }
    if (LevelInput[0] == 'B' || LevelInput[0] == 'b') {
        draw.upgrade[1].state = 1;//This is for Drawing Class!
        Money -= levelmoneyB;
		for (int i = 1; i < 7; i++){		//Because people[0] is advisor
			if (draw.people[i].state_person==1)	{
				student.ChangeHappinessLevel(20);
				student.ChangeResearchdT(2.0);
			}		
		}
    }
    if (LevelInput[0] == 'C' || LevelInput[0] == 'c') {
        draw.upgrade[2].state = 1;//This is for Drawing Class!
        Money -= levelmoneyC;
		for (int i = 1; i < 7; i++){		//Because people[0] is advisor
			if (draw.people[i].state_person==1)	{
				student.ChangeHappinessLevel(30);
				student.ChangeResearchdT(3.0);
			}		
		}
    }
    if (LevelInput[0] == 'D' || LevelInput[0] == 'd') {
        draw.upgrade[3].state = 1;//This is for Drawing Class!
        Money -= levelmoneyD;
		for (int i = 1; i < 7; i++){		//Because people[0] is advisor
			if (draw.people[i].state_person==1)	{
				student.ChangeHappinessLevel(40);
				student.ChangeResearchdT(4.0);
			}		
		}
    }
    if (LevelInput[0] == 'E' || LevelInput[0] == 'e') {
        draw.upgrade[4].state = 1;//This is for Drawing Class!
        Money -= levelmoneyE;
		for (int i = 1; i < 7; i++){		//Because people[0] is advisor
			if (draw.people[i].state_person==1)	{
				student.ChangeHappinessLevel(50);
				student.ChangeResearchdT(5.0);
			}		
		}
    }
    if (LevelInput[0] == 'F' || LevelInput[0] == 'f') {
        draw.upgrade[5].state = 1;//This is for Drawing Class!
        Money -= levelmoneyF;
		for (int i = 1; i < 7; i++){		//Because people[0] is advisor
			if (draw.people[i].state_person==1)	{
				student.ChangeHappinessLevel(6.0);
				student.ChangeResearchdT(6.0);
			}		
		}
    }
}
void Advisor::Party(GradStudent &student[],Drawing &draw) {
    //Increase GradStudent happiness for some amount.
	for (int i = 1; i < 7; i++) {		//Because people[0] is advisor
		if (draw.people[i].state_person == 1) {
			student.ChangeHappinessLevel(10);
			student.ChangeResearchdT(1.0);
		}
	}
    Money -= 50000;
}
void Advisor::Conference(GradStudent &student[],Drawing &draw) {
    double PresThresh=100;//Define a prestige threshold to determine what kind of conferences can one attend.
    int MoneyLevel[6];
	int StuTakenToConference[6];
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
    if (Prestige > 1.3 * PresThresh) {
        LevelState[0] = 1;
        LevelState[1] = 1;
        LevelState[2] = 1;
        LevelState[3] = 1;
    }
    if (Prestige > 1.6 * PresThresh) {
        LevelState[0] = 1;
        LevelState[1] = 1;
        LevelState[2] = 1;
		LevelState[3] = 1;
		LevelState[4] = 1;
    }
	if (Prestige > 1.9 * PresThresh) {
		LevelState[0] = 1;
		LevelState[1] = 1;
		LevelState[2] = 1;
		LevelState[3] = 1;
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

	//From here on, I am checking the user input
	//!!!Causion: would this check work if the user can only choose from A to C but chooses D?
    char CheckInput[12] = { 'A','a','B','b','C','c','D','d','E','e','F','f' };
	int checkwrong, available = 0;
	for (int i = 0; i < 6; i++) {
		if (LevelState[i] == 1)available++;
	}
	checkwrong = available;
	while (checkwrong == available) {
		checkwrong = 0;
		for (int j = 0; j < 2 * available; j++) {
			if (CheckInput[j] != LevelInput[0]) {
				checkwrong++;
			}
		}
		if (checkwrong < 2 * available) break;
		printf("Come on, bro! Do you know how hard it is to put this game together? Don't fool me and type only within the range shown!\n");
		fgets(LevelInput, 1, stdin);
	}
	//Check input End

	//--Mark User Choice Begins
	for (int i = 0; i < 12; i++) {
		if (CheckInput[i] == LevelInput[0])k = i;//This is to mark the user's choice.
	}
	k = (k-(k%2)) / 2;//This is the index of the user's choice.
	//--Mark User Choice End

	//--Take NumofStu to conference
	NumofStu = 0;
	int numAvailable = 0;	//Records the number of students that are already there (recruited)
	for (int i = 0; i < 6; i++) {
		if (draw.people[i].state_person == 1) {
			printf("Stu. Num. %d: ", i);
			student.PrintPersonality();
			numAvailable++;
		}
	}
	while(NumofStu<1||NumofStu>numAvailable){
		scanf("How many students do you want to take with you?%d\n", &NumofStu);
	}
	Money -= NumofStu*MoneyLevel[k];
	//---From here we are taking selected students to conference
	for (int i = 0; i < 6; i++) {
		StuTakenToConference[i]=0;
	}
	int ithTaken;
	for (int i = 0; i < NumofStu; i++) {
		scanf("Who do you want to take with?%d\n", &ithTaken);
		while (0 > ithTaken || ithTaken > numAvailable|| StuTakenToConference[ithTaken] == 1) {
			// This is to check in case the user wants to take a student out of range 
			// or wants to take someone that is already taken.
			scanf("Who do you want to take with? %d\n", &ithTaken);
		}
		StuTakenToConference[ithTaken] = 1;
	}
	//--Take NumofStu to conference End

	//Make Students that are taken to conference happier and more research-good--Begin
	int base = 10;// this is for balancing, 
	//the minimum happiness and research change in accordance with the conference level
	for (int i = 0; i < 6; i++) {
		if (StuTakenToConference[i] == 1) {
			student[i].ChangeHappinessLevel(0.5*base*k);
			student[i].ChangeResearchLevel(base*k);
			//!!!Balance issue: do I change the happiness and research level or happiness and research dT
		}
	}
	//Make Students that are taken to conference happier and research-good--End
}
void Advisor::SetResearchFocus(GradStudent &student[],Drawing &draw) {
	int focus;
	int ChosenStu;
	int numAvailable = 0;
	for (int i = 0; i < 6;i++ ) {
		if (draw.people[i].state_person == 1) {
			student[i].CheckIn(); 
			numAvailable++;
		}
	}
	scanf("Whose focus do you want to set? %d\n", &ChosenStu);
	while (ChosenStu<0 || ChosenStu > numAvailable) {
		scanf("No, please choose a real student in your group! %d\n", &ChosenStu);
	}
	printf("Which focuse do you want to set this student's focus on?\n");
	printf("0: Experiment\n");
	printf("1: Theory\n");
	scanf("> %d\n", &focus);
	student[ChosenStu].SetResearchFocus(focus);
}
void Advisor::RandomEvents(GradStudent student[]) {
}


