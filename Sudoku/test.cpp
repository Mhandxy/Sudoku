#include<iostream>
#include"Sudoku.h"
using namespace std;
int main()
{
	int input_num[9][9];
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			cin>>input_num[i][j];
	}
	Sudoku *test=new Sudoku(input_num);
	if(test->solve())
		test->print();
	else
		cout<<"Can't be solved";
	return 0;
}
