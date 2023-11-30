#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include "시외버스프로그램.h"

enum ColorType {
	BLACK,  	//0
	DARKBLUE,	//1
	DARKGREEN,	//2
	DARKSKYBLUE,//3
	DARKRED,  	//4
	DARKPURPLE,	//5
	DARKYELLOW,	//6
	GRAY,		//7
	DARKGRAY,	//8
	BLUE,		//9
	GREEN,		//10
	SKYBLUE,	//11
	RED,		//12
	PURPLE,		//13
	YELLOW,		//14
	WHITE		//15
} COLOR;

#define WIDE 100
#define HIGH 50

void textcolor(int colorNum)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

void gotoxy(int x, int y) {
	//x, y 좌표 설정
	COORD pos = { x,y };
	//커서 이동
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void print_box(int box_x, int box_y, int x, int y)
{
	gotoxy(x, y);
	printf("┌");
	for (int i = 0; i < box_x; i++)
		printf("─");
	printf("┐");

	for (int i = 1; i <= box_y; i++)
	{
		gotoxy(x, y+i);
		printf("│");
		for (int j = 0; j < box_x; j++)
			printf(" ");
		printf("│");
	}

	gotoxy(x, y + box_y + 1);
	printf("└");
	for (int i = 0; i < box_x; i++)
		printf("─");
	printf("┘");
}

void print_box2(int box_x, int box_y, int x, int y)
{
	gotoxy(x, y);
	printf("┌");
	for (int i = 0; i < box_x; i++)
		printf("─");
	printf("┐");

	for (int i = 1; i <= box_y; i++)
	{
		gotoxy(x, y + i);
		printf("│");
		for (int j = 0; j < box_x; j++)
			printf(" ");
		printf("│");
	}

	gotoxy(x, y + box_y + 1);
	printf("├");
	for (int i = 0; i < box_x; i++)
		printf("─");
	printf("┤");
}

void print_box3(int box_x, int box_y, int x, int y)
{
	gotoxy(x, y);
	printf("├");
	for (int i = 0; i < box_x; i++)
		printf("─");
	printf("┤");

	for (int i = 1; i <= box_y; i++)
	{
		gotoxy(x, y + i);
		printf("│");
		for (int j = 0; j < box_x; j++)
			printf(" ");
		printf("│");
	}

	gotoxy(x, y + box_y + 1);
	printf("├");
	for (int i = 0; i < box_x; i++)
		printf("─");
	printf("┤");
}

void print_box4(int box_x, int box_y, int x, int y)
{
	gotoxy(x, y);
	printf("├");
	for (int i = 0; i < box_x; i++)
		printf("─");
	printf("┤");

	for (int i = 1; i <= box_y; i++)
	{
		gotoxy(x, y + i);
		printf("│");
		for (int j = 0; j < box_x; j++)
			printf(" ");
		printf("│");
	}

	gotoxy(x, y + box_y + 1);
	printf("└");
	for (int i = 0; i < box_x; i++)
		printf("─");
	printf("┤");
}

void print_box5(int box_x, int box_y, int x, int y)
{
	gotoxy(x, y);
	printf("┌");
	for (int i = 0; i < box_x; i++)
		printf("─");
	printf("┐");

	for (int i = 1; i <= box_y; i++)
	{
		gotoxy(x, y + i);
		printf("│");
		for (int j = 0; j < box_x; j++)
			printf(" ");
		printf("│");
	}

	gotoxy(x, y + box_y + 1);
	printf("└");
	for (int i = 0; i < box_x; i++)
		printf("─");
	printf("┤");
}

void print_box6(int box_x, int box_y, int x, int y)
{
	gotoxy(x, y);
	printf("├");
	for (int i = 0; i < box_x; i++)
		printf("─");
	printf("┤");

	for (int i = 1; i <= box_y; i++)
	{
		gotoxy(x, y + i);
		printf("│");
		for (int j = 0; j < box_x; j++)
			printf(" ");
		printf("│");
	}

	gotoxy(x, y + box_y + 1);
	printf("├");
	for (int i = 0; i < box_x; i++)
		printf("─");
	printf("┘");
}

void print_box7(int box_x, int box_y, int x, int y)
{
	gotoxy(x, y);
	printf("┬");
	for (int i = 0; i < box_x; i++)
		printf("─");
	printf("┤");

	for (int i = 1; i <= box_y; i++)
	{
		gotoxy(x, y + i);
		printf("│");
		for (int j = 0; j < box_x; j++)
			printf(" ");
		printf("│");
	}

	gotoxy(x, y + box_y + 1);
	printf("└");
	for (int i = 0; i < box_x; i++)
		printf("─");
	printf("┤");
}

void print_box8(int box_x, int box_y, int x, int y)
{
	gotoxy(x, y);
	printf("┬");
	for (int i = 0; i < box_x; i++)
		printf("─");
	printf("┐");

	for (int i = 1; i <= box_y; i++)
	{
		gotoxy(x, y + i);
		printf("│");
		for (int j = 0; j < box_x; j++)
			printf(" ");
		printf("│");
	}

	gotoxy(x, y + box_y + 1);
	printf("├");
	for (int i = 0; i < box_x; i++)
		printf("─");
	printf("┤");
}

void print_box9(int box_x, int box_y, int x, int y)
{
	gotoxy(x, y);
	printf("┬");
	for (int i = 0; i < box_x; i++)
		printf("─");
	printf("┐");

	for (int i = 1; i <= box_y; i++)
	{
		gotoxy(x, y + i);
		printf("│");
		for (int j = 0; j < box_x; j++)
			printf(" ");
		printf("│");
	}

	gotoxy(x, y + box_y + 1);
	printf("└");
	for (int i = 0; i < box_x; i++)
		printf("─");
	printf("┤");
}

void print_box10(int box_x, int box_y, int x, int y)
{
	gotoxy(x, y);
	printf("┬");
	for (int i = 0; i < box_x; i++)
		printf("─");
	printf("┐");

	for (int i = 1; i <= box_y; i++)
	{
		gotoxy(x, y + i);
		printf("│");
		for (int j = 0; j < box_x; j++)
			printf(" ");
		printf("│");
	}

	gotoxy(x, y + box_y + 1);
	printf("└");
	for (int i = 0; i < box_x; i++)
		printf("─");
	printf("┘");
}

void print_box11(int box_x, int box_y, int x, int y)
{
	gotoxy(x, y);
	printf("├");
	for (int i = 0; i < box_x; i++)
		printf("─");
	printf("┤");

	for (int i = 1; i <= box_y; i++)
	{
		gotoxy(x, y + i);
		printf("│");
		for (int j = 0; j < box_x; j++)
			printf(" ");
		printf("│");
	}

	gotoxy(x, y + box_y + 1);
	printf("└");
	for (int i = 0; i < box_x; i++)
		printf("─");
	printf("┘");
}

void ui_frame(void)
{
	system("cls");
	print_box(WIDE, HIGH, 0, 0);
}

void ui_first_screen(char id[], char pw[])
{
	int x = 24;
	int y = 9;
	ui_frame();

	print_box(39, 3, x + 5, 2);

	gotoxy(42, 4);
	printf("시외버스 프로그램");

	gotoxy(x, y+1);
	printf("ID : %s",id);
	print_box(39, 1, x+5, y);

	gotoxy(x, y+5);
	printf("PW : %s",pw);
	print_box(39, 1, x+5, y+4);

	print_box(11, 5, x + 48, y);
	gotoxy(x + 52, y + 3);
	printf("로그인");

	print_box(11, 1, x+5, y +8);
	gotoxy(x+4+5, y + 9);
	printf("ID찾기");

	print_box(11, 1, x + 16+3, y +8);
	gotoxy(x + 21+2, y +9);
	printf("PW찾기");

	print_box(11, 1, x + 32+1, y +8);
	gotoxy(x +36, y +9);
	printf("회원가입");

	print_box(39, 1, x+5, y +12);
	gotoxy(x + 17+3, y + 13);
	printf("비로그인 이용");

	gotoxy(0, 52);
}

void ui_sign_up()
{
	int x = 25;
	int y = 9;
	ui_frame();

	print_box(39, 3, x +4, 2);

	gotoxy(44, 4);
	printf("회 원 가 입");

	gotoxy(x, y + 1);
	printf("ID : ");
	print_box(39, 1, x + 4, y);
	print_box(9, 1, x + 4+42, y);
	gotoxy(x + 4 + 44, y+1);
	printf("중복확인");

	gotoxy(x, y + 5);
	printf("PW : ");
	print_box(39, 1, x + 4, y + 4);

	gotoxy(x-5, y + 5+4);
	printf("PW 확인 : ");
	print_box(39, 1, x + 4, y + 4+4);
	
	gotoxy(x - 2, y + 5 + 4+4);
	printf("이름 : ");
	print_box(39, 1, x + 4, y + 4 + 4+4);

	gotoxy(x - 6, y + 5 + 4 + 4 + 4);
	printf("전화번호 : ");
	print_box(39, 1, x + 4, y + 4 + 4 + 4+4);

	gotoxy(x - 6, y + 5 + 4 + 4 + 4 + 4);
	printf("생년월일 : ");
	print_box(39, 1, x + 4, y + 4 + 4 + 4+4+4);

	print_box(19, 1, x + 4, y + 4 + 4 + 4 + 4 + 4+4);
	gotoxy(x+10, y + 4 + 4 + 4 + 4 + 4+4+1);
	printf("회 원 가 입");

	print_box(19, 1, x + 4+21, y + 4 + 4 + 4 + 4 + 4 + 4);
	gotoxy(x + 12+21, y + 4 + 4 + 4 + 4 + 4 + 4+1);
	printf("취 소");

	gotoxy(0, 52);
}

void ui_massage(char msg[], int size)
{
	print_box(50, 15, 24, 14);
	gotoxy(51-(size/2), 19);
	printf("%s", msg);
	print_box(9, 1, 44, 25);
	gotoxy(48, 26);
	printf("확인");
	gotoxy(0, 52);
}

void ui_login_screen(char name[])
{
	int x = 24;
	int y = 9;
	ui_frame();
	print_box(40, 3, x + 4, 2);

	gotoxy(44, 4);
	printf("%s 회원",name);

	print_box(19, 1, x + 4, y + 4);
	gotoxy(x + 9, y + 4 + 1);
	printf("시외버스 이용");

	print_box(19, 1, x + 4 + 21, y + 4);
	gotoxy(x + 11 + 21, y + 4 + 1);
	printf("티켓 조회");

	print_box(19, 1, x + 4, y + 4+4);
	gotoxy(x + 11, y + 4+4 + 1);
	printf("이용 내역");

	print_box(19, 1, x + 4 + 21, y + 4+4);
	gotoxy(x + 11 + 21, y + 4+4 + 1);
	printf("회원 정보");

	print_box(40, 1, x + 4, y + 4 + 4+4);

	gotoxy(46, y + 4 + 4 + 4+1);
	printf("로그아웃");

	gotoxy(0, 52);
}

void ui_nonmember_screen(void)
{
	int x = 24;
	int y = 9;
	ui_frame();
	print_box(40, 3, x + 4, 2);

	gotoxy(46, 4);
	printf("비회원");

	print_box(19, 1, x + 4, y + 4);
	gotoxy(x + 10, y + 4 + 1);
	printf("시외버스 이용");

	print_box(19, 1, x + 4 + 21, y + 4);
	gotoxy(x + 12 + 21, y + 4 + 1);
	printf("티켓 조회");

	print_box(40, 1, x + 4, y + 4 + 4);
	gotoxy(46, y + 4 + 4 + 1);
	printf("로그아웃");

	gotoxy(0, 52);
}

void ui_choice_route_frame(Terminal str)
{
	char um[12][14] = { "검색결과","즐겨찾기","전체","서울","인천/경기","강원","대전/충남","충북","광주/전남","전북","부산/경남","대구/경북" };
	int x = 24;
	int y = 9;
	ui_frame();

	print_box(15, 3, x + 3, 2);
	
	gotoxy(33, 4);
	printf("%s",str.terminal_name);

	gotoxy(50, 4);
	printf("->");

	print_box(15, 3, x + 4+30, 2);

	gotoxy(64, 4);
	printf("도착지");

	print_box(46, 1, x + 3, y-1);
	gotoxy(x +5, y);
	printf("검색 : ");

	print_box(46,25,x+3,y+2);
	print_box7(30, 23, x + 19, y + 2);
	print_box2(10, 1, x + 3, y + 2);
	gotoxy(x + 5, y + 3);
	printf("%s", um[0]);
	for (int i = 1; i <= 10; i++)
	{
		print_box3(10, 1, x + 3, y + 2+i*2);
		gotoxy(x + 5, y + 3 + i * 2);
		printf("%s", um[i]);
	}
	print_box6(10, 1, x + 3, y + 24);
	gotoxy(x + 5, y + 3 + 22);
	printf("%s", um[11]);

	gotoxy(0, 52);
}

void print_favorite_state(int x, int y, Terminal terminal, char user_id[])
{
	gotoxy(x, y);
	if (check_favorites_terminal(terminal, user_id) == 1)
	{
		textcolor(YELLOW);
		printf("★");
		textcolor(WHITE);
	}
	else
	{
		textcolor(YELLOW);
		printf("☆");
		textcolor(WHITE);
	}
}

void ui_print_city(char cat[], int page, int max_page, char user_id[],char search_str[])
{
	int x = 24, y = 9, i = 0;
	int res,check=0;
	Terminal* terminals = NULL;
	if (strcmp("즐겨찾기", cat) == 0)
	{
		res = count_favorites_terminal(user_id);
		terminals = (Terminal*)calloc(res, sizeof(Terminal));
		get_favorites_terminal(user_id, terminals);
		check = 1;
	}
	else if (strcmp("검색결과", cat) == 0)
	{
		res = count_search_result(search_str);
		terminals = (Terminal*)calloc(res, sizeof(Terminal));
		get_search_result(search_str, terminals);
		check = 1;
	}
	else
	{
		res = get_terminal_count(cat);
		terminals = (Terminal*)calloc(res, sizeof(Terminal));
		get_terminal(cat, terminals);
		check = 1;
	}
	print_box9(30, 23, x + 19, y + 2);
	if (res == 0)
	{
		printf("없음");
	}
	else
	{
		if (max_page != page)
		{
			print_box8(30, 1, x + 19, y + 2);
			gotoxy(x + 24, y + 3);
			printf("%s", terminals[0 + 12 * (page - 1)].terminal_name);
			print_favorite_state(x + 24 + 22, y + 3, terminals[0 + 12 * (page - 1)], user_id);
			for (i = 1; i < 11; i++)
			{
				print_box3(30, 1, x + 19, y + 2 + i * 2);
				gotoxy(x + 24, y + 3 + i * 2);
				printf("%s", terminals[i + 12 * (page - 1)].terminal_name);
				print_favorite_state(x + 24 + 22, y + 3 + i * 2, terminals[i + 12 * (page - 1)], user_id);
			}
			print_box4(30, 1, x + 19, y + 2 + i * 2);
			gotoxy(x + 24, y + 3 + i * 2);
			printf("%s", terminals[i + 12 * (page - 1)].terminal_name);
			print_favorite_state(x + 24 + 22, y + 3 + i * 2, terminals[i + 12 * (page - 1)], user_id);
		}
		else
		{
			res = res % 12;
			if (res == 1)
			{
				print_box8(30, 1, x + 19, y + 2);
				gotoxy(x + 24, y + 3);
				printf("%s", terminals[12 * (max_page - 1)].terminal_name);
				print_favorite_state(x + 24 + 22, y + 3, terminals[0 + 12 * (page - 1)], user_id);
				
			}
			else if (res == 0)
			{
				print_box8(30, 1, x + 19, y + 2);
				gotoxy(x + 24, y + 3);
				printf("%s", terminals[0 + 12 * (page - 1)].terminal_name);
				print_favorite_state(x + 24 + 22, y + 3, terminals[0 + 12 * (page - 1)], user_id);
				for (i = 1; i < 11; i++)
				{
					print_box3(30, 1, x + 19, y + 2 + i * 2);
					gotoxy(x + 24, y + 3 + i * 2);
					printf("%s", terminals[i + 12 * (page - 1)].terminal_name);
					print_favorite_state(x + 24 + 22, y + 3 + i * 2, terminals[i + 12 * (page - 1)], user_id);
				}
				print_box4(30, 1, x + 19, y + 2 + i * 2);
				gotoxy(x + 24, y + 3 + i * 2);
				printf("%s", terminals[i + 12 * (page - 1)].terminal_name);
				print_favorite_state(x + 24 + 22, y + 3 + i * 2, terminals[i + 12 * (page - 1)], user_id);
			}
			else
			{
				print_box8(30, 1, x + 19, y + 2);
				gotoxy(x + 24, y + 3);
				printf("%s", terminals[12 * (page - 1)].terminal_name);
				print_favorite_state(x + 24 + 22, y + 3, terminals[0 + 12 * (page - 1)], user_id);
				for (i = 1; i < res; i++)
				{
					print_box3(30, 1, x + 19, y + 2 + i * 2);
					gotoxy(x + 24, y + 3 + i * 2);
					printf("%s", terminals[i + 12 * (page - 1)].terminal_name);
					print_favorite_state(x + 24 + 22, y + 3 + i * 2, terminals[i + 12 * (page - 1)], user_id);
				}
			}
		}
	}
	if(check == 1)
	{
		free(terminals);
	}
}

void ui_print_arrival(char cat[], int page, int max_page, Terminal start, char user_id[], char search_str[])
{
	int x = 24, y = 9, i = 0, check = 0;
	int res = get_arrival_count(cat, start);
	Terminal* terminals = (Terminal*)calloc(res, sizeof(Terminal));
	get_arrival(cat, start, terminals);

	if (strcmp("즐겨찾기", cat) == 0)
	{
		res = count_favorites_arrival(start, user_id);
		terminals = (Terminal*)calloc(res, sizeof(Terminal));
		get_favorites_arrival(start, user_id, terminals);
		check = 1;
	}
	else if (strcmp("검색결과", cat) == 0)
	{
		res = count_search_arrival(search_str, start);
		terminals = (Terminal*)calloc(res, sizeof(Terminal));
		get_search_arrival(search_str, start, terminals);
		check = 1;
	}
	else
	{
		res = get_arrival_count(cat, start);
		terminals = (Terminal*)calloc(res, sizeof(Terminal));
		get_arrival(cat, start, terminals);
		check = 1;
	}

	print_box9(30, 23, x + 19, y + 2);
	if (res == 0)
	{
		printf("없음");
	}
	else
	{
		if (max_page != page)
		{
			print_box8(30, 1, x + 19, y + 2);
			gotoxy(x + 24, y + 3);
			printf("%s", terminals[+ 12 * (page - 1)].terminal_name);
			print_favorite_state(x + 24 + 22, y + 3, terminals[+ 12 * (page - 1)], user_id);
			for (i = 1; i < 11; i++)
			{
				print_box3(30, 1, x + 19, y + 2 + i * 2);
				gotoxy(x + 24, y + 3 + i * 2);
				printf("%s", terminals[i + 12 * (page - 1)].terminal_name);
				print_favorite_state(x + 24 + 22, y + 3 + i * 2, terminals[i + 12 * (page - 1)], user_id);
			}
			print_box4(30, 1, x + 19, y + 2 + i * 2);
			gotoxy(x + 24, y + 3 + i * 2);
			printf("%s", terminals[i + 12 * (page - 1)].terminal_name);
			print_favorite_state(x + 24 + 22, y + 3 + i * 2, terminals[i + 12 * (page - 1)], user_id);
		}
		else
		{
			res = res % 12;
			if (res == 1)
			{
				print_box8(30, 1, x + 19, y + 2);
				gotoxy(x + 24, y + 3);
				printf("%s", terminals[12 * (max_page - 1)].terminal_name);
				print_favorite_state(x + 24 + 22, y + 3, terminals[12 * (page - 1)], user_id);
			}
			else if (res == 0)
			{
				print_box8(30, 1, x + 19, y + 2);
				gotoxy(x + 24, y + 3);
				printf("%s", terminals[12 * (page - 1)].terminal_name);
				print_favorite_state(x + 24 + 22, y + 3, terminals[12 * (page - 1)], user_id);
				for (i = 1; i < 11; i++)
				{
					print_box3(30, 1, x + 19, y + 2 + i * 2);
					gotoxy(x + 24, y + 3 + i * 2);
					printf("%s", terminals[i + 12 * (page - 1)].terminal_name);
					print_favorite_state(x + 24 + 22, y + 3 + i * 2, terminals[i + 12 * (page - 1)], user_id);
				}
				print_box4(30, 1, x + 19, y + 2 + i * 2);
				gotoxy(x + 24, y + 3 + i * 2);
				printf("%s", terminals[i + 12 * (page - 1)].terminal_name);
				print_favorite_state(x + 24 + 22, y + 3 + i * 2, terminals[i + 12 * (page - 1)], user_id);
			}
			else
			{
				print_box8(30, 1, x + 19, y + 2);
				gotoxy(x + 24, y + 3);
				printf("%s", terminals[12 * (page - 1)].terminal_name);
				print_favorite_state(x + 24 + 22, y + 3, terminals[12 * (page - 1)], user_id);
				for (i = 1; i < res; i++)
				{
					print_box3(30, 1, x + 19, y + 2 + i * 2);
					gotoxy(x + 24, y + 3 + i * 2);
					printf("%s", terminals[i + 12 * (page - 1)].terminal_name);
					print_favorite_state(x + 24 + 22, y + 3 + i * 2, terminals[i + 12 * (page - 1)], user_id);
				}
			}
		}
	}
	if (check == 1)
	{
		free(terminals);
	}
}

void print_page(int cur_page, int max_page, int x, int y)
{
	if (max_page == 0)
	{
		gotoxy(x, y);
		printf("           ");
	}
	else if (cur_page == 1 && max_page == 1)
	{
		gotoxy(x, y);
		printf("   %d/%d   ",cur_page,max_page);
	}
	else if (cur_page == 1)
	{
		gotoxy(x, y);
		printf("   %d/%d ▶", cur_page, max_page);
	}
	else if (cur_page == max_page)
	{
		gotoxy(x, y);
		printf("◀ %d/%d   ", cur_page, max_page);
	}
	else
	{
		gotoxy(x, y);
		printf("◀ %d/%d ▶", cur_page, max_page);
	}
	gotoxy(0, 52);
}

void ui_choice_route_way_frame(int menu)
{
	int x = 24;
	int y = 9;
	char um[3][14] = { "직 행","최소 비용","최소 시간"};
	ui_frame();

	print_box(39, 3, x + 5, 2+3);

	gotoxy(43, 4+3);
	printf("직 행 / 환 승");

	print_box(46, 25, x + 3, y + 2);
	print_box10(30, 25, x + 19, y + 2);
	print_box2(15, 1, x + 3, y + 2);
	gotoxy(x + 9, y + 3);
	printf("%s", um[0]);
	
	print_box3(15, 1, x + 3, y + 2 + 2);
	gotoxy(x + 7, y + 3 + 2);
	printf("%s", um[1]);
	
	print_box3(15, 1, x + 3, y + 6);
	gotoxy(x + 7, y + 3 + 4);
	printf("%s", um[2]);

	gotoxy(55, 12);
	printf("%s", um[menu - 1]);

	gotoxy(0, 52);
}

void ui_choice_route_way(Terminal start, Terminal arrival,int menu)
{
	int x = 24, y = 9, count_transfer=0, start_num= get_terminal_num(start), arrival_num = get_terminal_num(arrival);
	int count = get_terminal_count("전체");
	int** cost = (int**)calloc(count, sizeof(int*));
	int** time = (int**)calloc(count, sizeof(int*));
	LinkedList** list1 = (LinkedList**)calloc(count, sizeof(LinkedList*));
	
	for (int i = 0; i < count; i++)
	{
		cost[i] = (int*)calloc(count, sizeof(int));
		time[i] = (int*)calloc(count, sizeof(int));
		list1[i] = (LinkedList*)calloc(count, sizeof(LinkedList));
	}

	floyd_warshall(menu, cost, time, list1);
	count_transfer = count_bus_transfer(list1[start_num][arrival_num]);
	ui_choice_route_way_frame(menu);
	
	gotoxy(46, 14);
	printf("예상 비용: %d", cost[start_num][arrival_num]);

	Time trasfer_time = min_to_time(time[start_num][arrival_num]);
	gotoxy(46, 18);
	printf("예상 시간: %d시간 %d분", trasfer_time.hour, trasfer_time.min);

	gotoxy(46, 22);
	printf("환승 횟수: %d", count_transfer);

	print_box(12, 3, 45, 32);
	gotoxy(50, 34);
	printf("선 택");

	print_box(12, 3, 59, 32);
	gotoxy(64, 34);
	printf("취 소");

	for (int i = 0; i < count; i++)
	{
		free(cost[i]);
		free(time[i]);
		//delete_node(list1[i][0].next);
		free(list1[i]);
	}

	free(cost);
	free(time);
	free(list1);
	gotoxy(0, 52);
}

void ui_calendar(Date d)
{
	ui_frame();
	int start_day = get_start_day(d.year, d.month);
	int last_day = get_last_day(d.year, d.month);
	int xx = 32;
	int yy = 19;
	int x = 25;
	int i = 0;
	time_t rawTime = time(NULL);
	struct tm* pTime = localtime(&rawTime);
	print_box(39, 3, x + 4, 2);

	gotoxy(44, 4);
	printf("날 짜 선 택");

	print_box(39, 22, x + 4, 9);
	
	if (d.year < pTime->tm_year + 1900 + 2)
	{
		gotoxy(54, 11);
		printf("▶");
	}

	if (d.year > pTime->tm_year + 1900)
	{
		gotoxy(45, 11);
		printf("◀");
	}

	gotoxy(48, 11);
	printf("%d년", d.year);

	gotoxy(49, 14);
	printf("%d월", d.month);
	
	if ((pTime->tm_year + 1900 + 2 > d.year) || (pTime->tm_year + 1900 + 2 >= d.year && pTime->tm_mon + 1 > d.month))
	{
		gotoxy(54, 14);
		printf("▶");
	}

	if ((pTime->tm_year + 1900 < d.year) || (pTime->tm_year + 1900 <= d.year && pTime->tm_mon + 1 < d.month))
	{
		gotoxy(45, 14);
		printf("◀");
	}

	gotoxy(35, 17);
	textcolor(DARKRED);
	printf("일	");
	textcolor(WHITE);
	printf("월   화   수   목   금	 ");
	textcolor(BLUE);
	printf("토");
	textcolor(WHITE);
	for (i = 0; i < start_day; i++)	//1일 시작전까지 빈칸을 출력
	{
		gotoxy(xx + 5 * start_day, yy);
		//printf("   ");
	}
	for (i = 1; i <= last_day; i++)	//마지막날짜까지 1부터 순서대로 출력
	{
		if ((start_day + i) % 7 == 1)	//빈칸포함 7번 입력하면 한칸 띄운다
		{
			if(d.year == pTime->tm_year + 1900 && d.month == pTime->tm_mon+1 && i < pTime->tm_mday)
			{
				textcolor(DARKGRAY);
				gotoxy(xx + 1, yy + 2 * (start_day + i) / 7);
				printf("%4d", i);
				textcolor(WHITE);
			}
			else
			{
				gotoxy(xx + 1, yy + 2 * (start_day + i) / 7);
				textcolor(DARKRED);
				printf("%4d", i);
				textcolor(WHITE);
			}
		}
		else
		{
			if (d.year == pTime->tm_year + 1900 && d.month == pTime->tm_mon + 1 && i < pTime->tm_mday)
			{
				textcolor(DARKGRAY);
				printf("%5d", i);
				textcolor(WHITE);
			}
			else
			{
				if ((start_day + i) % 7 == 0)
				{
					textcolor(BLUE);
					printf("%5d", i);
					textcolor(WHITE);
				}
				else
					printf("%5d", i);
			}
		}
	}
	gotoxy(0, 52);
}

void ui_choice_time_frame(Terminal start, Terminal arrival, Date start_day)
{
	ui_frame();
	int x = 24;
	int y = 9;

	print_box(15, 3, x + 3, 2);

	gotoxy(33, 4);
	printf("%s", start.terminal_name);

	gotoxy(50, 4);
	printf("->");

	print_box(15, 3, x + 4 + 30, 2);

	gotoxy(64, 4);
	printf("%s", arrival.terminal_name);

	print_box(46, 3, x + 3, y);
	print_box(46, 26, x + 3, y + 6);
	gotoxy(x + 20, y + 2);
	printf("%d년 %2d월 %2d일", start_day.year, start_day.month, start_day.day);
	for(int i=1;i<=6;i++)
	{
		if (i == 6)
			print_box11(46, 3, x + 3, y + 6 + 4 * i);
		else
			print_box3(46, 3, x + 3, y + 6 + 4 * i);
	}

	gotoxy(0, 52);
}

void ui_choice_time(Bus* bus_array, Date start_day, int page, int max_page)
{
	int x = 25;
	int y = 9;
	int i = 0, count = 0, seat_count = 0;
	Time start_time = { 0 };
	Bus bus;
	ui_choice_time_frame(bus_array[0].route.start, bus_array[0].route.arrival, start_day);
	if (page != max_page)
	{
		for (int i = 1; i <= 6; i++)
		{			
			bus = bus_array[i + 6 * (page - 1)];
			start_time = min_to_time(bus.startTime);
			seat_count = get_remain_bus_seat_count(bus.route.start, bus.route.arrival, start_day, start_time);

			gotoxy(x + 6, y + 8 + 4 * i);
			switch (bus.grade)
			{
			case 0:
				printf("%02d:%02d     %6d원        일반       %02d석", start_time.hour, start_time.min, bus.price, seat_count);
				break;
			case 1:
				printf("%02d:%02d     %6d원        우등       %02d석", start_time.hour, start_time.min, bus.price, seat_count);
				break;
			}
		}
	}
	else
	{
		count = get_bus_count(bus_array[0].route.start, bus_array[0].route.arrival);
		
		if (count % 6 == 0)
			count = 6;
		else
			count %= 6;

		for (int i = 0; i < count; i++)
		{			
			bus = bus_array[i + 6 * (page - 1)];
			start_time = min_to_time(bus.startTime);
			seat_count = get_remain_bus_seat_count(bus.route.start, bus.route.arrival, start_day, start_time);

			gotoxy(x + 6, y + 8 + 4 * i);
			switch (bus.grade)
			{
			case 0:
				printf("%02d:%02d     %6d원        일반       %02d석", start_time.hour, start_time.min, bus.price, seat_count);
				break;
			case 1:
				printf("%02d:%02d     %6d원        우등       %02d석", start_time.hour, start_time.min, bus.price, seat_count);
				break;
			}
		}
	}
}

void ui_select_bus_seat(Terminal start, Terminal arrival, Date start_day, Time start_time)
{
	int x = 24;
	int y = 9;
	
	Bus bus = get_bus_info(start, arrival, start_time);
	BusSeat* bus_seat_array = (BusSeat*)calloc(31 - 10 * bus.grade, sizeof(BusSeat));

	ui_frame();
	print_box(40, 3, x + 4, 2);

	gotoxy(46, 4);
	printf("좌석 선택");
	get_bus_seat(bus, start_day, bus_seat_array);

	switch (bus.grade)
	{
	case 0:
		for (int i = 0; i < 28; i++)
		{
			if (bus_seat_array[i].state == 1)
				textcolor(RED);
			if (i % 4 >= 2)
			{
				print_box(5, 2, 35 + 8 * (i % 4), 10 + (i / 4) * 4);
				gotoxy(38 + 8 * (i % 4), 11 + (i / 4) * 4);
				printf("%d", i + 1);
			}
			else
			{
				print_box(5, 2, 31 + 8 * (i % 4), 10 + (i / 4) * 4);
				gotoxy(34 + 8 * (i % 4), 11 + (i / 4) * 4);
				printf("%d", i + 1);
			}
			textcolor(WHITE);
		}
		break;
	case 1:
		for (int i = 0; i < 21; i++)
		{
			if (bus_seat_array[i].state == 1)
				textcolor(RED);
			if (i % 3 == 2)
			{
				print_box(5, 2, 31 + 8 * 4 - 3, 10 + (i / 3) * 4);
				gotoxy(47 + 8 * (i % 3), 11 + (i / 3) * 4);
				printf("%d", i + 1);
			}
			else
			{
				print_box(5, 2, 31 + 8 * (i % 3), 10 + (i / 3) * 4);
				gotoxy(34 + 8 * (i % 3), 11 + (i / 3) * 4);
				printf("%d", i + 1);
			}
			textcolor(WHITE);
		}
		break;
	default:
		printf("%d", bus.grade);
		break;
	}
	free(bus_seat_array);
	gotoxy(0, 52);
}

void ui_buy_tiket(Tiket tiket)
{
	int x = 24;
	int y = 9;
	char grade[2][6] = { "일반","우등" };
	ui_frame();

	print_box(40, 3, x + 4, 2);
	gotoxy(47, 4);
	printf("예 매");
	Bus bus = get_bus_info2(tiket.bus_id);
	print_box(36, 15, x + 6, 10);
	gotoxy(x + 8, 12);
	printf("      경 로     : %s -> %s", bus.route.start.terminal_name, bus.route.arrival.terminal_name);

	gotoxy(x + 8, 14);
	printf("    출발 날짜   : %4d년 %2d월 %2d일", tiket.startDay.year, tiket.startDay.month, tiket.startDay.day);

	Time start_time = min_to_time(bus.startTime);
	gotoxy(x + 8, 16);
	printf("    출발 시간   : %02d : %02d", start_time.hour, start_time.min);
	
	gotoxy(x + 8, 18);
	printf("   선택한좌석   : %d번 좌석", tiket.seatNum);

	gotoxy(x + 8, 20);
	printf("      등 급     : %s", grade[bus.grade]);

	gotoxy(x + 8, 22);
	printf("      가 격     : %d원", bus.price);

	Time cost_time = min_to_time(bus.route.time);
	gotoxy(x + 8, 24);
	printf("   걸리는시간   : %d시간 %2d분", cost_time.hour, cost_time.min);
	print_box(17, 1, x + 6, 27);
	print_box(17, 1, x + 6+19, 27);
	gotoxy(x + 13, 28);
	printf("예  매");
	gotoxy(x + 13+19, 28);
	printf("취  소");
	gotoxy(0, 52);
}

void ui_check_tiket(Tiket tiket)
{
	int x = 24;
	int y = 9;
	char grade[2][6] = { "일반","우등" };
	ui_frame();

	print_box(40, 3, x + 4, 2);
	gotoxy(45, 4);
	printf("티켓 조회");
	Bus bus = get_bus_info2(tiket.bus_id);
	print_box(36, 15, x + 6, 10);
	gotoxy(x + 8, 12);
	printf("      경 로     : %s -> %s", bus.route.start.terminal_name, bus.route.arrival.terminal_name);

	gotoxy(x + 8, 14);
	printf("    출발 날짜   : %4d년 %2d월 %2d일", tiket.startDay.year, tiket.startDay.month, tiket.startDay.day);

	Time start_time = min_to_time(bus.startTime);
	gotoxy(x + 8, 16);
	printf("    출발 시간   : %02d : %02d", start_time.hour, start_time.min);

	gotoxy(x + 8, 18);
	printf("   선택한좌석   : %d번 좌석", tiket.seatNum);

	gotoxy(x + 8, 20);
	printf("      등 급     : %s", grade[bus.grade]);

	gotoxy(x + 8, 22);
	printf("      가 격     : %d원", bus.price);

	Time cost_time = min_to_time(bus.route.time);
	gotoxy(x + 8, 24);
	printf("   걸리는시간   : %d시간 %2d분", cost_time.hour, cost_time.min);
	print_box(17, 1, x + 6, 27);
	print_box(17, 1, x + 6 + 19, 27);
	gotoxy(x + 12, 28);
	printf(" 취소하기");
	gotoxy(x + 12 + 19, 28);
	printf("  닫기");
	gotoxy(0, 52);
}

void ui_history_tiket(Tiket tiket)
{
	int x = 24;
	int y = 9;
	char grade[2][6] = { "일반","우등" };
	ui_frame();

	print_box(40, 3, x + 4, 2);
	gotoxy(45, 4);
	printf("티켓 조회");
	Bus bus = get_bus_info2(tiket.bus_id);
	print_box(36, 15, x + 6, 10);
	gotoxy(x + 8, 12);
	printf("      경 로     : %s -> %s", bus.route.start.terminal_name, bus.route.arrival.terminal_name);

	gotoxy(x + 8, 14);
	printf("    출발 날짜   : %4d년 %2d월 %2d일", tiket.startDay.year, tiket.startDay.month, tiket.startDay.day);

	Time start_time = min_to_time(bus.startTime);
	gotoxy(x + 8, 16);
	printf("    출발 시간   : %02d : %02d", start_time.hour, start_time.min);

	gotoxy(x + 8, 18);
	printf("   선택한좌석   : %d번 좌석", tiket.seatNum);

	gotoxy(x + 8, 20);
	printf("      등 급     : %s", grade[bus.grade]);

	gotoxy(x + 8, 22);
	printf("      가 격     : %d원", bus.price);

	Time cost_time = min_to_time(bus.route.time);
	gotoxy(x + 8, 24);
	printf("   걸리는시간   : %d시간 %2d분", cost_time.hour, cost_time.min);
	print_box(36, 1, x + 6, 27);
	gotoxy(x + 6 + 17, 28);
	printf("닫기");
	gotoxy(0, 52);
}

void ui_addmin_screen()
{
	int x = 24;
	int y = 9;
	ui_frame();
	print_box(40, 3, x + 4, 2);

	gotoxy(44, 4);
	printf("관리자 메뉴");

	print_box(19, 1, x + 4, y + 4);
	gotoxy(x + 9, y + 4 + 1);
	printf("버스운행 관리");

	print_box(19, 1, x + 4 + 21, y + 4);
	gotoxy(x + 11 + 21, y + 4 + 1);
	printf("매출 확인");

	print_box(19, 1, x + 4, y + 4 + 4);
	gotoxy(x + 12, y + 4 + 4 + 1);
	printf("PW 변경");


	print_box(40, 1, x + 4, y + 4 + 4 + 4);

	gotoxy(46, y + 4 + 4 + 4 + 1);
	printf("로그아웃");

	gotoxy(0, 52);
}

void ui_list_tiket(DataPerson d, int page, int max_page)
{
	int x = 24;
	int y = 9;
	ui_frame();

	print_box(40, 3, x + 4, 2);
	gotoxy(44, 4);
	printf("예매한 티켓");

	print_box(48, 23, x, y + 2);
	int res = count_tiket_array(d, 0), i = 0;
	Tiket* tiket_array = (Tiket*)calloc(res, sizeof(Tiket));
	get_tiket_array(d, tiket_array, 0);
	Bus bus;
	Time start_time;
	if(max_page != page)
	{
		print_box(48, 1, x, y + 2);
		gotoxy(x + 5, y + 3);
		bus = get_bus_info2(tiket_array[12 * (max_page - 1)].bus_id);
		start_time = min_to_time(bus.startTime);
		printf("%s -> %s %d년 %02d월 %02d일 %2d:%02d %2d번", bus.route.start.terminal_name, bus.route.arrival.terminal_name, tiket_array[12 * (max_page - 1)].startDay.year, tiket_array[12 * (max_page - 1)].startDay.month, tiket_array[12 * (max_page - 1)].startDay.day, start_time.hour, start_time.min, tiket_array[12 * (max_page - 1)].seatNum);
		for (i = 1; i < 11; i++)
		{
			print_box3(48, 1, x , y + 2 + i * 2);
			gotoxy(x + 5, y + 3 + i * 2);
			bus = get_bus_info2(tiket_array[i+12 * (max_page - 1)].bus_id);
			start_time = min_to_time(bus.startTime);
			printf("%s -> %s %d년 %02d월 %02d일 %2d:%02d %2d번", bus.route.start.terminal_name, bus.route.arrival.terminal_name, tiket_array[12 * (max_page - 1)].startDay.year, tiket_array[i+12 * (max_page - 1)].startDay.month, tiket_array[i+12 * (max_page - 1)].startDay.day, start_time.hour, start_time.min, tiket_array[i+12 * (max_page - 1)].seatNum);
		}
		bus = get_bus_info2(tiket_array[i + 12 * (max_page - 1)].bus_id);
		start_time = min_to_time(bus.startTime);
		print_box11(48, 1, x, y + 2 + i * 2);
		gotoxy(x + 5, y + 3 + i * 2);
		printf("%s -> %s %d년 %02d월 %02d일 %2d:%02d %2d번", bus.route.start.terminal_name, bus.route.arrival.terminal_name, tiket_array[12 * (max_page - 1)].startDay.year, tiket_array[i + 12 * (max_page - 1)].startDay.month, tiket_array[i + 12 * (max_page - 1)].startDay.day, start_time.hour, start_time.min, tiket_array[i + 12 * (max_page - 1)].seatNum);
		gotoxy(0, 52);
	}
	else
	{
		res = res % 12;
		if (res == 1)
		{
			print_box(48, 1, x, y + 2 + i * 2);
			gotoxy(x + 5, y + 3);
			bus = get_bus_info2(tiket_array[12 * (max_page - 1)].bus_id);
			start_time = min_to_time(bus.startTime);
			printf("%s -> %s %d년 %02d월 %02d일 %2d:%02d %2d번", bus.route.start.terminal_name, bus.route.arrival.terminal_name, tiket_array[12 * (max_page - 1)].startDay.year, tiket_array[12 * (max_page - 1)].startDay.month, tiket_array[12 * (max_page - 1)].startDay.day, start_time.hour, start_time.min, tiket_array[12 * (max_page - 1)].seatNum);

		}
		else if (res == 0)
		{
			print_box(48, 1, x, y + 2 + i * 2);
			gotoxy(x + 5, y + 3);
			bus = get_bus_info2(tiket_array[12 * (max_page - 1)].bus_id);
			start_time = min_to_time(bus.startTime);
			printf("%s -> %s %d년 %02d월 %02d일 %2d:%02d %2d번", bus.route.start.terminal_name, bus.route.arrival.terminal_name, tiket_array[12 * (max_page - 1)].startDay.year, tiket_array[i + 12 * (max_page - 1)].startDay.month, tiket_array[i + 12 * (max_page - 1)].startDay.day, start_time.hour, start_time.min, tiket_array[i + 12 * (max_page - 1)].seatNum);
			for (i = 1; i < 11; i++)
			{
				print_box3(48, 1, x, y + 2 + i * 2);
				gotoxy(x + 5, y + 3 + i * 2);
				bus = get_bus_info2(tiket_array[i+12 * (max_page - 1)].bus_id);
				start_time = min_to_time(bus.startTime);
				printf("%s -> %s %d년 %02d월 %02d일 %2d:%02d %2d번", bus.route.start.terminal_name, bus.route.arrival.terminal_name, tiket_array[12 * (max_page - 1)].startDay.year, tiket_array[i + 12 * (max_page - 1)].startDay.month, tiket_array[i + 12 * (max_page - 1)].startDay.day, start_time.hour, start_time.min, tiket_array[i + 12 * (max_page - 1)].seatNum);
			}
			print_box11(48, 1, x, y + 2 + i * 2);
			gotoxy(x + 5, y + 3 + i * 2);
			bus = get_bus_info2(tiket_array[i+12 * (max_page - 1)].bus_id);
			start_time = min_to_time(bus.startTime);
			printf("%s -> %s %d년 %02d월 %02d일 %2d:%02d %2d번", bus.route.start.terminal_name, bus.route.arrival.terminal_name, tiket_array[12 * (max_page - 1)].startDay.year, tiket_array[i + 12 * (max_page - 1)].startDay.month, tiket_array[i + 12 * (max_page - 1)].startDay.day, start_time.hour, start_time.min, tiket_array[i + 12 * (max_page - 1)].seatNum);
		}
		else
		{
			print_box(48, 1, x, y + 2 + i * 2);
			gotoxy(x + 5, y + 3);
			bus = get_bus_info2(tiket_array[12 * (max_page - 1)].bus_id);
			start_time = min_to_time(bus.startTime);
			printf("%s -> %s %d년 %02d월 %02d일 %2d:%02d %2d번", bus.route.start.terminal_name, bus.route.arrival.terminal_name, tiket_array[12 * (max_page - 1)].startDay.year, tiket_array[i + 12 * (max_page - 1)].startDay.month, tiket_array[i + 12 * (max_page - 1)].startDay.day, start_time.hour, start_time.min, tiket_array[i + 12 * (max_page - 1)].seatNum);
			for (i = 1; i < res; i++)
			{
				print_box3(48, 1, x, y + 2 + i * 2);
				gotoxy(x + 5, y + 3 + i * 2);
				bus = get_bus_info2(tiket_array[i + 12 * (max_page - 1)].bus_id);
				start_time = min_to_time(bus.startTime);
				printf("%s -> %s %d년 %02d월 %02d일 %2d:%02d %2d번", bus.route.start.terminal_name, bus.route.arrival.terminal_name, tiket_array[12 * (max_page - 1)].startDay.year, tiket_array[i + 12 * (max_page - 1)].startDay.month, tiket_array[i + 12 * (max_page - 1)].startDay.day, start_time.hour, start_time.min, tiket_array[i + 12 * (max_page - 1)].seatNum);
			}
		}
	}
	free(tiket_array);
	gotoxy(0, 52);
}

void ui_update_user_data()
{
	int x = 24;
	int y = 9;
	ui_frame();

	print_box(40, 3, x + 4, 2);
	gotoxy(44, 4);
	printf("정보 수정");

	print_box(40, 10, x + 4, y + 2);
	gotoxy(32, y + 4);
	printf("  이름   : ");
	print_box(23, 1, 36 + 7, y + 3);
	gotoxy(32, y + 7);
	printf("생년월일 : ");
	print_box(23, 1, 36 + 7, y + 6);
	gotoxy(32, y + 10);
	printf("전화번호 : ");
	print_box(23, 1, 36 + 7, y + 9);

	print_box(19, 1, x + 4, y + 14);
	gotoxy(x + 11, y + 15);
	printf("수정 완료");
	print_box(19, 1, x + 4+21, y + 14);
	gotoxy(x + 11+21, y + 15);
	printf("  취소");
	gotoxy(0, 52);
}

void ui_update_user_pw()
{
	int x = 24;
	int y = 9;
	ui_frame();

	print_box(40, 3, x + 4, 2);
	gotoxy(46, 4);
	printf("PW 변경");

	print_box(40, 10, x + 4, y + 2);

	gotoxy(31, y + 5);
	printf("현재 비밀번호 : ");
	print_box(20, 1, 36 + 10, y + 4);
	gotoxy(31, y + 9);
	printf("신규 비밀번호 : ");
	print_box(20, 1, 36 + 10, y + 8);

	print_box(19, 1, x + 4, y + 14);
	gotoxy(x + 11, y + 15);
	printf("수정 완료");
	print_box(19, 1, x + 4 + 21, y + 14);
	gotoxy(x + 11 + 21, y + 15);
	printf("  취소");

	gotoxy(0, 52);
}

void ui_mem_info(DataPerson d)
{
	int x = 24;
	int y = 9;
	ui_frame();

	print_box(40, 3, x + 4, 2);
	gotoxy(44, 4);
	printf("예매한 티켓");

	print_box(40, 10, x+4, y + 2);
	gotoxy(36, y + 5);
	printf("  이름   : %s", d.name);
	gotoxy(36, y + 7);
	printf("생년월일 : %d년 %d월 %d일", d.birthday.year, d.birthday.month, d.birthday.day);
	gotoxy(36, y + 9);
	printf("전화번호 : %s", d.phoneNum);
	print_box(12, 3, x + 4, y+14);
	gotoxy(x + 7, y + 16);
	printf("정보 수정");
	print_box(12, 3, x + 4+14, y + 14);
	gotoxy(x + 8+14, y + 16);
	printf("PW 변경");
	print_box(12, 3, x + 4+14+14, y + 14);
	gotoxy(x + 9 + 14+14, y + 16);
	printf("닫 기");
	gotoxy(0, 52);
}

void ui_print_city_admin(char cat[], int page, int max_page, char search_str[])
{
	int x = 24, y = 9, i = 0;
	int res, check = 0;
	Terminal* terminals = NULL;
	if (strcmp("검색결과", cat) == 0)
	{
		res = count_search_result(search_str);
		terminals = (Terminal*)calloc(res, sizeof(Terminal));
		get_search_result(search_str, terminals);
		check = 1;
	}
	else
	{
		res = get_terminal_count(cat);
		terminals = (Terminal*)calloc(res, sizeof(Terminal));
		get_terminal(cat, terminals);
		check = 1;
	}
	print_box9(30, 23, x + 19, y + 2);
	if (res == 0)
	{
		printf("없음");
	}
	else
	{
		if (max_page != page)
		{
			print_box8(30, 1, x + 19, y + 2);
			gotoxy(x + 24, y + 3);
			printf("%s", terminals[0 + 12 * (page - 1)].terminal_name);
			for (i = 1; i < 11; i++)
			{
				print_box3(30, 1, x + 19, y + 2 + i * 2);
				gotoxy(x + 24, y + 3 + i * 2);
				printf("%s", terminals[i + 12 * (page - 1)].terminal_name);
				
			}
			print_box4(30, 1, x + 19, y + 2 + i * 2);
			gotoxy(x + 24, y + 3 + i * 2);
			printf("%s", terminals[i + 12 * (page - 1)].terminal_name);

		}
		else
		{
			res = res % 12;
			if (res == 1)
			{
				print_box8(30, 1, x + 19, y + 2);
				gotoxy(x + 24, y + 3);
				printf("%s", terminals[12 * (max_page - 1)].terminal_name);
			

			}
			else if (res == 0)
			{
				print_box8(30, 1, x + 19, y + 2);
				gotoxy(x + 24, y + 3);
				printf("%s", terminals[0 + 12 * (page - 1)].terminal_name);
				for (i = 1; i < 11; i++)
				{
					print_box3(30, 1, x + 19, y + 2 + i * 2);
					gotoxy(x + 24, y + 3 + i * 2);
					printf("%s", terminals[i + 12 * (page - 1)].terminal_name);
					
				}
				print_box4(30, 1, x + 19, y + 2 + i * 2);
				gotoxy(x + 24, y + 3 + i * 2);
				printf("%s", terminals[i + 12 * (page - 1)].terminal_name);
			}
			else
			{
				print_box8(30, 1, x + 19, y + 2);
				gotoxy(x + 24, y + 3);
				printf("%s", terminals[12 * (page - 1)].terminal_name);
				
				for (i = 1; i < res; i++)
				{
					print_box3(30, 1, x + 19, y + 2 + i * 2);
					gotoxy(x + 24, y + 3 + i * 2);
					printf("%s", terminals[i + 12 * (page - 1)].terminal_name);
					
				}
			}
		}
	}
	if (check == 1)
	{
		free(terminals);
	}
}

void ui_print_arrival_admin(char cat[], int page, int max_page, Terminal start, char search_str[])
{
	int x = 24, y = 9, i = 0, check = 0;
	int res = get_arrival_count(cat, start);
	Terminal* terminals = (Terminal*)calloc(res, sizeof(Terminal));
	get_arrival(cat, start, terminals);

	if (strcmp("검색결과", cat) == 0)
	{
		res = count_search_arrival(search_str, start);
		terminals = (Terminal*)calloc(res, sizeof(Terminal));
		get_search_arrival(search_str, start, terminals);
		check = 1;
	}
	else
	{
		res = get_arrival_count(cat, start);
		terminals = (Terminal*)calloc(res, sizeof(Terminal));
		get_arrival(cat, start, terminals);
		check = 1;
	}

	print_box9(30, 23, x + 19, y + 2);
	if (res == 0)
	{
		printf("없음");
	}
	else
	{
		if (max_page != page)
		{
			print_box8(30, 1, x + 19, y + 2);
			gotoxy(x + 24, y + 3);
			printf("%s", terminals[+12 * (page - 1)].terminal_name);
			for (i = 1; i < 11; i++)
			{
				print_box3(30, 1, x + 19, y + 2 + i * 2);
				gotoxy(x + 24, y + 3 + i * 2);
				printf("%s", terminals[i + 12 * (page - 1)].terminal_name);
			}
			print_box4(30, 1, x + 19, y + 2 + i * 2);
			gotoxy(x + 24, y + 3 + i * 2);
			printf("%s", terminals[i + 12 * (page - 1)].terminal_name);
		}
		else
		{
			res = res % 12;
			if (res == 1)
			{
				print_box8(30, 1, x + 19, y + 2);
				gotoxy(x + 24, y + 3);
				printf("%s", terminals[12 * (max_page - 1)].terminal_name);
			}
			else if (res == 0)
			{
				print_box8(30, 1, x + 19, y + 2);
				gotoxy(x + 24, y + 3);
				printf("%s", terminals[12 * (page - 1)].terminal_name);
				for (i = 1; i < 11; i++)
				{
					print_box3(30, 1, x + 19, y + 2 + i * 2);
					gotoxy(x + 24, y + 3 + i * 2);
					printf("%s", terminals[i + 12 * (page - 1)].terminal_name);
				}
				print_box4(30, 1, x + 19, y + 2 + i * 2);
				gotoxy(x + 24, y + 3 + i * 2);
				printf("%s", terminals[i + 12 * (page - 1)].terminal_name);
			}
			else
			{
				print_box8(30, 1, x + 19, y + 2);
				gotoxy(x + 24, y + 3);
				printf("%s", terminals[12 * (page - 1)].terminal_name);
				for (i = 1; i < res; i++)
				{
					print_box3(30, 1, x + 19, y + 2 + i * 2);
					gotoxy(x + 24, y + 3 + i * 2);
					printf("%s", terminals[i + 12 * (page - 1)].terminal_name);
				}
			}
		}
	}
	if (check == 1)
	{
		free(terminals);
	}
}

void ui_choice_time_frame_admin(Terminal start, Terminal arrival)
{
	ui_frame();
	int x = 24;
	int y = 9;

	print_box(15, 3, x + 3, 2);

	gotoxy(33, 4);
	printf("%s", start.terminal_name);

	gotoxy(50, 4);
	printf("->");

	print_box(15, 3, x + 4 + 30, 2);

	gotoxy(64, 4);
	printf("%s", arrival.terminal_name);

	print_box(46, 26, x + 3, y);

	for (int i = 1; i <= 6; i++)
	{
		if (i == 6)
			print_box11(46, 3, x + 3, y + 4 * i);
		else
			print_box3(46, 3, x + 3, y + 4 * i);
	}

	gotoxy(0, 52);
}

void ui_choice_time_admin(Bus* bus_array, int page, int max_page)
{
	int x = 25;
	int y = 9;
	int i = 0, count = 0, seat_count = 0;
	Time start_time = { 0 };
	Bus bus;
	ui_choice_time_frame_admin(bus_array[0].route.start, bus_array[0].route.arrival);
	if (page != max_page)
	{
		for (int i = 1; i <= 6; i++)
		{
			bus = bus_array[i + 6 * (page - 1)];
			start_time = min_to_time(bus.startTime);
			seat_count = 31 - bus.grade * 10;

			gotoxy(x + 6, y + 8 + 4 * i);
			switch (bus.grade)
			{
			case 0:
				printf("%02d:%02d     %6d원        일반       %02d석", start_time.hour, start_time.min, bus.price, seat_count);
				break;
			case 1:
				printf("%02d:%02d     %6d원        우등       %02d석", start_time.hour, start_time.min, bus.price, seat_count);
				break;
			}
		}
	}
	else
	{
		count = get_bus_count(bus_array[0].route.start, bus_array[0].route.arrival);

		if (count % 6 == 0)
			count = 6;
		else
			count %= 6;

		for (int i = 0; i < count; i++)
		{
			bus = bus_array[i + 6 * (page - 1)];
			start_time = min_to_time(bus.startTime);
			seat_count = 31 - bus.grade * 10;

			gotoxy(x + 6, y + 8 + 4 * i);
			switch (bus.grade)
			{
			case 0:
				printf("%02d:%02d     %6d원        일반       %02d석", start_time.hour, start_time.min, bus.price, seat_count);
				break;
			case 1:
				printf("%02d:%02d     %6d원        우등       %02d석", start_time.hour, start_time.min, bus.price, seat_count);
				break;
			}
		}
	}
}

void ui_manage_bus(Terminal start, Terminal arrival)
{
	ui_frame();
	int x = 24;
	int y = 9;

	print_box(15, 3, x + 3, 2);

	gotoxy(33, 4);
	printf("%s", start.terminal_name);

	gotoxy(50, 4);
	printf("->");

	print_box(15, 3, x + 4 + 30, 2);

	gotoxy(64, 4);
	printf("%s", arrival.terminal_name);

	print_box(17, 5, x + 3, y);
	gotoxy(x + 6, y + 3);
	printf("버스 운행 추가");

	print_box(17, 5, x + 2 + 15 + 15, y);
	gotoxy(x + 5 + 15 + 15, y + 3);
	printf("버스 운행 수정");

	print_box(17, 5, x + 3, y + 6 + 2);
	gotoxy(x + 6, y + 3 + 6 + 2);
	printf("버스 운행 삭제");

	print_box(17, 5, x + 2 + 15 + 15, y + 6 + 2);
	gotoxy(x + 5 + 15 + 15, y + 3 + 6 + 2);
	printf("    나가기");

	gotoxy(0, 52);
}

void ui_delete_bus(Bus bus)
{
	int x = 24;
	int y = 9;
	char grade[2][6] = { "일반","우등" };
	ui_frame();

	print_box(40, 3, x + 4, 2);
	gotoxy(45, 4);
	printf("운행 삭제");
	
	print_box(36, 15, x + 6, 10);
	gotoxy(x + 8, 12);
	printf("      경 로     : %s -> %s", bus.route.start.terminal_name, bus.route.arrival.terminal_name);

	Time start_time = min_to_time(bus.startTime);
	gotoxy(x + 8, 14);
	printf("    출발 시간   : %02d : %02d", start_time.hour, start_time.min);

	
	gotoxy(x + 8, 16);
	printf("      등 급     : %s", grade[bus.grade]);

	gotoxy(x + 8, 18);
	printf("      가 격     : %d원", bus.price);

	Time cost_time = min_to_time(bus.route.time);
	gotoxy(x + 8, 20);
	printf("   걸리는시간   : %d시간 %2d분", cost_time.hour, cost_time.min);
	
	print_box(17, 1, x + 6, 27);
	print_box(17, 1, x + 6 + 19, 27);
	gotoxy(x + 12, 28);
	printf(" 삭제하기");
	gotoxy(x + 12 + 19, 28);
	printf("  닫기");
	gotoxy(0, 52);
}

void ui_update_bus(Bus bus)
{
	int x = 24;
	int y = 9;
	char grade[2][6] = { "일반","우등" };
	ui_frame();

	print_box(40, 3, x + 4, 2);
	gotoxy(45, 4);
	printf("운행 삭제");

	print_box(36, 15, x + 6, 10);
	gotoxy(x + 8, 12);
	printf("      경 로     : %s -> %s", bus.route.start.terminal_name, bus.route.arrival.terminal_name);

	Time start_time = min_to_time(bus.startTime);
	gotoxy(x + 8, 14);
	printf("    출발 시간   : %02d : %02d", start_time.hour, start_time.min);


	gotoxy(x + 8, 16);
	printf("      등 급     : %s", grade[bus.grade]);

	gotoxy(x + 8, 18);
	printf("      가 격     : %d원", bus.price);

	Time cost_time = min_to_time(bus.route.time);
	gotoxy(x + 8, 20);
	printf("   걸리는시간   : %d시간 %2d분", cost_time.hour, cost_time.min);

	print_box(17, 1, x + 6, 27);
	print_box(17, 1, x + 6 + 19, 27);
	gotoxy(x + 12, 28);
	printf(" 수정하기");
	gotoxy(x + 12 + 19, 28);
	printf("  닫기");
	gotoxy(0, 52);
}

void ui_add_bus(Terminal start, Terminal arrival)
{
	ui_frame();
	int x = 24;
	int y = 9;
	print_box(15, 3, x + 3, 2);

	gotoxy(33, 4);
	printf("%s", start.terminal_name);

	gotoxy(50, 4);
	printf("->");

	print_box(15, 3, x + 4 + 30, 2);

	gotoxy(64, 4);
	printf("%s", arrival.terminal_name);

	print_box(40, 13, x + 4, y + 2);
	gotoxy(31, y + 4);
	printf(" 출발 시간 : ");
	print_box(23, 1, 36 + 7, y + 3);
	gotoxy(31, y + 7);
	printf(" 버스 등급 : ");
	print_box(23, 1, 36 + 7, y + 6);
	
	gotoxy(31, y + 10);
	printf(" 버스 가격 : ");
	print_box(23, 1, 36 + 7, y + 9);

	gotoxy(31, y + 13);
	printf("걸리는시간 : ");
	print_box(23, 1, 36 + 7, y + 12);

	print_box(19, 1, x + 4, y + 17);
	gotoxy(x + 11, y + 18);
	printf(" 운행추가");
	print_box(19, 1, x + 4 + 21, y + 17);
	gotoxy(x + 11 + 21, y + 18);
	printf("  취소");
	gotoxy(0, 52);
}

void ui_money_admin()
{
	ui_frame();
	int x = 24;
	int y = 9;

	print_box(40, 3, x + 4, 2);
	gotoxy(46, 4);
	printf("매출 확인");

	print_box(17, 5, x + 1, y);
	gotoxy(x + 5, y + 3);
	printf("연 매출 출력");

	print_box(17, 5, x  + 15 + 15, y);
	gotoxy(x + 4 + 15 + 15, y + 3);
	printf("월 매출 출력");

	print_box(17, 5, x + 1, y + 6 + 2);
	gotoxy(x + 5, y + 3 + 6 + 2);
	printf("일 매출 출력");

	print_box(17, 5, x  + 15 + 15, y + 6 + 2);
	gotoxy(x + 3 + 15 + 15, y + 3 + 6 + 2);
	printf("    나가기");

	gotoxy(0, 52);
}

void ui_choice_route_frame_admin(Terminal str)
{
	char um[11][14] = { "검색결과","전체","서울","인천/경기","강원","대전/충남","충북","광주/전남","전북","부산/경남","대구/경북" };
	int x = 24;
	int y = 9;
	ui_frame();

	print_box(15, 3, x + 3, 2);

	gotoxy(33, 4);
	printf("%s", str.terminal_name);

	gotoxy(50, 4);
	printf("->");

	print_box(15, 3, x + 4 + 30, 2);

	gotoxy(64, 4);
	printf("도착지");

	print_box(46, 1, x + 3, y - 1);
	gotoxy(x + 5, y);
	printf("검색 : ");

	print_box(46, 25, x + 3, y + 2);
	print_box7(30, 23, x + 19, y + 2);
	print_box2(10, 1, x + 3, y + 2);
	gotoxy(x + 5, y + 3);
	printf("%s", um[0]);
	for (int i = 1; i <= 9; i++)
	{
		print_box3(10, 1, x + 3, y + 2 + i * 2);
		gotoxy(x + 5, y + 3 + i * 2);
		printf("%s", um[i]);
	}
	print_box6(10, 1, x + 3, y + 22);
	gotoxy(x + 5, y + 3 + 20);
	printf("%s", um[10]);

	gotoxy(0, 52);
}