#include"function����.h"
using namespace std;
void Dictionary::check() {
	cout << "�鿴ѵ�����������ݣ�" << endl;
	cout << setw(15) << "Word" << setw(10) << "jmp" << setw(10) << "nmp" <<setw(10)<< endl;
	cout << endl;
	for (int i = 0; i < 126; i++)
		cout <<setw(15)<< zidian[i].name << setw(10) << zidian[i].jmp << setw(10) << zidian[i].nmp << setw(10)<<endl;
	//չʾ ѵ�����ȴʵ�name��jmp��nmp
}