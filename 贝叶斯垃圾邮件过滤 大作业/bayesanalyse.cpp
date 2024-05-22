#include"function函数.h"
using namespace std;
void Dictionary::bayesanalyse() {
	ifstream ifile; Word a[200];				//大开小用。
	char filename[50] = { 0 };
	cout << "请输入想要过滤的邮件(名称.txt)：" << endl;											//输入想要过滤的邮件名！
	cin >> filename;
	ifstream in(filename, ios::in);
	if (in) {																					//txt在工程目录中时接下来进行所需要的操作
		ifile.open(filename);
		const int M = 2200; int m = 0, p = 0, z = 0;
		string zifu[M]; 
		string str;
		for (int n = 0; n <	80; n++) {															//循环读取邮件行数据
			getline(ifile, str);
			for (int i = 0; i < str.length(); i++) {
				if (str[i] == ' ' || str[i] == '?' || str[i] == ',' || str[i] == '!' || str[i] == ';' || str[i] == ':' || str[i] == '"' || str[i] == '.') {
					p++;																			//将读取出的邮件分词 以空格,问号，逗号，感叹号，分号，句号，引号作为分隔符
					continue;
				}
				zifu[p] += str[i];																	//将分割好的字符串放到zifu数组里
			}
		}
		for (m = 0; m < p; m++) {
			for (int k = 0; k < 126; k++) {
				if (zifu[m].compare(zidian[k].name) == 0)
				{
					a[z] = zidian[k]; z++; 														//此处热刺比对，将读取邮件中出现的热词存放到另一个Word数组中，便于下面概率比较和计算
					break;
				}
			}
		}


		Word temp;
		bool noswap;																			//冒泡排序（根据概率（若出现该词，邮件为垃圾邮件的概率）排序）
		int i = 0, j;
		for (i = 0; i < z - 1; i++) {
			noswap = true;
			for (j = z - 1; j > i; j--) {
				if ((a[j].jmp / a[j].nmp) >= (a[j - 1].jmp / a[j - 1].nmp)) {					//此处jmp/nmp为概率（若出现该词，邮件为垃圾邮件的概率）
					temp = a[j];
					a[j] = a[j - 1];
					a[j - 1] = temp;
					noswap = false;
				}
				if (noswap) break;
			}
		}

		Word max[3] = { a[0],a[1],a[2] };													//选取概率（若出现该词，邮件为垃圾邮件的概率）最大的三个词
		double pro;
		pro = 0.4 * (a[0].jmp * a[1].jmp * a[2].jmp) / (a[0].nmp * a[1].nmp * a[2].nmp);	//根据 贝叶斯联合概率公式 求得的垃圾邮件的概率(根据有关数据，垃圾邮件约全国收发总邮件数目的40%，所以取垃圾邮件出现概率为0.4)
		double po = 0.8;																	//设置阈值为0.8.（若超过阈值，则为垃圾邮件，否则为正常邮件）
		if (pro >= po && pro < 1)																//计算所得概率与阈值进行比较
		{
			cout << "该封邮件为垃圾邮件的概率为：" << pro << endl;
			cout << "该封邮件为垃圾邮件，因为计算所得概率超过阈值！" << endl;
			cout << "该封邮件出现的关键热词有：" << endl;									//若大于阈值，则会展示判断依据（即关键热词）
			for (int i = 0; i < 3; i++)
			{
				cout << a[i].seename() << " ";
			}
			cout << endl;
		}
		else if (pro > 1) {																	//此处由于邮件样本和热词数量有限，不能得到较为准确的结果（人工设置的jmp/nmp会偏大），但反应了为垃圾邮件的可能性！
			cout << "该封邮件为垃圾邮件，因为计算所得概率超过阈值！" << endl;
			cout << "该封邮件出现的关键热词有：" << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << a[i].seename() << " ";
			}
			cout << endl;
		}
		else
		{
			cout << "该封邮件为垃圾邮件的概率为：" << pro << endl;
			cout << "该封邮件为正常邮件，因为计算所得概率未超过阈值！" << endl;
		}
	}

	else {																						//文件未存入工程目录时，系统发出提示	
		cout << "该文本文件未存入同级工程目录中，不能分析！请移入或重新操作!!!" << endl;
	}
}