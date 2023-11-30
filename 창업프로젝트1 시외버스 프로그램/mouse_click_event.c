#include <Windows.h>
#include <stdio.h>

void click(int* xx, int* yy, int* lr)
{
    INPUT_RECORD rec;
    DWORD dwNOER;
    DWORD CIN;
    DWORD mode;
    CIN = GetStdHandle(STD_INPUT_HANDLE); //마우스 재활성화
    GetConsoleMode(CIN, &mode);
    SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
    while (1)
    {
        ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dwNOER); // 콘솔창 입력을 받아들임.
        if (rec.EventType == MOUSE_EVENT) {// 마우스 이벤트일 경우

            if (rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) { // 좌측 버튼이 클릭되었을 경우
                int mouse_x = rec.Event.MouseEvent.dwMousePosition.X; // X값 받아옴
                int mouse_y = rec.Event.MouseEvent.dwMousePosition.Y; // Y값 받아옴

                *xx = mouse_x; //x값을 넘김
                *yy = mouse_y; //y값을 넘김
                *lr = 1; //마우스 클릭상태를 넘김

                break;
            }
            else if (rec.Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED) { // 우측 버튼이 클릭되었을 경우
                int mouse_x = rec.Event.MouseEvent.dwMousePosition.X; // X값 받아옴
                int mouse_y = rec.Event.MouseEvent.dwMousePosition.Y; // Y값 받아옴

                *xx = mouse_x; //x값을 넘김
                *yy = mouse_y; //y값을 넘김
                *lr = 2; //마우스 클릭상태를 넘김

                break;
            }
        }
    }
    gotoxy(0, 52);
    printf("x = %03d y = %03d", *xx, *yy);
}