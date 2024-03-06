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
void adaugarePlaylist(char nume,double Rating, int numar)
{

}
void adaugareMelodie(int melodie,int numarPlaylist)
{

}
void vizualizeazaPlaylisURI(int nr)
{
  ///dupa rating
  int i;
  for(i=0;i<nr;i++)
            printf("%d. %s,%d melodii, Rating: %.2lf\n",i+1,play[i].nume,play[i].numarMelodii,play[i].rating);
}
void vizualizeazaPlaylist(int modificare)
{
    int i;
     for(i=0;i<play[modificare].numarMelodii;i++)
        printf("%d. %s",i+1,play[modificare].melodii[i]);
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
    FILE *fm =fopen("melodiee.txt","r");
    fscanf(fm,"%d",&nr2);
    fgetc(fm);
    for(i=0;i<nr2;i++)
    {
        //fscanf(fm,"%s",MatriceMelodii[i]);
       fgets(MatriceMelodii[i],50,fm);

    }
    //printf("%s",MatriceMelodii[0]);
    for(i=0;i<nr-1;i++)
        for(j=i+1;j<nr;j++)
        if(play[i].rating<play[j].rating)
        swap(&play[i],&play[j]);
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
        do {
            printf("Introduceti varianta dorita: ");
            scanf("%d", &choice);
        } while (choice < 1 || choice > 5);

        system("cls");

        if (choice == 1){
            int melodie,numar;
            char nume[11];
            double Rating;
            nr++;
             printf("CREAZA PLAYLIST\n");
              printf("Adauga nume playlist si rating: ");
              scanf("%s",&nume);
              scanf("%lf",&Rating);
              strcpy(play[nr-1].nume,nume);
              play[nr-1].rating=Rating;
               play[nr-1].numarMelodii=0;
                   while(1==1){

                    vizualizeazaMelodii(nr2);

                   do{
                    printf("Intoduceti optiunea dorita: ");
                    scanf("%d",&melodie);
                    }while(melodie<1||melodie>nr2+1);

                     if(melodie==nr2+1)
                    {
                        system("cls");
                        break;
                    }
                    else if(melodie>=1 && melodie<nr2){
                        adaugareMelodie(melodie,nr);
                        play[nr-1].numarMelodii++;
                        printf("Melodia %d a fost adaugata in playlist\n",melodie);
                    }

                    system("pause");
                    system("cls");

            }
            adaugarePlaylist(nume,Rating,numar);

            system("pause");
        }
        else if (choice == 2){
            printf("VIZUALIZEAZA PLAYLISTURI\n");
            vizualizeazaPlaylisURI(nr);
            system("pause");
        }
        else if (choice == 3){
           printf("STERGETI PLAYLIST: \n");
           printf("Selectati playlistul pe care doriti sa il stergeti:\n");
           vizualizeazaPlaylisURI(nr);
           int sterg;
           scanf("%d",&sterg);
           stergere(sterg-1);
           printf("Playlistul %d a fost sters\n",sterg);
           system("pause");

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
                   do{
                    printf("Introduceti optiunea dorita: \n");
                    scanf("%d",&modificare);
                    }while(modificare<1||modificare>nr+1);
                     if(modificare==nr+1)
                    {
                        system("cls");
                        break;
                    }

                    else if(modificare>=1 && modificare<=nr){
                            system("cls");
                        vizualizeazaPlaylist(modificare-1);
                        printf("Ati selectat playlistul %d pentru modificare\n",modificare);
                        while(1==1){
                        printf("Selectati modificarea dorita: \n");
                        printf("1.Stergere melodie\n");
                        printf("2.Adaugare melodie\n");
                        printf("3.Modificare rating\n");
                        printf("4.Iesire\n");
                        int dorit;
                        scanf("%d",&dorit);
                        if(dorit==4){
                                break;
                                system("cls");
                        }
                       // else if(dorit==1){adaugareMelodie(,modificare)}
                        //else if(dorit==2){stergereMelodie(,modificare)}

                        }
                    }
                    system("pause");
                    system("cls");

            }

            system("pause");
        }


    }
    return 0;
}
