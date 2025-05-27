/**
 * @file exitProgramUI.h
 * @brief 프로그램 종료 사용자 인터페이스 클래스
 * @details 프로그램 종료 요청을 처리하고 결과를 출력하는 UI 클래스입니다.
 */

#ifndef EXIT_PROGRAM_UI_H
#define EXIT_PROGRAM_UI_H

#include "forward.h"
#include <string>
#include <fstream>
using namespace std;

/**
 * @class ExitProgramUI
 * @brief 프로그램 종료 화면 UI 클래스
 * @details 프로그램 종료 요청을 처리하고 결과를 출력하는 인터페이스를 제공합니다.
 */
class ExitProgramUI
{
private:
    ExitProgram *exitProgram;  ///< 프로그램 종료 컨트롤러 객체

    /**
     * @brief 프로그램 종료 메시지를 출력하는 메소드
     * @param out_fp 출력 파일 스트림
     */
    void writeOutput(ofstream &out_fp);

public:
    /**
     * @brief 프로그램 종료 UI 생성자
     * @param exitProgram 프로그램 종료 컨트롤러 객체의 포인터
     */
    ExitProgramUI(ExitProgram *exitProgram);

    /**
     * @brief 프로그램 종료 UI 소멸자
     */
    ~ExitProgramUI();

    /**
     * @brief 프로그램 종료를 수행하는 메소드
     * @param out_fp 출력 파일 스트림
     */
    void exit(ofstream &out_fp);
};

#endif