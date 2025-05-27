/**
 * @file exitProgramControl.h
 * @brief 프로그램 종료 기능을 제어하는 컨트롤러 클래스
 * @details 사용자의 프로그램 종료 요청을 처리하는 컨트롤러입니다.
 */

#ifndef EXIT_PROGRAM_CONTROL_H
#define EXIT_PROGRAM_CONTROL_H

#include <string>
#include <fstream>
#include <list>

#include "forward.h"
#include "exitProgramUI.h"

/**
 * @class ExitProgram
 * @brief 프로그램 종료 기능을 담당하는 컨트롤러 클래스
 * @details 사용자 인터페이스로부터 프로그램 종료 요청을 받아 처리합니다.
 */
class ExitProgram
{
private:
    ExitProgramUI *exitProgramUI;  ///< 프로그램 종료 UI 객체

public:
    /**
     * @brief 프로그램 종료 컨트롤러 생성자
     */
    ExitProgram();

    /**
     * @brief 프로그램 종료 컨트롤러 소멸자
     */
    ~ExitProgram();

    /**
     * @brief 프로그램 종료 인터페이스를 시작하는 메소드
     * @param out_fp 출력 파일 스트림
     */
    void startInterface(ofstream &out_fp);
};

#endif