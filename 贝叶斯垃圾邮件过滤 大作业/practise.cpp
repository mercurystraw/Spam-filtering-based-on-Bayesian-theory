#include"function函数.h"
using namespace std;
void Dictionary::practise() {
	ifstream ifile;
	const int N = 2200;			//大开小用
	int i = 0; int p = 0; double count1[126] = { 0 }; double count2[126] = { 0 };
	//以下是训练热词的jmp（在垃圾邮件中出现的概率）
	ifile.open("junk.txt");										//将收集的垃圾邮件放入一个文本文件中，一行即一封邮件的内容,共40封垃圾邮件
	for (int n = 0; n < 40; n++) {
		string zifu[N]; string str;
		getline(ifile, str); int s = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ' ' || str[i] == '?' || str[i] == ',' || str[i] == '!' || str[i] == ';' || str[i] == ':' || str[i] == '"' || str[i] == '.') {
				s++;											//将读取出的邮件分词 以空格,问号，逗号，感叹号，分号，句号，引号作为分隔符
				continue;
			}
			zifu[s] += str[i];									//将分割好的字符串放到zifu数组里
		}

		for (int j = 0; j < 126; j++) {
			for (int k = 0; k < s; k++) {
				if (zidian[j].name == zifu[k]) {
					count1[j]++; break;
				}
			}
																//此处思路：循环读取一行对应的一封邮件 若一行分词得到的字符与Dictionary中的字典中词有重复，则热词出现次数加1，	
		}														//同一封邮件中出现多次同个热词的话，热词出现次数当作1次 则最终热词在垃圾邮件中出现的概率为：总出现次数/邮件数量=单个词jmp概率
	}
	for (int j = 0; j < 126; j++) {
		zidian[j].jmp = count1[j] * 1.0 / 40;					//一个词在垃圾邮件中出现的概率 40封垃圾邮件  
		if (zidian[j].jmp == 0) zidian[j].jmp = 0.04;			//如果热词不出现在所收纳的垃圾邮件中 设置出现在垃圾邮件概率为0.04
	}
	ifile.close();
	//以下为训练热词的nmp（在所有邮件中出现的概率）与上同理
	ifile.open("allmail.txt");									//将收集的所有邮件放入一个文本文件中，一行即一封邮件的内容,共80封邮件
	for (int n = 0; n < 80; n++) {
		string zifu[N]; string str;
		getline(ifile, str);
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ' ' || str[i] == '?' || str[i] == ',' || str[i] == '!' || str[i] == ';' || str[i] == ':' || str[i] == '"' || str[i] == '.') {
				p++;											//将读取出的邮件分词 以空格,问号，逗号，感叹号，分号，句号，引号作为分隔符
				continue;
			}
			zifu[p] += str[i];									//将分割好的字符串放到zifu数组里
		}

		for (int j = 0; j < 126; j++) {
			for (int k = 0; k < p; k++) {
				if (zidian[j].name == zifu[k]) {
					count2[j]++; break;
				}
			}
		}
	}
	for (int j = 0; j < 126; j++) {
		zidian[j].nmp = count2[j] * 1.0 / 80;					//共80封邮件          
		if (zidian[j].nmp == 0) zidian[j].nmp = 0.035;			//如果热词不出现在收纳的邮件中 设置出现在所有邮件概率为0.035（根据数据 垃圾邮件占总邮件数40%）
		ifile.close();
	}
	cout << "已根据目录中的垃圾邮件和正常邮件库读取训练！" << endl;
	cout << "训练成功！请返回！" << endl;
}