#include "stdio.h"

int sommaScontrino = 0;
int scelta;

int prezzi[4][5] = {
        {1, 3,  2,  2, 1},
        {7, 3,  2,  1, 4},
        {9, 11, 15, 7, 8},
        {2, 1,  1,  1, 5},};

int Tagli[6] = {1, 2, 5, 10, 20, 50};

int quantitaTagli[6] = {10, 10, 10, 2, 2, 2};

int QuantitaProdotti[4][5] = {
        {50,  30,  50,  50,  40},
        {30,  20,  35,  50,  40},
        {50,  30,  45,  70,  80},
        {100, 100, 100, 100, 50},};

void menuPrincipale();

void Reparti();

void sceltaReparto(int);

void Acquisto(int, int);

void Ortofrutta();

void Sala();

void Macelleria();

void ArticoliPerLaCasa();

void RicaricaProdotti(int, int, int);

void ricaricaTagli(int);

void Cassa();

void Pagamento();

void gestioneTagli();

void calcolaResto(int);

int sommaTotaleTagli();

void generaBuono(int);

int main(void) {
    menuPrincipale();

    return 0;
}

void menuPrincipale() {

    puts("");
    printf("Benvenuti nel supermercato, ");
    printf("scegliere la sezione \n");
    puts("da visionare. \n");
    printf("\nDigitare: \n");
    printf("1 - Per visualizzare i reparti;\n");
    printf("2 - Per andare alla cassa;\n");
    printf("3 - Per il pagamento;\n");
    printf("4 - Per uscire dal programma.\n");
    scanf("%d", &scelta);

    switch (scelta) {
        case 1: {
            Reparti();
            break;
        }
        case 2: {
            Cassa();
            break;
        }
        case 3: {
            Pagamento();
            break;
        }
        case 4: {
            printf("\nGrazie per aver usufruito del programma. \n");
            break;
        }
        default: {
            printf("\nInserimento invalido, riprovare. \n\n");
            menuPrincipale();
            break;
        }
    }
}

void Reparti() {
    int reparto;
    printf("\nA quale reparto desidera accedere? \n");
    printf("1 - Ortofrutta; \n");
    printf("2 - Sala; \n");
    printf("3 - Macelleria; \n");
    printf("4 - Articoli per la casa; \n");
    printf("5 - Per tornare al menù principale; \n");
    printf("6 - Per uscire dal programma.\n");
    scanf("%d", &reparto);

    sceltaReparto(reparto);
}

void sceltaReparto(int scelta) {
    switch (scelta) {
        case 1:
            Ortofrutta();
            break;
        case 2:
            Sala();
            break;
        case 3:
            Macelleria();
            break;
        case 4:
            ArticoliPerLaCasa();
            break;
        case 5:
            printf("\n\n**************************************\n\n");
            menuPrincipale();
            break;
        case 6:
            printf("\nGrazie per aver usufruito del programma. \n");
            printf("\n\n**************************************\n\n");
            break;
        default:
            printf("\nInserimento invalido, riprovare.\n \n");
            printf("\n\n**************************************\n\n");
            Reparti();
            break;
    }
}

void Ortofrutta() {
    int scelta = 0;

    printf("\nDigitare:\n");
    printf("1 - Mele (1€/kg), %d pezzi.\n", QuantitaProdotti[0][0]);
    printf("2 - Fragole (3€/kg), %d pezzi.\n", QuantitaProdotti[0][1]);
    printf("3 - Carote (2€/kg), %d pezzi.\n", QuantitaProdotti[0][2]);
    printf("4 - Zucche (2€/kg), %d pezzi.\n", QuantitaProdotti[0][3]);
    printf("5 - Limoni (1€/kg), %d pezzi.\n", QuantitaProdotti[0][4]);
    printf("6 - Per tornare alla scelta dei reparti;\n");
    printf("7 - Per tornare al menù iniziale;\n");
    printf("8 - Per uscire dal programma. \n\n");
    scanf("%d", &scelta);

    if (scelta == 6) {
        sceltaReparto(1);
    }

    if (scelta == 7) {
        menuPrincipale();
    }

    if (scelta == 8) {
        return;
    }

    Acquisto(0, scelta - 1);
}

void Sala() {
    int scelta;

    printf("\nDigitare i prodotti acquistati:\n");
    printf("1 - Olio EVO (7€/confezione), %d pezzi.\n", QuantitaProdotti[1][0]);
    printf("2 - Patatine fritte surgelate (3€/confezione), %d pezzi.\n", QuantitaProdotti[1][1]);
    printf("3 - Merendine (2€/confezione), %d pezzi.\n", QuantitaProdotti[1][2]);
    printf("4 - Latte (1€/confezione), %d pezzi.\n", QuantitaProdotti[1][3]);
    printf("5 - Passata di pomodoro (4€/confezione), %d pezzi.\n", QuantitaProdotti[1][4]);
    printf("7 - Per tornare alla scelta dei reparti.\n");
    printf("8 - Per tornare al menù iniziale.\n");
    printf("9 - Per uscire dal programma. \n\n");
    scanf("%d", &scelta);

    if (scelta == 7) {
        Reparti();
    }

    if (scelta == 8) {
        menuPrincipale();
    }

    if (scelta == 9) {
        return;
    }

    Acquisto(1, scelta - 1);
}


void Macelleria() {
    int scelta;

    printf("\nDigitare: \n");
    printf("1 - Carne Macinata (9€/kg), %d pezzi.\n", QuantitaProdotti[2][0]);
    printf("2 - Petto di pollo (11€/kg), %d pezzi.\n", QuantitaProdotti[2][1]);
    printf("3 - Carne di Bovino (15€/kg), %d pezzi.\n", QuantitaProdotti[2][2]);
    printf("4 - Salsicce di maiale (7€/kg), %d pezzi.\n", QuantitaProdotti[2][3]);
    printf("5 - Carne di vitello (8€/kg), %d pezzi.\n", QuantitaProdotti[2][4]);
    printf("6 - Per tornare alla scelta dei reparti.\n");
    printf("7 - Per tornare al menù iniziale.\n");
    printf("8 - Per uscire dal programma. \n\n");
    scanf("%d", &scelta);

    if (scelta == 6) {
        sceltaReparto(1);
    }

    if (scelta == 7) {
        menuPrincipale();
    }

    if (scelta == 8) {
        return;
    }

    Acquisto(2, scelta - 1);
}

void ArticoliPerLaCasa() {
    int scelta;

    printf("Digitare: \n");
    printf("1- Piatti (2€/pezzo), %d pezzi.\n", QuantitaProdotti[3][0]);
    printf("2- Bicchieri (1€ pezzo), %d pezzi.\n", QuantitaProdotti[3][1]);
    printf("3- Forchette (1€/pezzo), %d pezzi.\n", QuantitaProdotti[3][2]);
    printf("4- Cucchiai (1€/pezzo), %d pezzi.\n", QuantitaProdotti[3][3]);
    printf("5- Padelle (5€/pezzo), %d pezzi.\n", QuantitaProdotti[3][4]);
    printf("6 - Per tornare alla scelta dei reparti.\n");
    printf("7 - Per tornare al menù iniziale.\n");
    printf("8 - Per uscire dal programma. \n\n");
    scanf("%d", &scelta);

    if (scelta == 6) {
        sceltaReparto(1);
    }

    if (scelta == 7) {
        menuPrincipale();
    }

    if (scelta == 8) {
        return;
    }
    Acquisto(3, scelta - 1);
}

void RicaricaProdotti(reparto, prodotto, quantita) {
    int dose;

    printf("Inserire la dose da aggiungere al %d° prodotto: \n", prodotto + 1);
    scanf("%d", &dose);

    QuantitaProdotti[reparto][prodotto] = QuantitaProdotti[reparto][prodotto] + dose - quantita;
    printf("Ora il %d° prodotto è disponibile per %d volte. \n", prodotto + 1, QuantitaProdotti[reparto][prodotto]);
}

void Cassa() {
    int scelta;

    printf("Digitare: \n");
    printf("1- per visualizzare tutti i tagli con le loro quantità\n");
    printf("2- per tornare al menù principale \n");
    scanf("%d", &scelta);

    switch (scelta) {
        case 1:
            gestioneTagli();
            break;

        case 2:
            menuPrincipale();
            break;
    }

}

void gestioneTagli() {
    printf("I tagli disponibili sono: \n");

    for (int i = 0; i < 6; ++i) {
        printf("%d euro - %d pezzi\n", Tagli[i], quantitaTagli[i]);
    }

    printf("\n\n*******************************\n\n");

    printf("Digitare: \n");

    for (int i = 0; i < 6; ++i) {
        printf("%d - per ricaricare il taglio da %d euro\n", i + 1, Tagli[i]);
    }

    int scelta;

    scanf("%d", &scelta);

    ricaricaTagli(scelta);
}

void ricaricaTagli(int taglio) {
    int quantita;

    printf("Inserire la quantita da ricaricare: \n");
    scanf("%d", &quantita);

    quantitaTagli[taglio - 1] += quantita;

    int scelta;
    printf("1- per tornare alla cassa\n");
    printf("2- per tornare al menu principale\n");
    printf("3- per uscire dal programma\n");
    scanf("%d", &scelta);

    switch (scelta) {

        case 1:
            Cassa();
            break;
        case 2:
            menuPrincipale();
            break;
        case 3:
            return;
    }
}

void Acquisto(int reparto, int prodotto) {
    int quantita, opzione;

    if (prodotto > 8) {
        printf("Errore nell'inserimento. \n");
        Reparti();
    }

    printf("\nSi vuole prima ricaricare il prodotto? \n");
    printf("Digitare 1 per continuare, 2 per rifiutare. \n");
    scanf("%d", &scelta);

    if (scelta == 1) {
        RicaricaProdotti(reparto, prodotto, quantita);
    } else {
        printf("Va bene, allora quanti pezzi vuole acquistare il cliente?\n");
        scanf("%d", &quantita);
    }

    if (QuantitaProdotti[reparto][prodotto] < quantita) {
        printf("Non ci sono quantità a sufficienza. \n");
        printf("\n\n**************************************\n\n");
        Reparti();

    }

    sommaScontrino += prezzi[reparto][prodotto] * quantita;

    printf("\n1 - per operare su altri prodotti;\n");
    printf("2 - per stampare lo scontrino.\n");
    scanf("%d", &opzione);
    switch (opzione) {
        case 1: {
            sceltaReparto(scelta);
            break;
        }

        case 2: {
            printf("\nIl totale della spesa è %d€. \n", sommaScontrino);
            printf("\n\n**************************************\n\n");
//pagamento.
            menuPrincipale();
            break;
        }

        default: {
            printf("\nScelta errata, si prega di riprovare. \n");
            Acquisto(scelta, prodotto);

        }
    }
}


void Pagamento() {
    printf("Si sta per procedere al pagamento dell'importo totale di: %d\n\n", sommaScontrino);
    printf("Si prega di inserire l'importo versato: \n");

    int importo;

    scanf("%d", &importo);

    if (importo < sommaScontrino) {
        printf("L'importo versato non é sufficiente, reinserire l'importo corretto.\n");

        Pagamento();
    }

    calcolaResto(importo);

    printf("Digitare: \n");
    printf("1 - per tornare al menu principale. \n");
    printf("2 - per uscire dal programma. \n");

    int scelta;

    scanf("%d", &scelta);

    switch (scelta) {
        case 1:
            menuPrincipale();
            break;
        case 2:
            return;
    }
}


void calcolaResto(int importo) {
    int resti[6] = {0, 0, 0, 0, 0, 0};
    int resto = importo - sommaScontrino;
    if (sommaTotaleTagli() < importo - sommaScontrino) {
        printf("Il totale contenuto in cassa non é sufficiente per restituire il resto al cliente\n");
        generaBuono(importo);
    }

    for (int i = 5; i >= 0; --i) {
        resti[i] = resto / Tagli[i];
        resto = resto % Tagli[i];
    }

    printf("\n\n********************************** \n");
    printf("\n\nIl resto dovuto é composto da: \n");
    for (int i = 0; i < 6; ++i) {
        printf("%d pezzi da %d euro; \n", resti[i], Tagli[i]);
    }
}


int sommaTotaleTagli() {
    int somma = 0;
    for (int i = 0; i < 6; ++i) {
        somma += quantitaTagli[i] * Tagli[i];
    }

    return somma;
}

void generaBuono(int importo) {
    printf("\nÉ stato generato un buono pari a %d euro per il cliente.\n", importo);
}