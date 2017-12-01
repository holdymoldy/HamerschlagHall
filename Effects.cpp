#include "Effects.h"
#include "fssimplewindow.h"
#include "ysglfontdata.h"
#include <stdio.h>

void Effect::DrawMoney(float money)
{
	char moneyStr[100];
	sprintf_s(moneyStr, "Money: $%.2f", money);
	glRasterPos2i(50, 50);
	glColor3ub(0, 0, 255);
	YsGlDrawFontBitmap10x14(moneyStr);
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

	alpha -= 3;
	if (0 >= alpha)
	{
		tState = 0;
	}
}

