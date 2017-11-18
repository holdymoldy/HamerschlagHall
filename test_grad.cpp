
# include "graduateStudent.h"
// # include "paper.h"
// # include "personality.h"
# include <iostream>

using namespace std;

int main(void){
    GradStudent student;
    student.AssignPersonality(80, 80, 80);
    cout << student.personality->getIntelligence() << endl;
    cout << student.personality->getOptimism() << endl;
    
    student.CreatePaper();
    student.currpaper->GeneratePaperAfterSuccess(30, 1, 0.7);
    cout << student.currpaper->getCitations() << endl;

    GradStudent *newstudent = student.copy();
    cout << newstudent->personality->getIntelligence() << endl;
    cout << newstudent->personality->getOptimism() << endl;


    return 0;
}

