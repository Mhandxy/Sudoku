/*******************************************
*	Name:Sudoku
*	Description:to solve sudoku
*	Include:Sudoku.h,Sudoku.cpp
*	Version:V1.0
*	Author:Xinyu
*	Email:liuxinyu0922@163.com
*	Date:2013/01/04	
********************************************/

##软件用途
  求解数独,对于一般的数独，可以很开的求解
  注意：不要轻易尝试给出17个以下的提示的数独，可能会运行时间过长

##使用方法
  ##Sudoku.exe，依次（先行后列）输入81个数字，然后给出最终的结果。

  ##如果想从文件读入，可利用IO重定向，在命令行输入:
    Sudoku.exe <in.txt 从in.txt读入，输出到命令行
    或者
    Sudoku.exe <in.txt >out.txt 从in.txt读入，输出到out.txt
    有关IO重定向的具体内容，可自行百度

  ##如果想在别处调用该求解过程，或者进行扩展，可参考后文类外部接口，或者直接修改Sudoku类的代码  
  
##文件结构
  |-Sudoku
  |  |-Sudoku.h
  |  |-Sudoku.cpp
  |  |-test.cpp
  |-Example
  |  |-input1.txt
  |  |-output1.txt
  |  |-input2.txt
  |  |-output2.txt
  |-Sudoku.exe
  |-ReadMe.txt

##类外部接口
  class Sudoku；
  Suduko::Sudoku(int s[9][9]);//构造，用9*9二维的数组
  void Sudoku::print();//输出
  bool Sudoku::solve();//求解，若可解返回true

##说明
  若有任何问题，都可与我取得联系,Email见上
