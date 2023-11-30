#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<time.h>
#include "시외버스프로그램.h"

void sign_up(DataMember new_mem)
{
	FILE* fp = NULL;
	fp = fopen("회원목록.txt", "a");
	fprintf(fp, "%s %s %s %d %d %d %s\n", new_mem.id, new_mem.pw, new_mem.member.name, new_mem.member.birthday.year, new_mem.member.birthday.month, new_mem.member.birthday.day, new_mem.member.phoneNum);
	fclose(fp);
}

int get_member_size(void)
{
	DataMember mem = { "" };
	FILE* fp = NULL;
	int i = 0;
	fp = fopen("회원목록.txt", "r");
	while (!feof(fp))
	{
		i++;
		fscanf(fp, "%s %s %s %d %d %d %s\n", mem.id, mem.pw, mem.member.name, &mem.member.birthday.year, &mem.member.birthday.month, &mem.member.birthday.day, mem.member.phoneNum);
	}
	fclose(fp);
	return i;
}

void read_file_member(DataMember members[], int size)
{
	FILE* fp = NULL;
	fp = fopen("회원목록.txt", "r");
	for (int i = 0; i < size; i++)
	{
		fscanf(fp, "%s %s %s %d %d %d %s\n", members[i].id, members[i].pw, members[i].member.name, &members[i].member.birthday.year, &members[i].member.birthday.month, &members[i].member.birthday.day, members[i].member.phoneNum);
	}
	fclose(fp);
}

int get_bus_count(Terminal start, Terminal arrival)
{
	//printf("%s	%s\n", start.terminal_name, arrival.terminal_name);
	Bus bus;
	FILE* fp = NULL;
	int i = 0;
	fp = fopen("버스목록.txt", "r");
	while (!feof(fp))
	{
		fscanf(fp, "%s %s %s %d %d %d %d %d\n", bus.bus_id, bus.route.start.terminal_name, bus.route.arrival.terminal_name, &bus.route.time, &bus.startTime, &bus.grade, &bus.price,&bus.state);
		if (((strcmp(start.terminal_name, bus.route.start.terminal_name) == 0 && strcmp(arrival.terminal_name, bus.route.arrival.terminal_name) == 0) || strcmp(start.terminal_name, "전체") == 0) && bus.state == 1)
		{
			i++;
			//printf("%s	%s	%s\n", bus.route.start.terminal_name, bus.route.arrival.terminal_name, bus.bus_id);
		}
	}
	fclose(fp);
	return i;
}

void get_bus_array(Terminal start, Terminal arrival, Bus* array)
{
	FILE* fp = NULL;
	Bus bus;
	int i = 0;
	fp = fopen("버스목록.txt", "r");
	while(!feof(fp))
	{
		fscanf(fp, "%s %s %s %d %d %d %d %d\n", bus.bus_id, bus.route.start.terminal_name, bus.route.arrival.terminal_name, &bus.route.time, &bus.startTime, &bus.grade, &bus.price, &bus.state);
		if (((strcmp(start.terminal_name, bus.route.start.terminal_name) == 0 && strcmp(arrival.terminal_name, bus.route.arrival.terminal_name) == 0) || strcmp(start.terminal_name, "전체") == 0) && bus.state == 1)
			array[i++] = bus;
	}
	fclose(fp);
}

int get_terminal_count(char cat[])
{
	int count = 0;
	char city[20], terminal[20];
	FILE* fp = fopen("터미널정보.txt","r");
	if (strcmp(cat, "전체") == 0)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%s %s\n", city, terminal);
			count++;
		}
	}
	else
	{
		while (!feof(fp))
		{
			fscanf(fp, "%s %s\n", city, terminal);
			if (strcmp(cat, city) == 0)
			{
				count++;
			}
		}
	}
	fclose(fp);

	return count;
}

void get_terminal(char cat[], Terminal terminals[])
{
	FILE* fp = fopen("터미널정보.txt", "r");
	char city[20], terminal[20];
	int i = 0;
	if (strcmp(cat,"전체")==0)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%s %s\n", terminals[i].city, terminals[i].terminal_name);
			i++;
		}
	}
	else // 즐겨찾기와 검색결과는 다른 함수에서
	{
		while (!feof(fp))
		{
			fscanf(fp, "%s %s\n", city, terminal);
			if (strcmp(cat, city) == 0)
			{
				strcpy(terminals[i].terminal_name, terminal);
				strcpy(terminals[i].city, city);
				i++;
			}
		}
	}
	fclose(fp);
}

Bus get_bus_info(Terminal start, Terminal arrival, Time start_time)
{
	FILE* fp = fopen("버스목록.txt", "r");
	Bus bus;
	Time temp;
	while(!feof(fp))
	{
		fscanf(fp, "%s %s %s %d %d %d %d %d\n", bus.bus_id, bus.route.start.terminal_name, bus.route.arrival.terminal_name, &bus.route.time, &bus.startTime, &bus.grade, &bus.price,&bus.state);
		temp = min_to_time(bus.startTime);
		if (strcmp(start.terminal_name, bus.route.start.terminal_name) == 0 && strcmp(arrival.terminal_name, bus.route.arrival.terminal_name) == 0 && compare_time(temp, start_time) == 0 && bus.state == 1)
		{
			break;
		}
	}
	fclose(fp);
	return bus;
}

int get_remain_bus_seat_count(Terminal start, Terminal arrival, Date start_day, Time start_time)
{
	FILE* fp = NULL;
	fp = fopen("예매상태.txt", "r");
	int res = 0, temp1 = 0, temp2 = 0;
	Bus bus;
	bus = get_bus_info(start, arrival, start_time);
	BusSeat bus_seat;
	while (!feof(fp))
	{
		fscanf(fp, "%s %d %d %d %d %d\n", bus_seat.bus_id, &bus_seat.start_day.year, &bus_seat.start_day.month, &bus_seat.start_day.day, &bus_seat.seat_num, &bus_seat.state);
		if (strcmp(bus_seat.bus_id, bus.bus_id) == 0 && compare_date(start_day, bus_seat.start_day) == 0)
		{
			if (bus_seat.state == 0)
				temp1++;
			if (bus_seat.state == 1)
				temp2++;
		}
	}
	fclose(fp);

	//Bus bus;
	fp = fopen("버스목록.txt", "r");
	while (!feof(fp))
	{
		fscanf(fp, "%s %s %s %d %d %d %d %d\n", bus.bus_id, bus.route.start, bus.route.arrival, &bus.route.time, &bus.startTime, &bus.grade, &bus.price,&bus.state);
		if (strcmp(bus.bus_id, bus.bus_id) == 0)
			break;
	}
	fclose(fp);
	
	if (bus.grade == 0)
		res = NOMAL - temp2;
	if (bus.grade == 1)
		res = SPECIAL - temp2;
	
	if (temp1 == 0 && temp2 == 0)
	{
		if (bus.grade == 0)
			res = NOMAL;
		if (bus.grade == 1)
			res = SPECIAL;
	}
	//printf("%d", temp2);

	return res;
}

void get_bus_seat(Bus bus, Date start_day, BusSeat* seat_array)
{
	FILE* fp = NULL;
	fp = fopen("예매상태.txt", "r");
	int i = 0;
	BusSeat bus_seat, temp;
	strcpy(temp.bus_id, bus.bus_id);
	temp.start_day = start_day;
	temp.state = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%s %d %d %d %d %d\n", bus_seat.bus_id, &bus_seat.start_day.year, &bus_seat.start_day.month, &bus_seat.start_day.day, &bus_seat.seat_num, &bus_seat.state);
		if (strcmp(bus_seat.bus_id, bus.bus_id) == 0 && compare_date(start_day, bus_seat.start_day) == 0)
		{
			seat_array[bus_seat.seat_num - 1] = bus_seat;
		}
	}
	for (int i = 0; i < 31 - 10 * bus.grade; i++)
	{
		if (seat_array[i].seat_num != i + 1)
		{
			temp.seat_num = i;
			seat_array[i] = temp;
		}
	}
	fclose(fp);
}

int get_bus_max_page(Terminal start, Terminal arrival)
{
	int res = get_bus_count(start, arrival);
	if (res % 6 == 0)
		res /= 6;
	else
	{
		res /= 6;
		res += 1;
	}
	return res;
}

DataMember get_member_info(char id[], char pw[])
{
	FILE* fp = fopen("회원목록.txt", "r");
	DataMember temp;
	int trig = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%s %s %s %d %d %d %s\n", temp.id, temp.pw, temp.member.name, &temp.member.birthday.year, &temp.member.birthday.month, &temp.member.birthday.day, temp.member.phoneNum);
		if (strcmp(id, temp.id) == 0)
		{
			break;
		}
	}
	fclose(fp);

	return temp;
}

Bus get_bus_info2(char bus_id[])
{
	FILE* fp = fopen("버스목록.txt", "r");
	Bus bus;
	Time temp;
	while (!feof(fp))
	{
		fscanf(fp, "%s %s %s %d %d %d %d %d\n", bus.bus_id, bus.route.start.terminal_name, bus.route.arrival.terminal_name, &bus.route.time, &bus.startTime, &bus.grade, &bus.price, &bus.state);
		temp = min_to_time(bus.startTime);
		if (strcmp(bus_id,bus.bus_id) == 0)
		{
			break;
		}
	}
	fclose(fp);
	return bus;
}

void add_tiket(Tiket tiket)
{
	FILE* fp = NULL;
	fp = fopen("티켓.txt", "a");
	fprintf(fp, "%s %d %d %d %d %s %d %d %d %s %d\n", tiket.bus_id, tiket.seatNum, tiket.startDay.year, tiket.startDay.month, tiket.startDay.day, tiket.consumerData.name, tiket.consumerData.birthday.year, tiket.consumerData.birthday.month, tiket.consumerData.birthday.day, tiket.consumerData.phoneNum, tiket.state);
	fclose(fp);
	fp = fopen("예매상태.txt", "a");
	fprintf(fp, "%s %d %d %d %d %d\n", tiket.bus_id, tiket.startDay.year, tiket.startDay.month, tiket.startDay.day, tiket.seatNum, tiket.state);
	fclose(fp);
}

void sort_terminal_file(void)
{
	int terminal_count = get_terminal_count("전체");
	Terminal* terminals = (Terminal*)calloc(terminal_count, sizeof(Terminal));
	get_terminal("전체", terminals);
	qsort(terminals, terminal_count, sizeof(Terminal), compare_terminal);
	FILE* fp = fopen("터미널정보.txt", "w");
	for (int i = 0; i < terminal_count; i++)
	{
		fprintf(fp, "%s %s\n", terminals[i].city, terminals[i].terminal_name);
	}
	fclose(fp);
	free(terminals);
}

int count_favorites_terminal(char id[])
{
	FILE* fp = fopen("즐겨찾기.txt", "r");
	char temp1[20], temp2[20];
	int i = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%s %s\n", temp1, temp2);
		if (strcmp(id, temp1) == 0)
		{
			i++;
		}
	}
	fclose(fp);
	return i;
}

void get_favorites_terminal(char id[], Terminal terminals[])
{
	FILE* fp = fopen("즐겨찾기.txt", "r");
	char temp_id[20], temp_terminal[20];
	int i = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%s %s\n", temp_id, temp_terminal);
		if (strcmp(id, temp_id) == 0)
		{
			strcpy(terminals[i++].terminal_name, temp_terminal);
		}
	}
	fclose(fp);
}

int get_file_line_favorite(void)
{
	Favorite temp;
	FILE* fp = fopen("즐겨찾기.txt", "r");
	int res = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%s %s\n", temp.id, temp.terminal);
		res++;
	}
	fclose(fp);
	return res;
}

void get_favorite_all(Favorite array[])
{
	FILE*fp= fopen("즐겨찾기.txt", "r");
	int i = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%s %s\n", array[i].id, array[i].terminal);
		i++;
	}
	fclose(fp);
}

void change_favorite_state(char id[], Terminal terminal)
{
	int check = check_favorites_terminal(terminal, id);
	if(check == 1)
	{
		int count = get_file_line_favorite();
		Favorite* temp = (Favorite*)calloc(count, sizeof(Favorite));
		get_favorite_all(temp);
		FILE* fp = fopen("즐겨찾기.txt", "w");
		for (int i = 0; i < count; i++)
		{
			if (strcmp(temp[i].id, id) == 0 && strcmp(temp[i].terminal, terminal.terminal_name) == 0)
			{
				;
			}
			else
			{
				fprintf(fp, "%s %s\n", temp[i].id, temp[i].terminal);
			}
		}
		free(temp);
		fclose(fp);
	}
	else
	{
		FILE* fp = fopen("즐겨찾기.txt", "a");
		fprintf(fp, "%s %s\n", id, terminal);
		fclose(fp);
	}
}

void get_tiket_array(DataPerson person, Tiket tiket_array[], int menu)
{
	FILE* fp = fopen("티켓.txt","r");
	Tiket tiket;
	int i = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%s %d %d %d %d %s %d %d %d %s %d\n", tiket.bus_id, &tiket.seatNum, &tiket.startDay.year, &tiket.startDay.month, &tiket.startDay.day, tiket.consumerData.name, &tiket.consumerData.birthday.year, &tiket.consumerData.birthday.month, &tiket.consumerData.birthday.day, tiket.consumerData.phoneNum, &tiket.state);
		switch (menu)
		{
		case 0: // 사용안한거
		case 1: // 사용된거
		case 2: // 취소된거
			if (compare_data_person(person, tiket.consumerData) == 0 && tiket.state == menu)
			{
				tiket_array[i++] = tiket;
			}
			break;
		case 3: // 전체
			if (compare_data_person(person, tiket.consumerData) == 0)
			{
				tiket_array[i++] = tiket;
			}
			break;
		default:
			break;
		}
	}
	fclose(fp);
}

int count_tiket_array(DataPerson person, int menu)
{
	FILE* fp = fopen("티켓.txt", "r");
	Tiket tiket;
	int i = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%s %d %d %d %d %s %d %d %d %s %d\n", tiket.bus_id, &tiket.seatNum, &tiket.startDay.year, &tiket.startDay.month, &tiket.startDay.day, tiket.consumerData.name, &tiket.consumerData.birthday.year, &tiket.consumerData.birthday.month, &tiket.consumerData.birthday.day, tiket.consumerData.phoneNum, &tiket.state);
		switch (menu)
		{
		case 0: // 사용안한거
		case 1: // 사용된거
		case 2: // 취소된거
			if (compare_data_person(person, tiket.consumerData) == 0 && tiket.state == menu)
			{
				i++;
			}
			break;
		case 3: // 전체
			if (compare_data_person(person, tiket.consumerData) == 0)
			{
				i++;
			}
			break;
		default:
			break;
		}
	}
	fclose(fp);
	return i;
}

void get_tiket_all(Tiket tiket_array[])
{
	FILE* fp = fopen("티켓.txt", "r");
	Tiket tiket;
	int i = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%s %d %d %d %d %s %d %d %d %s %d\n", tiket.bus_id, &tiket.seatNum, &tiket.startDay.year, &tiket.startDay.month, &tiket.startDay.day, tiket.consumerData.name, &tiket.consumerData.birthday.year, &tiket.consumerData.birthday.month, &tiket.consumerData.birthday.day, tiket.consumerData.phoneNum, &tiket.state);
		tiket_array[i++] = tiket;
	}
	fclose(fp);
}

int count_tiket_all(void)
{
	int res = 0;
	FILE* fp = fopen("티켓.txt", "r");
	Tiket tiket;
	while (!feof(fp))
	{
		fscanf(fp, "%s %d %d %d %d %s %d %d %d %s %d\n", tiket.bus_id, &tiket.seatNum, &tiket.startDay.year, &tiket.startDay.month, &tiket.startDay.day, tiket.consumerData.name, &tiket.consumerData.birthday.year, &tiket.consumerData.birthday.month, &tiket.consumerData.birthday.day, tiket.consumerData.phoneNum, &tiket.state);
		res++;
	}
	fclose(fp);
	return res;
}

void refrash_tiket(void)
{
	int count = count_tiket_all();
	time_t t = time(NULL);
	struct tm* tt = localtime(&t);
	Tiket* tiket_array = (Tiket*)calloc(count, sizeof(Tiket));
	Date d;
	d.year = tt->tm_year + 1900;
	d.month = tt->tm_mon + 1;
	d.day = tt->tm_mday;
	get_tiket_all(tiket_array);
	FILE* fp = fopen("티켓.txt", "w");
	for (int i = 0; i < count; i++)
	{
		if ((compare_date(tiket_array[i].startDay, d) < 0) && tiket_array[i].state == 0)
		{
			tiket_array[i].state = 1;
		}
		fprintf(fp, "%s %d %d %d %d %s %d %d %d %s %d\n", tiket_array[i].bus_id, tiket_array[i].seatNum, tiket_array[i].startDay.year, tiket_array[i].startDay.month, tiket_array[i].startDay.day, tiket_array[i].consumerData.name, tiket_array[i].consumerData.birthday.year, tiket_array[i].consumerData.birthday.month, tiket_array[i].consumerData.birthday.day, tiket_array[i].consumerData.phoneNum, tiket_array[i].state);
	}
	fclose(fp);
}

void delete_tiket(Tiket tiket)
{
	int count = count_tiket_all();
	time_t t = time(NULL);
	struct tm* tt = localtime(&t);
	Tiket* tiket_array = (Tiket*)calloc(count, sizeof(Tiket));
	Date d;
	d.year = tt->tm_year + 1900;
	d.month = tt->tm_mon + 1;
	d.day = tt->tm_mday;
	get_tiket_all(tiket_array);
	FILE* fp = fopen("티켓.txt", "w");
	for (int i = 0; i < count; i++)
	{
		if (compare_tiket(tiket_array[i],tiket)!=0)
		{
			fprintf(fp, "%s %d %d %d %d %s %d %d %d %s %d\n", tiket_array[i].bus_id, tiket_array[i].seatNum, tiket_array[i].startDay.year, tiket_array[i].startDay.month, tiket_array[i].startDay.day, tiket_array[i].consumerData.name, tiket_array[i].consumerData.birthday.year, tiket_array[i].consumerData.birthday.month, tiket_array[i].consumerData.birthday.day, tiket_array[i].consumerData.phoneNum, tiket_array[i].state);
		}
	}
	fclose(fp);
}

void get_data_person(DataMember d[])
{
	FILE* fp = fopen("회원목록.txt", "r");
	int i = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%s %s %s %d %d %d %s\n", d[i].id, d[i].pw, d[i].member.name, &d[i].member.birthday.year, &d[i].member.birthday.month, &d[i].member.birthday.day, d[i].member.phoneNum);
		i++;
	}
	fclose(fp);
}

int count_data_person()
{
	DataMember d;
	FILE* fp = fopen("회원목록.txt", "r");
	int i = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%s %s %s %d %d %d %s\n", d.id, d.pw, d.member.name, &d.member.birthday.year, &d.member.birthday.month, &d.member.birthday.day, d.member.phoneNum);
		i++;
	}
	fclose(fp);
	return i;
}

void update_user_data_file(DataMember d)
{
	int count = count_data_person();
	DataMember* arr = (DataMember*)calloc(count, sizeof(DataMember));
	get_data_person(arr);
	FILE* fp = fopen("회원목록.txt", "w");
	for (int i = 0; i < count; i++)
	{
		if (strcmp(arr[i].id, d.id) == 0)
		{
			fprintf(fp, "%s %s %s %d %d %d %s\n", d.id, d.pw, d.member.name, d.member.birthday.year, d.member.birthday.month, d.member.birthday.day, d.member.phoneNum);
		}
		else
		{
			fprintf(fp, "%s %s %s %d %d %d %s\n", arr[i].id, arr[i].pw, arr[i].member.name, arr[i].member.birthday.year, arr[i].member.birthday.month, arr[i].member.birthday.day, arr[i].member.phoneNum);
		}
	}
	fclose(fp);
}

void delete_bus(Bus bus)
{
	Bus temp;
	strcpy(temp.route.start.terminal_name, "전체");
	strcpy(temp.route.arrival.terminal_name, "전체");
	int count = get_bus_count(temp.route.start, temp.route.arrival);
	Bus* bus_array = (Bus*)calloc(count, sizeof(Bus));
	get_bus_array(temp.route.start, temp.route.arrival, bus_array);
	FILE* fp = fopen("버스목록.txt", "w");
	for (int i = 0; i < count; i++)
	{
		if (strcmp(bus.bus_id, bus_array[i].bus_id) != 0)
		{
			fprintf(fp, "%s %s %s %d %d %d %d %d\n", bus_array[i].bus_id, bus_array[i].route.start.terminal_name, bus_array[i].route.arrival.terminal_name, bus_array[i].route.time, bus_array[i].startTime, bus_array[i].grade, bus_array[i].price, bus_array[i].state);
		}
		else
		{
			fprintf(fp, "%s %s %s %d %d %d %d %d\n", bus_array[i].bus_id, bus_array[i].route.start.terminal_name, bus_array[i].route.arrival.terminal_name, bus_array[i].route.time, bus_array[i].startTime, bus_array[i].grade, bus_array[i].price, 0);
		}
	}
	fclose(fp);
}

void update_bus(Bus bus)
{
	int count = get_bus_count(bus.route.start, bus.route.arrival);
	Bus* bus_array = (Bus*)calloc(count, sizeof(Bus));
	get_bus_array(bus.route.start, bus.route.arrival, bus_array);
	FILE* fp = fopen("버스목록.txt", "w");
	for (int i = 0; i < count; i++)
	{
		if (strcmp(bus.bus_id, bus_array[i].bus_id) != 0)
		{
			fprintf(fp, "%s %s %s %d %d %d %d %d\n", bus_array[i].bus_id, bus_array[i].route.start.terminal_name, bus_array[i].route.arrival.terminal_name, bus_array[i].route.time, bus_array[i].startTime, bus_array[i].grade, bus_array[i].price, bus_array[i].state);
		}
		else
		{
			fprintf(fp, "%s %s %s %d %d %d %d %d\n", bus_array[i].bus_id, bus_array[i].route.start.terminal_name, bus_array[i].route.arrival.terminal_name, bus_array[i].route.time, bus_array[i].startTime, bus_array[i].grade, bus_array[i].price, 0);
		}
	}
	Time start_time = min_to_time(bus.startTime);
	bus = create_bus(bus.route, start_time, bus.grade, bus.price);
	fprintf(fp, "%s %s %s %d %d %d %d %d\n", bus.bus_id, bus.route.start.terminal_name, bus.route.arrival.terminal_name, bus.route.time, bus.startTime, bus.grade, bus.price, bus.state);
	fclose(fp);
}

void add_bus(Bus bus)
{
	Time start_time = min_to_time(bus.startTime);
	FILE* fp = fopen("버스목록.txt", "a");
	fprintf(fp, "%s %s %s %d %d %d %d %d\n", bus.bus_id, bus.route.start.terminal_name, bus.route.arrival.terminal_name, bus.route.time, start_time, bus.grade, bus.price, bus.state);
	fclose(fp);
}