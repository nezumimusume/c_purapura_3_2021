# Chapter 2 C++による大規模開発 ～C++標準テンプレートライブラリの利用(基本)～ 


## 2.2 可変長配列「vector」
この節では次のプログラムを使用します。次のURLからプログラムをダウンロードしておいてください。</br>
**[Sample_02_01.zip](https://drive.google.com/file/d/1AXaP7mYkUd_bEqnuq2Keje1DI2JFrUnX/view?usp=sharing)**</br>
vectorは要素数を動的に変化させることができる配列です。「動的」というのはプログラム実行中ということです。</br>
これまで、皆さんが勉強した配列は、固定長配列です。固定長配列はプログラムの実行中にサイズを変えることはできません。</br>
次のプログラムを読んでみてください。</br>

```cpp
int hoge[10];
 ・
 省略
 ・
for( int i = 0; i < 10; i++){
    std::cout << hoge[i];
}
```
このプログラムには配列hogeが登場していますが、この配列のサイズは10で固定です。プログラム実行中に、動的にサイズを変えることはできません。</br>
可変長配列はこのサイズをプログラム実行中に変更することができるのです。</br>
要素を追加するにはpush_back()関数を利用します。

## 2.2.1 【ハンズオン】vectorを使ってみる。
では、習うより慣れろです。さっそくvectorを使ってみましょう。Sample_02_01を立ち上げてください。
立ち上がったら、main.cppを開いてください。

### step-1 vectorをインクルード
vectorを利用するためには、まずインクルードを行う必要があります。main.cppにリスト2.1のプログラムを入力してください。</br>
[リスト2.1]</br>

```cpp
//step-1 vectorをインクルード
#include <vector>
```

### step-2 int型の要素を記録できる可変長配列を定義する。
続いて、int型の要素を記録できる可変長配列を定義します。main.cppにリスト2.2のプログラムを入力してください。</br>
[リスト2.2]</br>

```cpp
//step-2 int型の要素を記録できる可変長配列を定義する。
std::vector<int> hoge;
```

### step-3 hogeに要素を追加する
続いて、hogeに要素を追加します。要素の追加はpush_back()関数を利用します。main.cppにリスト2.3のプログラムを入力してください。</br>
[リスト2.3]</br>

```cpp
//step-3 hogeに要素を追加する
hoge.push_back(10); //配列の末尾に10を追加する。
hoge.push_back(20); //配列の末尾に20を追加する。
hoge.push_back(30); //配列の末尾に30を追加する。
```

### step-4 hogeのサイズを表示する。
さて、step-3でhogeにint型のデータを3つ追加しました。ですので、可変長配列hogeのサイズは3になっているはずです。可変長配列のサイズはsize()関数で取得することができます。</br>
では、本当にhogeのサイズが3になっているか確認してみましょう。main.cppにリスト2.4のプログラムを入力して下さい。
[リスト2.4]</br>

```cpp
//step-4 hogeのサイズを表示する。
std::cout << "hogeのサイズは" << hoge.size() << "です。\n";
```

### step-5 for文を使って、hogeの要素の値を表示する。
可変長配列は、固定長配列と同じように添え字演算子、[]を利用してアクセスすることができます。では、for文で回して、hogeの各要素を表示してみましょう。</br>
main.cppにリスト2.5のプログラムを入力してください。</br>
[リスト2.5]</br>

```cpp
//step-5 for文を使って、hogeの要素の値を表示する。
for (int i = 0; i < hoge.size(); i++) {
    std::cout 
        << "hoge["
        << i 
        << "]の値は" 
        << hoge[i] 
        << "です。\n";
}
```

では、ここまでで一度実行してみて下さい。図2.2のように表示されていたら実装できています。</br>
[図2.2]</br>
<img src="fig/2.2.png" width="600"></img></br>

### step-6 さらにhogeに要素を追加する。
step-6では更にhogeに要素を追加してみましょう。main.cppにリスト2.6のプログラムを入力して下さい。</br>
[リスト2.6]</br>

```cpp
//step-6 さらにhogeに要素を追加する。
hoge.push_back(40);
hoge.push_back(50);
```

### step-7 再度hogeのサイズを表示する。
step-6でhogeに要素を２つ追加したので、hogeの要素数は5になっているはずです。では、再度hogeのサイズを表示するプログラムを追加しましょう。</br>
main.cppにリスト2.7のプログラムを入力してください。</br>
[リスト2.7]
```cpp
//step-7 再度hogeのサイズを表示する。
std::cout << "hogeのサイズは" << hoge.size() << "です。\n";
```

### step-8 もう一度for文を使って、hogeの要素の値を表示する。
では、最後にもう一度for文を使ってhogeの要素の値を表示してみましょう。main.cppにリスト2.8のプログラムを入力してください。</br>
[リスト2.8]
```cpp
//step-8 もう一度for文を使って、hogeの要素の値を表示する。
for (int i = 0; i < hoge.size(); i++) {
    std::cout
        << "hoge["
        << i
        << "]の値は"
        << hoge[i]
        << "です。\n";
}
```

入力出来たら実行してみてください。図2.3のように表示されていたら実装できています。</br>
[図2.3]</br>
<img src="fig/2.3.png" width="600"></img></br>

## 2.2.1 int型以外も記録できるの？
vectorクラスはテンプレートクラスとなっているため、int型以外の値も記録できます。float型を記録できる可変長配列を定義して、利用するコードを下記に示します。</br>

```cpp
std::vector<float> hoge;
hoge.push_back(10.0f);
hoge.push_back(20.0f);
hoge.push_back(30.0f);
```

vectorクラスはintやfloatのような組み込み型だけではなく、ユーザー定義のクラスでも利用できます。下記のコードはMatrixクラスのオブジェクトの値を記録しているコードです。</br>

```cpp
Matrix m0, m1, m2;
 　・
  省略
 　・
std::vector<Matrix> hoge;
hoge.push_back( m0 );
hoge.push_back( m1 );
hoge.push_back( m2 );
```


### 2.2.2 評価テスト-3

次の評価テストを行いなさい。</br>
[評価テストへジャンプ](https://docs.google.com/forms/d/e/1FAIpQLSfsx_Emr8kf2u1nInf9b_mB8jcRCKhOnmrR8SmMShy8T1I5mA/viewform?usp=sf_link)
</br>


