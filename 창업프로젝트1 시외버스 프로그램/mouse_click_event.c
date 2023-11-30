#include <Windows.h>
#include <stdio.h>

void click(int* xx, int* yy, int* lr)
{
    INPUT_RECORD rec;
    DWORD dwNOER;
    DWORD CIN;
    DWORD mode;
    CIN = GetStdHandle(STD_INPUT_HANDLE); //���콺 ��Ȱ��ȭ
    GetConsoleMode(CIN, &mode);
    SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
    while (1)
    {
        ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dwNOER); // �ܼ�â �Է��� �޾Ƶ���.
        if (rec.EventType == MOUSE_EVENT) {// ���콺 �̺�Ʈ�� ���

            if (rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) { // ���� ��ư�� Ŭ���Ǿ��� ���
                int mouse_x = rec.Event.MouseEvent.dwMousePosition.X; // X�� �޾ƿ�
                int mouse_y = rec.Event.MouseEvent.dwMousePosition.Y; // Y�� �޾ƿ�

                *xx = mouse_x; //x���� �ѱ�
                *yy = mouse_y; //y���� �ѱ�
                *lr = 1; //���콺 Ŭ�����¸� �ѱ�

                break;
            }
            else if (rec.Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED) { // ���� ��ư�� Ŭ���Ǿ��� ���
                int mouse_x = rec.Event.MouseEvent.dwMousePosition.X; // X�� �޾ƿ�
                int mouse_y = rec.Event.MouseEvent.dwMousePosition.Y; // Y�� �޾ƿ�

                *xx = mouse_x; //x���� �ѱ�
                *yy = mouse_y; //y���� �ѱ�
                *lr = 2; //���콺 Ŭ�����¸� �ѱ�

                break;
            }
        }
    }
    gotoxy(0, 52);
    printf("x = %03d y = %03d", *xx, *yy);
}