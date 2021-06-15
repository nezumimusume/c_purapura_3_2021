# Chapter-4 C++標準テンプレートライブラリの利用(上級)～

この節では次のプログラムを使用します。次のURLからプログラムをダウンロードしておいてください。</br>

**[Sample_04_06.zip](https://drive.google.com/file/d/1WOg8TFvkQmg1q0Y_aBvgeiJZ17rV9_WI/view?usp=sharing)**</br>


## 4.5 連想配列 mapの特徴

## 4.5.1 処理速度
mapの代表的な関数の処理速度は次のようになります。

1. 要素の追加。O(logN)
2. 要素へのアクセス時間がO(logN)
3. 要素の検索時間がO(logN)
4. 要素の削除の時間がO(1)

   

### 1. 要素の末尾への追加。O(logN)
末尾への要素の追加は、要素の数の対数時間となります。

```cpp
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
```

### 2.要素へのアクセス時間がO(logN)
キーによる二分探索を行うためアクセス時間は要素数の対数時間となる。

```cpp
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
```

### 3.要素の検索時間がO(logN)
これは要素へのアクセス時間と同じ処理になる。そのため対数時間となる。


### 4.要素の削除時間がO(1)
削除する要素のイテレータが分かっている場合は定数時間となる。



## 4.5.3 どのようなケースでmapを使うべき？？？
大量のデータを利用するケース。その他連想配列的な処理を行いたい場合。

## 4.5.4 要素を削除すると、イテレーターが無効になる。
これはvector、listと同様に起きる。



## 評価テスト
次の評価テストを行いなさい。</br>
[評価テストへジャンプ](https://docs.google.com/forms/d/e/1FAIpQLSdK_X4V9L0Z5O3evcc-BlynV5bweF3MHW_pB5qLbRutVQCuCg/viewform?usp=sf_link)
</br>

