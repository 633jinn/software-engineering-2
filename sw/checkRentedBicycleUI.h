/**
 * @file checkRentedBicycleUI.h
 * @brief 대여 자전거 조회 사용자 인터페이스 클래스
 * @details 회원이 대여한 자전거 목록을 조회하고 결과를 출력하는 UI 클래스입니다.
 */

#ifndef CHECK_RENTED_BICYCLE_UI_H
#define CHECK_RENTED_BICYCLE_UI_H

#include <string>
#include <fstream>
#include <list>

#include "forward.h"
using namespace std;

/**
 * @class CheckRentedBicycleUI
 * @brief 대여 자전거 조회 화면 UI 클래스
 * @details 대여한 자전거 목록을 조회하고 결과를 출력하는 인터페이스를 제공합니다.
 */
class CheckRentedBicycleUI
{
private:
    CheckRentedBicycle *checkRentedBicycle;  ///< 대여 자전거 조회 컨트롤러 객체

    /**
     * @brief 대여 자전거 목록을 출력하는 메소드
     * @param out_fp 출력 파일 스트림
     * @param rentedBicycle 대여한 자전거 목록
     */
    void writeOutput(ofstream &out_fp, list<Bicycle *> rentedBicycle);

public:
    /**
     * @brief 대여 자전거 조회 UI 생성자
     * @param checkRentedBicycle 대여 자전거 조회 컨트롤러 객체의 포인터
     */
    CheckRentedBicycleUI(CheckRentedBicycle *checkRentedBicycle);

    /**
     * @brief 대여 자전거 조회 UI 소멸자
     */
    ~CheckRentedBicycleUI();

    /**
     * @brief 대여 자전거 정보 조회를 수행하는 메소드
     * @param out_fp 출력 파일 스트림
     */
    void checkRentedInfo(ofstream &out_fp);
};

#endif