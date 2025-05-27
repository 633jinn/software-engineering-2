/**
 * @file signupControl.h
 * @brief 회원가입 기능을 제어하는 컨트롤러 클래스
 * @details 새로운 회원의 가입 요청을 처리하고 회원 정보를 등록하는 컨트롤러입니다.
 */

#ifndef SIGNUP_CONTROL_H
#define SIGNUP_CONTROL_H

#include <string.h>
#include <fstream>
#include <list>

#include "forward.h"
#include "signupUI.h"
#include "database.h"
#include "member.h"
using namespace std;

/**
 * @class SignUp
 * @brief 회원가입 기능을 담당하는 컨트롤러 클래스
 * @details 사용자 인터페이스로부터 회원가입 요청을 받아 처리하고, 데이터베이스에 회원 정보를 등록합니다.
 */
class SignUp
{
private:
    SignUpUI *signupUI;   ///< 회원가입 UI 객체
    Database *database;    ///< 데이터베이스 객체

public:
    /**
     * @brief 회원가입 컨트롤러 생성자
     * @param database 데이터베이스 객체의 포인터
     */
    SignUp(Database *database);

    /**
     * @brief 회원가입 컨트롤러 소멸자
     */
    ~SignUp();

    /**
     * @brief 회원가입 인터페이스를 시작하는 메소드
     * @param in_fp 입력 파일 스트림
     * @param out_fp 출력 파일 스트림
     */
    void startInterface(ifstream &in_fp, ofstream &out_fp);

    /**
     * @brief 새로운 회원을 추가하는 메소드
     * @param id 회원 아이디
     * @param password 회원 비밀번호
     * @param phoneNumber 회원 전화번호
     * @return 생성된 회원 객체의 포인터
     */
    Member *addNewMember(string id, string password, string phoneNumber);
};

#endif