/**
 * @file rentBicycleControl.h
 * @brief 자전거 대여 기능을 제어하는 컨트롤러 클래스
 * @details 회원의 자전거 대여 요청을 처리하고 대여 정보를 관리하는 컨트롤러입니다.
 */

#ifndef RENT_BICYCLE_CONTROL_H
#define RENT_BICYCLE_CONTROL_H

#include <string>
#include <fstream>
#include <list>

#include "forward.h"
#include "rentBicycleUI.h"
#include "database.h"
#include "session.h"
#include "user.h"
#include "member.h"
#include "bicycle.h"
#include "bicycleCollection.h"

using namespace std;

/**
 * @class RentBicycle
 * @brief 자전거 대여 기능을 담당하는 컨트롤러 클래스
 * @details 사용자 인터페이스로부터 자전거 대여 요청을 받아 처리하고, 대여 정보를 관리합니다.
 */
class RentBicycle
{
private:
    RentBicycleUI *rentBicycleUI;  ///< 자전거 대여 UI 객체
    Database *database;             ///< 데이터베이스 객체
    Session *session;               ///< 세션 객체

public:
    /**
     * @brief 자전거 대여 컨트롤러 생성자
     * @param database 데이터베이스 객체의 포인터
     * @param session 세션 객체의 포인터
     */
    RentBicycle(Database *database, Session *session);

    /**
     * @brief 자전거 대여 컨트롤러 소멸자
     */
    ~RentBicycle();

    /**
     * @brief 자전거 대여 인터페이스를 시작하는 메소드
     * @param in_fp 입력 파일 스트림
     * @param out_fp 출력 파일 스트림
     */
    void startInterface(ifstream &in_fp, ofstream &out_fp);

    /**
     * @brief 자전거 대여를 처리하는 메소드
     * @param bicycleId 대여할 자전거 ID
     * @return 대여된 자전거 객체의 포인터
     */
    Bicycle *rentBicycle(string bicycleId);
};

#endif