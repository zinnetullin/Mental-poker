#include <iostream>
#include <time.h>
#include <algorithm>
#include <string>
#include "Player.h"
#include "gen_rand.h"

using namespace std;

int main()
{
	srand(time(0));

	double p;
	p = gen_prime(MIN_VAL, 9999999);//�������� p
	
	cout<<"Alice:\n";//������� ������ Alice.
	Player Alice;
	Alice.gen_kz(p);//���������� k : gcd(k,p-1)=1 � z : k*z = 1 (mod p-1)
	Alice.show_kz();//�������

	
	cout<<"Bob:\n";//������� ������ Bob.
	Player Bob;
	Bob.gen_kz(p);//���������� k : gcd(k,p-1)=1 � z : k*z = 1 (mod p-1)
	Bob.show_kz();//�������

	cout << string(80, '-');
	cout << endl;

	Alice.encryptDeck(p);//����� ������� ������ � �������� ����
	
	cout << string(80, '-');
	cout << endl;
	cout<<"Bob choose for Alice : \n\n";
	Bob.chooseCards(Alice.enc_deck);//��� �������� 5 ��������� ���� �� ������ �����(�������������) � �������� �����
	Alice.setHands(Bob.enc_deck, p);//����� �������� 5 ���� 

	cout << string(80, '-');
	cout << endl;
	cout<<"ALICE HANDS:\n\n";

	Alice.showHands();//������� ����� ����� � ����
	
	cout << string(80, '-');
	cout << endl;
	cout<<"Bob choose for himself : \n\n";
	Bob.chooseCards(Alice.enc_deck);//��� �������� ����� ��� ����
	Bob.setHands(Bob.enc_deck, p, true);//������� �� ����� ������ � �������� �����

	Alice.setHands(Bob.enc_hands, p, false, true);//����� ��������� ����� ���������� ����� � �������� ���

	Bob.setHands(Alice.enc_hands,p);//��� ��������� ���������� ����� � ������ �� ����� ��� ��� �� �����

	cout << string(80, '-');
	cout << endl;
	cout<<"BOB HANDS:\n\n";
	Bob.showHands();//������� ����� ���� � ����

	cout << endl;
	system("pause");
	return 0;
}