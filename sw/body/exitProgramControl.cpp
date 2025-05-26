#include "../header/exitProgramControl.h"
#include "../header/exitProgramUI.h"
#include "../header/database.h"
ExitProgram::ExitProgram()
{
    exitProgramUI = new ExitProgramUI(this);
}

ExitProgram::~ExitProgram()
{
    delete exitProgramUI;
}

void ExitProgram::startInterface(ofstream &out_fp)
{
    exitProgramUI->exit(out_fp);
}