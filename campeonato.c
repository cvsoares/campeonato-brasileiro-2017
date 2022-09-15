/**************************************************************************
Descrição do Algoritmo: CAMPEONATO BRASILEIRO
Nome da Disciplina: Algoritmos
Nome Professor: 
Nome Aluno: Carla Soares
Turma: 
RGA:
Data Entrega: 
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
// #include <conio2.h>

void setVariancia(float *S, float SQ, float T){
    *S =  (float) SQ / (T-1);
}
float getDesvio(float v){
    return sqrt(v);
}
int main()
{

	int vetor [20] = {43,43,43,39,36,47,45,72,63,50,50,53,51,54,54,57,56,56,62,63};
	int primeiro, cont, i, j, posy, posx, getY, getX, menor, contModa, n, posModa, modaAnt, XI, fy, aux, x, y, N, K, AT, ATC, modas[10];
	float matz [20][4], SQ, FCS, S, D, MA=0, MD=0, Q;

	primeiro = 0;
	cont=0;

	while (cont <20)
	{
		menor = primeiro;

		for(i = primeiro + 1; i < 20; i++)
		{
			if(vetor[menor] > vetor[i])
			{
				menor = i;
			}
		}
		aux = vetor[primeiro];
		vetor[primeiro] = vetor[menor];
		vetor[menor] = aux;
		primeiro = primeiro + 1;
		cont++;
	}

    textbackground(WHITE);
	textcolor(BLACK);

	N = 20;
	K = sqrt(20) + 1;
	AT = vetor[19]-vetor[0];
	ATC = (AT/K) +1;

	for (i=0;i<20;i++)
	{
		MA+=vetor[i];
	}
    MA/=20;
    MD=(vetor[10]+vetor[11])/2;

	//ARMAZENANDO DADOS NA MATRIZ
    Q=0;
    i=0;
    while(i<20){
        for(j=0; j<4; j++){
            if(j==0)
                matz[i][j]=vetor[i];
            else if(j==1)
                matz[i][j]=MA;
            else if(j==2)
                matz[i][j]=vetor[i]-MA;
            else{
                Q=matz[i][2];
                matz[i][j]=Q*Q;
            }
        }
        i++;
    }
    system("cls");
    gotoxy(1, 2);
    printf("                         AMOSTRA                            \n\n");
    gotoxy(2, 4);
	for (i=0; i<20; i++)
	{
		textbackground(WHITE);
		printf ("%d ", vetor[i]);
	}
    //TABELA
    i=0;
    j=0;
    posy=wherey()+4;
    fy=posy+((20+1)*2);
    posx=(80-(4*10))/2;
    for(y=posy; y<=fy; y++){
        for(x=0; x<80; x++){
            gotoxy(x, y);
            //COLORINDO AS COLUNAS
            if(x>=posx && x<=posx+10)
                textcolor(RED);
            if(x>=posx+10 && x<=posx+20)
                textcolor(BLUE);
            if(x>=posx+20 && x<=posx+30)
                textcolor(GREEN);
            if(x>=posx+30 && x<=posx+40)
                textcolor(BLACK);
            //################
            //TITULO DAS COLUNAS
            if(y%2==0 && x>posx && x<posx+40)
                printf("%c", 196);
            else if(y==posy+1){
                    if(x==posx)
                        printf("\tx");
                    if(x==posx+10)
                        printf("MEDIA");
                    if(x==posx+20)
                        printf("DESVIO");
                    if(x==posx+30)
                        printf("QUADRADO");
            }else{
                //VALORES
                //condicao para analisar ate y==19
                if(y!=fy){
                    if(x==posx+1){
                        printf("\t%.0f", matz[i][j]);
                        j++;
                    }
                    if(x==posx+11){
                        printf("%.2f", matz[i][j]);
                        j++;
                    }
                    if(x==posx+21){
                        printf("%.2f", matz[i][j]);
                        j++;
                    }
                    if(x==posx+30){
                        SQ+=matz[i][j];
                        printf("%.4f", matz[i][j]);
                        j=0;
                        i++;
                    }
                }
            }
        }
        textcolor(BLACK);
    }

    //CALCULANDO VARIANCIA E DESVIO
    setVariancia(&S, SQ, 20);
    D=getDesvio(S);

    //EXIBINDO VARIANCIA E DESVIO
    posy=wherey()+4;
    fy=posy+(2*2);
    posx=(80-(10*2))/2;
    for(y=posy; y<=fy; y++){
        for(x=0; x<80; x++){
            gotoxy(x, y);
            if(y%2==0 && x>posx && x<posx+20){
                printf("%c", 196);
            }else if(y==posy+1){
                if(x==posx+1)
                    printf("VAR");
                if(x==posx+10)
                    printf(" DESV");
            }else{
                if(x==posx+1)
                    printf("%.3f", S);
                if(x==posx+10)
                    printf(" %.2f", D);
            }
        }
    }

    //EXIBINDO A MEDIA, MODA E MEDIANA
    posy=wherey()+4;
    fy=posy+(2*2);
    posx=(80-(10*3))/2;
    for(y=posy; y <fy; y++){
        for(x=0; x<80; x++){
            gotoxy(x, y);
            if(y%2==0 && x>posx && x<posx+30){
                printf("%c", 196);
            }else if(y==posy+1){
                //TITULO DAS COLUNAS
                if(x==posx+1){
                    printf("MODA");
                }
                if(x==posx+10){
                    printf("MEDIANA");
                }
                if(x==posx+20){
                    printf("MODA");
                }
            }else{
                //VALORES
                if(x==posx+1){
                    printf("%.2f", MA);
                }
                if(x==posx+10){
                    printf("%.2f", MD);
                }
                if(x==posx+20){
                    getY=wherey();
                    getX=wherex();
                }
            }
        }
    }
    //BUSCANDO A MODA
    contModa = 0;
    primeiro = 0;
    posModa = 0;
    modaAnt = 1;
    i = 0;
    while(i < 20){
        n = 1;
        for(j = primeiro + 1; j < 20; j++){
            if(vetor[primeiro] == vetor[j]){
                n++;
                posModa = j;
            }
        }
        if(n>1){
            if(n==modaAnt){
                modas[contModa]=vetor[posModa];
                contModa++;
            }
            if(n>modaAnt){
                modaAnt=n;
                contModa=0;
                modas[contModa]=vetor[posModa];
            }
        }
        primeiro+=1;
        i++;
    }
    modas[contModa+1]=0;

    printf("%i", modas[1]);
    for(i=0; i<10; i++){
    gotoxy(getX, getY);
        if(modas[i]==0)
            i=10;
        else{
            printf("%i", modas[i]);
            getX+=3;
        }

    }
    getch();
    return(0);
}
