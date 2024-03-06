#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct playlist{
    int numarMelodii;
    double rating;
    char nume[50],melodii[101][101];
}play[101];
char MatriceMelodii[50][50];
void swap(struct playlist *a,struct playlist *b)
{
    struct playlist aux=*a;
    *a=*b;
    *b=aux;
}
void vizualizeazaPlaylisURI(int nr)
{
  ///dupa rating
  int i,j;
  if(nr==0)
    printf("Nu exista playlisturi\n");
  else{
     for(i=0;i<nr-1;i++)
        for(j=i+1;j<nr;j++)
        if(play[i].rating<play[j].rating)
        swap(&play[i],&play[j]);
  for(i=0;i<nr;i++)
            printf("%d. %s,%d melodii, Rating: %.2lf\n",i+1,play[i].nume,play[i].numarMelodii,play[i].rating);
  }
}
void vizualizeazaPlaylist(int modificare)
{
    int i;
     for(i=0;i<play[modificare].numarMelodii;i++)
        printf("%d.%s",i+1,play[modificare].melodii[i]);
}
void stergere(int sterg)
{

}
void stergereMelodie(int melodie,int numarPlaylist)
{

}
void vizualizeazaMelodii(int nr)
{
    int i;
    for(i=0;i<nr;i++)
        printf("%d.%s",i+1,MatriceMelodii[i]);
    printf("%d.Iesire\n",nr+1);

}
int main() {

    //citire din fisier +sortare dupa rating
    int nr,nr2;
    FILE* fp = fopen("playlist.txt", "r");
    fscanf(fp,"%d",&nr);
    int i,j;
    //fgetc(fp);
    for(i=0;i<nr;i++)
    {
        fscanf(fp, "%s", play[i].nume);
        fscanf(fp, "%d", &play[i].numarMelodii);
        fscanf(fp,"%lf",&play[i].rating);
        int j;
        fgetc(fp);
        for(j=0;j<play[i].numarMelodii;j++)
            //fscanf(fp,"%s",play[i].melodii[j]);
            fgets(play[i].melodii[j],50,fp);

    }
    fclose(fp);
    FILE *fm =fopen("melodiee.txt","r");
    fscanf(fm,"%d",&nr2);
    fgetc(fm);
    for(i=0;i<nr2;i++)
    {
        //fscanf(fm,"%s",MatriceMelodii[i]);
       fgets(MatriceMelodii[i],50,fm);

    }
    //printf("%s",MatriceMelodii[0]);
    fclose(fm);
    //pana aici
    int numarPlaylist;
   while (1 == 1) {
        system("cls");
        printf("    -= MENIU =-\n\n");
        printf("1. Creaza playlist\n");
        printf("2. Vizualizeaza playlisturi\n");
        printf("3. Sterge playlist\n");
        printf("4. Modificare playlist\n");
        printf("5. Iesire\n");

        int choice;
        char x[10];
        do {
            printf("Introduceti varianta dorita: ");
            scanf("%s",x);
            int sw=0;
             for(i=0;i<strlen(x);i++)
                if(x[i]<'0'||x[i]>'9')
                    sw=-1;
            if(sw==0)
                choice=atoi(x);
            else
                choice=-1;

        } while (choice < 1 || choice > 5);

        system("cls");

        if (choice == 1){
            int melodie,numar;
            char nume[11];
            double Rating;
            nr++;
             printf("CREAZA PLAYLIST\n");
              printf("Adauga nume playlist: ");
              scanf("%s",nume);
              char p[10];
              do{
                printf("Intoduceti rating cu valoarea intre 0.0 si 5.0: ");
                scanf("%s",p);
                int sw=0;
                int nrpct=0;
                for(i=0;i<strlen(p);i++)
                   if(p[i]<'0'||p[i]>'9')
                    if(p[i]!='.' || (p[i]=='.'&&nrpct>0)|| (p[i]=='.' && nrpct==0 && ((p[i-1]<'0' ||p[i-1]>'9'))||(p[i+1]<'0' ||p[i+1]>'9')))
                        sw=-1;
                    else if(p[i]=='.'&&nrpct==0)
                        nrpct++;
            if(sw==0)
                Rating=atof(p);
            else
                Rating=-1;
                }while(Rating<0||Rating>5);
              strcpy(play[nr-1].nume,nume);
              play[nr-1].rating=Rating;
               play[nr-1].numarMelodii=0;
               j=0;
                   while(1==1){
                        printf("Introduceti melodia dorita pentru adaugare:\n");

                    vizualizeazaMelodii(nr2);
                   char y[10];
                   do{
                    printf("Intoduceti optiunea dorita: ");
                    scanf("%s",y);
                    int sw=0;
                     for(i=0;i<strlen(y);i++)
                         if(y[i]<'0'||y[i]>'9')
                          sw=-1;
                    if(sw==0)
                        melodie=atoi(y);
                    else
                        melodie=-1;
                    }while(melodie<1||melodie>nr2+1);

                     if(melodie==nr2+1)
                    {
                        system("cls");
                        break;
                    }
                    else if(melodie>=1 && melodie<=nr2){
                        strcpy(play[nr-1].melodii[j],MatriceMelodii[melodie-1]);
                        play[nr-1].numarMelodii++;
                        j++;
                        printf("Melodia %d a fost adaugata in playlist\n",melodie);
                    }

                    system("pause");
                    system("cls");

                   }

            system("pause");
        }
        else if (choice == 2){
            int ceva;
            while (1==1){
            system("cls");
            printf("VIZUALIZEAZA PLAYLISTURI\n");
            vizualizeazaPlaylisURI(nr);
            printf("%d. Iesire\n",nr+1);
            do{
            printf("Introduceti numarul playlist-ului pe care doriti sa-l vizualizati: ");
            char y[10];
            scanf("%s",y);
            int sw=0;
            int i;
                for(i=0;i<strlen(y);i++)
                    if(y[i]<'0'||y[i]>'9')
                         sw=-1;
                if(sw==0)
                    ceva=atoi(y);
                else
                    ceva=-1;
                }while(ceva<1 || ceva>nr+1);
                if(ceva==nr+1)
                {
                     system("cls");
                        break;
                }
            else
                {
                system("cls");
                vizualizeazaPlaylist(ceva-1);
                system("pause");

            }
        }
        }
        else if (choice == 3){
        while(1==1){
           printf("STERGETI PLAYLIST: \n");
           printf("Selectati playlistul pe care doriti sa il stergeti:\n");
           vizualizeazaPlaylisURI(nr);
           printf("%d. Iesire\n",nr+1);
           int sterg;
           char y[10];
            do {
            printf("Introduceti varianta dorita: ");
            scanf("%s",y);
            int sw=0;
            int i;
            for(i=0;i<strlen(y);i++)
                if(y[i]<'0'||y[i]>'9')
                      sw=-1;
            if(sw==0)
                sterg=atoi(y);
            else
                sterg=-1;
        } while (sterg < 1 || sterg > nr+1);
        if(sterg==nr+1)
        {
            system("cls");
            break;
        }
        else
        {

            for(i=sterg-1;i<nr-1;i++)
                play[i]=play[i+1];
            if(nr!=0)nr--;
        }
           printf("Playlistul cu numarul %d a fost sters\n",sterg);
           system("pause");
           system("cls");

        }
    }
        else if (choice == 5){
            exit(0);
        }
        else if (choice == 4){
                int modificare;
                while(1==1){
                    printf("MODIFICARE PLAYLIST:\n");
                    vizualizeazaPlaylisURI(nr);
                    printf("%d. Iesire\n",nr+1);
                    char y[10];
                   do{
                    printf("Introduceti optiunea dorita: \n");
                    scanf("%s",y);
                    int sw=0;
                    int i;
                for(i=0;i<strlen(y);i++)
                    if(y[i]<'0'||y[i]>'9')
                         sw=-1;
                if(sw==0)
                    modificare=atoi(y);
                else
                    modificare=-1;
                    }while(modificare<1||modificare>nr+1);
                     if(modificare==nr+1)
                    {
                        system("cls");
                        break;
                    }

                    else if(modificare>=1 && modificare<=nr){
                            system("cls");
                        //vizualizeazaPlaylist(modificare-1);
                        printf("Ati selectat playlistul cu numarul %d pentru modificare\n",modificare);
                        while(1==1){
                                 system("cls");
                        printf("Selectati modificarea dorita: \n");
                        printf("1.Stergere melodie\n");
                        printf("2.Adaugare melodie\n");
                        printf("3.Modificare rating\n");
                        printf("4.Iesire\n");
                        int dorit;
                        char y[10];
                        do
                        {

                            printf("Selectie: ");
                            scanf("%s",y);
                              int sw=0;
                              int i;
                        for(i=0;i<strlen(y);i++)
                                if(y[i]<'0'||y[i]>'9')
                                        sw=-1;
                        if(sw==0)
                            dorit=atoi(y);
                        else
                            dorit=-1;
                        }while(dorit<0 || dorit >4);
                        if(dorit==4){
                                break;
                                system("cls");
                        }
                        else if(dorit==3)
                        {
                            double rating_nou;
                            char x[10];
                            do
                            {
                                printf("Introduceti un nou rating cuprins intre 0.0 si 5.0: ");
                                scanf("%s",x);
                                int sw=0;
                                int nrpct=0;
                                for(i=0;i<strlen(x);i++)
                                        if(x[i]<'0'||x[i]>'9')
                                            if(x[i]!='.' || (x[i]=='.'&&nrpct>0)|| (x[i]=='.' && nrpct==0 && ((x[i-1]<'0' ||x[i-1]>'9'))||(x[i+1]<'0' ||x[i+1]>'9')))
                                            sw=-1;
                                        else if(x[i]=='.'&&nrpct==0)
                                            nrpct++;
                                if(sw==0)
                                        rating_nou=atof(x);
                                else
                                        rating_nou=-1;

                            }while(rating_nou<0 || rating_nou>5.0);
                            play[modificare-1].rating=rating_nou;
                            printf("Rating-ul a fost modificat cu succes\n");
                            system("pause");
                            system("cls");

                        }
                       else if(dorit==2){
                           while(1==1){
                            system("cls");
                            printf("Selectati o melodie dorita pentru a o adauga in playlist:\n");
                            vizualizeazaMelodii(nr2);
                            int adaugare;
                            char y[10];
                        do
                        {

                            scanf("%s",y);
                            int sw=0;
                            int i;
                             for(i=0;i<strlen(y);i++)
                                    if(y[i]<'0'||y[i]>'9')
                                        sw=-1;
                                if(sw==0)
                                        adaugare=atoi(y);
                                else
                                        adaugare=-1;
                        }while(adaugare<0 || adaugare>nr2+1);
                        if(adaugare==nr2+1)
                        {
                            system("cls");
                            break;

                        }
                        else if(adaugare>=1 && adaugare<=nr2){
                        strcpy(play[modificare-1].melodii[play[modificare-1].numarMelodii],MatriceMelodii[adaugare-1]);
                        play[modificare-1].numarMelodii++;
                        printf("Melodia %d a fost adaugata in playlist\n",adaugare);
                    }
                       system("pause");
                           }


                       }
                else if(dorit==1){
                     while(1==1){
                            system("cls");
                            printf("Selectati melodia pe care doriti sa o stergeti:\n");
                            vizualizeazaPlaylist(modificare-1);
                            printf("%d.Iesire\n",play[modificare-1].numarMelodii+1);
                            int stergere2;
                            char y[10];
                            do
                            {
                                printf("Selectie: ");
                                scanf("%s",y);
                                int sw=0;
                                int i;
                                 for(i=0;i<strlen(y);i++)
                                        if(y[i]<'0'||y[i]>'9')
                                           sw=-1;
                                 if(sw==0)
                                        stergere2=atoi(y);
                                 else
                                        stergere2=-1;
                            }while(stergere2<0 || stergere2 >play[modificare-1].numarMelodii+1);
                            if(stergere2==play[modificare-1].numarMelodii+1)
                            {
                                system("cls");
                                break;
                            }
                            else
                            {
                                for(i=stergere2-1;i<play[modificare-1].numarMelodii-1;i++)
                                    strcpy(play[modificare-1].melodii[i],play[modificare-1].melodii[i+1]);
                                if(play[modificare-1].numarMelodii!=0)
                                    play[modificare-1].numarMelodii--;

                            }
                    printf("Melodia cu numarul %d a fost stearsa\n",stergere2);
                    system("pause");
                    system("cls");



            }
        }

    }
}
                    system("pause");
                    system("cls");

            }

            system("pause");
        }

    FILE* fp= fopen("playlist.txt","w");

    fprintf(fp,"%d\n",nr);
    for(i=0;i<nr;i++)
    {fprintf(fp,"%s %d %.2lf\n", play[i].nume,play[i].numarMelodii,play[i].rating);
    for(j=0;j<play[i].numarMelodii;j++)
        fprintf(fp,"%s",play[i].melodii[j]);
    }


    fclose(fp);


    }
    return 0;
}
