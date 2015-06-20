#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <chrono>
#include <string.h>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

int main(void){
	long long int insert;

	cout << "숫자를 쳐라 : ";
	if(!(cin >> insert)){
		system("shutdown -s -t 300 -c \"숫자를 안 치다니 무례하다!\""); // 숫자가 아닐 경우 시스템 종료
		return 1;
	}

	long double number = insert; // clone var
	
	auto start = std::chrono::high_resolution_clock::now();

	// 홍길주의 제곱급 연산
	number /= 2;
	long double subtraction = 1.0;

	while(1){
		if(number - subtraction < 0){
			break;
		}
		number -= subtraction++;
	}

	auto finish = std::chrono::high_resolution_clock::now();

	cout << subtraction << ", " << number << endl;
	cout << endl;

	if(subtraction == number * 2){
		cout << subtraction << " 의 제곱근입니다." << endl;
	}else{
		cout << "제곱근이 아닙니다." << endl;
	}
	cout << "연산 종료: 걸린 시간 = " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " 나노초" << endl;
	cout << endl;

	cout << "새로운 연산 : math.h 의 sqrt() 사용" << endl;
	
	start = std::chrono::high_resolution_clock::now();

	// C++ API 를 이용한 연산
	long sqrted = sqrt(insert);
	finish = std::chrono::high_resolution_clock::now();
	cout << sqrted << "의 제곱근이랍니다." << endl;
	cout << "연산 종료 : 걸린시간 = " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "나노초" << endl;

	cout << endl;
	cout << "새로운 연산 : 우리의 연산법 " << endl;
	start = std::chrono::high_resolution_clock::now();
	
	// 우리가 평소에 쓰는 하나씩 다 나눠보는 연산
	long double division = 1;
	while(1){
		if(pow(division, 2) == insert){
			break;
		}
		division++;
	}
	finish = std::chrono::high_resolution_clock::now();

	cout << division << "의 제곱근이랍니다." << endl;
	cout << "연산 종료 : 걸린시간 = " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "나노초" << endl;

	cout << "정답지 확인 페이지로 넘어갑니다..." << endl;

	string link;
	stringstream stream;
	stream << "start \"\" http://www.wolframalpha.com/input/?i=sqrt%28" << insert << "%29";

	link = stream.str();

	system(link.c_str());
	system("pause");
	return 0;
}