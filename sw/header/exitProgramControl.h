#ifndef EXIT_PROGRAM_CONTROL_H
#define EXIT_PROGRAM_CONTROL_H

#include <string>
#include <fstream>
#include <list>

#include "forward.h"
#include "exitProgramUI.h"
// 프로그램 종료
class ExitProgram
{
private:
    ExitProgramUI *exitProgramUI;

public:
    ExitProgram();
    ~ExitProgram();
    void startInterface(ofstream &out_fp);
};

#endif