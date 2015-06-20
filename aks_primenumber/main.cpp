#include <math.h>
#include <iostream>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::endl;

int main(void){
	cout << "������ ã�� ������ ����Ͽ��� : ";

	long double number;
	if(!(cin >> number)){
		system("shutdown -s -t 300 -c \"���ڸ� ���� �ʴٴ� �����ϴ�\"");
		return 1;
	}
	cout << endl;
	
	cout << "�Ҽ� ��� ��...    0%";
	long int cnt = 0;
	int lastPercent = 0;
	for(int num = 2; num <= number; num += 2){
		double root = sqrt(num);
		bool isPrime = false;

		int percent = ((long double)num / (long double)number) * 100;
		if(lastPercent != percent){
			lastPercent = percent;
			cout << "\b\b\b\b";
			if(percent < 10){
				cout << " ";
			}
			cout << " " << percent << "%";
		}

		for(int i = 3; i <= root; i ++){
			if(num % i == 0){
				isPrime = true;
				break;
			}
		}
		if(!isPrime){
			cnt++;
		}
	}

	cout << endl;

	cout << cnt << "���� �Ҽ� �߰�" << endl;
	cout << endl;
	
	system("pause");
	return 0;
}