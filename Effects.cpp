#include "Effects.h"
#include "fssimplewindow.h"
#include "ysglfontdata.h"
#include <stdio.h>
#include "Advisor.h"

void Effect::DrawMoney(float money, float pres, float know, float ment, float exp, int sem, int year)
{
	char moneyStr[255], datStr[255];
	switch (sem)
	{
	case(0):
		sprintf(datStr, "Summer Semester, %d", year);
		break;
	case(1):
		sprintf(datStr, "Fall Semester, %d", year);
		break;
	case(2):
		sprintf(datStr, "Spring Semester, %d", year);
		break;
	}
	sprintf(moneyStr, "Money: $%.2f   Prestige: %.2f   Knowledge: %.2f   Mentoring: %.2f   Experience: %.2f", money, pres, know, ment, exp);
	glRasterPos2i(20, 20);
	glColor3ub(1, 1, 1);
	YsGlDrawFontBitmap10x14(moneyStr);
	glRasterPos2i(20, 50);
	glColor3ub(1, 1, 1);
	YsGlDrawFontBitmap10x14(datStr);
}

void Effect::initTransition(void)
{
	if (0 == tState)
	{
		tState = 1;
		alpha = 255;
	}
}

void Effect::DrawTransition(void)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glColor4ub(0, 0, 0, alpha);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(x, y);
	glVertex2i(x + 1200, y);
	glVertex2i(x + 1200, y + 800);
	glVertex2i(x, y + 800);
	glEnd();

	alpha -= 5;
	if (0 >= alpha)
	{
		tState = 0;
	}
}

