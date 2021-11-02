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
        printf("|"); //화살이 x좌표에서 위로 날아감 
        Sleep(20);
        gotoxy(x, y);
        printf(" "); //화살이 지나간 위치에는 공백으로 지워줌 
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
        printf("@"); //화살이 x좌표에서 위로 날아감 
        Sleep(100);
        gotoxy(x2, y2);
        printf(" "); //화살이 지나간 위치에는 공백으로 지워줌 
    }*/

    return x2;
}

void game(void)
{
    char ch;
    int x = 25, y = 24, loc; //플레이어 시작 위치 x:39 y:24 
    int score = 0;
    int Oldscore = 0;

    gotoxy(0, 0);

    printf("┏");

    for (int i = 1; i < 52; i++) {
        printf("━");
    }
    printf("┓");
    
    for (int i = 1; i < 25; i++) {
        gotoxy(0, i);
        printf("┃");
    }
    
    for (int i = 1; i < 25; i++) {
        gotoxy(52, i);
        printf("┃");
    }

    gotoxy(0, 25);

    printf("┗");

    for (int i = 1; i < 52; i++) {
        printf("━");
    }
    printf("┛");

    gotoxy(55, 0);
    printf("score : %d", score);

    loc = target(); // 최초 목표물 생성 + 목표물 x좌표 반환

    while (1)
    {
        gotoxy(55, 0);
        printf("score : %d", score);

        gotoxy(x, y);
        printf("[@]"); //플레이어 표시 
        ch = getch();

        Oldscore = score; // 몬스터를 처치하면 스코어 상승


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
                x--; // 방향키 ← 
                gotoxy(x + 1, y);
                printf("    ");
                break;
            }

        case 77:
            if (x < 51) {
                x++; //방향키 →
                gotoxy(x - 1, y);
                printf("    ");
                break;
            }
        case 72:
            if (y > 0) {
                y--; // 방향키 ↑
                gotoxy(x, y + 1);
                printf("    ");
                break;
            }
        case 80:
            if (y < 24) {
                y++; //방향키 ↓
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
    cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
    cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

int main(void)
{
    CursorView();
    game();
}