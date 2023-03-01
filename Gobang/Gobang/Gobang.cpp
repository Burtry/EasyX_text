#include "Gabang.h"

void Drew_board()
{
	// �������̱߿�
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 3);
	rectangle(LEFT_MARGIN, TOP_MARGIN, RIGHT_MARGIN, BOTTOM_MARGIN);
	// �������̸���
	setlinestyle(PS_SOLID, 2);
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		line(LEFT_MARGIN, TOP_MARGIN + i * GRID_SIZE, RIGHT_MARGIN, TOP_MARGIN + i * GRID_SIZE);
		line(LEFT_MARGIN + i * GRID_SIZE, TOP_MARGIN, LEFT_MARGIN + i * GRID_SIZE, BOTTOM_MARGIN);
	}
}
// ��ȡ���������Ľ����λ��
void getNearestCross(int x, int y, int& i, int& j)
{
    i = (y - TOP_MARGIN + GRID_SIZE / 2) / GRID_SIZE;
    j = (x - LEFT_MARGIN + GRID_SIZE / 2) / GRID_SIZE;
}


void PlayGame()
{
    int x, y, i, j;
    int player = 1;  // ��ǰ��ң�1Ϊ�ڷ���2Ϊ�׷�
    while (true)
    {
        ChearWin(player);
        if (player == 1)
        {
            // �ڷ�����
            while (true)
            {
                // �ȴ�����������
                if (MouseHit())
                {
                    MOUSEMSG msg = GetMouseMsg();
                    if (msg.uMsg == WM_LBUTTONDOWN)
                    {
                        x = msg.x;
                        y = msg.y;
                        getNearestCross(x, y, i, j);
                        if (board[i][j] == 0)
                        {
                            // �ڿ�λ���º���
                            setfillcolor(BLACK);
                            solidcircle(LEFT_MARGIN + j * GRID_SIZE, TOP_MARGIN + i * GRID_SIZE, GRID_SIZE / 2 - 2);
                            board[i][j] = 1;
                            player = 2;
                     
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            // �׷�����
            while (true)
            {
                // �ȴ�����Ҽ�����
                if (MouseHit())
                {
                    MOUSEMSG msg = GetMouseMsg();
                    if (msg.uMsg == WM_RBUTTONDOWN)
                    {
                        x = msg.x;
                        y = msg.y;
                        getNearestCross(x, y, i, j);
                        if (board[i][j] == 0)
                        {
                            // �ڿ�λ���°���
                            setfillcolor(WHITE);
                            solidcircle(LEFT_MARGIN + j * GRID_SIZE, TOP_MARGIN + i * GRID_SIZE, GRID_SIZE / 2 - 2);
                            board[i][j] = 1;
                            player = 1;
                            break;

                        }
                    }
                }
            }
        }
    }
}
int ChearWin(int player)
{
  
    // �����
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE - 4; j++) {
            if (board[i][j] != 0 && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3] && board[i][j] == board[i][j + 4]) {
                // ĳһ����ʤ
                settextcolor(YELLOW);
                settextstyle(30, 0, _T("΢���ź�"));
                outtextxy(LEFT_MARGIN, TOP_MARGIN + GRID_SIZE * BOARD_SIZE + 20, player == 1 ? _T("�׷���ʤ") : _T("�ڷ���ʤ"));
                getchar();
                closegraph();
                return 0;
            }
        }
    }

    // �����
    for (int i = 0; i < BOARD_SIZE - 4; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != 0 && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j] && board[i][j] == board[i + 4][j]) {
                // ĳһ����ʤ
                settextcolor(YELLOW);
                settextstyle(30, 0, _T("΢���ź�"));
                outtextxy(LEFT_MARGIN, TOP_MARGIN + GRID_SIZE * BOARD_SIZE + 20, player == 1 ? _T("�׷���ʤ") : _T("�ڷ���ʤ"));
                getchar();
                closegraph();
                return 0;
            }
        }
    }

    // ������Խ���
    for (int i = 0; i < BOARD_SIZE - 4; i++) {
        for (int j = 0; j < BOARD_SIZE - 4; j++) {
            if (board[i][j] != 0 && board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3] && board[i][j] == board[i + 4][j + 4]) {
                // ĳһ����ʤ
                settextcolor(YELLOW);
                settextstyle(30, 0, _T("΢���ź�"));
                outtextxy(LEFT_MARGIN, TOP_MARGIN + GRID_SIZE * BOARD_SIZE + 20, player == 1 ? _T("�׷���ʤ") : _T("�ڷ���ʤ"));
                getchar();
                closegraph();
                return 0;
            }
        }
    }

    // ��鸱�Խ���
    for (int i = 0; i < BOARD_SIZE - 4; i++) {
        for (int j = 4; j < BOARD_SIZE; j++) {
            if (board[i][j] != 0 && board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2] && board[i][j] == board[i + 3][j - 3] && board[i][j] == board[i + 4][j - 4]) {
                // ĳһ����ʤ
                settextcolor(YELLOW);
                settextstyle(30, 0, _T("΢���ź�"));
                outtextxy(LEFT_MARGIN, TOP_MARGIN + GRID_SIZE * BOARD_SIZE + 20, player == 1 ? _T("�׷���ʤ") : _T("�ڷ���ʤ"));
                getchar();
                closegraph();
                return 0;
            }
        }
    }

}

int main()
{
    initgraph(LEFT_MARGIN * 2 + GRID_SIZE * BOARD_SIZE, TOP_MARGIN * 2 + GRID_SIZE * BOARD_SIZE, EX_NOMINIMIZE);
    cleardevice();
    static IMAGE background;
    loadimage(&background, _T("jpg/c1.png", 800, 800));
    putimage(0, 0, &background);
    setbkcolor(TRANSPARENT);
    //��������
    Drew_board();
    // ����
    PlayGame();
    getchar();
    closegraph();
    return 0;
}

