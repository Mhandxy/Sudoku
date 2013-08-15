/*******************************************
*	Name:Sudoku
*	Description:to solve sudoku
*	Include:Sudoku.h,Sudoku.cpp
*	Version:V1.0
*	Author:Xinyu
*	Email:liuxinyu0922@163.com
*	Date:2013/01/04	
********************************************/
#pragma once
#include<list>
class Sudoku
{
public:
	Sudoku(int s[9][9]);//construct sudoku with a array(9*9)
	void print();
	bool solve();
private:
	int number[9][9];//number in every cell
	std::list<int> valid_num[9][9];//valid numbers in every cell(use stl::list)

	void fill_num(int i,int j,int num);//fill number in (i,j)
	bool try_num(int i,int j,int num);//try number in (i,j)

	void init_valid_num();//init list of valid numbers
	void update_valid_num(int i,int j);//update list of valid numbers
	
	int find_min_valid_count(int &mi,int &mj);//find the cell which valid_num.size() is minimum(nonzero)
	
	void copy_array(int to[9][9],int from[9][9]);//copy array
	bool 	could_solve();//whether can be solved
};
