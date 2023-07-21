#include <iostream>
#include <stdio.h>
using namespace std;

#pragma once

void Line(int length){

	for (int i=0; i < length * 10; i++){

		cout << "*";

	}

	cout << endl;
}

void printArrow(int length){
	for (int row = 0; row < length; row ++){

		if (row < length / 2){

			for (int nspace=0; nspace < length / 4; nspace++){
			cout << " ";
			}

			for (int column = 0; column  < length / 2 ; column++){
				cout << "*";
			}

			cout << endl;
		}

		if (row >= (length / 2)){

			for (int nspace=0; nspace < row - ( length / 2 ); nspace++){
				cout << " ";
			}

			for (int nstar=length; nstar >  2 * (row - (length /2))  ; nstar--){
				cout << "*";
			}

			cout << endl;

		}

	}

}

