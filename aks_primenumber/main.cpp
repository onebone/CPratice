#include <math.h>
#include <iostream>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::endl;

int main(void){
	cout << "어디까지 찾을 것인지 대답하여라 : ";

	long double number;
	if(!(cin >> number)){
		system("shutdown -s -t 300 -c \"숫자를 넣지 않다니 무례하다\"");
		return 1;
	}
	cout << endl;
	
	cout << "소수 계산 중...    0%";
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

	cout << cnt << "개의 소수 발견" << endl;
	cout << endl;
	
	system("pause");
	return 0;
}