#include <iostream>
using namespace std;
#include "pessoa.h"



main(){
	
	pessoa xunda;
	xunda.nome = "xunda";
	xunda.idade = 34;

	pessoa bastiao;
	bastiao.nome = "Sebastiao";
	bastiao.idade = 56;
	
	pessoa manel;
	manel.nome = "Manoel Ora Pois";
	manel.idade = 48;
	
	xunda.apresentar_se();
	system("pause");
	
	bastiao.apresentar_se();
	system("pause");
	
	manel.apresentar_se();
	system("pause");
}
