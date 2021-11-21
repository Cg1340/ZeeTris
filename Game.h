#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>            /* ����ͼ�� */
#include <string>
#include "Display.h"
#include "SteadyClock.h"
#include "Button.h"
#include "GameSetting.h"
using namespace sf;
using namespace std;

class Game {
public:
	RenderWindow* window;
	bool startGame(Font font, GameSetting gameSetting);

private:
	/*
	 * TODO:
	 * 1,��Ϊ���������Ͻ�0,0���½�10,20����ƫ�Ʊ��y���Ƿ�������
	 */

	int hold = 0;
	bool isHold = false;
	int blockIndex = 0;            /* ��ʾ��ǰ��������� */
	int rotate = 0;            /* ��ת��0 - 0, 1 - R, 2 - 2, 3 - L */
	int next[14] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	bool nextUsed[7] = { true, true, true, true, true, true, true };
	float downDelay = 500;          /*�½���ʱ */
	float downDelayFast = 50;           /* ��ʱ�½���ʱ */
	float delay = downDelay;
	float dropLockTime = 1000;

	static const int ROW_COUNT = 20;   /* ���� */
	static const int COL_COUNT = 10;   /* ���� */

	int table[ROW_COUNT][COL_COUNT] = { 0
	};

	int blocks[7] /*28�ַ���IJLOSTZ��4����̬*/[4][2] /*4��x,y����*/ = {
		{                                                                       /* I */
			{ 0, 1 }, { 1, 1 }, { 2, 1 }, { 3, 1 }
		},

		{                                                                       /* J */
			{ 0, 0 }, { 0, 1 }, { 1, 1 }, { 2, 1 }
		},

		{                                                                       /* L */
			{ 2, 0 }, { 2, 1 }, { 1, 1 }, { 0, 1 }
		},

		{                                                                       /* O */
			{ 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 }
		},

		{                                                                       /* S */
			{ 2, 0 }, { 1, 0 }, { 1, 1 }, { 0, 1 }
		},

		{                                                                       /* T */
			{ 0, 1 }, { 1, 1 }, { 1, 0 }, { 2, 1 }
		},

		{                                                                       /* Z */
			{ 0, 0 }, { 1, 0 }, { 1, 1 }, { 2, 1 }
		}
	};

	struct {
		int ZSJLT[8][5][2] = {
			{ { +0, +0 }, { -1, +0 }, { -1, -1 }, { +0, +2 }, { -1, +2 } }, /* 01 */
			{ { +0, +0 }, { +1, +0 }, { +1, +1 }, { +0, -2 }, { +1, -2 } }, /* 12 */
			{ { +0, +0 }, { +1, +0 }, { +1, -1 }, { +0, +2 }, { +1, +2 } }, /* 23 */
			{ { +0, +0 }, { -1, +0 }, { -1, +1 }, { +0, -2 }, { -1, -2 } }, /* 30 */

			{ { +0, +0 }, { +1, +0 }, { +1, -1 }, { +0, +2 }, { +1, +2 } }, /* 03 */
			{ { +0, +0 }, { +1, +0 }, { +1, +1 }, { +0, -2 }, { +1, -2 } }, /* 10 */
			{ { +0, +0 }, { -1, +0 }, { -1, -1 }, { +0, +2 }, { -1, +2 } }, /* 21 */
			{ { +0, +0 }, { -1, +0 }, { -1, +1 }, { +0, -2 }, { -1, -2 } }, /* 32 */
		};                                                                      /* ZSJLT */

		int I[8][5][2] = {
			{ { +0, +0 }, { -2, +0 }, { +1, +0 }, { -2, +1 }, { +1, -2 } }, /* 01 */
			{ { +0, +0 }, { -1, +0 }, { +2, +0 }, { -1, -2 }, { +2, +1 } }, /* 12 */
			{ { +0, +0 }, { +2, +0 }, { -1, +0 }, { +2, -1 }, { -1, +2 } }, /* 23 */
			{ { +0, +0 }, { +1, +0 }, { -2, +0 }, { +1, +2 }, { -2, -1 } }, /* 30 */

			{ { +0, +0 }, { -1, +0 }, { +2, +0 }, { -1, -2 }, { +2, +1 } }, /* 03 */
			{ { +0, +0 }, { +2, +0 }, { -1, +0 }, { +2, -1 }, { -1, +2 } }, /* 10 */
			{ { +0, +0 }, { +1, +0 }, { -2, +0 }, { +1, +2 }, { -2, -1 } }, /* 21 */
			{ { +0, +0 }, { -2, +0 }, { +1, +0 }, { -2, +1 }, { +1, -2 } }, /* 32 */
		};                                                                      /* I */
	} kickTable;

	/* �������� */
	struct Point {
		float	x;
		float	y;
	} curBlock[4], bakBlock[4], shadow[4];

	bool move(int move);

	/* ----- ��ת��rota == 0����ת��-1��ʱ�룬1˳ʱ�룩 ----- */
	bool rotateBlock(int rota);

	/* ----- ����Ƿ�Ϸ� ----- */
	bool check();

	void newbag(int count);

	/* ----- �����·��� ----- */
	void newBlock();

	void swapHold();

	/* ----- Ӱ��ϵͳ -----// */
	void refShadow();
};