#ifndef Drawing
#define Drawing

class Upgrade
{
public:
	int state, x, y;
	void Draw_Coffee(void);
	void Draw_CNC(void);
	void Draw_Clone(void);
	void Draw_Print(void);
	void Draw_Chem(void);
	void Draw_Server(void);
};

class Person
{
public:
	int state_person, state_walking, r_skin, g_skin, b_skin, r_hair, g_hair, b_hair, r_shirt, g_shirt, b_shirt, r_pants, g_pants, b_pants, r_shoes, g_shoes, b_shoes;
	double x, y;
	void Draw_up_still(void);
	void Draw_up_walk_left(void);
	void Draw_up_walk_right(void);
	void Draw_down_still(void);
	void Draw_down_left(void);
	void Draw_down_right(void);
	void Draw_left_still(void);
	void Draw_left_left(void);
	void Draw_left_right(void);
	void Draw_right_still(void);
	void Draw_right_left(void);
	void Draw_right_right(void);
};

class Desk
{
public:
	int state, x, y;
	void Draw(void);
};
class Computer
{
public:
	int state, x, y;
	void Draw(void);
};

#endif