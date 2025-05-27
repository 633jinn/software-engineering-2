/**
 * @file checkRentedBicycleControl.h
 * @brief 대여 자전거 조회 기능을 제어하는 컨트롤러 클래스
 * @details 회원이 대여한 자전거 목록을 조회하는 기능을 관리하는 컨트롤러입니다.
 */

#ifndef CHECK_RENTED_BICYCLE_CONTROL_H
#define CHECK_RENTED_BICYCLE_CONTROL_H

#include "forward.h"
#include "session.h"
#include "checkRentedBicycleUI.h"
#include "database.h"
#include <list>

using namespace std;

/**
 * @class CheckRentedBicycle
 * @brief 대여 자전거 조회 기능을 담당하는 컨트롤러 클래스
 * @details 사용자 인터페이스로부터 대여 자전거 조회 요청을 받아 처리하고, 대여 목록을 관리합니다.
 */
class CheckRentedBicycle
{
private:
    CheckRentedBicycleUI *checkRentedBicycleUI;  ///< 대여 자전거 조회 UI 객체
    Database *database;                           ///< 데이터베이스 객체
    Session *session;                             ///< 세션 객체

public:
    /**
     * @brief 대여 자전거 조회 컨트롤러 생성자
     * @param database 데이터베이스 객체의 포인터
     * @param session 세션 객체의 포인터
     */
    CheckRentedBicycle(Database *database, Session *session);

    /**
     * @brief 대여 자전거 조회 컨트롤러 소멸자
     */
    ~CheckRentedBicycle();

    /**
     * @brief 대여 자전거 조회 인터페이스를 시작하는 메소드
     * @param out_fp 출력 파일 스트림
     */
    void startInterface(ofstream &out_fp);

    /**
     * @brief 대여한 자전거 목록을 조회하는 메소드
     * @return 대여한 자전거 목록
     */
    list<Bicycle *> checkRentedList();
};

#endif