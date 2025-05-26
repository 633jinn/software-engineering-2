#include "forward.h"
#include "entity.h"
#include "control.h"
using namespace std;

void doTask(ifstream &in_fp, ofstream &out_fp, Database *database, Session *session)
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
        SignIn *signInControl = new SignIn(database);
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
        Login *loginControl = new Login(database, session);
        loginControl->startInterface(in_fp, out_fp);
        delete loginControl;
        break;
      }
      case 2:
      {
        Logout *logoutControl = new Logout(database, session);
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
        RegisterBicycle *registerBicycleControl = new RegisterBicycle(database);
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
        RentBicycle *rentBicycleControl = new RentBicycle(database, session);
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
        CheckRentedBicycle *checkRentedInfoControl = new CheckRentedBicycle(database, session);
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
        ExitProgram *exitProgramControl = new ExitProgram(database);
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
int main()
{

  // 파일 변수 선언
  ifstream in_fp;
  ofstream out_fp;

  // Database 선언
  Database *database = new Database();

  // Session 선언
  Session *session = new Session();

  // 파일 입출력을 위한 초기화
  in_fp.open(INPUT_FILE_NAME);
  out_fp.open(OUTPUT_FILE_NAME);

  doTask(in_fp, out_fp, database, session);

  delete database;
  delete session;

  out_fp.close();
  in_fp.close();

  return 0;
}