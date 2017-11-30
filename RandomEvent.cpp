void Advisor::RandomEvents(GradStudent student[]) {
	int randEvent;
	randEvent = rand() % 8;
	switch (randEvent) {
	case 0:
		printf("It looks that you are really woring hard as a start up professor,\n");
		printf("so the department decided to give you a small bonus to start, with 10000 USD!\n");
		Money += 10000;
	case 1:
		printf("Wow, Thanks Giving is approaching! It looks that everyone is happy!\n");
		printf("Happiness of every student you have has increased 5%.\n");
		for (int i = 0; i < StudentCounter; i++) {
			people[i].ModifyHappinessValue(5);
		}
	case 2:
		printf("An Earthquake took place! One of your machines broke.\n");
		printf("You have to spend extra money to repair it.Lose 10000 USD.\n");
		Money -= 10000;
	case 3:
		printf("Your student's dog just bit you, but you are kind enough not to bite your student back.\n")
			printf("Your student is very grateful for this,their happiness increase by 5%, and your prestige also increases by 10.\n");
		Prestige += 10;
		for (int i = 0; i < StudentCounter; i++) {
			people[i].ModifyHappinessValue(5);
		}
	case 4:
		printf("Someone from another research group just published your work!!\n");
		printf("This is really bad news and your students' research points just fall back 50%.\n");
		for (int i = 0; i < StudentCounter; i++) {
			people[i].ModifyResearchValue(-50);
		}
	case 5:
		printf("Suddenly you don't wanna work and sat down and chat with your student.\n");
		printf("Studnets think you are a nice advisor! Congrats! Prestige + 20 \n");
		Prestige += 100;
	}
	case 6:
		printf("Your first student just had an epiphany!\n");
		printf("Congrats, this student's research point increases 20 points!\n");
		people[0].ModifyResearchValue(-50);
	case 7:
		printf("Shoo, an uneventful semester! Finally\n");
		printf("Gonna go home and rest!\n");
}