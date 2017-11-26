# include "Paper_and_personality.h"
# include <iostream>
# include <time.h>
# include <random>

using namespace std;

int main(void){
    srand(time(NULL));
    Paper paper;
    paper.GeneratePaperAfterSuccess(30, 1, 0.7);
    cout << paper.getCitations() << endl;    
    cout << paper.title << endl;

    return 0;
}

