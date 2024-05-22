#include"function函数.h"
using namespace std;


Dictionary::Dictionary() { n = 0; }				//默认构造函数

Dictionary::Dictionary(Word shuju[], int N) {   //复制构造，将热词的shuju(数据)存贮到一个字典数组中
	for (int i = 0; i < N; i++)
	{
		zidian[i] = shuju[i];
	}
	n = N;
}
bool Dictionary::ifexist(string m) {            //查看热词是否在字典中，若存在则次数加一
	for (int i = 0; i < n; i++) {
		if (zidian[i].name == m)				//string 的比较是否相同用了==
			return true;
		else return false;
	}
}


