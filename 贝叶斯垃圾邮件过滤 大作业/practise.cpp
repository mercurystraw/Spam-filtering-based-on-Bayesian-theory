#include"function����.h"
using namespace std;
void Dictionary::practise() {
	ifstream ifile;
	const int N = 2200;			//��С��
	int i = 0; int p = 0; double count1[126] = { 0 }; double count2[126] = { 0 };
	//������ѵ���ȴʵ�jmp���������ʼ��г��ֵĸ��ʣ�
	ifile.open("junk.txt");										//���ռ��������ʼ�����һ���ı��ļ��У�һ�м�һ���ʼ�������,��40�������ʼ�
	for (int n = 0; n < 40; n++) {
		string zifu[N]; string str;
		getline(ifile, str); int s = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ' ' || str[i] == '?' || str[i] == ',' || str[i] == '!' || str[i] == ';' || str[i] == ':' || str[i] == '"' || str[i] == '.') {
				s++;											//����ȡ�����ʼ��ִ� �Կո�,�ʺţ����ţ���̾�ţ��ֺţ���ţ�������Ϊ�ָ���
				continue;
			}
			zifu[s] += str[i];									//���ָ�õ��ַ����ŵ�zifu������
		}

		for (int j = 0; j < 126; j++) {
			for (int k = 0; k < s; k++) {
				if (zidian[j].name == zifu[k]) {
					count1[j]++; break;
				}
			}
																//�˴�˼·��ѭ����ȡһ�ж�Ӧ��һ���ʼ� ��һ�зִʵõ����ַ���Dictionary�е��ֵ��д����ظ������ȴʳ��ִ�����1��	
		}														//ͬһ���ʼ��г��ֶ��ͬ���ȴʵĻ����ȴʳ��ִ�������1�� �������ȴ��������ʼ��г��ֵĸ���Ϊ���ܳ��ִ���/�ʼ�����=������jmp����
	}
	for (int j = 0; j < 126; j++) {
		zidian[j].jmp = count1[j] * 1.0 / 40;					//һ�����������ʼ��г��ֵĸ��� 40�������ʼ�  
		if (zidian[j].jmp == 0) zidian[j].jmp = 0.04;			//����ȴʲ������������ɵ������ʼ��� ���ó����������ʼ�����Ϊ0.04
	}
	ifile.close();
	//����Ϊѵ���ȴʵ�nmp���������ʼ��г��ֵĸ��ʣ�����ͬ��
	ifile.open("allmail.txt");									//���ռ��������ʼ�����һ���ı��ļ��У�һ�м�һ���ʼ�������,��80���ʼ�
	for (int n = 0; n < 80; n++) {
		string zifu[N]; string str;
		getline(ifile, str);
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ' ' || str[i] == '?' || str[i] == ',' || str[i] == '!' || str[i] == ';' || str[i] == ':' || str[i] == '"' || str[i] == '.') {
				p++;											//����ȡ�����ʼ��ִ� �Կո�,�ʺţ����ţ���̾�ţ��ֺţ���ţ�������Ϊ�ָ���
				continue;
			}
			zifu[p] += str[i];									//���ָ�õ��ַ����ŵ�zifu������
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
		zidian[j].nmp = count2[j] * 1.0 / 80;					//��80���ʼ�          
		if (zidian[j].nmp == 0) zidian[j].nmp = 0.035;			//����ȴʲ����������ɵ��ʼ��� ���ó����������ʼ�����Ϊ0.035���������� �����ʼ�ռ���ʼ���40%��
		ifile.close();
	}
	cout << "�Ѹ���Ŀ¼�е������ʼ��������ʼ����ȡѵ����" << endl;
	cout << "ѵ���ɹ����뷵�أ�" << endl;
}