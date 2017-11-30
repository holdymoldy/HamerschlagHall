#include "Paper_and_personality.h"
#include <random>
#include <time.h>
#include <string.h>
#include <stdio.h>

using namespace std;

int generateRand(void){
    return rand();
}

int generateRand(int val){
    return rand()%val;
}

Personality::Personality(){
    this->intelligence = 0;
    this->optimism = 0;
    this->stamina = 0;
}


Personality::~Personality(){

}


//knowledge, prestige, and mentoring all from advisor class
void Personality::generatePersonality(float knowledge, float prestige, float mentoring){

    // This function will need to be changed for game balancing
    float int_mean=30 + (knowledge*0.1) + (prestige*0.2) + (mentoring*0.1);
    float stam_mean=30;
    float opt_mean = 30 + (mentoring*0.2);
    float int_dev=10, stam_dev=10, opt_dev=10;

    default_random_engine gen(generateRand());
    normal_distribution<float> int_distribution(int_mean, int_dev);
    normal_distribution<float> stam_distribution(stam_mean, stam_dev);
    normal_distribution<float> opt_distribution(opt_mean, opt_dev);

    this->intelligence = int_distribution(gen);
    this->stamina = stam_distribution(gen);
    this->optimism = opt_distribution(gen);

    float attrs[3] = {this->intelligence, this->stamina, this->optimism};
    for(int i=0; i<3; i+=1){
        if(attrs[i] > 100.0){
            attrs[i] = 100;
        }
        else if(attrs[i]<0){
            attrs[i] = 0;
        }
    }
}

// getter for personality value. This getter should be used by the Student class
// The personality value should affect changes in mood, GPA, etc., in a student
float Personality::getIntelligence(){
    return this->intelligence;
}

float Personality::getOptimism(){
    return this->optimism;
}

float Personality::getStamina(){
    return this->stamina;
}

void Personality::setIntelligence(float i){
    this->intelligence = i;
}

void Personality::setOptimism(float o){
    this->optimism = o;
}

void Personality::setStamina(float s){
    this->stamina = s;
}


Paper::Paper(){
    this->citations = 0;
    this->journal = new char[20];
    this->title = new char[20];
}


Paper::~Paper(){
    if(journal!=NULL){
        delete [] journal;
        journal = NULL;
    }
    if(title!=NULL){
        delete [] title;
        title = NULL;
    }
}

void Paper::GenerateTitle(){
    char *name = new char[256];

    int sub_len = 22;
    int meth_len = 29;
    int adj_len = 32;
    int prep_len = 2;
    int verb_len = 12;

    char subjects[][30] = {"Lithium-ion Batteries", "3D Printing", "Space Travel", "Big Data Trends", "Climate Change", 
                            "CRISPR", "Biodiversity", "Data Resolution", "Epigentic Effects", "Gene Editing", 
                            "Scaling Relations", "Dark Matter", "Synthetic Biology", "Ecological Conservation", "Ecological Restoration", 
                            "Predictive Analytics", "Unstructured Data", "Ecosystem Services", "Dark Data", "Trophic Cascades",
                            "Life History", "Ecological Networks"};
    char methods[][30] = {"Neural Networks", "Hilbert Spaces", "Ecological Networks", "Game Theory", "Cayley Graphs", 
                        "Signal Processing", "Unsupervised Machine Learning", "Naive Bayes ML", "Random Forest ML", "K-Means ML",
                        "Logit Regression", "Meta-analysis", "Ethnographic Analysis", "Metapopulation Approach", "Random Sampling", 
                        "Monte Carlo", "Density Functional Theory", "Phylogenetic Reconstruction","Least-Squares Regression", "Pourbaix Analysis", 
                        "Functional Analysis", "Gene Knockout", "Optimization", "Modeling", "Path Analysis"
                        "Microscopy", "Gaussian Process Regression", "Lie Algebra", "Deep Learning"};
    char adj[][30] = {"Randomized", "Stochastic", "Computable", "Equivalent", "Connected", 
                        "Compact", "Continuous", "Degenerate", "Nondeterministic", "Resiliant", 
                        "Sesquilinear", "Invertible", "Topological", "Holistic", "Robust", 
                        "Nonlinear", "Streamlined", "Independent", "Quasi-Experimental", "Mixed-Methods",
                        "Interdisciplinary", "Phylogenetic", "Advanced", "Mixed-Dimension", "Irreducible", 
                        "Nonsingular", "Abelian", "Symbiotic", "Bayesian", "High-throughput", 
                        "Self-assembled", "Catalytic"};
    char preps[][30] = {"using", "with"};
    char verbs[][30] = {"Investigating", "Improving", "Observing", "Analyzing", "Determining Effects of", 
                        "Solving", "Designing", "Quantifying", "Uncoupling", "Modeling", 
                        "Identifying", "Calculating"};

    // test structure
    strcpy(name, verbs[generateRand(verb_len)]);
    strcat(name, " ");
    strcat(name, subjects[generateRand(sub_len)]);
    strcat(name, " ");
    strcat(name, preps[generateRand(prep_len)]);
    strcat(name, " ");
    strcat(name, adj[generateRand(adj_len)]);
    strcat(name, " ");
    strcat(name, adj[generateRand(adj_len)]);
    strcat(name, " ");
    strcat(name, methods[generateRand(meth_len)]);
    strcat(name, " ");

    if(this->title!=NULL){
        delete [] title;
        title = NULL;
    }

    this->title = name;
}



void Paper::GeneratePaperAfterSuccess(float intelligence, int focus){

    this->citations = generateCitations(intelligence, focus);

    if(this->getCitations()< 100){
        char str1[] = "The Tartan";
        strcpy(journal, str1);
    }
    if(this->getCitations() >= 100 && this->getCitations() < 300){
        char str1[] = "Buzzfeed News";
        strcpy(journal, str1);
    }
	if (this->getCitations() >= 300 && this->getCitations() < 400) {
		char str1[] = "Journal of Tourism Resarch and Hospitality";
        strcpy(journal, str1);
    }
	if (this->getCitations() >= 400 && this->getCitations() < 500) {
		char str1[] = "Magazine of Concrete Research";
        strcpy(journal, str1);
    }
	if (this->getCitations() >= 500 && this->getCitations() < 600) {
		char str1[] = "arXiv";
        strcpy(journal, str1);
    }
	if (this->getCitations() >= 600 && this->getCitations() < 700) {
		char str1[] = "Proceedings of the Royal Society";
        strcpy(journal, str1);
    }
	if (this->getCitations() >= 700 && this->getCitations() < 800) {
		char str1[] = "Reviews of Modern Science";
        strcpy(journal, str1);
    }
	if (this->getCitations() >= 800 && this->getCitations() < 900) {
		char str1[] = "Cell";
        strcpy(journal, str1);
    }
	if (this->getCitations() >= 900 && this->getCitations() < 1000) {
		char str1[] = "Science";
        strcpy(journal, str1);
    }
	if (this->getCitations() >= 1000) {
		char str1[] = "Nature";
        strcpy(journal, str1);
    }

    GenerateTitle();

}

int Paper::generateCitations(float intelligence, int focus){
    // will need to be changed later for balancing

    float mean = 8*intelligence;
    if(focus){
        mean *= 2;
    }

    return generateRand(mean+200)-200
}

int Paper::getCitations(){
    // getter for number of citations
    return citations;
}

