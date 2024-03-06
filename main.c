#include <stdio.h>
#include <stdlib.h>
void adaugarePlaylist(char nume)
{

}
void adaugareMelodie(int melodie,int numarPlaylist)
{

}
void vizualizeazaPlaylisURI()
{
  ///dupa rating
}
void vizualizeazaPlaylist(int modificare)
{

}
void stergere(int sterg)
{

}
void stergereMelodie(int melodie,int numarPlaylist)
{

}
void vizualizeazaMelodii()
{

}
int main() {
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
            int melodie;
            char nume[11];
             printf("CREAZA PLAYLIST\n");
              printf("Adauga nume playlist: ");
              scanf("%s",&nume);
              adaugarePlaylist(nume);
                   while(1==1){
                    printf("Nume: %s\n",nume);
                    printf("Adauga melodiile dorite:\n");
                    printf("1.Ceva\n");
                    printf("2.Ceva\n");
                    printf("3.Ceva\n");
                    printf("4.Ceva\n");
                    printf("5.Ceva\n");
                    printf("6.Ceva\n");
                    printf("7.Ceva\n");
                    printf("8.Inapoi\n");
                    vizualizeazaMelodii();

                   do{
                    printf("Intoduceti optiunea dorita: ");
                    scanf("%d",&melodie);
                    }while(melodie<1||melodie>8);
                     if(melodie==8)
                    {
                        system("cls");
                        break;

                    }
                    else if(melodie>=1 && melodie<=7){
                        adaugareMelodie(melodie,numarPlaylist);
                        printf("Melodia %d a fost adaugata in playlist\n",melodie);
                    }
                    system("pause");
                    system("cls");

            }

            system("pause");
        }
        else if (choice == 2){
            printf("VIZUALIZEAZA PLAYLISTURI\n");
            vizualizeazaPlaylisURI();
            system("pause");
        }
        else if (choice == 3){
           printf("STERGETI PLAYLIST: \n");
           printf("Selectati playlistul pe care doriti sa il stergeti: ");
           vizualizeazaPlaylisURI();
           int sterg;
           scanf("%d",&sterg);
           stergere(sterg);
           printf("Playlistul a %d fost sters\n",sterg);
           system("pause");

        }
        else if (choice == 5){
            exit(0);
        }
        else if (choice == 4){
                int modificare;
                while(1==1){
                    printf("MODIFICARE PLAYLIST:\n");
                    printf("1.Altceva\n");
                    printf("2.Altceva\n");
                    printf("3.Altceva\n");
                    printf("4.Altceva\n");
                    printf("5.Altceva\n");
                    printf("6.Altceva\n");
                    printf("7.Altceva\n");
                    printf("8.Inapoi\n");
                    vizualizeazaPlaylisURI();
                   do{
                    printf("Introduceti optiunea dorita: \n");
                    scanf("%d",&modificare);
                    }while(modificare<1||modificare>8);
                     if(modificare==8)
                    {
                        system("cls");
                        break;
                    }

                    else if(modificare>=1 && modificare<=7){
                            system("cls");
                        vizualizeazaPlaylist(modificare);
                        printf("Ati selectat playlistul %d pentru modificare\n",modificare);

                        while(1==1){
                        printf("Selectati modificarea dorita: \n");
                        printf("1.Stergere melodie\n");
                        printf("2.Adaugare melodie\n");
                        printf("3.Inapoi\n");
                        int dorit;
                        scanf("%d",&dorit);
                        if(dorit==3){
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
