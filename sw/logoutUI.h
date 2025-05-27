/**
 * @file logoutUI.h
 * @brief 로그아웃 사용자 인터페이스 클래스
 * @details 사용자의 로그아웃 요청을 처리하고 결과를 출력하는 UI 클래스입니다.
 */

#ifndef LOGOUT_UI_H
#define LOGOUT_UI_H

#include <string>
#include <fstream>
#include "forward.h"
using namespace std;

/**
 * @class LogoutUI
 * @brief 로그아웃 화면 UI 클래스
 * @details 로그아웃 요청을 처리하고 결과를 출력하는 인터페이스를 제공합니다.
 */
class LogoutUI
{
private:
    Logout *logout;  ///< 로그아웃 컨트롤러 객체

    /**
     * @brief 로그아웃 결과를 출력하는 메소드
     * @param out_fp 출력 파일 스트림
     * @param user 로그아웃된 사용자 객체의 포인터
     */
    void writeOutput(ofstream &out_fp, User *user);

public:
    /**
     * @brief 로그아웃 UI 생성자
     * @param logout 로그아웃 컨트롤러 객체의 포인터
     */
    LogoutUI(Logout *logout);

    /**
     * @brief 로그아웃 UI 소멸자
     */
    ~LogoutUI();

    /**
     * @brief 로그아웃 계정 처리를 수행하는 메소드
     * @param out_fp 출력 파일 스트림
     */
    void logoutAccount(ofstream &out_fp);
};

#endif