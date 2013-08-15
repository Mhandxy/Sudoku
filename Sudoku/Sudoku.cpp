#include "Sudoku.h"
#include <iostream>
using namespace std;

//construct with a array(9*9)
Sudoku::Sudoku(int s[9][9])
{
	copy_array(number,s);
	//deal with incorrect input,let numbers which are not in range[0,9] be 0
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			if(number[i][j]>9&&number[i][j]<0)
				number[i][j]=0;
	}
	init_valid_num();//init list of valid numbers
}

void Sudoku::print()
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cout<<number[i][j]<<" ";
			if(j%3==2)
				cout<<" ";
		}
		cout<<endl;
		if(i==2||i==5) 
			cout<<endl;
	}
}

//cycle to find the cell which valid_num.size() is minimum(nonzero)
//if min_valid_count is 1,fill it
//else in order to try them
bool Sudoku::solve()
{
	int fi,fj;//filli,fillj
	int min_valid_count=0;
	while((min_valid_count=find_min_valid_count(fi,fj))<10)//m_v_c>9means all cells have been filled
	{
		if(!could_solve()) return false;//if can not be solved,return false
		if(min_valid_count==1)//if m_v_n is 1,fill it
			fill_num(fi,fj,*valid_num[fi][fj].begin());
		else
		{
			list<int> valid(valid_num[fi][fj]);//save list to try
			list<int>::iterator iter=valid.begin();
			for(;iter!=valid.end();++iter)
				if(try_num(fi,fj,*iter)) return true;//try them all,if find a correct answer,return true;
			return false;
		}
	}
	return true;//complete
}

//fill number in (i,j)
void Sudoku::fill_num(int i,int j,int num)
{
	number[i][j]=num;
	update_valid_num(i,j);//update valid number in(i,j)
	valid_num[i][j].clear();//clear the list in(i,j)
}

//try number in (i,j)
bool Sudoku::try_num(int i,int j,int num)
{
	int tmp[9][9];//save numbers before having a try
	copy_array(tmp,number);
	fill_num(i,j,num);
	if(solve())//then solve the sudoku	
		return true;
	copy_array(number,tmp);
	init_valid_num();
	return false;
}

//init list of valid numbers
void Sudoku::init_valid_num()
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			//traversal all cells
			valid_num[i][j].clear();
			if(number[i][j]==0)//don't fill with a number
			{
				//remove numbers from same row,colnum,block
				for(int k=1;k<10;k++)
						valid_num[i][j].push_back(k);
				for(int k=0;k<9;k++)
				{
						valid_num[i][j].remove(number[i][k]);
						valid_num[i][j].remove(number[k][j]);
				}
				int m=int(i/3)*3;
				int n=int(j/3)*3;
				for(int k=m;k<m+3;k++)
				{
					for(int l=n;l<n+3;l++)						
						valid_num[i][j].remove(number[k][l]);
				}
			}
		}
	}
}

//update list of valid numbers
void Sudoku::update_valid_num(int i,int j)
{
	//remove numbers from same row,colnum,block
	int tmp=number[i][j];
	for(int m=0;m<9;m++)
			valid_num[i][m].remove(tmp);
	for(int n=0;n<9;n++)
			valid_num[n][j].remove(tmp);
	int m=int(i/3)*3;
	int n=int(j/3)*3;
	for(int k=m;k<m+3;k++)
	{
		for(int l=n;l<n+3;l++)						
			valid_num[k][l].remove(tmp);
	}
}

//find the cell which valid_num.size() is minimum(nonzero)
int Sudoku::find_min_valid_count(int& mini,int &minj)
{
	int min=10;//any number large than 9
	minj=mini=0;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			int tmp=valid_num[i][j].size();
			if(tmp>0&&tmp<min)
			{
				min=tmp;
				mini=i;
				minj=j;
				if(tmp==1) 
					return min;//find a cell which can only fill in one number,return
			}
		}
	}
	return min;//if all cells have been filled,min will not change,this soduku is solved
}

//if there is a cell than can't fill with any number ,this sudoku can'be solved
bool Sudoku::could_solve()
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			if(valid_num[i][j].size()==0&&number[i][j]==0)
				return false;
	}
	return true;
}

void Sudoku::copy_array(int to[9][9],int from[9][9])
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			to[i][j]=from[i][j];
	}
}
