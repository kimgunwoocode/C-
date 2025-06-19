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
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, };//바둑판 19*19
								//0: 비어있음, 1: 검은돌, 2: 흰돌


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
{4,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,3}, };//0: ╂, 1: ┌, 2: ┐, 3: ┘, 4: └, 5:╋, 6: ┬, 7: ┴, 8: ├, 9: ┤
//바둑판 모양 출력



int x = 9, y = 9;//현재 커서 위치 (dhahr 변수 위치 기준)
int victory = 0;//0: 경기 진행중, 1: 검은돌 승리, 2: 흰돌 승리
int continue_ = 0;//게임 계속하기, 0: 게임 그대로 진행, 1: 일시정지후 게임진행
int restart = 0;//게임 다시 시작, 0: 게임 계속 진행, 1: 게임 초기화
int end = 0;//게임 종료
int turn = 0;//1: 검은돌 차례, 2: 흰돌 차례	


void gotoxy(int x, int y);//커서이동
void CursorView(char show);//커서숨기기(0: 숨기기, 1: 보이기)
void color(int color_num);//색 변경하기
void PrintBackGround();//화면크기 설정, 배경(기본)화면 출력
void print_qkenrvks();//바둑판 출력(=! 현재화면 출력!!)
void testprint_qkenrvks();//현재 바둑판 출력(숫자로 테스트)
void move(int turn);//바둑돌 위치할 커서 이동, (흰돌차례, 검은돌 차례 구분하기)
void right();//커서 오른쪽 이동
void left();//커서 왼쪽 이동
void up();//커서 위로 이동
void down();//커서 아래로 이동
void befor_cusor();//커서 이동시, 이전 커서 지우기
void now_cusor();//커서 이동시, 커서 위치 화면 출력
void put(int put_turn);//커서 위치에 바둑돌 놓기
void stop();//일시정지
void del_stopscreen();//일시정지 화면 없애기 (일시정지화면/stop() 전용)
void reset();//바둑판 초기화, 승리 초기화, 커서위치 초기화, 턴 수 초기화
void check_white(int board_white[19][19]);//흰돌 승리 확인
void check_black(int board_black[19][19]);//검은돌 승리 확인
void victory_screen(int victory_end);//경기가 끝났을 때 승리화면 띄우기, (승리한 돌, 다시하기, 메인화면, 종료)
void stop_vic();//경기종료시 화면출력(반짝이기, 다시하기, 종료)

//-----------------------start_screen에 들어갈 함수들-----------------------
void start_screen_menu();//시작화면 출력, (게임시작, 도움말, 종료)
void information_screen();//게임정보화면, (게임 규칙, 흑돌 선, 제작자 정보, 개발일, 메일)
void end_main();//메인화면 전용 종료화면 출력


void start_screen_menu()//시작화면 출력, (게임시작, 도움말, 종료)
{
	char ch_main;
	int main_y = 8;

	color(105);
	gotoxy(30, 4);
	printf("◈");
	gotoxy(17, 4);
	printf("◈");
	gotoxy(21, 8);
	printf("새 게임");
	color(96);
	gotoxy(21, 4);
	printf(" 오 목 ");
	gotoxy(21, 10);
	printf("도움말");
	gotoxy(21, 12);
	printf("종료");
	color(105);
	gotoxy(18, main_y);
	printf("▶");
	color(107);
	gotoxy(16, 16);
	printf("선택: [스페이스바]");

	while (1)
	{
		//gotoxy(0, 0);
		//printf("main_y: %d", main_y);//테스트
		ch_main = _getch();
		switch (ch_main)
		{
		case UP:
		{
			color(96);
			gotoxy(18, main_y);
			printf("  ");
			gotoxy(21, 8);
			printf("새 게임");
			gotoxy(21, 10);
			printf("도움말");
			gotoxy(21, 12);
			printf("종료");
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
			printf("새 게임");
			gotoxy(21, 10);
			printf("도움말");
			gotoxy(21, 12);
			printf("종료");
			if (main_y == 12)
				main_y = 8;
			else
				main_y += 2;
			break;
		}
		case 32:
		{
			if (main_y == 8)//게임시작
			{
				return 0;
			}
			else if (main_y == 10)//도움말(게임정보)
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
				printf("◈");
				gotoxy(17, 4);
				printf("◈");
				color(96);
				gotoxy(21, 8);
				printf("새 게임");
				gotoxy(21, 4);
				printf(" 오 목 ");
				gotoxy(21, 10);
				printf("도움말");
				gotoxy(21, 12);
				printf("종료");
				color(105);
				gotoxy(18, main_y);
				printf("▶");
				color(107);
				gotoxy(16, 16);
				printf("선택: [스페이스바]");
			}
			else if (main_y == 12)//종료
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
				printf("◈");
				gotoxy(17, 4);
				printf("◈");
				color(96);
				gotoxy(21, 8);
				printf("새 게임");
				gotoxy(21, 4);
				printf(" 오 목 ");
				gotoxy(21, 10);
				printf("도움말");
				gotoxy(21, 12);
				printf("종료");
				color(105);
				gotoxy(18, main_y);
				printf("▶");
				color(107);
				gotoxy(16, 16);
				printf("선택: [스페이스바]");
			}
			break;
		}
		}
		color(105);
		gotoxy(18, main_y);
		printf("▶");
		if (main_y == 8)
		{
			gotoxy(21, 8);
			printf("새 게임");
		}
		else if (main_y == 10)
		{
			gotoxy(21, 10);
			printf("도움말");
		}
		else if (main_y == 12)
		{
			gotoxy(21, 12);
			printf("종료");
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
	printf("가로, 세로, 대각선으로 연속해서 자신의 돌을 5개 놓으면 승리한다");
	gotoxy(10, 8);
	printf("두 명이 번갈아가며 1대1로 게임을 진행한다 (흑돌 선)");
	gotoxy(10, 10);
	printf("←,↑,→,↓ : 돌을 놓을 커서 이동");
	gotoxy(10, 12);
	printf("SPACE bar : 커서위치에 돌 놓기 / 상호작용");
	gotoxy(10, 14);
	printf("ESC : 게임 일시정지");
	gotoxy(10, 16);
	printf("개발자 : 김건우");
	color(107);
	gotoxy(12, 19);
	printf("메일: fantaandgom@gmail.com");


	color(96);
	gotoxy(16, 21);
	printf("메인화면으로 돌아가기");

	char ch_information;
	color(105);
	gotoxy(12, 21);
	printf("▶");
	gotoxy(39, 21);
	printf("◀");

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
	printf("▶");
	gotoxy(21, 11);
	printf("예");
	color(96);
	gotoxy(17, 9);
	printf("종료 하시겠습니까?");
	gotoxy(20, 13);
	printf("아니오");

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
		printf("▶");
		if (main_finish_y == 11)
		{
			gotoxy(21, 11);
			printf("예");
			color(96);
			gotoxy(20, 13);
			printf("아니오");
		}
		else if (main_finish_y == 13)
		{
			gotoxy(20, 13);
			printf("아니오");
			color(96);
			gotoxy(21, 11);
			printf("예");
		}
	}
}













void gotoxy(int x, int y)//커서이동
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


void CursorView(char show)//커서숨기기(0: 숨기기, 1: 보이기)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}


void color(int color_num)//색 변경하기
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_num);
}


void PrintBackGround()//화면크기 설정, 배경(기본)화면 출력
{
	system("mode con cols=80 lines=26");
	color(102);
	for (int i = 0; i <= 26; i++)
	{
		for (int l = 0; l <= 80; l++)
		{
			gotoxy(l, i);
			printf("■");
		}
	}
}


void print_qkenrvks()//바둑판 출력(=! 현재화면 출력!!)
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
				printf("╋");
			}
			else if (qkenrvks[i][l] == 6)
			{
				printf("┬");
			}
			else if (qkenrvks[i][l] == 7)
			{
				printf("┴");
			}
			else if (qkenrvks[i][l] == 8)
			{
				printf("├");
			}
			else if (qkenrvks[i][l] == 9)
			{
				printf("┤");
			}
			else if (qkenrvks[i][l] == 1)
			{
				printf("┌");
			}
			else if (qkenrvks[i][l] == 2)
			{
				printf("┐");
			}
			else if (qkenrvks[i][l] == 3)
			{
				printf("┘");
			}
			else if (qkenrvks[i][l] == 4)
			{
				printf("└");
			}
			else if (qkenrvks[i][l] == 5)
			{
				printf("╋");
			}
		}
	}

	color(97);
	gotoxy(50, 9);
	printf("▲");
	gotoxy(50, 13);
	printf("▼");
	gotoxy(46, 11);
	printf("◀");
	gotoxy(54, 11);
	printf("▶");
	color(96);
	gotoxy(50, 11);
	printf("●");

	//-----------------------------------------방향키, 현재 차례 출력하기 (검은돌 선)------------------

}


void testprint_qkenrvks()//현재 바둑판 출력(숫자로 테스트)
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


void move(int turn)//바둑돌 위치할 커서 이동, (흰돌차례, 검은돌 차례 구분하기)
{
	char ch;
	int next = 0;//돌을 놓았을 때 차례 넘기기(0: 아직 차례 안넘어감, 1: 차례 넘기기)

	//gotoxy(50, 26);
	//printf("turn: %d", turn);//테스트
	color(99);
	gotoxy(45, 7);
	printf("놓기: [스페이스바]");

	//-------------------방향키 눌렀을 때 반짝이기, 현재 차례 출력하기---------------
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
				//printf("case32: %d", turn);//테스트

				put(turn);
				if (turn == 2)//현재 차례가 흰일 때 다음차례 출력
				{
					color(96);
					gotoxy(50, 11);
					printf("●");

					//gotoxy(50, 28);
					//printf("%d: 검", turn);//테스트
				}
				else if (turn == 1)//현재 차례가 검일 때 다음차례 출력
				{
					color(111);
					gotoxy(50, 11);
					printf("●");
					
					//gotoxy(50, 28);
					//printf("%d: 흰", turn);//테스트
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
			//printf("x: %d ", x);//테스트
			//gotoxy(57, 29);
			//printf("y: %d ", y);//테스트

			if (next == 1)
				break;
		}

		if (next == 1)
			next = 0; break;
	}
}


void up()//커서 위로 이동
{
	color(100);
	gotoxy(50, 9);
	printf("▲");
	Sleep(100);
	color(97);
	gotoxy(50, 9);
	printf("▲");

	befor_cusor();

	if (y >= 1)
		y--;

	now_cusor();
}


void down()//커서 아래로 이동
{

	color(100);
	gotoxy(50, 13);
	printf("▼");
	Sleep(100);
	color(97);
	gotoxy(50, 13);
	printf("▼");

	befor_cusor();

	if (y <= 17)
		y++;

	now_cusor();
}


void right()//커서 오른쪽 이동
{
	color(100);
	gotoxy(54, 11);
	printf("▶");
	Sleep(100);
	color(97);
	gotoxy(54, 11);
	printf("▶");

	befor_cusor();

	if (x <= 17)
		x++;

	now_cusor();
}


void left()//커서 왼쪽 이동
{
	color(100);
	gotoxy(46, 11);
	printf("◀");
	Sleep(100);
	color(97);
	gotoxy(46, 11);
	printf("◀");

	befor_cusor();
	
	if(x >= 1)
		x--;

	now_cusor();
}


void befor_cusor()//커서 이동시, 이전 커서 지우기
{
	gotoxy(x * 2 + 6, y + 2);//현재 커서 위치

	//0: ╂, 1: ┌, 2: ┐, 3: ┘, 4: └, 5:╋, 6: ┬, 7: ┴, 8: ├, 9: ┤
	if (dhahr[y][x] == 0)
	{
		color(104);

		if (qkenrvks[y][x] == 0)
			printf("╂");
		else if (qkenrvks[y][x] == 1)
			printf("┌");
		else if (qkenrvks[y][x] == 2)
			printf("┐");
		else if (qkenrvks[y][x] == 3)
			printf("┘");
		else if (qkenrvks[y][x] == 4)
			printf("└");
		else if (qkenrvks[y][x] == 5)
			printf("╋");
		else if (qkenrvks[y][x] == 6)
			printf("┬");
		else if (qkenrvks[y][x] == 7)
			printf("┴");
		else if (qkenrvks[y][x] == 8)
			printf("├");
		else if (qkenrvks[y][x] == 9)
			printf("┤");
	}
	else if (dhahr[y][x] == 1)
	{
		color(96);
		printf("●");
	}
	else if (dhahr[y][x] == 2)
	{
		color(111);
		printf("●");
	}
}


void now_cusor()//커서 이동시, 커서 위치 화면 출력
{
	gotoxy(x * 2 + 6, y + 2);//현재 커서 위치

	//0: ╂, 1: ┌, 2: ┐, 3: ┘, 4: └, 5:╋, 6: ┬, 7: ┴, 8: ├, 9: ┤
	if (dhahr[y][x] == 0)
	{
		color(152);

		if (qkenrvks[y][x] == 0)
			printf("╂");
		else if (qkenrvks[y][x] == 1)
			printf("┌");
		else if (qkenrvks[y][x] == 2)
			printf("┐");
		else if (qkenrvks[y][x] == 3)
			printf("┘");
		else if (qkenrvks[y][x] == 4)
			printf("└");
		else if (qkenrvks[y][x] == 5)
			printf("╋");
		else if (qkenrvks[y][x] == 6)
			printf("┬");
		else if (qkenrvks[y][x] == 7)
			printf("┴");
		else if (qkenrvks[y][x] == 8)
			printf("├");
		else if (qkenrvks[y][x] == 9)
			printf("┤");
	}
	else if (dhahr[y][x] == 1)
	{
		color(144);
		printf("●");
	}
	else if (dhahr[y][x] == 2)
	{
		color(159);
		printf("●");
	}
}


void put(int put_turn)//커서 위치에 바둑돌 놓기
{
	if (dhahr[y][x] == 0)//커서위치 비어있을 때
		dhahr[y][x] = put_turn;//바둑돌 놓기 (현재 차례 turn 입력)


	gotoxy(x * 2 + 6, y + 2);
	if (put_turn == 1)
	{
		color(144);
		printf("●");
	}
	else if (put_turn == 2)
	{
		color(159);
		printf("●");
	}
		
}


void stop()//일시정지
{
	color(96);
	gotoxy(50, 15);
	printf("계속하기");
	gotoxy(50, 17);
	printf("다시하기");
	gotoxy(50, 19);
	printf("종    료");

	color(105);
	gotoxy(46, 15);
	printf("▶");

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
		printf("▶");
	}
}


void del_stopscreen()//일시정지 화면 없애기 (일시정지화면/stop() 전용)
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


void reset()//바둑판 초기화, 승리 초기화, 커서위치 초기화, 턴 수 초기화
{
	for (int i = 0; i <= 18; i++)//바둑판 초기화
	{
		for (int l = 0; l <= 18; l++)
		{
			if (dhahr[i][l] != 0)
			{
				dhahr[i][l] = 0;
			}
		}
	}

	victory = 0;//승리초기화
	x = 9, y = 9;//커서위치 초기화

}


void check_black(int board_black[19][19])//검은돌 승리 확인
{
	for (int i = 4; i <= 14; i++)
	{
		for (int l = 4; l <= 14; l++)
		{
			if (dhahr[i][l] == 1)//이 위치에 검은돌 있을 때 8방향으로 5목 확인
			{
				if (victory == 0)
				{
					int vic = 1;
					for (int n = 1; n <= 4; n++)//↑
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
					for (int n = 1; n <= 4; n++)//↗
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
					for (int n = 1; n <= 4; n++)//→
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
					for (int n = 1; n <= 4; n++)//↘
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
					for (int n = 1; n <= 4; n++)//↓
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
					for (int n = 1; n <= 4; n++)//↙
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
					for (int n = 1; n <= 4; n++)//←
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
					for (int n = 1; n <= 4; n++)//↖
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


void check_white(int board_white[19][19])//흰돌 승리 확인
{
	for (int i = 4; i <= 14; i++)
	{
		for (int l = 4; l <= 14; l++)
		{
			if (dhahr[i][l] == 2)//이 위치에 흰돌 있을 때 8방향으로 5목 확인
			{
				if (victory == 0)
				{
					int vic = 1;
					for (int n = 1; n <= 4; n++)//↑
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
					for (int n = 1; n <= 4; n++)//↗
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
					for (int n = 1; n <= 4; n++)//→
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
					for (int n = 1; n <= 4; n++)//↘
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
					for (int n = 1; n <= 4; n++)//↓
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
					for (int n = 1; n <= 4; n++)//↙
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
					for (int n = 1; n <= 4; n++)//←
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
					for (int n = 1; n <= 4; n++)//↖
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


void victory_screen(int victory_end)//경기가 끝났을 때 승리화면 띄우기
{
	if (victory_end == 0)
		return 0;

	color(100);
	gotoxy(46, 2);
	printf("☆★☆★☆★☆★☆");
	gotoxy(46, 3);
	printf("★              ★");
	gotoxy(46, 4);
	printf("☆              ☆");
	gotoxy(46, 5);
	printf("★              ★");
	gotoxy(46, 6);
	printf("☆★☆★☆★☆★☆");

	
	color(111);

	gotoxy(50, 4);
	if (victory_end == 1)
	{
		color(96);
		printf("흑 돌   ");
		color(97);
		printf("승");
	}
	else if (victory_end == 2)
	{
		color(111);
		printf("흰 돌   ");
		color(97);
		printf("승");
	}

	stop_vic();
}



void stop_vic()//경기종료시 화면출력(반짝이기, 다시하기, 종료)
{
	int n = 0;
	color(96);
	gotoxy(50, 17);
	printf("다시하기");
	gotoxy(50, 19);
	printf("종    료");

	color(105);
	gotoxy(46, 17);
	printf("▶");

	char ch;
	int y = 17;

	while (1)
	{
		{
			Sleep(20);
			color(100);
			gotoxy(46, 2);
			printf("☆★☆★☆★☆★☆");
			gotoxy(46, 3);
			printf("★              ★");
			gotoxy(46, 4);
			printf("☆");
			gotoxy(62, 4);
			printf("☆");
			gotoxy(46, 5);
			printf("★              ★");
			gotoxy(46, 6);
			printf("☆★☆★☆★☆★☆");

			Sleep(20);
			gotoxy(46, 2);
			printf("★☆★☆★☆★☆★");
			gotoxy(46, 3);
			printf("☆              ☆");
			gotoxy(46, 4);
			printf("★");
			gotoxy(62, 4);
			printf("★");
			gotoxy(46, 5);
			printf("☆              ☆");
			gotoxy(46, 6);
			printf("★☆★☆★☆★☆★");
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
			printf("▶");
		}
	}
}