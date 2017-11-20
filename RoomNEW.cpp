
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

void GenerateSetup(int nDesk, Desk desk[6], Computer computer[6], Person people[7], Upgrade upgrade[6])
{
	int i;
	for (i = 0; i<nDesk / 2; i++)
	{
		desk[i].state = 0;
		desk[i].x = 400;
		desk[i].y = 700 - 200 * i;

		computer[i].state = 0;
		computer[i].x = 400;
		computer[i].y = 650 - 200 * i;

		people[i + 1].state_person = 0;
		people[i + 1].x = 400;
		people[i + 1].y = 620 - 200 * i;

		upgrade[i].state = 0;
		upgrade[i].x = 65;
		upgrade[i].y = 700 - 200 * i;

		desk[i + 3].state = 0;
		desk[i + 3].x = 800;
		desk[i + 3].y = 700 - 200 * i;

		computer[i + 3].state = 0;
		computer[i + 3].x = 800;
		computer[i + 3].y = 650 - 200 * i;

		people[i + 4].state_person = 0;
		people[i + 4].x = 800;
		people[i + 4].y = 620 - 200 * i;

		upgrade[i + 3].state = 0;
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

	 using namespace std;

	
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
	 */

	 int main(void)
	 {
		 int StudentCounter = 0;
		 Advisor ADV;
		 int i, key, nShot;
		 double x_prof = 600, y_prof = 700, x_profdesk = 600, y_profdesk = 125;
		 const double PI = 3.1415927;

		 srand(time(NULL));

		 FsOpenWindow(16, 16, 1200, 800, 1);
		 GradStudent student[6];
		 Desk desk[nDesk];
		 Computer computer[nDesk];
		 Person people[nPerson];
		 Upgrade upgrade[nUpgrade];

		 GenerateSetup(nDesk, desk, computer, people, upgrade);

		 for (i = 0; i < nDesk; i++)
		 {
			 desk[i].state = 1;
			 computer[i].state = 1;
			 upgrade[i].state = 1;
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
	
		 people[1].x = x_prof;
		 people[1].y = y_prof;
		 people[1].r_skin = 255;
		 people[1].g_skin = 205;
		 people[1].b_skin = 148;
		 people[1].r_hair = 100;
		 people[1].g_hair = 50;
		 people[1].b_hair = 200;
		 people[1].r_shirt = 192;
		 people[1].g_shirt = 12;
		 people[1].b_shirt = 12;
		 people[1].r_pants = 71;
		 people[1].g_pants = 111;
		 people[1].b_pants = 181;
		 people[1].r_shoes = 139;
		 people[1].g_shoes = 69;
		 people[1].b_shoes = 19;

		 FsPollDevice();

		 nShot = 0;
		 while (FSKEY_ESC != (key = FsInkey()))
		 {
			 FsPollDevice();

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
				 if (people[0].y < 300 && people[0].x < 200) {
					 ADV.Semester++;
				 }
				 if (people[0].y < 300 && people[0].x >800)
				 {
					 if (ADV.Semester % 3 == 1) {
						 char Ans[3];
						 printf("would you like to apply to a Grant? Y/N\n");
						 My2Fgets(Ans, 2, stdin);
						 if (Ans[0] == 'Y') {
							 ADV.WriteGrant();
						 }
					 }
					 if (ADV.Semester % 3 == 0) {
						 char Ans[3];
						 printf("would you like to hire to a New Graduate Student? Y/N\n");
						 My2Fgets(Ans, 2, stdin);
						 if (Ans[0] == 'Y') {
							
							 ADV.Recruit(student, StudentCounter);
							 printf("YOU GOT OUT OF THE RECRUIT");
							 people[StudentCounter + 1].state_person = 1;
							 StudentCounter++;
						 }
					 }
					 if (ADV.Semester % 3 == 2) {
						 char Ans[3];
						 printf("would you like to attend a Conference? Y/N\n");
						 My2Fgets(Ans, 2, stdin);
						 if (Ans[0] == 'Y') {
							 ADV.Conference(student, StudentCounter);
						 }
					 }
				 }
					 break;
			 case FSKEY_P:
				 if (people[0].y < 300 && people[0].x < 200) {
					 for (int i = 0; i < StudentCounter; i++) {
						 student[i].PrintPersonality();
					 }
				 }
				 break;
				 }

			 /*
			 int j;
			 for (j = 1; j < people.nPerson; j++)
			 {
			 if (CheckHitTarget(people[0].x, people[0].y, people[j].x, people[j].y, w, h) == 1)
			 {
			 check[0] = 1;
			 check[1] = j;
			 }
			 }
			 */

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
				 upgrade[2].Draw_Chem();
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
				 upgrade[1].Draw_Chem();
			 }
			 if (upgrade[4].state != 0)
			 {
				 upgrade[4].Draw_Coffee();
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
				 upgrade[3].Draw_Chem();
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

		 return 0;
	 }