#include "../control/exitProgramControl.h"
#include "../boundary/exitProgramUI.h"
#include "../entity/database.h"
ExitProgram::ExitProgram(Database *database)
{
    this->database = database;
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