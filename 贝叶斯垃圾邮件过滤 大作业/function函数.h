#pragma once
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<fstream>
#include<iomanip>
using namespace std;
class Word {						//Word类
private:
	string name;					//单词的名字
	double jmp;						//单词的在junk mail出现 概率
	double nmp;						//单词的在正常和垃圾邮件(所有邮件)出现的概率
public:
	Word();						    //默认构造函数
	Word(string a);				    //复制构造函数
	double seejunk();               //接口函数 返回jmp
	double seenormal();             //接口函数 返回nmp
	string seename();               //接口函数 返回name
	void setjunk(double a);         //设置一个词在垃圾邮件中出现的概率
	void setnormal(double a);       //在正常邮件中出现的概率
	bool operator>(Word a);		    //Word大于号重载
	bool operator<(Word a);		    //Word小于号重载
	Word operator =(Word &a);	    //Word等号重载（复制）
	friend class Dictionary;	    //Dictionary为Word友元，便于调用成员函数
};

class Dictionary {						//Dictionary类
private:
	int n;								//单词的数量
	Word zidian[126];					//Word类的数组
public:
	Dictionary();						//默认构造函数
	Dictionary(Word zidian[], int N);	//复制构造函数 注意单词库中数组名字为shuju[].
	bool ifexist(string m );			//查看热词是否在字典中
	void practise();					//训练特征
	void bayesanalyse();				//判断邮件是否是垃圾邮件
	void check();						//查看训练数据

};
extern Dictionary dic;					//设置全局变量

void menu();							//功能：交互界面制作
 
void notice();							//功能：注意事项