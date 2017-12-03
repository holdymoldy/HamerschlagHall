#ifndef Effects
#define Effects

class Effect
{
public:
	int x = 0, y = 0, tState = 0, alpha;
	void DrawMoney(float money, float pres, float know, float ment, float exp, int sem, int year);
	void DrawTransition(void);
	void initTransition(void);
};


#endif
