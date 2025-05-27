/**
 * @file member.h
 * @brief 회원 정보를 관리하는 클래스
 * @details User 클래스를 상속받아 회원의 추가 정보(전화번호, 대여 자전거)를 관리하는 클래스입니다.
 */

#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include "forward.h"
#include "user.h"
#include "bicycleCollection.h"

/**
 * @class Member
 * @brief 회원 정보를 나타내는 클래스
 * @details User 클래스를 상속받아 일반 회원의 기능을 구현합니다.
 */
class Member : public User
{
private:
    string phoneNumber;                    ///< 회원 전화번호
    BicycleCollection *bicycleCollection;  ///< 회원이 대여한 자전거 컬렉션 객체

public:
    /**
     * @brief 회원 객체 생성자
     * @param id 회원 아이디
     * @param password 회원 비밀번호
     * @param phoneNumber 회원 전화번호
     */
    Member(string id, string password, string phoneNumber);

    /**
     * @brief 회원 객체 소멸자
     */
    ~Member();

    /**
     * @brief 회원 전화번호를 반환하는 메소드
     * @return 회원 전화번호
     */
    string getPhoneNumber();

    /**
     * @brief 회원이 대여한 자전거 목록을 반환하는 메소드
     * @return 대여한 자전거 컬렉션 객체의 포인터
     */
    BicycleCollection *getBicycleCollection();
};

#endif