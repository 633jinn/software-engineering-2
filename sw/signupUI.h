/**
 * @file signupUI.h
 * @brief 회원가입 사용자 인터페이스 클래스
 * @details 사용자로부터 회원가입 정보를 입력받고 결과를 출력하는 UI 클래스입니다.
 */

#ifndef SIGNUP_UI_H
#define SIGNUP_UI_H

#include <string>
#include <fstream>
#include "forward.h"
#include "signupControl.h"
using namespace std;

/**
 * @class SignUpUI
 * @brief 회원가입 화면 UI 클래스
 * @details 회원가입에 필요한 사용자 입력을 처리하고 결과를 출력하는 인터페이스를 제공합니다.
 */
class SignUpUI
{
private:
    SignUp *signUp;        ///< 회원가입 컨트롤러 객체
    string id;             ///< 입력받은 사용자 아이디
    string password;       ///< 입력받은 사용자 비밀번호
    string phoneNumber;    ///< 입력받은 사용자 전화번호

    /**
     * @brief 사용자 입력을 읽는 메소드
     * @param in_fp 입력 파일 스트림
     */
    void readInput(ifstream &in_fp);

    /**
     * @brief 회원가입 결과를 출력하는 메소드
     * @param out_fp 출력 파일 스트림
     * @param member 생성된 회원 객체의 포인터
     */
    void writeOutput(ofstream &out_fp, Member *member);

public:
    /**
     * @brief 회원가입 UI 생성자
     * @param signup 회원가입 컨트롤러 객체의 포인터
     */
    SignUpUI(SignUp *signup);

    /**
     * @brief 회원가입 UI 소멸자
     */
    ~SignUpUI();

    /**
     * @brief 회원가입 계정 처리를 수행하는 메소드
     * @param in_fp 입력 파일 스트림
     * @param out_fp 출력 파일 스트림
     */
    void signUpAccount(ifstream &in_fp, ofstream &out_fp);
};

#endif