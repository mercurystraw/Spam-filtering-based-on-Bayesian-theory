#include"function����.h"
using namespace std;
Word shuju[126] =								//�ռ����ȴʿ⣡
{
Word("free"),Word("depression"), Word("XXX"),		Word("xxx"),		Word("gambling"), Word("pay"),		Word("charge"),			Word("debtget"),Word("Call"),		Word("gas"),	Word("housewife"),
Word("special"),   Word("ambien"),Word("ultram"),   Word("discounts"),Word("medications"),Word("sale"),     Word("cheap"),          Word("dating"), Word("advertise"),	Word("order"),Word("sign"),
Word("loans"),     Word("winner"),Word("buy"),      Word("tramadol"), Word("Free"),		Word("trading"),	Word("advicer"),		Word("teen"),	Word("match"),		Word("flow"),	Word("click"),	
Word("million"),   Word("risk"),  Word("satisfied"),Word("access"),   Word("act"),		Word("all-new"),	Word("amazing"),		Word("apply"),	Word("believe"),	Word("direct"),	Word("cash"),
Word("click"),     Word("credit"),Word("deal"),     Word("dear"),     Word("deposit"),	Word("discount"),	Word("delete"),			Word("expire"),	Word("extra"),		Word("quote"),	Word("sample"),	Word("trial"),		 
Word("guarantee"), Word("income"),Word("Internet"), Word("lose"),     Word("lower"),	Word("price"),		Word("rate"),			Word("luxury"),	Word("marketing"),	Word("million"),Word("refund"),
Word("profit"),    Word("refund"),Word("sample"),   Word("spam"),     Word("stock"),	Word("success"),	Word("supplies"),		Word("terms"),	Word("urgent"),		Word("dollars"),Word("win"),	Word("urgent"),
Word("scratch"),   Word("sign"),  Word("disorders"),Word("substantial"),Word("super"),	Word("fuck"),		Word("survey"),			Word("capitol"),Word("worry-free"),	Word("FREE"),	Word("boss"),	Word("promise"),	  
Word("dollar"),    Word("lose weight"),Word("expire"),Word("singles"),Word("deposit"),	Word("money"),		Word("flow"),			Word("data usage"),Word("bllogspot"),Word("x - rated"),Word("sexual"),Word("credit card"),
Word("shop"),      Word("taboo"), Word("livingmake"),Word("privacy"), Word("WINNER"),	Word("entry"),		Word("investment"),		Word("investor"),Word("join"),		Word("debt"),   Word("certified"),Word("chance"),
Word("photos"),    Word("product"),Word("pain"),    Word("drug"),     Word("recover"),	Word("incest"),		Word("investing"),	    Word("reply"),Word("Reply"),		Word("offer"),	Word("invest"),
};
Dictionary dic(shuju, 126);		//�ȴʴ����ֵ���


Word::Word() { name = '0'; jmp = 0.001; nmp =0.01 ; }	//Word�๹��

Word::Word(string a) {								//Word�ิ��
	name = a; jmp = 0; nmp = 0.01; 
}
bool Word::operator<(Word a) { return 0; }			//���������
bool Word::operator>(Word a) { return 0; }			//���������
Word Word::operator=(Word &a) { name = a.name; jmp = a.jmp; nmp = a.nmp; return *this; }	//���������
double Word::seejunk()								//����jmp
{
	return jmp;
}
double Word::seenormal()							//����nmp
{
	return nmp;
}
string Word::seename() {							//����name
	return name;
}
void Word::setjunk(double a)						//����jmp
{
	jmp = a;
}
void Word::setnormal(double a)						//����nmp
{
	nmp = a;
}

