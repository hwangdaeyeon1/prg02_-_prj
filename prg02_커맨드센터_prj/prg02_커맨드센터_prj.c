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

int bullet = 20; //�Ѿ� int ��
char board[HEIGHT][WIDTH];

gotoxy(int x, int y)
{
    COORD pos = { x , y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void shoot(int x)
{
    int y = 22;
    
    /*for (y = 22; y >= 1; y--) {
        gotoxy(x, y);
        printf("|");
        Sleep(20);
    }
    return;*/

    board[y][x] = 'l';
    bullet--;//�Ѿ� �߻��ϸ� �پ��

        gotoxy(x, y);
        board[y][x] = 'l';
        printf("%c", board[y][x]); //ȭ���� x��ǥ���� ���� ���ư� 
        Sleep(50);
        gotoxy(x, y);
        printf(" "); //ȭ���� ������ ��ġ���� �������� ������ 
        board[y][x] = ' ';
   
}

int target(void)
{
    srand((unsigned int)time(NULL));

    int x = rand() % 51;
    int y = 2;
    gotoxy(x, y);
    printf("@");

    return x;
}

void game(void)
{
    char ch;
    int x = 25, y = 23, loc; //�÷��̾� ���� ��ġ
    int score = 0;//���� int ��
    int wall = 100; // �� int ��

    gotoxy(0, 0);

    printf("��");//��� ������ �𼭸�

    for (int i = 1; i < 52; i++) {//���� �����
        printf("��");
    }

    printf("��");//�߰� ǥ��

    for (int i = 53; i < 92; i++) {
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
        gotoxy(92, i);
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

    for (int i = 53; i < 92; i++) {
        printf("��");//������ �ϴ���
    }
    printf("��");//�ϴ� ���� �𼭸�

    gotoxy(60, 3);
    printf("���� : %d", score); // ȭ��� ���� ǥ��
    gotoxy(60, 6);
    printf("�Ѿ� : %d / 100", bullet); // �Ѿ��� �� ǥ��
    gotoxy(60, 9);
    printf("���� ������ :% d / 100", wall);// ���� ������ ǥ��
    gotoxy(60, 19);
    printf("<- : �������� �̵�");//���۹�
    gotoxy(60, 21);
    printf("<- : ���������� �̵�");//���۹�
    gotoxy(60, 23);
    printf("s : �Ѿ˹߻�");//���۹�
    loc = target(); // ���� ��ǥ�� ���� + ��ǥ�� x��ǥ ��ȯ
    int T = 0;
    int a = 100;
    int s_x;
    while (1)
    {
        gotoxy(60, 3);
        printf("���� : %d", T); // ȭ��� ���� ǥ��
        gotoxy(60, 6);
        printf("�Ѿ� : %d / 100", bullet); // �Ѿ��� �� ǥ��
        gotoxy(60, 9);
        printf("���� ������ :% d / 100", wall);// ���� ������ ǥ��
        gotoxy(x, y);
        printf("@"); //�÷��̾� ǥ��

        T++;//T ����
        Sleep(20);
        if (_kbhit()) {
            ch = _getch();
            if (ch == 's')
            {
                s_x = x;
                a = 22;
                shoot(x);
                if (loc == x) {
                    score += 100;//���� �Ѿ��� ������ ������ ǥ�ð� 10�ö�
                    bullet += 3;//���� �Ѿ��� ������ �Ѿ��� ǥ�ð� 3�ö�
                    loc = target();
                }
            }
            if (a < 23) {
                a--;
                gotoxy(s_x, a);
                board[a][s_x] = 'l';
                printf("%c", board[a][s_x]); //ȭ���� x��ǥ���� ���� ���ư� 
                Sleep(10);
                gotoxy(s_x, a);
                printf(" "); //ȭ���� ������ ��ġ���� �������� ������ 
                board[a][s_x] = ' ';
                if (a < 2) {
                    a = 100;
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