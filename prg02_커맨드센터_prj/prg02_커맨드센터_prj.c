#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define WIDTH   52
#define HEIGHT  25

/*
체크리스트

(1) 인트로X : 게임 배경 설명

(2) 게임판O : x 길이 0-92, y길이 0-25

(3) 게임조작법O : 좌 : ← / 우 : → / 공격 : s

(4) 스코어 표시O : 일반 좀비 * 100 / 특수 좀비 * 1000 / 보스 좀비 * 10000

(5) 라이프 표시O : 주인공이 지키는 커맨드센터의 체력 100
                   - 좀비가 벽(*)을 공격했을 시 좀비 공격력만큼 체력 깎임
                   - 좀비가 주인공을 공격했을 시 좀비 공격력 * 2 배로 체력 깎임

(6) 플레이어O : 좌우무빙

(7) 플레이어 총알O : 시작 20발 / 최대 100발
                    일반 좀비 처치 시 총알 + 3
                    특수 좀비 처치 시 총알 + 6

(8) 적(1,2,3)X
                일반 좀비(1) : 체력 2, 공격력 1
                특수 좀비(2) : 좌우무빙, 체력 4, 공격력 5
                보스(3) : 투사체 공격, 좌우무빙, 1,2번 좀비 생성, 체력 30, 공격력 10

(9) 아이템(1, 2)X
                1 : 라이프 + 10
                2 : 총알 보급 + 20

(10) 아웃트로X : 엔딩

체크리스트 달성률 60% (6 / 10)
*/
int  T_b = 0, cb, cb_a, c, c1;
char board[HEIGHT][WIDTH];
int boss_hp = 30;
int score = 0;//점수 int 값

gotoxy(int x, int y)
{
    COORD pos = { x , y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CursorView()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
    cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}


int target(void)
{
    srand((unsigned int)time(NULL));

    int x = ((rand() + 3) % 49) + 2;
    int y = 2;
    if (T_b == 0) {
        y = 2;
    }
    else
    {
        y = 8;
    }
    gotoxy(x, y);
    printf("0");
    c = y;
    return x;
}

int target1(void)
{
    srand((unsigned int)time(NULL) / 2);
    int x = ((rand() + 2) % 49) + 2;
    int y = 8;
    gotoxy(x, y);
    printf("1");
    c1 = y;
    return x;
}

int boss(void)
{

    gotoxy(20, 2);
    printf("＾── ＾");
    gotoxy(20, 3);
    printf("ⓞωⓞ＂＂＂＂＂");
    gotoxy(20, 4);
    printf("＂               ＂");
    gotoxy(20, 5);
    printf("＂               ＂＂");
    gotoxy(20, 6);
    printf("ㆀㆀ＂＂＂＂＂ㆀㆀ");
    cb = 5;
    return 20;
}

int boss_a(void)
{
    srand((unsigned int)time(NULL) / 5);
    int x = (rand() % 49) + 2;
    int y = 8;
    gotoxy(x, y);
    printf("v");
    cb_a = y;
    return x;
}


void opening() {
    printf("┏");//상단 오른쪽 모서리

    for (int i = 1; i < 108; i++) {//상단줄
        printf("━");
    }

    printf("┓");//오른쪽 상단 모서리

    for (int i = 1; i < 25; i++) {
        gotoxy(0, i);
        printf("┃");//왼쪽 세로줄
    }

    for (int i = 1; i < 25; i++) {
        gotoxy(108, i);
        printf("┃");//오른쪽 세로줄
    }
    gotoxy(0, 25);

    printf("┗");//왼쪽 모서리

    for (int i = 1; i < 108; i++) {
        printf("━");//하단줄
    }

    printf("┛");//하단 왼쪽 모서리
    gotoxy(30, 3);
    printf("     시간이 지날수록 강한 적이 등장합니다!");
    Sleep(1000);
    gotoxy(30, 5);
    printf("몬스터 ""0""은 한 발의 총알을 쏴서 죽일 수 있습니다.");
    Sleep(800);
    gotoxy(34, 7);
    printf("몬스터 ""1""은 두 발을 맞춰서 죽일 수 있습니다.");
    Sleep(800);
    gotoxy(34, 10);
    printf("     적으로부터 벽(*)을 지켜주세요!");
    Sleep(1000);
    gotoxy(34, 14);
    printf("====  잠시후 게임이 시작됩니다!  =====");
    Sleep(800);
    gotoxy(34, 14);
    printf("========           3         =========");
    Sleep(800);
    gotoxy(34, 14);
    printf("========           2         =========");
    Sleep(800);
    gotoxy(34, 14);
    printf("========           1         =========");
    Sleep(800);
    gotoxy(34, 14);
    printf("========  게임을 시작합니다  =========");

    Sleep(1500);
    system("cls");
}

void gamewin() {
    printf("┏");//상단 오른쪽 모서리

    for (int i = 1; i < 108; i++) {//상단줄
        printf("━");
    }

    printf("┓");//오른쪽 상단 모서리

    for (int i = 1; i < 25; i++) {
        gotoxy(0, i);
        printf("┃");//왼쪽 세로줄
    }

    for (int i = 1; i < 25; i++) {
        gotoxy(108, i);
        printf("┃");//오른쪽 세로줄
    }
    gotoxy(0, 25);

    printf("┗");//왼쪽 모서리

    for (int i = 1; i < 108; i++) {
        printf("━");//하단줄
    }

    printf("┛");//하단 왼쪽 모서리
    for (int i = 0; i < 6; i++) {
        for (int j = 8; j < 16; j++) {
            gotoxy(3, j);
            printf("                                                                                                         ");//
        }
        Sleep(300);
        gotoxy(3, 8);
        printf("           ■        ■  ■■■■■■  ■        ■  ■  ■■  ■  ■■■■■■  ■■      ■            ");//
        gotoxy(3, 9);
        printf("           ■        ■  ■        ■  ■        ■  ■  ■■  ■  ■■■■■■  ■■      ■            ");//
        gotoxy(3, 10);
        printf("           ■■    ■■  ■        ■  ■        ■  ■ ■  ■ ■      ■■      ■ ■     ■            ");//
        gotoxy(3, 11);
        printf("             ■    ■    ■        ■  ■        ■  ■ ■  ■ ■      ■■      ■  ■    ■            ");//
        gotoxy(3, 12);
        printf("              ■■■     ■        ■  ■        ■  ■■    ■■      ■■      ■    ■  ■            ");//
        gotoxy(3, 13);
        printf("               ■■      ■        ■  ■        ■  ■■    ■■      ■■      ■     ■ ■            ");//
        gotoxy(3, 14);
        printf("               ■■      ■        ■  ■        ■  ■        ■  ■■■■■■  ■      ■■            ");//
        gotoxy(3, 15);
        printf("               ■■      ■■■■■■  ■■■■■■  ■        ■  ■■■■■■  ■      ■■            ");//
        Sleep(700);
    }

    gotoxy(3, 20);
    printf("최종 점수 : %d점 ", score);//

    gotoxy(0, 25);
    Sleep(1000);
}

void gameover() {
    printf("┏");//상단 오른쪽 모서리

    for (int i = 1; i < 108; i++) {//상단줄
        printf("━");
    }

    printf("┓");//오른쪽 상단 모서리

    for (int i = 1; i < 25; i++) {
        gotoxy(0, i);
        printf("┃");//왼쪽 세로줄
    }

    for (int i = 1; i < 25; i++) {
        gotoxy(108, i);
        printf("┃");//오른쪽 세로줄
    }
    gotoxy(0, 25);

    printf("┗");//왼쪽 모서리

    for (int i = 1; i < 108; i++) {
        printf("━");//하단줄
    }

    printf("┛");//하단 왼쪽 모서리


    for (int i = 0; i < 6; i++) {
        for (int j = 8; j < 16; j++) {
            gotoxy(3, j);
            printf("                                                                                                         ");//
        }
        Sleep(300);
        gotoxy(3, 8);
        printf("■■■■■■ ■■■■■■ ■        ■ ■■■■■■ ■■■■■■ ■        ■ ■■■■■■ ■■■■■■  ");//
        gotoxy(3, 9);
        printf("■        ■ ■        ■ ■■    ■■ ■           ■        ■ ■        ■ ■           ■        ■  ");//
        gotoxy(3, 10);
        printf("■        ■ ■        ■ ■■    ■■ ■           ■        ■ ■        ■ ■           ■        ■  ");//
        gotoxy(3, 11);
        printf("■           ■        ■ ■ ■  ■ ■ ■           ■        ■ ■        ■ ■           ■■■■■■  ");//
        gotoxy(3, 12);
        printf("■    ■■■ ■■■■■■ ■ ■  ■ ■ ■■■■■■ ■        ■ ■■    ■■ ■■■■■■ ■  ■  ");//
        gotoxy(3, 13);
        printf("■        ■ ■        ■ ■  ■■  ■ ■           ■        ■   ■    ■   ■           ■    ■  ");//
        gotoxy(3, 14);
        printf("■        ■ ■        ■ ■  ■■  ■ ■           ■        ■     ■■     ■           ■      ■    ");//
        gotoxy(3, 15);
        printf("■■■■■■ ■        ■ ■  ■■  ■ ■■■■■■ ■■■■■■     ■■     ■■■■■■ ■        ■  ");//
        Sleep(700);
    }

    gotoxy(0, 25);
    Sleep(1000);
}

void game(void)
{
    char ch;
    int x = 25, y = 23, loc_b = 0, loc_ba = 0, loc, loc1; //플레이어 시작 위치

    int wall = 100; // HP int 값
    int bullet = 20; //총알 int 값
    int T = 0;      // 시간
    int a = 100;
    int b = 0;
    int e1 = 0;


    gotoxy(0, 0);

    printf("┏");//상단 오른쪽 모서리

    for (int i = 1; i < 52; i++) {//왼쪽 상단줄
        printf("━");
    }

    printf("┳");//중간 표시

    for (int i = 53; i < 108; i++) {
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
        gotoxy(108, i);
        printf("┃");//오른쪽 세로줄
    }

    gotoxy(1, 24);

    for (int i = 1; i < 52; i++) {
        printf("*");//벽
    }

    gotoxy(0, 25);

    printf("┗");//왼쪽 모서리

    for (int i = 1; i < 52; i++) {
        printf("━");//왼쪽 하단줄
    }

    printf("┻");//하단 중단 표시

    for (int i = 53; i < 108; i++) {
        printf("━");//오른쪽 하단줄
    }
    printf("┛");//하단 왼쪽 모서리

    gotoxy(60, 16);
    printf("<- : 왼쪽으로 이동");//조작법
    gotoxy(60, 18);
    printf("<- : 오른쪽으로 이동");//조작법
    gotoxy(60, 20);
    printf("s  : 총알발사");//조작법
    loc = target(); // 최초 목표물 생성 + 목표물 x좌표 반환

    while (1)
    {
        CursorView();
        gotoxy(60, 3);
        printf("점수 : %d        ", score); // 화면상 점수 표시
        printf("시간 : %d", T); // 화면상 점수 표시
        gotoxy(60, 6);
        printf("총알 : %d / 30 ", bullet); // 총알의 수 표시
        gotoxy(60, 9);
        printf("HP :% d / 100 ", wall);// HP 표시
        gotoxy(60, 12);
        printf("보스 HP :");// 보스 HP 표시
        for (int i = 0; i < boss_hp / 3; i++) {
            gotoxy(70 + i * 2, 12);
            printf("■");
        }
        gotoxy(71 + boss_hp / 3 * 2, 12);
        printf("  ");


        gotoxy(x, y);
        printf("@"); //플레이어 표시
        //보스 생성
        if (T > 300 && T_b == 0) {
            loc_ba = boss_a();
            T_b++;
        }

        if (T_b == 1) {
            loc_b = boss();
        }

        T++;//T 설정
        if (T == 150) {
            loc1 = target1();
        }
        Sleep(20);
        if (_kbhit()) {
            ch = _getch();
            if (a > 50 || a < 8) {//a가 50 이상일 떄 총알이 안나간다.
                if (ch == 's')
                {

                    b = x;
                    a = 23;
                    bullet--;//총알 발사하면 줄어듬
                }
            }
            switch (ch)
            {
            case 75:
                if (x > 2) {
                    x--; // 방향키 ← 
                    gotoxy(x + 1, y);
                    printf("  ");
                    break;
                }

            case 77:
                if (x < 50) {
                    x++; //방향키 →
                    gotoxy(x - 1, y);
                    printf("  ");
                    break;
                }
            }
        }

        //총알
        if (a < 24) {
            a--;
            gotoxy(b, a);
            board[a][b] = 'l';
            printf("%c", board[a][b]); //총알이 x좌표에서 위로 날아감 
            Sleep(5);
            gotoxy(b, a);
            printf(" "); //총알이 지나간 위치에는 공백으로 지워줌 
            board[a][b] = ' ';
            if (a < 2) {
                a = 100;
            }

        }

        //적("0")

        if (T % 22 == 1) {
            gotoxy(loc, c - 1);
            printf(" ");
            Sleep(5);
            gotoxy(loc, c++);
            printf("0");
            if (c == 24) {
                Sleep(20);
                gotoxy(loc, c - 1);
                printf(" ");
                wall -= 10;
                loc = target();

            }
        }
        if (loc == b && a == c) {
            score += 19;//적에 총알이 닿으면 점수의 표시가 10올라감
            bullet += 2;//적에 총알이 닿으면 총알의 표시가 3올라감
            if (bullet > 30) {
                bullet = 30;
            }
            loc = target();
        }


        //적("1")
        if (T > 150) {
            if (T % 31 == 1) {
                gotoxy(loc1, c1 - 1);
                printf(" ");
                Sleep(5);
                gotoxy(loc1, c1++);
                printf("1");
                if (c1 == 24) {
                    Sleep(20);
                    gotoxy(loc1, c1 - 1);
                    printf(" ");
                    wall -= 15;
                    e1 = 0;
                    loc1 = target1();


                }
            }
            if (loc1 == b && a == c1) {
                e1++;
                if (e1 >= 2) {
                    score += 43;//적에 총알이 닿으면 점수의 표시가 20올라감
                    bullet += 3;//적에 총알이 닿으면 총알의 표시가 3올라감
                    if (bullet > 30) {
                        bullet = 30;
                    }
                    loc1 = target1();
                    e1 = 0;
                }
            }
        }
        //보스 화살
        if (loc_ba > 0) {
            if (T % 13 == 1) {
                gotoxy(loc_ba, cb_a - 1);
                printf(" ");
                Sleep(5);
                gotoxy(loc_ba, cb_a++);
                printf("v");
                if (cb_a == 24) {
                    Sleep(20);
                    gotoxy(loc_ba, cb_a - 1);
                    printf(" ");
                    wall -= 20;
                    loc_ba = boss_a();

                }
            }
            if (loc_ba == b && a == cb_a) {
                score += 36;//적에 총알이 닿으면 점수의 표시가 20올라감
                bullet += 2;//적에 총알이 닿으면 총알의 표시가 3올라감
                if (bullet > 30) {
                    bullet = 30;
                }
                loc_ba = boss_a();
            }
        }
        if (loc_b > 0) {
            if (b > 19 && b < 41 && a == cb) {
                boss_hp--;
                if (boss_hp == -1) {
                    gotoxy(20, 2);
                    printf("                           ");
                    gotoxy(20, 3);
                    printf("                           ");
                    gotoxy(20, 4);
                    printf("                           ");
                    gotoxy(20, 5);
                    printf("                           ");
                    gotoxy(20, 6);
                    printf("                           ");

                    score += 5000;
                    Sleep(500);
                    T_b++;
                }
            }
        }

        if (bullet < 0 || wall < 1 || boss_hp <= 0) {
            break;
        }
    }
}



int main(void)
{
    CursorView();
    opening();
    system("cls");
    game();
    system("cls");
    if (boss_hp <= 0) {
        gamewin();
    }
    else {
        gameover();
    }
    return 0;

}