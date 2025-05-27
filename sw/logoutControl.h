/**
 * @file logoutControl.h
 * @brief 로그아웃 기능을 제어하는 컨트롤러 클래스
 * @details 사용자의 로그아웃 요청을 처리하고 세션을 관리하는 컨트롤러입니다.
 */

#ifndef LOGOUT_CONTROL_H
#define LOGOUT_CONTROL_H

#include <string>
#include <fstream>
#include <list>

#include "forward.h"
#include "logoutUI.h"
#include "database.h"
#include "session.h"
#include "user.h"

/**
 * @class Logout
 * @brief 로그아웃 기능을 담당하는 컨트롤러 클래스
 * @details 사용자 인터페이스로부터 로그아웃 요청을 받아 처리하고, 세션 정보를 업데이트합니다.
 */
class Logout
{
private:
    LogoutUI *logoutUI;   ///< 로그아웃 UI 객체
    Database *database;    ///< 데이터베이스 객체
    Session *session;      ///< 세션 객체

public:
    /**
     * @brief 로그아웃 컨트롤러 생성자
     * @param database 데이터베이스 객체의 포인터
     * @param session 세션 객체의 포인터
     */
    Logout(Database *database, Session *session);

    /**
     * @brief 로그아웃 컨트롤러 소멸자
     */
    ~Logout();

    /**
     * @brief 로그아웃 인터페이스를 시작하는 메소드
     * @param out_fp 출력 파일 스트림
     */
    void startInterface(ofstream &out_fp);

    /**
     * @brief 사용자 로그아웃을 처리하는 메소드
     * @return 로그아웃된 사용자 객체의 포인터
     */
    User *logout();
};

#endif