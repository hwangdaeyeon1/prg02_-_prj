// ���� 1

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

gotoxy(int x, int y)
{
    COORD pos = { x , y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

gotoxy2(int x2, int y2)
{
    COORD pos = { x2 , y2 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void shoot(int x)
{
    int y;

    for (y = 10; y >= 1; y--)
    {
        gotoxy(x, y);
        printf("|"); //ȭ���� x��ǥ���� ���� ���ư� 
        Sleep(20);
        gotoxy(x, y);
        printf(" "); //ȭ���� ������ ��ġ���� �������� ������ 
    }
}

int target(void)
{
    int num = 0;
    int x2 = rand() % 51;
    int y2 = 2;
    gotoxy2(x2, y2);
    printf("@");
    
    /*for (y2 = 2; y2 <= 24; y2++)
    {
        gotoxy(x2, y2);
        printf("@"); //ȭ���� x��ǥ���� ���� ���ư� 
        Sleep(100);
        gotoxy(x2, y2);
        printf(" "); //ȭ���� ������ ��ġ���� �������� ������ 
    }*/

    return x2;
}

void game(void)
{
    char ch;
    int x = 25, y = 24, loc; //�÷��̾� ���� ��ġ x:39 y:24 
    int score = 0;
    int Oldscore = 0;

    gotoxy(0, 0);
    for (int i = 0; i < 53; i++) {
        printf("��");
    }

    gotoxy(0, 25);
    for (int i = 0; i < 53; i++) {
        printf("��");
    }

    gotoxy(55, 0);
    printf("score : %d", score);

    loc = target(); // ���� ��ǥ�� ���� + ��ǥ�� x��ǥ ��ȯ

    while (1)
    {
        gotoxy(55, 0);
        printf("score : %d", score);

        gotoxy(x, y);
        printf("[@]"); //�÷��̾� ǥ�� 
        ch = getch();

        Oldscore = score; // ���͸� óġ�ϸ� ���ھ� ���


        if (ch == 's')
        {
            shoot(x);
            if (loc == x) {
                score += 10;
                loc = target();
            }
        }

        switch (ch)
        {
        case 75:
            if (x > 0) {
                x--; // ����Ű �� 
                gotoxy(x + 1, y);
                printf("    ");
                break;
            }

        case 77:
            if (x < 51) {
                x++; //����Ű ��
                gotoxy(x - 1, y);
                printf("    ");
                break;
            }
        case 72:
            if (y > 0) {
                y--; // ����Ű ��
                gotoxy(x, y + 1);
                printf("    ");
                break;
            }
        case 80:
            if (y < 24) {
                y++; //����Ű ��
                gotoxy(x, y - 1);
                printf("    ");
                break;
            }
        }
        gotoxy(x, y);
        printf("[@]");
    }
}

void CursorView()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
    cursorInfo.bVisible = FALSE; //Ŀ�� Visible TRUE(����) FALSE(����)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

int main(void)
{
    CursorView();
    game();
}