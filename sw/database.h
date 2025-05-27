/**
 * @file database.h
 * @brief 시스템의 데이터를 관리하는 데이터베이스 클래스
 * @details 회원, 자전거, 관리자 정보를 저장하고 관리하는 클래스입니다.
 */

#ifndef DATABASE_H
#define DATABASE_H

#include <list>
#include "user.h"
#include "manager.h"
#include "bicycle.h"
#include "member.h"
#include "forward.h"
using namespace std;

/**
 * @class Database
 * @brief 시스템의 모든 데이터를 관리하는 클래스
 */
class Database
{
private:
    Manager *manager;          ///< 시스템 관리자 객체
    list<Member *> memberList; ///< 회원 목록
    list<Bicycle *> bicycleList; ///< 자전거 목록

public:
    /**
     * @brief 데이터베이스 생성자
     */
    Database();

    /**
     * @brief 데이터베이스 소멸자
     */
    ~Database();

    /**
     * @brief 새로운 회원을 추가하는 메소드
     * @param id 회원 아이디
     * @param password 회원 비밀번호
     * @param phoneNumber 회원 전화번호
     * @return 생성된 회원 객체의 포인터
     */
    Member *addMember(string id, string password, string phoneNumber);

    /**
     * @brief 사용자 정보를 찾는 메소드
     * @param id 사용자 아이디
     * @param password 사용자 비밀번호
     * @return 찾은 사용자 객체의 포인터, 없으면 nullptr
     */
    User *findUser(string id, string password);

    /**
     * @brief 새로운 자전거를 추가하는 메소드
     * @param bicycleId 자전거 ID
     * @param bicycleName 자전거 이름
     * @return 생성된 자전거 객체의 포인터
     */
    Bicycle *addBicycle(string bicycleId, string bicycleName);

    /**
     * @brief 자전거 정보를 찾는 메소드
     * @param bicycleId 자전거 ID
     * @return 찾은 자전거 객체의 포인터, 없으면 nullptr
     */
    Bicycle *findBicycle(string bicycleId);
};

#endif