#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include"오목.h"


void start_screen();//시작화면 출력 (게임시작, 게임정보, 종료)
void game_screen();//오목화면 출력 (게임진행, 일시정지)


void start_screen()
{
	PrintBackGround();
	start_screen_menu();
}


void game_screen()
{
	int num = 1;//흰돌 검은돌 차례
	int n = 0;//현재 수 개수
	print_qkenrvks();
	color(152);
	gotoxy(x * 2 + 6, y + 2);//시작 커서 위치
	printf("╂");
	while (1)
	{
		//------
		//gotoxy(50, 25);
		//printf("main: %d", num);
		//gotoxy(50, 24);
		//printf("count: %d", n);
		n++;
		//---테스트
		move(num);//커서 움직이기, 돌 놓기

		//testprint_qkenrvks();//테스트

		check_black(dhahr);//검은돌 확인
		check_white(dhahr);//흰돌 확인

		victory_screen(victory);


		if (continue_ == 1)
		{
			continue_ = 0;
			continue;
		}
		else if (restart == 1)//게임 다시 시작
		{
			restart = 0;
			reset();//게임 초기화
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
	while (1)//게임 다시 시작할 때 반복하기
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