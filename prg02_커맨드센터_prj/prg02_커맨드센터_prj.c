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
int c;
int c1;

char board[HEIGHT][WIDTH];

gotoxy(int x, int y)
{
    COORD pos = { x , y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int target(void)
{
    srand((unsigned int)time(NULL));

    int x = (rand() % 49) + 2;
    int y = 2;
    gotoxy(x, y);
    printf("0");
    c = y;
    return x;
}
int target1(void)
{
    srand((unsigned int)time(NULL)/2);
    int x = (rand() % 49) + 2;
    int y = 8;
    gotoxy(x, y);
    printf("1");
    c1 = y;
    return x;
}


void game(void)
{
    char ch;
    int x = 25, y = 23, loc, loc1; //�÷��̾� ���� ��ġ
    int score = 0;//���� int ��
    int wall = 100; // �� int ��
    int bullet = 20; //�Ѿ� int ��
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
    printf("HP :% d / 100", wall);// HP ǥ��
    gotoxy(60, 19);
    printf("<- : �������� �̵�");//���۹�
    gotoxy(60, 21);
    printf("<- : ���������� �̵�");//���۹�
    gotoxy(60, 23);
    printf("s : �Ѿ˹߻�");//���۹�
    loc = target(); // ���� ��ǥ�� ���� + ��ǥ�� x��ǥ ��ȯ
  
    int T = 0;
    int a = 100;
    int b = 0;
    int e1 = 0;
    while (1)
    {
        gotoxy(60, 3);
        printf("���� : %d", score); // ȭ��� ���� ǥ��
        gotoxy(60, 6);
        printf("�Ѿ� : %d / 100", bullet); // �Ѿ��� �� ǥ��
        gotoxy(60, 9);
        printf("HP :% d / 100", wall);// HP ǥ��
        gotoxy(60, 12);
        printf("�ð� :% d", T);// �ð� ǥ��
      
        
        gotoxy(x, y);
        printf("@"); //�÷��̾� ǥ��

        T++;//T ����
        if (T == 300) {
            loc1 = target1();
        }
        Sleep(20);
        if (_kbhit()) {
            ch = _getch();
            if(a > 50){//a�� 50 �̻��� �� �Ѿ��� �ȳ�����.
            if (ch == 's')
            {
   
                b = x;
                a = 22;
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
                    gotoxy(x -1, y);
                    printf("  ");
                    break;
                }
            }
        }

        //�Ѿ�
        if (a < 23) {
            a--;
            gotoxy(b, a);
            board[a][b] = 'l';
            printf("%c", board[a][b]); //�Ѿ��� x��ǥ���� ���� ���ư� 
            Sleep(10);
            gotoxy(b, a);
            printf(" "); //�Ѿ��� ������ ��ġ���� �������� ������ 
            board[a][b] = ' ';
            if (a < 2) {
                a = 100;
            }

        }

        //��("0")
        if(T % 20 == 1){
        gotoxy(loc, c - 1);
        printf(" ");
        Sleep(5);
        gotoxy(loc, c++);
        printf("0");
        if (c == 24) {
            Sleep(20);
            gotoxy(loc, c - 1);
            printf(" ");
            loc = target();
            wall -= 5;
        }
        }
        if (loc == b && a == c) {
            score += 10;//���� �Ѿ��� ������ ������ ǥ�ð� 10�ö�
            bullet += 3;//���� �Ѿ��� ������ �Ѿ��� ǥ�ð� 3�ö�
            loc = target();
        }
        //��("1")
        if(T>300){
            if (T % 30 == 1) {
                gotoxy(loc1, c1 - 1);
                printf(" ");
                Sleep(5);
                gotoxy(loc1, c1++);
                printf("1");
                if (c1 == 24) {
                    Sleep(20);
                    gotoxy(loc1, c1 - 1);
                    printf(" ");
                    loc1 = target1();
                    wall -= 10;
                }
            }
            if (loc1 == b && a == c1) {
                e1++;
                if(e1 >= 2){
                    score += 20;//���� �Ѿ��� ������ ������ ǥ�ð� 20�ö�
                    bullet += 3;//���� �Ѿ��� ������ �Ѿ��� ǥ�ð� 3�ö�
                    loc1 = target1();
                    e1 = 0;
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
    return 0;
}