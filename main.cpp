/* 
	Seccion 1 Ejercicio 2
	Grupo K100101
 */
 
#include <iostream>
using namespace std;

char ReadProposicion();
int ReadConectorLogico();
void ProcesoImpresion(char proposiciones[], int primerConector, int segundoConector);
void SetearValoresPropocisiones(bool valoresProposiciones[],char proposiciones[], char nombreProposicion, bool valorProposicion);
bool obtenerValorCompuesto(bool valoresProposiciones[],int primerConector,int segundoConector);
char Mayuscula(char caracter);


int main() {
	char proposiciones [3];
	proposiciones[0] = ReadProposicion();
	int primerConector = ReadConectorLogico();
	proposiciones [1] = ReadProposicion();
	int segundoConector = ReadConectorLogico();
	proposiciones[2] = ReadProposicion();
	
	ProcesoImpresion(proposiciones, primerConector, segundoConector);
}

char ReadProposicion() {
	cout << "\nSeleccione una proposicion(use la letra en mayuscula para negarla): \n";
	cout << "\tp\n";
	cout << "\tq\n";
	cout << "\tr\n";
	char p;
	cin>>p;
	if(!((p>='p' and p<='r') or (p>='P' and p<='R'))) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "\nSeleccione una proposicion valida (p,q,r,P,Q,R)\n";
		p = ReadProposicion();
	}
	return p;
}

int ReadConectorLogico() {
	cout << "\nSeleccione el conector logico a utilizar(1, 2 o 3): \n";
	cout << "\t1. Y\n";
	cout << "\t2. O\n";
	cout << "\t3. Entonces\n";
	int c;
	cin >> c;
	if(c<1 or c>3) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "\nSeleccione un conector valido, entre 1 y 3\n";
		c = ReadConectorLogico();
	}
	return c;
}

void ProcesoImpresion(char proposiciones[], int primerConector, int segundoConector) {
	bool valoresProposiciones [3];
	//p falso, q falso, r falso (000)
	SetearValoresPropocisiones(valoresProposiciones,proposiciones,'p', false);
	SetearValoresPropocisiones(valoresProposiciones,proposiciones,'q', false);
	SetearValoresPropocisiones(valoresProposiciones,proposiciones,'r', false);
	bool valorCompuesto = obtenerValorCompuesto(valoresProposiciones, primerConector, segundoConector);
	
	//p falso, q falso, r verdadero (001)
	SetearValoresPropocisiones(valoresProposiciones,proposiciones,'r', true);
	if(obtenerValorCompuesto(valoresProposiciones, primerConector, segundoConector) != valorCompuesto) {
		cout<<"Contingencia";
		return;
	}
	
	//p falso, q verdadero, r verdadero (011)
	SetearValoresPropocisiones(valoresProposiciones,proposiciones,'q', true);
	if(obtenerValorCompuesto(valoresProposiciones, primerConector, segundoConector) != valorCompuesto) {
		cout<<"Contingencia";
		return;
	}
	
	//p falso, q verdadero, r falso (010)
	SetearValoresPropocisiones(valoresProposiciones,proposiciones,'r', false);
	if(obtenerValorCompuesto(valoresProposiciones, primerConector, segundoConector) != valorCompuesto) {
		cout<<"Contingencia";
		return;
	}
	
	//p verdadero, q verdadero, r falso (110)
	SetearValoresPropocisiones(valoresProposiciones,proposiciones,'p', true);
	if(obtenerValorCompuesto(valoresProposiciones, primerConector, segundoConector) != valorCompuesto) {
		cout<<"Contingencia";
		return;
	}
	
	//p verdadero, q verdadero, r verdadero (111)
	SetearValoresPropocisiones(valoresProposiciones,proposiciones,'r', true);
	if(obtenerValorCompuesto(valoresProposiciones, primerConector, segundoConector) != valorCompuesto) {
		cout<<"Contingencia";
		return;
	}
	
	//p verdadero, q falso, r verdadero (101)
	SetearValoresPropocisiones(valoresProposiciones,proposiciones,'q', false);
	if(obtenerValorCompuesto(valoresProposiciones, primerConector, segundoConector) != valorCompuesto) {
		cout<<"Contingencia";
		return;
	}
	
	//p verdadero, q falso, r falso (100)
	SetearValoresPropocisiones(valoresProposiciones,proposiciones,'r', false);
	if(obtenerValorCompuesto(valoresProposiciones, primerConector, segundoConector) != valorCompuesto) {
		cout<<"Contingencia";
		return;
	}
	
	if(valorCompuesto) {
		cout<<"Tautologia";
	} else {
		cout<<"Contradiccion";
	}
	
	return;
}
void SetearValoresPropocisiones(bool valoresProposiciones[],char proposiciones[], char nombreProposicion, bool valorProposicion) {
	for(int i = 0; i < 3; i++) {
		if(proposiciones[i] == nombreProposicion) {
			valoresProposiciones [i] = valorProposicion;
		} else if(proposiciones[i] == Mayuscula(nombreProposicion)) {
			valoresProposiciones [i] = !valorProposicion;
		}
	}
}

char Mayuscula(char caracter) {
	return caracter - 32;
}

bool obtenerValorCompuesto(bool valoresProposiciones[],int primerConector,int segundoConector) {
	bool primeraParte;
	switch(primerConector) {
		case 1: {
			primeraParte = valoresProposiciones[0] && valoresProposiciones[1];
			break;
		}
		case 2: {
			primeraParte = valoresProposiciones[0] || valoresProposiciones[1];
			break;
		}
		case 3: {
			primeraParte = !valoresProposiciones[0] || valoresProposiciones[1];
			break;
		}
	}
	switch(segundoConector) {
		case 1: {
			return primeraParte && valoresProposiciones[2];
		}
		case 2: {
			return primeraParte || valoresProposiciones[2];
		}
		case 3: {
			return !primeraParte || valoresProposiciones[2];
		}
	}
	
}


