#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
	int level;
	int digit;
	int ulang;
	int score = 0;
	int putaran = 0;
	char operasi[4];
	cout << "Set level (1 = + and -; 2 = +, -, and ×; 3 = +, -, ×, and ÷): ";
	cin >> level;
	if(level <= 0 | level > 3){
		cout << "Invalid choise" << endl;
		return 0;
	} else {
		if(level == 1){
			operasi[0] = '+';
			operasi[1] = '-';
			operasi[2] = '+';
			operasi[3] = '-';
		} else if(level == 2){
			operasi[0] = '+';
			operasi[1] = '-';
			operasi[2] = '*';
			operasi[3] = '*';
		} else {
			operasi[0] = '+';
			operasi[1] = '-';
			operasi[2] = '*';
			operasi[3] = '/';
		}

	}
	cout << "Set loop";
	cin >> ulang;
	cout << "Set digits: (max = 5): ";
	cin >> digit;
	if(digit <= 0 & digit > 5){
		cout << "Invalid" << endl;
		return 0;
	}

	cout << "Let's start this game......" << endl;
	string rentanS;
	int rentan;
	for(int i = 0; i < digit; i++)
		rentanS.append("9");
	rentan = stoi(rentanS);

	srand(time(0));
	while(ulang != putaran){
		putaran++;
		
		int angka1 = rand() % rentan + 1;
		int angka2 = rand() % rentan + 1;
		int operasinya = rand() % 4;
		float hasil;
		float jawab;
		if(operasi[operasinya] == '+')
			hasil = static_cast<float>(angka1) + static_cast<float>(angka2);
		else if(operasi[operasinya] == '-')
			hasil = static_cast<float>(angka1) - static_cast<float>(angka2);
		else if(operasi[operasinya] == '*')
			hasil = static_cast<float>(angka1) *  static_cast<float>(angka2);
		else
			hasil = static_cast<float>(angka1) / static_cast<float>(angka2);

		cout << angka1 << " " << operasi[operasinya] << " " << angka2 << " = ";
		cin >> jawab;
		if(jawab == hasil){
			cout << "You're right!" << endl;
			score++;
		}
		else 
			cout << "Wrong!, " << angka1 << " " << operasi[operasinya] << " " << angka2 << " = " << hasil << endl;
	}
		
	cout << "The game is end, score:" << score << endl;
	return 0;
	}
