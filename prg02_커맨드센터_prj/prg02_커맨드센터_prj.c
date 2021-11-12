#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define _CRT_SECURE_NO_WARNINGS
#define WIDTH   52
#define HEIGHT  25

char board[HEIGHT][WIDTH]; // �÷��̾� ������
int boss_hp = 30; // ���� HP
int score = 0;//���� int ��
int T = 0;    // �ð�
int T_b = 0, cb_hit, cb_a, c, c1;
// c : "0"�� y��         c1 : "1"�� y��             T_b : ����(on/off)
// cb_a : ���� ȭ�� y��  cb_hit : ���� ��Ʈ�ڽ� y��

gotoxy(int x, int y) // ��ǥ �̵�
{
    COORD pos = { x , y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CursorView() // Ŀ�� �����
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
    cursorInfo.bVisible = FALSE; //Ŀ�� Visible TRUE(����) FALSE(����)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

int target(void) // ù ��° ��("0")
{
    //srand((unsigned int)time(NULL));
    srand((int)time(NULL));

    int x = ((rand() * 37) % 49) + 2;
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

int target1(void) // �� ��° ��("1")
{
    //srand((unsigned int)time(NULL) / 2);
    srand((int)time(NULL));
    int x = ((rand() * 29) % 49) + 2;
    int y = 8;
    gotoxy(x, y);
    printf("1");
    c1 = y;
    return x;
}

int boss(void) // ����
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
    cb_hit = 5; // ��Ʈ�ڽ� ���� y��
    return 20;
}

int boss_a(void) // ���� ȭ��
{
    //srand((unsigned int)time(NULL) / 5);
    srand((int)time(NULL));

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

    printf("��");//��� ������ �𼭸�

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

    printf("��");//�ϴ� ������ �𼭸�

    gotoxy(20, 3);
    printf("�����κ��� ��(*)�� �����ּ���!");
    gotoxy(51, 3);
    printf("�ð��� �������� ���� ���� �����մϴ�!");
    Sleep(1200);

    gotoxy(8, 5);
    printf("���� ""0,"" ""v ""�� �� �߸� ���絵 ���� �� �ֽ��ϴ�!");
    gotoxy(56, 5);
    printf("���� ""1 ""�� �� ���� ���缭 ���� �� �ֽ��ϴ�!");
    Sleep(1200);

    gotoxy(25, 7);
    printf("���� ""0,"" ""1,"" ""v"" �� ���̸� �Ѿ˰� ü���� ���� �� �ֽ��ϴ�!");
    Sleep(1200);

    gotoxy(12, 9);
    printf("�ð��� ������ ���� ������ ��Ÿ���ϴ�.");
    gotoxy(51, 9);
    printf("���� ������ ���� �� �����ؾ� ���� �� �ֽ��ϴ�!");
    Sleep(1200);

    gotoxy(19, 11);
    printf("���� �����ϸ� ��� ���߷��� ������");
    gotoxy(55, 11);
    printf("�ָ� �ִ� ���� ���� �� ���� �˴ϴ�!");
    Sleep(1200);

    gotoxy(28, 13);
    printf("�Ѿ� Ȥ�� �÷��̾� HP�� 0�� �Ǹ� �й��ϰ� �˴ϴ�!");
    Sleep(1200);

    int start = 1;

    while (start) {
        gotoxy(19, 16);
        printf("====  ���̵��� ����ּ���! EASY : (e)   NORMAL : (n)  HARD : (h) ======");
        switch (_getch())
        {
        case 'e': boss_hp = 30;
            start = 0;
            break;
        case 'E': boss_hp = 30;
            start = 0;
            break;
        case 'n': boss_hp = 50;
            start = 0;
            break;
        case 'N': boss_hp = 50;
            start = 0;
            break;
        case 'h': boss_hp = 100;
            start = 0;
            break;
        case 'H': boss_hp = 100;
            start = 0;
            break;
        }
    }

    gotoxy(20, 16);
    printf("========     ������ �����Ͻðڽ��ϱ�? Enter�� �����ּ���!     ========");
    Sleep(700);

    while(_getch() != '\r'){
    }

    gotoxy(20, 16);
    printf("========              ����� ������ ���۵˴ϴ�!               ========");
    Sleep(1000);
    gotoxy(20, 16);
    printf("========                          3                           ========");
    Sleep(1000);
    gotoxy(20, 16);
    printf("========                          2                           ========");
    Sleep(1000);
    gotoxy(20, 16);
    printf("========                          1                           ========");
    Sleep(1000);
    gotoxy(20, 16);
    printf("========                          0                           ========");
    Sleep(1000);
    gotoxy(20, 16);
    printf("========                  ������ �����մϴ�!                  ========");

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
        for (int j = 8; j < 21; j++) {
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
        gotoxy(30, 20);
        printf("���� ���� : %d�� ", score);
        gotoxy(60, 20);
        printf("�÷��� Ÿ�� : %d ", T);
        Sleep(700);
    }

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
    int x = 25, y = 23, loc_ba = 0, loc, loc1; //�÷��̾� ���� ��ġ
    // loc, loc1 : ��("0", "1")�� x��ǥ     loc_ba : ���� ȭ���� x��ǥ

    int wall = 50; // HP int ��
    int bullet = 20; //�Ѿ� int ��
    int a = 100; // �Ѿ� y��
    int b = 0;   // �Ѿ� x��
    int e1 = 0;  // ��("1")�� ü��(�Ѿ��� ���� Ƚ��)
    int boss_starthp = boss_hp; // ���̵� ������ ���� ��

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
    printf("S  : ����");//���۹�
    loc = target(); // ���� ��ǥ�� ���� + ��ǥ�� x��ǥ ��ȯ

    while (1)
    {
        CursorView();
        gotoxy(60, 3);
        printf("���� : %d        ", score); // ���� ǥ��
        printf("�ð� : %d ", T); // �ð� ǥ��
        gotoxy(60, 6);
        printf("�Ѿ� : %d / 30 ", bullet); // �Ѿ� �� ǥ��
        gotoxy(60, 9);
        printf("�÷��̾� HP :% d / 50 ", wall);// HP ǥ��
        

        gotoxy(x, y);
        printf("@"); //�÷��̾� ǥ��

        // ���ӽð��� 150�� �Ǹ� ��("1") ����
        if (T == 150) {
            loc1 = target1();
        }

        // ���ӽð��� 300�� �ʰ��ϸ� ���� ȭ�� ����
        if (T == 300) {
            loc_ba = boss_a();
            T_b++; // ���� ON
        }
        // T_b == 1 �ݺ��� ���� ���ǹ�
        if (T_b == 1) {
            boss(); // ���� ����
            gotoxy(60, 12);
            printf("���� HP :");// ���� HP ǥ��. ü�� 10 �� ��� ǥ��
            if (boss_starthp < 31) {
                for (int i = 0; i < boss_hp / 3; i++) {
                    gotoxy(70 + i * 2, 12);
                    printf("��");
                }
                gotoxy(71 + boss_hp / 3 * 2, 12); // ����ü�¿��� 3�� ���ҵ� ������ �� �ϳ� �پ��.
                printf("  ");
                gotoxy(70, 14);
                printf("����HP : %d  ", boss_hp);
            }
            else if(boss_starthp < 51) {
                for (int i = 0; i < boss_hp / 5; i++) {
                    gotoxy(70 + i * 2, 12);
                    printf("��");
                }
                gotoxy(71 + boss_hp / 5 * 2, 12); // ����ü�¿��� 5�� ���ҵ� ������ �� �ϳ� �پ��.
                printf("  ");
                gotoxy(70, 14);
                printf("����HP : %d  ", boss_hp);
            }
            else {
                for (int i = 0; i < boss_hp / 10; i++) {
                    gotoxy(70 + i * 2, 12);
                    printf("��");
                }
                gotoxy(71 + boss_hp / 10 * 2, 12); // ����ü�¿��� 10�� ���ҵ� ������ �� �ϳ� �پ��.
                printf("  ");
                gotoxy(70, 14);
                printf("����HP : %d  ", boss_hp);
            }
        }

        T++;//T ����
        
        Sleep(10);

        // kbhit ������ �༭ ������ ���� �۵��ϵ���
        if (_kbhit()) {
            ch = _getch();
            if (a > 50 || a < 5) {//a�� 50 �̻��� �� �Ѿ��� �� ��.(��Ÿ �Ұ���)
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
            printf("%c", board[a][b]); //��ǥ�� �޾� �Ѿ��� ���� �߻���
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
            Sleep(8);
            gotoxy(loc, c++);
            printf("0");
            if (c == 24) { // ���� �÷��̾�� ���� y�� ��ġ(24)���� ���� HP�� ���ҽ�Ű�� �ٽ� ��("0") ����
                Sleep(20);
                gotoxy(loc, c - 1);
                printf(" ");
                wall -= 11; // HP 10 ����
                loc = target(); // ������

            }
        }
        // b�� �÷��̾ ���� �� �� x��, loc�� ���� x��, a�� �Ѿ��� y��, c�� ���� y��
        if (loc == b && a == c) {
            score += 19;//���� ���߸� ���� + 19
            wall += 1;
            if (wall > 50) {
                wall = 50;
            }
            bullet += 2;//���� ���߸� 2�� ����
            // �Ѿ��� �ִ� 20�߱��� ä�� �� �ִ�
            if (bullet > 20) {
                bullet = 20;
            }
            loc = target();
        }

        //��("1")
        if (T > 150) {
            if (T % 31 == 1) {
                gotoxy(loc1, c1 - 1);
                printf(" ");
                Sleep(3);
                gotoxy(loc1, c1++);
                printf("1");
                if (c1 == 24) { // ���� �÷��̾�� ���� y�� ��ġ(�ǹ�)���� ���� HP�� ���ҽ�Ű�� �ٽ� ��("1") ����
                    Sleep(20);
                    gotoxy(loc1, c1 - 1);
                    printf(" ");
                    wall -= 15; //HP 10 ����
                    e1 = 0; //���� �ٽ� ������ �� ���� ü���� �ʱ�ȭ
                    loc1 = target1();
                }
            }
            // b�� �÷��̾ ���� �� �� x��, loc1�� ���� x��, a�� �Ѿ��� y��, c1�� ���� y��
            if (loc1 == b && a == c1) {
                e1++; // �Ѿ��� ���� Ƚ�� + 1
                // ���� Ƚ���� 2 �̻��̸� ���� ���� ������ ����
                if (e1 >= 2) {
                    score += 43;//���� ���߸� ���� + 43
                    wall += 2;
                    if (wall > 50) {
                        wall = 50;
                    }
                    bullet += 3;//���� ���߸� 3�� ����
                    if (bullet > 20) {
                        bullet = 20;
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
                    wall -= 18;        // ���� ȭ�쿡 ������ HP - 20
                    loc_ba = boss_a(); // ���� ȭ���� x��
                }
            }
            if (loc_ba == b && a == cb_a) {
                score += 36;//���� ���߸� ���� + 36
                wall += 1;
                if (wall > 50) {
                    wall = 50;
                }
                bullet += 1;//���� ���߸� 3�� ����
                if (bullet > 20) {
                    bullet = 20;
                }
                loc_ba = boss_a();
            }
        }
        // ������ ������ 
        if (T_b > 0) {
            // �÷��̾� �Ѿ��� x���� 20~40�̰� y���� cb(���� ��Ʈ�ڽ�y��)�̸� ���� HP ����
            if (b > 19 && b < 41 && a == cb_hit) {
                boss_hp--;
                // ���� HP�� 0 ���Ϸ� �������� ���� ����
                if (boss_hp < 1) {

                    score += 5000;
                    gotoxy(60, 3);
                    printf("���� : %d ", score); // ���� ǥ��
                    gotoxy(60, 12);
                    printf("���� HP :");// ���� HP ǥ��. ü�� 10 �� ��� ǥ��
                    gotoxy(70, 12);
                    printf("    ");

                    for (int i = 1; i < 10; i++) {
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

                        Sleep(1000/i);

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

                        Sleep(1000/i);
                    }
                }
            }
        }
        // �Ѿ��� 0 �̸��� �ǰų� �÷��̾� HP�� 1 �̸��� �ǰų� ������ HP�� 0 ���ϰ� �Ǿ��� �� ���� ����
        if (bullet < 0 || wall < 1 || boss_hp < 1) {
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
    //game()�� break �Ǿ��� �� ������ ���� ��� �¸� ȭ���� �����ش�.
    if (boss_hp <= 0) {
        gamewin();
    }
    //������ ���� ���� ��� �й� ȭ���� �����ش�.
    else {
        gameover();
    }
    return 0;
}