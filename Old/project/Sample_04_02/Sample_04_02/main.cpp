// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

// MyVectorクラス。
template<class T>
class MyVector {
private:
    T* m_ptr = nullptr; //配列の先頭アドレス。
    int m_size = 0;     //配列の要素数。
    int m_capacity = 0; //配列が記憶できる要素の限界値。
public:
    /// <summary>
    /// 要素を末尾に追加する。
    /// </summary>
    /// <param name="value">追加する要素</param>
    void PushBack(T value)
    {
        // まず配列のサイズチェック。
        if (m_size == m_capacity) {
            // 配列の要素数が限界値に達しているので、配列を拡張する。
            if (m_capacity == 0) {
                // 一番最初の拡張なので、限界値を1にする。
                m_capacity = 1;
            }
            else {
                // 以降は限界に達したら２倍する。
                m_capacity *= 2;
            }
            // 新しい配列をメモリ上に動的確保。
            T* newArray = new T[m_capacity];
            // 古い配列の内容を新しいメモリにコピーする。
            memcpy(newArray, m_ptr, sizeof(T) * m_size);
            // 古い配列を削除する。
            delete[] m_ptr;
            // m_ptrが新しい配列を指すように変更する。
            m_ptr = newArray;
        }

        // 配列の末尾に新しい要素を追加。
        m_ptr[m_size] = value;
        // 配列の要素数を1インクリメントする。
        m_size++;
    }
    T& operator[](int index)
    {
        //　配列は連続しているメモリ上に確保されているため、ただのアドレス加算でアクセスできる。
        //　計算量はO(1)
        return m_ptr[index];
    }
    int* Find(int value)
    {
        // 計算量はO(N)
        for (int i = 0; i < m_size; i++) {
            if (m_ptr[i] == value) {
                return &m_ptr[i];
            }
        }
        // 見つからなかった。
        return nullptr;
    }
    void Erase(int value)
    {
        // 要素の削除
        // 計算量はO(N)
        for (int i = 0; i < m_size; i++) {
            if (m_ptr[i] == value) {
                //要素を見つけたので、この後ろからメモリコピーする。
                for (int j = i; j < m_size - 1; j++) {
                    m_ptr[j] = m_ptr[j + 1];
                }
            }
        }
    }
    T* Begin()
    {
        // Begin()関数は先頭要素を指すアドレスを返す・・・。
        // PushBack()関数で新しいメモリが確保されると無効なアドレスになるのでは・・・。
        return m_ptr;
    }
};

int main()
{
    MyVector<int> hoge;
    hoge.PushBack(10);
    hoge.PushBack(20);
    hoge.PushBack(30);
    hoge.PushBack(40);

    std::cout << hoge[0] << "\n";
    std::cout << hoge[1] << "\n";

    int* p = hoge.Find(30);
    std::cout << *p << "\n";

    hoge.Erase(30);
    p = hoge.Find(30);
    if (p == nullptr) {
        std::cout << "削除できている" << "\n";
    }
    
    return 0;
}



