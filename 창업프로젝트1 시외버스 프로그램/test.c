#include "시외버스프로그램.h"
#include <stdio.h>
#include <Windows.h>

void test_first_screen(void)
{
	int x, y, l;
	while (1)
	{
		click(&x, &y, &l);
		printf("x = %d y = %d lr = %d\n", x, y, l);
	}
}

void test_login_ui(void)
{
	ui_login_screen("이홍구");
}

void test_sign_up(void)
{
	ui_sign_up();
}

void test_message(void)
{
	ui_sign_up();
	ui_massage("사용 가능한 ID 입니다.",20);
}

void test_floyd()
{
	int menu = 2, **cost, ** time, a;
	LinkedList** list;
	a = get_terminal_count("전체");
	cost = (int**)calloc(a, sizeof(int*));
	time = (int**)calloc(a, sizeof(int*));
	list = (LinkedList**)calloc(a, sizeof(LinkedList*));
	for (int i = 0; i < a; i++)
	{
		cost[i] = (int*)calloc(a, sizeof(int));
		time[i] = (int*)calloc(a, sizeof(int));
		list[i] = (LinkedList*)calloc(a, sizeof(LinkedList));
	}
	set_terminal_array(1, cost, list);
	//floyd_warshall(menu, cost, time, list);
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			printf("%05d ", cost[i][j]);
		}
		printf("\n");
		free(cost[i]);
		free(time[i]);
		//delete_node(list[i][0].next);
		free(list[i]);
	}
	free(cost);
	free(time);
	free(list);
}

void test_select_route_way(void)
{
	Terminal str1, str2;
	strcpy(str1.terminal_name, "청주");
	strcpy(str2.terminal_name, "강남");
	select_manage_menu(str1, str2);
	
}

void test_caleasd(void)
{
	Date d;
	while (1)
	{
		d = select_day();
		gotoxy(0, 53);
		printf("%d  %d  %d", d.year, d.month, d.day);
		Sleep(500);
	}
}

void test_time(void)
{
	Terminal start = { "청주" }, arrival = { "강남" };
	Date start_day = { 2023,11,26 };
	select_time(start, arrival, start_day);
}

void test4(void)
{
	DataMember d;
	strcpy(d.id, "id1234");
	strcpy(d.pw, "pw1234");
	strcpy(d.member.name, "이홍구");
	strcpy(d.member.phoneNum, "010-4079-1229");
	d.member.birthday.year = 2003;
	d.member.birthday.month = 12;
	d.member.birthday.day = 29;
	update_user_pw(d);
}