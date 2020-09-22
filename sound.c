#include <stdlib.h>
#include <stdio.h>
#include <fmodex/fmod.h>
#include <gtk/gtk.h>


G_MODULE_EXPORT void on_btn_reset_clicked(GtkButton *button);

G_MODULE_EXPORT void on_btnEnter_clicked(GtkButton *button);
G_MODULE_EXPORT void on_btnVolumeM_clicked(GtkButton *button);
G_MODULE_EXPORT void on_btnVolumeA_clicked(GtkButton *button);
G_MODULE_EXPORT void  on_btnPause_clicked(GtkButton *button);
G_MODULE_EXPORT void on_btnRecule_clicked(GtkButton *button);
G_MODULE_EXPORT void on_btnAvance_clicked(GtkButton *button);
unsigned getCurrentPos();
int getLength();
int play=0;
G_MODULE_EXPORT void on_windows11_destroy();


FMOD_CHANNEL *channel1;
FMOD_BOOL etat;
FMOD_CHANNELGROUP *channelGroup;/*Pour regrouper la music en groupe afin de pouvoir regler le volume et autre de tout les song en meme temps*/
FMOD_SYSTEM * systemet;
FMOD_SOUND * musique;
FMOD_RESULT resultat;
float volumeMusic=1.0;


void on_btnEnter_clicked(GtkButton *button)
{
    if (play==0)
    {
        FMOD_System_Create(&systemet);
        FMOD_System_Init(systemet, 1, FMOD_INIT_NORMAL, NULL);

        /* On ouvre la musique */
        resultat = FMOD_System_CreateSound(systemet, "hype_home.mP3", FMOD_HARDWARE | FMOD_LOOP_OFF | FMOD_2D, 0, &musique);

        /* On vérifie si elle a bien été ouverte (IMPORTANT) */
        if (resultat != FMOD_OK)
        {
            fprintf(stderr, "Impossible de lire le fichier mp3\n");
            exit(EXIT_FAILURE);
        }

        /* On active la répétition de la musique à l'infini */
        FMOD_Sound_SetLoopCount(musique, -1);

        /* On joue la musique */
        FMOD_System_PlaySound(systemet, FMOD_CHANNEL_FREE, musique, 0, NULL);
        etat=1;
        /* ******** */
        FMOD_System_GetMasterChannelGroup(systemet,&channelGroup);
        FMOD_ChannelGroup_SetVolume (channelGroup, volumeMusic);/* le volume max*/

        play=1;
        /*petit algo pour determiner la duree de la musique et l'afficher ensuite*/
        int dureMin= 0;
        int dure=0;
        FMOD_Sound_GetLength(musique,&dure,FMOD_TIMEUNIT_MS);
        dure=dure/1000;
        dureMin=dure/60;
        int dureSecond=dure - (dureMin * 60);
        /* **********Fin de l'algo */



        printf("\n\n---Musique ouverte avec success !!");


        /* **Petite condition if pour reguler l'affichage de la duré de la musique ** */
        if (dureMin > 9 && dureSecond > 9)
        {
            printf("\n---Duréé -> \"%d:%d\"",dureMin,dureSecond);
        }

        if (dureMin < 10 && dureSecond > 9)
        {
            printf("\n---Duréé -> \"0%d:%d\"",dureMin,dureSecond);
        }

        if (dureMin > 9 && dureSecond < 10)
        {
            printf("\n---Duréé -> \"%d:0%d\"",dureMin,dureSecond);
        }

        if (dureMin < 10 && dureSecond < 10)
        {
            printf("\n---Duréé -> \"0%d:0%d\"",dureMin,dureSecond);
        }


    }
    else
    {

        printf("\n\n music deja lancer !!");
    }


}





/* **************CLIC SUR LE BOUTON VOLUME +*********** */

void on_btnVolumeA_clicked(GtkButton *button){
    if(volumeMusic>=0.0 || volumeMusic<=1.0){
        if(volumeMusic==1.0){
            printf("\nVolume Max atteint!");
        }
        else{
             printf("\nAugmenter volume!");
    volumeMusic+=0.1;
    FMOD_ChannelGroup_SetVolume (channelGroup, volumeMusic);}}
}


/* ************************************************** */




/* **************CLIC SUR LE BOUTON VOLUME -*********** */

void on_btnVolumeM_clicked(GtkButton *button){
    if(volumeMusic>=0.0 && volumeMusic<=1.0){
            if(volumeMusic==0.0){
            printf("\nVolume Min atteint!");
        }
        else{
            printf("\ndimunier volume!");
volumeMusic-=0.1;
    FMOD_ChannelGroup_SetVolume (channelGroup, volumeMusic);}}

}

/* ************************************************** */

/* **************CLIC SUR LE BOUTON PAUSE *********** */
 void  on_btnPause_clicked(GtkButton *button){

    FMOD_System_GetMasterChannelGroup(systemet,&channelGroup);

    if (etat==1) // Si la chanson est en pause
    {
        printf("\nlecture");
        FMOD_ChannelGroup_SetPaused(channelGroup, 0);   // On enlève la pause
        etat=0;
    }
    else if(etat==0)// Sinon, elle est en cours de lecture
    {
        printf("\nPause");
        FMOD_ChannelGroup_SetPaused(channelGroup, 1);
        etat=1;
    }// On active la pause
 }

/* ************************************************** */
/*récupérer la position courante dans le morceau courant
*/
 unsigned int getCurrentPos(){

    unsigned int tps;
    FMOD_ChannelGroup_GetChannel(channelGroup,0,&channel1);
    FMOD_Channel_GetPosition(channel1, &tps, FMOD_TIMEUNIT_MS);

    return tps;
}
/*
récupérer la durée du morceau courant
*/
 int getLength(){
    int i;
    FMOD_Sound_GetLength(musique, &i, FMOD_TIMEUNIT_MS  );
    return i;
}

/* **************CLIC SUR LE BOUTON Avancer la music  >> *********** */
void on_btnAvance_clicked(GtkButton *button){



   int c=getCurrentPos();
   unsigned int i=5000;
    int l=getLength();
    printf("\navancer --> l: %d ,c=%d!",l,c);
    if(c+i<l)
        FMOD_Channel_SetPosition(channel1, c+i,FMOD_TIMEUNIT_MS );

}
/* ************************************************** */

/* **************CLIC SUR LE BOUTON Avancer la music  >> *********** */
void on_btnRecule_clicked(GtkButton *button){



   int c=getCurrentPos();
   unsigned int i=5000;
    int l=getLength();
    printf("\nReculer --> l: %d ,c=%d!",l,c);
    if(c-i<l)
        FMOD_Channel_SetPosition(channel1, c-i,FMOD_TIMEUNIT_MS );

}
/* ************************************************** */

void on_windows11_destroy()
{


    FMOD_System_Close(systemet);

    FMOD_System_Release(systemet);
    gtk_main_quit();
}