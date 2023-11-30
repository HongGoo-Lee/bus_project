#pragma once

/*
* 파일이름
* 버스목록.txt
* 지역정보.txt
* 회원목록.txt
*/

// 구조체
typedef struct _terminal {
	char terminal_name[20];
	char city[20];
}Terminal;

typedef struct _date {
	int year;
	int month;
	int day;
} Date;

typedef struct _dataPerson {
	char name[20]; // 이름
	Date birthday; //생년월일
	char phoneNum[20]; // 전화번호
} DataPerson;

typedef struct _dataMember {
	char id[16];
	char pw[16];
	DataPerson member;// 이름, 생년월일, 전화번호
} DataMember;

typedef struct _time {
	int hour;
	int min;
} Time;

typedef struct _route {
	Terminal start;// 출발지역
	Terminal arrival;// 도착지역
	int time;// 걸리는 시간
} Route;

typedef struct _bus {
	char bus_id[10];//버스 번호판
	Route route; // 경로
	int startTime; // 출발 시간
	int grade; // 버스 등급
	int price; // 가격
	int state; // 버스 상태
} Bus;

typedef struct _busSeat {
	char bus_id[10]; //버스 번호판
	Date start_day; // 출발날짜
	int seat_num; // 좌석 번호
	int state; // 구매 여부
} BusSeat;

typedef struct _tiket {
	DataPerson consumerData; // 구매한사람의 정보
	char bus_id[10]; // 버스 번호판
	int seatNum; // 좌석 번호
	Date startDay; // 출발 날짜
	int state; // 티켓 상태 0:미사용,1:사용,2:취소
} Tiket;

typedef struct _linkedList {
	struct _linkedList* next;
	Terminal terminal;
}LinkedList;

typedef struct _favorite {
	char id[20];
	char terminal[20];
}Favorite;

#define NOMAL 28
#define SPECIAL 21


// 파일 입출력
int get_member_size(void);
void read_file_member(DataMember members[], int size);
void sign_up(DataMember new_mem);
void get_terminal(char cat[], Terminal citys[]);
int get_terminal_count(char cat[]);
int get_bus_count(Terminal start, Terminal arrival);
void get_bus_array(Terminal start, Terminal arrival, Bus* array);
int get_remain_bus_seat_count(Terminal start, Terminal arrival, Date start_date, Time start_time);
Bus get_bus_info(Terminal start, Terminal arrival, Time start_time);
DataMember get_member_info(char id[], char pw[]);
Bus get_bus_info2(char bus_id[]);
void add_tiket(Tiket tiket);
int count_favorites_terminal(char id[]);
void get_favorites_terminal(char id[], Terminal terminals[]);
int get_file_line_favorite(void);
void get_favorite_all(Favorite array[]);
void change_favorite_state(char id[], Terminal terminal);
void get_tiket_array(DataPerson person, Tiket tiket_array[], int menu);
void get_tiket_all(Tiket tiket_array[]);
int count_tiket_all(void);
void refrash_tiket(void);
int count_tiket_array(DataPerson person, int menu);
void delete_tiket(Tiket tiket);
void update_user_data_file(DataMember d);
int get_bus_max_page(Terminal start, Terminal arrival);
void update_bus(Bus bus);
void add_bus(Bus bus);
void delete_bus(Bus bus);

// UI
void gotoxy(int x, int y);
void print_box(int box_x, int box_y, int x, int y);
void print_box2(int box_x, int box_y, int x, int y);
void print_box3(int box_x, int box_y, int x, int y);
void print_box4(int box_x, int box_y, int x, int y);
void print_box5(int box_x, int box_y, int x, int y);
void print_box6(int box_x, int box_y, int x, int y);
void print_box7(int box_x, int box_y, int x, int y);
void print_box8(int box_x, int box_y, int x, int y);
void print_box9(int box_x, int box_y, int x, int y);
void print_box10(int box_x, int box_y, int x, int y);
void ui_frame(void);
void ui_first_screen(char id[], char pw[]);
void ui_sign_up();
void ui_massage(char msg[], int size);
void ui_login_screen(char name[]);
void ui_nonmember_screen(void);
void ui_choice_route_frame(Terminal str);
void ui_print_city(char cat[], int page, int max_page, char user_id[], char search_str[]);
void ui_print_arrival(char cat[], int page, int max_page, Terminal start, char user_id[], char search_str[]);
void print_page(int cur_page, int max_page, int x, int y);
void ui_choice_route_way_frame(int menu);
void ui_choice_route_way(Terminal start, Terminal arrival, int menu);
void ui_choice_time_frame(Terminal start, Terminal arrival, Date start_day);
void ui_calendar(Date d);
void ui_choice_time(Bus* bus_array, Date start_day, int page, int max_page);
void ui_select_bus_seat(Terminal start, Terminal arrival, Date start_day, Time start_time);
void get_bus_seat(Bus bus, Date start_day, BusSeat* seat_array);
void ui_buy_tiket(Tiket tiket);
void print_favorite_state(int x, int y, Terminal terminal, char user_id[]);
void ui_addmin_screen();
void ui_list_tiket(DataPerson d, int page, int max_page);
void ui_check_tiket(Tiket tiket);
void ui_history_tiket(Tiket tiket);
void ui_update_user_data();
void ui_update_user_pw();
void ui_mem_info(DataPerson d);
void ui_print_city_admin(char cat[], int page, int max_page, char search_str[]);
void ui_print_arrival_admin(char cat[], int page, int max_page, Terminal start, char search_str[]);
void ui_choice_time_frame_admin(Terminal start, Terminal arrival);
void ui_choice_time_admin(Bus* bus_array, int page, int max_page);
void ui_manage_bus(Terminal start, Terminal arrival);
void ui_delete_bus(Bus bus);
void ui_add_bus(Terminal start, Terminal arrival);
void ui_update_bus(Bus bus);
void ui_money_admin();
void ui_choice_route_frame_admin(Terminal str);

// 마우스 클릭
void click(int* xx, int* yy, int* lr);

// 기능
int check_member(DataMember member);
int check_nomarl_phoneNum(DataMember mem);
int checkDate(int year, int month, int day);
int check_nomarl_birthDay(DataMember mem);
int check_nomarl_member(DataMember mem);
int check_id(char id[]);
DataMember get_member(char id[]);
int login(char id[], char pw[]);
int menu_sign_up();
void add_next(LinkedList* list, Terminal terminal);
void set_terminal_array(int menu, int** array, LinkedList** list);
void floyd_warshall(int menu, int** cost, int** time, LinkedList** list);
Time min_to_time(int min);
int get_terminal_page(char cat[]);
int get_terminal_num(Terminal city);
Terminal select_start(char user_id[]);
int get_arrival_count(char cat[], Terminal start);
void get_arrival(char cat[], Terminal start, Terminal* city);
int get_arrival_page(char cat[], Terminal start);
Terminal select_arrival(Terminal start, char user_id[]);
int select_route_way(Terminal start, Terminal arrival);
int count_bus_transfer(LinkedList list);
void get_string(char str[], int str_size, int max, int x, int y);
void get_string_secret(char str[], int str_size, int max, int x, int y);
int get_start_day(int _year, int _month);
int get_last_day(int _year, int _month);
Date select_day(void);
Time select_time(Terminal start, Terminal arrival, Date start_day);
int compare_time(Time t1, Time t2);
int compare_date(Date d1, Date d2);
void compare_bus_startTime(const Bus* first, const Bus* second);
int select_seat_num(Terminal start, Terminal arrival, Date start_day, Time start_time);
Tiket create_tiket(DataPerson consumer_data, char bus_id[], int seat_num, Date start_day);
int buy_tiket(char id[], char pw[], Terminal start, Terminal arrival);
void message(char str[]);
int compare_terminal(Terminal terminal1, Terminal terminal2);
void buy_transfer_tiket(char id[], char pw[], LinkedList list, int transfer_count);
int get_max_page_favorites_terminal(char user_id[]);
int check_favorites_terminal(Terminal terminal, char user_id[]);
int count_search_result(char str[]);
void get_search_result(char str[], Terminal terminal_array[]);
int get_max_page_search_result(char str[]);
int count_favorites_arrival(Terminal start, char user_id[]);
void get_favorites_arrival(Terminal start, char user_id[], Terminal terminal_array[]);
int count_search_arrival(char str[], Terminal start);
void get_search_arrival(char str[], Terminal start, Terminal terminal_array[]);
int get_max_page_search_arrival(char str[], Terminal start);
int get_max_page_favorites_arrival(Terminal start, char user_id[]);
void menu_admin(void);
int compare_data_person(DataPerson p1, DataPerson p2);
Tiket select_tiket(DataPerson d, int menu);
void update_user_data(DataMember temp);
void update_user_pw(DataMember temp);


//관리자 기능
Terminal select_start_admin();
Terminal select_arrival_admin(Terminal start);
Time select_time_admin(Terminal start, Terminal arrival);
int select_manage_menu(Terminal start, Terminal arrival);
void update_bus2(Bus bus);
Bus create_bus(Route route, Time start_time, int grade, int price);
int select_money_menu();

//테스트
void test_floyd();
void test_select_route_way(void);
void test_time(void);

// 메뉴들
void menu_1(void);
void menu_user(char id[], char pw[]);
void menu_buy_tiket(char id[], char pw[]);
void menu_admin(void);
void menu_check_tiket(DataPerson d);
void menu_history_tiket(DataPerson d);
void menu_mem_info(DataMember d);
void menu_update_bus(Terminal start, Terminal arrival);
void menu_manage_bus(void);