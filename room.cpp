#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "fssimplewindow.h"
#include "room.hpp"
#include "Advisor-Action.hpp"

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

int CheckHitTarget(
                   double missileX, double missileY,
                   double targetX, double targetY, double targetSizeX, double targetSizeY)
{
    double relativeX, relativeY;
    relativeX = missileX - targetX;
    relativeY = missileY - targetY;
    if (0 <= relativeX && relativeX<targetSizeX && 0 <= relativeY && relativeY<targetSizeY)
    {
        return 1;
    }
    else
    {
        return 0;
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

void GenerateSetup(int nDesk, Desk desk[6], Computer computer[6], Person people[7], Upgrade upgrade[6])
{
    int i;
    for (i = 0; i<nDesk / 2; i++)
    {
        desk[i].state = 0;
        desk[i].x = 400;
        desk[i].y = 900 - 200 * i;
        
        computer[i].state = 0;
        computer[i].x = 400;
        computer[i].y = 850 - 200 * i;
        
        people[i].state_person = 0;
        people[i].x = 400;
        people[i].y = 820 - 200 * i;
        
        upgrade[i].state = 0;
        upgrade[i].x = 200;
        upgrade[i].y = 900 - 200 * i;
        
        desk[i + 3].state = 0;
        desk[i + 3].x = 800;
        desk[i + 3].y = 900 - 200 * i;
        
        computer[i + 3].state = 0;
        computer[i + 3].x = 800;
        computer[i + 3].y = 850 - 200 * i;
        
        people[i + 3].state_person = 0;
        people[i + 3].x = 800;
        people[i + 3].y = 820 - 200 * i;
        
        upgrade[i + 3].state = 0;
        upgrade[i + 3].x = 1135;
        upgrade[i + 3].y = 900 - 200 * i;
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
    
    y = y - 50;
    
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
    
    // Mail Box
    
    y = y + 25;
    x = x + 140;
    
    glColor3ub(70, 130, 180);
    glBegin(GL_POLYGON);
    glVertex2d((double)x - 20.75, (double)y - 10);
    glVertex2d((double)x + 20.75, (double)y - 10);
    glVertex2i(x + 22, y + 10);
    glVertex2i(x - 22, y + 10);
    glEnd();
    
    glColor3ub(255, 222, 173);
    glBegin(GL_QUADS);
    glVertex2i(x - 18, y - 14);
    glVertex2i(x + 18, y - 14);
    glVertex2i(x + 18, y + 6);
    glVertex2i(x - 18, y + 6);
    glEnd();
    
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(x - 18, y - 14);
    glVertex2i(x + 18, y - 14);
    glVertex2i(x + 18, y + 6);
    glVertex2i(x - 18, y + 6);
    glEnd();
    
    glColor3ub(255, 222, 173);
    glBegin(GL_QUADS);
    glVertex2i(x - 18, y - 11);
    glVertex2i(x + 18, y - 11);
    glVertex2i(x + 18, y + 9);
    glVertex2i(x - 18, y + 9);
    glEnd();
    
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(x - 18, y - 11);
    glVertex2i(x + 18, y - 11);
    glVertex2i(x + 18, y + 9);
    glVertex2i(x - 18, y + 9);
    glEnd();
    
    glColor3ub(255, 222, 173);
    glBegin(GL_QUADS);
    glVertex2i(x - 18, y - 8);
    glVertex2i(x + 18, y - 8);
    glVertex2i(x + 18, y + 12);
    glVertex2i(x - 18, y + 12);
    glEnd();
    
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(x - 18, y - 8);
    glVertex2i(x + 18, y - 8);
    glVertex2i(x + 18, y + 12);
    glVertex2i(x - 18, y + 12);
    glEnd();
    
    glColor3ub(255, 222, 173);
    glBegin(GL_QUADS);
    glVertex2i(x - 18, y - 5);
    glVertex2i(x + 18, y - 5);
    glVertex2i(x + 18, y + 15);
    glVertex2i(x - 18, y + 15);
    glEnd();
    
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(x - 18, y - 5);
    glVertex2i(x + 18, y - 5);
    glVertex2i(x + 18, y + 15);
    glVertex2i(x - 18, y + 15);
    glEnd();
    
    glColor3ub(255, 222, 173);
    glBegin(GL_QUADS);
    glVertex2i(x - 18, y - 2);
    glVertex2i(x + 18, y - 2);
    glVertex2i(x + 18, y + 18);
    glVertex2i(x - 18, y + 18);
    glEnd();
    
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(x - 18, y - 2);
    glVertex2i(x + 18, y - 2);
    glVertex2i(x + 18, y + 18);
    glVertex2i(x - 18, y + 18);
    glEnd();
    
    glColor3ub(255, 222, 173);
    glBegin(GL_QUADS);
    glVertex2i(x - 18, y + 1);
    glVertex2i(x + 18, y + 1);
    glVertex2i(x + 18, y + 21);
    glVertex2i(x - 18, y + 21);
    glEnd();
    
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(x - 18, y + 1);
    glVertex2i(x + 18, y + 1);
    glVertex2i(x + 18, y + 21);
    glVertex2i(x - 18, y + 21);
    glEnd();
    
    glColor3ub(255, 222, 173);
    glBegin(GL_QUADS);
    glVertex2i(x - 18, y + 4);
    glVertex2i(x + 18, y + 4);
    glVertex2i(x + 18, y + 24);
    glVertex2i(x - 18, y + 24);
    glEnd();
    
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(x - 18, y + 4);
    glVertex2i(x + 18, y + 4);
    glVertex2i(x + 18, y + 24);
    glVertex2i(x - 18, y + 24);
    glEnd();
    
    glColor3ub(30, 144, 255);
    glBegin(GL_QUADS);
    glVertex2i(x - 22, y + 10);
    glVertex2i(x + 22, y + 10);
    glVertex2i(x + 22, y + 50);
    glVertex2i(x - 22, y + 50);
    glEnd();
    
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2d((double)x - 20.75, (double)y - 10);
    glVertex2d((double)x + 20.75, (double)y - 10);
    glVertex2i(x + 22, y + 10);
    glVertex2i(x - 22, y + 10);
    glEnd();
    
    glColor3ub(255, 222, 173);
    glBegin(GL_LINES);
    glVertex2d((double)x - 17, (double)y - 10);
    glVertex2d((double)x + 18, (double)y - 10);
    glEnd();
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
 */

int main(void)
{
    int i, key, nShot;
    double x_prof = 600, y_prof = 900, x_profdesk = 600, y_profdesk = 200;
    const double PI = 3.1415927;
    
    srand(time(NULL));
    
    FsOpenWindow(16, 16, 1200, 1000, 1);
    
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
                if (upgrade[5].state == 1)
                {
                    if (people[0].y > (upgrade[5].y - 75) && people[0].y < (upgrade[5].y + 15) && (people[0].x - 32) < (upgrade[5].x + 60) && (people[0].x + 32) > (upgrade[5].x - 60))
                    {
                        people[0].y += 10;
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
                if (people[0].y > 950)
                {
                    people[0].y -= 10;
                }
                if (upgrade[5].state == 1)
                {
                    if (people[0].y > (upgrade[5].y - 75) && people[0].y < (upgrade[5].y + 15) && (people[0].x - 32) < (upgrade[5].x + 60) && (people[0].x + 32) > (upgrade[5].x - 60))
                    {
                        people[0].y -= 10;
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
                if (upgrade[5].state == 1)
                {
                    if (people[0].y > (upgrade[5].y - 75) && people[0].y < (upgrade[5].y + 15) && (people[0].x - 32) < (upgrade[5].x + 60) && (people[0].x + 32) > (upgrade[5].x - 60))
                    {
                        people[0].x -= 10;
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
                if (upgrade[5].state == 1)
                {
                    if (people[0].y > (upgrade[5].y - 75) && people[0].y < (upgrade[5].y + 15) && (people[0].x - 32) < (upgrade[5].x + 60) && (people[0].x + 32) > (upgrade[5].x - 60))
                    {
                        people[0].x += 10;
                    }
                }
                break;
            case FSKEY_SPACE:
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
                if (people[i].y < 425 && people[i].y >= 125)
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
        if (upgrade[5].state != 0)
        {
            upgrade[5].Draw_Coffee();
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
                if (people[i].y < 625 && people[i].y >= 425)
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
                if (people[i].y < 825 && people[i].y >= 625)
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
                if (people[i].y <= 1000 && people[i].y >= 825)
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

