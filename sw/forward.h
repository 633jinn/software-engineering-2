/**
 * @file forward.h
 * @brief 클래스 전방 선언과 상수 정의 헤더 파일
 * @details 시스템에서 사용되는 모든 클래스의 전방 선언과 공통 상수를 정의합니다.
 */

#ifndef FORWARD_H
#define FORWARD_H

/**
 * @brief 엔티티(Entity) 클래스 전방 선언
 * @details 시스템의 핵심 데이터를 표현하는 클래스들을 선언합니다.
 */
class User;
class Member;
class Manager;
class Bicycle;
class BicycleCollection;
class Database;
class Session;

/**
 * @brief 컨트롤(Control) 클래스 전방 선언
 * @details 시스템의 비즈니스 로직을 처리하는 컨트롤러 클래스들을 선언합니다.
 */
class SignUp;
class Login;
class Logout;
class RegisterBicycle;
class RentBicycle;
class CheckRentedBicycle;
class ExitProgram;

/**
 * @brief 바운더리(Boundary) 클래스 전방 선언
 * @details 사용자 인터페이스를 담당하는 UI 클래스들을 선언합니다.
 */
class SignUpUI;
class LoginUI;
class LogoutUI;
class RegisterBicycleUI;
class RentBicycleUI;
class CheckRentedBicycleUI;
class ExitProgramUI;

/**
 * @brief 시스템 공통 상수 정의
 */
#define MAX_STRING 32          ///< 문자열 최대 길이
#define INPUT_FILE_NAME "input.txt"    ///< 입력 파일 이름
#define OUTPUT_FILE_NAME "output.txt"  ///< 출력 파일 이름

#endif