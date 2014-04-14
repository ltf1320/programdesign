////////////////////////////////////////////
// �������ƣ�����˹����
// ���뻷����Visual C++ 6.0 / 2010��EasyX 2011���ݰ�
// �����д��krissi <zhaoh1987@qq.com>
// ���¼�¼��2010-12-18	zhaoh1987@qq.com ��д
// ����������2011-9-28	yw80@qq.com �޸������䳬ʱ���߼�
//
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include "StdAfx.h"



/////////////////////////////////////////////
// ���峣����ö�������ṹ�塢ȫ�ֱ���
/////////////////////////////////////////////

#define	WIDTH	10		// ��Ϸ�����
#define	HEIGHT	22		// ��Ϸ���߶�
#define	SIZE	20		// ÿ����Ϸ����λ��ʵ������

// �����������
enum CMD
{
	CMD_ROTATE,						// ������ת
	CMD_LEFT, CMD_RIGHT, CMD_DOWN,	// �������ҡ����ƶ�
	CMD_SINK,						// �������
	CMD_QUIT						// �˳���Ϸ
};

// ������Ʒ���ķ���
enum DRAW
{
	SHOW,	// ��ʾ����
	HIDE,	// ���ط���
	FIX		// �̶�����
};

// �������ֶ���˹����
struct BLOCK
{
	WORD dir[4];	// ������ĸ���ת״̬
	COLORREF color;	// �������ɫ
}	g_Blocks[7] = {	{0x0F00, 0x4444, 0x0F00, 0x4444, RED},		// I
					{0x0660, 0x0660, 0x0660, 0x0660, BLUE},		// ��
					{0x4460, 0x02E0, 0x0622, 0x0740, MAGENTA},	// L
					{0x2260, 0x0E20, 0x0644, 0x0470, YELLOW},	// ��L
					{0x0C60, 0x2640, 0x0C60, 0x2640, CYAN},		// Z
					{0x0360, 0x4620, 0x0360, 0x4620, GREEN},	// ��Z
					{0x4E00, 0x4C40, 0x0E40, 0x4640, BROWN}};	// T

// ���嵱ǰ���顢��һ���������Ϣ
struct BLOCKINFO
{
	byte id;	// ���� ID
	char x, y;	// ��������Ϸ���е�����
	byte dir:2;	// ����
}	g_CurBlock, g_NextBlock;

// ������Ϸ��
BYTE g_World[WIDTH][HEIGHT] = {0};



/////////////////////////////////////////////
// ��������
/////////////////////////////////////////////

void Init();											// ��ʼ����Ϸ
void Quit();											// �˳���Ϸ
void NewGame();											// ��ʼ����Ϸ
void GameOver();										// ������Ϸ
CMD  GetCmd();											// ��ȡ��������
void DispatchCmd(CMD _cmd);								// �ַ���������
void NewBlock();										// �����µķ���
bool CheckBlock(BLOCKINFO _block);						// ���ָ�������Ƿ���Է���
void DrawBlock(BLOCKINFO _block, DRAW _draw = SHOW);	// ������
void OnRotate();										// ��ת����
void OnLeft();											// ���Ʒ���
void OnRight();											// ���Ʒ���
void OnDown();											// ���Ʒ���
void OnSink();											// ���׷���



/////////////////////////////////////////////
// ��������
/////////////////////////////////////////////

// ������
void main()
{
	Init();

	CMD c;
	while(true)
	{
		c = GetCmd();
		DispatchCmd(c);

		// ���˳�ʱ����ʾ�Ի�����ѯ�û��Ƿ��˳�
		if (c == CMD_QUIT)
		{
			HWND wnd = GetHWnd();
			if (MessageBox(wnd, _T("��Ҫ�˳���Ϸ��"), _T("����"), MB_OKCANCEL | MB_ICONQUESTION) == IDOK)
				Quit();
		}
	}
}


// ��ʼ����Ϸ
void Init()
{
	initgraph(640, 480);
	srand((unsigned)time(NULL));

	// ��ʾ����˵��
	setfont(14, 0, _T("����"));
	outtextxy(20, 330, _T("����˵��"));
	outtextxy(20, 350, _T("�ϣ���ת"));
	outtextxy(20, 370, _T("������"));
	outtextxy(20, 390, _T("�ң�����"));
	outtextxy(20, 410, _T("�£�����"));
	outtextxy(20, 430, _T("�ո񣺳���"));
	outtextxy(20, 450, _T("ESC���˳�"));

	// ��������ԭ��
	setorigin(220, 20);

	// ������Ϸ���߽�
	rectangle(-1, -1, WIDTH * SIZE, HEIGHT * SIZE);
	rectangle((WIDTH + 1) * SIZE - 1, -1, (WIDTH + 5) * SIZE, 4 * SIZE);

	// ��ʼ����Ϸ
	NewGame();
}


// �˳���Ϸ
void Quit()
{
	closegraph();
	exit(0);
}


// ��ʼ����Ϸ
void NewGame()
{
	// �����Ϸ��
	setfillstyle(BLACK);
	bar(0, 0, WIDTH * SIZE - 1, HEIGHT * SIZE - 1);
	ZeroMemory(g_World, WIDTH * HEIGHT);

	// ������һ������
	g_NextBlock.id = rand() % 7;
	g_NextBlock.dir = rand() % 4;
	g_NextBlock.x = WIDTH + 1;
	g_NextBlock.y = HEIGHT - 1;

	// ��ȡ�·���
	NewBlock();
}


// ������Ϸ
void GameOver()
{
	HWND wnd = GetHWnd();
	if (MessageBox(wnd, _T("��Ϸ������\n����������һ����"), _T("��Ϸ����"), MB_YESNO | MB_ICONQUESTION) == IDYES)
		NewGame();
	else
		Quit();
}


// ��ȡ��������
DWORD m_oldtime;
CMD GetCmd()
{
	// ��ȡ����ֵ
	while(true)
	{
		// �����ʱ���Զ�����һ��
		DWORD newtime = GetTickCount();
		if (newtime - m_oldtime >= 500)
		{
			m_oldtime = newtime;
			return CMD_DOWN;
		}

		// ����а��������ذ�����Ӧ�Ĺ���
		if (kbhit())
		{
			switch(getch())
			{
				case 'w':
				case 'W':	return CMD_ROTATE;
				case 'a':
				case 'A':	return CMD_LEFT;
				case 'd':
				case 'D':	return CMD_RIGHT;
				case 's':
				case 'S':	return CMD_DOWN;
				case 27:	return CMD_QUIT;
				case ' ':	return CMD_SINK;
				case 0:
				case 0xE0:
					switch(getch())
					{
						case 72:	return CMD_ROTATE;
						case 75:	return CMD_LEFT;
						case 77:	return CMD_RIGHT;
						case 80:	return CMD_DOWN;
					}
			}
		}

		// ��ʱ (���� CPU ռ����)
		Sleep(20);
	}
}


// �ַ���������
void DispatchCmd(CMD _cmd)
{
	switch(_cmd)
	{
		case CMD_ROTATE:	OnRotate();		break;
		case CMD_LEFT:		OnLeft();		break;
		case CMD_RIGHT:		OnRight();		break;
		case CMD_DOWN:		OnDown();		break;
		case CMD_SINK:		OnSink();		break;
		case CMD_QUIT:		break;
	}
}


// �����µķ���
void NewBlock()
{
	g_CurBlock.id = g_NextBlock.id,		g_NextBlock.id = rand() % 7;
	g_CurBlock.dir = g_NextBlock.dir,	g_NextBlock.dir = rand() % 4;
	g_CurBlock.x = (WIDTH - 4) / 2;
	g_CurBlock.y = HEIGHT + 2;

	// �����·���ֱ���оֲ���ʾ
	WORD c = g_Blocks[g_CurBlock.id].dir[g_CurBlock.dir];
	while((c & 0xF) == 0)
	{
		g_CurBlock.y--;
		c >>= 4;
	}

	// �����·���
	DrawBlock(g_CurBlock);

	// ������һ������
	setfillstyle(BLACK);
	bar((WIDTH + 1) * SIZE, 0, (WIDTH + 5) * SIZE - 1, 4 * SIZE - 1);
	DrawBlock(g_NextBlock);

	// ���ü�ʱ���������ж��Զ�����
	m_oldtime = GetTickCount();
}


// ������
void DrawBlock(BLOCKINFO _block, DRAW _draw)
{
	WORD b = g_Blocks[_block.id].dir[_block.dir];
	int x, y;

	int color = BLACK;
	switch(_draw)
	{
		case SHOW: color = g_Blocks[_block.id].color; break;
		case HIDE: color = BLACK;	break;
		case FIX: color = g_Blocks[_block.id].color / 3; break;
	}
	setfillstyle(color);

	for(int i=0; i<16; i++)
	{
		if (b & 0x8000)
		{
			x = _block.x + i % 4;
			y = _block.y - i / 4;
			if (y < HEIGHT)
			{
				if (_draw != HIDE)
					bar3d(x * SIZE + 2, (HEIGHT - y - 1) * SIZE + 2, (x + 1) * SIZE - 4, (HEIGHT - y) * SIZE - 4, 3, true);
				else
					bar(x * SIZE, (HEIGHT - y - 1) * SIZE, (x + 1) * SIZE - 1, (HEIGHT - y) * SIZE - 1);
			}
		}
		b <<= 1;
	}
}


// ���ָ�������Ƿ���Է���
bool CheckBlock(BLOCKINFO _block)
{
	WORD b = g_Blocks[_block.id].dir[_block.dir];
	int x, y;

	for(int i=0; i<16; i++)
	{
		if (b & 0x8000)
		{
			x = _block.x + i % 4;
			y = _block.y - i / 4;
			if ((x < 0) || (x >= WIDTH) || (y < 0))
				return false;

			if ((y < HEIGHT) && (g_World[x][y]))
				return false;
		}
		b <<= 1;
	}

	return true;
}


// ��ת����
void OnRotate()
{
	// ��ȡ������ת�� x ƫ����
	int dx;
	BLOCKINFO tmp = g_CurBlock;
	tmp.dir++;					if (CheckBlock(tmp))	{	dx = 0;		goto rotate;	}
	tmp.x = g_CurBlock.x - 1;	if (CheckBlock(tmp))	{	dx = -1;	goto rotate;	}
	tmp.x = g_CurBlock.x + 1;	if (CheckBlock(tmp))	{	dx = 1;		goto rotate;	}
	tmp.x = g_CurBlock.x - 2;	if (CheckBlock(tmp))	{	dx = -2;	goto rotate;	}
	tmp.x = g_CurBlock.x + 2;	if (CheckBlock(tmp))	{	dx = 2;		goto rotate;	}
	return;

rotate:
	// ��ת
	DrawBlock(g_CurBlock, HIDE);
	g_CurBlock.dir++;
	g_CurBlock.x += dx;
	DrawBlock(g_CurBlock);
}


// ���Ʒ���
void OnLeft()
{
	BLOCKINFO tmp = g_CurBlock;
	tmp.x--;
	if (CheckBlock(tmp))
	{
		DrawBlock(g_CurBlock, HIDE);
		g_CurBlock.x--;
		DrawBlock(g_CurBlock);
	}
}


// ���Ʒ���
void OnRight()
{
	BLOCKINFO tmp = g_CurBlock;
	tmp.x++;
	if (CheckBlock(tmp))
	{
		DrawBlock(g_CurBlock, HIDE);
		g_CurBlock.x++;
		DrawBlock(g_CurBlock);
	}
}


// ���Ʒ���
void OnDown()
{
	BLOCKINFO tmp = g_CurBlock;
	tmp.y--;
	if (CheckBlock(tmp))
	{
		DrawBlock(g_CurBlock, HIDE);
		g_CurBlock.y--;
		DrawBlock(g_CurBlock);
	}
	else
		OnSink();	// ��������ʱ��ִ�С����׷��顱����
}


// ���׷���
void OnSink()
{
	int i, x, y;

	// �������Ʒ���
	DrawBlock(g_CurBlock, HIDE);
	BLOCKINFO tmp = g_CurBlock;
	tmp.y--;
	while (CheckBlock(tmp))
	{
		g_CurBlock.y--;
		tmp.y--;
	}
	DrawBlock(g_CurBlock, FIX);

	// �̶���������Ϸ��
	WORD b = g_Blocks[g_CurBlock.id].dir[g_CurBlock.dir];
	for(i = 0; i < 16; i++)
	{
		if (b & 0x8000)
		{
			if (g_CurBlock.y - i / 4 >= HEIGHT)
			{	// �������Ĺ̶�λ�ó����߶ȣ�������Ϸ
				GameOver();
				return;
			}
			else
				g_World[g_CurBlock.x + i % 4][g_CurBlock.y - i / 4] = 1;
		}

		b <<= 1;
	}

	// ����Ƿ���Ҫ�����У������
	int row[4] = {0};
	bool bRow = false;
	for(y = g_CurBlock.y; y >= max(g_CurBlock.y - 3, 0); y--)
	{
		i = 0;
		for(x = 0; x < WIDTH; x++)
			if (g_World[x][y] == 1)
				i++;
		if (i == WIDTH)
		{
			bRow = true;
			row[g_CurBlock.y - y] = 1;
			setfillstyle(WHITE, DIAGCROSS2_FILL);
			bar(0, (HEIGHT - y - 1) * SIZE + SIZE / 2 - 2, WIDTH * SIZE - 1, (HEIGHT - y - 1) * SIZE + SIZE / 2 + 2);
		}
	}

	if (bRow)
	{
		// ��ʱ 200 ����
		Sleep(200);

		// �����ղű�ǵ���
		IMAGE img;
		for(i = 0; i < 4; i++)
		{
			if (row[i])
			{
				for(y = g_CurBlock.y - i + 1; y < HEIGHT; y++)
					for(x = 0; x < WIDTH; x++)
					{
						g_World[x][y - 1] = g_World[x][y];
						g_World[x][y] = 0;
					}

				getimage(&img, 0, 0, WIDTH * SIZE, (HEIGHT - (g_CurBlock.y - i + 1)) * SIZE);
				putimage(0, SIZE, &img);
			}
		}
	}

	// �����·���
	NewBlock();
}
