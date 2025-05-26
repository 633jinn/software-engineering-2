#ifndef EXIT_PROGRAM_UI_H
#define EXIT_PROGRAM_UI_H

#include "forward.h"
#include <string>
#include <fstream>
using namespace std;

class ExitProgramUI
{
private:
    ExitProgram *exitProgram;
    void writeOutput(ofstream &out_fp);

public:
    ExitProgramUI(ExitProgram *exitProgram);
    ~ExitProgramUI();
    void exit(ofstream &out_fp);
};

#endif