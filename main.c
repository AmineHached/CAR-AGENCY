#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct traveux
{
    int numero;
    char codeOp[20];
    float cout;
    int mainOeuvre;                     // declaration de la structure traveux
    int tempsOp;
    struct traveux *suiv;   //pointure de type traveux pour pointé sur le noeud suivant
} traveux;

typedef struct                      // declaration de la structure liste
{
    traveux* tete;             // tete de la liste qui va pointé sur le premier traveux
    int longeur;            // longeur de la liste
} traveuxList;

typedef traveuxList* liste;      //creation du type liste qui est un pointeur sur le type traveuxListe



void rechercheSeqTrav(traveux* P, char op[])             //Question 3
{

    if(strcasecmp(P->codeOp,op)==0)  // condition d'arret 1 : si le code d'op existe
    {
        printf("l'adresse du premier code d'operation est : %p\n",P);
    }
    else if(P->suiv == NULL)
    {
        printf("NULL\n");       // condition d'arret 2: si le code d'op n'existe pas
    }
    else
    {
        rechercheSeqTrav(P->suiv,op);       // iteration recursive avec le noeud suivant
    }
}


void ajoutOp(liste lst)             //Question 4
{
    traveux *P, *Q, *ptr;
    int num, b, i;
    float cout;
    int mainOeuv;
    int tempOp;

    if(lst->longeur == 0)
    {
        printf("veuillez remplir votre liste avant.\n");        // il faut remplir la liste avant d'inserer un seul traveux
    }
    else
    {
        P = (traveux*)malloc(sizeof(traveux));
        do
        {
            printf("Donner le numero de ce traveux: ");
            fflush(stdin);
            scanf("%d", &num);
            Q = lst->tete;
            b=0;
            do
            {
                if(Q->numero == num)
                {
                    b=1;
                }
                else
                {
                    if(Q->suiv == NULL)
                    {
                        Q = NULL;
                        b=0;
                    }
                    else
                    {
                        Q= Q->suiv;
                    }
                }
            }
            while((Q != NULL) && (b !=1));
        }
        while(b==1);

        P->numero = num; // affectation du numero dans le noeud

        printf("Donner le code d'operation: ");
        fflush(stdin);
        gets(P->codeOp); //affection du code d'operation dans le noeud

        do
        {
            printf("Donner le cout de ce traveux: ");
            fflush(stdin);
            scanf("%f",&cout);
        }
        while(cout<=0);   // verification que le cout est different de 0

        P->cout = cout; //affectation du cout dans le noeud

        do
        {
            printf("Donner la main d'ouevre: ");
            fflush(stdin);
            scanf("%d",&mainOeuv);
        }
        while(mainOeuv <=0);  // verification de la main oeuvre est different de 0

        P->mainOeuvre = mainOeuv; //affection de la main d'oeuvre dans le noeud

        do
        {
            printf("Donner le temps d'operation: ");
            fflush(stdin);
            scanf("%d",&tempOp); // verification du temps d'operation est different de 0

        }
        while(tempOp <=0);

        P->tempsOp = tempOp; // affectation du temps operation dans le noeud
        P->suiv = NULL;
        Q = lst->tete;
        b=0;
        i=0;
        do
        {
            if( (strcasecmp(Q->codeOp,P->codeOp) ==0) && (Q->suiv != NULL))
            {
                if(Q->suiv->codeOp == P->codeOp)
                {
                    Q = Q->suiv;
                }
                else
                {
                    ptr = Q->suiv;
                    Q->suiv = P;
                    P->suiv = ptr;
                    b=1;
                }
            }
            else if( strcasecmp(Q->codeOp,P->codeOp)==0 && Q->suiv == NULL)
            {
                Q->suiv = P;
                b=1;
            }
            else if(strcasecmp(Q->codeOp,P->codeOp) !=0 && Q->suiv ==NULL)
            {
                Q->suiv = P;
                b=1;
            }
            else if(strcasecmp(Q->codeOp,P->codeOp) !=0 && Q->suiv != NULL)
            {
                Q= Q->suiv;
            }
        }
        while((Q != NULL)&& (b != 1));

        lst->longeur = lst->longeur + 1;
    }
}

void afficheListe(liste lst)        //Question 5
{
    traveux* P;
    P=lst->tete;
    while(P!=NULL)
    {
        printf("Le numero de ce traveux est: %d\n",P->numero);
        printf("Le code d'operation est: %s\n",P->codeOp);
        printf("Le cout de cette operation est: %0.3f\n",P->cout);
        printf("La main oeuvre egale a: %d\n",P->mainOeuvre);
        printf("Le temps de cette operation est: %d\n",P->tempsOp);
        printf("____________________________________\n");
        P = P->suiv;
    }
}

void travseqdonne(liste L,char op[])  //Question 6
{
    traveux *P;
    char num[20];
    int b;

    printf("Donner le Code d'operation \n ");
    fflush(stdin);
    gets(num);
    P = L->tete;

    do
    {
        if(strcasecmp(P->codeOp,num)==0)
        {
            printf("Le numero de ce traveux est: %d\n",P->numero);
            printf("Le code d'operation est: %s\n",P->codeOp);
            printf("Le cout de cette operation est: %0.3f\n",P->cout);
            printf("La main oeuvre egale a: %d\n",P->mainOeuvre);
            printf("Le temps de cette operation est: %d\n",P->tempsOp);
            printf("____________________________________\n");
            P=P->suiv;
            b=1;
        }
        else
        {
            P=P->suiv;
            b=0;


        }
    }
    while(P!=NULL);
    if(b==0)
        printf("Code d'operation existe pas \n");
}
void Update(liste L)
{
    traveux* P;
    P=L->tete;
    float cmax=0;
    int pos=0;
    for(int i=1; i<L->longeur; i++)
    {
        if(P->cout>cmax)
            cmax=P->cout;
        pos++;
        P=P->suiv;
    }
    P=L->tete;
    for(int i=1; i<=pos; i++)
        P=P->suiv;
    P->mainOeuvre=P->mainOeuvre-3;
    P->tempsOp=P->tempsOp+5;
    P->cout=P->cout*0.7;
    printf("Le numero de ce traveux est: %d\n",P->numero);
    printf("Le code d'operation est: %s\n",P->codeOp);
    printf("Le cout de cette operation est: %f\n",P->cout);
    printf("La main oeuvre egale a: %d\n",P->mainOeuvre);
    printf("Le temps de cette operation est: %d\n",P->tempsOp);
    printf("____________________________________\n");
}
void Delete(liste L,int pos)
{
    traveux* p=L->tete,*q;
    if(pos==1)
    {
        q=L->tete;
        L->tete=L->tete->suiv;
    }
    else
    {
        for(int i=1; i<pos-1; i++)
            p=p->suiv;
        q=p->suiv;
        p->suiv=q->suiv;
    }
    free(q);
    (L->longeur)--;
}
void codeaffiche(liste L)
{
    traveux* P;
    int tmax=0,pos=0;
    P = L->tete;
    for(int i=0; i<L->longeur; i++)
    {
        if(P->tempsOp>tmax){
            tmax=P->tempsOp;
            pos++;
        }
        P=P->suiv;
    }
    P=L->tete;
    for(int i=0; i<pos; i++)
        P=P->suiv;
    printf("le code opératoire nécessitant le temps le plus elevé est %s",P->codeOp);
}

void main()
{
    liste L;
    int n,c,pos;
    traveux*P,*Q,*ptr,*K;
    int num, b,j;
    float cout;
    int mainOeuv;
    int tempOp;
    char op[20];
    L =(liste)malloc(sizeof(traveuxList)); // creation de la liste
    L->longeur=0; // initialisation de la longeur de la liste

    printf("Donner le nombre de traveux a ajouter: ");
    scanf("%d", &n);
//Question 2!!
    if (L->longeur==0) // initialisation de la liste avec un noeud
    {
        L->tete=(traveux*)malloc(sizeof(traveux));  //allocation de memoire pour un seul noeud
        printf("Donner le numero du premier traveux: ");
        scanf("%d", &num); // premier numero pas besoin d'etre verifier
        fflush(stdin);
        L->tete->numero = num; // affectation du numero dans le noeud

        printf("Donner le code d'operation: ");
        fflush(stdin);
        gets(L->tete->codeOp); //affection du code d'operation dans le noeud

        do
        {
            printf("Donner le cout de ce traveux: ");
            fflush(stdin);
            scanf("%f",&cout);
        }
        while(cout<=0);   // verification que le cout est different de 0

        L->tete->cout = cout; //affectation du cout dans le noeud

        do
        {
            printf("Donner la main d'ouevre: ");
            fflush(stdin);
            scanf("%d",&mainOeuv);
        }
        while(mainOeuv <=0);  // verification de la main oeuvre est different de 0

        L->tete->mainOeuvre = mainOeuv; //affection de la main d'oeuvre dans le noeud

        do
        {
            printf("Donner le temps d'operation: ");
            fflush(stdin);
            scanf("%d",&tempOp); // verification du temps d'operation est different de 0

        }
        while(tempOp <=0);

        L->tete->tempsOp = tempOp; // affectation du temps operation dans le noeud

        L->tete->suiv=NULL;
        L->longeur=L->longeur+1;
        printf("____________________________\n");
    }
    P=L->tete;
    for(int i=1 ; i<n; i++)
    {
        Q=(traveux*)malloc(sizeof(traveux)); // allocation de memoire du noeud suivant

        do
        {
            printf("Donner le numero de ce traveux: ");
            fflush(stdin);
            scanf("%d", &num);
            ptr = L->tete; // ptr pour parcourir la liste et de verifier si le numero existe deja ou pas
            b=0;    // b prend 0 s'il n'existe pas, 1 s'il existe
            do
            {
                if(ptr->numero == num)
                {
                    b=1;
                }
                else
                {
                    if(ptr->suiv != NULL)
                    {
                        ptr = ptr->suiv;
                    }
                    else
                    {
                        b=0;
                        ptr = NULL;
                    }
                }
            }
            while((ptr != NULL) && (b != 1));
        }
        while(b==1);

        Q->numero = num; // affectation du numero dans le noeud

        printf("Donner le code d'operation: ");
        fflush(stdin);
        gets(Q->codeOp); //affection du code d'operation dans le noeud

        do
        {
            printf("Donner le cout de ce traveux: ");
            fflush(stdin);
            scanf("%f",&cout);
        }
        while(cout<=0);   // verification que le cout est different de 0

        Q->cout = cout; //affectation du cout dans le noeud

        do
        {
            printf("Donner la main d'ouevre: ");
            fflush(stdin);
            scanf("%d",&mainOeuv);
        }
        while(mainOeuv <=0);  // verification de la main oeuvre est different de 0

        Q->mainOeuvre = mainOeuv; //affection de la main d'oeuvre dans le noeud

        do
        {
            printf("Donner le temps d'operation: ");
            fflush(stdin);
            scanf("%d",&tempOp); // verification du temps d'operation est different de 0

        }
        while(tempOp <=0);

        Q->tempsOp = tempOp; // affectation du temps operation dans le noeud7
        Q->suiv = NULL;

        ptr = L->tete; // pour parcourir la liste est choisir le bon emplacement

        b=0;        // noeud ajouté
        do
        {
            if( (strcasecmp(ptr->codeOp,Q->codeOp) ==0) && (ptr->suiv != NULL))  // comparer le noeud actuel et verifier s'il existe un autre ou pas
            {
                if(ptr->suiv->codeOp == Q->codeOp)      // si le noeud suivant a le meme code d'op on avance
                {
                    ptr = ptr->suiv;
                }
                else        // sinon on affecte ce noeud
                {
                    K = ptr->suiv;      // pour sauvgarder le suivant
                    ptr->suiv = Q;      // affecter le noeud a son emplacement
                    Q->suiv = K;        // le suivant de ce noeud doit avoir le noeud sauvgarder pour garantir que la liste ne pert pas
                    b=1;                // noeud ajouté
                    L->longeur=L->longeur+1;
                }
            }
            else if( strcasecmp(ptr->codeOp,Q->codeOp)==0 && ptr->suiv == NULL)   // si le noeud suivant est null on affecte directement
            {
                ptr->suiv = Q;
                L->longeur=L->longeur+1;
                b=1;
            }
            else if(strcasecmp(ptr->codeOp,Q->codeOp) !=0 && ptr->suiv ==NULL)  // si le noeud actuel n'a pas le meme code d'op et il n'existe pas un autre noeud
            {
                ptr->suiv = Q;
                L->longeur=L->longeur+1;                    // on affecte le noeud a la fin de la liste
                b=1;
            }
            else if(strcasecmp(ptr->codeOp,Q->codeOp) !=0 && ptr->suiv != NULL)     // sinon on avance
            {
                ptr= ptr->suiv;
            }
        }
        while((ptr != NULL)&& (b != 1));


        printf("_____________________________\n");
    }

    system("cls");  //efface le contenu de l'ecran
    do
    {
        printf(" Veuillez choisissez parmi les taches suivant : \n");
        printf(" 1. Ajouter une opération. \n");
        printf(" 2. Afficher tous les travaux. \n");
        printf(" 3. Rechercher une séquence de travaux. \n");
        printf(" 4. Afficher la liste des opérations par nature (par code opération). \n");
        printf(" 5. Modifier l’opération la plus coûteuse. \n");
        printf(" 6. Supprimer une opération. \n");
        printf(" 7. Afficher le code opératoire nécessitant le temps le plus élevé. \n");
        printf(" 8. Quitter \n");
        do
        {
            scanf("%d",&c);
        }
        while(c<1 && c>8);
        switch(c)
        {
        case 1:
            ajoutOp(L);
            break;
        case 2:
            afficheListe(L);
            break;
        case 3:
            printf("Donner la sequence que vous voulez rechercher: ");
            fflush(stdin);
            gets(op);
            rechercheSeqTrav(L->tete,op);
            break;
        case 4:
            travseqdonne(L,op);
            break;
        case 5:
            Update(L);
            break;
        case 6:
            printf("tapez l'opperation que vous voulez supprimer \n");
            scanf("%d",&pos);
            Delete(L,pos);
            break;
        case 7:
            codeaffiche(L);
            break;
        }
    }
    while(c!=8);
    printf("_____________");

}
