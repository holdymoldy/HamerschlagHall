
# include "graduateStudent.cpp"
# include <iostream>

using namespace std;

int main(void){
    GradStudent student;
    student.AssignPersonality(80, 80, 80);
    cout << student.personality.getIntelligence() << endl;
    cout << student.personality.getOptimism() << endl;
    
    student.CreatePaper();
    student.currpaper.GeneratePaperAfterSuccess(30, 1, 0.7);
    cout << student.currpaper.getCitations() << endl;
    cout << student.currpaper.getJournal() << endl;
    return 0;
}