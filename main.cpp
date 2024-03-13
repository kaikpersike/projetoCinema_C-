#include <iostream>
#include <iomanip>
#include <string>
#include <typeinfo>
using namespace std;

#define LIN 16
#define COL 41

void matriz(bool **ptr, int op){
    int opcao;
    int poltrona, fileira;
    
    //cout << endl << ptr << endl << op << endl;
    
    if(op == 1)
    {
        cout << endl << "Escolha fileira (LINHA) e poltrona (COLUNA): " << endl;
        cin >> poltrona >> fileira;
        
        for(int i=1; i<LIN; ++i)
	    {
		    for(int j=1; j<COL; ++j)
		    {
		        if(i == poltrona && j == fileira)
		        {
		            if(ptr[i][j] == 0)
		            {
    		            cout << endl << "Sua poltrona foi reservada!" << endl;
    		            ptr[i][j] = 1;
		            }
		            else
		            {
		                cout << endl << "Lugar ocupado!" << endl;
		            }
		        }
			
		    }

	    }
        
        cout << endl << "Selecione uma opção: " << endl << "0. Finalizar" << endl << "1. Reservar poltrona" << endl << "2. Mapa de ocupacao" << endl << "3. Faturamento" << endl;
        cin >> opcao;
        
        matriz(ptr, opcao);
        
    }
    else if(op == 2)
    {
        for(int i=1; i<LIN; ++i)
	    {
		    for(int j=1; j<COL; ++j)
		    {
		        if(ptr[i][j] == 1)
		        {
		           cout << setw(2) << "#";
		        }
		        else
		        {
		           cout << setw(2) << ".";
		        }
			    
		    }
		    cout << endl;
	    }
	    cout << endl << "Selecione uma opção: " << endl << "0. Finalizar" << endl << "1. Reservar poltrona" << endl << "2. Mapa de ocupacao" << endl << "3. Faturamento" << endl;
        cin >> opcao;

        matriz(ptr, opcao);
    }
    else if(op == 3)
    {
        int cont;
        int bil = 0;
        cont = 0;
        
        for(int i=1; i<LIN; ++i)
	    {
		    for(int j=1; j<COL; ++j)
		    {
			    if(ptr[i][j] == 1 && (i <=5))
			    {
			        bil += 50;
			        cont++;
			    }
			    else if(ptr[i][j] == 1 && (6 <= i <=10))
			    {
			        bil +=30;
			        cont++;
			    }
			    else if(ptr[i][j] == 1 && (11 <= i <=15))
			    {
			        bil +=15;
			        cont++;
			    }
		    }
	    }
	    cout << endl << "Quantidade de lugares ocupados: " << cont << endl;
	    cout << endl << "Valor de bilheteria: " << bil << endl;
	    
	    cout << endl << "Selecione uma opção: " << endl << "0. Finalizar" << endl << "1. Reservar poltrona" << endl << "2. Mapa de ocupacao" << endl << "3. Faturamento" << endl;
        //op1(ptr, cord);
        cin >> opcao;
        
        matriz(ptr, opcao);
    }
    else
    {
        delete[] ptr;
    }
    
}

int main(int argc, char** argv)
{
    // variaveis
    int opcao;
    
    bool **mat;
	
	mat = new bool*[LIN];
	
	// carregando array
	for(int i=1; i<LIN; ++i)
	{
		mat[i] = new bool[COL];
	}
	
	
	for(int i=1; i<LIN; ++i)
	{
		for(int j=1; j<COL; ++j)
		{
			mat[i][j] = 0; 
		}
	}
	
	// fim carregamento
    
    cout << endl << "Selecione uma opção: " << endl << "0. Finalizar" << endl << "1. Reservar poltrona" << endl << "2. Mapa de ocupacao" << endl << "3. Faturamento" << endl;
    
    cin >> opcao;
    
    switch(opcao)
    {
        case 1:
            matriz(mat, opcao);
            break;
        case 2:
            matriz(mat, opcao);
            break;
        case 3:
            matriz(mat, opcao);
            break;;
        default:
            delete[] mat;
    }
    
    return 0;
}





