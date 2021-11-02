#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
int bullet = 20; //�Ѿ� int ��

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
    bullet--;//�Ѿ� �߻��ϸ� �پ��
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

    return x2;
}

void game(void)
{
    char ch;
    int x = 25, y = 24, loc; //�÷��̾� ���� ��ġ x:39 y:24 
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

    while (1)
    {
        gotoxy(60, 3);
        printf("���� : %d", score); // ȭ��� ���� ǥ��
        gotoxy(60, 6);
        printf("�Ѿ� : %d / 100", bullet); // �Ѿ��� �� ǥ��
        gotoxy(60, 9);
        printf("���� ������ :% d / 100", wall);// ���� ������ ǥ��
        gotoxy(x, y);
        printf("[��]"); //�÷��̾� ǥ�� 
        ch = getch();

 


        if (ch == 's')
        {
            shoot(x);
            if (loc == x) {
                score += 10;//���� �Ѿ��� ������ ������ ǥ�ð� 10�ö�
                bullet += 3;//���� �Ѿ��� ������ �Ѿ��� ǥ�ð� 3�ö�
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
        gotoxy(x, y);//�÷��̾� ������ġ
        printf("[@]");//�÷��̾� ǥ��
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