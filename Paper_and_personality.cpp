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
    float int_mean=50 + (knowledge*0.1) + (prestige*0.2) + (mentoring*0.15);
    float stam_mean=50;
    float opt_mean = 50 + (mentoring*0.2);
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
        if(attrs[i] > 100){
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

int Paper::SubmitPaper(float intelligence, int focus, float risk){
    // risk is a value between 0 and 1 (from lowest risk paper submission to highest risk (1 is Nature))

    default_random_engine generator;
    float multiplier = 0;
    if(focus){
        multiplier += 0.2;
    }
    // other multipliers here

    normal_distribution<float> accept_distribution(intelligence + multiplier*8, 20.0 - risk*5.0);
    float acceptance = accept_distribution(generator);
    if(acceptance > risk*100.0){
        return 1;
    }

    return 0;
}

void Paper::GenerateTitle(){
    char *name = new char[256];

    int sub_len = 22;
    int meth_len = 26;
    int adj_len = 32;
    int prep_len = 2;
    int verb_len = 12;

    char subjects[][30] = {"Lithium-ion Batteries", "3D Printing", "Space Travel", "Big Data Trends", "Climate Change", 
                            "CRISPR", "Biodiversity", "Data Resolution", "Epigentic Effects", "Gene Editing", 
                            "Scaling Relations", "Dark Matter", "Synthetic Biology", "Ecological Conservation", "Ecological Restoration", 
                            "Predictive Analytics", "Unstructured Data", "Ecosystem Services", "Dark Data", "Trophic Cascades",
                            "Life History", "Ecological Networks"};
    char methods[][30] = {"Neural Networks", "Hilbert Spaces", "Ecological Networks", "Game Theory", "Cayley Graphs", 
                        "Signal Processing", "Machine Learning", "Naive Bayes ML", "Random Forest ML", "K-Means ML",
                        "Logit Regression", "Meta-analysis", "Ethnographic Analysis", "Metapopulation Approach", "Random Sampling", 
                        "Monte Carlo", "Density Functional Theory", "Phylogenetic Reconstruction","Least-Squares Regression", "Pourbaix Analysis", 
                        "Functional Analysis", "Gene Knockout", "Optimization", "Modeling", "Path Analysis"
                        "Microscopy"};
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



void Paper::GeneratePaperAfterSuccess(float intelligence, int focus, float risk){

    this->citations = generateCitations(intelligence, focus, risk);

    if(risk>=0 && risk<0.1){
        char str1[] = "The Tartan";
        strcpy(journal, str1);
    }
    if(risk>=0.1 && risk<0.2){
        char str1[] = "Buzzfeed News";
        strcpy(journal, str1);
    }
    if(risk>=0.2 && risk<0.3){
        char str1[] = "Journal of Tourism Resarch and Hospitality";
        strcpy(journal, str1);
    }
    if(risk>=0.3 && risk<0.4){
         char str1[] = "Magazine of Concrete Research";
        strcpy(journal, str1);
    }
    if(risk>=0.4 && risk<0.5){
        char str1[] = "arXiv";
        strcpy(journal, str1);
    }
    if(risk>=0.5 && risk<0.6){
        char str1[] = "Proceedings of the Royal Society";
        strcpy(journal, str1);
    }
    if(risk>=0.6 && risk<0.7){
         char str1[] = "Reviews of Modern Science";
        strcpy(journal, str1);
    }
    if(risk>=0.7 && risk<0.8){
        char str1[] = "Cell";
        strcpy(journal, str1);
    }
    if(risk>=0.8 && risk<0.9){
         char str1[] = "Science";
        strcpy(journal, str1);
    }
    if(risk>=0.9 && risk<1.0){
        char str1[] = "Nature";
        strcpy(journal, str1);
    }

    GenerateTitle();

}

int Paper::generateCitations(float intelligence, int focus, float risk){
    // will need to be changed later for balancing

    default_random_engine generator;
    float mean = intelligence + risk*500;
    if(focus){
        mean *= 2;
    }
    normal_distribution<float> cit_distribution(mean, 20);

    return (int)cit_distribution(generator);
}

int Paper::getCitations(){
    // getter for number of citations
    return citations;
}

