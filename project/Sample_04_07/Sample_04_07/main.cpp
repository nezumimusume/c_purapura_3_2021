// Sample_04_04.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>


template<class TKey, class TValue>
struct Node {
    TKey key;
    TValue value;
    Node* left = nullptr; //左のノード。
    Node* right = nullptr; //右のノード。
};

template<class TKey, class TValue>
class MyMap {
private:
    Node<TKey, TValue>* m_top = nullptr;    //ツリーのトップ。
private:
    void InsertCore(Node<TKey, TValue>* parentNode, Node<TKey, TValue>* newNode)
    {
        if (newNode->key < parentNode->key) {
            //newNodeのキーの値が親のノードのキーの値よりも小さい。
            //左側に接続する。
            if (parentNode->left == nullptr) {
                //左の木がnullなのでここに挿入する。
                parentNode->left = newNode;
            }
            else {
                //更に潜る。
                InsertCore(parentNode->left, newNode);
            }
        }
        else {
            //newNodeのキーの値が親のノードのキーの値と同じか大きい。
            //右側に挿入する。
            if (parentNode->right == nullptr) {
                //右の木がnullなのでここに挿入する。
                parentNode->right = newNode;
            }
            else {
                //更に潜る
                InsertCore(parentNode->right, newNode);
            }
        }
    }
public:
    
    void Insert(TKey key, TValue value)
    {
        //新しいノードを作成する。
        Node<TKey, TValue>* newNode = new Node <TKey, TValue>;
        newNode->key = key;
        newNode->value = value;
        if (m_top == nullptr) {
            m_top = newNode;
        }
        else {
            InsertCore(m_top, newNode);
        }

    }
    TValue& operator[](const TKey& key)
    {
        Node<TKey, TValue>* node = m_top;

        while (node->key != key && node != nullptr) {
            //見つかるまでの間木を潜り続ける。
            if (key < node->key) {
                //検索しているキーが現在のノードのキーより小さいので左側を潜る。
                node = node->left;
            }
            else {
                //検索しているキーが現在のノードのキーより大きいので左側を潜る。
                node = node->right;
            }
        }
        if (node == nullptr) {
            //末端まで行ったので見つからなかった。
            std::abort();
        }
        return node->value;
    }
};
int main()
{
    MyMap<std::string, int> myMap;
    myMap.Insert("清原", 40);
    myMap.Insert("清水", 30);
    myMap.Insert("後藤", 25);
    myMap.Insert("大西", 22);
    myMap.Insert("原", 21);
    myMap.Insert("ダルビッシュ", 34);

    std::cout << myMap["原"];
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
