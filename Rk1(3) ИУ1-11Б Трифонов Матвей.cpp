#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int size;
	cout << "Введите кол-во блюд ";
	cin >> size;
	char**names = new char*[size];
	int*kolv = new int[size];
	int*cened = new int[size];
	cin.ignore();
	for (int i = 0; i<size; ++i){
		char buffer[100];
		cout << "Введите название блюда ";
		cin.getline(buffer,100);
		names[i] = new char[strlen(buffer)];
		strcpy(names[i], buffer);
		cout << "Введите кол-во порций ";
		cin >> kolv[i];
		cout << "введите цену за порцию ";
		cin >> cened[i];
		cout << "Общая сумма заказа " << (cened[i]*kolv[i]) << endl;
		cin.ignore();
	}
	for (int i = 0; i<size-1; ++i){
		for (int j = 0; j<size-i-1; ++j){
			if (strcmp(names[j], names[j+1])>0){
				swap(names[j], names[j+1]);
				swap(kolv[j], kolv[j+1]);
				swap(cened[j], cened[j+1]);
			}
		}
	}double sum = 0;
	double sum1;
	double sum2;
	for (int i = 0; i<size; ++i){
		double c;
		double b;
		b=double(kolv[i]);
		c=double(b*cened[i]);
		sum+=c;
		sum1+=double(cened[i]);
		sum2+=double(kolv[i]);
	}
	for (int i = 0; i<size; ++i){
		cout << " Название блюда - " << names[i] << " Кол-во порций - " << kolv[i] << " Цена за порцию -  " << cened[i] << endl;
	}
	cout << "Сумма цен все блюд - " << sum << endl;
	return 0;
	
}
