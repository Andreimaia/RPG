#ifndef HEADER
#define HEADER

using namespace std;

//STRUCTS
struct Posicao{
    int l;
    int c;
};

struct Tp{
    Posicao posicao;
    string tp;
};

struct Botao{
    Posicao posicao;
    string botao;
};

struct PortaFechada{
    Posicao posicao;
    string porta;
};

struct PortaFinal{
    Posicao posicao;
    string portaFinal;
};

struct Jogador{
    Posicao posicao;
    int vidas;
    string jogador;
};

struct Chave{
    Posicao posicao;
    string chave;
};
//####################



//DEFININDO AS FUN??ES
void MenuPrincipal();
void Fase1();
void Fase2();
void Fase3();
void Tutorial();
//#####################



void MenuPrincipal()
{
    char escolha; //Variavel que armazena os valores que o usu?rio digita para selecionar op??es

    system("clear || cls"); //Apaga o que estava printado na tela

    do
    {
        cout << "       MENU PRINCIPAL" << endl;
        cout << "_____________________________" << endl;
        cout << endl;
        cout << "          1- Jogar" << endl;
        cout << "          2- Sair" << endl;
        cout << "_____________________________" << endl;
        cout << "Escolha: ";
        cin >> escolha;
        system("clear || cls");
    } while (escolha != '1' && escolha != '2'); //Enquanto a escolha for diferente de 1 e 2, ele continuar? nessa tela

    if(escolha == '1') //Se a escolha for 1, o jogador inicia o jogo
    {
        do
        {
            cout << "_____________________________" << endl;
            cout << endl;
            cout << "      1- Jogar tutorial" << endl;
            cout << "      2- Pular tutorial" << endl;
            cout << "      3- Voltar para menu" << endl;
            cout << "_____________________________" << endl;
            cout << "Escolha: ";
            cin >> escolha;
            system("clear || cls");
        }while(escolha != '1' && escolha != '2' && escolha != '3'); //Enquanto a escolha for diferente de 1 e 2, ele continuar? nessa tela

        if(escolha == '1') //Se a escolha for 1, o jogador joga o tutorial
        {
            Tutorial();
        }

        else if(escolha == '2') //Se a escolha for 2, o jogador vai direto para a fase 1, pulando o tutorial
        {
            Fase1();
        }

        else if(escolha == '3') //Se a escolha for 3, o jogador volta para o menu
        {
            MenuPrincipal();
        }
    }
    else if(escolha == '2') //Se a escolha for 2, o jogo se fecha
    {
        cout << "_____________________________" << endl;
        cout << endl;
        cout << "          Voce saiu" << endl;
        cout << "_____________________________" << endl;
        exit(0);
    }
}

void Tutorial()
{
    //Definindo as structs
    PortaFechada portaF;
    PortaFinal portaFinal;
    Jogador jogador;
    Chave chave;
    Botao botao;
    Tp tp;
    Tp tp2;

    //Gera??o da matriz
    const int tamanhoMapa = 25;
    string mapa[tamanhoMapa][tamanhoMapa];

    //Icone do espinho
    string espinho = "#";

    //Posi??o e icone dos teleportes
    tp.posicao.l = 5;
    tp.posicao.c = 19;
    tp2.posicao.l = 19;
    tp2.posicao.c = 5;
    tp.tp = ">";
    tp2.tp = ">";

    //Posi??o e icone do bot?o
    botao.posicao.l = 2;
    botao.posicao.c = 19;
    botao.botao = "O";

    //Posi??o e icone da porta
    portaF.posicao.l = 5;
    portaF.posicao.c = 14;
    portaF.porta = "D";

    //Posi??o e icone da porta final
    portaFinal.posicao.l = 19;
    portaFinal.posicao.c = 7;
    portaFinal.portaFinal = "X";

    //Posi??o e icone da chave
    chave.posicao.l = 5;
    chave.posicao.c = 6;
    chave.chave = "@";
    
    //Posi??o e icone do jogador
    jogador.jogador = "&";
    jogador.posicao.l = 11;
    jogador.posicao.c = 12;
    int posOriginalL = 11; //Guarda a posi??o inicial X do jogador. ? usada para redefinir a sua posi??o quando morre
    int posOriginalC = 12; //Guarda a posi??o inicial Y do jogador. ? usada para redefinir a sua posi??o quando morre
    
    char interagir; //Variavel respons?vel por armazenar as intera??es do jogador com o mapa (Movimenta??o e utiliza??o dos objetos)

    char temp[4]; //Variavel usada somente no tutorial para comparar as teclas que o jogador usa
    
    //Variaveis que s?o usadas para armazenar se algo foi usado. Sempre iniciam falso
    bool comChave = false;
    bool portaAberta = false;
    bool botaoAtivo = false;
    bool tpAtivo = false;
    bool complete = false; //Somente usada no tutorial

    int loop = 54; //Variavel que mantem a fase em um loop at? que o jogador chegue ao final

    int cont = 0; //Variavel somente usada no tutorial. Um contador que tomar? conta das intera??es do usuario

    char escolha; //Variavel que armazena os valores que o usu?rio digita para selecionar op??es

    while(loop == 54)
    {
        //Gera??o da matriz (Paredes exteriores)
        for(int i = 0; i < tamanhoMapa; i++)
        {
           for(int j = 0; j < tamanhoMapa; j++)
           {
               if(i == 0 || i == tamanhoMapa-1 || j == 0 || j == tamanhoMapa-1)
               {
                   mapa[i][j] = "*";
               }
               else
               {
                   mapa[i][j] = " ";
               }
           }
        }

        //Define a localiza??o dos objetos no mapa
        if(cont >= 4) //Somente vai aparecer na tela ap?s a primeira parte do tutorial ser completada
        {
            mapa[chave.posicao.l][chave.posicao.c] = chave.chave;
            
            if(comChave == false) //Se o jogador obter a chave ela desaparece do ch?o
            {
                mapa[chave.posicao.l][chave.posicao.c] = chave.chave;
            }
            else
            {
                mapa[chave.posicao.l][chave.posicao.c] = " ";
            }
            
            //Sala superior direito
            mapa[tp.posicao.l][tp.posicao.c] = tp.tp;
            mapa[botao.posicao.l][botao.posicao.c] = botao.botao;
            if(botaoAtivo == true) //Se o bot?o estiver ativo, ele liga o teleporte
            {
                tpAtivo = true;
            }
            for(int i = 24; i >= 14; i--)
            {
                mapa[9][i] = "*";
            }
            for(int i = 1; i <= 9; i++)
            {
                mapa[i][14] = "*";
            }
            for(int i = 15; i <= 20; i++)
            {
                mapa[6][i] = espinho;
            }
            for(int i = 6; i >= 1; i--)
            {
                mapa[i][20] = espinho;
            }
            for(int i = 15; i <= 18; i++)
            {
                mapa[4][i] = espinho;
            }
            for(int i = 4; i >= 1; i--)
            {
                mapa[i][18] = espinho;
            }
            
            if(portaAberta == false)
            {
                mapa[portaF.posicao.l][portaF.posicao.c] = portaF.porta; //Se a porta estiver trancada ela se mantem com o icone D (Porta fechada)
            }
            else
            {
                mapa[portaF.posicao.l][portaF.posicao.c] = "="; //Se a porta for aberta, o seu icone muda para = (Porta aberta)
            }
            
            //Sala inferior esquerdo
            for(int i = 1; i <= 10; i++)
            {
                mapa[15][i] = "*";
            }
            for(int i = 15; i <= 24; i++)
            {
                mapa[i][10] = "*";
            }
            mapa[tp2.posicao.l][tp2.posicao.c] = tp2.tp;
            mapa[portaFinal.posicao.l][portaFinal.posicao.c] = portaFinal.portaFinal;
        }

        mapa[jogador.posicao.l][jogador.posicao.c] = jogador.jogador; //Define a localiza??o e o icone do jogador

        //Printa a matriz e os objetos do mapa na tela
        for(int i = 0; i < tamanhoMapa; i++)
        {
            for(int j = 0; j < tamanhoMapa; j++)
            {
                cout << mapa[i][j] << " ";
            }
            cout << endl;
        }

        if(cont < 4) //Somente usado no tutoral. Texto fica na tela at? o jogador apertar todas as teclas de movimenta??o pelo menos uma vez
        {
            cout << "Voce eh &" << endl;
            cout << "Pressione WASD para se mover: ";
        }
        if(portaAberta == false && cont >= 4) //Somente usado no tutoral. Texto aparece ap?s o jogador usar as teclas de movimenta??o e antes de abrir a porta
        {
            cout << "Aperte I para interagir com objetos" << endl;
            cout << "@ eh uma chave, use-a para abrir a porta trancada D" << endl;
            cout << "Interagir (WASDI): ";
        }
        if(portaAberta == true && tpAtivo == false && cont >= 4) //Somente usado no tutoral. Texto aparece ap?s abrir a porta e antes de ativar o teleporte
        {
            cout << "Na sua frente esta um teleporte >, use o botao O para liga-lo" << endl;
            cout << "Os botoes tambem podem ser usados para abrir portoes" << endl;
            cout << "Tenha cuidado com os espinhos X" << endl;
            cout << "Interagir (WASDI): ";
        }
        if(tpAtivo == true && cont >= 4) //Somente usado no tutoral. Texto aparece ap?s o teleporte ser ativo
        {
            cout << "Dica: As vezes, interagir com objetos como portas e portoes, mesmo sem ter a chave, pode ativar eventos importantes" << endl;
            cout << "O teleporte > esta ativo, tente usa-lo. Interaja com a porta X para completar o tutorial" << endl;
            cout << "Interagir (WASDI): ";
        }
        cin >> interagir; //Armazena os inputs do jogador na variavel interagir

        interagir = toupper(interagir); //Transforma todos os inputs do jogador para maiusculo
        
        //SISTEMA DE MOVIMENTA??O
        if(interagir == 'W') 
        {
            if(mapa[jogador.posicao.l-1][jogador.posicao.c] == "*" || mapa[jogador.posicao.l-1][jogador.posicao.c] == portaF.porta) //Se o jogador apertar W, mas estiver sendo bloqueado por uma parede ou porta, ele n?o se move
            {
                jogador.posicao.l;
            }
            else //Caso o jogador n?o seja bloqueado, ele se movimenta para frente
            {
                jogador.posicao.l--;
            }
        }
        else if(interagir == 'A')
        {
            if(mapa[jogador.posicao.l][jogador.posicao.c-1] == "*" || mapa[jogador.posicao.l][jogador.posicao.c-1] == portaF.porta) //Se o jogador apertar A, mas estiver sendo bloqueado por uma parede ou porta, ele n?o se move
            {
                jogador.posicao.c;
            }
            else //Caso o jogador n?o seja bloqueado, ele se movimenta para o lado esquerdo
            {
                jogador.posicao.c--;
            }
        }
        else if(interagir == 'S')
        {
            if(mapa[jogador.posicao.l+1][jogador.posicao.c] == "*" || mapa[jogador.posicao.l+1][jogador.posicao.c] == portaF.porta) //Se o jogador apertar W, mas estiver sendo bloqueado por uma parede ou porta, ele n?o se move
            {
                jogador.posicao.l;
            }
            else //Caso o jogador n?o seja bloqueado, ele se movimenta para tras
            {
                jogador.posicao.l++;
            }
        }
        else if(interagir == 'D')
        {
            if(mapa[jogador.posicao.l][jogador.posicao.c+1] == "*" || mapa[jogador.posicao.l][jogador.posicao.c+1] == portaF.porta) //Se o jogador apertar W, mas estiver sendo bloqueado por uma parede ou porta, ele n?o se move
            {
                jogador.posicao.c;
            }
            else //Caso o jogador n?o seja bloqueado, ele se movimenta para o lado direito
            {
                jogador.posicao.c++;
            }
        }

        //SISTEMA DE INTERA??O COM OS OBJETOS
        if(interagir == 'I')
        {
            if(mapa[jogador.posicao.l][jogador.posicao.c] == mapa[chave.posicao.l][chave.posicao.c]) //Funcionamento da chave
            {
                comChave = true; //Se o jogador interagir com a chave, ficando em cima dela e apertando I, o jogador coleta a chave
            }

            if(mapa[jogador.posicao.l][jogador.posicao.c] == mapa[portaF.posicao.l][portaF.posicao.c-1] && comChave == true) //Funcionamento da porta
            {
                portaAberta = true; //Se o jogador interagir com a porta, ela se abre. Jogador deve ficar a um espa?o da porta
            }
            
            if(mapa[jogador.posicao.l][jogador.posicao.c] == mapa[botao.posicao.l][botao.posicao.c]) //Funcionamento do bot?o
            {
                botaoAtivo = true; //Se o jogador interagir com o bot?o, ficando em cima dele e apertando I, ele se ativa
            }

            if(mapa[jogador.posicao.l][jogador.posicao.c] == mapa[tp.posicao.l][tp.posicao.c] && tpAtivo == true) //Funcionamento do TP
            {
                //Teleporta o jogador para a posi??o do TP2
                jogador.posicao.l = tp2.posicao.l;
                jogador.posicao.c = tp2.posicao.c;
            }
            else
            {
                if(mapa[jogador.posicao.l][jogador.posicao.c] == mapa[tp2.posicao.l][tp2.posicao.c] && tpAtivo == true) //Funcionamento do TP
                {
                    //Teleporta o jogador para a posi??o do TP1
                    jogador.posicao.l = tp.posicao.l;
                    jogador.posicao.c = tp.posicao.c;
                }
            }

            if(mapa[jogador.posicao.l][jogador.posicao.c] == mapa[portaFinal.posicao.l][portaFinal.posicao.c]) //Jogador acaba o tutorial passando pela porta final
            {
                do //Loop somente usado no tutorial
                {
                    system("clear || cls");
                    cout << "_____________________________" << endl;
                    cout << endl;
                    cout << "  1- Continuar para fase 1" << endl;
                    cout << "     2- Ir para o menu" << endl;
                    cout << "_____________________________" << endl;
                    cout << "Escolha: ";
                    cin >> escolha;
                }while(escolha != '1' && escolha != '2');

                if(escolha == '1') //Continua o jogo e vai para fase 1
                {
                    Fase1();
                }
                else if(escolha == '2') //Volta para o menu
                {
                    MenuPrincipal();
                }
            }
        }

        complete = false; //Somente usado no tutoral. Complete sempre deve iniciar falso antes de entrar no loop

        temp[cont] = interagir; //Somente usado no tutoral. Atribui o valor de interagir para a variavel temp. Foi usado um vetor para fazer com que a variavel conseguisse armazenar todas as teclas de movimento (WASD)

        if(cont < 4)
        {
            //Somente usado no tutoral. For?a o jogador a usar as teclas de movimenta??o no inicio do tutorial
            if(temp[cont] == 'W' || temp[cont] == 'A' || temp[cont] == 'S' || temp[cont] == 'D')
            {
                if(cont >= 1)
                {
                    for(int i = 1; i <= cont; i++)
                    {
                        if(temp[cont] != temp[cont - i]) //Somente usado no tutoral. Se as teclas usadas forem diferentes, complete se torna verdadeiro
                        {
                            complete = true;
                        }
                        else //Somente usado no tutoral. Se alguma tecla for repetida o loop se quebra
                        {
                            break;
                        }
                    }
                }
                else //Somente usado no tutoral. O contador vai sempre aumentar independente da tecla que o jogador usar. S? funciona para a primeira tecla
                {
                    cont++;
                }
            }
        }
        
        if(complete == true) //Somente usado no tutoral. Se complete for verdadeiro, o contador aumenta 1
        {
        	cont++;
		}

        if(mapa[jogador.posicao.l][jogador.posicao.c] == espinho) //Se o jogador cair em um espinho, ele morre e reseta a fase (Jogador possui vidas infinitas no tutorial)
        {
            comChave = false;
            portaAberta = false;
            botaoAtivo = false;
            //Jogador volta para a sua posi??o original
            jogador.posicao.l = posOriginalL;
            jogador.posicao.c = posOriginalC;
        }
        system("clear || cls");
    }
}

void Fase1()
{
    //Definindo as structs
    PortaFechada portaF;
    PortaFinal portaFinal;
    Jogador jogador;
    Chave chave;

    //Gera??o da matriz
    const int tamanhoMapa = 25;
    string mapa[tamanhoMapa][tamanhoMapa];

    //Posi??o e icone da porta
    portaF.posicao.l = 6;
    portaF.posicao.c = 12;
    portaF.porta = "D";

    //Icone port?o
    string portao = "H";

    //Posi??o e icone da porta final
    portaFinal.posicao.l = 3;
    portaFinal.posicao.c = 12;
    portaFinal.portaFinal = "X";

    //Posi??o e icone da chave
    chave.posicao.l = 21;
    chave.posicao.c = 1;
    chave.chave = "@";
    
    //Posi??o e icone do jogador
    jogador.jogador = "&";
    jogador.posicao.l = 1;
    jogador.posicao.c = 1;

    //Variaveis que s?o usadas para armazenar se algo foi usado. Sempre iniciam falso
    bool comChave = false;
    bool portaAberta = false;
    
    char interagir; //Variavel respons?vel por armazenar as intera??es do jogador com o mapa (Movimenta??o e utiliza??o dos objetos)

    int loop = 54; //Variavel que mantem a fase em um loop at? que o jogador chegue ao final

    char lixo; //N?o armazena nenhum valor de interesse, somente usada para pausar o jogo

    system("clear || cls");

    while(loop == 54)
    {
        //Gera??o da matriz (Paredes exteriores)
        for(int i = 0; i < tamanhoMapa; i++)
        {
           for(int j = 0; j < tamanhoMapa; j++)
           {
               if(i == 0 || i == tamanhoMapa-1 || j == 0 || j == tamanhoMapa-1)
               {
                   mapa[i][j] = "*";
               }
               else
               {
                   mapa[i][j] = " ";
               }
           }
        }

        //Define a localiza??o dos objetos no mapa
        //Sala final
        for(int i = 1; i <= 6; i++)
        {
            mapa[i][8] = "*";
        }
        for(int i = 1; i <= 6; i++)
        {
            mapa[i][16] = "*";
        }
        for(int i = 8; i <= 16; i++)
        {
            mapa[6][i] = "*";
        }
        mapa[portaF.posicao.l][portaF.posicao.c] = portaF.porta;
        //Labirinto
        for(int i = 1; i <= 5; i++)
        {
            mapa[3][i] = "*";
        }
        for(int i = 3; i <= 11; i++)
        {
            mapa[i][5] = "*";
        }
        for(int i = 5; i <= 8; i++)
        {
            mapa[11][i] = "*";
        }
        for(int i = 11; i <= 21; i++)
        {
            mapa[i][8] = "*";
        }
        for(int i = 1; i <= 5; i++)
        {
            mapa[18][i] = "*";
        }
        for(int i = 18; i <= 21; i++)
        {
            mapa[i][5] = "*";
        }
        for(int i = 5; i <= 8; i++)
        {
            mapa[21][i] = "*";
        }
        for(int i = 11; i <= 21; i++)
        {
            mapa[i][12] = "*";
        }
        for(int i = 12; i <= 20; i++)
        {
            mapa[21][i] = "*";
        }
        for(int i = 21; i >= 18; i--)
        {
            mapa[i][20] = "*";
        }
        for(int i = 16; i <= 20; i++)
        {
            mapa[18][i] = "*";
        }
        for(int i = 18; i >= 11; i--)
        {
            mapa[i][16] = "*";
        }
        for(int i = 16; i >= 12; i--)
        {
            mapa[11][i] = "*";
        }

        for(int i = 16; i <= 23; i++)
        {
            mapa[6][i] = "*";
        }
        if(comChave == false) //Se o jogador obter a chave, ela desaparece do ch?o
        {
            mapa[chave.posicao.l][chave.posicao.c] = chave.chave;
        }
        else
        {
            mapa[chave.posicao.l][chave.posicao.c] = " ";
            for(int i = 9; i <= 11; i++)
            {
                mapa[11][i] = "H"; //Quando a chave for coletada, o caminho ser? bloqueado por port?es
            }
        } 
        mapa[portaFinal.posicao.l][portaFinal.posicao.c] = portaFinal.portaFinal;

        if(portaAberta == false)
        {
            mapa[portaF.posicao.l][portaF.posicao.c] = portaF.porta; //Se a porta estiver trancada ela se mantem com o icone D (Porta fechada)
        }
        else
        {
            mapa[portaF.posicao.l][portaF.posicao.c] = "="; //Se a porta for aberta ela mude de icone para = (Porta aberta)
        }

        mapa[jogador.posicao.l][jogador.posicao.c] = jogador.jogador;

        cout << "Fase 1" << endl;

        for(int i = 0; i < tamanhoMapa; i++)
        {
            for(int j = 0; j < tamanhoMapa; j++)
            {
                cout << mapa[i][j] << " ";
            }
            cout << endl;
        }
        cout << "Interagir (WASDI): ";
        cin >> interagir; //Armazena os inputs do jogador na variavel interagir

        interagir = toupper(interagir); //Transforma todos os inputs do jogador para maiusculo

        //SISTEMA DE MOVIMENTA??O
        if(interagir == 'W') 
        {
            if(mapa[jogador.posicao.l-1][jogador.posicao.c] == "*" || mapa[jogador.posicao.l-1][jogador.posicao.c] == portaF.porta || mapa[jogador.posicao.l-1][jogador.posicao.c] == "H") //Se o jogador apertar W, mas estiver sendo bloqueado por uma parede ou porta, ele n?o se move
            {
                jogador.posicao.l;
            }
            else //Caso o jogador n?o seja bloqueado, ele se movimenta para frente
            {
                jogador.posicao.l--;
            }
        }
        else if(interagir == 'A')
        {
            if(mapa[jogador.posicao.l][jogador.posicao.c-1] == "*" || mapa[jogador.posicao.l][jogador.posicao.c-1] == portaF.porta || mapa[jogador.posicao.l][jogador.posicao.c-1] == "H") //Se o jogador apertar A, mas estiver sendo bloqueado por uma parede ou porta, ele n?o se move
            {
                jogador.posicao.c;
            }
            else //Caso o jogador n?o seja bloqueado, ele se movimenta para o lado esquerdo
            {
                jogador.posicao.c--;
            }
        }
        else if(interagir == 'S')
        {
            if(mapa[jogador.posicao.l+1][jogador.posicao.c] == "*" || mapa[jogador.posicao.l+1][jogador.posicao.c] == portaF.porta || mapa[jogador.posicao.l+1][jogador.posicao.c] == "H") //Se o jogador apertar W, mas estiver sendo bloqueado por uma parede ou porta, ele n?o se move
            {
                jogador.posicao.l;
            }
            else //Caso o jogador n?o seja bloqueado, ele se movimenta para tras
            {
                jogador.posicao.l++;
            }
        }
        else if(interagir == 'D')
        {
            if(mapa[jogador.posicao.l][jogador.posicao.c+1] == "*" || mapa[jogador.posicao.l][jogador.posicao.c+1] == portaF.porta || mapa[jogador.posicao.l][jogador.posicao.c+1] == "H") //Se o jogador apertar W, mas estiver sendo bloqueado por uma parede ou porta, ele n?o se move
            {
                jogador.posicao.c;
            }
            else //Caso o jogador n?o seja bloqueado, ele se movimenta para o lado direito
            {
                jogador.posicao.c++;
            }
        }

        //SISTEMA DE INTERA??O COM OS OBJETOS
        if(interagir == 'I')
        {
            if(mapa[jogador.posicao.l][jogador.posicao.c] == mapa[chave.posicao.l][chave.posicao.c]) //Funcionamento da chave
            {
                comChave = true; //Se o jogador interagir com a chave, ficando em cima dela e apertando I, o jogador coleta a chave
            }

            if(mapa[jogador.posicao.l][jogador.posicao.c] == mapa[portaF.posicao.l][portaF.posicao.c-1] || mapa[jogador.posicao.l][jogador.posicao.c] == mapa[portaF.posicao.l][portaF.posicao.c+1] || mapa[jogador.posicao.l][jogador.posicao.c] == mapa[portaF.posicao.l-1][portaF.posicao.c] || mapa[jogador.posicao.l][jogador.posicao.c] == mapa[portaF.posicao.l+1][portaF.posicao.c] && comChave == true) //Funcionamento da porta
            {
                portaAberta = true; //Se o jogador interagir com a porta, ela se abre. Jogador deve ficar a um espa?o da porta
            }
            if(mapa[jogador.posicao.l][jogador.posicao.c] == mapa[portaFinal.posicao.l][portaFinal.posicao.c])
            {
                Fase2();
            }
        }
        system("clear || cls");
    }
}

void Fase2()
{
    //Definindo as structs
    PortaFechada portaF;
    PortaFinal portaFinal;
    Jogador jogador;
    Chave chave;
    Botao botao;

    //Gera??o da matriz
    const int tamanhoMapa = 50;
    string mapa[tamanhoMapa][tamanhoMapa];

    //Icone do espinho
    string espinho = "#";

    //Posi??o e icone do bot?o
    botao.posicao.l = 25;
    botao.posicao.c = 45;
    botao.botao = "O";

    //Posi??o e icone da porta
    portaF.posicao.l = 25;
    portaF.posicao.c = 40;
    portaF.porta = "D";

    //Icone do portao
    string portao = "H";

    //Posi??o e icone da porta final
    portaFinal.posicao.l = 25;
    portaFinal.posicao.c = 5;
    portaFinal.portaFinal = "X";

    //Posi??o e icone da chave
    chave.posicao.l = 45;
    chave.posicao.c = 13;
    chave.chave = "@";
    
    //Posi??o e icone do jogador
    jogador.jogador = "&";
    jogador.posicao.l = 2;
    jogador.posicao.c = 25;
    int posOriginalx = 2; //Guarda a posi??o inicial X do jogador. ? usada para redefinir a sua posi??o quando morre
    int posOriginaly = 25; //Guarda a posi??o inicial Y do jogador. ? usada para redefinir a sua posi??o quando morre
    jogador.vidas = 3; //Variavel que armazena a quantidade de vidas do jogador

    //Variaveis que s?o usadas para armazenar se algo foi usado. Sempre iniciam falso
    bool comChave = false;
    bool portaAberta = false;
    bool botaoAtivo = false;
    bool portaoLevantado = false;
    
    char interagir; //Variavel respons?vel por armazenar as intera??es do jogador com o mapa (Movimenta??o e utiliza??o dos objetos)

    int loop = 54; //Variavel que mantem a fase em um loop at? que o jogador chegue ao final

    char lixo; //N?o armazena nenhum valor de interesse, somente usada para pausar o jogo

    system("clear || cls");

    while(loop == 54)
    {
        //Gera??o da matriz (Paredes exteriores)
        for(int i = 0; i < tamanhoMapa; i++)
        {
           for(int j = 0; j < tamanhoMapa; j++)
           {
               if(i == 0 || i == tamanhoMapa-1 || j == 0 || j == tamanhoMapa-1)
               {
                   mapa[i][j] = "*";
               }
               else
               {
                   mapa[i][j] = " ";
               }
           }
        }

        //Define a localiza??o dos objetos no mapa
        for(int i = 1; i <= 8; i++)
        {
            mapa[i][20] = "*";
        }
        for(int i = 1; i <= 12; i++)
        {
            mapa[i][29] = "*";
        }
        for(int i = 8; i <= 11; i++)
        {
            for(int j = 25; j <= 28; j++)
            {
                mapa[i][j] = espinho;
            }
        }
        for(int i = 41; i <= 48; i++)
        {
            mapa[29][i] = espinho;
        }
        for(int i = 41; i <= 48; i++)
        {
            mapa[21][i] = espinho;
        }
        for(int i = 4; i <= 6; i++)
        {
            mapa[24][i] = espinho;
        }
        for(int i = 24; i <= 26; i++)
        {
            mapa[i][4] = espinho;
        }
        for(int i = 4; i <= 6; i++)
        {
            mapa[26][i] = espinho;
        }
        mapa[45][14] = espinho;
        for(int i = 12; i <= 14; i++)
        {
            mapa[46][i] = espinho;
        }
        for(int i = 44; i <= 46; i++)
        {
            mapa[i][12] = espinho;
        }
        for(int i = 12; i <= 14; i++)
        {
            mapa[47][i] = espinho;
        }
        mapa[9][11] = espinho;
        for(int i = 20; i >= 10; i--)
        {
            mapa[8][i] = "*";
        }
        for(int i = 8; i <= 30; i++)
        {
            mapa[i][10] = "*";
        }
        for(int i = 1; i <= 10; i++)
        {
            mapa[20][i] = "*";
        }
        for(int i = 1; i <= 10; i++)
        {
            mapa[30][i] = "*";
        }
        if(botaoAtivo == false) //Se o bot?o for ativo, ele abre os port?es
        {
            for(int i = 24; i <= 26; i++)
            {
                mapa[i][10] = portao;
            }
        }
        else
        {
            for(int i = 24; i <= 26; i++)
            {
                mapa[i][10] = " ";
            }
        }
        for(int i = 15; i <= 29; i++)
        {
            mapa[12][i] = "*";
        }
        for(int i = 12; i <= 22; i++)
        {
            mapa[i][15] = "*";
        }
        for(int i = 15; i <= 40; i++)
        {
            mapa[22][i] = "*";
        }
        for(int i = 40; i <= 50; i++)
        {
            mapa[20][i] = "*";
        }
        for(int i = 40; i <= 50; i++)
        {
            mapa[30][i] = "*";
        }
        for(int i = 20; i <= 30; i++)
        {
            mapa[i][40] = "*";
        }
        for(int i = 10; i <= 40; i++)
        {
            mapa[28][i] = "*";
        }
        for(int i = 28; i <= 45; i++)
        {
            mapa[i][30] = "*";
        }
        for(int i = 28; i <= 49; i++)
        {
            mapa[i][34] = "*";
        }
        if(portaoLevantado == false) //Se o jogador interagir com a porta fechada, sem a chave, os port?es se abrem
        {
            for(int i = 31; i <= 33; i++)
            {
                mapa[28][i] = portao;
            }
        }
        else
        {
            for(int i = 31; i <= 33; i++)
            {
                mapa[28][i] = " ";
            }
        }
        for(int i = 16; i <= 30; i++)
        {
            mapa[45][i] = "*";
        }
        mapa[44][16] = "*";
        for(int i = 10; i <= 16; i++)
        {
            mapa[43][i] = "*";
        }
        for(int i = 43; i <= 49; i++)
        {
            mapa[i][10] = "*";
        }
        mapa[portaF.posicao.l][portaF.posicao.c] = portaF.porta;
        mapa[portaFinal.posicao.l][portaFinal.posicao.c] = portaFinal.portaFinal;

        if(comChave == false) //Se o jogador obter a chave, ela desaparece do ch?o
        {
            mapa[chave.posicao.l][chave.posicao.c] = chave.chave;
        }
        else
        {
            mapa[chave.posicao.l][chave.posicao.c] = " ";
        }
        if(portaAberta == false)
        {
            mapa[portaF.posicao.l][portaF.posicao.c] = portaF.porta; //Se a porta estiver trancada ela se mantem com o icone D (Porta fechada)
        }
        else
        {
            mapa[portaF.posicao.l][portaF.posicao.c] = "="; //Se a porta for aberta ela mude de icone para = (Porta aberta)
        }

        mapa[botao.posicao.l][botao.posicao.c] = botao.botao;
        mapa[jogador.posicao.l][jogador.posicao.c] = jogador.jogador;

        cout << "Fase 2" << endl;

        for(int i = 0; i < tamanhoMapa; i++)
        {
            for(int j = 0; j < tamanhoMapa; j++)
            {
                cout << mapa[i][j] << " ";
            }
            cout << endl;
        }
        cout << "Voce possui " << jogador.vidas << " vidas" << endl;
        cout << "Interagir (WASDI): ";
        cin >> interagir; //Armazena os inputs do jogador na variavel interagir

        interagir = toupper(interagir); //Transforma todos os inputs do jogador para maiusculo

        //SISTEMA DE MOVIMENTA??O
        if(interagir == 'W') 
        {
            if(mapa[jogador.posicao.l-1][jogador.posicao.c] == "*" || mapa[jogador.posicao.l-1][jogador.posicao.c] == portaF.porta || mapa[jogador.posicao.l-1][jogador.posicao.c] == "H") //Se o jogador apertar W, mas estiver sendo bloqueado por uma parede ou porta, ele n?o se move
            {
                jogador.posicao.l;
            }
            else //Caso o jogador n?o seja bloqueado, ele se movimenta para frente
            {
                jogador.posicao.l--;
            }
        }
        else if(interagir == 'A')
        {
            if(mapa[jogador.posicao.l][jogador.posicao.c-1] == "*" || mapa[jogador.posicao.l][jogador.posicao.c-1] == portaF.porta || mapa[jogador.posicao.l][jogador.posicao.c-1] == "H") //Se o jogador apertar A, mas estiver sendo bloqueado por uma parede ou porta, ele n?o se move
            {
                jogador.posicao.c;
            }
            else //Caso o jogador n?o seja bloqueado, ele se movimenta para o lado esquerdo
            {
                jogador.posicao.c--;
            }
        }
        else if(interagir == 'S')
        {
            if(mapa[jogador.posicao.l+1][jogador.posicao.c] == "*" || mapa[jogador.posicao.l+1][jogador.posicao.c] == portaF.porta || mapa[jogador.posicao.l+1][jogador.posicao.c] == "H") //Se o jogador apertar W, mas estiver sendo bloqueado por uma parede ou porta, ele n?o se move
            {
                jogador.posicao.l;
            }
            else //Caso o jogador n?o seja bloqueado, ele se movimenta para tras
            {
                jogador.posicao.l++;
            }
        }
        else if(interagir == 'D')
        {
            if(mapa[jogador.posicao.l][jogador.posicao.c+1] == "*" || mapa[jogador.posicao.l][jogador.posicao.c+1] == portaF.porta || mapa[jogador.posicao.l][jogador.posicao.c+1] == "H") //Se o jogador apertar W, mas estiver sendo bloqueado por uma parede ou porta, ele n?o se move
            {
                jogador.posicao.c;
            }
            else //Caso o jogador n?o seja bloqueado, ele se movimenta para o lado direito
            {
                jogador.posicao.c++;
            }
        }

        //SISTEMA DE INTERA??O COM OS OBJETOS
        if(interagir == 'I')
        {
            if(mapa[jogador.posicao.l][jogador.posicao.c] == mapa[chave.posicao.l][chave.posicao.c]) //Funcionamento da chave
            {
                comChave = true; //Se o jogador interagir com a chave, ficando em cima dela e apertando I, o jogador coleta a chave
            }

            if(mapa[jogador.posicao.l][jogador.posicao.c] == mapa[portaF.posicao.l][portaF.posicao.c-1] || mapa[jogador.posicao.l][jogador.posicao.c] == mapa[portaF.posicao.l][portaF.posicao.c+1] || mapa[jogador.posicao.l][jogador.posicao.c] == mapa[portaF.posicao.l-1][portaF.posicao.c] || mapa[jogador.posicao.l][jogador.posicao.c] == mapa[portaF.posicao.l+1][portaF.posicao.c] && comChave == true) //Funcionamento da porta
            {
                portaAberta = true; //Se o jogador interagir com a porta, ela se abre. Jogador deve ficar a um espa?o da porta
            }
            
            if(mapa[jogador.posicao.l][jogador.posicao.c] == mapa[botao.posicao.l][botao.posicao.c]) //Funcionamento do bot?o
            {
                botaoAtivo = true; //Se o jogador interagir com o bot?o, ficando em cima dele e apertando I, ele se ativa
            }

            if(mapa[jogador.posicao.l][jogador.posicao.c] == mapa[portaFinal.posicao.l][portaFinal.posicao.c])
            {
                Fase3();
            }

            if(mapa[jogador.posicao.l][jogador.posicao.c+1] == mapa[portaF.posicao.l][portaF.posicao.c] && portaoLevantado == false) //O port?o levanta quando o jogador interage com a porta trancada
            {
                portaoLevantado = true;
                portaAberta = false;
            }
        }

        if(mapa[jogador.posicao.l][jogador.posicao.c] == espinho) //Se o jogador cair em um espinho, ele morre e reseta a fase
        {
            comChave = false;
            portaAberta = false;
            botaoAtivo = false;
            //Jogador volta para a sua posi??o original
            jogador.posicao.l = posOriginalx;
            jogador.posicao.c = posOriginaly;
            jogador.vidas -=1; //Jogador perde uma vida
            if(jogador.vidas == 0) //Se as vidas do jogador acabarem aparece uma tela de derrota e ele volta para o menu
            {
                system("clear || cls");
                cout << "______________________________________" << endl;
                cout << endl;
                cout << "             Voce perdeu" << endl;
                cout << "   Tome mais cuidado da proxima vez" << endl;
                cout << "______________________________________" << endl;
                cout << "Pressione qualquer tecla para continuar: ";
                cin >> lixo;
                MenuPrincipal();
            }
        }
        system("clear || cls");
    }
}

void Fase3()
{
    //Definindo as structs
    PortaFechada portaF;
    PortaFinal portaFinal;
    Jogador jogador;
    Chave chave;
    Botao botao;
    Tp tp;
    Tp tp2;

    //Gera??o da matriz
    const int tamanhoMapa = 75;
    string mapa[tamanhoMapa][tamanhoMapa];

    //Icone do espinho
    string espinho = "#";

    //Posi??o e icone dos teleportes
    tp.posicao.l = 9;
    tp.posicao.c = 35;
    tp2.posicao.l = 69;
    tp2.posicao.c = 38;
    tp.tp = ">";
    tp2.tp = "<";

    //Posi??o e icone do bot?o
    botao.posicao.l = 72;
    botao.posicao.c = 67;
    botao.botao = "O";

    //Posi??o e icone da porta
    portaF.posicao.l = 68;
    portaF.posicao.c = 67;
    portaF.porta = "D";

    //Posi??o e icone da porta final
    portaFinal.posicao.l = 72;
    portaFinal.posicao.c = 38;
    portaFinal.portaFinal = "X";

    //Posi??o e icone da chave
    chave.posicao.l = 3;
    chave.posicao.c = 64;
    chave.chave = "@";
    
    //Posi??o e icone do jogador
    jogador.jogador = "&";
    jogador.posicao.l = 38;
    jogador.posicao.c = 2;
    int posOriginalx = 38; //Guarda a posi??o inicial X do jogador. ? usada para redefinir a sua posi??o quando morre
    int posOriginaly = 2; //Guarda a posi??o inicial Y do jogador. ? usada para redefinir a sua posi??o quando morre
    jogador.vidas = 3; //Variavel que armazena a quantidade de vidas do jogador

    //Variaveis que s?o usadas para armazenar se algo foi usado. Sempre iniciam falso
    bool comChave = false;
    bool portaAberta = false;
    bool botaoAtivo = false;
    bool tpAtivo = false;
    
    char interagir; //Variavel respons?vel por armazenar as intera??es do jogador com o mapa (Movimenta??o e utiliza??o dos objetos)

    int loop = 54; //Variavel que mantem a fase em um loop at? que o jogador chegue ao final

    char lixo; //N?o armazena nenhum valor de interesse, somente usada para pausar o jogo

    system("clear || cls");

    while(loop == 54)
    {
        //Gera??o da matriz (Paredes exteriores)
        for(int i = 0; i < tamanhoMapa; i++)
        {
           for(int j = 0; j < tamanhoMapa; j++)
           {
               if(i == 0 || i == tamanhoMapa-1 || j == 0 || j == tamanhoMapa-1)
               {
                   mapa[i][j] = "*";
               }
               else
               {
                   mapa[i][j] = " ";
               }
           }
        }

        mapa[portaFinal.posicao.l][portaFinal.posicao.c] = portaFinal.portaFinal;

        //Define a localiza??o dos objetos no mapa
        //Sala inicial
        for(int i = 6; i <= 15; i++)
        {
            mapa[28][i] = "*";
        }
        for(int i = 1; i <= 15; i++)
        {
            mapa[48][i] = "*";
        }
        for(int i = 6; i <= 28; i++)
        {
            mapa[i][6] = "*";
        }
        for(int i = 6; i <= 30; i++)
        {
            mapa[6][i] = "*";
        }
        for(int i = 6; i <= 14; i++)
        {
            mapa[i][30] = "*";
        }
        for(int i = 30; i <= 40; i++)
        {
            mapa[14][i] = "*";
        }
        for(int i = 1; i <= 14; i++)
        {
            mapa[i][40] = "*";
        }
        for(int i = 28; i <= 35; i++)
        {
            mapa[i][15] = "*";
        }
        for(int i = 41; i <= 48; i++)
        {
            mapa[i][15] = "*";
        }
        for(int i = 15; i <= 35; i++)
        {
            mapa[35][i] = "*";
        }
        for(int i = 15; i <= 64; i++)
        {
            mapa[41][i] = "*";
        }
        for(int i = 41; i <= 73; i++)
        {
            mapa[i][64] = "*";
        }
        for(int i = 35; i >= 20; i--)
        {
            mapa[i][35] = "*";
        }
        for(int i = 1; i <= 14; i++)
        {
            mapa[i][54] = "*";
        }
        for(int i = 54; i <= 68; i++)
        {
            mapa[14][i] = "*";
        }
        for(int i = 14; i <= 20; i++)
        {
            mapa[i][68] = "*";
        }
        for(int i = 35; i <= 68; i++)
        {
            mapa[20][i] = "*";
        }
        for(int i = 41; i <= 73; i++)
        {
            mapa[26][i] = "*";
        }
        for(int i = 26; i <= 35; i++)
        {
            mapa[i][41] = "*";
        }
        for(int i = 41; i <= 70; i++)
        {
            mapa[35][i] = "*";
        }
        for(int i = 35; i <= 73; i++)
        {
            mapa[i][70] = "*";
        }
        for(int i = 28; i <= 48; i++)
        {
            mapa[68][i] = "*";
        }
        for(int i = 73; i >= 68; i--)
        {
            mapa[i][28] = "*";
        }
        for(int i = 73; i >= 68; i--)
        {
            mapa[i][48] = "*";
        }
        for(int i = 65; i <= 69; i++)
        {
            mapa[68][i] = "*";
        }
        for(int i = 29; i <= 47; i++)
        {
            mapa[69][i] = espinho;
        }
        for(int i = 73; i >= 69; i--)
        {
            mapa[i][29] = espinho;
        }
        for(int i = 73; i >= 69; i--)
        {
            mapa[i][47] = espinho;
        }

        for(int i = 27; i <= 49; i++)
        {
            mapa[67][i] = espinho;
        }
        for(int i = 73; i >= 68; i--)
        {
            mapa[i][27] = espinho;
        }
        for(int i = 73; i >= 68; i--)
        {
            mapa[i][49] = espinho;
        }
        for(int i = 29; i <= 31; i++)
        {
            for(int j = 11; j <= 14; j++)
            {
                mapa[i][j] = espinho;
            }
        }

        if(comChave == false) //Se o jogador obter a chave, ela desaparece do ch?o
        {
            mapa[chave.posicao.l][chave.posicao.c] = chave.chave;
	    comChave = false;
        }
        else
        {
            mapa[chave.posicao.l][chave.posicao.c] = " ";
        }

        mapa[tp.posicao.l][tp.posicao.c] = tp.tp;
        if(botaoAtivo == true) //Se o bot?o for ativo, ele liga o teleporte
        {
            tpAtivo = true;
        }
        if(portaAberta == false)
        {
            mapa[portaF.posicao.l][portaF.posicao.c] = portaF.porta; //Se a porta estiver trancada ela se mantem com o icone D (Porta fechada)
        }
        else
        {
            mapa[portaF.posicao.l][portaF.posicao.c] = "="; //Se a porta for aberta ela mude de icone para = (Porta aberta)
        }
        mapa[tp2.posicao.l][tp2.posicao.c] = tp2.tp;

        mapa[botao.posicao.l][botao.posicao.c] = botao.botao;
        mapa[jogador.posicao.l][jogador.posicao.c] = jogador.jogador;

        cout << "Fase 3" << endl;

        for(int i = 0; i < tamanhoMapa; i++)
        {
            for(int j = 0; j < tamanhoMapa; j++)
            {
                cout << mapa[i][j] << " ";
            }
            cout << endl;
        }
        cout << "Voce possui " << jogador.vidas << " vidas" << endl;
        cout << "Interagir (WASDI): ";
        cin >> interagir; //Armazena os inputs do jogador na variavel interagir

        interagir = toupper(interagir); //Transforma todos os inputs do jogador para maiusculo

        //SISTEMA DE MOVIMENTA??O
        if(interagir == 'W') 
        {
            if(mapa[jogador.posicao.l-1][jogador.posicao.c] == "*" || mapa[jogador.posicao.l-1][jogador.posicao.c] == portaF.porta || mapa[jogador.posicao.l-1][jogador.posicao.c] == "H") //Se o jogador apertar W, mas estiver sendo bloqueado por uma parede ou porta, ele n?o se move
            {
                jogador.posicao.l;
            }
            else //Caso o jogador n?o seja bloqueado, ele se movimenta para frente
            {
                jogador.posicao.l--;
            }
        }
        else if(interagir == 'A')
        {
            if(mapa[jogador.posicao.l][jogador.posicao.c-1] == "*" || mapa[jogador.posicao.l][jogador.posicao.c-1] == portaF.porta || mapa[jogador.posicao.l][jogador.posicao.c-1] == "H") //Se o jogador apertar A, mas estiver sendo bloqueado por uma parede ou porta, ele n?o se move
            {
                jogador.posicao.c;
            }
            else //Caso o jogador n?o seja bloqueado, ele se movimenta para o lado esquerdo
            {
                jogador.posicao.c--;
            }
        }
        else if(interagir == 'S')
        {
            if(mapa[jogador.posicao.l+1][jogador.posicao.c] == "*" || mapa[jogador.posicao.l+1][jogador.posicao.c] == portaF.porta || mapa[jogador.posicao.l+1][jogador.posicao.c] == "H") //Se o jogador apertar W, mas estiver sendo bloqueado por uma parede ou porta, ele n?o se move
            {
                jogador.posicao.l;
            }
            else //Caso o jogador n?o seja bloqueado, ele se movimenta para tras
            {
                jogador.posicao.l++;
            }
        }
        else if(interagir == 'D')
        {
            if(mapa[jogador.posicao.l][jogador.posicao.c+1] == "*" || mapa[jogador.posicao.l][jogador.posicao.c+1] == portaF.porta || mapa[jogador.posicao.l][jogador.posicao.c+1] == "H") //Se o jogador apertar W, mas estiver sendo bloqueado por uma parede ou porta, ele n?o se move
            {
                jogador.posicao.c;
            }
            else //Caso o jogador n?o seja bloqueado, ele se movimenta para o lado direito
            {
                jogador.posicao.c++;
            }
        }

        //SISTEMA DE INTERA??O COM OS OBJETOS
        if(interagir == 'I')
        {
            if(mapa[jogador.posicao.l][jogador.posicao.c] == mapa[chave.posicao.l][chave.posicao.c]) //Funcionamento da chave
            {
                comChave = true; //Se o jogador interagir com a chave, ficando em cima dela e apertando I, o jogador coleta a chave
            }

            if(mapa[jogador.posicao.l][jogador.posicao.c] == mapa[portaF.posicao.l][portaF.posicao.c-1] || mapa[jogador.posicao.l][jogador.posicao.c] == mapa[portaF.posicao.l][portaF.posicao.c+1] || mapa[jogador.posicao.l][jogador.posicao.c] == mapa[portaF.posicao.l-1][portaF.posicao.c] || mapa[jogador.posicao.l][jogador.posicao.c] == mapa[portaF.posicao.l+1][portaF.posicao.c] && comChave == true) //Funcionamento da porta
            {
                portaAberta = true; //Se o jogador interagir com a porta, ela se abre. Jogador deve ficar a um espa?o da porta
            }
            
            if(mapa[jogador.posicao.l][jogador.posicao.c] == mapa[botao.posicao.l][botao.posicao.c]) //Funcionamento do bot?o
            {
                botaoAtivo = true; //Se o jogador interagir com o bot?o, ficando em cima dele e apertando I, ele se ativa
            }

            if(mapa[jogador.posicao.l][jogador.posicao.c] == mapa[tp.posicao.l][tp.posicao.c] && tpAtivo == true) //Funcionamento do TP
            {
                //Teleporta o jogador para a posi??o do TP2
                jogador.posicao.l = tp2.posicao.l;
                jogador.posicao.c = tp2.posicao.c;
            }
            else
            {
                if(mapa[jogador.posicao.l][jogador.posicao.c] == mapa[tp2.posicao.l][tp2.posicao.c] && tpAtivo == true) //Funcionamento do TP
                {
                    //Teleporta o jogador para a posi??o do TP1
                    jogador.posicao.l = tp.posicao.l;
                    jogador.posicao.c = tp.posicao.c;
                }
            }

            if(mapa[jogador.posicao.l][jogador.posicao.c] == mapa[portaFinal.posicao.l][portaFinal.posicao.c])
            {
                system("clear || cls");
                cout << "___________________________________________________" << endl;
		cout << endl;
                cout << "			Parabens! Voce venceu" << endl;
                cout << "Pressione qualquer tecla para voltar para o menu: ";
                cout << "___________________________________________________" << endl;
                cin >> lixo;
                MenuPrincipal();
            }
        }

        if(mapa[jogador.posicao.l][jogador.posicao.c] == espinho) //Se o jogador cair em um espinho, ele morre e reseta a fase
        {
            comChave = false;
            portaAberta = false;
            botaoAtivo = false;
            //Jogador volta para a sua posi??o original
            jogador.posicao.l = posOriginalx;
            jogador.posicao.c = posOriginaly;
            jogador.vidas -=1; //Jogador perde uma vida
            if(jogador.vidas == 0) //Se as vidas do jogador acabarem aparece uma tela de derrota e ele volta para o menu
            {
                system("clear || cls");
                cout << "______________________________________" << endl;
                cout << endl;
                cout << "             Voce perdeu" << endl;
                cout << "   Tome mais cuidado da proxima vez" << endl;
                cout << "______________________________________" << endl;
                cout << "Pressione qualquer tecla para continuar: ";
                cin >> lixo;
                MenuPrincipal();
            }
        }
        system("clear || cls");
    }
}

#endif
