#include"function����.h"
using namespace std;
void Dictionary::bayesanalyse() {
	ifstream ifile; Word a[200];				//��С�á�
	char filename[50] = { 0 };
	cout << "��������Ҫ���˵��ʼ�(����.txt)��" << endl;											//������Ҫ���˵��ʼ�����
	cin >> filename;
	ifstream in(filename, ios::in);
	if (in) {																					//txt�ڹ���Ŀ¼��ʱ��������������Ҫ�Ĳ���
		ifile.open(filename);
		const int M = 2200; int m = 0, p = 0, z = 0;
		string zifu[M]; 
		string str;
		for (int n = 0; n <	80; n++) {															//ѭ����ȡ�ʼ�������
			getline(ifile, str);
			for (int i = 0; i < str.length(); i++) {
				if (str[i] == ' ' || str[i] == '?' || str[i] == ',' || str[i] == '!' || str[i] == ';' || str[i] == ':' || str[i] == '"' || str[i] == '.') {
					p++;																			//����ȡ�����ʼ��ִ� �Կո�,�ʺţ����ţ���̾�ţ��ֺţ���ţ�������Ϊ�ָ���
					continue;
				}
				zifu[p] += str[i];																	//���ָ�õ��ַ����ŵ�zifu������
			}
		}
		for (m = 0; m < p; m++) {
			for (int k = 0; k < 126; k++) {
				if (zifu[m].compare(zidian[k].name) == 0)
				{
					a[z] = zidian[k]; z++; 														//�˴��ȴ̱ȶԣ�����ȡ�ʼ��г��ֵ��ȴʴ�ŵ���һ��Word�����У�����������ʱȽϺͼ���
					break;
				}
			}
		}


		Word temp;
		bool noswap;																			//ð�����򣨸��ݸ��ʣ������ָôʣ��ʼ�Ϊ�����ʼ��ĸ��ʣ�����
		int i = 0, j;
		for (i = 0; i < z - 1; i++) {
			noswap = true;
			for (j = z - 1; j > i; j--) {
				if ((a[j].jmp / a[j].nmp) >= (a[j - 1].jmp / a[j - 1].nmp)) {					//�˴�jmp/nmpΪ���ʣ������ָôʣ��ʼ�Ϊ�����ʼ��ĸ��ʣ�
					temp = a[j];
					a[j] = a[j - 1];
					a[j - 1] = temp;
					noswap = false;
				}
				if (noswap) break;
			}
		}

		Word max[3] = { a[0],a[1],a[2] };													//ѡȡ���ʣ������ָôʣ��ʼ�Ϊ�����ʼ��ĸ��ʣ�����������
		double pro;
		pro = 0.4 * (a[0].jmp * a[1].jmp * a[2].jmp) / (a[0].nmp * a[1].nmp * a[2].nmp);	//���� ��Ҷ˹���ϸ��ʹ�ʽ ��õ������ʼ��ĸ���(�����й����ݣ������ʼ�Լȫ���շ����ʼ���Ŀ��40%������ȡ�����ʼ����ָ���Ϊ0.4)
		double po = 0.8;																	//������ֵΪ0.8.����������ֵ����Ϊ�����ʼ�������Ϊ�����ʼ���
		if (pro >= po && pro < 1)																//�������ø�������ֵ���бȽ�
		{
			cout << "�÷��ʼ�Ϊ�����ʼ��ĸ���Ϊ��" << pro << endl;
			cout << "�÷��ʼ�Ϊ�����ʼ�����Ϊ�������ø��ʳ�����ֵ��" << endl;
			cout << "�÷��ʼ����ֵĹؼ��ȴ��У�" << endl;									//��������ֵ�����չʾ�ж����ݣ����ؼ��ȴʣ�
			for (int i = 0; i < 3; i++)
			{
				cout << a[i].seename() << " ";
			}
			cout << endl;
		}
		else if (pro > 1) {																	//�˴������ʼ��������ȴ��������ޣ����ܵõ���Ϊ׼ȷ�Ľ�����˹����õ�jmp/nmp��ƫ�󣩣�����Ӧ��Ϊ�����ʼ��Ŀ����ԣ�
			cout << "�÷��ʼ�Ϊ�����ʼ�����Ϊ�������ø��ʳ�����ֵ��" << endl;
			cout << "�÷��ʼ����ֵĹؼ��ȴ��У�" << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << a[i].seename() << " ";
			}
			cout << endl;
		}
		else
		{
			cout << "�÷��ʼ�Ϊ�����ʼ��ĸ���Ϊ��" << pro << endl;
			cout << "�÷��ʼ�Ϊ�����ʼ�����Ϊ�������ø���δ������ֵ��" << endl;
		}
	}

	else {																						//�ļ�δ���빤��Ŀ¼ʱ��ϵͳ������ʾ	
		cout << "���ı��ļ�δ����ͬ������Ŀ¼�У����ܷ���������������²���!!!" << endl;
	}
}