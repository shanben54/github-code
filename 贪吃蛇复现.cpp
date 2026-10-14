// ============================================================
//  贪吃蛇（跨平台版：Windows + Linux）
//
//  Windows 编译： g++ 贪吃蛇复现.cpp -o snake.exe -std=c++17
//  Linux   编译： g++ 贪吃蛇复现.cpp -o snake -std=c++17
//
//  结构分成两层：
//    平台层 —— 跟操作系统打交道的，用 #ifdef _WIN32 分两份
//    通用层 —— 纯 C++ 逻辑，两边完全一样
// ============================================================

#include <iostream>
#include <cstdlib>
#include <deque>
#include <time.h>

#ifdef _WIN32
    #include <conio.h>          // _kbhit / _getch
    #include <windows.h>        // SetConsoleMode / Sleep
    #ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
    #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
    #endif
#else
    #include <termios.h>        // 关闭行缓冲 + 回显
    #include <unistd.h>         // read / usleep
    #include <sys/select.h>     // select：检查有没有按键
    #include <sys/time.h>
#endif

const int W = 30;
const int H = 20;

// ============================================================
//  平台层：下面这几个函数，Windows 和 Linux 各一套实现
// ============================================================

#ifndef _WIN32
static termios g_oldTermios;    // 存 Linux 终端原设置，退出时还原
#endif

// 进入程序时调一次：Linux 要把终端切成"原始模式"（关行缓冲 + 回显），
// 否则按键要等回车才到、还会回显到屏幕上
void setupTerminal() {
#ifndef _WIN32
    tcgetattr(STDIN_FILENO, &g_oldTermios);
    termios t = g_oldTermios;
    t.c_lflag &= ~(ICANON | ECHO);
    t.c_cc[VMIN] = 0;
    t.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
#endif
}

// 退出前调一次：还原终端设置，不然 Linux 终端会卡在原始模式
void restoreTerminal() {
#ifndef _WIN32
    tcsetattr(STDIN_FILENO, TCSANOW, &g_oldTermios);
#endif
}

// 打开 ANSI 支持：Windows 要手动开，Linux 终端原生支持（什么都不做）
void enableANSI() {
#ifdef _WIN32
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(h, &mode);
    SetConsoleMode(h, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif
}

// 有没有按键（不阻塞）—— 相当于 Windows 的 _kbhit
bool keyPressed() {
#ifdef _WIN32
    return _kbhit();
#else
    timeval tv{0, 0};               // 超时 0 秒 = 立即返回
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    return select(STDIN_FILENO + 1, &fds, nullptr, nullptr, &tv) > 0;
#endif
}

// 读一个按键 —— 相当于 Windows 的 _getch
int getKey() {
#ifdef _WIN32
    return _getch();
#else
    unsigned char c = 0;
    read(STDIN_FILENO, &c, 1);
    return c;
#endif
}

// 睡眠 ms 毫秒
void sleepMs(int ms) {
#ifdef _WIN32
    Sleep(ms);
#else
    usleep(ms * 1000);              // usleep 收的是微秒
#endif
}

// 结束前暂停（Windows 双击运行时用；Linux 上等个回车）
void pauseScreen() {
#ifdef _WIN32
    system("pause");
#else
    std::cout << "按回车键退出...";
    std::cin.get();
#endif
}

// ============================================================
//  通用层：纯 C++ 逻辑，两边一样
// ============================================================

// 移动光标（ANSI 转义，两边通用）
void gotoxy(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H";
}

// 游戏状态
struct Game {
    std::deque<std::pair<int,int>> snake = {{W/2+1, H/2}, {W/2, H/2}, {W/2-1, H/2}};
    std::pair<int,int> food = {0, 0};
    std::pair<int,int> next = {0, 0};
};

// 生成一个不在蛇身上的食物
void Food(Game &g) {
    bool onsnake;
    do {
        g.food.first  = 2 + rand() % (W - 2);
        g.food.second = 2 + rand() % (H - 2);
        onsnake = false;
        for (auto &c : g.snake) {
            if (g.food == c) { onsnake = true; break; }
        }
    } while (onsnake);
}

int main() {
#ifdef _WIN32
    system("chcp 65001>nul");       // Windows 控制台切 UTF-8；Linux 默认就是
#endif
    setupTerminal();                // Linux：进原始模式
    enableANSI();                   // Windows：开 ANSI；Linux：什么都不做
    srand(time(0));
    std::cout << "\033[?25l";       // 隐藏光标
    std::cout << "\033[2J";         // 启动前先清屏

    int dx = 1, dy = 0;             // 方向变量
    Game game;
    Food(game);

    bool running = true;
    while (running) {
        while (keyPressed()) {
            int key = getKey();
            if      ((key=='w'||key=='W') && dy!=1)  dx=0, dy=-1;
            else if ((key=='s'||key=='S') && dy!=-1) dx=0, dy=1;
            else if ((key=='a'||key=='A') && dx!=1)  dx=-1, dy=0;
            else if ((key=='d'||key=='D') && dx!=-1) dx=1, dy=0;
            else if (key=='q'||key=='Q') running = false;
        }

        // 每帧打印，先把地图打印出来
        gotoxy(1, 1);
        for (int i = 1; i <= H; i++) {          // 外层：行
            for (int j = 1; j <= W; j++) {      // 内层：列
                if (i==1 || i==H || j==1 || j==W)
                    std::cout << '#';
                else
                    std::cout << ' ';
            }
            std::cout << "\033[K\n";
        }

        // 打印食物
        gotoxy(game.food.first, game.food.second);
        std::cout << "*";

        game.next = game.snake.front();
        game.next.first  += dx;
        game.next.second += dy;

        // 撞墙判断
        if (game.next.first<2 || game.next.first>W-1 ||
            game.next.second<2 || game.next.second>H-1) {
            gotoxy(1, H+6);
            std::cout << "\033[?25h";
            std::cout << "GAMEOVER~\n";
            restoreTerminal();
            pauseScreen();
            return 0;
        }

        // 吃到自己判断
        for (auto c : game.snake) {
            if (game.next == c) {
                gotoxy(1, H+6);
                std::cout << "\033[?25h";
                std::cout << "GAMEOVER~\n";
                restoreTerminal();
                pauseScreen();
                return 0;
            }
        }

        if (game.next == game.food) {
            game.snake.push_front(game.next);   // 吃到：只加头，不变长尾巴
            Food(game);
        } else {
            game.snake.push_front(game.next);
            game.snake.pop_back();
        }

        for (size_t i = 0; i < game.snake.size(); i++) {
            gotoxy(game.snake[i].first, game.snake[i].second);
            if (i == 0)
                std::cout << 'O';
            else
                std::cout << 'o';
        }

        gotoxy(1, H+2);
        std::cout << "WASD 移动     Q 退出\033[K\n";
        std::cout << std::flush;

        sleepMs(80);
    }

    gotoxy(1, H+6);
    std::cout << "\033[?25h";       // 显示光标
    std::cout << "Bye~\n";
    restoreTerminal();
    pauseScreen();
    return 0;
}
