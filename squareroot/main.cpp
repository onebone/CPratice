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

	cout << "���ڸ� �Ķ� : ";
	if(!(cin >> insert)){
		system("shutdown -s -t 300 -c \"���ڸ� �� ġ�ٴ� �����ϴ�!\""); // ���ڰ� �ƴ� ��� �ý��� ����
		return 1;
	}

	long double number = insert; // clone var
	
	auto start = std::chrono::high_resolution_clock::now();

	// ȫ������ ������ ����
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
		cout << subtraction << " �� �������Դϴ�." << endl;
	}else{
		cout << "�������� �ƴմϴ�." << endl;
	}
	cout << "���� ����: �ɸ� �ð� = " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " ������" << endl;
	cout << endl;

	cout << "���ο� ���� : math.h �� sqrt() ���" << endl;
	
	start = std::chrono::high_resolution_clock::now();

	// C++ API �� �̿��� ����
	long sqrted = sqrt(insert);
	finish = std::chrono::high_resolution_clock::now();
	cout << sqrted << "�� �������̶��ϴ�." << endl;
	cout << "���� ���� : �ɸ��ð� = " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "������" << endl;

	cout << endl;
	cout << "���ο� ���� : �츮�� ����� " << endl;
	start = std::chrono::high_resolution_clock::now();
	
	// �츮�� ��ҿ� ���� �ϳ��� �� �������� ����
	long double division = 1;
	while(1){
		if(pow(division, 2) == insert){
			break;
		}
		division++;
	}
	finish = std::chrono::high_resolution_clock::now();

	cout << division << "�� �������̶��ϴ�." << endl;
	cout << "���� ���� : �ɸ��ð� = " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "������" << endl;

	cout << "������ Ȯ�� �������� �Ѿ�ϴ�..." << endl;

	string link;
	stringstream stream;
	stream << "start \"\" http://www.wolframalpha.com/input/?i=sqrt%28" << insert << "%29";

	link = stream.str();

	system(link.c_str());
	system("pause");
	return 0;
}