// Sample_04_04.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

template<class T>
struct Node {
    T value;
    Node* next = nullptr; //次のノード。
    Node* prev = nullptr; //前のノード。
};
template<class T>
class MyList{
private:
    Node<T>* m_begin = nullptr;     //先頭ノード。
    Node<T>* m_end = nullptr;       //終端ノード。
public:
    T& operator[](int i)
    {
        
        int count = 0;
        
        Node<T>* node = m_begin;
        Node<T>* targetNode = nullptr;
        while (node != nullptr) {
            if (count == i) {
                //目的に要素に到達した。
                targetNode = node;
                break;
            }
            count++;
        }
        targetNode->value;
    }
    /// <summary>
    /// リストに新しい要素を追加。
    /// </summary>
    /// <param name="value"></param>
    void PushBack(T value)
    {
        //新しいノードを確保。
        Node<T>* newNode = new Node<T>;
        newNode->value = value;
        if (m_begin == nullptr) {
            //先頭ノードが空
            m_begin = newNode;
            m_end = m_begin;
        }
        else {
            //終端ノードの末尾に新しいノードを接続する。
            //まず新しいノードの前のノードを、古い終端ノードにする。
            newNode->prev = m_end;
            //古い終端ノードの次のノードを新しいノードにする。
            m_end->next = newNode;
            //終端ノードを更新。
            m_end = newNode;
        }
    }
    /// <summary>
    /// 先頭ノードを取得。
    /// </summary>
    /// <returns></returns>
    Node<T>* Begin()
    {
        return m_begin;
    }
    /// <summary>
    /// 終端ノードを取得。
    /// </summary>
    /// <returns></returns>
    Node<T>* End()
    {
        return m_end;
    }
    /// <summary>
    /// ノードを検索。
    /// </summary>
    /// <param name="value"></param>
    /// <returns></returns>
    Node<T>* Find(T value)
    {
        for (
            Node<T>* node = m_begin;
            node != nullptr;
            node = node->next
            ) 
        {
            if (node->value == value) {
                //発見。
                return node;
            }
        }
        return nullptr;
    }
    /// <summary>
    /// 削除。
    /// </summary>
    /// <param name="node"></param>
    void Erase(Node<T>* node)
    {
        //ノードを削除する。
        if (node == m_end) {
            //削除しようとしているノードが終端ノード、
            //削除するノードの前のノードが終端ノードになる。
            m_end = node->prev;
            if (m_end) {
                //終端ノードの次のノードにnullを代入。
                m_end->next = nullptr;
            }
            if (m_end == nullptr) {
                //リストが空になっている。
                m_begin = nullptr;
            }
        }
        else if (node == m_begin) {
            //削除しようとしているノードが先頭ノード。
            //先頭ノードを次のノードにする。
            m_begin = node->next;
            if (m_begin != nullptr) {
                //次のノードがnull出なければ。
                //先頭ノードの手前のノードは存在しないのでnullptrを代入
                m_begin->prev = nullptr;
            }
            if (m_begin == nullptr) {
                //リストが空になっている。
                m_end = nullptr;
            }
        }
        else {
            //削除しようとしているノードが中間ノード。
            node->prev->next = node->next;
        }
        //ノードを削除
        delete node;
    }
    /// <summary>
    /// prevNodeの後ろに新しい要素を挿入する。
    /// </summary>
    /// <param name="prevNode"></param>
    /// <param name="newValue"></param>
    void Insert(Node<T>* prevNode, T newValue)
    {
    }

};
int main()
{
    MyList<int> myList;
    myList.PushBack(10);
    myList.PushBack(20);
    myList.PushBack(30);

    Node<int>* node = myList.Begin();
    while (node != nullptr) {
        std::cout << node->value << "\n";
        //次のノード
        node = node->next;
    }

    //30という値をして削除する。
    node = myList.Find(30);
    if (node != nullptr) {
        myList.Erase(node);
    }

    // 実習課題
    // 先頭ノードの後ろに25という数値を挿入する
    myList.Insert(myList.Begin(), 25 );
    // 終端ノードの後ろに35という数値を挿入する。
    myList.Insert(myList.End(), 35);

    // 正しくInsert関数が実装できていたら、次のように表示されるはず。
    // 10
    // 25
    // 20
    // 35
    node = myList.Begin();
    while (node != nullptr) {
        std::cout << node->value << "\n";
        //次のノード
        node = node->next;
    }

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
