# Chapter 3 C++による大規模開発 ～C++標準テンプレートライブラリの利用(中級)～ 

この節では次のプログラムを使用します。次のURLからプログラムをダウンロードしておいてください。</br>
**[Sample_02_01.zip](https://drive.google.com/file/d/1AXaP7mYkUd_bEqnuq2Keje1DI2JFrUnX/view?usp=sharing)**</br>

## 3.1 検索
std::find()関数を利用することで、可変長配列に記録されている要素を検索することができます。次のコードはfind()関数の利用例です。
```cpp
std::vector< int > hoge;
hoge.push_back(30);
hoge.push_back(40);
hoge.push_back(50);

std::vector<int>::iterator it;
// find関数は第一引数と第二引数にイテレーターを指定して、
// 検索範囲を指定する。第三引数は検索する値。
// 今回だと、hogeの先頭から終端までの範囲で、40という値を検索している。
it = std::find(
    hoge.begin(),   
    hoge.end(), 
    40 
);

if ( it == hoge.end() ) {
    // 検索対象の値が見つからなかった場合は終端のイテレーターを返してくる。
    std::cout << "見つからなかった" << "\n";
}else{
    std::cout << "見つかった" << *it << "\n";
}
```

## 3.2 要素の削除
vectorはerase()関数を利用することで、要素を削除することができます。erase()関数に削除したいイテレーターを渡すことで削除することができます。次のコードはerase()関数の利用例です。

```cpp
std::vector< int > hoge;
hoge.push_back(30);
hoge.push_back(40);
hoge.push_back(50);

std::vector<int>::iterator it;
// hogeから40が記録されているイテレータを検索する。
it = std::find(
    hoge.begin(),   
    hoge.end(), 
    40 
);

if ( it != hoge.end() ) {
    // 見つかったので削除
    hoge.erase( it );
}
```

## 3.2 実習課題
Question_03_01のコメントを読んで課題に取り組みなさい。


## 3.3 実習課題(上級)
Question_03_01のコメントを読んで課題に取り組みなさい。

次の評価テストを行いなさい。</br>
[評価テストへジャンプ](https://docs.google.com/forms/d/e/1FAIpQLSfsx_Emr8kf2u1nInf9b_mB8jcRCKhOnmrR8SmMShy8T1I5mA/viewform?usp=sf_link)
</br>


