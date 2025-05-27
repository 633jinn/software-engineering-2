/**
 * @file loginUI.h
 * @brief 로그인 사용자 인터페이스 클래스
 * @details 사용자로부터 로그인 정보를 입력받고 결과를 출력하는 UI 클래스입니다.
 */

#ifndef LOGIN_UI_H
#define LOGIN_UI_H

#include "forward.h"
#include <string>
#include <fstream>
using namespace std;

/**
 * @class LoginUI
 * @brief 로그인 화면 UI 클래스
 * @details 로그인에 필요한 사용자 입력을 처리하고 결과를 출력하는 인터페이스를 제공합니다.
 */
class LoginUI
{
private:
    Login *login;         ///< 로그인 컨트롤러 객체
    string id;           ///< 입력받은 사용자 아이디
    string password;     ///< 입력받은 사용자 비밀번호

    /**
     * @brief 사용자 입력을 읽는 메소드
     * @param in_fp 입력 파일 스트림
     */
    void readInput(ifstream &in_fp);

    /**
     * @brief 로그인 결과를 출력하는 메소드
     * @param out_fp 출력 파일 스트림
     * @param user 로그인된 사용자 객체의 포인터
     */
    void writeOutput(ofstream &out_fp, User *user);

public:
    /**
     * @brief 로그인 UI 생성자
     * @param login 로그인 컨트롤러 객체의 포인터
     */
    LoginUI(Login *login);

    /**
     * @brief 로그인 UI 소멸자
     */
    ~LoginUI();

    /**
     * @brief 로그인 계정 처리를 수행하는 메소드
     * @param in_fp 입력 파일 스트림
     * @param out_fp 출력 파일 스트림
     */
    void loginAccount(ifstream &in_fp, ofstream &out_fp);
};

#endif