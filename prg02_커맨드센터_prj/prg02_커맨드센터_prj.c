#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define WIDTH   52
#define HEIGHT  25

/*
üũ����Ʈ

(1) ��Ʈ��X : ���� ��� ����

(2) ������O : x ���� 0-92, y���� 0-25

(3) �������۹�O : �� : �� / �� : �� / ���� : s

(4) ���ھ� ǥ��O : �Ϲ� ���� * 100 / Ư�� ���� * 1000 / ���� ���� * 10000

(5) ������ ǥ��O : ���ΰ��� ��Ű�� Ŀ�ǵ弾���� ü�� 100
                   - ���� ��(*)�� �������� �� ���� ���ݷ¸�ŭ ü�� ����
                   - ���� ���ΰ��� �������� �� ���� ���ݷ� * 2 ��� ü�� ����

(6) �÷��̾�O : �¿칫��

(7) �÷��̾� �Ѿ�O : ���� 20�� / �ִ� 100��
                    �Ϲ� ���� óġ �� �Ѿ� + 3
                    Ư�� ���� óġ �� �Ѿ� + 6

(8) ��(1,2,3)X
                �Ϲ� ����(1) : ü�� 2, ���ݷ� 1
                Ư�� ����(2) : �¿칫��, ü�� 4, ���ݷ� 5
                ����(3) : ����ü ����, �¿칫��, 1,2�� ���� ����, ü�� 30, ���ݷ� 10

(9) ������(1, 2)X
                1 : ������ + 10
                2 : �Ѿ� ���� + 20

(10) �ƿ�Ʈ��X : ����

üũ����Ʈ �޼��� 60% (6 / 10)
*/
int  T_b = 0, cb, cb_a, c, c1;
char board[HEIGHT][WIDTH];
int boss_hp = 30;
int score = 0;//���� int ��

gotoxy(int x, int y)
{
    COORD pos = { x , y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CursorView()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
    cursorInfo.bVisible = FALSE; //Ŀ�� Visible TRUE(����) FALSE(����)
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
    printf("�ަ��� ��");
    gotoxy(20, 3);
    printf("�ۥ��ۣ���������");
    gotoxy(20, 4);
    printf("��               ��");
    gotoxy(20, 5);
    printf("��               ����");
    gotoxy(20, 6);
    printf("��𣢣����������");
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
    printf("��");//��� ������ �𼭸�

    for (int i = 1; i < 108; i++) {//�����
        printf("��");
    }

    printf("��");//������ ��� �𼭸�

    for (int i = 1; i < 25; i++) {
        gotoxy(0, i);
        printf("��");//���� ������
    }

    for (int i = 1; i < 25; i++) {
        gotoxy(108, i);
        printf("��");//������ ������
    }
    gotoxy(0, 25);

    printf("��");//���� �𼭸�

    for (int i = 1; i < 108; i++) {
        printf("��");//�ϴ���
    }

    printf("��");//�ϴ� ���� �𼭸�
    gotoxy(30, 3);
    printf("     �ð��� �������� ���� ���� �����մϴ�!");
    Sleep(1000);
    gotoxy(30, 5);
    printf("���� ""0""�� �� ���� �Ѿ��� ���� ���� �� �ֽ��ϴ�.");
    Sleep(800);
    gotoxy(34, 7);
    printf("���� ""1""�� �� ���� ���缭 ���� �� �ֽ��ϴ�.");
    Sleep(800);
    gotoxy(34, 10);
    printf("     �����κ��� ��(*)�� �����ּ���!");
    Sleep(1000);
    gotoxy(34, 14);
    printf("====  ����� ������ ���۵˴ϴ�!  =====");
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
    printf("========  ������ �����մϴ�  =========");

    Sleep(1500);
    system("cls");
}

void gamewin() {
    printf("��");//��� ������ �𼭸�

    for (int i = 1; i < 108; i++) {//�����
        printf("��");
    }

    printf("��");//������ ��� �𼭸�

    for (int i = 1; i < 25; i++) {
        gotoxy(0, i);
        printf("��");//���� ������
    }

    for (int i = 1; i < 25; i++) {
        gotoxy(108, i);
        printf("��");//������ ������
    }
    gotoxy(0, 25);

    printf("��");//���� �𼭸�

    for (int i = 1; i < 108; i++) {
        printf("��");//�ϴ���
    }

    printf("��");//�ϴ� ���� �𼭸�
    for (int i = 0; i < 6; i++) {
        for (int j = 8; j < 16; j++) {
            gotoxy(3, j);
            printf("                                                                                                         ");//
        }
        Sleep(300);
        gotoxy(3, 8);
        printf("           ��        ��  �������  ��        ��  ��  ���  ��  �������  ���      ��            ");//
        gotoxy(3, 9);
        printf("           ��        ��  ��        ��  ��        ��  ��  ���  ��  �������  ���      ��            ");//
        gotoxy(3, 10);
        printf("           ���    ���  ��        ��  ��        ��  �� ��  �� ��      ���      �� ��     ��            ");//
        gotoxy(3, 11);
        printf("             ��    ��    ��        ��  ��        ��  �� ��  �� ��      ���      ��  ��    ��            ");//
        gotoxy(3, 12);
        printf("              ����     ��        ��  ��        ��  ���    ���      ���      ��    ��  ��            ");//
        gotoxy(3, 13);
        printf("               ���      ��        ��  ��        ��  ���    ���      ���      ��     �� ��            ");//
        gotoxy(3, 14);
        printf("               ���      ��        ��  ��        ��  ��        ��  �������  ��      ���            ");//
        gotoxy(3, 15);
        printf("               ���      �������  �������  ��        ��  �������  ��      ���            ");//
        Sleep(700);
    }

    gotoxy(3, 20);
    printf("���� ���� : %d�� ", score);//

    gotoxy(0, 25);
    Sleep(1000);
}

void gameover() {
    printf("��");//��� ������ �𼭸�

    for (int i = 1; i < 108; i++) {//�����
        printf("��");
    }

    printf("��");//������ ��� �𼭸�

    for (int i = 1; i < 25; i++) {
        gotoxy(0, i);
        printf("��");//���� ������
    }

    for (int i = 1; i < 25; i++) {
        gotoxy(108, i);
        printf("��");//������ ������
    }
    gotoxy(0, 25);

    printf("��");//���� �𼭸�

    for (int i = 1; i < 108; i++) {
        printf("��");//�ϴ���
    }

    printf("��");//�ϴ� ���� �𼭸�


    for (int i = 0; i < 6; i++) {
        for (int j = 8; j < 16; j++) {
            gotoxy(3, j);
            printf("                                                                                                         ");//
        }
        Sleep(300);
        gotoxy(3, 8);
        printf("������� ������� ��        �� ������� ������� ��        �� ������� �������  ");//
        gotoxy(3, 9);
        printf("��        �� ��        �� ���    ��� ��           ��        �� ��        �� ��           ��        ��  ");//
        gotoxy(3, 10);
        printf("��        �� ��        �� ���    ��� ��           ��        �� ��        �� ��           ��        ��  ");//
        gotoxy(3, 11);
        printf("��           ��        �� �� ��  �� �� ��           ��        �� ��        �� ��           �������  ");//
        gotoxy(3, 12);
        printf("��    ���� ������� �� ��  �� �� ������� ��        �� ���    ��� ������� ��  ��  ");//
        gotoxy(3, 13);
        printf("��        �� ��        �� ��  ���  �� ��           ��        ��   ��    ��   ��           ��    ��  ");//
        gotoxy(3, 14);
        printf("��        �� ��        �� ��  ���  �� ��           ��        ��     ���     ��           ��      ��    ");//
        gotoxy(3, 15);
        printf("������� ��        �� ��  ���  �� ������� �������     ���     ������� ��        ��  ");//
        Sleep(700);
    }

    gotoxy(0, 25);
    Sleep(1000);
}

void game(void)
{
    char ch;
    int x = 25, y = 23, loc_b = 0, loc_ba = 0, loc, loc1; //�÷��̾� ���� ��ġ

    int wall = 100; // HP int ��
    int bullet = 20; //�Ѿ� int ��
    int T = 0;      // �ð�
    int a = 100;
    int b = 0;
    int e1 = 0;


    gotoxy(0, 0);

    printf("��");//��� ������ �𼭸�

    for (int i = 1; i < 52; i++) {//���� �����
        printf("��");
    }

    printf("��");//�߰� ǥ��

    for (int i = 53; i < 108; i++) {
        printf("��");//������ �����
    }

    printf("��");//������ ��� �𼭸�

    for (int i = 1; i < 25; i++) {
        gotoxy(0, i);
        printf("��");//���� ������
    }

    for (int i = 1; i < 25; i++) {
        gotoxy(52, i);
        printf("��");//��� ������
    }

    for (int i = 1; i < 25; i++) {
        gotoxy(108, i);
        printf("��");//������ ������
    }

    gotoxy(1, 24);

    for (int i = 1; i < 52; i++) {
        printf("*");//��
    }

    gotoxy(0, 25);

    printf("��");//���� �𼭸�

    for (int i = 1; i < 52; i++) {
        printf("��");//���� �ϴ���
    }

    printf("��");//�ϴ� �ߴ� ǥ��

    for (int i = 53; i < 108; i++) {
        printf("��");//������ �ϴ���
    }
    printf("��");//�ϴ� ���� �𼭸�

    gotoxy(60, 16);
    printf("<- : �������� �̵�");//���۹�
    gotoxy(60, 18);
    printf("<- : ���������� �̵�");//���۹�
    gotoxy(60, 20);
    printf("s  : �Ѿ˹߻�");//���۹�
    loc = target(); // ���� ��ǥ�� ���� + ��ǥ�� x��ǥ ��ȯ

    while (1)
    {
        CursorView();
        gotoxy(60, 3);
        printf("���� : %d        ", score); // ȭ��� ���� ǥ��
        printf("�ð� : %d", T); // ȭ��� ���� ǥ��
        gotoxy(60, 6);
        printf("�Ѿ� : %d / 30 ", bullet); // �Ѿ��� �� ǥ��
        gotoxy(60, 9);
        printf("HP :% d / 100 ", wall);// HP ǥ��
        gotoxy(60, 12);
        printf("���� HP :");// ���� HP ǥ��
        for (int i = 0; i < boss_hp / 3; i++) {
            gotoxy(70 + i * 2, 12);
            printf("��");
        }
        gotoxy(71 + boss_hp / 3 * 2, 12);
        printf("  ");


        gotoxy(x, y);
        printf("@"); //�÷��̾� ǥ��
        //���� ����
        if (T > 300 && T_b == 0) {
            loc_ba = boss_a();
            T_b++;
        }

        if (T_b == 1) {
            loc_b = boss();
        }

        T++;//T ����
        if (T == 150) {
            loc1 = target1();
        }
        Sleep(20);
        if (_kbhit()) {
            ch = _getch();
            if (a > 50 || a < 8) {//a�� 50 �̻��� �� �Ѿ��� �ȳ�����.
                if (ch == 's')
                {

                    b = x;
                    a = 23;
                    bullet--;//�Ѿ� �߻��ϸ� �پ��
                }
            }
            switch (ch)
            {
            case 75:
                if (x > 2) {
                    x--; // ����Ű �� 
                    gotoxy(x + 1, y);
                    printf("  ");
                    break;
                }

            case 77:
                if (x < 50) {
                    x++; //����Ű ��
                    gotoxy(x - 1, y);
                    printf("  ");
                    break;
                }
            }
        }

        //�Ѿ�
        if (a < 24) {
            a--;
            gotoxy(b, a);
            board[a][b] = 'l';
            printf("%c", board[a][b]); //�Ѿ��� x��ǥ���� ���� ���ư� 
            Sleep(5);
            gotoxy(b, a);
            printf(" "); //�Ѿ��� ������ ��ġ���� �������� ������ 
            board[a][b] = ' ';
            if (a < 2) {
                a = 100;
            }

        }

        //��("0")

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
            score += 19;//���� �Ѿ��� ������ ������ ǥ�ð� 10�ö�
            bullet += 2;//���� �Ѿ��� ������ �Ѿ��� ǥ�ð� 3�ö�
            if (bullet > 30) {
                bullet = 30;
            }
            loc = target();
        }


        //��("1")
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
                    score += 43;//���� �Ѿ��� ������ ������ ǥ�ð� 20�ö�
                    bullet += 3;//���� �Ѿ��� ������ �Ѿ��� ǥ�ð� 3�ö�
                    if (bullet > 30) {
                        bullet = 30;
                    }
                    loc1 = target1();
                    e1 = 0;
                }
            }
        }
        //���� ȭ��
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
                score += 36;//���� �Ѿ��� ������ ������ ǥ�ð� 20�ö�
                bullet += 2;//���� �Ѿ��� ������ �Ѿ��� ǥ�ð� 3�ö�
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