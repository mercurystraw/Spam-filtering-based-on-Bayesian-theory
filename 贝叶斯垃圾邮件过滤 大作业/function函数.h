#pragma once
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<fstream>
#include<iomanip>
using namespace std;
class Word {						//Word��
private:
	string name;					//���ʵ�����
	double jmp;						//���ʵ���junk mail���� ����
	double nmp;						//���ʵ��������������ʼ�(�����ʼ�)���ֵĸ���
public:
	Word();						    //Ĭ�Ϲ��캯��
	Word(string a);				    //���ƹ��캯��
	double seejunk();               //�ӿں��� ����jmp
	double seenormal();             //�ӿں��� ����nmp
	string seename();               //�ӿں��� ����name
	void setjunk(double a);         //����һ�����������ʼ��г��ֵĸ���
	void setnormal(double a);       //�������ʼ��г��ֵĸ���
	bool operator>(Word a);		    //Word���ں�����
	bool operator<(Word a);		    //WordС�ں�����
	Word operator =(Word &a);	    //Word�Ⱥ����أ����ƣ�
	friend class Dictionary;	    //DictionaryΪWord��Ԫ�����ڵ��ó�Ա����
};

class Dictionary {						//Dictionary��
private:
	int n;								//���ʵ�����
	Word zidian[126];					//Word�������
public:
	Dictionary();						//Ĭ�Ϲ��캯��
	Dictionary(Word zidian[], int N);	//���ƹ��캯�� ע�ⵥ�ʿ�����������Ϊshuju[].
	bool ifexist(string m );			//�鿴�ȴ��Ƿ����ֵ���
	void practise();					//ѵ������
	void bayesanalyse();				//�ж��ʼ��Ƿ��������ʼ�
	void check();						//�鿴ѵ������

};
extern Dictionary dic;					//����ȫ�ֱ���

void menu();							//���ܣ�������������
 
void notice();							//���ܣ�ע������