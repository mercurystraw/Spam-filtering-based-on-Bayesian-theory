#include"function����.h"
using namespace std;


Dictionary::Dictionary() { n = 0; }				//Ĭ�Ϲ��캯��

Dictionary::Dictionary(Word shuju[], int N) {   //���ƹ��죬���ȴʵ�shuju(����)������һ���ֵ�������
	for (int i = 0; i < N; i++)
	{
		zidian[i] = shuju[i];
	}
	n = N;
}
bool Dictionary::ifexist(string m) {            //�鿴�ȴ��Ƿ����ֵ��У��������������һ
	for (int i = 0; i < n; i++) {
		if (zidian[i].name == m)				//string �ıȽ��Ƿ���ͬ����==
			return true;
		else return false;
	}
}


