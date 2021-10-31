// Maze.cpp: implementation of the CMaze class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Robot.h"
#include "Maze.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMaze::CMaze()
{
	// ����������� �ʱ�ȭ 
	m_pwndDraw = 0;
	memset(m_arrayMaze, 0, sizeof(m_arrayMaze));
	InitRecord();
}

CMaze::~CMaze()
{
}

void CMaze::SetMaze(int maze[][MAZE_SIZE])
{
	memcpy(m_arrayMaze, maze, sizeof(m_arrayMaze));
}

int CMaze::GetShape(int x, int y)
{
	int shape = 0;
	
	if (m_arrayMaze[y][x] != 0) 	// ���� �ִ� ��쿡�� ����� ���� ������. 
	{			
		if (y > 0 && m_arrayMaze[y-1][x])		// ���ʿ� ���� �ֳ�?
			shape |= UP;
		if (y < MAZE_SIZE - 1 && m_arrayMaze[y+1][x])	// �Ʒ��ʿ� ���� �ֳ�?
			shape |= DOWN;
		if (x > 0 && m_arrayMaze[y][x-1])		// ���ʿ� ���� �ֳ�?
			shape |= LEFT;
		if (x < MAZE_SIZE - 1 && m_arrayMaze[y][x+1])	// �����ʿ� ���� �ֳ�?
			shape |= RIGHT;
	}

	return shape;
}

bool CMaze::DrawMaze()
{
	// assertion
	if (!m_pwndDraw) 
		return false;

	// DC�� ��´�. 
	CDC *pdc = m_pwndDraw->GetDC();
	if (!pdc) 
		return false;

	// �� �̹����� �ε��Ͽ� �޸�DC�� �ִ´�. 
	CDC dcMem;
	dcMem.CreateCompatibleDC(pdc);
	CBitmap bmpWall;
	CBitmap *pbmpOld;
	bmpWall.LoadBitmap(IDB_WALL);
	pbmpOld = dcMem.SelectObject(&bmpWall);

	// �̷θ� �׸���. 
	int i, j;
	for (j = 0; j < MAZE_SIZE; j++) {
		for (i = 0; i < MAZE_SIZE; i++) {
			int shape = GetShape(i, j);
			pdc->BitBlt(i * 16, j * 16, 16, 16, &dcMem, shape*16, 0, SRCCOPY);		
		}
	}

	// ����� ���ҽ����� �����Ѵ�. 
	dcMem.SelectObject(pbmpOld);
	bmpWall.DeleteObject();
	m_pwndDraw->ReleaseDC(pdc);
	m_pwndDraw->ReleaseDC(&dcMem);
	return false;
}


void CMaze::SetDrawWnd(CWnd *pwnd)
{
	m_pwndDraw = pwnd;
}

void CMaze::GoForward(int &x, int &y, int dir)
{
	// ��ǥ �̵� 
	x = (dir == LEFT ? --x : dir == RIGHT ? ++x : x);
	y = (dir == UP ? --y : dir == DOWN ? ++y : y);
}

void CMaze::DrawMouse(int x, int y, int dir)
{
	// dir�� 0�̸� �����, 1,2,4,8 �̸� �ش� ������� �׸���. 
	if (!m_pwndDraw)
		return;

	CDC *pdc = m_pwndDraw->GetDC();
	if (!pdc) 
		return;

	// ����� ��� (dir == 0)�̸� �׳� ����� ���� 
	if (dir == 0) {
		pdc->FillSolidRect(x*16, y*16, 16, 16, RGB(255, 255, 255));
		return;
	}

	// ��� ���� 
	int shape = (dir == UP ? 0 : dir == RIGHT ? 1 : dir == DOWN ? 2 : dir == LEFT ? 3 : dir == NODIR ? 4 : -1);
	if (shape < 0) 
		return;

	// ���콺 �̹����� �ε��Ͽ� �޸�DC�� �ִ´�. 
	CDC dcMem;
	dcMem.CreateCompatibleDC(pdc);
	CBitmap bmpMouse;
	CBitmap *pbmpOld;
	bmpMouse.LoadBitmap(IDB_MOUSE);
	pbmpOld = dcMem.SelectObject(&bmpMouse);
	
	// ���콺�� �׸���. 
	pdc->BitBlt(x * 16, y * 16, 16, 16, &dcMem, shape*16, 0, SRCCOPY);		

	// ����� ���ҽ����� �����Ѵ�. 
	dcMem.SelectObject(pbmpOld);
	bmpMouse.DeleteObject();
	m_pwndDraw->ReleaseDC(pdc);
	m_pwndDraw->ReleaseDC(&dcMem);
}

bool CMaze::StillInMaze(int x, int y)
{
	if (x > 0 && x < MAZE_SIZE - 1 && y > 0 && y < MAZE_SIZE - 1)
		return true;
	else
		return false;
}

bool CMaze::WallAhead(int x, int y, int dir)
{
	// ��ǥ�� ��ĭ �̵��Ͽ� ������ �ƴ����� üũ�Ѵ�. 
	x = (dir == LEFT ? --x : dir == RIGHT ? ++x : x);
	y = (dir == UP ? --y : dir == DOWN ? ++y : y);

	return m_arrayMaze[y][x] != 0;
}


void CMaze::TurnRight(int &dir)
{
	dir <<= 1;
	dir = (dir > LEFT ? UP : dir);
}

void CMaze::TurnLeft(int &dir)
{
	dir >>= 1;
	dir = (dir == 0 ? LEFT : dir);
}

#define DELAY	100		// 100 msec
void CMaze::RightHandOnWall(int x, int y, int dir)
{
	InitRecord();

	// ���� �׸��� 
	DrawMouse(x, y, dir);
	Sleep(DELAY);		// �ð� ���� 
	Record(x, y);

//	GoForward(x, y, dir);		// ������ ����.
	while (StillInMaze(x, y)) {		// ������ �̷� ���̸�. 
		TurnRight(dir);		// ���������� Ʋ�� 
		DrawMouse(x, y, dir);
		Sleep(DELAY);
		while (WallAhead(x, y, dir)) {		// �տ� ���� ������ ��� 
			TurnLeft(dir);			// �������� ư��. 
			DrawMouse(x, y, dir);
			Sleep(DELAY);
		}
		// ������ �����. 
		DrawMouse(x, y, 0);

		// �̵� 
		GoForward(x, y, dir);
		Record(x, y);		// ���ο� ��ǥ ��� 
		DrawMouse(x, y, dir);
		Sleep(DELAY);
	}

	// Ž�� ��. 
	Record(-1, -1);
}

bool CMaze::Record(int x, int y)
{
	if (m_indexRecord > MAZE_SIZE*MAZE_SIZE*2 - 3)	// �����÷ο� ����. 
		return false;

	m_arrayRecord[m_indexRecord++] = x;
	m_arrayRecord[m_indexRecord++] = y;
	return true;
}

void CMaze::InitRecord()
{
	// �ʱ�ȭ 
	memset(m_arrayRecord, -1, sizeof(m_arrayRecord));
	m_indexRecord = 0;
}

int CMaze::DeletePath(int i, int j)
{
	int k = i;
	while (m_arrayRecord[j] >= 0)
		m_arrayRecord[i++] = m_arrayRecord[j++];
	m_arrayRecord[i] = -1;
	m_arrayRecord[i+1] = -1;
	return k;		// k�� �����ǰ� �� ��, j�� ������ �� ��. 
}

void CMaze::ShortestPath()
{
	int i = 0;
	int x, y;
	int j;
	int x1, y1;

	while (m_arrayRecord[i] >= 0) {
		x = m_arrayRecord[i];
		y = m_arrayRecord[i+1];
		j = i + 2;		// �� ��ǥ�� �ΰ��� �����̹Ƿ� ���� ��ǥ�� +2�̴�. 

		while (m_arrayRecord[j] >= 0) {
			x1 = m_arrayRecord[j];
			y1 = m_arrayRecord[j+1];
			if (x == x1 && y == y1)		// ���� ��ǥ �߰ߵǸ� 
				j = DeletePath(i, j);		// �ߺ� ��� ���� 
			j += 2;
		}
		i += 2;
	}
}

void CMaze::DrawShortedPath()
{
	int i = 0;
	int x, y;
	while (m_arrayRecord[i] >= 0) {
		x = m_arrayRecord[i++];
		y = m_arrayRecord[i++];

		DrawMouse(x, y, NODIR);
		Sleep(DELAY);
		DrawMouse(x, y, 0);
	}
}
