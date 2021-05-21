#include <stdio.h>
int sommaScontrino = 0;
int sommaCassa = 0;

int prezzi[4][5] = {
    {1, 3, 2, 2, 1},
    {1, 3, 1, 2, 1},
    {1, 3, 2, 2, 1},
    {1, 3, 2, 2, 1},
};

void menuPrincipale();

void Reparti();

void Cassa();

void Vendita();

void repartoOrtofrutta();

void repartoArticoliQuotidianeita();

void repartoMacelleria();

void repartoCasalinghi();

void acquisto(int, int);

void scontrino();

void sceltaReparto(int);

void paga();

int pagamento( int );

int main()
{
    menuPrincipale();
}

void menuPrincipale()
{
    int scelta;

    puts("");
    printf("Benvenuti nel supermercato, ");
    printf("scegliere la sezione \n");
    puts("da visionare. \n");
    printf("Digitare: \n1 - per visionare i reparti; \n");
    printf("2 - per la paga; \n");
    printf("3 - per la vendita; \n");
    printf("4 - per il pagamento; \n");
    printf("5 - per le informazioni relative al supermercato; \n");
    puts("\"Altro valore\" - per terminare il programma. \n");
    puts("Inserire di seguito la sezione scelta: ");
    scanf("%d\a", &scelta);

    switch (scelta)
    {
    case 1:
        Reparti();
        break;

    case 2:
        Cassa();
        break;

    case 3:
        Vendita();
        break;

    case 4:
        break;
    }
}

void Reparti()
{
    int reparto;

    puts(" \nI reparti del supermercato sono i seguenti: \n");
    printf("1 - Ortofrutta; \n");
    printf("2 - Articoli per la quotidianeità; \n");
    printf("3 - Macelleria; \n");
    printf("4 - Articoli casalinghi. \n\n");
    printf("Digitare la scelta del reparto: \n");
    scanf("%d", &reparto);

    sceltaReparto(reparto);
}

void sceltaReparto(int scelta)
{
    switch (scelta)
    {
    case 1:
        repartoOrtofrutta();
        break;
    case 2:
        repartoArticoliQuotidianeita();
        break;
    case 3:
        repartoMacelleria();
        break;
    case 4:
        repartoCasalinghi();
        break;
    }
}

void Cassa()
{
}

void Vendita()
{
}

void acquisto(int reparto, int prodotto)
{
    int quantita;

    if (prodotto > 5 || prodotto < 1)
    {
        printf("Errore nell'inserimento");
        sceltaReparto(reparto);
    }

    printf("Quanti kg vuole acquistare?\n");
    scanf("%d", &quantita);

    sommaScontrino += prezzi[reparto][prodotto] * quantita;

    int scelta;
    printf("\n1 - per inserire altri prodotti;\n");
    printf("2 - per stampare lo scontrino.\n");
    scanf("%d", &scelta);
    switch (scelta)
    {
        case 1:
        sceltaReparto(scelta);
        break;

    case 2:
        scontrino();
        break;

    default:
        printf("scelta errata, si prega di riprovare");
        acquisto(reparto, prodotto);
        break;
    }
}

void repartoOrtofrutta()
{
    int scelta = 0;

    printf("\nDigitare:\n");
    printf("1 - Mele (1€/kg)\n");
    printf("2 - Fragole (3€/kg)\n");
    printf("3 - Carote (2€/kg)\n");
    printf("4 - Zucche (2€/kg)\n");
    printf("5 - Limoni (1€/kg)\n");
    printf("6 - Per tornare alla scelta dei reparti.\n");
    printf("7 - Per tornare al menù iniziale.\n");
    printf("8 - Per uscire dal programma. \n\n");
    scanf("%d", &scelta);

    if ( scelta == 7 )
    {
        sceltaReparto( 1 );
    }

    if ( scelta == 8 ) {
        menuPrincipale();
    }

    if ( scelta == 9 ) {
        return;
    }

    acquisto(0, scelta-1);
}

void repartoArticoliQuotidianeita() {
    int scelta;

    printf("\nDigitare i prodotti acquistati:\n");
    printf("1 - Olio EVO (7€/confezione)\n");
    printf("2 - Patatine fritte surgelate (3€/confezione)\n");
    printf("3 - Merendine (2€/confezione)\n");
    printf("4 - Latte (1€/confezione)\n");
    printf("5 - Passata di pomodoro (4€/confezione)\n");
    printf("6 - Cereali (5€/confezione)\n");
    printf("7 - Per tornare alla scelta dei reparti.\n");
    printf("8 - Per tornare al menù iniziale.\n");
    printf("9 - Per uscire dal programma. \n\n");
    scanf("%d", &scelta);

    if ( scelta == 7 )
    {
        sceltaReparto( 1 );
    }

    if ( scelta == 8 ) {
        menuPrincipale();
    }

    if ( scelta == 9 ) {
        return;
    }

    acquisto(1, scelta-1);
}

void repartoMacelleria() {
    int scelta;

    printf("\nDigitare: \n");
    printf("1 - Carne Macinata (9€/kg)\n");
    printf("2 - Petto di pollo (11€/kg)\n");
    printf("3 - Carne di Bovino (15€/kg)\n");
    printf("4 - Salsicce di maiale (7€/kg)\n");
    printf("5 - Carne di vitello (8€/kg)\n");
    printf("6 - Per tornare alla scelta dei reparti.\n");
    printf("7 - Per tornare al menù iniziale.\n");
    printf("8 - Per uscire dal programma. \n\n");
    scanf("%d", &scelta);

    if ( scelta == 7 )
    {
        sceltaReparto( 1 );
    }

    if ( scelta == 8 ) {
        menuPrincipale();
    }

    if ( scelta == 9 ) {
        return;
    }

    acquisto(2, scelta-1);
}

void repartoCasalinghi() {
    int scelta;

    printf("Digitare: \n");
    printf("1- Piatti (2€/pezzo)\n");
    printf("2- Bicchieri (1€ pezzo)\n");
    printf("3- Forchette (1€/pezzo)\n");
    printf("4- Cucchiai (1€/pezzo)\n");
    printf("5-  Padelle (5€/pezzo)\n");
    scanf ("%d", &scelta);

    if ( scelta == 7 )
    {
        sceltaReparto( 1 );
    }

    if ( scelta == 8 ) {
        menuPrincipale();
    }

    if ( scelta == 9 ) {
        return;
    }

    acquisto(3, scelta-1);
}


void scontrino()
{
    printf( "********************************\n\n" );
    printf("Il totale dello scontrino é: %d", sommaScontrino);
    printf( "********************************\n\n\n\n\n\n" );
    printf( "1 - Continua "
            "\n 2- Paga" );

    int scelta;
    scanf( "%d", &scelta );
     if ( scelta == 1 ) {
         menuPrincipale();
     } else {
         paga();
     }
}

void paga() {
    int ammontare;

    printf( "Il totale dello scontrino é: %d", sommaScontrino );
    printf( "\nImmetti l'ammontare: \n" );
    scanf( "%d", &ammontare );

    pagamento(  );
}


int pagamento( int ammontare ) {
    int differenza = sommaScontrino - ammontare;

    if ( differenza<0 ) {
        printf( "Il totale inserito non é sufficiente" );
        paga();
    }

    for ( int i = 0, i<  )
}
