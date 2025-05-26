#ifndef EXIT_PROGRAM_CONTROL_H
#define EXIT_PROGRAM_CONTROL_H

#include <string>
#include <fstream>
#include <list>

#include "../forward.h"
#include "../entity/database.h"
#include "../boundary/exitProgramUI.h"
// 프로그램 종료
class ExitProgram
{
private:
    ExitProgramUI *exitProgramUI;
    Database *database;

public:
    ExitProgram(Database *database);
    ~ExitProgram();
    void startInterface(ofstream &out_fp);
};

#endif