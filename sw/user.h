/**
 * @file user.h
 * @brief 사용자 기본 정보를 관리하는 추상 클래스
 * @details 모든 사용자 타입의 기본이 되는 추상 클래스로, 기본적인 인증 정보를 관리합니다.
 */

#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

/**
 * @class User
 * @brief 사용자 기본 클래스
 * @details 시스템의 모든 사용자 타입(회원, 관리자 등)의 기본이 되는 추상 클래스입니다.
 */
class User
{
protected:
    string id;       ///< 사용자 아이디
    string password; ///< 사용자 비밀번호

public:
    /**
     * @brief 가상 소멸자
     */
    virtual ~User() {}

    /**
     * @brief 사용자 아이디를 반환하는 메소드
     * @return 사용자 아이디
     */
    string getId() { return id; }

    /**
     * @brief 사용자 비밀번호를 반환하는 메소드
     * @return 사용자 비밀번호
     */
    string getPassword() { return password; }

    /**
     * @brief 사용자 인증을 확인하는 메소드
     * @param id 확인할 사용자 아이디
     * @param password 확인할 사용자 비밀번호
     * @return 인증 성공 여부
     */
    bool isValid(string id, string password)
    {
        if (id == this->id && password == this->password)
            return true;
        return false;
    }
};

#endif