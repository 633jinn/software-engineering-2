/**
 * @file manager.h
 * @brief 관리자 정보를 관리하는 클래스
 * @details User 클래스를 상속받아 시스템 관리자의 정보를 관리하는 클래스입니다.
 */

#ifndef MANAGER_H
#define MANAGER_H

#include "user.h"

/**
 * @class Manager
 * @brief 시스템 관리자 클래스
 * @details User 클래스를 상속받아 시스템 관리자의 기능을 구현합니다.
 */
class Manager : public User
{
public:
    /**
     * @brief 관리자 객체 생성자
     * @param id 관리자 아이디
     * @param password 관리자 비밀번호
     */
    Manager(string id, string password);

    /**
     * @brief 관리자 객체 소멸자
     */
    ~Manager();
};

#endif