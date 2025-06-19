#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27


int dhahr[19][19] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, };//�ٵ��� 19*19
								//0: �������, 1: ������, 2: ��


int qkenrvks[19][19] = {
{1,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,2},
{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{8,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,9},
{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9},
{4,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,3}, };//0: ��, 1: ��, 2: ��, 3: ��, 4: ��, 5:��, 6: ��, 7: ��, 8: ��, 9: ��
//�ٵ��� ��� ���



int x = 9, y = 9;//���� Ŀ�� ��ġ (dhahr ���� ��ġ ����)
int victory = 0;//0: ��� ������, 1: ������ �¸�, 2: �� �¸�
int continue_ = 0;//���� ����ϱ�, 0: ���� �״�� ����, 1: �Ͻ������� ��������
int restart = 0;//���� �ٽ� ����, 0: ���� ��� ����, 1: ���� �ʱ�ȭ
int end = 0;//���� ����
int turn = 0;//1: ������ ����, 2: �� ����	


void gotoxy(int x, int y);//Ŀ���̵�
void CursorView(char show);//Ŀ�������(0: �����, 1: ���̱�)
void color(int color_num);//�� �����ϱ�
void PrintBackGround();//ȭ��ũ�� ����, ���(�⺻)ȭ�� ���
void print_qkenrvks();//�ٵ��� ���(=! ����ȭ�� ���!!)
void testprint_qkenrvks();//���� �ٵ��� ���(���ڷ� �׽�Ʈ)
void move(int turn);//�ٵϵ� ��ġ�� Ŀ�� �̵�, (������, ������ ���� �����ϱ�)
void right();//Ŀ�� ������ �̵�
void left();//Ŀ�� ���� �̵�
void up();//Ŀ�� ���� �̵�
void down();//Ŀ�� �Ʒ��� �̵�
void befor_cusor();//Ŀ�� �̵���, ���� Ŀ�� �����
void now_cusor();//Ŀ�� �̵���, Ŀ�� ��ġ ȭ�� ���
void put(int put_turn);//Ŀ�� ��ġ�� �ٵϵ� ����
void stop();//�Ͻ�����
void del_stopscreen();//�Ͻ����� ȭ�� ���ֱ� (�Ͻ�����ȭ��/stop() ����)
void reset();//�ٵ��� �ʱ�ȭ, �¸� �ʱ�ȭ, Ŀ����ġ �ʱ�ȭ, �� �� �ʱ�ȭ
void check_white(int board_white[19][19]);//�� �¸� Ȯ��
void check_black(int board_black[19][19]);//������ �¸� Ȯ��
void victory_screen(int victory_end);//��Ⱑ ������ �� �¸�ȭ�� ����, (�¸��� ��, �ٽ��ϱ�, ����ȭ��, ����)
void stop_vic();//�������� ȭ�����(��¦�̱�, �ٽ��ϱ�, ����)

//-----------------------start_screen�� �� �Լ���-----------------------
void start_screen_menu();//����ȭ�� ���, (���ӽ���, ����, ����)
void information_screen();//��������ȭ��, (���� ��Ģ, �浹 ��, ������ ����, ������, ����)
void end_main();//����ȭ�� ���� ����ȭ�� ���


void start_screen_menu()//����ȭ�� ���, (���ӽ���, ����, ����)
{
	char ch_main;
	int main_y = 8;

	color(105);
	gotoxy(30, 4);
	printf("��");
	gotoxy(17, 4);
	printf("��");
	gotoxy(21, 8);
	printf("�� ����");
	color(96);
	gotoxy(21, 4);
	printf(" �� �� ");
	gotoxy(21, 10);
	printf("����");
	gotoxy(21, 12);
	printf("����");
	color(105);
	gotoxy(18, main_y);
	printf("��");
	color(107);
	gotoxy(16, 16);
	printf("����: [�����̽���]");

	while (1)
	{
		//gotoxy(0, 0);
		//printf("main_y: %d", main_y);//�׽�Ʈ
		ch_main = _getch();
		switch (ch_main)
		{
		case UP:
		{
			color(96);
			gotoxy(18, main_y);
			printf("  ");
			gotoxy(21, 8);
			printf("�� ����");
			gotoxy(21, 10);
			printf("����");
			gotoxy(21, 12);
			printf("����");
			if (main_y == 8)
				main_y = 12;
			else
				main_y -= 2;
			break;
		}
		case DOWN:
		{
			color(96);
			gotoxy(18, main_y);
			printf("  ");
			gotoxy(21, 8);
			printf("�� ����");
			gotoxy(21, 10);
			printf("����");
			gotoxy(21, 12);
			printf("����");
			if (main_y == 12)
				main_y = 8;
			else
				main_y += 2;
			break;
		}
		case 32:
		{
			if (main_y == 8)//���ӽ���
			{
				return 0;
			}
			else if (main_y == 10)//����(��������)
			{
				color(102);
				gotoxy(25, 5);
				printf("            ");
				gotoxy(20, 8);
				printf("            ");
				gotoxy(20, 10);
				printf("            ");
				gotoxy(20, 12);
				printf("            ");
				gotoxy(16, 16);
				printf("                      ");
				gotoxy(14, main_y);
				printf("     ");

				information_screen();

				color(105);
				gotoxy(30, 4);
				printf("��");
				gotoxy(17, 4);
				printf("��");
				color(96);
				gotoxy(21, 8);
				printf("�� ����");
				gotoxy(21, 4);
				printf(" �� �� ");
				gotoxy(21, 10);
				printf("����");
				gotoxy(21, 12);
				printf("����");
				color(105);
				gotoxy(18, main_y);
				printf("��");
				color(107);
				gotoxy(16, 16);
				printf("����: [�����̽���]");
			}
			else if (main_y == 12)//����
			{
				color(102);
				gotoxy(20, 5);
				printf("              ");
				gotoxy(16, 8);
				printf("              ");
				gotoxy(16, 10);
				printf("              ");
				gotoxy(16, 12);
				printf("              ");
				gotoxy(16, 16);
				printf("                     ");
				gotoxy(16, main_y);
				printf("  ");

				end_main();

				color(105);
				gotoxy(30, 4);
				printf("��");
				gotoxy(17, 4);
				printf("��");
				color(96);
				gotoxy(21, 8);
				printf("�� ����");
				gotoxy(21, 4);
				printf(" �� �� ");
				gotoxy(21, 10);
				printf("����");
				gotoxy(21, 12);
				printf("����");
				color(105);
				gotoxy(18, main_y);
				printf("��");
				color(107);
				gotoxy(16, 16);
				printf("����: [�����̽���]");
			}
			break;
		}
		}
		color(105);
		gotoxy(18, main_y);
		printf("��");
		if (main_y == 8)
		{
			gotoxy(21, 8);
			printf("�� ����");
		}
		else if (main_y == 10)
		{
			gotoxy(21, 10);
			printf("����");
		}
		else if (main_y == 12)
		{
			gotoxy(21, 12);
			printf("����");
		}
	}
}


void information_screen()
{
	color(97);
	gotoxy(7, 6);
	printf("-");
	gotoxy(7, 8);
	printf("-");
	gotoxy(7, 10);
	printf("-");
	gotoxy(7, 12);
	printf("-");
	gotoxy(7, 14);
	printf("-");
	gotoxy(7, 16);
	printf("-");

	color(96);
	gotoxy(10, 6);
	printf("����, ����, �밢������ �����ؼ� �ڽ��� ���� 5�� ������ �¸��Ѵ�");
	gotoxy(10, 8);
	printf("�� ���� �����ư��� 1��1�� ������ �����Ѵ� (�浹 ��)");
	gotoxy(10, 10);
	printf("��,��,��,�� : ���� ���� Ŀ�� �̵�");
	gotoxy(10, 12);
	printf("SPACE bar : Ŀ����ġ�� �� ���� / ��ȣ�ۿ�");
	gotoxy(10, 14);
	printf("ESC : ���� �Ͻ�����");
	gotoxy(10, 16);
	printf("������ : ��ǿ�");
	color(107);
	gotoxy(12, 19);
	printf("����: fantaandgom@gmail.com");


	color(96);
	gotoxy(16, 21);
	printf("����ȭ������ ���ư���");

	char ch_information;
	color(105);
	gotoxy(12, 21);
	printf("��");
	gotoxy(39, 21);
	printf("��");

	while (1)
	{
		if (_kbhit())
		{
			ch_information = _getch();
			if (ch_information == 32)
			{
				color(97);
				gotoxy(7, 6);
				printf("                                                                       ");
				gotoxy(7, 8);
				printf("                                                                       ");
				gotoxy(7, 10);
				printf("                                                                       ");
				gotoxy(7, 12);
				printf("                                                                       ");
				gotoxy(7, 14);
				printf("                                                                       ");
				gotoxy(7, 16);
				printf("                                                                       ");
				gotoxy(7, 19);
				printf("                                                                       ");
				gotoxy(7, 21);
				printf("                                                                       ");
				
				return 0;
			}
		}
	}
}


void end_main()
{
	int main_finish_y = 11;
	char ch_finish;
	color(105);
	gotoxy(18, 11);
	printf("��");
	gotoxy(21, 11);
	printf("��");
	color(96);
	gotoxy(17, 9);
	printf("���� �Ͻðڽ��ϱ�?");
	gotoxy(20, 13);
	printf("�ƴϿ�");

	while (1)
	{
		ch_finish = _getch();

		switch (ch_finish)
		{
		case UP:
		{
			gotoxy(18, main_finish_y);
			printf("  ");
			if (main_finish_y == 11)
				main_finish_y = 13;
			else if (main_finish_y == 13)
				main_finish_y = 11;
			break;
		}
		case DOWN:
		{
			gotoxy(18, main_finish_y);
			printf("  ");
			if (main_finish_y == 11)
				main_finish_y = 13;
			else if (main_finish_y == 13)
				main_finish_y = 11;
			break;
		}
		case 32:
		{
			if (main_finish_y == 11)
			{
				exit(0);
			}
			else if (main_finish_y == 13)
			{
				gotoxy(10, 9);
				printf("                          ");
				gotoxy(10, 10);
				printf("                          ");
				color(102);
				gotoxy(10, 11);
				printf("                          ");
				gotoxy(10, 12);
				printf("                          ");
				gotoxy(10, 13);
				printf("                          ");

				return 0;

			}
		}
		}
		color(105);
		gotoxy(18, main_finish_y);
		printf("��");
		if (main_finish_y == 11)
		{
			gotoxy(21, 11);
			printf("��");
			color(96);
			gotoxy(20, 13);
			printf("�ƴϿ�");
		}
		else if (main_finish_y == 13)
		{
			gotoxy(20, 13);
			printf("�ƴϿ�");
			color(96);
			gotoxy(21, 11);
			printf("��");
		}
	}
}













void gotoxy(int x, int y)//Ŀ���̵�
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


void CursorView(char show)//Ŀ�������(0: �����, 1: ���̱�)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}


void color(int color_num)//�� �����ϱ�
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_num);
}


void PrintBackGround()//ȭ��ũ�� ����, ���(�⺻)ȭ�� ���
{
	system("mode con cols=80 lines=26");
	color(102);
	for (int i = 0; i <= 26; i++)
	{
		for (int l = 0; l <= 80; l++)
		{
			gotoxy(l, i);
			printf("��");
		}
	}
}


void print_qkenrvks()//�ٵ��� ���(=! ����ȭ�� ���!!)
{
	PrintBackGround();

	color(104);

	for (int i = 0; i <= 18; i++)
	{
		for (int l = 0; l <= 18; l++)
		{
			gotoxy(l * 2 + 6, i + 2);
			if (qkenrvks[i][l] == 0)
			{
				printf("��");
			}
			else if (qkenrvks[i][l] == 6)
			{
				printf("��");
			}
			else if (qkenrvks[i][l] == 7)
			{
				printf("��");
			}
			else if (qkenrvks[i][l] == 8)
			{
				printf("��");
			}
			else if (qkenrvks[i][l] == 9)
			{
				printf("��");
			}
			else if (qkenrvks[i][l] == 1)
			{
				printf("��");
			}
			else if (qkenrvks[i][l] == 2)
			{
				printf("��");
			}
			else if (qkenrvks[i][l] == 3)
			{
				printf("��");
			}
			else if (qkenrvks[i][l] == 4)
			{
				printf("��");
			}
			else if (qkenrvks[i][l] == 5)
			{
				printf("��");
			}
		}
	}

	color(97);
	gotoxy(50, 9);
	printf("��");
	gotoxy(50, 13);
	printf("��");
	gotoxy(46, 11);
	printf("��");
	gotoxy(54, 11);
	printf("��");
	color(96);
	gotoxy(50, 11);
	printf("��");

	//-----------------------------------------����Ű, ���� ���� ����ϱ� (������ ��)------------------

}


void testprint_qkenrvks()//���� �ٵ��� ���(���ڷ� �׽�Ʈ)
{
	color(96);
	gotoxy(0, 21);
	for (int i = 0; i <= 18; i++)
	{
		printf("     ");
		for (int l = 0; l <= 18; l++)
		{
			printf(" %d",dhahr[i][l]);
		}
		printf("\n");
	}
}


void move(int turn)//�ٵϵ� ��ġ�� Ŀ�� �̵�, (������, ������ ���� �����ϱ�)
{
	char ch;
	int next = 0;//���� ������ �� ���� �ѱ��(0: ���� ���� �ȳѾ, 1: ���� �ѱ��)

	//gotoxy(50, 26);
	//printf("turn: %d", turn);//�׽�Ʈ
	color(99);
	gotoxy(45, 7);
	printf("����: [�����̽���]");

	//-------------------����Ű ������ �� ��¦�̱�, ���� ���� ����ϱ�---------------
	while (1)
	{
		while (1)
		{
			ch = _getch();
			switch (ch)
			{
			case UP:
				up(); break;
			case DOWN:
				down(); break;
			case LEFT:
				left(); break;
			case RIGHT:
				right(); break;
			case 32:
			{
				if (dhahr[y][x] != 0)
					break;

				//gotoxy(50, 27);
				//printf("case32: %d", turn);//�׽�Ʈ

				put(turn);
				if (turn == 2)//���� ���ʰ� ���� �� �������� ���
				{
					color(96);
					gotoxy(50, 11);
					printf("��");

					//gotoxy(50, 28);
					//printf("%d: ��", turn);//�׽�Ʈ
				}
				else if (turn == 1)//���� ���ʰ� ���� �� �������� ���
				{
					color(111);
					gotoxy(50, 11);
					printf("��");
					
					//gotoxy(50, 28);
					//printf("%d: ��", turn);//�׽�Ʈ
				}

				next = 1;
				break;
			}
			case ESC:
				stop();
				return 0;
				break;
			}

			color(101);
			//gotoxy(50, 29);
			//printf("x: %d ", x);//�׽�Ʈ
			//gotoxy(57, 29);
			//printf("y: %d ", y);//�׽�Ʈ

			if (next == 1)
				break;
		}

		if (next == 1)
			next = 0; break;
	}
}


void up()//Ŀ�� ���� �̵�
{
	color(100);
	gotoxy(50, 9);
	printf("��");
	Sleep(100);
	color(97);
	gotoxy(50, 9);
	printf("��");

	befor_cusor();

	if (y >= 1)
		y--;

	now_cusor();
}


void down()//Ŀ�� �Ʒ��� �̵�
{

	color(100);
	gotoxy(50, 13);
	printf("��");
	Sleep(100);
	color(97);
	gotoxy(50, 13);
	printf("��");

	befor_cusor();

	if (y <= 17)
		y++;

	now_cusor();
}


void right()//Ŀ�� ������ �̵�
{
	color(100);
	gotoxy(54, 11);
	printf("��");
	Sleep(100);
	color(97);
	gotoxy(54, 11);
	printf("��");

	befor_cusor();

	if (x <= 17)
		x++;

	now_cusor();
}


void left()//Ŀ�� ���� �̵�
{
	color(100);
	gotoxy(46, 11);
	printf("��");
	Sleep(100);
	color(97);
	gotoxy(46, 11);
	printf("��");

	befor_cusor();
	
	if(x >= 1)
		x--;

	now_cusor();
}


void befor_cusor()//Ŀ�� �̵���, ���� Ŀ�� �����
{
	gotoxy(x * 2 + 6, y + 2);//���� Ŀ�� ��ġ

	//0: ��, 1: ��, 2: ��, 3: ��, 4: ��, 5:��, 6: ��, 7: ��, 8: ��, 9: ��
	if (dhahr[y][x] == 0)
	{
		color(104);

		if (qkenrvks[y][x] == 0)
			printf("��");
		else if (qkenrvks[y][x] == 1)
			printf("��");
		else if (qkenrvks[y][x] == 2)
			printf("��");
		else if (qkenrvks[y][x] == 3)
			printf("��");
		else if (qkenrvks[y][x] == 4)
			printf("��");
		else if (qkenrvks[y][x] == 5)
			printf("��");
		else if (qkenrvks[y][x] == 6)
			printf("��");
		else if (qkenrvks[y][x] == 7)
			printf("��");
		else if (qkenrvks[y][x] == 8)
			printf("��");
		else if (qkenrvks[y][x] == 9)
			printf("��");
	}
	else if (dhahr[y][x] == 1)
	{
		color(96);
		printf("��");
	}
	else if (dhahr[y][x] == 2)
	{
		color(111);
		printf("��");
	}
}


void now_cusor()//Ŀ�� �̵���, Ŀ�� ��ġ ȭ�� ���
{
	gotoxy(x * 2 + 6, y + 2);//���� Ŀ�� ��ġ

	//0: ��, 1: ��, 2: ��, 3: ��, 4: ��, 5:��, 6: ��, 7: ��, 8: ��, 9: ��
	if (dhahr[y][x] == 0)
	{
		color(152);

		if (qkenrvks[y][x] == 0)
			printf("��");
		else if (qkenrvks[y][x] == 1)
			printf("��");
		else if (qkenrvks[y][x] == 2)
			printf("��");
		else if (qkenrvks[y][x] == 3)
			printf("��");
		else if (qkenrvks[y][x] == 4)
			printf("��");
		else if (qkenrvks[y][x] == 5)
			printf("��");
		else if (qkenrvks[y][x] == 6)
			printf("��");
		else if (qkenrvks[y][x] == 7)
			printf("��");
		else if (qkenrvks[y][x] == 8)
			printf("��");
		else if (qkenrvks[y][x] == 9)
			printf("��");
	}
	else if (dhahr[y][x] == 1)
	{
		color(144);
		printf("��");
	}
	else if (dhahr[y][x] == 2)
	{
		color(159);
		printf("��");
	}
}


void put(int put_turn)//Ŀ�� ��ġ�� �ٵϵ� ����
{
	if (dhahr[y][x] == 0)//Ŀ����ġ ������� ��
		dhahr[y][x] = put_turn;//�ٵϵ� ���� (���� ���� turn �Է�)


	gotoxy(x * 2 + 6, y + 2);
	if (put_turn == 1)
	{
		color(144);
		printf("��");
	}
	else if (put_turn == 2)
	{
		color(159);
		printf("��");
	}
		
}


void stop()//�Ͻ�����
{
	color(96);
	gotoxy(50, 15);
	printf("����ϱ�");
	gotoxy(50, 17);
	printf("�ٽ��ϱ�");
	gotoxy(50, 19);
	printf("��    ��");

	color(105);
	gotoxy(46, 15);
	printf("��");

	char ch;
	int y = 15;
	while (1)
	{
		ch = _getch();
		switch (ch)
		{
		case UP:
		{
			gotoxy(46, y);
			printf("  ");

			if (y == 15)
				y = 19;
			else
				y -= 2;

			break;
		}
		case DOWN:
		{
			gotoxy(46, y);
			printf("  ");

			if (y == 19)
				y = 15;
			else
				y += 2;

			break;
		}
		case 32:
		{
			if (y == 15)
			{
				del_stopscreen();
				continue_ = 1;
				return 0;
			}
			else if (y == 17)
			{
				del_stopscreen();

				restart = 1;
				return 0;
			}	
			else if (y == 19)
			{
				del_stopscreen();

				end = 1;
				return 0;
			}

			break;
		}
		case ESC:
		{
			del_stopscreen();
			continue_ = 1;
			return 0;
		}
		}
		color(105);
		gotoxy(46, y);
		printf("��");
	}
}


void del_stopscreen()//�Ͻ����� ȭ�� ���ֱ� (�Ͻ�����ȭ��/stop() ����)
{
	gotoxy(46, 15);
	printf("  ");
	gotoxy(46, 17);
	printf("  ");
	gotoxy(46, 19);
	printf("  ");

	gotoxy(50, 15);
	printf("         ");
	gotoxy(50, 17);
	printf("         ");
	gotoxy(50, 19);
	printf("         ");
}


void reset()//�ٵ��� �ʱ�ȭ, �¸� �ʱ�ȭ, Ŀ����ġ �ʱ�ȭ, �� �� �ʱ�ȭ
{
	for (int i = 0; i <= 18; i++)//�ٵ��� �ʱ�ȭ
	{
		for (int l = 0; l <= 18; l++)
		{
			if (dhahr[i][l] != 0)
			{
				dhahr[i][l] = 0;
			}
		}
	}

	victory = 0;//�¸��ʱ�ȭ
	x = 9, y = 9;//Ŀ����ġ �ʱ�ȭ

}


void check_black(int board_black[19][19])//������ �¸� Ȯ��
{
	for (int i = 4; i <= 14; i++)
	{
		for (int l = 4; l <= 14; l++)
		{
			if (dhahr[i][l] == 1)//�� ��ġ�� ������ ���� �� 8�������� 5�� Ȯ��
			{
				if (victory == 0)
				{
					int vic = 1;
					for (int n = 1; n <= 4; n++)//��
					{
						if (dhahr[i - n][l] == 1)
							vic++;
						else
							break;

						if (vic == 5)
							victory = 1;
					}
				}

				if (victory == 0)
				{
					int vic = 1;
					for (int n = 1; n <= 4; n++)//��
					{
						if (dhahr[i - n][l + n] == 1)
							vic++;
						else
							break;

						if (vic == 5)
							victory = 1;
					}
				}

				if (victory == 0)
				{
					int vic = 1;
					for (int n = 1; n <= 4; n++)//��
					{
						if (dhahr[i][l + n] == 1)
							vic++;
						else
							break;

						if (vic == 5)
							victory = 1;
					}
				}

				if (victory == 0)
				{
					int vic = 1;
					for (int n = 1; n <= 4; n++)//��
					{
						if (dhahr[i + n][l + n] == 1)
							vic++;
						else
							break;

						if (vic == 5)
							victory = 1;
					}
				}

				if (victory == 0)
				{
					int vic = 1;
					for (int n = 1; n <= 4; n++)//��
					{
						if (dhahr[i + n][l] == 1)
							vic++;
						else
							break;

						if (vic == 5)
							victory = 1;
					}
				}

				if (victory == 0)
				{
					int vic = 1;
					for (int n = 1; n <= 4; n++)//��
					{
						if (dhahr[i + n][l - n] == 1)
							vic++;
						else
							break;

						if (vic == 5)
							victory = 1;
					}
				}

				if (victory == 0)
				{
					int vic = 1;
					for (int n = 1; n <= 4; n++)//��
					{
						if (dhahr[i][l - n] == 1)
							vic++;
						else
							break;

						if (vic == 5)
							victory = 1;
					}
				}

				if (victory == 0)
				{
					int vic = 1;
					for (int n = 1; n <= 4; n++)//��
					{
						if (dhahr[i - n][l - n] == 1)
							vic++;
						else
							break;

						if (vic == 5)
							victory = 1;
					}
				}
			}
		}
	}
}


void check_white(int board_white[19][19])//�� �¸� Ȯ��
{
	for (int i = 4; i <= 14; i++)
	{
		for (int l = 4; l <= 14; l++)
		{
			if (dhahr[i][l] == 2)//�� ��ġ�� �� ���� �� 8�������� 5�� Ȯ��
			{
				if (victory == 0)
				{
					int vic = 1;
					for (int n = 1; n <= 4; n++)//��
					{
						if (dhahr[i - n][l] ==2)
							vic++;
						else
							break;

						if (vic == 5)
							victory = 2;
					}
				}

				if (victory == 0)
				{
					int vic = 1;
					for (int n = 1; n <= 4; n++)//��
					{
						if (dhahr[i - n][l + n] ==2)
							vic++;
						else
							break;

						if (vic == 5)
							victory = 2;
					}
				}

				if (victory == 0)
				{
					int vic = 1;
					for (int n = 1; n <= 4; n++)//��
					{
						if (dhahr[i][l + n] ==2)
							vic++;
						else
							break;

						if (vic == 5)
							victory = 2;
					}
				}

				if (victory == 0)
				{
					int vic = 1;
					for (int n = 1; n <= 4; n++)//��
					{
						if (dhahr[i + n][l + n] ==2)
							vic++;
						else
							break;

						if (vic == 5)
							victory = 2;
					}
				}

				if (victory == 0)
				{
					int vic = 1;
					for (int n = 1; n <= 4; n++)//��
					{
						if (dhahr[i + n][l] ==2)
							vic++;
						else
							break;

						if (vic == 5)
							victory = 2;
					}
				}

				if (victory == 0)
				{
					int vic = 1;
					for (int n = 1; n <= 4; n++)//��
					{
						if (dhahr[i + n][l - n] ==2)
							vic++;
						else
							break;

						if (vic == 5)
							victory = 2;
					}
				}

				if (victory == 0)
				{
					int vic = 1;
					for (int n = 1; n <= 4; n++)//��
					{
						if (dhahr[i][l - n] ==2)
							vic++;
						else
							break;

						if (vic == 5)
							victory = 2;
					}
				}

				if (victory == 0)
				{
					int vic = 1;
					for (int n = 1; n <= 4; n++)//��
					{
						if (dhahr[i - n][l - n] ==2)
							vic++;
						else
							break;

						if (vic == 5)
							victory = 2;
					}
				}
			}
		}
	}
}


void victory_screen(int victory_end)//��Ⱑ ������ �� �¸�ȭ�� ����
{
	if (victory_end == 0)
		return 0;

	color(100);
	gotoxy(46, 2);
	printf("�١ڡ١ڡ١ڡ١ڡ�");
	gotoxy(46, 3);
	printf("��              ��");
	gotoxy(46, 4);
	printf("��              ��");
	gotoxy(46, 5);
	printf("��              ��");
	gotoxy(46, 6);
	printf("�١ڡ١ڡ١ڡ١ڡ�");

	
	color(111);

	gotoxy(50, 4);
	if (victory_end == 1)
	{
		color(96);
		printf("�� ��   ");
		color(97);
		printf("��");
	}
	else if (victory_end == 2)
	{
		color(111);
		printf("�� ��   ");
		color(97);
		printf("��");
	}

	stop_vic();
}



void stop_vic()//�������� ȭ�����(��¦�̱�, �ٽ��ϱ�, ����)
{
	int n = 0;
	color(96);
	gotoxy(50, 17);
	printf("�ٽ��ϱ�");
	gotoxy(50, 19);
	printf("��    ��");

	color(105);
	gotoxy(46, 17);
	printf("��");

	char ch;
	int y = 17;

	while (1)
	{
		{
			Sleep(20);
			color(100);
			gotoxy(46, 2);
			printf("�١ڡ١ڡ١ڡ١ڡ�");
			gotoxy(46, 3);
			printf("��              ��");
			gotoxy(46, 4);
			printf("��");
			gotoxy(62, 4);
			printf("��");
			gotoxy(46, 5);
			printf("��              ��");
			gotoxy(46, 6);
			printf("�١ڡ١ڡ١ڡ١ڡ�");

			Sleep(20);
			gotoxy(46, 2);
			printf("�ڡ١ڡ١ڡ١ڡ١�");
			gotoxy(46, 3);
			printf("��              ��");
			gotoxy(46, 4);
			printf("��");
			gotoxy(62, 4);
			printf("��");
			gotoxy(46, 5);
			printf("��              ��");
			gotoxy(46, 6);
			printf("�ڡ١ڡ١ڡ١ڡ١�");
		}

		if (_kbhit())
		{
			ch = _getch();
			switch (ch)
			{
			case UP:
			{
				gotoxy(46, y);
				printf("  ");

				if (y == 17)
					y = 19;
				else if (y == 19)
					y = 17;
				break;
			}
			case DOWN:
			{
				gotoxy(46, y);
				printf("  ");

				if (y == 19)
					y = 17;
				else if (y == 17)
					y = 19;
				break;
			}
			case 32:
			{
				if (y == 17)
				{
					del_stopscreen();

					restart = 1;
					return 0;
				}
				else if (y == 19)
				{
					del_stopscreen();

					end = 1;
					return 0;
				}

				break;
			}
			case ESC:
			{
				del_stopscreen();
				return 0;
			}
			}
			color(105);
			gotoxy(46, y);
			printf("��");
		}
	}
}