#include "Gabang.h"

void Drew_board()
{
	// 绘制棋盘边框
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 3);
	rectangle(LEFT_MARGIN, TOP_MARGIN, RIGHT_MARGIN, BOTTOM_MARGIN);
	// 绘制棋盘格线
	setlinestyle(PS_SOLID, 2);
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		line(LEFT_MARGIN, TOP_MARGIN + i * GRID_SIZE, RIGHT_MARGIN, TOP_MARGIN + i * GRID_SIZE);
		line(LEFT_MARGIN + i * GRID_SIZE, TOP_MARGIN, LEFT_MARGIN + i * GRID_SIZE, BOTTOM_MARGIN);
	}
}
// 获取离鼠标最近的交叉点位置
void getNearestCross(int x, int y, int& i, int& j)
{
    i = (y - TOP_MARGIN + GRID_SIZE / 2) / GRID_SIZE;
    j = (x - LEFT_MARGIN + GRID_SIZE / 2) / GRID_SIZE;
}


void PlayGame()
{
    int x, y, i, j;
    int player = 1;  // 当前玩家，1为黑方，2为白方
    while (true)
    {
        ChearWin(player);
        if (player == 1)
        {
            // 黑方下棋
            while (true)
            {
                // 等待鼠标左键按下
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
                            // 在空位处下黑棋
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
            // 白方下棋
            while (true)
            {
                // 等待鼠标右键按下
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
                            // 在空位处下白棋
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
  
    // 检查行
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE - 4; j++) {
            if (board[i][j] != 0 && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3] && board[i][j] == board[i][j + 4]) {
                // 某一方获胜
                settextcolor(YELLOW);
                settextstyle(30, 0, _T("微软雅黑"));
                outtextxy(LEFT_MARGIN, TOP_MARGIN + GRID_SIZE * BOARD_SIZE + 20, player == 1 ? _T("白方获胜") : _T("黑方获胜"));
                getchar();
                closegraph();
                return 0;
            }
        }
    }

    // 检查列
    for (int i = 0; i < BOARD_SIZE - 4; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != 0 && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j] && board[i][j] == board[i + 4][j]) {
                // 某一方获胜
                settextcolor(YELLOW);
                settextstyle(30, 0, _T("微软雅黑"));
                outtextxy(LEFT_MARGIN, TOP_MARGIN + GRID_SIZE * BOARD_SIZE + 20, player == 1 ? _T("白方获胜") : _T("黑方获胜"));
                getchar();
                closegraph();
                return 0;
            }
        }
    }

    // 检查主对角线
    for (int i = 0; i < BOARD_SIZE - 4; i++) {
        for (int j = 0; j < BOARD_SIZE - 4; j++) {
            if (board[i][j] != 0 && board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3] && board[i][j] == board[i + 4][j + 4]) {
                // 某一方获胜
                settextcolor(YELLOW);
                settextstyle(30, 0, _T("微软雅黑"));
                outtextxy(LEFT_MARGIN, TOP_MARGIN + GRID_SIZE * BOARD_SIZE + 20, player == 1 ? _T("白方获胜") : _T("黑方获胜"));
                getchar();
                closegraph();
                return 0;
            }
        }
    }

    // 检查副对角线
    for (int i = 0; i < BOARD_SIZE - 4; i++) {
        for (int j = 4; j < BOARD_SIZE; j++) {
            if (board[i][j] != 0 && board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2] && board[i][j] == board[i + 3][j - 3] && board[i][j] == board[i + 4][j - 4]) {
                // 某一方获胜
                settextcolor(YELLOW);
                settextstyle(30, 0, _T("微软雅黑"));
                outtextxy(LEFT_MARGIN, TOP_MARGIN + GRID_SIZE * BOARD_SIZE + 20, player == 1 ? _T("白方获胜") : _T("黑方获胜"));
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
    //绘制棋盘
    Drew_board();
    // 下棋
    PlayGame();
    getchar();
    closegraph();
    return 0;
}

