#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "시외버스프로그램.h"

int check_bus_id(Bus bus)
{
	FILE* fp = fopen("버스목록.txt", "r");
	Bus temp;
	int res = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%s %s %s %d %d %d %d %d\n", temp.bus_id, temp.route.start.terminal_name, temp.route.arrival.terminal_name, &temp.route.time, &temp.startTime, &temp.grade, &temp.price, &bus.state);
		if (strcmp(bus.bus_id, temp.bus_id) == 0)
		{
			res = 1;
			break;
		}
	}
	fclose(fp);
	return res;
}

Bus create_bus(Route route, Time start_time, int grade, int price)
{
	Bus res;
	char temp[10] = "",temp2[10]="";
	int a;
	int b;

	do
	{
		strcpy(temp, "");
		strcpy(temp2, "");
		a = rand() % 9999 + 1;
		b = rand() % 99 + 1;
		_itoa(b, temp, 10);
		strcat(temp, "버");
		_itoa(a, temp2, 10);
		strcat(temp, temp2);
		strcpy(res.bus_id, temp);
	} while (check_bus_id(res) != 0);

	res.grade = grade;
	res.price = price;
	res.route = route;
	res.startTime = start_time.hour * 60 + start_time.min;
	res.state = 1;

	return res;
}

Terminal select_start_admin()
{
	char cat[11][14] = { "검색결과","전체","서울","인천/경기","강원","대전/충남","충북","광주/전남","전북","부산/경남","대구/경북" };
	Terminal str = { "출발지" };
	ui_choice_route_frame_admin(str);
	int xx = 0, yy = 0, lr = 0, i = 1, page = 1, max_page, city_num = 0, trig = 0, count = 0;
	char temp[50] = "";
	while (1)
	{
		if (i == 0)
		{
			max_page = get_max_page_search_result(temp);
			count = count_search_result(temp);
		}
		else
		{
			max_page = get_terminal_page(cat[i]);
			count = get_terminal_count(cat[i]);
		}
		ui_print_city_admin(cat[i], page, max_page, temp);
		print_page(page, max_page, 56, 36);

		click(&xx, &yy, &lr);
		if (xx >= 29 && xx <= 74 && yy == 9)
		{
			get_string(temp, strlen(temp), 50, 36, 9);
			i = 0;
			page = 1;
		}
		if (xx >= 28 && xx <= 38 && yy >= 11 && yy <= 34)
		{
			if (yy >= 11 && yy <= 12)
			{
				i = 0;
				page = 1;
			}
			if (yy >= 13 && yy <= 14)
			{
				i = 1;
				page = 1;
			}
			if (yy >= 15 && yy <= 16)
			{
				i = 2;
				page = 1;
			}
			if (yy >= 17 && yy <= 18)
			{
				i = 3;
				page = 1;
			}
			if (yy >= 19 && yy <= 20)
			{
				i = 4;
				page = 1;
			}
			if (yy >= 21 && yy <= 22)
			{
				i = 5;
				page = 1;
			}
			if (yy >= 23 && yy <= 24)
			{
				i = 6;
				page = 1;
			}
			if (yy >= 25 && yy <= 26)
			{
				i = 7;
				page = 1;
			}
			if (yy >= 27 && yy <= 28)
			{
				i = 8;
				page = 1;
			}
			if (yy >= 29 && yy <= 30)
			{
				i = 9;
				page = 1;
			}
			if (yy >= 31 && yy <= 32)
			{
				i = 10;
				page = 1;
			}
			if (yy >= 33 && yy <= 34)
			{
				i = 11;
				page = 1;
			}
		}
		if (xx >= 44 && xx <= 74 && yy >= 11 && yy <= 34) // 도시 선택
		{
			if (page != max_page)
			{

				for (int j = 0; j < 12; j++)
				{
					if (yy >= 11 + j * 2 && yy <= 12 + j * 2)
					{
						trig = 1;
						city_num = j;
					}
				}

			}
			else
			{
				int b = count % 12;
				if (b == 0)
					b = 12;

				if (yy >= 11 && yy <= 12 + b * 2)
				{
					for (int j = 0; j < b; j++)
					{
						if (yy >= 11 + j * 2 && yy <= 12 + j * 2)
						{
							trig = 1;
							city_num = j;
						}
					}
				}

			}
		}
		if (xx == 63 && yy == 36) // 페이지 버튼
		{
			if (page < max_page)
				page++;
		}
		if (xx == 57 && yy == 36)
		{
			if (page > 1)
				page--;
		}
		if (trig != 0)
			break;
	}
	Terminal* citys = (Terminal*)calloc(count, sizeof(Terminal));
	get_terminal(cat[i], citys);
	Terminal res = citys[city_num + 12 * (page - 1)];
	free(citys);
	return res;
}

Terminal select_arrival_admin(Terminal start)
{
	char cat[11][14] = { "검색결과","전체","서울","인천/경기","강원","대전/충남","충북","광주/전남","전북","부산/경남","대구/경북" };
	Terminal str = { "출발지" };
	ui_choice_route_frame_admin(start);
	int xx = 0, yy = 0, lr = 0, i = 1, page = 1, max_page, city_num = 0, trig = 0, count = 0;
	char temp[50] = "";
	while (1)
	{
		if (i == 0)
		{
			max_page = get_max_page_search_result(temp);
			count = count_search_result(temp);
		}
		else
		{
			max_page = get_terminal_page(cat[i]);
			count = get_terminal_count(cat[i]);
		}
		ui_print_city_admin(cat[i], page, max_page, temp);
		print_page(page, max_page, 56, 36);

		click(&xx, &yy, &lr);
		if (xx >= 29 && xx <= 74 && yy == 9)
		{
			get_string(temp, strlen(temp), 50, 36, 9);
			i = 0;
			page = 1;
		}
		if (xx >= 28 && xx <= 38 && yy >= 11 && yy <= 34)
		{
			if (yy >= 11 && yy <= 12)
			{
				i = 0;
				page = 1;
			}
			if (yy >= 13 && yy <= 14)
			{
				i = 1;
				page = 1;
			}
			if (yy >= 15 && yy <= 16)
			{
				i = 2;
				page = 1;
			}
			if (yy >= 17 && yy <= 18)
			{
				i = 3;
				page = 1;
			}
			if (yy >= 19 && yy <= 20)
			{
				i = 4;
				page = 1;
			}
			if (yy >= 21 && yy <= 22)
			{
				i = 5;
				page = 1;
			}
			if (yy >= 23 && yy <= 24)
			{
				i = 6;
				page = 1;
			}
			if (yy >= 25 && yy <= 26)
			{
				i = 7;
				page = 1;
			}
			if (yy >= 27 && yy <= 28)
			{
				i = 8;
				page = 1;
			}
			if (yy >= 29 && yy <= 30)
			{
				i = 9;
				page = 1;
			}
			if (yy >= 31 && yy <= 32)
			{
				i = 10;
				page = 1;
			}
			if (yy >= 33 && yy <= 34)
			{
				i = 11;
				page = 1;
			}
		}
		if (xx >= 44 && xx <= 74 && yy >= 11 && yy <= 34) // 도시 선택
		{
			if (page != max_page)
			{

				for (int j = 0; j < 12; j++)
				{
					if (yy >= 11 + j * 2 && yy <= 12 + j * 2)
					{
						trig = 1;
						city_num = j;
					}
				}

			}
			else
			{
				int b = count % 12;
				if (b == 0)
					b = 12;

				if (yy >= 11 && yy <= 12 + b * 2)
				{
					for (int j = 0; j < b; j++)
					{
						if (yy >= 11 + j * 2 && yy <= 12 + j * 2)
						{
							trig = 1;
							city_num = j;
						}
					}
				}

			}
		}
		if (xx == 63 && yy == 36) // 페이지 버튼
		{
			if (page < max_page)
				page++;
		}
		if (xx == 57 && yy == 36)
		{
			if (page > 1)
				page--;
		}
		if (trig != 0)
			break;
	}
	Terminal* citys = (Terminal*)calloc(count, sizeof(Terminal));
	get_terminal(cat[i], citys);
	Terminal res = citys[city_num + 12 * (page - 1)];
	free(citys);
	return res;
}

Time select_time_admin(Terminal start, Terminal arrival)
{
	int bus_count = get_bus_count(start, arrival);
	Bus* bus_array = (Bus*)calloc(bus_count, sizeof(Bus));
	get_bus_array(start, arrival, bus_array);
	qsort(bus_array, bus_count, sizeof(Bus), compare_bus_startTime);
	int page = 1, max_page = get_bus_max_page(start, arrival), temp = 0, xx, yy, lr, temp2;
	ui_choice_time_admin(bus_array, page, max_page);
	print_page(page, max_page, 47, 45);
	int trig = 0;
	while (1)
	{
		click(&xx, &yy, &lr);
		if (((xx >= 55 && xx <= 56) || (xx >= 48 && xx <= 49)) && yy == 45)
		{
			if (xx >= 55 && xx <= 56)
			{
				if (page < max_page)
				{
					page++;
					ui_choice_time_admin(bus_array, page, max_page);
				}
			}
			if (xx >= 48 && xx <= 49)
			{
				if (page > 0)
				{
					page--;
					ui_choice_time_admin(bus_array, page, max_page);
				}
			}
		}
		if (page != max_page)
		{
			for (int i = 0; i < 6; i++)
			{
				if (xx >= 28 && xx <= 74 && yy >= 15 + i * 4 && yy <= 18 + i * 4)
				{
					temp = i;
					trig = 1;
					break;
				}
			}
		}
		else
		{
			temp2 = bus_count % 6;
			if (bus_count % 6 == 0)
			{
				temp2++;
			}
			for (int i = 0; i < temp2; i++)
			{
				if (xx >= 28 && xx <= 74 && yy >= 15 + i * 4 && yy <= 18 + i * 4)
				{
					temp = i;
					trig = 1;
					break;
				}
			}
		}
		if (trig == 1)
			break;
	}
	Time res = min_to_time(bus_array[temp + (page - 1) * 6].startTime);
	free(bus_array);
	return res;
}

int select_manage_menu(Terminal start, Terminal arrival)
{
	ui_manage_bus(start, arrival);
	int xx, yy, lr,res=0;
	while (1)
	{
		click(&xx, &yy, &lr);
		if (xx >= 28 && xx <= 45 && yy >= 9 && yy <= 14)
		{
			res = 1;
		}
		if (xx >= 57 && xx <= 74 && yy >= 9 && yy <= 14)
		{
			res = 2;
		}
		if (xx >= 28 && xx <= 45 && yy >= 17 && yy <= 22)
		{
			res = 3;
		}
		if (xx >= 57 && xx <= 74 && yy >= 17 && yy <= 22)
		{
			res = 4;
		}
		if (res != 0)
			break;
	}
	return res;
}

void update_bus2(Bus bus)
{
	int xx, yy, lr;
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
			update_bus(bus);
			message("운행이 수정 되었습니다.");
			break;
		}
		if (xx >= 50 && xx <= 69 && yy >= 26 && yy <= 28)
		{
			message("운행 수정을 취소합니다.");
			break;
		}
	}
}

int select_money_menu()
{
	ui_money_admin();
	int xx, yy, lr, res = 0;
	while (1)
	{
		click(&xx, &yy, &lr);
		if (xx >= 26 && xx <= 43 && yy >= 9 && yy <= 14)
		{
			res = 1;
		}
		if (xx >= 55 && xx <= 72 && yy >= 9 && yy <= 14)
		{
			res = 2;
		}
		if (xx >= 26 && xx <= 43 && yy >= 17 && yy <= 22)
		{
			res = 3;
		}
		if (xx >= 55 && xx <= 72 && yy >= 17 && yy <= 22)
		{
			res = 4;
		}
		if (res != 0)
			break;
	}
	return res;
}