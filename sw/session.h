/**
 * @file session.h
 * @brief 사용자 세션을 관리하는 클래스
 * @details 현재 로그인한 사용자의 정보를 관리하는 세션 클래스입니다.
 */

#ifndef SESSION_H
#define SESSION_H

#include "user.h"

/**
 * @class Session
 * @brief 사용자 세션 관리 클래스
 * @details 시스템에 로그인한 사용자의 정보를 저장하고 관리합니다.
 */
class Session
{
private:
    User *loginUser; ///< 현재 로그인한 사용자 객체

public:
    /**
     * @brief 세션 객체 생성자
     */
    Session();

    /**
     * @brief 세션 객체 소멸자
     */
    ~Session();

    /**
     * @brief 로그인한 사용자를 설정하는 메소드
     * @param user 로그인한 사용자 객체의 포인터
     */
    void setLoginUser(User *user);

    /**
     * @brief 현재 로그인한 사용자를 반환하는 메소드
     * @return 로그인한 사용자 객체의 포인터
     */
    User *getLoginUser();

    /**
     * @brief 사용자 로그아웃을 처리하는 메소드
     */
    void logoutUser();
};

#endif