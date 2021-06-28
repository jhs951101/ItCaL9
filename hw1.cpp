#include<iostream>
#include<string>

using namespace std;

string korean_dight(long long n){  // ���� �� �ڸ��� �ѱ۷� ����ϰ� �ش� �Լ�

	if (n == 1) return "��";
	if (n == 2) return "��";
	if (n == 3) return "��";
	if (n == 4) return "��";
	if (n == 5) return "��";
	if (n == 6) return "��";
	if (n == 7) return "ĥ";
	if (n == 8) return "��";
	if (n == 9) return "��";

}


string korean_number(long long n){

	string str_4;  // str_4: '��,����,����,õ��'�κи� ��� ����
	string str_3;  // str_3: '��,�ʾ�,���,õ��'�κи� ��� ����
	string str_2;  // str_2: '��,�ʸ�,�鸸,õ��'�κи� ��� ����
	string str_1;  // str_1: '��,��,��,õ'�κи� ��� ����

	if (n >= 1000000000000){
		str_4 = korean_number(n / 1000000000000) + "�� ";  // '��,����,����,õ��'�κ��� ����
		n = n % 1000000000000;
	}

	if (n >= 100000000){
		str_3 = korean_number(n / 100000000) + "�� ";      // '��,�ʾ�,���,õ��'�κ��� ����
		n = n % 100000000;
	}

	if (n >= 10000){
		str_2 = korean_number(n / 10000) + "�� ";          // '��,�ʸ�,�鸸,õ��'�κ��� ����
		n = n % 10000;
	}


	if (n >= 1000){
		str_1 = str_1 + korean_dight(n / 1000) + "õ";
		n = n % 1000;
	}
	if (n >= 100){
		str_1 = str_1 + korean_dight(n / 100) + "��";
		n = n % 100;
	}
	if (n >= 10){
		str_1 = str_1 + korean_dight(n / 10) + "��";
		n = n % 10;
	}
	if (n > 0){
		str_1 = str_1 + korean_dight(n);
	}                                                  // '��,��,��,õ'�κ� (��, ��, �� �κп����� ����)

	return str_4 + str_3 + str_2 + str_1;              // �ѱ۷� ��ȯ�� ���� ���� ������

}



int main(){

	long long number;

	cout << "1�� ���� ���� ����� �Է��Ͻÿ� : ";
	cin >> number;                          // 1�� �̸��� ���� �Է¹���(long long)

	cout << korean_number(number) << endl;  // �ѱ۷� ��ȯ�� ���� ���� ���

	return 0;

}