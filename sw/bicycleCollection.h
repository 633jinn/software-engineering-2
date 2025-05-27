/**
 * @file bicycleCollection.h
 * @brief 대여된 자전거 목록을 관리하는 클래스
 * @details 회원이 대여한 자전거들의 목록을 관리하는 컬렉션 클래스입니다.
 */

#ifndef BICYCLE_COLLECTION_H
#define BICYCLE_COLLECTION_H

#include <list>
#include "bicycle.h" 

using namespace std;

/**
 * @class BicycleCollection
 * @brief 대여된 자전거 컬렉션 클래스
 * @details 회원이 대여한 자전거들의 목록을 저장하고 관리하는 컬렉션 클래스입니다.
 */
class BicycleCollection
{
private:
    list<Bicycle *> rentedBicycle; ///< 대여된 자전거 목록

public:
    /**
     * @brief 자전거 컬렉션 객체 생성자
     */
    BicycleCollection();

    /**
     * @brief 자전거 컬렉션 객체 소멸자
     */
    ~BicycleCollection();

    /**
     * @brief 대여된 자전거를 목록에 추가하는 메소드
     * @param bicycle 대여된 자전거 객체의 포인터
     */
    void addRentedBicycle(Bicycle *bicycle);

    /**
     * @brief 대여된 자전거 목록을 반환하는 메소드
     * @return 대여된 자전거 목록
     */
    list<Bicycle *> getRentedList();
};

#endif