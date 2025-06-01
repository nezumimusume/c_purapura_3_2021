#include <iostream>
#include <Windows.h>

// 悪い例1: 定数をマクロで定義（型安全性がない）
#define WIDTH 1920
#define HEIGHT 1080
#define MAX_PLAYERS 4
#define PLAYER_SPEED 5
#define INITIAL_SCORE 100

// 悪い例2: 列挙値の代わりにマクロを使用
#define GAME_STATE_TITLE 0
#define GAME_STATE_PLAYING 1
#define GAME_STATE_PAUSED 2
#define GAME_STATE_GAMEOVER 3

// 悪い例3: マクロで関数を定義（括弧の問題が発生する）
#define SQUARE(x) x * x
#define MAX(a,b) (a > b ? a : b)
#define MULTIPLY(a,b) a * b

// 悪い例4: 文字列をマクロで定義
#define ERROR_MESSAGE "エラーが発生しました"
#define GAME_TITLE "サンプルゲーム"

int main() {
    SetConsoleOutputCP(CP_UTF8);

    // 悪い例1の問題点：型が不明確な定数の使用
    std::cout << "=== 型が不明確な定数の使用 ===\n";
    int playerPos = PLAYER_SPEED * 10;
    int score = INITIAL_SCORE + playerPos;  // 型が不明確なため、意図しない計算になる可能性
    std::cout << "プレイヤーの位置: " << playerPos << "\n";
    std::cout << "スコア: " << score << "\n\n";

    // 悪い例2の問題点：型安全性のない状態管理
    std::cout << "=== 型安全性のない状態管理 ===\n";
    int gameState = GAME_STATE_PLAYING;
    if (gameState == GAME_STATE_PLAYING) {
        std::cout << GAME_TITLE << "は現在プレイ中です\n";
    }
    gameState = 999; // 誤った値を入れても検出されない
    std::cout << "不正な状態値でも代入可能: " << gameState << "\n\n";

    // 悪い例3の問題点：マクロ関数での予期しない演算順序
    std::cout << "=== マクロ関数の問題 ===\n";
    std::cout << "SQUARE(5) = " << SQUARE(5) << "\n";          // 25になる（正しい）
    std::cout << "SQUARE(2+3) = " << SQUARE(2+3) << "\n";      // 2+3*2+3=11になる（誤り）
    
    int a = 5, b = 3;
    std::cout << "MULTIPLY(a+2, b-1) = " << MULTIPLY(a+2, b-1) << "\n"; // a+2*b-1になる（誤り）
    std::cout << "MAX(++a, b) = " << MAX(++a, b) << "\n";      // aが2回インクリメントされる\n\n";

    // 悪い例4の問題点：文字列リテラルの重複と型の不明確さ
    std::cout << "=== 文字列定数の問題 ===\n";
    const char* msg1 = ERROR_MESSAGE;
    const char* msg2 = ERROR_MESSAGE;
    std::cout << "メモリ上で同じ文字列が複数回現れる可能性: " << (msg1 == msg2 ? "同じ" : "異なる") << "\n";

    return 0;
}
