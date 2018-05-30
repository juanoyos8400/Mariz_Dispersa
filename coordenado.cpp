//#include <Coordenado.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
/*#include <iostream>
#ifndef __Coordenado_H
#define __Coordenado_H
#include <vector>
using namespace std;
*/
/*FORMATO Coordenado*/
class Coordenado{
	private:
		vector<int> valores;
		vector<int> columnas;
		vector<int> filas;
		int numfilas;
		int numcolumnas;

	public:

		Coordenado crearDispersa(vector<vector<int> > matriz, int filas, int columnas);
		vector<vector<int> > crearCompleta(Coordenado matriz_dispersa);
		int obtenerElem(Coordenado matriz_dispersa, int i, int j);
		vector<int> obtenerFila(Coordenado matriz_dispersa , int filai);
		vector<int> obtenerColumna( Coordenado matriz_dispersa, int columnaj);
		vector<int> obtenerFilaDispersaVector(Coordenado matriz_dispersa, int filai);
		vector<int> obtenerColumnaDispersaVector( Coordenado matriz_dispersa, int columnaj); 
		int obtenerNumElementos(Coordenado matriz_dispersa);
		Coordenado modificarPos(Coordenado matriz_dispersa, int element, int i, int j);
		Coordenado suma(vector<vector<int> >matriz ,vector<vector<int> > matrizb);
		vector<int> producto(vector<vector<int> >matriz , vector<int> b);
		Coordenado transpuesta(vector<vector<int> >matriz );

			
};
Coordenado Coordenado::crearDispersa(vector<vector<int> > matriz, int filas, int columnas){
	Coordenado matriz_dispersa;
	matriz_dispersa.numcolumnas = columnas;
	matriz_dispersa.numfilas = filas;
	for (int i = 0; i < filas; i++){
		for (int j = 0; j < columnas; j++){
			if (matriz[i][j] != 0){
				matriz_dispersa.valores.push_back(matriz[i][j]);
				matriz_dispersa.filas.push_back(i);
				matriz_dispersa.columnas.push_back(j);	
			}
		}
	}
	return matriz_dispersa;
}
vector<vector<int> > Coordenado::crearCompleta(Coordenado matriz_dispersa){
	int h = 0;
	vector<vector<int> >matriz(matriz_dispersa.numfilas);
	for (int i = 0; i < matriz_dispersa.numfilas; i++){
			matriz[i].resize(matriz_dispersa.numcolumnas);
	}
	for (int i = 0; i < matriz_dispersa.numfilas; i++){
		for (int j = 0; j < matriz_dispersa.numcolumnas; ++j){
			if (matriz_dispersa.filas[h] == i && matriz_dispersa.columnas[h] == j){
				matriz[i][j] = matriz_dispersa.valores[h];
				h++;
			}
		}	
	}
	return matriz;
}
int Coordenado::obtenerElem(Coordenado matriz_dispersa, int fila, int colu){
	for (int i = 0; i < matriz_dispersa.valores.size(); ++i){
		if((matriz_dispersa.filas[i] == fila) && (matriz_dispersa.columnas[i] == colu))
			return matriz_dispersa.valores[i];	
	}
	return 0;
}
vector<int> Coordenado::obtenerFila(Coordenado matriz_dispersa , int filai){
	std::vector<int> row;
	for (int i = 0; i < matriz_dispersa.filas.size() ; ++i){
		if(matriz_dispersa.filas[i] == filai)
			row.push_back(matriz_dispersa.valores[i]);
		
	}
	return row;
}
vector<int> Coordenado::obtenerColumna(Coordenado matriz_dispersa, int columnaj){
	std::vector<int> column;
	for (int i = 0; i < matriz_dispersa.columnas.size(); ++i){
		if(matriz_dispersa.columnas[i] == columnaj )
			column.push_back(matriz_dispersa.valores[i]);
	}
	return column;

}
vector<int> Coordenado::obtenerFilaDispersaVector(Coordenado matriz_dispersa, int filai){
	std::vector<int> rowDispersa;
	std::vector<std::vector<int> > matriz_completa = crearCompleta(matriz_dispersa);
	for (int i = 0; i <matriz_dispersa.numfilas ; ++i){
		for (int j = 0; j < matriz_dispersa.numcolumnas; ++j){
			if( i == filai){
				rowDispersa.push_back(matriz_completa[i][j]);
			}
		}
	}
	return rowDispersa;
}
vector<int> Coordenado::obtenerColumnaDispersaVector(Coordenado matriz_dispersa, int columnaj){
	std::vector<int> colDispersa;
	std::vector<std::vector<int> > matriz_completa = crearCompleta(matriz_dispersa);
	for (int i = 0; i <matriz_dispersa.numfilas ; ++i){
		for (int j = 0; j < matriz_dispersa.numcolumnas; ++j){
			if( j == columnaj){
				colDispersa.push_back(matriz_completa[i][j]);
			}
		}
	}
	return colDispersa;
}
int Coordenado::obtenerNumElementos(Coordenado matriz_dispersa){
	//numero de elementos incluyendo el cero//
	//int numElementos = matriz_dispersa.numfilas*matriz_dispersa.numcolumnas;

	//numero de elementos diferentes de cero//
	int numElementos = matriz_dispersa.valores.size();


}
Coordenado Coordenado::modificarPos(Coordenado matriz_dispersa , int element, int filai, int columnaj){

	vector<vector<int> > matriztmp = crearCompleta(matriz_dispersa);
	for (int i = 0; i < matriz_dispersa.numfilas; ++i){
		for (int j = 0; j < matriz_dispersa.numcolumnas; ++j){
			if(i == filai && j == columnaj)
				matriztmp[i][j] = element;
		}
	}
	for (int i = 0; i < matriz_dispersa.numfilas; i++){
		cout<<endl;
		for (int j = 0; j < matriz_dispersa.numcolumnas; j++){
			cout<<"|"<<matriztmp[i][j]<<"|";
		}
	}
	cout<<endl;

	Coordenado nuevaMatriz_dispersa = crearDispersa(matriztmp,matriz_dispersa.numfilas,matriz_dispersa.numcolumnas);
	return nuevaMatriz_dispersa;

}
Coordenado Coordenado::suma (Coordenado matriz_dispersa1, Coordenado matriz_dispersa2){






}
int main(){
	vector<vector<int> >matriz = {{1, 2 ,2 ,3 },	
								  {0, 1, 2, 3}};
	Coordenado coordenada;
	//Coordenado matriz_dispersa;
	coordenada = coordenada.crearDispersa(matriz,2,4);
	//******************************************//	

	std::vector<std::vector<int> >matriz_completa = coordenada.crearCompleta(coordenada);
	cout<<"MATRIZ COMPLETA"<<endl;
	for (int i = 0; i < 2; i++){
		cout<<endl;
		for (int j = 0; j < 4; j++){
			cout<<"|"<<matriz_completa[i][j]<<"|";
		}
	}
	cout<<endl;

// *********************************************************//
	cout<<"OBTENER ELEMNETO"<<endl;

	int element = coordenada.obtenerElem(coordenada,1,2);
	cout<<"elemento es "<<element<<endl;

//****************************************************//
	cout<<"OBTENER FILA"<<endl;

	std::vector<int> rows = coordenada.obtenerFila(coordenada,1);
	for (int i = 0; i < rows.size(); ++i){
		cout<<"|"<<rows[i]<<"|";
	}
	cout<<endl;
//******************************************************///

	cout<<"OBTENER COLUMNA"<<endl;

	std::vector<int> column = coordenada.obtenerColumna(coordenada,0);
	for (int i = 0; i < column.size(); ++i){
		cout<<"|"<<column[i]<<"|";
	}
	cout<<endl;
	//******************************************************///

	cout<<"OBTENER FILA DISPERSA"<<endl;

	std::vector<int> rowDispersa = coordenada.obtenerFilaDispersaVector(coordenada,1);
	for (int i = 0; i < rowDispersa.size(); ++i){
		cout<<"|"<<rowDispersa[i]<<"|";
	}
	cout<<endl;
	//******************************************************///

	cout<<"OBTENER COLUMNA DISPERSA"<<endl;

	std::vector<int> colDispersa = coordenada.obtenerColumnaDispersaVector(coordenada,1);
	for (int i = 0; i < colDispersa.size(); ++i){
		cout<<"|"<<colDispersa[i]<<"|";
	}
	cout<<endl;
	//******************************************************///
	cout<<"NUMERO DE ELEMTOS"<<endl;
	int numElementos = coordenada.obtenerNumElementos(coordenada);
	cout<<numElementos<<endl;
	//******************************************************///
	cout<<"MODIFICAR POSICION"<<endl;
	int elemento = 0, fila = 1, columna = 2; 
	cout<<"ELEMNETO = "<<elemento<<" FILA = "<< fila<<" COLUMNA = "<<columna<<endl;
	coordenada = coordenada.modificarPos(coordenada,0,1,2);
	
	//******************************************************///


	return 0;
}
