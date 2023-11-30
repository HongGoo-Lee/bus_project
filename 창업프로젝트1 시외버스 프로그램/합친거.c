#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "시외버스프로그램.h"

DataMember get_member(char id[]);

void menu_1(void)	// 맨 처음화면
{
	int x = 24, y = 9, xx, yy, lr,check=0;
	char id[20] = { 0 }, pw[20] = { 0 };
	while (1)
	{
		if (check == 0)
		{
			ui_first_screen(id, pw);
			check = 1;
		}
		click(&xx, &yy, &lr);
		if (lr == 1)
		{
			if (yy >= 9 && yy <= 10 && xx >= 30 && xx <= 67)//id 입력
			{
				print_box(39, 1, x + 5, y);
				//gotoxy(31, 10);
				get_string(id, strlen(id), 20, 31, 10);
				//scanf("%s", id);
			}
			if (yy >= 13 && yy <= 14 && xx >= 30 && xx <= 67)//pw 입력
			{
				print_box(39, 1, x + 5, y+4);
				//gotoxy(31, 14);
				get_string_secret(pw, strlen(pw), 20, 31, 14);
				//scanf("%s", pw);
			}
			if (yy >= 10 && yy <= 14 && xx >= 73 && xx <= 82) // 로그인 버튼 클릭
			{
				printf("로그인 호출");
				int state = login(id, pw);
				switch (state)
				{
				case 0:
					message("ID가 없습니다.");
					//printf("id가 없음");
					case 1:
						menu_user(id,pw); // 로그인 성공
						strcpy(id, "");
						strcpy(pw, "");
						break;
					case 2:
						message("비밀번호가 틀립니다.");
						//printf("비밀번호가 다름");
						break;
					case 3:
						menu_admin();
						break;
					default:
						message("알 수 없는 오류가 발생했습니다.");
						//printf("이 무슨 오류임");
						break;
				}
				check = 0;
			}
			if (yy == 18 && xx >= 30 && xx <= 39) // id찾기 버튼 클릭
			{
				printf("id찾기 호출");
			}
			if (yy == 18 && xx >= 44 && xx <= 53) // pw찾기 버튼 클릭
			{
				printf("pw찾기 호출");
			}
			if (yy == 18 && xx >= 58 && xx <= 67) // 회원가입 버튼 클릭
			{
				menu_sign_up();
				check = 0;
			}
			if (xx >= 30 && xx <= 69 && yy >= 21 && yy <= 23)
			{
				menu_non_user();
				check = 0;
			}
		}
	}
}

void menu_non_user()
{
	int xx, yy, lr;
	int x = 24;
	int y = 9;
	ui_nonmember_screen();
	while (1)
	{
		click(&xx, &yy, &lr);
		if (xx >= x + 5 && xx <= x + 5 + 39 && yy == y + 4 + 4 + 1)
		{
			break;
		}
	}
}

void menu_user(char id[], char pw[])	// 회원 화면
{
	DataMember mem = get_member(id);

	int x, y, lr, check = 0;
	while (1)
	{
		if (check == 0)
		{
			ui_login_screen(mem.member.name);
			check = 1;
		}
		click(&x, &y, &lr);
		if (lr == 1)
		{
			if (x >= 28 && x < 49 && y >= 13 && y <= 16) // 티켓구매 이용 버튼 클릭
			{
				menu_buy_tiket(id, pw);
				check = 0;
			}
			if (x >= 28+21 && x <= 69 && y >= 13 && y <= 16) // 티켓조회 버튼 클릭
			{
				menu_check_tiket(mem.member);
				check = 0;
			}
			if (x >= 28 && x < 49 && y >= 17 && y <= 19) // 이용내역 버튼 클릭
			{
				menu_history_tiket(mem.member);
				check = 0;
			}
			if (x >= 50 && x <= 69 && y >= 17 && y <= 19) // 회원정보 버튼 클릭
			{
				menu_mem_info(mem);
				check = 0;
			}
			if (x >= 29 && x <= 69 && y>= 21 && y<= 23) // 로그아웃 버튼 클릭
			{
				break;
			}
		}
	}
}

void menu_buy_tiket(char id[], char pw[])
{
	Terminal start, arrival;
	start = select_start(id);
	arrival = select_arrival(start, id);

	int menu = select_route_way(start, arrival);
	int start_num = get_terminal_num(start), arrival_num = get_terminal_num(arrival);
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
	int count_transfer = count_bus_transfer(list1[start_num][arrival_num]);

	switch (menu)
	{
	case 0:
		// 구매 취소
		message("예매를 취소 하셨습니다.");
		break;
	case 1:
		// 직행 구매
		buy_tiket(id, pw, start, arrival);
		break;
	case 2:
	case 3:
		// 환승 구매
		buy_transfer_tiket(id, pw, list1[start_num][arrival_num], count_transfer);
		break;
	default:
		break;
	}
	for (int i = 0; i < count; i++)
	{
		free(cost[i]);
		free(time[i]);
		free(list1[i]);
	}
	free(cost);
	free(time);
	free(list1);
}

void menu_check_tiket(DataPerson d)
{
	Tiket tiket = select_tiket(d,0);
	int xx, yy, lr;
	ui_check_tiket(tiket);
	while (1)
	{
		click(&xx, &yy, &lr);
		if (xx >= 31 && xx <= 48 && yy >= 27 && yy <= 28)
		{
			delete_tiket(tiket);
			message("예매를 취소하셨습니다.");
			break;
		}
		if (xx >= 50 && xx <= 67 && yy >= 27 && yy <= 28)
		{
			break;
		}
	}
}

void menu_history_tiket(DataPerson d)
{
	Tiket tiket = select_tiket(d, 3);
	int xx, yy, lr;
	ui_history_tiket(tiket);
	while (1)
	{
		click(&xx, &yy, &lr);
		if (xx >= 31 && xx <= 67 && yy >= 27 && yy <= 28)
		{
			break;
		}
	}
}

void menu_mem_info(DataMember d)
{
	int xx, yy, lr;
	ui_mem_info(d.member);
	while (1)
	{
		click(&xx, &yy, &lr);
		if (xx >= 29 && xx <= 40 && yy >= 23 && yy <= 26)
		{
			update_user_data(d);
			break;
		}
		if (xx >= 43 && xx <= 55 && yy >= 23 && yy <= 26)
		{
			update_user_pw(d);
			break;
		}
		if (xx >= 57 && xx <= 69 && yy >= 23 && yy <= 26)
		{
			break;
		}
	}
}

void menu_admin(void)
{
	int xx, yy, lr,check=0;
	//ui_addmin_screen();
	while (1)
	{
		if (check == 0)
		{
			ui_addmin_screen();
			check = 1;
		}
		click(&xx, &yy, &lr);
		if (lr == 1)
		{
			if (xx >= 28 && xx < 49 && yy >= 13 && yy <= 16) // 버스운행 관리 버튼 클릭
			{
				menu_manage_bus();
				check = 0;
			}
			if (xx >= 28 + 21 && xx <= 69 && yy >= 13 && yy <= 16) // 매출확인 버튼 클릭
			{
				check = 0;
			}
			if (xx >= 28 && xx < 49 && yy >= 17 && yy <= 19) // pw변경 버튼 클릭
			{
				check = 0;
			}
			if (xx >= 29 && xx <= 69 && yy >= 21 && yy <= 23) // 로그아웃 버튼 클릭
			{
				break;
			}
		}
	}
}

void menu_delete_bus(Terminal start, Terminal arrival)
{
	int xx, yy, lr;
	Time time = select_time_admin(start, arrival);
	Bus bus = get_bus_info(start, arrival, time);
	ui_delete_bus(bus);
	while(1)
	{
		click(&xx, &yy, &lr);
		if (xx >= 31 && xx <= 48 && yy >= 27 && yy <= 28)
		{
			delete_bus(bus);
			message("운행을 삭제하셨습니다.");
			break;
		}
		if (xx >= 50 && xx <= 67 && yy >= 27 && yy <= 28)
		{
			break;
		}
	}
}

void menu_update_bus(Terminal start, Terminal arrival)
{
	int xx, yy, lr;
	Time time = select_time_admin(start, arrival);
	Bus bus = get_bus_info(start, arrival, time);
	ui_update_bus(bus);
	while (1)
	{
		click(&xx, &yy, &lr);
		if (xx >= 31 && xx <= 48 && yy >= 27 && yy <= 28)
		{
			update_bus2(bus);
			break;
		}
		if (xx >= 50 && xx <= 67 && yy >= 27 && yy <= 28)
		{
			break;
		}
	}
}

void menu_add_bus(Terminal start, Terminal arrival)
{
	int xx, yy, lr;
	Bus bus;
	bus.route.start = start;
	bus.route.arrival = arrival;
	Time start_time;
	ui_add_bus(start, arrival);
	while (1)
	{
		click(&xx, &yy, &lr);
		if (xx >= 44 && xx <= 66 && yy == 13)
		{
			gotoxy(46, 13);
			scanf("%d", &bus.startTime);
		}
		if (xx >= 44 && xx <= 66 && yy == 16)
		{
			gotoxy(46, 16);
			scanf("%d", &bus.grade);
		}
		if (xx >= 44 && xx <= 66 && yy == 19)
		{
			gotoxy(46, 19);
			scanf("%d", &bus.price);
		}
		if (xx >= 44 && xx <= 66 && yy == 22)
		{
			gotoxy(46, 22);
			scanf("%d", &bus.route.time);
		}
		if (xx >= 29 && xx <= 47 && yy >= 26 && yy <= 28)
		{
			start_time = min_to_time(bus.startTime);
			bus = create_bus(bus.route, start_time, bus.grade, bus.price);
			add_bus(bus);
			message("운행이 추가 되었습니다.");
			break;
		}
		if (xx >= 50 && xx <= 69 && yy >= 26 && yy <= 28)
		{
			message("운행 추가를 취소합니다.");
			break;
		}
	}
}

void menu_manage_bus(void)
{
	Terminal start = select_start_admin();
	Terminal arrival = select_arrival_admin(start);
	int menu = select_manage_menu(start, arrival);
	Bus bus;
	Time time;
	switch (menu)
	{
	case 1:
		menu_add_bus(start, arrival);
		break;
	case 2:
		menu_update_bus(start, arrival);
		break;
	case 3:
		menu_delete_bus(start, arrival);
		break;
	case 4:
		break;
	default:
		break;
	}
	
}

void menu_money(void)
{
	int menu = select_money_menu();
	switch (menu)
	{
	case 1:
		//menu_add_bus(start, arrival);
		break;
	case 2:
		//menu_update_bus(start, arrival);
		break;
	case 3:
		//menu_delete_bus(start, arrival);
		break;
	case 4:
		break;
	default:
		break;
	}
}