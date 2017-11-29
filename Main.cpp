
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include<iostream>
#include <random>
#include "fssimplewindow.h"
#include "Drawing.h"
#include "graduateStudent.h"
#include "Advisor.h"
char *My2Fgets(char str[], int limit, FILE *fp)
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
char actionforStudent() {
	printf("A: You want to check in on the student\nB: You want to send the student to an internship\nC: You want to set research focus for the student\n");
	char choice[3];
	My2Fgets(choice, 2, stdin);
	return choice[0];
}

void GenerateSetup(int nDesk, Desk desk[6], Computer computer[6], Person people[7], Upgrade upgrade[6], int flag)
{
    int i;
    if (flag == 0)
    {
        for (i = 0; i<nDesk / 2; i++)
        {
            desk[i].state = 0;
            computer[i].state = 0;
            people[i + 1].state_person = 0;
            upgrade[i].state = 0;
            desk[i + 3].state = 0;
            computer[i + 3].state = 0;
            people[i + 4].state_person = 0;
            upgrade[i + 3].state = 0;
        }
    }
    
    for (i = 0; i<nDesk / 2; i++)
    {
        desk[i].x = 400;
        desk[i].y = 700 - 200 * i;
        
        computer[i].x = 400;
        computer[i].y = 650 - 200 * i;
        
        people[i + 1].x = 400;
        people[i + 1].y = 620 - 200 * i;
        
        upgrade[i].x = 75;
        upgrade[i].y = 700 - 200 * i;
        
        desk[i + 3].x = 800;
        desk[i + 3].y = 700 - 200 * i;
        
        computer[i + 3].x = 800;
        computer[i + 3].y = 650 - 200 * i;
        
        people[i + 4].x = 800;
        people[i + 4].y = 620 - 200 * i;
        
        upgrade[i + 3].x = 1135;
        upgrade[i + 3].y = 700 - 200 * i;
    }
}

void DrawRoom(void)
{
    glColor3ub(255, 248, 220);
    glBegin(GL_QUADS);
    glVertex2i(0, 0);
    glVertex2i(1200, 0);
    glVertex2i(1200, 100);
    glVertex2i(0, 100);
    glEnd();
    
    glColor3ub(135, 206, 250);
    glBegin(GL_QUADS);
    glVertex2i(0, 100);
    glVertex2i(1200, 100);
    glVertex2i(1200, 1000);
    glVertex2i(0, 1000);
    glEnd();
    
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(0, 100);
    glVertex2i(1200, 100);
    glEnd();
    
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(500, 750);
    glVertex2i(700, 750);
    glVertex2i(700, 800);
    glVertex2i(500, 800);
    glEnd();
}

void DrawProfDesk(int x, int y)
{
    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2i(x - 175, y - 40);
    glVertex2i(x + 175, y - 40);
    glVertex2i(x + 180, y + 40);
    glVertex2i(x - 180, y + 40);
    glEnd();
    
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(x - 175, y - 40);
    glVertex2i(x + 175, y - 40);
    glVertex2i(x + 180, y + 40);
    glVertex2i(x - 180, y + 40);
    glEnd();
    
    glColor3ub(160, 82, 45);
    glBegin(GL_QUADS);
    glVertex2i(x - 180, y + 40);
    glVertex2i(x + 180, y + 40);
    glVertex2i(x + 180, y + 60);
    glVertex2i(x - 180, y + 60);
    glEnd();
    
    glColor3ub(160, 82, 45);
    glBegin(GL_QUADS);
    glVertex2i(x - 170, y + 60);
    glVertex2i(x - 150, y + 60);
    glVertex2i(x - 150, y + 100);
    glVertex2i(x - 170, y + 100);
    glEnd();
    
    glColor3ub(160, 82, 45);
    glBegin(GL_QUADS);
    glVertex2i(x + 170, y + 60);
    glVertex2i(x + 150, y + 60);
    glVertex2i(x + 150, y + 100);
    glVertex2i(x + 170, y + 100);
    glEnd();
    
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(x - 180, y + 60);
    glVertex2i(x + 180, y + 60);
    glEnd();
    
    // Computer
    
    glColor3ub(105, 105, 105);
    glBegin(GL_POLYGON);
    glVertex2i(x - 42, y - 85);
    glVertex2i(x + 42, y - 85);
    glVertex2i(x + 45, y - 80);
    glVertex2i(x - 45, y - 80);
    glEnd();
    
    glColor3ub(105, 105, 105);
    glBegin(GL_POLYGON);
    glVertex2d((double)x - 43.75, (double)y - 10);
    glVertex2d((double)x + 43.75, (double)y - 10);
    glVertex2i(x + 45, y + 10);
    glVertex2i(x - 45, y + 10);
    glEnd();
    
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);
    glVertex2i(x - 45, y + 10);
    glVertex2i(x + 45, y + 10);
    glVertex2i(x + 45, y + 15);
    glVertex2i(x - 45, y + 15);
    glEnd();
    
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2d((double)x - 43.75, (double)y - 10);
    glVertex2d((double)x + 43.75, (double)y - 10);
    glVertex2i(x + 45, y + 10);
    glVertex2i(x - 45, y + 10);
    glEnd();
    
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);
    glVertex2i(x - 45, y - 80);
    glVertex2i(x + 45, y - 80);
    glVertex2i(x + 45, y - 20);
    glVertex2i(x - 45, y - 20);
    glEnd();
    
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);
    glVertex2i(x - 10, y - 20);
    glVertex2i(x + 10, y - 20);
    glVertex2i(x + 10, y);
    glVertex2i(x - 10, y);
    glEnd();
    
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(x - 45, y - 20);
    glVertex2i(x + 45, y - 20);
    glEnd();
    
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(x - 42, y - 85);
    glVertex2i(x + 42, y - 85);
    glVertex2i(x + 45, y - 80);
    glVertex2i(x - 45, y - 80);
    glEnd();
    
    // Mail Box
    
    glColor3ub(70, 130, 180);
    glBegin(GL_POLYGON);
    glVertex2d((double)x + 119.25, (double)y - 35);
    glVertex2d((double)x + 160.75, (double)y - 35);
    glVertex2i(x + 162, y - 15);
    glVertex2i(x + 118, y - 15);
    glEnd();
    
    glColor3ub(255, 222, 173);
    glBegin(GL_QUADS);
    glVertex2i(x + 122, y - 39);
    glVertex2i(x + 158, y - 39);
    glVertex2i(x + 158, y - 19);
    glVertex2i(x + 122, y - 19);
    glEnd();
    
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(x + 122, y - 39);
    glVertex2i(x + 158, y - 39);
    glVertex2i(x + 158, y - 19);
    glVertex2i(x + 122, y - 19);
    glEnd();
    
    glColor3ub(255, 222, 173);
    glBegin(GL_QUADS);
    glVertex2i(x + 122, y - 36);
    glVertex2i(x + 158, y - 36);
    glVertex2i(x + 158, y - 16);
    glVertex2i(x + 122, y - 16);
    glEnd();
    
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(x + 122, y - 36);
    glVertex2i(x + 158, y - 36);
    glVertex2i(x + 158, y - 16);
    glVertex2i(x + 122, y - 16);
    glEnd();
    
    glColor3ub(255, 222, 173);
    glBegin(GL_QUADS);
    glVertex2i(x + 122, y - 33);
    glVertex2i(x + 158, y - 33);
    glVertex2i(x + 158, y - 13);
    glVertex2i(x + 122, y - 13);
    glEnd();
    
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(x + 122, y - 33);
    glVertex2i(x + 158, y - 33);
    glVertex2i(x + 158, y - 13);
    glVertex2i(x + 122, y - 13);
    glEnd();
    
    glColor3ub(255, 222, 173);
    glBegin(GL_QUADS);
    glVertex2i(x + 122, y - 30);
    glVertex2i(x + 158, y - 30);
    glVertex2i(x + 158, y - 10);
    glVertex2i(x + 122, y - 10);
    glEnd();
    
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(x + 122, y - 30);
    glVertex2i(x + 158, y - 30);
    glVertex2i(x + 158, y - 10);
    glVertex2i(x + 122, y - 10);
    glEnd();
    
    glColor3ub(255, 222, 173);
    glBegin(GL_QUADS);
    glVertex2i(x + 122, y - 27);
    glVertex2i(x + 158, y - 27);
    glVertex2i(x + 158, y - 7);
    glVertex2i(x + 122, y - 7);
    glEnd();
    
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(x + 122, y - 27);
    glVertex2i(x + 158, y - 27);
    glVertex2i(x + 158, y - 7);
    glVertex2i(x + 122, y - 7);
    glEnd();
    
    glColor3ub(255, 222, 173);
    glBegin(GL_QUADS);
    glVertex2i(x + 122, y - 24);
    glVertex2i(x + 158, y - 24);
    glVertex2i(x + 158, y - 4);
    glVertex2i(x + 122, y - 4);
    glEnd();
    
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(x + 122, y - 24);
    glVertex2i(x + 158, y - 24);
    glVertex2i(x + 158, y - 4);
    glVertex2i(x + 122, y - 4);
    glEnd();
    
    glColor3ub(255, 222, 173);
    glBegin(GL_QUADS);
    glVertex2i(x + 122, y - 21);
    glVertex2i(x + 158, y - 21);
    glVertex2i(x + 158, y - 1);
    glVertex2i(x + 122, y - 1);
    glEnd();
    
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(x + 122, y - 21);
    glVertex2i(x + 158, y - 21);
    glVertex2i(x + 158, y - 1);
    glVertex2i(x + 122, y - 1);
    glEnd();
    
    glColor3ub(30, 144, 255);
    glBegin(GL_QUADS);
    glVertex2i(x + 118, y - 15);
    glVertex2i(x + 162, y - 15);
    glVertex2i(x + 162, y + 25);
    glVertex2i(x + 118, y + 25);
    glEnd();
    
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2d((double)x + 119.25, (double)y - 35);
    glVertex2d((double)x + 160.75, (double)y - 35);
    glVertex2i(x + 162, y - 15);
    glVertex2i(x + 118, y - 15);
    glEnd();
    
    glColor3ub(255, 222, 173);
    glBegin(GL_LINES);
    glVertex2d((double)x + 123, (double)y - 35);
    glVertex2d((double)x + 157, (double)y - 35);
    glEnd();
}

void Interaction(int &inter, int &inter_state, Upgrade upgrade[], Person people[], int nPerson)
{
    double min_distance = 3000, distance;
    
    for (int i = 1; i < nPerson; i++)
    {
        if (people[i].state_person == 1)
        {
            if (fabs(people[0].x - people[i].x) < 50 && fabs(people[0].y - people[i].y) < 50 && inter_state != 1)
            {
                inter_state = 1;
                inter = i;
                min_distance = sqrt(pow((people[0].x - people[i].x), 2) + pow((people[0].y - people[i].y), 2));
            }
            else if (fabs(people[0].x - people[i].x) < 50 && fabs(people[0].y - people[i].y) < 50 && inter_state == 1)
            {
                distance = sqrt(pow((people[0].x - people[i].x), 2) + pow((people[0].y - people[i].y), 2));
                if (distance < min_distance)
                {
                    inter = i;
                    min_distance = distance;
                }
            }
        }
    }
    
    // Door
    
    if (fabs(people[0].x - 600) < 50 && fabs(people[0].y - 750) < 50)
    {
        if (inter_state == 1)
        {
            distance = sqrt(pow((people[0].x - 600), 2) + pow((people[0].y - 750), 2));
            if (distance < min_distance)
            {
                inter = 0;
                min_distance = distance;
            }
        }
        else
        {
            inter = 0;
            inter_state = 1;
        }
    }
    
    // Mailbox
    
    if (fabs(people[0].x - 740) < 50 && fabs(people[0].y - 96) < 50)
    {
        if (inter_state == 1)
        {
            distance = sqrt(pow((people[0].x - 740), 2) + pow((people[0].y - 96), 2));
            if (distance < min_distance)
            {
                inter = 7;
                min_distance = distance;
            }
        }
        else
        {
            inter = 7;
            inter_state = 1;
        }
    }
    
    // Clone Machine
    
    if (upgrade[0].state == 1)
    {
        if (fabs(people[0].x - 75) < 50 && (people[0].y - 700) < 50)
        {
            if (inter_state == 1)
            {
                distance = sqrt(pow((people[0].x - 75), 2) + pow((people[0].y - 700), 2));
                if (distance < min_distance)
                {
                    inter = 8;
                    min_distance = distance;
                }
            }
            else
            {
                inter = 8;
                inter_state = 1;
            }
        }
    }
}

const int nPerson = 7;
const int nDesk = 6;
const int nUpgrade = 6;

/*
 silver - r = 192, g = 192, b = 192
 brown - r = 139, g = 69, b = 19
 tan skin - r = 255, g = 205, b = 148
 blue jeans - r = 71, g = 111, b = 181
 Draw Desk First
 y for desk is + 50 of corresponding computer
 Summer -> semester_state = 0
 Fall -> semester_state = 1
 Spring -> semseter_state = 2
 */

int main(void)
{
    int i, key, nShot, inter_state = 0, inter = 9, year = 2017, semester_state = 0, window_term = 0, game_term = 0, setup_flag = 0;
    double x_prof = 600, y_prof = 700, x_profdesk = 600, y_profdesk = 125;
    char decision_leave;
	Advisor ADV;
    srand(time(NULL));
	int StudentCounter = 0;
    FsOpenWindow(16, 16, 1200, 800, 1);
	
    Desk desk[nDesk];
    Computer computer[nDesk];
    Person people[nPerson];
    Upgrade upgrade[nUpgrade];
	GradStudent Student[6];
    GenerateSetup(nDesk, desk, computer, people, upgrade, setup_flag);
    setup_flag = 1;

    for (i = 0; i < nDesk; i++)
    {
        desk[i].state = 1;
        computer[i].state = 1;
        upgrade[i].state = 0;
    }
    
    people[0].state_person = 1;
    people[0].x = x_prof;
    people[0].y = y_prof;
    people[0].r_skin = 255;
    people[0].g_skin = 205;
    people[0].b_skin = 148;
    people[0].r_hair = 0;
    people[0].g_hair = 0;
    people[0].b_hair = 0;
    people[0].r_shirt = 192;
    people[0].g_shirt = 192;
    people[0].b_shirt = 192;
    people[0].r_pants = 71;
    people[0].g_pants = 111;
    people[0].b_pants = 181;
    people[0].r_shoes = 139;
    people[0].g_shoes = 69;
    people[0].b_shoes = 19;
	for (int i = 1; i < nPerson; i++) {

		people[i].r_skin = 255;
		people[i].g_skin = 205;
		people[i].b_skin = 148;
		people[i].r_hair = i*10+rand()%80;
		people[i].g_hair = i*30;
		people[i].b_hair = rand()%255;
		people[i].r_shirt = 192;
		people[i].g_shirt = 192;
		people[i].b_shirt = 192;
		people[i].r_pants = 71;
		people[i].g_pants = 111;
		people[i].b_pants = 181;
		people[i].r_shoes = 139;
		people[i].g_shoes = 69;
		people[i].b_shoes = 19;
}
    
    nShot = 0;
    while (game_term != 1)
    {
        GenerateSetup(nDesk, desk, computer, people, upgrade, setup_flag);
        
        if (semester_state == 0)
        {
            printf("Summer Semester, %d\n", year);
        }
        else if (semester_state == 1)
        {
            printf("Fall Semester, %d\n", year);
        }
        else
        {
            printf("Spring Semester, %d\n", year);
        }
        
		// if happiness < 0: drop out
		// if output >= 100: write paper
		for (int i = 0; i < nDesk; i += 1) {
			if (people[i + 1].state_person == 1) {
				if (Student[i].GetResearchVal() > 100){
					Student[i].CreatePaper();
					Student[i].currpaper->GeneratePaperAfterSuccess(Student[i].personality->getIntelligence(), Student[i].GetFocus());
					printf("Congratulations! Your student ");
					Student[i].PrintName();
					printf(" has published a paper!\n");
					printf("The title is %s\n", Student[i].currpaper->title);
					printf("It was published in %s\n", Student[i].currpaper->journal);
					Student[i].ModifyHappinessValue(20);
					Student[i].ModifyResearchValue(-Student[i].GetResearchVal());
				}
			}
		}


        while (window_term != 1)
        {
            FsPollDevice();
            key = FsInkey();
            
            switch (key)
            {
                case FSKEY_UP:
                    people[0].y -= 10;
                    for (i = 0; i < nDesk; i++)
                    {
                        if (desk[i].state == 1)
                        {
                            if (people[0].y > (desk[i].y - 75) && people[0].y < (desk[i].y + 15) && (people[0].x - 32) < (desk[i].x + 90) && (people[0].x + 32) > (desk[i].x - 90))
                            {
                                people[0].y += 10;
                            }
                        }
                    }
                    if (people[0].y > (y_profdesk - 75) && people[0].y < (y_profdesk + 15) && (people[0].x - 32) < (x_profdesk + 180) && (people[0].x + 32) > (x_profdesk - 180))
                    {
                        people[0].y += 10;
                    }
                    if (people[0].y < 20)
                    {
                        people[0].y += 10;
                    }
                    for (i = 0; i < nUpgrade; i++)
                    {
                        if (upgrade[i].state == 1)
                        {
                            if (people[0].y > (upgrade[i].y - 75) && people[0].y < (upgrade[i].y + 15) && (people[0].x - 32) < (upgrade[i].x + 60) && (people[0].x + 32) > (upgrade[i].x - 60))
                            {
                                people[0].y += 10;
                            }
                        }
                    }
                    break;
                case FSKEY_DOWN:
                    people[0].y += 10;
                    for (i = 0; i < nDesk; i++)
                    {
                        if (desk[i].state == 1)
                        {
                            if (people[0].y > (desk[i].y - 75) && people[0].y < (desk[i].y + 15) && (people[0].x - 32) < (desk[i].x + 90) && (people[0].x + 32) > (desk[i].x - 90))
                            {
                                people[0].y -= 10;
                            }
                        }
                    }
                    if (people[0].y > (y_profdesk - 75) && people[0].y < (y_profdesk + 15) && (people[0].x - 32) < (x_profdesk + 180) && (people[0].x + 32) > (x_profdesk - 180))
                    {
                        people[0].y -= 10;
                    }
                    if (people[0].y > 750)
                    {
                        people[0].y -= 10;
                    }
                    for (i = 0; i < nUpgrade; i++)
                    {
                        if (upgrade[i].state == 1)
                        {
                            if (people[0].y > (upgrade[i].y - 75) && people[0].y < (upgrade[i].y + 15) && (people[0].x - 32) < (upgrade[i].x + 60) && (people[0].x + 32) > (upgrade[i].x - 60))
                            {
                                people[0].y -= 10;
                            }
                        }
                    }
                    break;
                case FSKEY_RIGHT:
                    people[0].x += 10;
                    for (i = 0; i < nDesk; i++)
                    {
                        if (desk[i].state == 1)
                        {
                            if (people[0].y > (desk[i].y - 75) && people[0].y < (desk[i].y + 15) && (people[0].x - 32) < (desk[i].x + 90) && (people[0].x + 32) > (desk[i].x - 90))
                            {
                                people[0].x -= 10;
                            }
                        }
                    }
                    if (people[0].y > (y_profdesk - 75) && people[0].y < (y_profdesk + 15) && (people[0].x - 32) < (x_profdesk + 180) && (people[0].x + 32) > (x_profdesk - 180))
                    {
                        people[0].x -= 10;
                    }
                    if (people[0].x > 1180)
                    {
                        people[0].x -= 10;
                    }
                    for (i = 0; i < nUpgrade; i++)
                    {
                        if (upgrade[i].state == 1)
                        {
                            if (people[0].y > (upgrade[i].y - 75) && people[0].y < (upgrade[i].y + 15) && (people[0].x - 32) < (upgrade[i].x + 60) && (people[0].x + 32) > (upgrade[i].x - 60))
                            {
                                people[0].x -= 10;
                            }
                        }
                    }
                    break;
                case FSKEY_LEFT:
                    people[0].x -= 10;
                    for (i = 0; i < nDesk; i++)
                    {
                        if (desk[i].state == 1)
                        {
                            if (people[0].y > (desk[i].y - 75) && people[0].y < (desk[i].y + 15) && (people[0].x - 32) < (desk[i].x + 90) && (people[0].x + 32) > (desk[i].x - 90))
                            {
                                people[0].x += 10;
                            }
                        }
                    }
                    if (people[0].y > (y_profdesk - 75) && people[0].y < (y_profdesk + 15) && (people[0].x - 32) < (x_profdesk + 180) && (people[0].x + 32) > (x_profdesk - 180))
                    {
                        people[0].x += 10;
                    }
                    if (people[0].x < 20)
                    {
                        people[0].x += 10;
                    }
                    for (i = 0; i < nUpgrade; i++)
                    {
                        if (upgrade[i].state == 1)
                        {
                            if (people[0].y > (upgrade[i].y - 75) && people[0].y < (upgrade[i].y + 15) && (people[0].x - 32) < (upgrade[i].x + 60) && (people[0].x + 32) > (upgrade[i].x - 60))
                            {
                                people[0].x += 10;
                            }
                        }
                    }
                    break;
                case FSKEY_SPACE:
                    Interaction(inter, inter_state, upgrade, people, nPerson);
                    break;
                case FSKEY_ESC:
                    game_term = 1;
                    window_term = 1;
            }
            
            if (inter_state == 1)
            {
                if (inter == 0)
                {
                    printf("Are you sure you want to leave? [Y/N]\n");
                    scanf("%c", &decision_leave);
                    if (decision_leave == 'Y')
                    {
                        window_term = 1;
                    }
                }
                else if (inter == 8)
                {
                    // PUT INTERACTION WITH STUDENT HERE
                    printf("interacting with Clone Machine\n");
                    // LEAVE LINE BELOW
                    inter_state = 0;
                }
                else if (inter == 7)
                {
					if (semester_state % 3 == 0) {
						char choice1[10];
						char choice2[10];
						printf("A:Would you like to hire a new student?[Y/N]\n");
						My2Fgets(choice1, 9, stdin);
						if (choice1[0] == 'Y') {
							ADV.Recruit(Student, StudentCounter);
							people[StudentCounter + 1].state_person = 1;
							//char desired[] = "HOLDENPARKS";
							//Student[StudentCounter].NameStudent(desired, 11);
							//int colorarr[3] = { 100,100,250 };
							//Student[StudentCounter].SetColor(colorarr);
							StudentCounter++;
						}
						printf("A:Do you want to upgrade the office and lab ?[Y/N]\n");
						My2Fgets(choice2, 9, stdin);
						if (choice2[0] == 'Y') {
							ADV.UpgradeLab(Student,upgrade,people,StudentCounter);
						}
					}
					if (semester_state % 3 == 1) {
						printf("Would you like to write a grant?[Y/N]\n");
						char a[5];
						My2Fgets(a, 4, stdin);
						if (a[0] == 'Y') {
							ADV.WriteGrant();
						}
						else {
							printf("You don`t want to write a grant huh, then how are you gonna feed these poor grads!!\n");
						}
					}
					if (semester_state % 3 == 2) {
						printf("Do you wanna party\n");
						ADV.Party(Student, StudentCounter);
					}
                    inter_state = 0;
                }
                else
                {
					printf("interacting with Student\n"); //add name, print student name
					char actionn = actionforStudent();
					if (actionn == 'A') {
						printf("YEAR:%d\n",Student[inter -1].GetYear());
						printf("Focus:%d\n", Student[inter - 1].GetFocus());
						Student[inter - 1].PrintPersonality();
						Student[inter - 1].CheckIn();
					}
					if (actionn == 'B') {
						ADV.SendtoCompany(Student, inter-1);
					}
					if (actionn == 'C') {
						ADV.SetResearchFocus(Student, inter - 1);
					}
                    // LEAVE LINE BELOW
                    inter_state = 0;
                }
            }
            
            glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
            DrawRoom();
            for (i = 0; i<nPerson; i++)
            {
                if (people[i].state_person != 0)
                {
                    if (people[i].y < 125)
                    {
                        people[i].Draw_up_still();
                    }
                }
            }
            DrawProfDesk(x_profdesk, y_profdesk);
            for (i = 0; i<nPerson; i++)
            {
                if (people[i].state_person != 0)
                {
                    if (people[i].y < 225 && people[i].y >= 100)
                    {
                        people[i].Draw_up_still();
                    }
                }
            }
            if (desk[2].state != 0)
            {
                desk[2].Draw();
            }
            if (computer[2].state != 0)
            {
                computer[2].Draw();
            }
            if (upgrade[2].state != 0)
            {
                upgrade[2].Draw_CNC();
            }
            if (upgrade[5].state != 0)
            {
                upgrade[5].Draw_Server();
            }
            if (desk[5].state != 0)
            {
                desk[5].Draw();
            }
            if (computer[5].state != 0)
            {
                computer[5].Draw();
            }
            for (i = 0; i<nPerson; i++)
            {
                if (people[i].state_person != 0)
                {
                    if (people[i].y < 425 && people[i].y >= 225)
                    {
                        people[i].Draw_up_still();
                    }
                }
            }
            if (desk[1].state != 0)
            {
                desk[1].Draw();
            }
            if (computer[1].state != 0)
            {
                computer[1].Draw();
            }
            if (upgrade[1].state != 0)
            {
                upgrade[1].Draw_Print();
            }
            if (upgrade[4].state != 0)
            {
                upgrade[4].Draw_Chem();
            }
            if (desk[4].state != 0)
            {
                desk[4].Draw();
            }
            if (computer[4].state != 0)
            {
                computer[4].Draw();
            }
            for (i = 0; i<nPerson; i++)
            {
                if (people[i].state_person != 0)
                {
                    if (people[i].y < 625 && people[i].y >= 425)
                    {
                        people[i].Draw_up_still();
                    }
                }
            }
            if (desk[0].state != 0)
            {
                desk[0].Draw();
            }
            if (computer[0].state != 0)
            {
                computer[0].Draw();
            }
            if (upgrade[0].state != 0)
            {
                upgrade[0].Draw_Clone();
            }
            if (upgrade[3].state != 0)
            {
                upgrade[3].Draw_Coffee();
            }
            if (desk[3].state != 0)
            {
                desk[3].Draw();
            }
            if (computer[3].state != 0)
            {
                computer[3].Draw();
            }
            for (i = 0; i<nPerson; i++)
            {
                if (people[i].state_person != 0)
                {
                    if (people[i].y <= 800 && people[i].y >= 625)
                    {
                        people[i].Draw_up_still();
                    }
                }
            }
            FsSwapBuffers();
            
            FsSleep(30);
        }
        
        if (semester_state == 0)
        {
            semester_state = 1;
        }
        else if (semester_state == 1)
        {
            semester_state = 2;
            year++;
        }
        else if (semester_state == 2)
        {
            semester_state = 0;
        }
        
        window_term = 0;
        inter_state = 0;
        // ADD OTHER UPDATES AT END OF A SEMESTER HERE
		for (int i = 0; i < nDesk; i += 1){
			if (people[i + 1].state_person == 1) {
				Student[i].turn();
			}
		}
    }
    return 0;
}
