#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include"����.h"


void start_screen();//����ȭ�� ��� (���ӽ���, ��������, ����)
void game_screen();//����ȭ�� ��� (��������, �Ͻ�����)


void start_screen()
{
	PrintBackGround();
	start_screen_menu();
}


void game_screen()
{
	int num = 1;//�� ������ ����
	int n = 0;//���� �� ����
	print_qkenrvks();
	color(152);
	gotoxy(x * 2 + 6, y + 2);//���� Ŀ�� ��ġ
	printf("��");
	while (1)
	{
		//------
		//gotoxy(50, 25);
		//printf("main: %d", num);
		//gotoxy(50, 24);
		//printf("count: %d", n);
		n++;
		//---�׽�Ʈ
		move(num);//Ŀ�� �����̱�, �� ����

		//testprint_qkenrvks();//�׽�Ʈ

		check_black(dhahr);//������ Ȯ��
		check_white(dhahr);//�� Ȯ��

		victory_screen(victory);


		if (continue_ == 1)
		{
			continue_ = 0;
			continue;
		}
		else if (restart == 1)//���� �ٽ� ����
		{
			restart = 0;
			reset();//���� �ʱ�ȭ
			return 0;
		}
		else if (end == 1)
		{
			return 0;
		}

		if (num == 1)
			num = 2;
		else if (num == 2)
			num = 1;

	}
}


int main()
{
	CursorView(0);
	start_screen();
	while (1)//���� �ٽ� ������ �� �ݺ��ϱ�
	{
		game_screen();

		if (end == 1)
		{
			PrintBackGround();
			color(96);
			gotoxy(5, 5);
			return 0;
		}
	}
}