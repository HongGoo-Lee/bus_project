#include <stdio.h>
#include <Windows.h>
#include "시외버스프로그램.h"



int main()
{    
    SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
    //test_time();
    //test_seat();
    //test_floyd();
    //test_login_ui();
    menu_1();
    //test_tiket_ui();
    //test4();
    //test_select_route_way();
    //test_seat();
    //ui_money_admin();
    //select_money_menu();
    return 0;
}