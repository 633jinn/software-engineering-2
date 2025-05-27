/**
 * @file bicycle.h
 * @brief 자전거 정보를 관리하는 클래스
 * @details 자전거의 기본 정보(ID, 이름)를 저장하고 관리하는 클래스입니다.
 */

#ifndef BICYCLE_H
#define BICYCLE_H

#include <string>
using namespace std;

/**
 * @class Bicycle
 * @brief 자전거 정보를 나타내는 클래스
 */
class Bicycle
{
private:
    string id;   ///< 자전거 ID
    string name; ///< 자전거 이름

public:
    /**
     * @brief 자전거 객체 생성자
     * @param id 자전거 ID
     * @param name 자전거 이름
     */
    Bicycle(string id, string name);

    /**
     * @brief 자전거 객체 소멸자
     */
    ~Bicycle();

    /**
     * @brief 자전거 ID를 반환하는 메소드
     * @return 자전거 ID
     */
    string getId();

    /**
     * @brief 자전거 이름을 반환하는 메소드
     * @return 자전거 이름
     */
    string getName();
};

#endif