/**
 * @file registerBicycleControl.h
 * @brief 자전거 등록 기능을 제어하는 컨트롤러 클래스
 * @details 새로운 자전거의 등록 요청을 처리하고 자전거 정보를 관리하는 컨트롤러입니다.
 */

#ifndef REGISTER_BICYCLE_CONTROL_H
#define REGISTER_BICYCLE_CONTROL_H

#include <string>
#include <fstream>
#include <list>

#include "forward.h"
#include "registerBicycleUI.h"
#include "database.h"
#include "bicycle.h"

/**
 * @class RegisterBicycle
 * @brief 자전거 등록 기능을 담당하는 컨트롤러 클래스
 * @details 사용자 인터페이스로부터 자전거 등록 요청을 받아 처리하고, 데이터베이스에 자전거 정보를 등록합니다.
 */
class RegisterBicycle
{
private:
    RegisterBicycleUI *registerBicycleUI;  ///< 자전거 등록 UI 객체
    Database *database;                     ///< 데이터베이스 객체

public:
    /**
     * @brief 자전거 등록 컨트롤러 생성자
     * @param database 데이터베이스 객체의 포인터
     */
    RegisterBicycle(Database *database);

    /**
     * @brief 자전거 등록 컨트롤러 소멸자
     */
    ~RegisterBicycle();

    /**
     * @brief 자전거 등록 인터페이스를 시작하는 메소드
     * @param in_fp 입력 파일 스트림
     * @param out_fp 출력 파일 스트림
     */
    void startInterface(ifstream &in_fp, ofstream &out_fp);

    /**
     * @brief 새로운 자전거를 등록하는 메소드
     * @param bicycleId 자전거 ID
     * @param bicycleName 자전거 이름
     * @return 등록된 자전거 객체의 포인터
     */
    Bicycle *registerBicycle(string bicycleId, string bicycleName);
};

#endif