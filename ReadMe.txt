/*******************************************
*	Name:Sudoku
*	Description:to solve sudoku
*	Include:Sudoku.h,Sudoku.cpp
*	Version:V1.0
*	Author:Xinyu
*	Email:liuxinyu0922@163.com
*	Date:2013/01/04	
********************************************/

##�����;
  �������,����һ������������Ժܿ������
  ע�⣺��Ҫ���׳��Ը���17�����µ���ʾ�����������ܻ�����ʱ�����

##ʹ�÷���
  ##Sudoku.exe�����Σ����к��У�����81�����֣�Ȼ��������յĽ����

  ##�������ļ����룬������IO�ض���������������:
    Sudoku.exe <in.txt ��in.txt���룬�����������
    ����
    Sudoku.exe <in.txt >out.txt ��in.txt���룬�����out.txt
    �й�IO�ض���ľ������ݣ������аٶ�

  ##������ڱ𴦵��ø������̣����߽�����չ���ɲο��������ⲿ�ӿڣ�����ֱ���޸�Sudoku��Ĵ���  
  
##�ļ��ṹ
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

##���ⲿ�ӿ�
  class Sudoku��
  Suduko::Sudoku(int s[9][9]);//���죬��9*9��ά������
  void Sudoku::print();//���
  bool Sudoku::solve();//��⣬���ɽⷵ��true

##˵��
  �����κ����⣬��������ȡ����ϵ,Email����
