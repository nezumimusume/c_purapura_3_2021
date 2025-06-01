#include <iostream>
#include <Windows.h>
#include <string>
#include <string_view>

// 良い例：型が明確な定数
const int kWidth = 1920;
const int kHeight = 1080;
const int kMaxPlayers = 4;
const int kPlayerSpeed = 5;
const int kInitialScore = 100;

// 良い例：列挙型による状態管理
enum class GameState {
    Title,
    Playing,
    Paused,
    GameOver
};

// 良い例：文字列定数
const std::string_view kErrorMessage = "エラーが発生しました";
const std::string_view kGameTitle = "サンプルゲーム";

// 良い例：inline関数（型安全で、括弧の問題が起きない）
inline int Square(int x) {
    return x * x;
}

inline int Max(int a, int b) {
    return (a > b) ? a : b;
}

inline int Multiply(int a, int b) {
    return a * b;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    // 定数の使用例
    std::cout << "画面サイズ: " << kWidth << "x" << kHeight << "\n";
    
    // inline関数の使用例（型安全）
    std::cout << "Square(5) = " << Square(5) << "\n";
    std::cout << "Square(2+3) = " << Square(2+3) << "\n";      // 正しく計算される
    
    // inline関数の使用例
    int a = 5, b = 3;
    std::cout << "Multiply(a+2, b-1) = " << Multiply(a+2, b-1) << "\n"; // 正しく計算される

    // 列挙型による型安全な状態管理
    GameState gameState = GameState::Playing;
    if (gameState == GameState::Playing) {
        std::cout << kGameTitle << "は現在プレイ中です\n";
    }

    // 型が明確な計算
    int playerPos = kPlayerSpeed * 10;
    int score = kInitialScore + playerPos;  // 型が明確で安全
    std::cout << "プレイヤーの位置: " << playerPos << "\n";
    std::cout << "スコア: " << score << "\n";

    // 文字列定数の使用
    bool hasError = true;
    if (hasError) {
        std::cout << kErrorMessage << "\n";
    }

    // inline関数の使用例
    std::cout << "Max(3, 7) = " << Max(3, 7) << "\n";
    std::cout << "Max(10, 5) = " << Max(10, 5) << "\n";

    return 0;
} 