/**
 * @file rentBicycleUI.h
 * @brief 자전거 대여 사용자 인터페이스 클래스
 * @details 사용자로부터 자전거 대여 정보를 입력받고 결과를 출력하는 UI 클래스입니다.
 */

#ifndef RENT_BICYCLE_UI_H
#define RENT_BICYCLE_UI_H

#include <string>
#include <fstream>
#include "forward.h"

using namespace std;

/**
 * @class RentBicycleUI
 * @brief 자전거 대여 화면 UI 클래스
 * @details 자전거 대여에 필요한 사용자 입력을 처리하고 결과를 출력하는 인터페이스를 제공합니다.
 */
class RentBicycleUI
{
private:
    RentBicycle *rentBicycle;  ///< 자전거 대여 컨트롤러 객체
    string bicycleId;          ///< 입력받은 자전거 ID

    /**
     * @brief 사용자 입력을 읽는 메소드
     * @param in_fp 입력 파일 스트림
     */
    void readInput(ifstream &in_fp);

    /**
     * @brief 자전거 대여 결과를 출력하는 메소드
     * @param out_fp 출력 파일 스트림
     * @param bicycle 대여된 자전거 객체의 포인터
     */
    void writeOutput(ofstream &out_fp, Bicycle *bicycle);

public:
    /**
     * @brief 자전거 대여 UI 생성자
     * @param rentBicycle 자전거 대여 컨트롤러 객체의 포인터
     */
    RentBicycleUI(RentBicycle *rentBicycle);

    /**
     * @brief 자전거 대여 UI 소멸자
     */
    ~RentBicycleUI();

    /**
     * @brief 자전거 대여 정보 처리를 수행하는 메소드
     * @param in_fp 입력 파일 스트림
     * @param out_fp 출력 파일 스트림
     */
    void rentBicycleInfo(ifstream &in_fp, ofstream &out_fp);
};

#endif