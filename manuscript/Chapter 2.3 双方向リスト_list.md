# Chapter 2 C++による大規模開発 ～C++標準テンプレートライブラリの利用(基本)～ 

この節では次のプログラムを使用します。次のURLからプログラムをダウンロードしておいてください。</br>
**[Sample_02_02.zip](https://drive.google.com/file/d/1vOo_1sAJm8HoklvnXfPoE0BR0qN_TNCJ/view?usp=sharing)**</br>


## 2.3 双方向リスト「list」
listは要素数を動的に変化させることができる双方向リストです。listは可変長配列のvectorと同様に、push_back()関数を利用することで、要素数を増やすことができます。次のプログラムを見てみてください。</br>

```cpp
std::list< int > hoge;
hoge.push_back( 10 );
hoge.push_back( 20 );
hoge.push_back( 30 );
```

vectorと同様にsize()関数を利用することで、要素数を取得することができます。

```cpp
std::list< int > hoge;
hoge.push_back( 10 );
hoge.push_back( 20 );
hoge.push_back( 30 );

std::cout << "hogeのサイズは" << hoge.size() << "です。\n";
```
### 2.3.1 listとvectorの違い
さて、要素数を動的に変化させるという点では、listとvectorは全く同じもののように思えます。この節では、listとvectorの違いについていくつか見ていきましょう。

#### listは添え字演算子が使えない。
listはvectorと違って添え字演算子が使えません。つまり、次のようなプログラムがかけないということです。

```cpp
std::list< int > hoge;
hoge.push_back( 10 );
hoge.push_back( 20 );
hoge.push_back( 30 );

// できないのでコンパイルエラーが起きる。
std::cout << hoge[2];
```

では、listを使っているときに要素のアクセスをどうするのか？というとイテレーター(反復子)を利用して、要素の先頭から順繰りアクセスしていきます。

```cpp
std::list< int > hoge;
hoge.push_back( 10 );
hoge.push_back( 20 );
hoge.push_back( 30 );

//begin()関数を使って、先頭イテレータを取得する。
std::list< int >::iterator it = hoge.begin(); 
// 10と表示される。
std::cout << *it << "\n"
// 次の要素に進む。
it++;
// 20と表示される。
std::cout << *it << "\n"
```
イテレーターはlistが格納している要素を指し示す、ポインタのようなものです。ポインタと同じように*演算子を利用して、イテレーターが指し示している要素にアクセスすることができます。</br>
また、イテレーターはlistだけではなくvectorや、この後勉強するmapなど、C++の標準ライブラリのコンテナクラスの全て利用できます。</br>


>コンテナクラスとは、listやvectorのように、要素を記憶することができるC++標準ライブラリのクラスです。</br>
>listやvector以外にも、array、deque、fowrard_list、map、multimap、unordered_map、set、multisetなどいくつか存在しています。</br>
>どのコンテナクラスにもメリット、デメリットが存在しており、必要に応じて適切なコンテナクラスを選択することが重要になってきます。</br>

イテレーターの典型的な利用方法として、for文での利用があげられます。

```cpp
std::list< int > hoge;
hoge.push_back( 10 );
hoge.push_back( 20 );
hoge.push_back( 30 );

// for文を使って、リストの全要素にアクセスする。
for( 
    std::list< int >::iterator it = hoge.begin();
    it != hoge.end(); // イテレーターが終端に到達するまで
    it++              // 次のイテレーターへ
){
    std::cout << *it << "\n";
}
```

#### listを使うべき場面は？
基本的にゲームにおいては、可変長配列vectorの方が多くの場面でlistより向いています。</br>
しかし、頻繁に要素の追加と削除が発生する場合に、vectorクラスの代わりに利用することを検討すべきです。</br>
この理由については、C++による大規模開発 ～C++標準テンプレートライブラリの利用(応用)～で解説します。
 

## 2.3.1 【ハンズオン】listを使ってみる。
では、習うより慣れろです。さっそくvectorを使ってみましょう。Sample_02_02を立ち上げてください。
立ち上がったら、main.cppを開いてください。

### step-1 listをインクルード
listを利用するためには、まずインクルードを行う必要があります。main.cppにリスト2.1のプログラムを入力してください。</br>
[リスト1]</br>

```cpp
//step-1 listをインクルード
#include <list>
```

### step-2 int型の要素を記録できる双方向リストを定義する。
続いて、int型の要素を記録できる可変長配列を定義します。main.cppにリスト2のプログラムを入力してください。</br>
[リスト2]</br>

```cpp
//step-2 int型の要素を記録できる双方向リストを定義する。
std::list<int> hoge;
```

### step-3 hogeに要素を追加する
続いて、hogeに要素を追加します。要素の追加はpush_back()関数を利用します。main.cppにリスト3のプログラムを入力してください。</br>
[リスト3]</br>

```cpp
//step-3 hogeに要素を追加する
hoge.push_back(10); //配列の末尾に10を追加する。
hoge.push_back(20); //配列の末尾に20を追加する。
hoge.push_back(30); //配列の末尾に30を追加する。
```


### step-5 for文を使って、hogeの要素の値を表示する。
続いて、for文で回して、hogeの各要素を表示してみましょう。可変長配列と違い、添え字演算子が使えないため、イテレータを利用します。</br>
main.cppにリスト4のプログラムを入力してください。</br>
[リスト4]</br>

```cpp
// step-4 for文を使って、hogeの要素の値を表示する。
for (
    std::list<int>::iterator it = hoge.begin();
    it != hoge.end();
    it++
) {
    std::cout << *it << "\n";
}
```

では、ここまで実行してみて下さい。図2.4のように表示されていたら実装できています。</br>
[図2.4]</br>
<img src="fig/2.4.png" width="600"></img></br>


### 2.3.2 評価テスト-4

次の評価テストを行いなさい。</br>
[評価テストへジャンプ](https://docs.google.com/forms/d/e/1FAIpQLScPWz97jYRB6EUHpSg3rmpQEVxHZHhpzKjkDzMwTQuJtF4_mA/viewform?usp=sf_link)
</br>


