/**
 * @file loginControl.h
 * @brief 로그인 기능을 제어하는 컨트롤러 클래스
 * @details 사용자의 로그인 요청을 처리하고 인증을 수행하는 컨트롤러입니다.
 */

#ifndef LOGIN_CONTROL_H
#define LOGIN_CONTROL_H

#include <string>
#include <fstream>
#include <list>

#include "forward.h"
#include "loginUI.h"
#include "database.h"
#include "session.h"
#include "user.h"

/**
 * @class Login
 * @brief 로그인 기능을 담당하는 컨트롤러 클래스
 * @details 사용자 인터페이스로부터 로그인 요청을 받아 처리하고, 데이터베이스와 세션을 관리합니다.
 */
class Login
{
private:
    LoginUI *loginUI;     ///< 로그인 UI 객체
    Database *database;   ///< 데이터베이스 객체
    Session *session;     ///< 세션 객체

public:
    /**
     * @brief 로그인 컨트롤러 생성자
     * @param database 데이터베이스 객체의 포인터
     * @param session 세션 객체의 포인터
     */
    Login(Database *database, Session *session);

    /**
     * @brief 로그인 컨트롤러 소멸자
     */
    ~Login();

    /**
     * @brief 로그인 인터페이스를 시작하는 메소드
     * @param in_fp 입력 파일 스트림
     * @param out_fp 출력 파일 스트림
     */
    void startInterface(ifstream &in_fp, ofstream &out_fp);

    /**
     * @brief 사용자 로그인을 처리하는 메소드
     * @param id 사용자 아이디
     * @param password 사용자 비밀번호
     * @return 인증된 사용자 객체의 포인터, 실패시 nullptr
     */
    User *login(string id, string password);
};

#endif