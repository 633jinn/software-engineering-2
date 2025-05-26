#include "../header/exitProgramUI.h"
#include <iostream>
using namespace std;

ExitProgramUI::ExitProgramUI(ExitProgram *exitProgram)
{
    this->exitProgram = exitProgram;
}

ExitProgramUI::~ExitProgramUI() {}

void ExitProgramUI::exit(ofstream &out_fp)
{
    writeOutput(out_fp);
}

void ExitProgramUI::writeOutput(ofstream &out_fp)
{
    out_fp << "6.1. 종료" << endl;
}