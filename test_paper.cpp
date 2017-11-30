# include "Paper_and_personality.h"
# include <iostream>
# include <time.h>
# include <vector>
# include <random>

using namespace std;

int main(void){
    srand(time(NULL));
    Paper paper;
    paper.GeneratePaperAfterSuccess(30, 1);
    // cout << paper.getCitations() << endl;    
    // cout << paper.title << endl;

    Paper paper2(paper);
    // cout << "here" << endl;
    // cout << paper.getCitations() << endl;    
    // cout << paper.title << endl;

    Paper paper3;
    paper3.GeneratePaperAfterSuccess(100, 1);

    vector<Paper> papers;
    papers.push_back(paper);
    papers.push_back(paper2);
    papers.push_back(paper3);
    cout << papers.size() << endl;

    for(int i=0; i<papers.size(); i+=1){
    	cout << i << papers[i].title << papers[i].getCitations() << endl;
    }

    return 0;
}

