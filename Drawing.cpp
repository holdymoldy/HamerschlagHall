#include "Drawing.h"
#include "fssimplewindow.h"
#include <math.h>


void DrawCircle(double cx, double cy, int rad, int fill)
{
	const double YS_PI = 3.1415927;

	if (0 != fill)
	{
		glBegin(GL_POLYGON);
	}
	else
	{
		glBegin(GL_LINE_LOOP);
	}

	int i;
	for (i = 0; i<64; i++)
	{
		double angle = (double)i*YS_PI / 32.0;
		double x = cx + cos(angle)*(double)rad;
		double y = cy + sin(angle)*(double)rad;
		glVertex2d(x, y);
	}

	glEnd();
}

void Upgrade::Draw_CNC(void)
{
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2i(x - 40, y - 65);
	glVertex2i(x + 40, y - 65);
	glVertex2i(x + 40, y + 5);
	glVertex2i(x - 40, y + 5);
	glEnd();

	glColor3ub(20, 20, 20);
	DrawCircle(x - 40, y - 60, 4, 1);

	glColor3ub(20, 20, 20);
	DrawCircle(x - 40, y - 58, 4, 1);

	glColor3ub(20, 20, 20);
	glBegin(GL_QUADS);
	glVertex2i(x - 40, y - 60);
	glVertex2i(x - 30, y - 60);
	glVertex2i(x - 30, y - 58);
	glVertex2i(x - 40, y - 58);
	glEnd();

	glColor3ub(20, 20, 20);
	DrawCircle(x - 40, y - 48, 4, 1);

	glColor3ub(20, 20, 20);
	DrawCircle(x - 40, y - 46, 4, 1);

	glColor3ub(20, 20, 20);
	glBegin(GL_QUADS);
	glVertex2i(x - 40, y - 48);
	glVertex2i(x - 25, y - 48);
	glVertex2i(x - 25, y - 46);
	glVertex2i(x - 40, y - 46);
	glEnd();

	glColor3ub(0, 0, 205);
	glBegin(GL_QUADS);
	glVertex2i(x - 60, y - 95);
	glVertex2i(x + 60, y - 95);
	glVertex2i(x + 60, y - 65);
	glVertex2i(x - 60, y - 65);
	glEnd();

	glColor3ub(0, 0, 128);
	glBegin(GL_QUADS);
	glVertex2d((double)x - 57.5, (double)y - 115);
	glVertex2d((double)x + 57.5, (double)y - 115);
	glVertex2i(x + 60, y - 95);
	glVertex2i(x - 60, y - 95);
	glEnd();

	glColor3ub(0, 0, 205);
	glBegin(GL_QUADS);
	glVertex2i(x - 60, y - 65);
	glVertex2i(x - 40, y - 65);
	glVertex2i(x - 40, y + 100);
	glVertex2i(x - 60, y + 100);
	glEnd();

	glColor3ub(0, 0, 205);
	glBegin(GL_QUADS);
	glVertex2i(x + 60, y - 65);
	glVertex2i(x + 40, y - 65);
	glVertex2i(x + 40, y + 100);
	glVertex2i(x + 60, y + 100);
	glEnd();

	glColor3ub(0, 0, 205);
	glBegin(GL_QUADS);
	glVertex2i(x - 60, y + 5);
	glVertex2i(x + 60, y + 5);
	glVertex2i(x + 60, y + 100);
	glVertex2i(x - 60, y + 100);
	glEnd();

	glColor3ub(105, 105, 105);
	glBegin(GL_QUADS);
	glVertex2i(x - 35, y - 5);
	glVertex2i(x + 35, y - 5);
	glVertex2i(x + 35, y + 5);
	glVertex2i(x - 35, y + 5);
	glEnd();

	glColor3ub(105, 105, 105);
	glBegin(GL_QUADS);
	glVertex2i(x - 20, y - 65);
	glVertex2i(x + 20, y - 65);
	glVertex2i(x + 20, y - 35);
	glVertex2i(x - 20, y - 35);
	glEnd();

	glColor3ub(20, 20, 20);
	DrawCircle(x - 2, y - 20, 4, 1);

	glColor3ub(20, 20, 20);
	DrawCircle(x + 2, y - 20, 4, 1);

	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(x - 10, y - 35);
	glVertex2i(x + 10, y - 35);
	glVertex2i(x + 10, y - 20);
	glVertex2i(x - 10, y - 20);
	glEnd();

	glColor3ub(20, 20, 20);
	glBegin(GL_QUADS);
	glVertex2i(x - 2, y - 20);
	glVertex2i(x + 2, y - 20);
	glVertex2i(x + 2, y - 10);
	glVertex2i(x - 2, y - 10);
	glEnd();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glColor4ub(201, 219, 220, 125);
	glBegin(GL_QUADS);
	glVertex2i(x - 40, y - 65);
	glVertex2i(x + 40, y - 65);
	glVertex2i(x + 40, y + 5);
	glVertex2i(x - 40, y + 5);
	glEnd();

	glColor4ub(0, 0, 0, 125);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x - 40, y - 65);
	glVertex2i(x, y - 65);
	glVertex2i(x, y + 5);
	glVertex2i(x - 40, y + 5);
	glEnd();

	glColor4ub(0, 0, 0, 125);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x + 40, y - 65);
	glVertex2i(x, y - 65);
	glVertex2i(x, y + 5);
	glVertex2i(x + 40, y + 5);
	glEnd();

	glDisable(GL_BLEND);

	glColor3ub(105, 105, 105);
	glBegin(GL_QUADS);
	glVertex2i(x - 40, y + 10);
	glVertex2i(x + 40, y + 10);
	glVertex2i(x + 40, y + 52);
	glVertex2i(x - 40, y + 52);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(x - 38, y + 12);
	glVertex2i(x + 1, y + 12);
	glVertex2i(x + 1, y + 40);
	glVertex2i(x - 38, y + 40);
	glEnd();

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			glColor3ub(255, 255, 255);
			glBegin(GL_QUADS);
			glVertex2i(x - 38 + 5 * i, y + 41 + 5 * j);
			glVertex2i(x - 34 + 5 * i, y + 41 + 5 * j);
			glVertex2i(x - 34 + 5 * i, y + 45 + 5 * j);
			glVertex2i(x - 38 + 5 * i, y + 45 + 5 * j);
			glEnd();
		}
	}

	glColor3ub(255, 255, 0);
	DrawCircle(x + 8, y + 19, 6, 1);

	glColor3ub(255, 0, 0);
	DrawCircle(x + 8, y + 19, 4, 1);

	glColor3ub(0, 0, 0);
	DrawCircle(x + 8, y + 30, 4, 1);

	glColor3ub(0, 0, 0);
	DrawCircle(x + 8, y + 39, 4, 1);

	glColor3ub(0, 0, 0);
	DrawCircle(x + 8, y + 48, 4, 1);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			glColor3ub(255, 255, 255);
			glBegin(GL_QUADS);
			glVertex2i(x + 14 + 5 * i, y + 12 + 5 * j);
			glVertex2i(x + 18 + 5 * i, y + 12 + 5 * j);
			glVertex2i(x + 18 + 5 * i, y + 16 + 5 * j);
			glVertex2i(x + 14 + 5 * i, y + 16 + 5 * j);
			glEnd();
		}
	}

	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2i(x + 24, y + 39);
	glVertex2i(x + 28, y + 39);
	glVertex2i(x + 28, y + 43);
	glVertex2i(x + 24, y + 43);
	glEnd();

	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2i(x + 24, y + 44);
	glVertex2i(x + 28, y + 44);
	glVertex2i(x + 28, y + 48);
	glVertex2i(x + 24, y + 48);
	glEnd();

	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2i(x + 19, y + 42);
	glVertex2i(x + 23, y + 42);
	glVertex2i(x + 23, y + 46);
	glVertex2i(x + 19, y + 46);
	glEnd();

	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2i(x + 29, y + 42);
	glVertex2i(x + 33, y + 42);
	glVertex2i(x + 33, y + 46);
	glVertex2i(x + 29, y + 46);
	glEnd();
}

void Upgrade::Draw_Print(void)
{
	glColor3ub(139, 69, 19);
	glBegin(GL_POLYGON);
	glVertex2d((double)x - 57.5, (double)y);
	glVertex2d((double)x + 57.5, (double)y);
	glVertex2i(x + 60, y + 40);
	glVertex2i(x - 60, y + 40);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2d((double)x - 57.5, (double)y);
	glVertex2d((double)x + 57.5, (double)y);
	glVertex2i(x + 60, y + 40);
	glVertex2i(x - 60, y + 40);
	glEnd();

	glColor3ub(160, 82, 45);
	glBegin(GL_QUADS);
	glVertex2i(x - 60, y + 40);
	glVertex2i(x + 60, y + 40);
	glVertex2i(x + 60, y + 60);
	glVertex2i(x - 60, y + 60);
	glEnd();

	glColor3ub(160, 82, 45);
	glBegin(GL_QUADS);
	glVertex2i(x - 50, y + 60);
	glVertex2i(x - 30, y + 60);
	glVertex2i(x - 30, y + 100);
	glVertex2i(x - 50, y + 100);
	glEnd();

	glColor3ub(160, 82, 45);
	glBegin(GL_QUADS);
	glVertex2i(x + 50, y + 60);
	glVertex2i(x + 30, y + 60);
	glVertex2i(x + 30, y + 100);
	glVertex2i(x + 50, y + 100);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(x - 60, y + 60);
	glVertex2i(x + 60, y + 60);
	glEnd();

	glColor3ub(160, 82, 45);
	glBegin(GL_QUADS);
	glVertex2i(x + 50, y + 60);
	glVertex2i(x + 30, y + 60);
	glVertex2i(x + 30, y + 100);
	glVertex2i(x + 50, y + 100);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(x - 55, y - 65);
	glVertex2i(x + 55, y - 65);
	glVertex2i(x + 55, y - 45);
	glVertex2i(x - 55, y - 45);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(x - 55, y - 45);
	glVertex2i(x - 35, y - 45);
	glVertex2i(x - 35, y + 35);
	glVertex2i(x - 55, y + 35);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(x + 55, y - 45);
	glVertex2i(x + 35, y - 45);
	glVertex2i(x + 35, y + 35);
	glVertex2i(x + 55, y + 35);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(x - 35, y + 15);
	glVertex2i(x + 35, y + 15);
	glVertex2i(x + 35, y + 35);
	glVertex2i(x - 35, y + 35);
	glEnd();

	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2i(x - 35, y - 45);
	glVertex2i(x + 35, y - 45);
	glVertex2i(x + 35, y + 15);
	glVertex2i(x - 35, y + 15);
	glEnd();

	glColor3ub(31, 31, 31);
	glBegin(GL_QUADS);
	glVertex2d((double)x - 52.5, (double)y - 85);
	glVertex2d((double)x + 52.5, (double)y - 85);
	glVertex2i(x + 55, y - 65);
	glVertex2i(x - 55, y - 65);
	glEnd();

	glColor3ub(0, 255, 0);
	DrawCircle(x - 15, y, 5, 1);

	glColor3ub(0, 255, 0);
	DrawCircle(x + 15, y, 5, 1);

	glColor3ub(0, 255, 0);
	glBegin(GL_QUADS);
	glVertex2i(x - 25, y - 13);
	glVertex2i(x + 25, y - 13);
	glVertex2i(x + 25, y - 3);
	glVertex2i(x - 25, y - 3);
	glEnd();

	glColor3ub(0, 255, 0);
	glBegin(GL_QUADS);
	glVertex2i(x - 18, y - 30);
	glVertex2i(x + 18, y - 30);
	glVertex2i(x + 18, y - 13);
	glVertex2i(x - 18, y - 13);
	glEnd();

	glColor3ub(105, 105, 105);
	glBegin(GL_QUADS);
	glVertex2i(x - 25, y + 5);
	glVertex2i(x + 25, y + 5);
	glVertex2i(x + 25, y + 15);
	glVertex2i(x - 25, y + 15);
	glEnd();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glColor4ub(201, 219, 220, 175);
	glBegin(GL_QUADS);
	glVertex2i(x - 35, y - 45);
	glVertex2i(x + 35, y - 45);
	glVertex2i(x + 35, y + 15);
	glVertex2i(x - 35, y + 15);
	glEnd();

	glDisable(GL_BLEND);
}

void Upgrade::Draw_Clone(void)
{
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glVertex2i(x - 40, y - 65);
	glVertex2i(x + 40, y - 65);
	glVertex2i(x + 40, y + 80);
	glVertex2i(x - 40, y + 80);
	glEnd();

	glColor3ub(105, 105, 105);
	glBegin(GL_TRIANGLES);
	glVertex2i(x - 30, y - 45);
	glVertex2i(x + 30, y - 45);
	glVertex2i(x, y - 70);
	glEnd();

	glColor3ub(220, 220, 220);
	glBegin(GL_QUADS);
	glVertex2i(x - 70, y - 95);
	glVertex2i(x + 60, y - 95);
	glVertex2i(x + 60, y - 65);
	glVertex2i(x - 70, y - 65);
	glEnd();

	glColor3ub(192, 192, 192);
	glBegin(GL_QUADS);
	glVertex2d((double)x - 67.5, (double)y - 115);
	glVertex2d((double)x + 57.5, (double)y - 115);
	glVertex2i(x + 60, y - 95);
	glVertex2i(x - 70, y - 95);
	glEnd();

	glColor3ub(220, 220, 220);
	glBegin(GL_QUADS);
	glVertex2i(x - 70, y - 65);
	glVertex2i(x - 40, y - 65);
	glVertex2i(x - 40, y + 100);
	glVertex2i(x - 70, y + 100);
	glEnd();

	glColor3ub(220, 220, 220);
	glBegin(GL_QUADS);
	glVertex2i(x + 60, y - 65);
	glVertex2i(x + 40, y - 65);
	glVertex2i(x + 40, y + 100);
	glVertex2i(x + 60, y + 100);
	glEnd();

	glColor3ub(220, 220, 220);
	glBegin(GL_QUADS);
	glVertex2i(x - 70, y + 80);
	glVertex2i(x + 60, y + 80);
	glVertex2i(x + 60, y + 100);
	glVertex2i(x - 70, y + 100);
	glEnd();

	glColor3ub(105, 105, 105);
	glBegin(GL_QUADS);
	glVertex2i(x - 35, y + 70);
	glVertex2i(x + 35, y + 70);
	glVertex2i(x + 35, y + 80);
	glVertex2i(x - 35, y + 80);
	glEnd();

	glColor3ub(105, 105, 105);
	glBegin(GL_QUADS);
	glVertex2i(x - 66, y - 20);
	glVertex2i(x - 44, y - 20);
	glVertex2i(x - 44, y + 20);
	glVertex2i(x - 66, y + 20);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(x - 64, y - 17);
	glVertex2i(x - 46, y - 17);
	glVertex2i(x - 46, y - 7);
	glVertex2i(x - 64, y - 7);
	glEnd();

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			glColor3ub(220, 220, 220);
			glBegin(GL_QUADS);
			glVertex2i(x - 63 + 6 * i, y - 5 + 7 * j);
			glVertex2i(x - 59 + 6 * i, y - 5 + 7 * j);
			glVertex2i(x - 59 + 6 * i, y + 7 * j);
			glVertex2i(x - 63 + 6 * i, y + 7 * j);
			glEnd();
		}
	}

	glColor3ub(57, 255, 20);
	DrawCircle(x - 30, y + 75, 3, 1);

	glColor3ub(253, 28, 3);
	DrawCircle(x - 20, y + 75, 3, 1);

	glColor3ub(0, 98, 255);
	DrawCircle(x - 10, y + 75, 3, 1);

	glColor3ub(255, 255, 51);
	DrawCircle(x, y + 75, 3, 1);

	glColor3ub(157, 0, 255);
	DrawCircle(x + 10, y + 75, 3, 1);

	glColor3ub(255, 0, 153);
	DrawCircle(x + 20, y + 75, 3, 1);

	glColor3ub(204, 204, 204);
	DrawCircle(x + 30, y + 75, 3, 1);

	glColor3ub(105, 105, 105);
	glBegin(GL_QUADS);
	glVertex2i(x - 10, y - 65);
	glVertex2i(x + 10, y - 65);
	glVertex2i(x + 10, y - 55);
	glVertex2i(x - 10, y - 55);
	glEnd();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glColor4ub(201, 219, 220, 125);
	glBegin(GL_QUADS);
	glVertex2i(x - 40, y - 65);
	glVertex2i(x + 40, y - 65);
	glVertex2i(x + 40, y + 80);
	glVertex2i(x - 40, y + 80);
	glEnd();

	glColor4ub(0, 0, 0, 125);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x - 40, y - 65);
	glVertex2i(x, y - 65);
	glVertex2i(x, y + 80);
	glVertex2i(x - 40, y + 80);
	glEnd();

	glColor4ub(0, 0, 0, 125);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x + 40, y - 65);
	glVertex2i(x, y - 65);
	glVertex2i(x, y + 80);
	glVertex2i(x + 40, y + 80);
	glEnd();

	glDisable(GL_BLEND);
}

void Upgrade::Draw_Chem(void)
{
	glColor3ub(139, 69, 19);
	glBegin(GL_POLYGON);
	glVertex2d((double)x - 57.5, (double)y);
	glVertex2d((double)x + 57.5, (double)y);
	glVertex2i(x + 60, y + 40);
	glVertex2i(x - 60, y + 40);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2d((double)x - 57.5, (double)y);
	glVertex2d((double)x + 57.5, (double)y);
	glVertex2i(x + 60, y + 40);
	glVertex2i(x - 60, y + 40);
	glEnd();

	glColor3ub(160, 82, 45);
	glBegin(GL_QUADS);
	glVertex2i(x - 60, y + 40);
	glVertex2i(x + 60, y + 40);
	glVertex2i(x + 60, y + 60);
	glVertex2i(x - 60, y + 60);
	glEnd();

	glColor3ub(160, 82, 45);
	glBegin(GL_QUADS);
	glVertex2i(x - 50, y + 60);
	glVertex2i(x - 30, y + 60);
	glVertex2i(x - 30, y + 100);
	glVertex2i(x - 50, y + 100);
	glEnd();

	glColor3ub(160, 82, 45);
	glBegin(GL_QUADS);
	glVertex2i(x + 50, y + 60);
	glVertex2i(x + 30, y + 60);
	glVertex2i(x + 30, y + 100);
	glVertex2i(x + 50, y + 100);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(x - 60, y + 60);
	glVertex2i(x + 60, y + 60);
	glEnd();

	glColor3ub(0, 220, 0);
	glBegin(GL_QUADS);
	glVertex2i(x - 32, y + 6);
	glVertex2i(x - 28, y + 6);
	glVertex2i(x - 28, y + 14);
	glVertex2i(x - 32, y + 14);
	glEnd();

	glColor3ub(0, 220, 0);
	DrawCircle(x - 30, y + 14, 4, 1);

	glColor3ub(0, 220, 0);
	DrawCircle(x - 42, y + 28, 4, 1);

	glColor3ub(0, 220, 0);
	DrawCircle(x - 18, y + 28, 4, 1);

	glColor3ub(0, 220, 0);
	glBegin(GL_TRIANGLES);
	glVertex2i(x - 14, y + 28);
	glVertex2i(x - 30, y + 28);
	glVertex2i(x - 30, y + 6);
	glEnd();

	glColor3ub(0, 220, 0);
	glBegin(GL_TRIANGLES);
	glVertex2i(x - 46, y + 28);
	glVertex2i(x - 30, y + 28);
	glVertex2i(x - 30, y + 6);
	glEnd();

	glColor3ub(0, 220, 0);
	glBegin(GL_QUADS);
	glVertex2i(x - 42, y + 32);
	glVertex2i(x - 42, y + 28);
	glVertex2i(x - 18, y + 28);
	glVertex2i(x - 18, y + 32);
	glEnd();

	glColor3ub(0, 0, 220);
	glBegin(GL_QUADS);
	glVertex2i(x + 28, y + 6);
	glVertex2i(x + 32, y + 6);
	glVertex2i(x + 32, y + 14);
	glVertex2i(x + 28, y + 14);
	glEnd();

	glColor3ub(0, 0, 220);
	DrawCircle(x + 30, y + 14, 4, 1);

	glColor3ub(0, 0, 220);
	DrawCircle(x + 18, y + 28, 4, 1);

	glColor3ub(0, 0, 220);
	DrawCircle(x + 42, y + 28, 4, 1);

	glColor3ub(0, 0, 220);
	glBegin(GL_TRIANGLES);
	glVertex2i(x + 46, y + 28);
	glVertex2i(x + 30, y + 28);
	glVertex2i(x + 30, y + 6);
	glEnd();

	glColor3ub(0, 0, 220);
	glBegin(GL_TRIANGLES);
	glVertex2i(x + 14, y + 28);
	glVertex2i(x + 30, y + 28);
	glVertex2i(x + 30, y + 6);
	glEnd();

	glColor3ub(0, 0, 220);
	glBegin(GL_QUADS);
	glVertex2i(x + 42, y + 32);
	glVertex2i(x + 42, y + 28);
	glVertex2i(x + 18, y + 28);
	glVertex2i(x + 18, y + 32);
	glEnd();

	glColor3ub(199, 21, 133);
	glBegin(GL_QUADS);
	glVertex2i(x - 2, y - 16);
	glVertex2i(x + 2, y - 16);
	glVertex2i(x + 2, y - 8);
	glVertex2i(x - 2, y - 8);
	glEnd();

	glColor3ub(199, 21, 133);
	DrawCircle(x, y - 8, 4, 1);

	glColor3ub(199, 21, 133);
	DrawCircle(x - 12, y + 6, 4, 1);

	glColor3ub(199, 21, 133);
	DrawCircle(x + 12, y + 6, 4, 1);

	glColor3ub(199, 21, 133);
	glBegin(GL_TRIANGLES);
	glVertex2i(x + 16, y + 6);
	glVertex2i(x, y + 6);
	glVertex2i(x, y - 16);
	glEnd();

	glColor3ub(199, 21, 133);
	glBegin(GL_TRIANGLES);
	glVertex2i(x - 16, y + 6);
	glVertex2i(x, y + 6);
	glVertex2i(x, y - 16);
	glEnd();

	glColor3ub(199, 21, 133);
	glBegin(GL_QUADS);
	glVertex2i(x + 12, y + 10);
	glVertex2i(x + 12, y + 6);
	glVertex2i(x - 12, y + 6);
	glVertex2i(x - 12, y + 10);
	glEnd();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glColor4ub(201, 219, 220, 175);
	glBegin(GL_QUADS);
	glVertex2i(x - 40, y + 3);
	glVertex2i(x - 20, y + 3);
	glVertex2i(x - 20, y - 2);
	glVertex2i(x - 40, y - 2);
	glEnd();

	glColor4ub(201, 219, 220, 175);
	glBegin(GL_TRIANGLES);
	glVertex2i(x - 50, y + 28);
	glVertex2i(x - 35, y + 28);
	glVertex2i(x - 35, y + 8);
	glEnd();

	glColor4ub(201, 219, 220, 175);
	glBegin(GL_TRIANGLES);
	glVertex2i(x - 25, y + 28);
	glVertex2i(x - 25, y + 8);
	glVertex2i(x - 10, y + 28);
	glEnd();

	glColor4ub(201, 219, 220, 175);
	glBegin(GL_QUADS);
	glVertex2i(x - 35, y + 3);
	glVertex2i(x - 25, y + 3);
	glVertex2i(x - 25, y + 28);
	glVertex2i(x - 35, y + 28);
	glEnd();

	glColor4ub(201, 219, 220, 175);
	glBegin(GL_QUADS);
	glVertex2i(x - 50, y + 28);
	glVertex2i(x - 10, y + 28);
	glVertex2i(x - 10, y + 35);
	glVertex2i(x - 50, y + 35);
	glEnd();

	glColor4ub(201, 219, 220, 175);
	glBegin(GL_QUADS);
	glVertex2i(x + 20, y + 3);
	glVertex2i(x + 40, y + 3);
	glVertex2i(x + 40, y - 2);
	glVertex2i(x + 20, y - 2);
	glEnd();

	glColor4ub(201, 219, 220, 175);
	glBegin(GL_TRIANGLES);
	glVertex2i(x + 10, y + 28);
	glVertex2i(x + 25, y + 28);
	glVertex2i(x + 25, y + 8);
	glEnd();

	glColor4ub(201, 219, 220, 175);
	glBegin(GL_TRIANGLES);
	glVertex2i(x + 35, y + 28);
	glVertex2i(x + 35, y + 8);
	glVertex2i(x + 50, y + 28);
	glEnd();

	glColor4ub(201, 219, 220, 175);
	glBegin(GL_QUADS);
	glVertex2i(x + 25, y + 3);
	glVertex2i(x + 35, y + 3);
	glVertex2i(x + 35, y + 28);
	glVertex2i(x + 25, y + 28);
	glEnd();

	glColor4ub(201, 219, 220, 175);
	glBegin(GL_QUADS);
	glVertex2i(x + 10, y + 28);
	glVertex2i(x + 50, y + 28);
	glVertex2i(x + 50, y + 35);
	glVertex2i(x + 10, y + 35);
	glEnd();

	glColor4ub(201, 219, 220, 175);
	glBegin(GL_QUADS);
	glVertex2i(x - 10, y - 19);
	glVertex2i(x + 10, y - 19);
	glVertex2i(x + 10, y - 24);
	glVertex2i(x - 10, y - 24);
	glEnd();

	glColor4ub(201, 219, 220, 175);
	glBegin(GL_TRIANGLES);
	glVertex2i(x - 20, y + 6);
	glVertex2i(x - 5, y + 6);
	glVertex2i(x - 5, y - 14);
	glEnd();

	glColor4ub(201, 219, 220, 175);
	glBegin(GL_TRIANGLES);
	glVertex2i(x + 5, y + 6);
	glVertex2i(x + 5, y - 14);
	glVertex2i(x + 20, y + 6);
	glEnd();

	glColor4ub(201, 219, 220, 175);
	glBegin(GL_QUADS);
	glVertex2i(x - 5, y - 19);
	glVertex2i(x + 5, y - 19);
	glVertex2i(x + 5, y + 6);
	glVertex2i(x - 5, y + 6);
	glEnd();

	glColor4ub(201, 219, 220, 175);
	glBegin(GL_QUADS);
	glVertex2i(x - 20, y + 6);
	glVertex2i(x + 20, y + 6);
	glVertex2i(x + 20, y + 13);
	glVertex2i(x - 20, y + 13);
	glEnd();

	glDisable(GL_BLEND);
}

void Upgrade::Draw_Server(void)
{
	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(x - 60, y - 95);
	glVertex2i(x + 60, y - 95);
	glVertex2i(x + 60, y - 65);
	glVertex2i(x - 60, y - 65);
	glEnd();

	glColor3ub(31, 31, 31);
	glBegin(GL_QUADS);
	glVertex2d((double)x - 57.5, (double)y - 115);
	glVertex2d((double)x + 57.5, (double)y - 115);
	glVertex2i(x + 60, y - 95);
	glVertex2i(x - 60, y - 95);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(x - 60, y - 65);
	glVertex2i(x - 40, y - 65);
	glVertex2i(x - 40, y + 100);
	glVertex2i(x - 60, y + 100);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(x + 60, y - 65);
	glVertex2i(x + 40, y - 65);
	glVertex2i(x + 40, y + 100);
	glVertex2i(x + 60, y + 100);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(x - 60, y + 80);
	glVertex2i(x + 60, y + 80);
	glVertex2i(x + 60, y + 100);
	glVertex2i(x - 60, y + 100);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(x - 60, y + 25);
	glVertex2i(x + 60, y + 25);
	glVertex2i(x + 60, y + 45);
	glVertex2i(x - 60, y + 45);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(x - 60, y - 10);
	glVertex2i(x + 60, y - 10);
	glVertex2i(x + 60, y - 30);
	glVertex2i(x - 60, y - 30);
	glEnd();

	glColor3ub(169, 169, 169);
	glBegin(GL_QUADS);
	glVertex2i(x + 40, y + 80);
	glVertex2i(x - 40, y + 80);
	glVertex2i(x - 40, y + 45);
	glVertex2i(x + 40, y + 45);
	glEnd();

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			glColor3ub(0, 0, 0);
			DrawCircle(x - 35 + 5 * i, y + 50 + 5 * j, 2, 1);
		}
	}

	for (int i = 0; i < 3; i++)
	{
		glColor3ub(0, 0, 255);
		glBegin(GL_QUADS);
		glVertex2i(x - 5, y + 55 + 11 * i);
		glVertex2i(x + 15, y + 55 + 11 * i);
		glVertex2i(x + 15, y + 48 + 11 * i);
		glVertex2i(x - 5, y + 48 + 11 * i);
		glEnd();
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			glColor3ub(220 * i, 220 * (1 - i), 0);
			DrawCircle(x + 32 - 10 * i, y + 52 + 10 * j, 4, 1);
		}
	}

	glColor3ub(169, 169, 169);
	glBegin(GL_QUADS);
	glVertex2i(x + 40, y + 25);
	glVertex2i(x - 40, y + 25);
	glVertex2i(x - 40, y - 10);
	glVertex2i(x + 40, y - 10);
	glEnd();

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			glColor3ub(0, 0, 0);
			DrawCircle(x - 35 + 5 * i, y - 5 + 5 * j, 2, 1);
		}
	}

	for (int i = 0; i < 3; i++)
	{
		glColor3ub(0, 0, 255);
		glBegin(GL_QUADS);
		glVertex2i(x - 5, y + 11 * i);
		glVertex2i(x + 15, y + 11 * i);
		glVertex2i(x + 15, y - 7 + 11 * i);
		glVertex2i(x - 5, y - 7 + 11 * i);
		glEnd();
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			glColor3ub(220 * i, 220 * (1 - i), 0);
			DrawCircle(x + 32 - 10 * i, y - 3 + 10 * j, 4, 1);
		}
	}

	glColor3ub(169, 169, 169);
	glBegin(GL_QUADS);
	glVertex2i(x + 40, y - 30);
	glVertex2i(x - 40, y - 30);
	glVertex2i(x - 40, y - 65);
	glVertex2i(x + 40, y - 65);
	glEnd();

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			glColor3ub(0, 0, 0);
			DrawCircle(x - 35 + 5 * i, y - 60 + 5 * j, 2, 1);
		}
	}

	for (int i = 0; i < 3; i++)
	{
		glColor3ub(0, 0, 255);
		glBegin(GL_QUADS);
		glVertex2i(x - 5, y - 55 + 11 * i);
		glVertex2i(x + 15, y - 55 + 11 * i);
		glVertex2i(x + 15, y - 62 + 11 * i);
		glVertex2i(x - 5, y - 62 + 11 * i);
		glEnd();
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			glColor3ub(220 * i, 220 * (1 - i), 0);
			DrawCircle(x + 32 - 10 * i, y - 58 + 10 * j, 4, 1);
		}
	}
}

void Upgrade::Draw_Coffee(void)
{
	glColor3ub(139, 69, 19);
	glBegin(GL_POLYGON);
	glVertex2d((double)x - 57.5, (double)y);
	glVertex2d((double)x + 57.5, (double)y);
	glVertex2i(x + 60, y + 40);
	glVertex2i(x - 60, y + 40);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2d((double)x - 57.5, (double)y);
	glVertex2d((double)x + 57.5, (double)y);
	glVertex2i(x + 60, y + 40);
	glVertex2i(x - 60, y + 40);
	glEnd();

	glColor3ub(160, 82, 45);
	glBegin(GL_QUADS);
	glVertex2i(x - 60, y + 40);
	glVertex2i(x + 60, y + 40);
	glVertex2i(x + 60, y + 60);
	glVertex2i(x - 60, y + 60);
	glEnd();

	glColor3ub(160, 82, 45);
	glBegin(GL_QUADS);
	glVertex2i(x - 50, y + 60);
	glVertex2i(x - 30, y + 60);
	glVertex2i(x - 30, y + 100);
	glVertex2i(x - 50, y + 100);
	glEnd();

	glColor3ub(160, 82, 45);
	glBegin(GL_QUADS);
	glVertex2i(x + 50, y + 60);
	glVertex2i(x + 30, y + 60);
	glVertex2i(x + 30, y + 100);
	glVertex2i(x + 50, y + 100);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(x - 60, y + 60);
	glVertex2i(x + 60, y + 60);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(x - 50, y + 15);
	glVertex2i(x + 50, y + 15);
	glVertex2i(x + 50, y + 35);
	glVertex2i(x - 50, y + 35);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(x + 20, y - 75);
	glVertex2i(x + 50, y - 75);
	glVertex2i(x + 50, y + 15);
	glVertex2i(x + 20, y + 15);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(x - 50, y - 95);
	glVertex2i(x + 50, y - 95);
	glVertex2i(x + 50, y - 65);
	glVertex2i(x - 50, y - 65);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(x - 50, y - 75);
	glVertex2i(x + 20, y - 75);
	glVertex2i(x, y - 35);
	glVertex2i(x - 30, y - 35);
	glEnd();

	glColor3ub(31, 31, 31);
	glBegin(GL_QUADS);
	glVertex2d((double)x - 47.5, (double)y - 115);
	glVertex2d((double)x + 47.5, (double)y - 115);
	glVertex2i(x + 50, y - 95);
	glVertex2i(x - 50, y - 95);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(x - 70, y - 34);
	glVertex2i(x + 15, y - 34);
	glVertex2i(x + 15, y - 29);
	glVertex2i(x - 70, y - 29);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(x - 55, y - 29);
	glVertex2i(x - 50, y - 29);
	glVertex2i(x - 50, y + 5);
	glVertex2i(x - 55, y + 5);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(x - 70, y - 29);
	glVertex2i(x - 62, y - 29);
	glVertex2i(x - 62, y + 5);
	glVertex2i(x - 70, y + 5);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(x - 70, y);
	glVertex2i(x - 50, y);
	glVertex2i(x - 50, y + 5);
	glVertex2i(x - 70, y + 5);
	glEnd();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glColor4ub(201, 219, 220, 70);
	glBegin(GL_QUADS);
	glVertex2i(x - 50, y - 29);
	glVertex2i(x + 15, y - 29);
	glVertex2i(x + 15, y + 10);
	glVertex2i(x - 50, y + 10);
	glEnd();

	glColor4ub(201, 219, 220, 70);
	glBegin(GL_QUADS);
	glVertex2i(x - 46, y + 10);
	glVertex2i(x + 11, y + 10);
	glVertex2i(x + 11, y + 15);
	glVertex2i(x - 46, y + 15);
	glEnd();

	glDisable(GL_BLEND);
}




void Person::Draw_down_still(void)
{
	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x - 36, y + 22, 10, 1);

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x + 36, y + 22, 10, 1);

	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x - 32, y + 16);
	glVertex2d(x + 32, y + 16);
	glVertex2d(x + 32, y + 66);
	glVertex2d(x - 32, y + 66);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_QUADS);
	glVertex2d(x - 32, y + 66);
	glVertex2d(x + 32, y + 66);
	glVertex2d(x + 32, y + 80);
	glVertex2d(x - 32, y + 80);
	glEnd();

	glColor3ub(r_shirt, g_shirt, b_shirt);
	DrawCircle(x + 34, y + 34, 10, 1);

	glColor3ub(r_shirt, g_shirt, b_shirt);
	DrawCircle(x - 34, y + 34, 10, 1);

	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x - 44, y + 34);
	glVertex2d(x - 32, y + 34);
	glVertex2d(x - 32, y + 40);
	glVertex2d(x - 44, y + 40);
	glEnd();

	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x + 44, y + 34);
	glVertex2d(x + 32, y + 34);
	glVertex2d(x + 32, y + 40);
	glVertex2d(x + 44, y + 40);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	glBegin(GL_QUADS);
	glVertex2d(x - 44, y + 40);
	glVertex2d(x - 32, y + 40);
	glVertex2d(x - 32, y + 66);
	glVertex2d(x - 44, y + 66);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	glBegin(GL_QUADS);
	glVertex2d(x + 44, y + 40);
	glVertex2d(x + 32, y + 40);
	glVertex2d(x + 32, y + 66);
	glVertex2d(x + 44, y + 66);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x - 38, y + 66, 6, 1);

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x + 38, y + 66, 6, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x + 26, y + 96, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x + 16, y + 96, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x - 26, y + 96, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x - 16, y + 96, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	glBegin(GL_QUADS);
	glVertex2d(x - 26, y + 96);
	glVertex2d(x - 16, y + 96);
	glVertex2d(x - 16, y + 104);
	glVertex2d(x - 26, y + 104);
	glEnd();

	glColor3ub(r_shoes, g_shoes, b_shoes);
	glBegin(GL_QUADS);
	glVertex2d(x + 26, y + 96);
	glVertex2d(x + 16, y + 96);
	glVertex2d(x + 16, y + 104);
	glVertex2d(x + 26, y + 104);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_QUADS);
	glVertex2d(x - 32, y + 80);
	glVertex2d(x - 8, y + 80);
	glVertex2d(x - 8, y + 96);
	glVertex2d(x - 32, y + 96);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_QUADS);
	glVertex2d(x + 8, y + 80);
	glVertex2d(x + 32, y + 80);
	glVertex2d(x + 32, y + 96);
	glVertex2d(x + 8, y + 96);
	glEnd();

	glColor3ub(r_hair, g_hair, b_hair);
	DrawCircle(x, y, 40, 1);

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x, y + 6, 36, 1);

	glColor3ub(255, 255, 255);
	DrawCircle(x + 16, y + 5, 7, 1);

	glColor3ub(255, 255, 255);
	DrawCircle(x - 16, y + 5, 7, 1);

	glColor3ub(r_eyes, g_eyes, b_eyes);
	DrawCircle(x + 14, y + 5, 4, 1);

	glColor3ub(r_eyes, g_eyes, b_eyes);
	DrawCircle(x - 14, y + 5, 4, 1);

	glColor3ub(0, 0, 0);
	DrawCircle(x + 14, y + 5, 2, 1);

	glColor3ub(0, 0, 0);
	DrawCircle(x - 14, y + 5, 2, 1);

	glColor3ub(201, 130, 118);
	glBegin(GL_QUADS);
	glVertex2d(x + 10, y + 24);
	glVertex2d(x - 10, y + 24);
	glVertex2d(x - 10, y + 32);
	glVertex2d(x + 10, y + 32);
	glEnd();
}

void Person::Draw_down_left(void)
{
	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x - 36, y + 22, 10, 1);

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x + 36, y + 22, 10, 1);

	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x - 32, y + 16);
	glVertex2d(x + 32, y + 16);
	glVertex2d(x + 32, y + 66);
	glVertex2d(x - 32, y + 66);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_QUADS);
	glVertex2d(x - 32, y + 66);
	glVertex2d(x + 32, y + 66);
	glVertex2d(x + 32, y + 80);
	glVertex2d(x - 32, y + 80);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x - 38, y + 42, 6, 1);

	glColor3ub(r_shirt, g_shirt, b_shirt);
	DrawCircle(x + 34, y + 34, 10, 1);

	glColor3ub(r_shirt, g_shirt, b_shirt);
	DrawCircle(x - 34, y + 34, 10, 1);

	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x - 44, y + 34);
	glVertex2d(x - 32, y + 34);
	glVertex2d(x - 32, y + 40);
	glVertex2d(x - 44, y + 40);
	glEnd();

	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x + 44, y + 34);
	glVertex2d(x + 32, y + 34);
	glVertex2d(x + 32, y + 40);
	glVertex2d(x + 44, y + 40);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	glBegin(GL_QUADS);
	glVertex2d(x + 44, y + 36);
	glVertex2d(x + 32, y + 36);
	glVertex2d(x + 32, y + 56);
	glVertex2d(x + 44, y + 56);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x + 38, y + 56, 6, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x - 26, y + 96, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x - 16, y + 93, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	glBegin(GL_POLYGON);
	glVertex2d(x - 26, y + 93);
	glVertex2d(x - 16, y + 101);
	glVertex2d(x - 16, y + 101);
	glVertex2d(x - 26, y + 104);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_POLYGON);
	glVertex2d(x - 32, y + 80);
	glVertex2d(x - 8, y + 80);
	glVertex2d(x - 8, y + 93);
	glVertex2d(x - 32, y + 99);
	glEnd();

	glColor3ub(r_hair, g_hair, b_hair);
	DrawCircle(x, y, 40, 1);

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x, y + 6, 36, 1);

	glColor3ub(255, 255, 255);
	DrawCircle(x + 16, y + 5, 7, 1);

	glColor3ub(255, 255, 255);
	DrawCircle(x - 16, y + 5, 7, 1);

	glColor3ub(r_eyes, g_eyes, b_eyes);
	DrawCircle(x + 14, y + 5, 4, 1);

	glColor3ub(r_eyes, g_eyes, b_eyes);
	DrawCircle(x - 14, y + 5, 4, 1);

	glColor3ub(0, 0, 0);
	DrawCircle(x + 14, y + 5, 2, 1);

	glColor3ub(0, 0, 0);
	DrawCircle(x - 14, y + 5, 2, 1);

	glColor3ub(201, 130, 118);
	glBegin(GL_QUADS);
	glVertex2d(x + 10, y + 24);
	glVertex2d(x - 10, y + 24);
	glVertex2d(x - 10, y + 32);
	glVertex2d(x + 10, y + 32);
	glEnd();
}

void Person::Draw_down_right(void)
{
	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x - 36, y + 22, 10, 1);

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x + 36, y + 22, 10, 1);

	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x - 32, y + 16);
	glVertex2d(x + 32, y + 16);
	glVertex2d(x + 32, y + 66);
	glVertex2d(x - 32, y + 66);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_QUADS);
	glVertex2d(x - 32, y + 66);
	glVertex2d(x + 32, y + 66);
	glVertex2d(x + 32, y + 80);
	glVertex2d(x - 32, y + 80);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x + 38, y + 42, 6, 1);

	glColor3ub(r_shirt, g_shirt, b_shirt);
	DrawCircle(x + 34, y + 34, 10, 1);

	glColor3ub(r_shirt, g_shirt, b_shirt);
	DrawCircle(x - 34, y + 34, 10, 1);

	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x - 44, y + 34);
	glVertex2d(x - 32, y + 34);
	glVertex2d(x - 32, y + 40);
	glVertex2d(x - 44, y + 40);
	glEnd();

	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x + 44, y + 34);
	glVertex2d(x + 32, y + 34);
	glVertex2d(x + 32, y + 40);
	glVertex2d(x + 44, y + 40);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	glBegin(GL_QUADS);
	glVertex2d(x - 44, y + 36);
	glVertex2d(x - 32, y + 36);
	glVertex2d(x - 32, y + 56);
	glVertex2d(x - 44, y + 56);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x - 38, y + 56, 6, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x + 26, y + 96, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x + 16, y + 93, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	glBegin(GL_POLYGON);
	glVertex2d(x + 26, y + 93);
	glVertex2d(x + 16, y + 101);
	glVertex2d(x + 16, y + 101);
	glVertex2d(x + 26, y + 104);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_POLYGON);
	glVertex2d(x + 32, y + 80);
	glVertex2d(x + 8, y + 80);
	glVertex2d(x + 8, y + 93);
	glVertex2d(x + 32, y + 99);
	glEnd();

	glColor3ub(r_hair, g_hair, b_hair);
	DrawCircle(x, y, 40, 1);

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x, y + 6, 36, 1);

	glColor3ub(255, 255, 255);
	DrawCircle(x + 16, y + 5, 7, 1);

	glColor3ub(255, 255, 255);
	DrawCircle(x - 16, y + 5, 7, 1);

	glColor3ub(r_eyes, g_eyes, b_eyes);
	DrawCircle(x + 14, y + 5, 4, 1);

	glColor3ub(r_eyes, g_eyes, b_eyes);
	DrawCircle(x - 14, y + 5, 4, 1);

	glColor3ub(0, 0, 0);
	DrawCircle(x + 14, y + 5, 2, 1);

	glColor3ub(0, 0, 0);
	DrawCircle(x - 14, y + 5, 2, 1);

	glColor3ub(201, 130, 118);
	glBegin(GL_QUADS);
	glVertex2d(x + 10, y + 24);
	glVertex2d(x - 10, y + 24);
	glVertex2d(x - 10, y + 32);
	glVertex2d(x + 10, y + 32);
	glEnd();
}

void Person::Draw_left_still(void)
{
	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x - 12, y + 16);
	glVertex2d(x + 12, y + 16);
	glVertex2d(x + 12, y + 66);
	glVertex2d(x - 12, y + 66);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_QUADS);
	glVertex2d(x - 12, y + 66);
	glVertex2d(x + 12, y + 66);
	glVertex2d(x + 12, y + 80);
	glVertex2d(x - 12, y + 80);
	glEnd();

	glColor3ub(r_hair, g_hair, b_hair);
	DrawCircle(x, y, 40, 1);

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x - 5, y + 7, 35, 1);

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x + 26, y + 16, 10, 1);

	glColor3ub(255, 255, 255);
	DrawCircle(x - 8, y + 5, 7, 1);

	glColor3ub(r_eyes, g_eyes, b_eyes);
	DrawCircle(x - 10, y + 5, 4, 1);

	glColor3ub(0, 0, 0);
	DrawCircle(x - 10, y + 5, 2, 1);

	glColor3ub(201, 130, 118);
	glBegin(GL_POLYGON);
	glVertex2d(x - 16, y + 24);
	glVertex2d(x - 36, y + 24);
	glVertex2d(x - 30, y + 32);
	glVertex2d(x - 16, y + 32);
	glEnd();

	glColor3ub(r_shirt, g_shirt, b_shirt);
	DrawCircle(x, y + 34, 10, 1);

	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x - 6, y + 34);
	glVertex2d(x + 6, y + 34);
	glVertex2d(x + 6, y + 40);
	glVertex2d(x - 6, y + 40);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	glBegin(GL_QUADS);
	glVertex2d(x - 6, y + 40);
	glVertex2d(x + 6, y + 40);
	glVertex2d(x + 6, y + 66);
	glVertex2d(x - 6, y + 66);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x, y + 66, 6, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x + 5, y + 96, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x - 5, y + 96, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	glBegin(GL_QUADS);
	glVertex2d(x - 5, y + 96);
	glVertex2d(x + 5, y + 96);
	glVertex2d(x + 5, y + 104);
	glVertex2d(x - 5, y + 104);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_QUADS);
	glVertex2d(x - 12, y + 80);
	glVertex2d(x + 12, y + 80);
	glVertex2d(x + 12, y + 96);
	glVertex2d(x - 12, y + 96);
	glEnd();
}

void Person::Draw_left_left(void)
{
	glColor3ub(r_skin, g_skin, b_skin);
	glBegin(GL_POLYGON);
	glVertex2d((double)x - 2.2, y + 44);
	glVertex2d((double)x + 8.2, y + 38);
	glVertex2d((double)x + 21.2, (double)y + 60.52);
	glVertex2d((double)x + 10.8, (double)y + 66.52);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x + 16, y + 63.52, 6, 1);

	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x - 12, y + 16);
	glVertex2d(x + 12, y + 16);
	glVertex2d(x + 12, y + 66);
	glVertex2d(x - 12, y + 66);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_QUADS);
	glVertex2d(x - 12, y + 66);
	glVertex2d(x + 12, y + 66);
	glVertex2d(x + 12, y + 80);
	glVertex2d(x - 12, y + 80);
	glEnd();

	glColor3ub(r_hair, g_hair, b_hair);
	DrawCircle(x, y, 40, 1);

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x - 5, y + 7, 35, 1);

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x + 26, y + 16, 10, 1);

	glColor3ub(255, 255, 255);
	DrawCircle(x - 8, y + 5, 7, 1);

	glColor3ub(r_eyes, g_eyes, b_eyes);
	DrawCircle(x - 10, y + 5, 4, 1);

	glColor3ub(0, 0, 0);
	DrawCircle(x - 10, y + 5, 2, 1);

	glColor3ub(201, 130, 118);
	glBegin(GL_POLYGON);
	glVertex2d(x - 16, y + 24);
	glVertex2d(x - 36, y + 24);
	glVertex2d(x - 30, y + 32);
	glVertex2d(x - 16, y + 32);
	glEnd();

	glColor3ub(r_shirt, g_shirt, b_shirt);
	DrawCircle(x, y + 34, 10, 1);

	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x - 6, y + 34);
	glVertex2d(x + 6, y + 34);
	glVertex2d(x + 6, y + 40);
	glVertex2d(x - 6, y + 40);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	glBegin(GL_POLYGON);
	glVertex2d((double)x + 2.2, y + 44);
	glVertex2d((double)x - 8.2, y + 38);
	glVertex2d((double)x - 21.2, (double)y + 60.52);
	glVertex2d((double)x - 10.8, (double)y + 66.52);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x - 16, y + 63.52, 6, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x + 13.07, y + 97.86, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x + 6.15, y + 100.86, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	glBegin(GL_POLYGON);
	glVertex2d((double)x + 6.15, (double)y + 100.86);
	glVertex2d((double)x + 13.07, (double)y + 97.86);
	glVertex2d((double)x + 17.07, (double)y + 104.79);
	glVertex2d((double)x + 10.15, (double)y + 107.79);
	glEnd();

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x - 13.07, y + 97.86, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x - 6.15, y + 100.86, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	glBegin(GL_POLYGON);
	glVertex2d((double)x - 6.15, (double)y + 100.86);
	glVertex2d((double)x - 13.07, (double)y + 97.86);
	glVertex2d((double)x - 17.07, (double)y + 104.79);
	glVertex2d((double)x - 10.15, (double)y + 107.79);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_QUADS);
	glVertex2d(x - 12, y + 80);
	glVertex2d(x + 12, y + 80);
	glVertex2d(x + 12, y + 88);
	glVertex2d(x - 12, y + 88);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_POLYGON);
	glVertex2d((double)x - 8.78, (double)y + 92);
	glVertex2d((double)x + 12, (double)y + 80);
	glVertex2d((double)x + 20, (double)y + 93.86);
	glVertex2d((double)x - .78, (double)y + 104.86);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_POLYGON);
	glVertex2d((double)x + 8.78, (double)y + 92);
	glVertex2d((double)x - 12, (double)y + 80);
	glVertex2d((double)x - 20, (double)y + 93.86);
	glVertex2d((double)x + .78, (double)y + 104.86);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2d((double)x - 12, (double)y + 80);
	glVertex2d((double)x - .78, (double)y + 104.86);
	glEnd();
}

void Person::Draw_left_right(void)
{
	glColor3ub(r_skin, g_skin, b_skin);
	glBegin(GL_POLYGON);
	glVertex2d((double)x + 2.2, y + 44);
	glVertex2d((double)x - 8.2, y + 38);
	glVertex2d((double)x - 21.2, (double)y + 60.52);
	glVertex2d((double)x - 10.8, (double)y + 66.52);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x - 16, y + 63.52, 6, 1);

	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x - 12, y + 16);
	glVertex2d(x + 12, y + 16);
	glVertex2d(x + 12, y + 66);
	glVertex2d(x - 12, y + 66);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_QUADS);
	glVertex2d(x - 12, y + 66);
	glVertex2d(x + 12, y + 66);
	glVertex2d(x + 12, y + 80);
	glVertex2d(x - 12, y + 80);
	glEnd();

	glColor3ub(r_hair, g_hair, b_hair);
	DrawCircle(x, y, 40, 1);

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x - 5, y + 7, 35, 1);

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x + 26, y + 16, 10, 1);

	glColor3ub(255, 255, 255);
	DrawCircle(x - 8, y + 5, 7, 1);

	glColor3ub(r_eyes, g_eyes, b_eyes);
	DrawCircle(x - 10, y + 5, 4, 1);

	glColor3ub(0, 0, 0);
	DrawCircle(x - 10, y + 5, 2, 1);

	glColor3ub(201, 130, 118);
	glBegin(GL_POLYGON);
	glVertex2d(x - 16, y + 24);
	glVertex2d(x - 36, y + 24);
	glVertex2d(x - 30, y + 32);
	glVertex2d(x - 16, y + 32);
	glEnd();

	glColor3ub(r_shirt, g_shirt, b_shirt);
	DrawCircle(x, y + 34, 10, 1);

	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x - 6, y + 34);
	glVertex2d(x + 6, y + 34);
	glVertex2d(x + 6, y + 40);
	glVertex2d(x - 6, y + 40);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	glBegin(GL_POLYGON);
	glVertex2d((double)x - 2.2, y + 44);
	glVertex2d((double)x + 8.2, y + 38);
	glVertex2d((double)x + 21.2, (double)y + 60.52);
	glVertex2d((double)x + 10.8, (double)y + 66.52);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x + 16, y + 63.52, 6, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x + 13.07, y + 97.86, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x + 6.15, y + 100.86, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	glBegin(GL_POLYGON);
	glVertex2d((double)x + 6.15, (double)y + 100.86);
	glVertex2d((double)x + 13.07, (double)y + 97.86);
	glVertex2d((double)x + 17.07, (double)y + 104.79);
	glVertex2d((double)x + 10.15, (double)y + 107.79);
	glEnd();

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x - 13.07, y + 97.86, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x - 6.15, y + 100.86, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	glBegin(GL_POLYGON);
	glVertex2d((double)x - 6.15, (double)y + 100.86);
	glVertex2d((double)x - 13.07, (double)y + 97.86);
	glVertex2d((double)x - 17.07, (double)y + 104.79);
	glVertex2d((double)x - 10.15, (double)y + 107.79);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_QUADS);
	glVertex2d(x - 12, y + 80);
	glVertex2d(x + 12, y + 80);
	glVertex2d(x + 12, y + 88);
	glVertex2d(x - 12, y + 88);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_POLYGON);
	glVertex2d((double)x - 8.78, (double)y + 92);
	glVertex2d((double)x + 12, (double)y + 80);
	glVertex2d((double)x + 20, (double)y + 93.86);
	glVertex2d((double)x - .78, (double)y + 104.86);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_POLYGON);
	glVertex2d((double)x + 8.78, (double)y + 92);
	glVertex2d((double)x - 12, (double)y + 80);
	glVertex2d((double)x - 20, (double)y + 93.86);
	glVertex2d((double)x + .78, (double)y + 104.86);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2d((double)x + 12, (double)y + 80);
	glVertex2d((double)x + .78, (double)y + 104.86);
	glEnd();
}

void Person::Draw_right_still(void)
{
	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x - 12, y + 16);
	glVertex2d(x + 12, y + 16);
	glVertex2d(x + 12, y + 66);
	glVertex2d(x - 12, y + 66);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_QUADS);
	glVertex2d(x - 12, y + 66);
	glVertex2d(x + 12, y + 66);
	glVertex2d(x + 12, y + 80);
	glVertex2d(x - 12, y + 80);
	glEnd();

	glColor3ub(r_hair, g_hair, b_hair);
	DrawCircle(x, y, 40, 1);

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x + 5, y + 7, 35, 1);

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x - 26, y + 16, 10, 1);

	glColor3ub(255, 255, 255);
	DrawCircle(x + 8, y + 5, 7, 1);

	glColor3ub(r_eyes, g_eyes, b_eyes);
	DrawCircle(x + 10, y + 5, 4, 1);

	glColor3ub(0, 0, 0);
	DrawCircle(x + 10, y + 5, 2, 1);

	glColor3ub(201, 130, 118);
	glBegin(GL_POLYGON);
	glVertex2d(x + 16, y + 24);
	glVertex2d(x + 36, y + 24);
	glVertex2d(x + 30, y + 32);
	glVertex2d(x + 16, y + 32);
	glEnd();

	glColor3ub(r_shirt, g_shirt, b_shirt);
	DrawCircle(x, y + 34, 10, 1);

	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x - 6, y + 34);
	glVertex2d(x + 6, y + 34);
	glVertex2d(x + 6, y + 40);
	glVertex2d(x - 6, y + 40);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	glBegin(GL_QUADS);
	glVertex2d(x - 6, y + 40);
	glVertex2d(x + 6, y + 40);
	glVertex2d(x + 6, y + 66);
	glVertex2d(x - 6, y + 66);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x, y + 66, 6, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x + 5, y + 96, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x - 5, y + 96, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	glBegin(GL_QUADS);
	glVertex2d(x - 5, y + 96);
	glVertex2d(x + 5, y + 96);
	glVertex2d(x + 5, y + 104);
	glVertex2d(x - 5, y + 104);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_QUADS);
	glVertex2d(x - 12, y + 80);
	glVertex2d(x + 12, y + 80);
	glVertex2d(x + 12, y + 96);
	glVertex2d(x - 12, y + 96);
	glEnd();
}

void Person::Draw_right_left(void)
{
	glColor3ub(r_skin, g_skin, b_skin);
	glBegin(GL_POLYGON);
	glVertex2d((double)x - 2.2, y + 44);
	glVertex2d((double)x + 8.2, y + 38);
	glVertex2d((double)x + 21.2, (double)y + 60.52);
	glVertex2d((double)x + 10.8, (double)y + 66.52);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x + 16, y + 63.52, 6, 1);

	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x - 12, y + 16);
	glVertex2d(x + 12, y + 16);
	glVertex2d(x + 12, y + 66);
	glVertex2d(x - 12, y + 66);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_QUADS);
	glVertex2d(x - 12, y + 66);
	glVertex2d(x + 12, y + 66);
	glVertex2d(x + 12, y + 80);
	glVertex2d(x - 12, y + 80);
	glEnd();

	glColor3ub(r_hair, g_hair, b_hair);
	DrawCircle(x, y, 40, 1);

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x + 5, y + 7, 35, 1);

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x - 26, y + 16, 10, 1);

	glColor3ub(255, 255, 255);
	DrawCircle(x + 8, y + 5, 7, 1);

	glColor3ub(r_eyes, g_eyes, b_eyes);
	DrawCircle(x + 10, y + 5, 4, 1);

	glColor3ub(0, 0, 0);
	DrawCircle(x + 10, y + 5, 2, 1);

	glColor3ub(201, 130, 118);
	glBegin(GL_POLYGON);
	glVertex2d(x + 16, y + 24);
	glVertex2d(x + 36, y + 24);
	glVertex2d(x + 30, y + 32);
	glVertex2d(x + 16, y + 32);
	glEnd();

	glColor3ub(r_shirt, g_shirt, b_shirt);
	DrawCircle(x, y + 34, 10, 1);

	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x - 6, y + 34);
	glVertex2d(x + 6, y + 34);
	glVertex2d(x + 6, y + 40);
	glVertex2d(x - 6, y + 40);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	glBegin(GL_POLYGON);
	glVertex2d((double)x + 2.2, y + 44);
	glVertex2d((double)x - 8.2, y + 38);
	glVertex2d((double)x - 21.2, (double)y + 60.52);
	glVertex2d((double)x - 10.8, (double)y + 66.52);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x - 16, y + 63.52, 6, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x + 13.07, y + 97.86, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x + 6.15, y + 100.86, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	glBegin(GL_POLYGON);
	glVertex2d((double)x + 6.15, (double)y + 100.86);
	glVertex2d((double)x + 13.07, (double)y + 97.86);
	glVertex2d((double)x + 17.07, (double)y + 104.79);
	glVertex2d((double)x + 10.15, (double)y + 107.79);
	glEnd();

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x - 13.07, y + 97.86, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x - 6.15, y + 100.86, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	glBegin(GL_POLYGON);
	glVertex2d((double)x - 6.15, (double)y + 100.86);
	glVertex2d((double)x - 13.07, (double)y + 97.86);
	glVertex2d((double)x - 17.07, (double)y + 104.79);
	glVertex2d((double)x - 10.15, (double)y + 107.79);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_QUADS);
	glVertex2d(x - 12, y + 80);
	glVertex2d(x + 12, y + 80);
	glVertex2d(x + 12, y + 88);
	glVertex2d(x - 12, y + 88);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_POLYGON);
	glVertex2d((double)x - 8.78, (double)y + 92);
	glVertex2d((double)x + 12, (double)y + 80);
	glVertex2d((double)x + 20, (double)y + 93.86);
	glVertex2d((double)x - .78, (double)y + 104.86);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_POLYGON);
	glVertex2d((double)x + 8.78, (double)y + 92);
	glVertex2d((double)x - 12, (double)y + 80);
	glVertex2d((double)x - 20, (double)y + 93.86);
	glVertex2d((double)x + .78, (double)y + 104.86);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2d((double)x - 12, (double)y + 80);
	glVertex2d((double)x + .78, (double)y + 104.86);
	glEnd();
}

void Person::Draw_right_right(void)
{
	glColor3ub(r_skin, g_skin, b_skin);
	glBegin(GL_POLYGON);
	glVertex2d((double)x + 2.2, y + 44);
	glVertex2d((double)x - 8.2, y + 38);
	glVertex2d((double)x - 21.2, (double)y + 60.52);
	glVertex2d((double)x - 10.8, (double)y + 66.52);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x - 16, y + 63.52, 6, 1);

	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x - 12, y + 16);
	glVertex2d(x + 12, y + 16);
	glVertex2d(x + 12, y + 66);
	glVertex2d(x - 12, y + 66);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_QUADS);
	glVertex2d(x - 12, y + 66);
	glVertex2d(x + 12, y + 66);
	glVertex2d(x + 12, y + 80);
	glVertex2d(x - 12, y + 80);
	glEnd();

	glColor3ub(r_hair, g_hair, b_hair);
	DrawCircle(x, y, 40, 1);

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x + 5, y + 7, 35, 1);

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x - 26, y + 16, 10, 1);

	glColor3ub(255, 255, 255);
	DrawCircle(x + 8, y + 5, 7, 1);

	glColor3ub(r_eyes, g_eyes, b_eyes);
	DrawCircle(x + 10, y + 5, 4, 1);

	glColor3ub(0, 0, 0);
	DrawCircle(x + 10, y + 5, 2, 1);

	glColor3ub(201, 130, 118);
	glBegin(GL_POLYGON);
	glVertex2d(x + 16, y + 24);
	glVertex2d(x + 36, y + 24);
	glVertex2d(x + 30, y + 32);
	glVertex2d(x + 16, y + 32);
	glEnd();

	glColor3ub(r_shirt, g_shirt, b_shirt);
	DrawCircle(x, y + 34, 10, 1);

	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x - 6, y + 34);
	glVertex2d(x + 6, y + 34);
	glVertex2d(x + 6, y + 40);
	glVertex2d(x - 6, y + 40);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	glBegin(GL_POLYGON);
	glVertex2d((double)x - 2.2, y + 44);
	glVertex2d((double)x + 8.2, y + 38);
	glVertex2d((double)x + 21.2, (double)y + 60.52);
	glVertex2d((double)x + 10.8, (double)y + 66.52);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x + 16, y + 63.52, 6, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x + 13.07, y + 97.86, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x + 6.15, y + 100.86, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	glBegin(GL_POLYGON);
	glVertex2d((double)x + 6.15, (double)y + 100.86);
	glVertex2d((double)x + 13.07, (double)y + 97.86);
	glVertex2d((double)x + 17.07, (double)y + 104.79);
	glVertex2d((double)x + 10.15, (double)y + 107.79);
	glEnd();

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x - 13.07, y + 97.86, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x - 6.15, y + 100.86, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	glBegin(GL_POLYGON);
	glVertex2d((double)x - 6.15, (double)y + 100.86);
	glVertex2d((double)x - 13.07, (double)y + 97.86);
	glVertex2d((double)x - 17.07, (double)y + 104.79);
	glVertex2d((double)x - 10.15, (double)y + 107.79);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_QUADS);
	glVertex2d(x - 12, y + 80);
	glVertex2d(x + 12, y + 80);
	glVertex2d(x + 12, y + 88);
	glVertex2d(x - 12, y + 88);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_POLYGON);
	glVertex2d((double)x - 8.78, (double)y + 92);
	glVertex2d((double)x + 12, (double)y + 80);
	glVertex2d((double)x + 20, (double)y + 93.86);
	glVertex2d((double)x - .78, (double)y + 104.86);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_POLYGON);
	glVertex2d((double)x + 8.78, (double)y + 92);
	glVertex2d((double)x - 12, (double)y + 80);
	glVertex2d((double)x - 20, (double)y + 93.86);
	glVertex2d((double)x + .78, (double)y + 104.86);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2d((double)x + 12, (double)y + 80);
	glVertex2d((double)x - .78, (double)y + 104.86);
	glEnd();
}

void Person::Draw(void)
{
	switch (state_walking)
	{
	case 0:
		Draw_up_still();
		break;
	case 1:
		Draw_up_walk_right();
		break;
	case 2:
		Draw_up_walk_left();
		break;
	case 3:
		Draw_down_still();
		break;
	case 4:
		Draw_down_right();
		break;
	case 5:
		Draw_down_left();
		break;
	case 6:
		Draw_left_still();
		break;
	case 7:
		Draw_left_right();
		break;
	case 8:
		Draw_left_left();
		break;
	case 9:
		Draw_right_still();
		break;
	case 10:
		Draw_right_right();
		break;
	case 11:
		Draw_right_left();
		break;
	}
}

void Person::Draw_up_walk_right(void)
{
	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x - 32, y + 16);
	glVertex2d(x + 32, y + 16);
	glVertex2d(x + 32, y + 66);
	glVertex2d(x - 32, y + 66);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_QUADS);
	glVertex2d(x - 32, y + 66);
	glVertex2d(x + 32, y + 66);
	glVertex2d(x + 32, y + 80);
	glVertex2d(x - 32, y + 80);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x + 38, y + 42, 6, 1);

	glColor3ub(r_shirt, g_shirt, b_shirt);
	DrawCircle(x + 34, y + 34, 10, 1);

	glColor3ub(r_shirt, g_shirt, b_shirt);
	DrawCircle(x - 34, y + 34, 10, 1);

	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x - 44, y + 34);
	glVertex2d(x - 32, y + 34);
	glVertex2d(x - 32, y + 40);
	glVertex2d(x - 44, y + 40);
	glEnd();

	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x + 44, y + 34);
	glVertex2d(x + 32, y + 34);
	glVertex2d(x + 32, y + 40);
	glVertex2d(x + 44, y + 40);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	glBegin(GL_QUADS);
	glVertex2d(x - 44, y + 36);
	glVertex2d(x - 32, y + 36);
	glVertex2d(x - 32, y + 56);
	glVertex2d(x - 44, y + 56);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x - 38, y + 56, 6, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x + 26, y + 93, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x + 16, y + 96, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	glBegin(GL_POLYGON);
	glVertex2d(x + 26, y + 93);
	glVertex2d(x + 16, y + 101);
	glVertex2d(x + 16, y + 104);
	glVertex2d(x + 26, y + 101);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_POLYGON);
	glVertex2d(x + 32, y + 80);
	glVertex2d(x + 8, y + 80);
	glVertex2d(x + 8, y + 99);
	glVertex2d(x + 32, y + 93);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x - 36, y + 22, 10, 1);

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x + 36, y + 22, 10, 1);

	glColor3ub(r_hair, g_hair, b_hair);
	DrawCircle(x, y, 40, 1);
}

void Person::Draw_up_walk_left(void)
{
	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x - 32, y + 16);
	glVertex2d(x + 32, y + 16);
	glVertex2d(x + 32, y + 66);
	glVertex2d(x - 32, y + 66);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_QUADS);
	glVertex2d(x - 32, y + 66);
	glVertex2d(x + 32, y + 66);
	glVertex2d(x + 32, y + 80);
	glVertex2d(x - 32, y + 80);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x - 38, y + 42, 6, 1);

	glColor3ub(r_shirt, g_shirt, b_shirt);
	DrawCircle(x + 34, y + 34, 10, 1);

	glColor3ub(r_shirt, g_shirt, b_shirt);
	DrawCircle(x - 34, y + 34, 10, 1);

	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x - 44, y + 34);
	glVertex2d(x - 32, y + 34);
	glVertex2d(x - 32, y + 40);
	glVertex2d(x - 44, y + 40);
	glEnd();

	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x + 44, y + 34);
	glVertex2d(x + 32, y + 34);
	glVertex2d(x + 32, y + 40);
	glVertex2d(x + 44, y + 40);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	glBegin(GL_QUADS);
	glVertex2d(x + 44, y + 36);
	glVertex2d(x + 32, y + 36);
	glVertex2d(x + 32, y + 56);
	glVertex2d(x + 44, y + 56);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x + 38, y + 56, 6, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x - 26, y + 93, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x - 16, y + 96, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	glBegin(GL_POLYGON);
	glVertex2d(x - 26, y + 93);
	glVertex2d(x - 16, y + 101);
	glVertex2d(x - 16, y + 104);
	glVertex2d(x - 26, y + 101);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_POLYGON);
	glVertex2d(x - 32, y + 80);
	glVertex2d(x - 8, y + 80);
	glVertex2d(x - 8, y + 99);
	glVertex2d(x - 32, y + 93);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x - 36, y + 22, 10, 1);

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x + 36, y + 22, 10, 1);

	glColor3ub(r_hair, g_hair, b_hair);
	DrawCircle(x, y, 40, 1);
}

void Person::Draw_up_still(void)
{
	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x - 32, y + 16);
	glVertex2d(x + 32, y + 16);
	glVertex2d(x + 32, y + 66);
	glVertex2d(x - 32, y + 66);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_QUADS);
	glVertex2d(x - 32, y + 66);
	glVertex2d(x + 32, y + 66);
	glVertex2d(x + 32, y + 80);
	glVertex2d(x - 32, y + 80);
	glEnd();

	glColor3ub(r_shirt, g_shirt, b_shirt);
	DrawCircle(x + 34, y + 34, 10, 1);

	glColor3ub(r_shirt, g_shirt, b_shirt);
	DrawCircle(x - 34, y + 34, 10, 1);

	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x - 44, y + 34);
	glVertex2d(x - 32, y + 34);
	glVertex2d(x - 32, y + 40);
	glVertex2d(x - 44, y + 40);
	glEnd();

	glColor3ub(r_shirt, g_shirt, b_shirt);
	glBegin(GL_QUADS);
	glVertex2d(x + 44, y + 34);
	glVertex2d(x + 32, y + 34);
	glVertex2d(x + 32, y + 40);
	glVertex2d(x + 44, y + 40);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	glBegin(GL_QUADS);
	glVertex2d(x - 44, y + 40);
	glVertex2d(x - 32, y + 40);
	glVertex2d(x - 32, y + 66);
	glVertex2d(x - 44, y + 66);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	glBegin(GL_QUADS);
	glVertex2d(x + 44, y + 40);
	glVertex2d(x + 32, y + 40);
	glVertex2d(x + 32, y + 66);
	glVertex2d(x + 44, y + 66);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x - 38, y + 66, 6, 1);

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x + 38, y + 66, 6, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x + 26, y + 96, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x + 16, y + 96, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x - 26, y + 96, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	DrawCircle(x - 16, y + 96, 8, 1);

	glColor3ub(r_shoes, g_shoes, b_shoes);
	glBegin(GL_QUADS);
	glVertex2d(x - 26, y + 96);
	glVertex2d(x - 16, y + 96);
	glVertex2d(x - 16, y + 104);
	glVertex2d(x - 26, y + 104);
	glEnd();

	glColor3ub(r_shoes, g_shoes, b_shoes);
	glBegin(GL_QUADS);
	glVertex2d(x + 26, y + 96);
	glVertex2d(x + 16, y + 96);
	glVertex2d(x + 16, y + 104);
	glVertex2d(x + 26, y + 104);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_QUADS);
	glVertex2d(x - 32, y + 80);
	glVertex2d(x - 8, y + 80);
	glVertex2d(x - 8, y + 96);
	glVertex2d(x - 32, y + 96);
	glEnd();

	glColor3ub(r_pants, g_pants, b_pants);
	glBegin(GL_QUADS);
	glVertex2d(x + 8, y + 80);
	glVertex2d(x + 32, y + 80);
	glVertex2d(x + 32, y + 96);
	glVertex2d(x + 8, y + 96);
	glEnd();

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x - 36, y + 22, 10, 1);

	glColor3ub(r_skin, g_skin, b_skin);
	DrawCircle(x + 36, y + 22, 10, 1);

	glColor3ub(r_hair, g_hair, b_hair);
	DrawCircle(x, y, 40, 1);
}




void Desk::Draw(void)
{
	glColor3ub(139, 69, 19);
	glBegin(GL_POLYGON);
	glVertex2i(x - 85, y - 40);
	glVertex2i(x + 85, y - 40);
	glVertex2i(x + 90, y + 40);
	glVertex2i(x - 90, y + 40);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x - 85, y - 40);
	glVertex2i(x + 85, y - 40);
	glVertex2i(x + 90, y + 40);
	glVertex2i(x - 90, y + 40);
	glEnd();

	glColor3ub(160, 82, 45);
	glBegin(GL_QUADS);
	glVertex2i(x - 90, y + 40);
	glVertex2i(x + 90, y + 40);
	glVertex2i(x + 90, y + 60);
	glVertex2i(x - 90, y + 60);
	glEnd();

	glColor3ub(160, 82, 45);
	glBegin(GL_QUADS);
	glVertex2i(x - 80, y + 60);
	glVertex2i(x - 60, y + 60);
	glVertex2i(x - 60, y + 100);
	glVertex2i(x - 80, y + 100);
	glEnd();

	glColor3ub(160, 82, 45);
	glBegin(GL_QUADS);
	glVertex2i(x + 80, y + 60);
	glVertex2i(x + 60, y + 60);
	glVertex2i(x + 60, y + 100);
	glVertex2i(x + 80, y + 100);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(x - 90, y + 60);
	glVertex2i(x + 90, y + 60);
	glEnd();
}



void Computer::Draw(void)
{
	glColor3ub(105, 105, 105);
	glBegin(GL_POLYGON);
	glVertex2i(x - 42, y - 35);
	glVertex2i(x + 42, y - 35);
	glVertex2i(x + 45, y - 30);
	glVertex2i(x - 45, y - 30);
	glEnd();

	glColor3ub(105, 105, 105);
	glBegin(GL_POLYGON);
	glVertex2d((double)x - 43.75, (double)y + 40);
	glVertex2d((double)x + 43.75, (double)y + 40);
	glVertex2i(x + 45, y + 60);
	glVertex2i(x - 45, y + 60);
	glEnd();

	glColor3ub(128, 128, 128);
	glBegin(GL_QUADS);
	glVertex2i(x - 45, y + 60);
	glVertex2i(x + 45, y + 60);
	glVertex2i(x + 45, y + 65);
	glVertex2i(x - 45, y + 65);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2d((double)x - 43.75, (double)y + 40);
	glVertex2d((double)x + 43.75, (double)y + 40);
	glVertex2i(x + 45, y + 60);
	glVertex2i(x - 45, y + 60);
	glEnd();

	glColor3ub(128, 128, 128);
	glBegin(GL_QUADS);
	glVertex2i(x - 45, y - 30);
	glVertex2i(x + 45, y - 30);
	glVertex2i(x + 45, y + 30);
	glVertex2i(x - 45, y + 30);
	glEnd();

	glColor3ub(128, 128, 128);
	glBegin(GL_QUADS);
	glVertex2i(x - 10, y + 30);
	glVertex2i(x + 10, y + 30);
	glVertex2i(x + 10, y + 50);
	glVertex2i(x - 10, y + 50);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(x - 45, y + 30);
	glVertex2i(x + 45, y + 30);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x - 42, y - 35);
	glVertex2i(x + 42, y - 35);
	glVertex2i(x + 45, y - 30);
	glVertex2i(x - 45, y - 30);
	glEnd();
}