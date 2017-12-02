#ifndef PapPer_h
#define PapPer_h

class Paper {
public:
	Paper();
	Paper(const Paper &from);
	~Paper();
	char* journal;
	char* title;
	int generateCitations(float intelligence, int focus);
	void GeneratePaperAfterSuccess(float intelligence, int focus);
	void GenerateTitle();
	void PrintTitle();
	void PrintJournal();
	int getCitations();
	int citations;

};

class Personality {
public:
	Personality();
	~Personality();
	void generatePersonality(float knowledge, float prestige, float mentoring);
	float getIntelligence();
	float getOptimism();
	float getStamina();
	void setIntelligence(float i);
	void setOptimism(float o);
	void setStamina(float s);

private:
	float intelligence;
	float optimism;
	float stamina;
};