#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include "시외버스프로그램.h"
#define INF 99999

//1=있음,0=없음
int check_member(DataMember member)
{
	int size_member = get_member_size();
	DataMember* members = (DataMember*)calloc(size_member, sizeof(DataMember));
	read_file_member(members, size_member);

	for (int i = 0; i < size_member; i++)
	{
		if (strcmp(member.id, members[i].id) == 0 && strcmp(member.member.phoneNum, members[i].member.phoneNum) == 0)
		{
			free(members);
			return 1; // 똑같은 회원정보가 있음
		}
	}
	free(members);
	return 0; // 똑같은 회원정보가 없음
}

//0정상 -1비정상
int check_nomarl_phoneNum(DataMember mem)
{
	char *str = strtok(mem.member.phoneNum, "-");
	if (strcmp(str, "010") != 0)
	{
		return -1;
	}
	for(int j=0;j<2;j++)
	{
		str = strtok(NULL, "-");
		if (strlen(str) != 4)
		{
			return -1;
		}
		for (int i = 0; i < 4; i++)
		{
			if (str[i] < 48 || str[i]>57)
				return -1;
		}
	}
	return 0;//정상
}

// month  1  2  3  4  5  6  7  8  9  10  11  12
// day    31 28 31 30 31 30 31 31 30 31  30  31

//정상이면 0 아니면 -1
int checkDate(int year, int month, int day)
{
	if ((month % 2 == 1)) //odd month 
	{
		if (month <= 7)
		{
			if (day <= 0 || day > 31) return -1;
			else if (day <= 0 || day > 30) return -1;
		}
	}
	else //even month
	{
		if (month <= 6) {
			if (month == 2)
			{
				if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) // leap year
				{
					if (day <= 0 || day > 29) return -1;
				}
				else if (day <= 0 || day > 28) return -1;

			}
			if (day <= 0 || day > 30) return -1;
		}
		else
		{
			if (day <= 0 || day > 31) return -1;
		}
	}
	return 0;
}

// 정상 0 비정상 -1
int check_nomarl_birthDay(DataMember mem)
{
	if (mem.member.birthday.year < 1923 || mem.member.birthday.year > 2023)
	{
		return -1; //비정상
	}
	else
	{
		return checkDate(mem.member.birthday.year, mem.member.birthday.month, mem.member.birthday.day);
	}
}

// 올바른 회원 정보인지 체크하는 함수
int check_nomarl_member(DataMember mem)
{
	if (check_nomarl_birthDay(mem) == 0 && check_nomarl_phoneNum(mem) == 0)
		return 0;
	else
		return -1;
}

//1=ID있음,0=ID없음
int check_id(char id[])
{
	int size_member = get_member_size();
	DataMember* members = (DataMember*)calloc(size_member, sizeof(DataMember));
	read_file_member(members, size_member);

	for (int i = 0; i < size_member; i++)
	{
		if (strcmp(id, members[i].id) == 0)
		{
			free(members);
			return 1; // 똑같은 ID가 있음
		}
	}
	free(members);
	return 0; // 똑같은 ID가 없음
}

DataMember get_member(char id[])
{
	int i, size_member = get_member_size();
	DataMember* members = (DataMember*)calloc(size_member, sizeof(DataMember));
	read_file_member(members, size_member);

	DataMember mem = { ""};

	for (i = 0; i < size_member; i++)
	{
		if (strcmp(id, members[i].id) == 0)
		{
			strcpy(mem.id, members[i].id);
			strcpy(mem.pw, members[i].pw);
			mem.member.birthday.year = members[i].member.birthday.year;
			mem.member.birthday.month = members[i].member.birthday.month;
			mem.member.birthday.day = members[i].member.birthday.day;
			strcpy(mem.member.name, members[i].member.name);
			strcpy(mem.member.phoneNum, members[i].member.phoneNum);
			break;
		}
	}
	free(members);
	return mem;
}

int login(char id[], char pw[])
{
	FILE* fp = fopen("관리자파일.txt", "r");
	char temp_id[20], temp_pw[20];
	fscanf(fp, "%s %s", temp_id, temp_pw);
	fclose(fp);
	if (strcmp(id, temp_id) == 0 && strcmp(pw, temp_pw) == 0)
	{
		return 3; // 관리자 로그인 성공
	}
	else
	{
		int size_member = get_member_size();
		DataMember* members = (DataMember*)calloc(size_member, sizeof(DataMember));
		read_file_member(members, size_member);

		for (int i = 0; i < size_member; i++)
		{
			if (strcmp(id, members[i].id) == 0)
			{
				if (strcmp(pw, members[i].pw) == 0)
				{
					free(members);
					return 1; //로그인 성공
				}
				else
				{
					free(members);
					return 2; //비밀번호가 틀림
				}
			}
		}
		free(members);
	}
	return 0; //ID가 없음
}

// 1=실패, 0=성공
int menu_sign_up()
{
	DataMember member = {""};
	int xx, yy, lr, id_check = -1, count = 0;
	char check_pw[20] = "";
	ui_sign_up();
	while (1)
	{
		click(&xx, &yy, &lr);
		if (lr == 1)
		{
			if (xx >= 30 && xx <= 69 && yy >= 9 && yy <= 10)
			{
				gotoxy(0, 52);
				printf("              ");
				printf("id입력");
				//gotoxy(31, 10);
				get_string(member.id, strlen(member.id), 20, 31, 10);
				//scanf("%s", member.id);
				id_check = -1;
			}
			if (xx >= 72 && xx <= 81 && yy >= 9 && yy <= 10)
			{
				gotoxy(0, 52);
				printf("              ");
				printf("id중복체크");
				id_check = check_id(member.id);
				if (id_check == 0)
				{
					gotoxy(0, 52);
					printf("              ");
					printf("사용가능");
				}
				else
				{
					gotoxy(0, 52);
					printf("              ");
					printf("사용 불가능");
				}
			}
			if (xx >= 30 && xx <= 69 && yy >= 13 && yy <= 14)
			{
				gotoxy(0, 52);
				printf("              ");
				printf("pw입력");
				//gotoxy(31, 14);
				get_string_secret(member.pw, strlen(member.pw), 20, 31, 14);
				//scanf("%s", member.pw);
			}
			if (xx >= 30 && xx <= 69 && yy >= 17 && yy <= 18)
			{
				gotoxy(0, 52);
				printf("              ");
				printf("pw 확인");
				get_string_secret(check_pw, strlen(check_pw), 20, 31, 18);
			}
			if (xx >= 30 && xx <= 69 && yy >= 21 && yy <= 22)
			{
				printf("이름 입력");
				gotoxy(31, 22);
				printf("                ");
				gotoxy(31, 22);
				scanf("%s", member.member.name);
			}
			if (xx >= 30 && xx <= 69 && yy >= 25 && yy <= 26)
			{
				gotoxy(0, 52);
				printf("              ");
				printf("전화번호 입력");
				gotoxy(31, 26);
				printf("                ");
				gotoxy(31, 26);
				scanf("%s", member.member.phoneNum);
				
			}
			if (xx >= 30 && xx <= 69 && yy >= 29 && yy <= 30)
			{
				gotoxy(0, 52);
				printf("              ");
				printf("생년월일 입력");
				gotoxy(31, 30);
				printf("                ");
				gotoxy(31, 30);
				scanf("%d %d %d", &member.member.birthday.year, &member.member.birthday.month, &member.member.birthday.day);
			}
			if (xx >= 30 && xx <= 49 && yy >= 33 && yy <= 34)
			{
				//printf("회원가입 실행");
				if(check_member(member)==0 && check_nomarl_member(member)==0)
				{
					sign_up(member);
					gotoxy(0, 52);
					printf("              ");
					gotoxy(0, 52);
					message("회원가입에 성공 하셨습니다.");
					count = 1;
				}
				else
				{
					gotoxy(0, 52);
					printf("              ");
					gotoxy(0, 52);
					message("실패 하셨습니다. 정보를 다시 확인해주세요.");
				}
			}
			if (xx >= 51 && xx <= 69 && yy >= 33 && yy <= 34)
			{
				gotoxy(0, 52);
				printf("              ");
				message("회원가입을 취소 하셨습니다.");
				count = 1;
			}
		}
		if (count == 1)
			break;
	}
	return count;
}

void add_next(LinkedList* list, Terminal terminal)
{
	LinkedList* new_node = (LinkedList*)calloc(1, sizeof(LinkedList));
	new_node->terminal = terminal;
	new_node->next = NULL;
	list->next = new_node;
}

/*
void delete_node(LinkedList *node)
{
	LinkedList* temp;
	while(node != NULL)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
}
*/

void set_terminal_array(int menu, int** array, LinkedList** list)
{
	FILE* fp = NULL;
	Bus bus;
	int count = get_terminal_count("전체");
	//printf("%d", count);
	Terminal* terminal = (Terminal*)calloc(count, sizeof(Terminal));
	//Terminal city = { 0 };
	get_terminal("전체", terminal);
	
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			if (i == j)
			{
				array[i][j] = 0;
			}
			else
			{
				array[i][j] = INF;
				strcpy(list[i][j].terminal.terminal_name, terminal[i].terminal_name);
				list[i][j].next = NULL;
			}
		}
	}
	//Sleep(10000);
	switch (menu)
	{
	case 1: //가중치 = 돈, 일반과 우등이 있으면 우등 우선
		fp = fopen("버스목록.txt", "r");
		while (!feof(fp))
		{
			fscanf(fp, "%s %s %s %d %d %d %d %d\n", bus.bus_id, bus.route.start.terminal_name, bus.route.arrival.terminal_name, &bus.route.time, &bus.startTime, &bus.grade, &bus.price,&bus.state);
			for (int i = 0; i < count; i++)
			{
				if(strcmp(terminal[i].terminal_name, bus.route.start.terminal_name) == 0 &&bus.state==1)
				{
					for (int j = 0; j < count; j++)
					{
						if (i != j)
						{
							if (strcmp(terminal[j].terminal_name, bus.route.arrival.terminal_name) == 0)
							{
								if (array[i][j] < bus.price || array[i][j] == INF)
								{
									array[i][j] = bus.price;
									//get_city(terminal[j], city);
									add_next(&list[i][j], terminal[j]);
								}
							}
						}
					}
				}
			}
		}
		fclose(fp);
		break;

	case 2: //가중치 = 시간
		fp = fopen("버스목록.txt", "r");
		while (!feof(fp))
		{
			fscanf(fp, "%s %s %s %d %d %d %d %d\n", bus.bus_id, bus.route.start.terminal_name, bus.route.arrival.terminal_name, &bus.route.time, &bus.startTime, &bus.grade, &bus.price,&bus.state);
			for (int i = 0; i < count; i++)
			{
				for (int j = 0; j < count; j++)
				{
					if (i != j)
					{
						if (strcmp(terminal[i].terminal_name, bus.route.start.terminal_name) == 0 && strcmp(terminal[j].terminal_name, bus.route.arrival.terminal_name) == 0 && bus.state==1)
						{
							if (array[i][j] > bus.route.time)
							{
								array[i][j] = bus.route.time;
								//get_city(terminal[j], city);
								add_next(&list[i][j], terminal[j]);
							}
						}
					}
				}
			}
		}
		fclose(fp);
		break;
	default:
		printf("오류");
		break;
	}
	free(terminal);
}

void floyd_warshall(int menu, int** cost, int** time, LinkedList** list)
{
	int count = get_terminal_count("전체");
	set_terminal_array(1, cost, list);
	set_terminal_array(2, time, list);
	if(menu != 1)
	{
		for (int k = 0; k < count; k++)
		{
			for (int i = 0; i < count; i++)
			{
				for (int j = 0; j < count; j++)
				{
					if(i!=j)
					//dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
					{
						switch (menu)
						{
						case 2:
							if (cost[i][j] > cost[i][k] + cost[k][j])
							{
								cost[i][j] = cost[i][k] + cost[k][j];
								time[i][j] = time[i][k] + time[k][j];
								list[i][j].next = &list[k][j];
								//printf("%s %s\n", list[i][j].terminal.str, list[k][j].terminal.str);
								//list[i][k].next = &list[k][j];
								//printf("%s %s\n", list[i][j].terminal.str, list[i][k].next->terminal.str);
							}
							break;
						case 3:
							if (time[i][j] > time[i][k] + time[k][j])
							{
								cost[i][j] = cost[i][k] + cost[k][j];
								time[i][j] = time[i][k] + time[k][j];
								list[i][j].next = list[i][k].next;
								list[i][k].next = &list[k][j];
							}
							break;
						default:
							break;
						}
					}
				}
			}
		}
	}
}

Time min_to_time(int min)
{
	Time res = { 0 };
	res.hour = min / 60;
	res.min = min % 60;
	return res;
}

int count_bus_transfer(LinkedList list)
{
	int count = 0;
	while (list.next != NULL)
	{
		list = *list.next;

		count++;
	}
	return count - 1;
}

void get_string(char str[], int str_size, int max, int x, int y)
{
	int i = str_size;
	int ch;
	gotoxy(x, y);
	printf("%s", str);
	x += str_size;
	while (1)
	{
		ch = _getch();
		if (ch == '\b')
		{
			if (str_size > 0)
			{
				gotoxy(--x, y);
				printf(" ");
				gotoxy(x, y);
				i--;
				str_size--;
			}
		}
		else
		{
			str_size++;
			x++;
			if (ch == 13)
				break;
			if (i == max)
				printf("입력불가");
			else
			{
				printf("%c", ch);
				str[i++] = ch;
			}
		}
	}
	for (; i < max; i++)
		str[i] = 0;
}

void get_string_secret(char str[], int str_size, int max, int x, int y)
{
	int i = str_size;
	int ch;
	gotoxy(x, y);
	for (int j = 0; j < str_size; j++)
	{
		printf("*");
	}
	x += str_size;
	while (1)
	{
		ch = _getch();
		if (ch == '\b')
		{
			if (str_size > 0)
			{
				gotoxy(--x, y);
				printf(" ");
				gotoxy(x, y);
				i--;
				str_size--;
			}
		}
		else
		{
			str_size++;
			x++;
			if (ch == 13)
				break;
			if (i == max)
				printf("입력불가");
			else
			{
				printf("*");
				str[i++] = ch;
			}
		}
	}
	for (; i < max; i++)
		str[i] = 0;
}

int get_terminal_page(char cat[])
{
	int a = get_terminal_count(cat), res = 0;
	res = a / 12;
	if (a % 12 != 0)
		res++;
	return res;
}

int get_terminal_num(Terminal city)
{
	int res = -1, count = get_terminal_count("전체");
	Terminal* citys = (Terminal*)calloc(count, sizeof(Terminal));
	get_terminal("전체", citys);
	for (int i = 0; i < count; i++)
	{
		if (strcmp(citys[i].terminal_name, city.terminal_name) == 0)
		{
			res = i;
			break;
		}
	}
	free(citys);
	return res;
}

Terminal select_start(char user_id[])
{
	char cat[12][14] = { "검색결과","즐겨찾기","전체","서울","인천/경기","강원","대전/충남","충북","광주/전남","전북","부산/경남","대구/경북" };
	Terminal str = { "출발지" };
	ui_choice_route_frame(str);
	int xx = 0, yy = 0, lr = 0, i = 2, page = 1, max_page, city_num = 0, trig = 0,count=0;
	char temp[50] = "";
	while (1)
	{
		if (i == 0)
		{
			max_page = get_max_page_search_result(temp);
			count = count_search_result(temp);
		}
		else if (i == 1)
		{
			max_page = get_max_page_favorites_terminal(user_id);
			count = count_favorites_terminal(user_id);
		}
		else
		{
			max_page = get_terminal_page(cat[i]);
			count = get_terminal_count(cat[i]);
		}
		ui_print_city(cat[i], page, max_page, user_id, temp);
		print_page(page, max_page,56,36);
		
		click(&xx, &yy, &lr);
		if (xx >= 29 && xx <= 74 && yy == 9)
		{
			get_string(temp, strlen(temp), 50, 36, 9);
			i = 0;
			page = 1;
		}
		if (xx >= 28 && xx <= 38 && yy >= 11 && yy <= 34)
		{
			if (yy >= 11  && yy <= 12)
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
				if (xx >= 70 && xx <= 71)
				{
					for (int j = 0; j < 12; j++)
					{
						if (yy == 12 + j * 2)
						{
							city_num = j;
							Terminal* citys = (Terminal*)calloc(count, sizeof(Terminal));
							get_terminal(cat[i], citys);
							Terminal res = citys[city_num + 12 * (page - 1)];
							free(citys);
							change_favorite_state(user_id, res);
						}
					}
				}
				else
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
			}
			else
			{
				int b = count % 12;
				if (b == 0)
					b = 12;
				if (xx >= 70 && xx <= 71)
				{
					if (yy >= 11 && yy <= 12 + b * 2)
					{
						for (int j = 0; j < b; j++)
						{
							if (yy == 12 + j * 2)
							{
								city_num = j;
								Terminal* citys = (Terminal*)calloc(count, sizeof(Terminal));
								get_terminal(cat[i], citys);
								Terminal res = citys[city_num + 12 * (page - 1)];
								free(citys);
								change_favorite_state(user_id, res);
							}
						}
					}
				}
				else
				{
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

int get_arrival_count(char cat[], Terminal start)
{
	int b = get_terminal_count("전체"), res = 0, start_num = get_terminal_num(start);
	
	int** array = (int**)calloc(b, sizeof(int*));
	LinkedList** list = (LinkedList**)malloc(b * sizeof(LinkedList*));
	for (int i = 0; i < b; i++)
	{
		array[i] = (int*)calloc(b, sizeof(int));
		list[i] = (LinkedList*)malloc(b * sizeof(LinkedList));
	}
	floyd_warshall(2, array, array, list);
	for (int i = 0; i < b; i++)
	{
		if (start_num == i)
		{
			for (int j = 0; j < b; j++)
			{
				if (i != j && array[i][j] != INF)
				{
					if ((strcmp(list[i][j].terminal.city, cat) == 0) || (strcmp("전체", cat) == 0))
						res++;
				}
			}
			break;
		}
	}
	for (int i = 0; i < b; i++)
	{
		free(array[i]);
		//delete_node(list[i][0].next);
		free(list[i]);
	}
	free(array);
	free(list);
	return res;
}

void get_arrival(char cat[], Terminal start, Terminal* city)
{
	int a = get_terminal_count(cat), res = 0, m = 0, b = get_terminal_count("전체");
	int** array = (int**)calloc(b, sizeof(int*));
	Terminal* citys = (Terminal*)calloc(b, sizeof(Terminal));
	LinkedList** list = (LinkedList**)calloc(b, sizeof(LinkedList*));
	
	for (int i = 0; i < b; i++)
	{
		array[i] = (int*)calloc(b, sizeof(int));
		list[i] = (LinkedList*)calloc(b, sizeof(LinkedList));
	}

	get_terminal("전체", citys);
	floyd_warshall(2, array, array,list);
	for (int i = 0; i < b; i++)
	{
		if (strcmp(start.terminal_name, citys[i].terminal_name) == 0)
		{
			for (int j = 0; j < b; j++)
			{
				if (i != j && array[i][j] < INF)
				{
					if ((strcmp(list[i][j].terminal.city, cat) == 0) || (strcmp("전체", cat) == 0))
					{
						strcpy(city[m++].terminal_name, citys[j].terminal_name);
					}
				}
			}
			break;
		}
	}
	for (int i = 0; i < b; i++)
	{
		free(array[i]);
		//delete_node(list[i][0].next);
		free(list[i]);
	}
	free(array);
	free(list);
	free(citys);
}

int get_arrival_page(char cat[], Terminal start)
{
	int a = get_arrival_count(cat, start), res = 0;
	res = a / 12;
	if (a % 12 != 0)
		res++;
	return res;
}

Terminal select_arrival(Terminal start, char user_id[])
{
	char cat[12][14] = { "검색결과","즐겨찾기","전체","서울","인천/경기","강원","대전/충남","충북","광주/전남","전북","부산/경남","대구/경북" };
	
	int xx = 0, yy = 0, lr = 0, i = 2, page = 1, max_page, city_num = 0, trig = 0,count=0;
	char temp[50] = "";
	Terminal res;

	ui_choice_route_frame(start);
	while (1)
	{
		if (i == 0)
		{
			max_page = get_max_page_search_arrival(temp, start);
			count = count_search_arrival(temp, start);
		}
		else if (i == 1)
		{
			max_page = get_max_page_favorites_arrival(start, user_id);
			count = count_favorites_arrival(start, user_id);
		}
		else
		{
			count = get_arrival_count(cat[i], start);
			max_page = get_arrival_page(cat[i], start);
		}
		
		print_page(page, max_page,56,36);
		ui_print_arrival(cat[i], page, max_page, start, user_id, temp);
		
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
			if(page != max_page)
			{
				if (xx >= 70 && xx<=71)
				{
					for (int j = 0; j < 12; j++)
					{
						if (yy == 12 + j * 2)
						{
							city_num = j;
							Terminal* city = (Terminal*)calloc(count, sizeof(Terminal));
							get_arrival(cat[i], start, city);
							res = city[city_num + 12 * (page - 1)];
							free(city);
							change_favorite_state(user_id, res);
						}
					}
				}
				else
				{
					trig = 1;
					for (int j = 0; j < 12; j++)
					{
						if (yy >= 11 + j * 2 && yy <= 12 + j * 2)
						{
							city_num = j;
						}
					}
				}
			}
			else
			{
				int b = count % 12;
				if (b == 0)
					b = 12;
				if (xx >= 70 && xx <= 71)
				{
					if (yy >= 11 && yy <= 12 + b * 2)
					{
						for (int j = 0; j < b; j++)
						{
							if (yy == 12 + j * 2)
							{
								city_num = j;
								Terminal* city = (Terminal*)calloc(count, sizeof(Terminal));
								get_arrival(cat[i], start, city);
								res = city[city_num + 12 * (page - 1)];
								free(city);
								change_favorite_state(user_id, res);
							}
						}
					}
				}
				else
				{
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
		}
		if (xx == 63 && yy == 36) // 아 그거
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
	Terminal* city = (Terminal*)calloc(count, sizeof(Terminal));
	get_arrival(cat[i], start, city);
	res = city[city_num + 12 * (page - 1)];
	free(city);
	return res;
}

int select_route_way(Terminal start, Terminal arrival)
{
	int xx, yy, lr, menu=1;
	ui_choice_route_way(start, arrival, menu);
	while (1)
	{
		click(&xx, &yy, &lr);
		if(xx >= 28 && xx <= 43 && yy>=11 && yy<=16)
		{
			if (yy >= 11 && yy <= 12)
			{
				menu = 1;
			}
			if (yy >= 13 && yy <= 14)
			{
				menu = 2;
			}
			if (yy >= 15 && yy <= 16)
			{
				menu = 3;
			}
			ui_choice_route_way(start, arrival, menu);
		}
		if (yy >= 32 && yy <= 36)
		{
			if (xx >= 46 && xx <= 58)
			{
				break;
			}
			if (xx >= 61 && xx <= 72)
			{
				menu = 0;
				break;
			}
		}
	}
	return menu;
}

int check_leaf_year(int year)
{
	if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0))
		return 1;
	return 0;
}

int get_day(int year, int month)
{
	int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	day[2] += check_leaf_year(year);
	return day[month];
}

int get_start_day(int _year, int _month)
{
	int lastyear = _year - 1;	//입력한 year의 전 year을 구한다
	int lastyeardate = 0;	//작년까지 총 날짜 저장
	int inputyeardate = 0;	//올해 입력달까지의 총 날짜 저장
	int firstdate = 0;	//1일이 시작될 위치값
	int month = _month;	//_month를 1부터 _month 전 달까지 증가시켜주기 위해 month에 저장
	lastyeardate = lastyear * 365 + lastyear / 400 + lastyear / 4 - lastyear / 100 + 1;	//1년1월1일부터 입력한 년의 전 년까지 날짜들의 총합
	int leapyear = check_leaf_year(_year);	//LeapYear을 실행해서 윤년을 불러온다

	for (int _month = 1; _month < month; _month++)	//입력받은 달을 1부터 입력받은 전달까지 for문을 사용
	{
		int date = get_last_day(_year, _month);	//변수 date에 LastDate함수로 호출한 그 달의 마지막 날을 입력한다
		inputyeardate += date;	//입력한 년의 1월1일부터 입력한 달의 전 달까지 총합
	}
	firstdate = (lastyeardate + inputyeardate) % 7;	//입력한 달의 시작일을 구하기위해 (작년까지 일수의 총합+올해 일수의 총합+1)을 7로 나눈 나머지값을 구한다

	return firstdate;	//+1은 1년 1월 1일이 월요일이기때문에 달력은 일요일부터 시작하므로 +1한다.
}

int get_last_day(int _year, int _month)
{
	int lastdate = 0;
	int leapyear = check_leaf_year(_year);	//LeapYear함수를 호출해 leapyear에 저장한다(윤년)

	if (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12)
	{
		lastdate = 31;	//1, 3, 5, 7, 8, 10, 12월 마지막 날짜는 31일
	}
	else if (_month == 4 || _month == 6 || _month == 9 || _month == 11)
	{
		lastdate = 30;	//4, 6, 9, 11월 마지막 날짜는 30일 
	}
	else if (leapyear == 1 && _month == 2)
	{
		lastdate = 29;	//윤년일 경우 2월의 마지막 날짜는 29일
	}
	else if (leapyear == 0 && _month == 2)
	{
		lastdate = 28;	//평년일 경우 2월의 마지막 날짜는 28일
	}

	return lastdate;	//마지막 날짜를 반환
}

Date select_day()
{
	time_t rawTime = time(NULL);
	struct tm* pTime = localtime(&rawTime);
	Date d;
	int xx, yy, lr, x = 0, y = 0, start_day = 0;
	d.year = pTime->tm_year + 1900;
	d.month = pTime->tm_mon + 1;
	ui_calendar(d);
	while(1)
	{
		click(&xx, &yy, &lr);
		if (pTime->tm_year + 1900 + 2 > d.year)
		{
			if (xx >= 54 && xx <= 55 && yy == 11)
			{
				d.year += 1;
				if (pTime->tm_year + 1900 + 2 == d.year && pTime->tm_mon + 1 < d.month)
					d.month = pTime->tm_mon + 1;
				ui_calendar(d);
			}
		}
		if ((pTime->tm_year + 1900 + 2 > d.year) || (pTime->tm_year + 1900 + 2 >= d.year && pTime->tm_mon + 1 > d.month))
		{
			if (xx >= 54 && xx <= 55 && yy == 14)
			{
				d.month += 1;
				if (d.month > 12)
				{
					d.month = 1;
					d.year += 1;
				}
				ui_calendar(d);
			}
		}
		if (pTime->tm_year + 1900 < d.year)
		{
			if (xx >= 45 && xx <= 46 && yy == 11)
			{
				d.year -= 1;
				if (pTime->tm_year + 1900 == d.year && pTime->tm_mon + 1 > d.month)
					d.month = pTime->tm_mon + 1;
				ui_calendar(d);
			}
		}
		if ((pTime->tm_year + 1900 < d.year) || (pTime->tm_year + 1900 <= d.year && pTime->tm_mon + 1 < d.month))
		{
			if (xx >= 45 && xx <= 46 && yy == 14)
			{
				d.month -= 1;
				if (d.month < 1)
				{
					d.month = 12;
					d.year -= 1;
				}
				ui_calendar(d);
			}
		}
		if (xx >= 35 && xx <= 66 && yy >= 19 && yy <= 29)
		{
			for (int i = 0; i < 7; i++)
			{
				if (xx >= 35 + i * 5 && xx <= 36 + i * 5)
				{
					for (int j = 0; j < 5; j++)
					{
						if (yy >= 19 + j * 2)
						{
							x = xx- 30;
							x /= 5;
							y = yy - 17;
							y /= 2;
							start_day = get_start_day(d.year, d.month);
							d.day = x + (y - 1) * 7 - start_day;
							if(d.year == pTime->tm_year + 1900 && d.month == pTime->tm_mon+1 && d.day <pTime->tm_mday)
							{
								x = 0;
								y = 0;
							}
						}
					}
				}
			}
		}
		if (x != 0 && y != 0)
			break;
	}
	return d;
}

Time select_time(Terminal start, Terminal arrival, Date start_day)
{
	int bus_count = get_bus_count(start, arrival);
	Bus* bus_array = (Bus*)calloc(bus_count, sizeof(Bus));
	get_bus_array(start, arrival, bus_array);
	qsort(bus_array, bus_count, sizeof(Bus), compare_bus_startTime);
	int page = 1, max_page = get_bus_max_page(start, arrival),temp=0,xx,yy,lr,temp2;
	ui_choice_time(bus_array, start_day, page, max_page);
	print_page(page, max_page, 47, 45);
	int trig = 0;
	while(1)
	{
		click(&xx, &yy, &lr);
		if (((xx >= 55 && xx <= 56) || (xx >= 48 && xx <= 49)) && yy == 45)
		{
			if (xx >= 55 && xx <= 56)
			{
				if (page < max_page)
				{
					page++;
					ui_choice_time(bus_array, start_day, page, max_page);
				}
			}
			if (xx >= 48 && xx <= 49)
			{
				if (page > 0)
				{
					page--;
					ui_choice_time(bus_array, start_day, page, max_page);
				}
			}
		}
		if(page != max_page)
		{
			for(int i=0;i<6;i++)
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

int compare_time(Time t1, Time t2)
{
	if (t1.hour > t2.hour)
	{
		return 1;
	}
	else if (t1.hour < t2.hour)
	{
		return -1;
	}
	else
	{
		if (t1.min > t2.min)
			return 1;
		else if (t1.min < t2.min)
			return -1;
		else
			return 0;
	}
}

int compare_date(Date d1, Date d2)
{
	if (d1.year > d2.year)
		return 1;
	else if (d1.year < d2.year)
		return -1;
	else
	{
		if (d1.month > d2.month)
			return 1;
		else if (d1.month < d2.month)
			return -1;
		else
		{
			if (d1.day > d2.day)
				return 1;
			else if (d1.day < d2.day)
				return -1;
			else
				return 0;
		}
	}
}

void compare_bus_startTime(const Bus* first, const Bus* second)
{
	if (first->startTime > second->startTime)
		return 1;
	else if (first->startTime < second->startTime)
		return -1;
	else
		return 0;
}

int select_seat_num(Terminal start, Terminal arrival, Date start_day, Time start_time)
{
	int xx, yy, lr,res=0,trig=0;
	Bus bus = get_bus_info(start, arrival, start_time);
	BusSeat* seat_array = (BusSeat*)calloc(31 - 10 * bus.grade, sizeof(BusSeat));
	get_bus_seat(bus, start_day, seat_array);
	ui_select_bus_seat(start, arrival, start_day, start_time);
	while(1)
	{
		click(&xx, &yy, &lr);
		switch (bus.grade)
		{
		case 0:
			for (int i = 0; i < NOMAL; i++)
			{
				if (i % 4 >= 2)
				{
					if (xx >= 52 + 8 * ((i % 4) - 2) && xx <= 57 + 8 * ((i % 4) - 2) && yy >= 10 + (i / 4) * 4 && yy <= 13 + (i / 4) * 4)
					{
						if(seat_array[i].state == 0)
						{
							res = i + 1;
							trig = 1;
						}
						break;
					}
				}
				else
				{
					if (xx >= 32 + 8 * (i % 4) && xx <= 37 + 8 * (i % 4) && yy >= 10 + (i / 4) * 4 && yy <= 13 + (i / 4) * 4)
					{
						if (seat_array[i].state == 0)
						{
							res = i + 1;
							trig = 1;
						}
						break;
					}
				}
			}
			break;
		case 1:
			for (int i = 0; i < SPECIAL; i++)
			{
				if (i % 3 == 2)
				{
					if (xx >= 61 && xx <= 66 && yy >= 10 + (i / 3) * 4 && yy <= 13 + (i / 3) * 4)
					{
						if (seat_array[i].state == 0)
						{
							res = i + 1;
							trig = 1;
						}
						break;
					}
				}
				else
				{
					if (xx >= 32 + 8 * (i % 3) && xx <= 37 + 8 * (i % 3) && yy >= 10 + (i / 3) * 4 && yy <= 13 + (i / 3) * 4)
					{
						if (seat_array[i].state == 0)
						{
							res = i + 1;
							trig = 1;
						}
						break;
					}
				}
			}
			break;
		}
		if (trig == 1)
			break;
	}
	free(seat_array);
	return res;
}

Tiket create_tiket(DataPerson consumer_data, char bus_id[], int seat_num, Date start_day)
{
	Tiket res = { 0 };
	res.consumerData = consumer_data;
	res.seatNum = seat_num;
	res.startDay = start_day;
	strcpy(res.bus_id, bus_id);
	return res;
}

int buy_tiket(char id[], char pw[], Terminal start, Terminal arrival)
{
	int xx, yy, lr,res=0;
	Date start_day;
	Time start_time;
	start_day = select_day();
	start_time = select_time(start, arrival, start_day);
	int seat_num = select_seat_num(start, arrival, start_day, start_time);
	Bus bus = get_bus_info(start, arrival, start_time);
	DataMember data = get_member_info(id, pw);
	Tiket tiket = create_tiket(data.member, bus.bus_id, seat_num, start_day);
	
	char str[50];
	ui_buy_tiket(tiket);
	while (1)
	{
		click(&xx, &yy, &lr);
		if (xx >= 31 && xx <= 48 && yy >= 27 && yy <= 29)
		{
			message("예매 되었습니다.");
			add_tiket(tiket);
			break;
		}
		if (xx >= 50 && xx <= 67 && yy >= 27 && yy <= 29)
		{
			message("예매가 취소 되었습니다.");
			res = 1;
			break;
		}
	}
	return res;
}

void message(char str[])
{
	ui_massage(str, strlen(str));
	int xx=0, yy=0, lr=0;
	while (1)
	{
		click(&xx, &yy, &lr);
		if (xx >= 45 && xx <= 54 && yy == 26)
		{
			break;
		}
	}
}

void buy_transfer_tiket(char id[], char pw[], LinkedList list, int count_transfer)
{
	int trig = 0;
	for (int i = 0; i <= count_transfer; i++)
	{
		trig = buy_tiket(id, pw, list.terminal, list.next->terminal);
		if (trig == 1)
		{
			message("환승 구매를 취소합니다.");
			break;
		}
		list = *list.next;
	}
	if (trig == 0)
	{
		message("환승 구매가 완료 되었습니다.");
	}
}

int compare_terminal(Terminal terminal1, Terminal terminal2)
{
	if (strcmp(terminal1.terminal_name, terminal2.terminal_name) < 0)
		return -1;
	else if (strcmp(terminal1.terminal_name, terminal2.terminal_name) > 0)
		return 1;
	else
		return 0;
}

int get_max_page_favorites_terminal(char user_id[])
{
	int a = count_favorites_terminal(user_id), res = 0;
	res = a / 12;
	if (a % 12 != 0)
		res++;
	return res;
}

// 1이면 즐겨찾기 0이면 즐겨찾기아님
int check_favorites_terminal(Terminal terminal,char user_id[])
{
	int count = count_favorites_terminal(user_id), res = 0;
	Terminal* temp = (Terminal*)calloc(count, sizeof(Terminal));
	get_favorites_terminal(user_id, temp);
	for (int i = 0; i < count; i++)
	{
		if (compare_terminal(temp[i],terminal) == 0)
		{
			res = 1;
		}
	}
	return res;
}

int count_search_result(char str[])
{
	int count = get_terminal_count("전체"),res=0;
	Terminal* terminal_array = (Terminal*)calloc(count, sizeof(Terminal));
	get_terminal("전체", terminal_array);

	for (int i = 0; i < count; i++)
	{
		if (strstr(terminal_array[i].terminal_name, str) != NULL)
			res++;
	}
	free(terminal_array);
	return res;
}

void get_search_result(char str[], Terminal terminal_array[])
{
	int count = get_terminal_count("전체"), res = 0;
	Terminal* temp = (Terminal*)calloc(count, sizeof(Terminal));
	get_terminal("전체", temp);
	int j = 0;
	for (int i = 0; i < count; i++)
	{
		if (strstr(temp[i].terminal_name, str) != NULL)
		{
			strcpy(terminal_array[j++].terminal_name, temp[i].terminal_name);
		}
	}
	free(temp);
}

int get_max_page_search_result(char str[])
{
	int a = count_search_result(str), res = 0;
	res = a / 12;
	if (a % 12 != 0)
		res++;
	return res;
}

int count_favorites_arrival(Terminal start, char user_id[])
{
	int arrival_count = get_arrival_count("전체", start), res = 0;
	Terminal* arrival_array = (Terminal*)calloc(arrival_count, sizeof(Terminal));
	int favorite_count = count_favorites_terminal(user_id);
	Terminal* favorite_array = (Terminal*)calloc(favorite_count, sizeof(Terminal));
	for (int i = 0; i < arrival_count; i++)
	{
		for (int j = 0; j < favorite_count; j++)
		{
			if (compare_terminal(arrival_array[i], favorite_array[j]) == 0)
				res++;
		}
	}
	free(arrival_array);
	free(favorite_array);
	return res;
}

void get_favorites_arrival(Terminal start, char user_id[], Terminal terminal_array[])
{
	int arrival_count = get_arrival_count("전체", start), res = 0;
	Terminal* arrival_array = (Terminal*)calloc(arrival_count, sizeof(Terminal));
	get_arrival("전체", start, arrival_array);
	int favorite_count = count_favorites_terminal(user_id);
	Terminal* favorite_array = (Terminal*)calloc(favorite_count, sizeof(Terminal));
	get_favorites_terminal(user_id, favorite_array);
	for (int i = 0; i < arrival_count; i++)
	{
		for (int j = 0; j < favorite_count; j++)
		{
			if (compare_terminal(arrival_array[i], favorite_array[j]) == 0)
			{
				terminal_array[res++] = arrival_array[i];
			}
		}
	}
	free(arrival_array);
	free(favorite_array);
}

int count_search_arrival(char str[], Terminal start)
{
	int count = get_arrival_count("전체", start), res = 0;
	Terminal* arrival_array = (Terminal*)calloc(count, sizeof(Terminal));
	get_arrival("전체", start, arrival_array);

	for (int i = 0; i < count; i++)
	{
		if (strstr(arrival_array[i].terminal_name, str) != NULL)
			res++;
	}
	free(arrival_array);
	return res;
}

void get_search_arrival(char str[], Terminal start, Terminal terminal_array[])
{
	int count = get_arrival_count("전체", start), res = 0;
	Terminal* temp = (Terminal*)calloc(count, sizeof(Terminal));
	get_arrival("전체", start, temp);
	int j = 0;
	for (int i = 0; i < count; i++)
	{
		if (strstr(temp[i].terminal_name, str) != NULL)
		{
			terminal_array[j++] = temp[i];
		}
	}
	free(temp);
}

int get_max_page_search_arrival(char str[], Terminal start)
{
	int a = count_search_arrival(str, start);
	int res = a / 12;
	if (a % 12 != 0)
		res++;
	return res;
}

int get_max_page_favorites_arrival(Terminal start, char user_id[])
{
	int a = count_favorites_arrival(start, user_id);
	int res = a / 12;
	if (a % 12 != 0)
		res++;
	return res;
}

int compare_data_person(DataPerson p1, DataPerson p2)
{
	if (strcmp(p1.phoneNum, p2.phoneNum) == 0 && strcmp(p1.name, p2.name) == 0 && compare_date(p1.birthday, p2.birthday) == 0)
	{
		return 0;
	}
	else
		return 1;
}

int get_max_page_tiket(DataPerson person, int menu)
{
	int a = count_tiket_array(person, menu);
	int res = a / 12;
	if (a % 12 != 0)
		res++;
	return res;
}

Tiket select_tiket(DataPerson d, int menu)
{
	int page = 1, max_page,xx,yy,lr;
	max_page = get_max_page_tiket(d, menu);
	ui_list_tiket(d, page, max_page);
	int count = count_tiket_array(d, menu), i = 0;
	Tiket* tiket_array = (Tiket*)calloc(count, sizeof(Tiket));
	get_tiket_array(d, tiket_array, menu);
	print_page(page, max_page, 46, 36);
	int res=0, trig=0;
	Tiket temp;
	while (1)
	{
		click(&xx, &yy, &lr);
		if (xx >= 25 && xx <= 73)
		{
			for (int i = 0; i < 12; i++)
			{
				if (yy == 12 + i * 2)
				{
					res = i;
					trig = 1;
				}
			}
		}
		if (xx == 53 && yy == 36) // 페이지 버튼
		{
			if (page < max_page)
			{
				page++;
				print_page(page, max_page, 46, 36);
			}
		}
		if (xx == 57 && yy == 36)
		{
			if (page > 1)
			{
				page--;
				print_page(page, max_page, 46, 36);
			}
		}
		if (trig == 1)
			break;
	}
	temp = tiket_array[res + (page - 1) * 12];
	free(tiket_array);
	return temp;
}

int compare_tiket(Tiket t1, Tiket t2)
{
	if (strcmp(t1.bus_id, t2.bus_id) == 0 && compare_data_person(t1.consumerData, t2.consumerData) == 0 && t1.seatNum == t2.seatNum && compare_date(t1.startDay, t2.startDay) == 0 && t1.state == t2.state)
		return 0;
	else
		return 1;
}

void update_user_data(DataMember temp)
{
	int x = 24;
	int y = 9;
	int xx, yy, lr;
	ui_update_user_data();
	gotoxy(46, 13);
	printf("%s", temp.member.name);
	gotoxy(46, 16);
	printf("%d %d %d", temp.member.birthday.year, temp.member.birthday.month, temp.member.birthday.day);
	gotoxy(46, 19);
	printf("%s", temp.member.phoneNum);
	while (1)
	{
		click(&xx, &yy, &lr);
		if (xx >= 45 && xx <= 66 && yy == 13)
		{
			get_string(temp.member.name, strlen(temp.member.name), 20, 46, 13);
		}
		if (xx >= 45 && xx <= 66 && yy == 16)
		{
			gotoxy(46, 16);
			printf("               ");
			gotoxy(46, 16);
			scanf("%d %d %d", &temp.member.birthday.year, &temp.member.birthday.month, &temp.member.birthday.day);
		}
		if (xx >= 45 && xx <= 66 && yy == 19)
		{
			get_string(temp.member.phoneNum, strlen(temp.member.phoneNum), 20, 46, 19);
		}
		if (xx >= 29 && xx <= 47 && yy >= 23 && yy <= 25)
		{
			message("회원 정보를 수정하였습니다.");
			update_user_data_file(temp);
			break;
		}
		if (xx >= 50 && xx <= 69 && yy >= 23 && yy <= 25)
		{
			message("정보 수정을 취소합니다.");
			break;
		}
	}
}

void update_user_pw(DataMember temp)
{
	int xx, yy, lr;
	char cur_pw[20],new_pw[20];
	ui_update_user_pw();
	while (1)
	{
		click(&xx, &yy, &lr);
		if (xx >= 48 && xx <= 66 && yy == 14)
		{
			get_string(cur_pw, strlen(cur_pw), 20, 49, 14);
		}
		if (xx >= 48 && xx <= 66 && yy == 18)
		{
			get_string(new_pw, strlen(new_pw), 20, 49, 18);
			strcpy(temp.pw, new_pw);
		}
		if (xx >= 29 && xx <= 47 && yy >= 23 && yy <= 25)
		{
			message("회원 정보를 수정하였습니다.");
			update_user_data_file(temp);
			break;
		}
		if (xx >= 50 && xx <= 69 && yy >= 23 && yy <= 25)
		{
			message("정보 수정을 취소합니다.");
			break;
		}
	}
}

DataPerson login_non_user(void)
{

}