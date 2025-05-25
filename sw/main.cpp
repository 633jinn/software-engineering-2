#include "forward.h"
#include "entity.h"
#include "control.h"
using namespace std;

// 함수 선언
void doTask(UserDB *userDB);
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

  // UserDB 생성
  UserDB *userDB = new UserDB();

  doTask(userDB);

  // ...

  out_fp.close();
  in_fp.close();

  return 0;
}

void doTask(UserDB *userDB)
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

        SignIn *signInControl = new SignIn(userDB);
        signInControl->startInterface(in_fp, out_fp);
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