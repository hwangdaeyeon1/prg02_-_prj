#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
int bullet = 20; //총알 int 값

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
    bullet--;//총알 발사하면 줄어듬
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

    return x2;
}

void game(void)
{
    char ch;
    int x = 25, y = 24, loc; //플레이어 시작 위치 x:39 y:24 
    int score = 0;//점수 int 값
    int wall = 100; // 벽 int 값

    gotoxy(0, 0);

    printf("┏");//상단 오른쪽 모서리

    for (int i = 1; i < 52; i++) {//왼쪽 상단줄
        printf("━");
    }

    printf("┳");//중간 표시

    for (int i = 53; i < 92; i++) {
        printf("━");//오른쪽 상단줄
    }

    printf("┓");//오른쪽 상단 모서리
    
    for (int i = 1; i < 25; i++) {
        gotoxy(0, i);
        printf("┃");//왼쪽 세로줄
    }
    
    for (int i = 1; i < 25; i++) {
        gotoxy(52, i);
        printf("┃");//가운데 세로줄
    }

    for (int i = 1; i < 25; i++) {
        gotoxy(92, i);
        printf("┃");//오른쪽 세로줄
    }

    gotoxy(0, 25);

    printf("┗");//왼쪽 모서리

    for (int i = 1; i < 52; i++) {
        printf("━");//왼쪽 하단줄
    }

    printf("┻");//하단 중단 표시

    for (int i = 53; i < 92; i++) {
        printf("━");//오른쪽 하단줄
    }
    printf("┛");//하단 왼쪽 모서리

    gotoxy(60, 3);
    printf("점수 : %d", score); // 화면상 점수 표시
    gotoxy(60, 6);
    printf("총알 : %d / 100", bullet); // 총알의 수 표시
    gotoxy(60, 9);
    printf("벽의 내구성 :% d / 100", wall);// 벽의 내구성 표시
    gotoxy(60, 19);
    printf("<- : 왼쪽으로 이동");//조작법
    gotoxy(60, 21);
    printf("<- : 오른쪽으로 이동");//조작법
    gotoxy(60, 23);
    printf("s : 총알발사");//조작법
    loc = target(); // 최초 목표물 생성 + 목표물 x좌표 반환

    while (1)
    {
        gotoxy(60, 3);
        printf("점수 : %d", score); // 화면상 점수 표시
        gotoxy(60, 6);
        printf("총알 : %d / 100", bullet); // 총알의 수 표시
        gotoxy(60, 9);
        printf("벽의 내구성 :% d / 100", wall);// 벽의 내구성 표시
        gotoxy(x, y);
        printf("[★]"); //플레이어 표시 
        ch = getch();

 


        if (ch == 's')
        {
            shoot(x);
            if (loc == x) {
                score += 10;//적에 총알이 닿으면 점수의 표시가 10올라감
                bullet += 3;//적에 총알이 닿으면 총알의 표시가 3올라감
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
        gotoxy(x, y);//플레이어 현제위치
        printf("[@]");//플레이어 표시
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