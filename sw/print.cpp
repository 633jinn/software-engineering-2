// 헤더 선언
#include <string.h>
#include <fstream>
#include <list>

#include "entity/member.h"
#include "control/signin.h"

using namespace std;

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void doTask();
void join();
void program_exit();

// 변수 선언
ofstream out_fp;
ifstream in_fp;

int main()
{

  // 파일 입출력을 위한 초기화
  in_fp.open(INPUT_FILE_NAME);
  out_fp.open(OUTPUT_FILE_NAME);

  doTask();

  // ...

  out_fp.close();
  in_fp.close();

  return 0;
}

void doTask()
{

  // 메뉴 파싱을 위한 level 구분을 위한 변수
  int menu_level_1 = 0, menu_level_2 = 0;
  int is_program_exit = 0;

  while (!is_program_exit)
  {
    // 입력파일에서 메뉴 숫자 2개를 읽기
    in_fp >> menu_level_1 >> menu_level_2;
    cout << "menu_1:" << menu_level_1 << endl;
    cout << "menu_2:" << menu_level_2 << endl;
    // 메뉴 구분 및 해당 연산 수행
    switch (menu_level_1)
    {
    case 1:
    {
      switch (menu_level_2)
      {
      case 1: // "1.1. 회원가입" 메뉴 부분
      {
        // 해당 기능 수행
        join();
        break;
      }
      case 2:
      {
        // ...
        break;
      }
      }
    }
    // ...
    case 7:
    {
      switch (menu_level_2)
      {
      case 1: // "6.1. 종료" 메뉴 부분
      {
        // ...
        is_program_exit = 1;
        break;
      }
      }
    }
    }
    // ...
  }
  is_program_exit = 1;
}

void join()
{

  SignIn signInControl;
  /*
   * 단순히 파일을 통해 입출력하는 방법을 보이기 위한 것이므로 실제 이 함수를 사용하면 안됨.
   * 위의 switch 문에서 control 및 boundary class를 이용해서 이 기능이 구현되도록 해야 함.
   */

  char  ID[MAX_STRING], password[MAX_STRING], phoneNumber[MAX_STRING];

  // 입력 형식 : 이름, ID, Password를 파일로부터 읽음
  in_fp >> ID >> password >> phoneNumber;

  // 해당 기능 수행
  signInControl.addNewMember(ID, password, phoneNumber);

  // 출력 형식
  out_fp << "1.1. 회원가입" << endl;
  out_fp << "> " << ID << " " << password << " " << phoneNumber << " " << password << endl;
}
