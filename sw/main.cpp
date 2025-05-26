#include "forward.h"
#include "entity.h"
#include "control.h"
using namespace std;

// 변수 선언
ofstream out_fp;
ifstream in_fp;

// Database 정적 멤버 변수 선언
Manager *Database::manager = nullptr;
list<Member *> Database::memberList;
list<Bicycle *> Database::bicycleList;

// Session 선언
User *Session::loginUser = nullptr;

// Database 초기화 함수 구현
void initializeDatabase()
{
  Database::manager = new Manager("admin", "admin");
}

int main()
{
  // Database 초기화
  initializeDatabase();

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
        SignIn *signInControl = new SignIn();
        signInControl->startInterface(in_fp, out_fp);
        delete signInControl;
        break;
      }
      }
      break;
    }
    case 2:
    {
      switch (menu_level_2)
      {
      case 1: // "2.1. 로그인" 메뉴 부분
      {
        Login *loginControl = new Login();
        loginControl->startInterface(in_fp, out_fp);
        delete loginControl;
        break;
      }
      case 2:
      {
        Logout *logoutControl = new Logout();
        logoutControl->startInterface(in_fp, out_fp);
        delete logoutControl;
        break;
      }
      }
      break;
    }
    case 3:
    {
      switch (menu_level_2)
      {
      case 1: // "3.1. 자전거 등록" 메뉴 부분
      {
        RegisterBicycle *registerBicycleControl = new RegisterBicycle();
        registerBicycleControl->startInterface(in_fp, out_fp);
        delete registerBicycleControl;
        break;
      }
      }
      break;
    }
    case 4:
    {
      switch (menu_level_2)
      {
      case 1: // "4.1. 자전거 대여" 메뉴 부분
      {
        RentBicycle *rentBicycleControl = new RentBicycle();
        rentBicycleControl->startInterface(in_fp, out_fp);
        delete rentBicycleControl;
        break;
      }
      }
      break;
    }
    case 5:
    {
      switch (menu_level_2)
      {
      case 1: // "5.1. 자전거 대여 리스트" 메뉴 부분
      {
        CheckRentedBicycle *checkRentedInfoControl = new CheckRentedBicycle();
        checkRentedInfoControl->startInterface(out_fp);
        delete checkRentedInfoControl;
        break;
      }
      }
      break;
    }
    case 6:
    {
      switch (menu_level_2)
      {
      case 1: // "6.1. 종료" 메뉴 부분
      {
        ExitProgram *exitProgramControl = new ExitProgram();
        exitProgramControl->startInterface(out_fp);
        delete exitProgramControl;
        is_program_exit = 1;
        break;
      }
      }
      break;
    }
    }
  }
}