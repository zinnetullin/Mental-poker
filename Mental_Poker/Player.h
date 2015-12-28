#include "CardDeck.h"
#include <map>
#include <float.h>

#define MIN_VAL 999999

typedef std::map<unsigned, unsigned> c_section;
typedef std::map<unsigned, unsigned>::iterator type_it;

class Player{
private:
	CardDeck			deck;	//������
	c_section			hands; //����� �� ����
	double				k; // k : gcd(k, p-1) = 1
	double				z; // z : k*z = 1 mod(p-1)
public:
	c_deck				enc_hands;
	c_deck				enc_deck;
    static const unsigned handSize;
	Player();
	~Player();
	void				gen_kz(double);//��������� k � z
	void				show_kz();//����� k � z
	void				encryptDeck(double, bool = false);// ����������� ������ ���� 2 ���-� true �� ����� �� ����
	void				decryptDeck(double, bool = false);//������������
	void				showCards(bool = false);//����� �� ����� ������
	void				showEncCards();//����� �� ����� ������������� ����
	void				chooseCards(c_deck);//������� ���� �� ����� ������
	void				setHands(c_deck, double, bool = false, bool = false);// �������� ���� �� ���� ���� ��� ���� ���� ��� ������� ������
	void				showHands();//����� ���� �� ����
	void				showAll();//����� ������ ������������� � �������������

};