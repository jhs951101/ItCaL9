#include<iostream>
#include<string>

using namespace std;

string korean_dight(long long n){  // 숫자 한 자리를 한글로 출력하게 해는 함수

	if (n == 1) return "일";
	if (n == 2) return "이";
	if (n == 3) return "삼";
	if (n == 4) return "사";
	if (n == 5) return "오";
	if (n == 6) return "육";
	if (n == 7) return "칠";
	if (n == 8) return "팔";
	if (n == 9) return "구";

}


string korean_number(long long n){

	string str_4;  // str_4: '조,십조,백조,천조'부분만 담는 변수
	string str_3;  // str_3: '억,십억,백억,천억'부분만 담는 변수
	string str_2;  // str_2: '만,십만,백만,천만'부분만 담는 변수
	string str_1;  // str_1: '일,십,백,천'부분만 담는 변수

	if (n >= 1000000000000){
		str_4 = korean_number(n / 1000000000000) + "조 ";  // '조,십조,백조,천조'부분을 담음
		n = n % 1000000000000;
	}

	if (n >= 100000000){
		str_3 = korean_number(n / 100000000) + "억 ";      // '억,십억,백억,천억'부분을 담음
		n = n % 100000000;
	}

	if (n >= 10000){
		str_2 = korean_number(n / 10000) + "만 ";          // '만,십만,백만,천만'부분을 담음
		n = n % 10000;
	}


	if (n >= 1000){
		str_1 = str_1 + korean_dight(n / 1000) + "천";
		n = n % 1000;
	}
	if (n >= 100){
		str_1 = str_1 + korean_dight(n / 100) + "백";
		n = n % 100;
	}
	if (n >= 10){
		str_1 = str_1 + korean_dight(n / 10) + "십";
		n = n % 10;
	}
	if (n > 0){
		str_1 = str_1 + korean_dight(n);
	}                                                  // '일,십,백,천'부분 (만, 억, 조 부분에서도 사용됨)

	return str_4 + str_3 + str_2 + str_1;              // 한글로 변환한 최종 값을 내놓음

}



int main(){

	long long number;

	cout << "1경 보다 작은 양수를 입력하시오 : ";
	cin >> number;                          // 1경 미만의 값을 입력받음(long long)

	cout << korean_number(number) << endl;  // 한글로 변환한 최종 값을 출력

	return 0;

}