/*
Artur Henrique Pagno - 21013037
Carlos Eduardo Fontes Camacho - 21008649
Cesar Augusto Camote Inocencio - 20018446
Patrick Pimentel Correa Leite - 21007850
Felipe de Moura Tayar - 21019634
Joao Victor Moreira Vidal - 19291384
*/



#include <iostream>
#include <locale.h>
#include <string>
#include <string.h>

using namespace std;




void instrucoes()
{

    cout << R"( _____  ___________  ___   ______ _____   _      _____ ___________  ___   _____ _ 
/  ___||  _  | ___ \/ _ \  |  _  \  ___| | |    |  ___|_   _| ___ \/ _ \ /  ___| |
\ `--. | | | | |_/ / /_\ \ | | | | |__   | |    | |__   | | | |_/ / /_\ \\ `--.| |
 `--. \| | | |  __/|  _  | | | | |  __|  | |    |  __|  | | |    /|  _  | `--. \ |
/\__/ /\ \_/ / |   | | | | | |/ /| |___  | |____| |___  | | | |\ \| | | |/\__/ /_|
\____/  \___/\_|   \_| |_/ |___/ \____/  \_____/\____/  \_/ \_| \_\_| |_/\____/(_))";

    cout << "\n\n\n================================================" << endl;
    cout << "==================== REGRAS ====================" << endl;
    cout << "================================================" << endl;
    cout << "\n 1) Crie palavras com as letras do quadro" << endl;
    cout << " 2) Total de 30 palavras com menos de 16 letras" << endl;
    cout << " 3) Apos 5 erros o jogo e encerrado" << endl;





}


void Quadro()
{
    int i = 0;
    cout << "\n\n================================================" << endl;
    cout << "============== QUADRO DE LETRAS ================" << endl;
    cout << "================================================" << endl;
    cout << "\n                  A G U A M R\n                  G O T C C J\n                  O L E I E S\n                  S U Q N A U\n";



}

void Banco()
{
    cout << "\n\n================================================" << endl;
    cout << "============== BANCO DE PALAVRAS ===============" << endl;
    cout << "================================================" << endl;

    cout << "AGUA    AMARGO   ARCO    ARO     ATA      CARO\n";
    cout << "CIRCO   COR      JOGO    LEITE   LETRA    LEVA\n";
    cout << "LUA     MACA     MALA    MESA    META     MIRA\n";
    cout << "MISSA   OVO      RUA     QUEIJO  QUIMONO  SINETA\n";
    cout << "SINO    SOLETRA  SONECA  SUINO   SUMO     TACO\n";

}



int main()
{
    char alternativa[20];

    int i, j;
    int corretas = 0;
    int achou = 0;
    char selecao;
    int erros = 0;
    int teveErro = 0;
    instrucoes();



    char carec[22] = { 'A', 'G', 'U', 'A', 'M', 'R',
        'G', 'O', 'T', 'C', 'C', 'J', 'O', 'L', 'E', 'I', 'E',
        'S', 'S', 'U', 'Q', 'N', };
    char letras[30][23] = { "AGUA", "AMARGO", "ARCO", "ARO",
        "ATA", "CARO", "CIRCO", "COR", "JOGO", "LEITE", "LETRA",
        "LEVA", "LUA", "MACA", "MALA", "MESA", "META", "MIRA", "MISSA", "OVO", "RUA",
        "QUEIJO", "QUIMONO", "SINETA", "SINO", "SOLETRA", "SONECA", "SUINO", "SUMO",
        "TACO" };
    char acertos[30][23];
    do {
        Quadro();
        for (i = 0; i < corretas; i++) {

            cout << "\nPalavras Corretas: " << acertos[i];


        }


        cout << " \n \nDigite uma palavra: ";
        cin >> alternativa;
        _strupr_s(alternativa);
        fflush(stdin);


        for (i = 0; i < 30; i++) {
            if (strcmp(letras[i], alternativa) == 0) {
                teveErro = 1;
                for (j = 0; j < 30; j++) {

                    if (strcmp(acertos[j], alternativa) == 0) {
                        achou = 1; break;


                    }
                }

                if (achou == 0) {
                    corretas++;
                    acertos[corretas - 1];
                    strcpy_s(acertos[corretas - 1], alternativa);

                }
            }



        }
        if (teveErro == 0) {
            erros++;

        }

        teveErro = 0;

        if (erros >= 5) {
            cout << "Você Teve Mais de 5 Erros!!!" << endl; break;
        }

        if (strcmp(alternativa, "ENTER") == 0)break;



    } while (corretas < 30);



    if (corretas == 30) {
        cout << "\n Parabens :D Voce Acertou as 30 Palavras.";
    }


    cout << "\n\nDeseja visualizar o Banco de Palavras? (s/n)";
    cin >> selecao;
    if (selecao == 's' || selecao == 'S') {
        Banco();
    }
}