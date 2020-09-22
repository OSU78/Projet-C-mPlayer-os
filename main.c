#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include <mysql/mysql.h>
#include <fmodex/fmod.h>

char UserPseudo[36];
char PlaylistName[36];
char UserMdp[36];
char* uleader;
int uleader2;
MYSQL *mysql;
MYSQL_RES *res;
MYSQL_ROW row;
char sql_cmd[1024];
char gamebtn1;
char gamebtn2;
char gamebtn3;
char gamebtn4;
char question[50];
int uscore = 0;
char uscore_end[36];
char filename2[36];
char FileFolder[255];
int fileExist=0;
int etatListePl=0;

GtkWidget *Gtk_entryName;
GtkWidget *btnConnect;
GtkWidget *lbl_error;
GtkWidget *Gtk_entryMdp;
GtkWidget *lbl_Question;
GtkWidget *lbl_result;
GtkWidget *lbl_Question2;
GtkWidget *lbl_result2;
GtkWidget *lbl_Question3;
GtkWidget *lbl_result3;
GtkWidget *lbl_endmsg;
GtkWidget *btn1;
GtkWidget *btn2;
GtkWidget *btn3;
GtkWidget *btn4;
GtkWidget *btninst1;
GtkWidget *btninst2;
GtkWidget *btninst3;
GtkWidget *btninst4;
GtkWidget *btnblind1;
GtkWidget *btnblind2;
GtkWidget *btnblind3;
GtkWidget *btnblind4;

GtkWidget       *Gtk_entryNamePl ;
GtkWidget      *btn_CreatePl ;
GtkWidget      *lbl_ReponsePl;
GtkWidget      *btn_Quit12;
GtkWidget       *fileOpen;
GtkWidget       * lbl_reponseFile;

//
GtkWidget       *Gtk_entryNamePl ;
GtkWidget      *btn_CreatePl ;
GtkWidget      *lbl_ReponsePl;
GtkWidget      *btn_Quit12;
GtkWidget       *fileOpen;
GtkWidget       * lbl_reponseFile;
GtkWidget       *textbuffer1;
GtkWidget       *btn_AddToPL;
GtkWidget       *lbl_reponsePl2;
GtkWidget      *btn_Quit13;
GtkWidget      *hboxPl ;
GtkWidget      *Btn_CreatePlRC;
GtkWidget      *btn_listeSoundOnPl;
GtkWidget      *lbl_ReponsePl3;
GtkWidget      * btn_readPL;
GtkWidget      * hbox2;
G_MODULE_EXPORT void on_Gtk_AddToPL_activate(GtkMenuItem *menuitem);
G_MODULE_EXPORT void on_btn_FileChoose_file_set(GtkFileChooserButton *f);
G_MODULE_EXPORT void on_btn_CreatePlaylist_clicked(GtkButton *button);
G_MODULE_EXPORT void on_lbl_CreateNewPlaylist_activate(GtkMenuItem *menuitem);
G_MODULE_EXPORT void on_btn_AddTothePl_clicked(GtkButton *button);
G_MODULE_EXPORT void on_btn_GetPlExist_clicked(GtkButton *button);
G_MODULE_EXPORT void on_btn_readPL_clicked(GtkButton *button);
//

G_MODULE_EXPORT void on_btn_FileChoose_file_set(GtkFileChooserButton *f);

G_MODULE_EXPORT void on_click_new(GtkLabel *label);
G_MODULE_EXPORT void on_window_main_destroy();
G_MODULE_EXPORT void on_Gtk_entryMdp_changed();
G_MODULE_EXPORT void on_Gtk_entryName_changed();
G_MODULE_EXPORT void on_btn_reset_clicked(GtkButton *button);
G_MODULE_EXPORT void on_btnConnect_clicked(GtkButton *button);
G_MODULE_EXPORT void on_btnConnect_clicked2(GtkButton *button);
G_MODULE_EXPORT void on_click_games(GtkImageMenuItem *ImageMenuItem);
G_MODULE_EXPORT void on_click_back(GtkLabel *Label);
G_MODULE_EXPORT void on_click_culture(GtkLabel* label);
G_MODULE_EXPORT void on_click_instrument(GtkLabel* label);
G_MODULE_EXPORT void on_click_blindtest(GtkLabel* label);
G_MODULE_EXPORT void on_click_back2(GtkLabel* label);
G_MODULE_EXPORT void on_click_back3(GtkLabel* label);
G_MODULE_EXPORT void on_click_back4(GtkLabel* label);
G_MODULE_EXPORT void on_click_back5(GtkLabel* label);
G_MODULE_EXPORT void on_click_back6(GtkLabel* label);
G_MODULE_EXPORT void on_click_back7(GtkLabel* label);
G_MODULE_EXPORT void on_click_back8(GtkLabel* label);
G_MODULE_EXPORT void on_click_tryagain(GtkLabel* label);
G_MODULE_EXPORT void on_click_tryagain2(GtkLabel* label);
G_MODULE_EXPORT void on_click_tryagain3(GtkLabel* label);
G_MODULE_EXPORT void on_btn1_clicked(GtkButton *button);
G_MODULE_EXPORT void on_btn2_clicked(GtkButton *button);
G_MODULE_EXPORT void on_btn3_clicked(GtkButton *button);
G_MODULE_EXPORT void on_btn4_clicked(GtkButton *button);
G_MODULE_EXPORT void on_btninst1_clicked(GtkButton *button);
G_MODULE_EXPORT void on_btninst2_clicked(GtkButton *button);
G_MODULE_EXPORT void on_btninst3_clicked(GtkButton *button);
G_MODULE_EXPORT void on_btninst4_clicked(GtkButton *button);
G_MODULE_EXPORT void on_btnblind1_clicked(GtkButton *button);
G_MODULE_EXPORT void on_btnblind2_clicked(GtkButton *button);
G_MODULE_EXPORT void on_btnblind3_clicked(GtkButton *button);
G_MODULE_EXPORT void on_btnblind4_clicked(GtkButton *button);


//Music

G_MODULE_EXPORT void on_btn_reset_clicked(GtkButton *button);
G_MODULE_EXPORT void on_btnEnter_clicked(GtkButton *button);
G_MODULE_EXPORT void  on_btnPause_clicked(GtkButton *button);
G_MODULE_EXPORT void on_btnRecule_clicked(GtkButton *button);
G_MODULE_EXPORT void on_btnAvance_clicked(GtkButton *button);
G_MODULE_EXPORT  void on_btn_Quit13_clicked(GtkButton *button);
G_MODULE_EXPORT  void on_btn_Quit12_clicked(GtkButton *button);
G_MODULE_EXPORT void on_lbl_CreateNewPlaylist_activate(GtkMenuItem *menuitem);
G_MODULE_EXPORT void on_lbl_LookPlaylist_activate(GtkMenuItem *menuitem);
gboolean timer_handler(GtkWidget *timer);
gboolean ZicTime(GtkWidget *lblTimef);
G_MODULE_EXPORT void inc_progress();
G_MODULE_EXPORT void on_volumeBtn_value_changed(GtkVolumeButton *v1);
unsigned int getCurrentPos();
int getLength();
int play=0;
int dureMin= 0;
int dure=0;
char MusicTimeTotal[10];/*Dans cette variable sera stocker le temps total de la music sous forme mn:seconde*/
G_MODULE_EXPORT void on_windows11_destroy();
int posAct;

FMOD_CHANNEL *channel1;
FMOD_BOOL etat;
FMOD_CHANNELGROUP *channelGroup;/*Pour regrouper la music en groupe afin de pouvoir regler le volume et autre de tout les song en meme temps*/
FMOD_SYSTEM * systemet;
FMOD_SOUND * musique;
FMOD_RESULT resultat;
float volumeMusic = 1.0;
float volumeMusicGame;

int erreurPl=0;
char sql_cmd2[1024];
int pLexist=0;
char PlName[36];
char tabMusic[256][256]= {0};
int j=0;
//Music

GtkWidget *window2Playlist;
GtkWidget *window3ListPlaylist;
GtkWidget *timer;
GtkWidget *volumeBtn;
GtkWidget *lblTime;
GtkWidget *lbl_CreateNewPlaylist;
GtkWidget *lbl_LookPlaylist;
GtkWidget *prog1;/*progress bar*/
/* ************ */


GtkBuilder      *builder;
GtkWidget       *window;
GtkWidget       *window2;
GtkWidget       *window3;
GtkWidget       *window4;
GtkWidget       *window5;
GtkWidget       *window6;
GtkWidget       *window7;
GtkWidget       *window8;
GtkWidget       *window9;
GtkWidget       *window10;



FILE* fp;
char VolumeGameMusic2[20];
char height[20];
char width[20];

int main(int argc, char *argv[]){
    /*system("pause");*/
    fp = fopen("project.conf", "r");
    if (fp == NULL) return 1;
    char* tmp;
    int f = 0;
    char c;
	int count = 0;
	//we place character by character into our arrays.
	while((c = fgetc(fp)) != EOF){
        if(count == 5 && c != ' '){
	    tmp = c;
	    VolumeGameMusic2[f] = tmp;
	    f++;
	}
        if(count == 7)f=0;
        if(count == 8 && c != ' ' ){
        tmp = c;
	    height[f] = tmp;
	    f++;
    }
    if(count == 9)f=0;
    if(count == 10 && c != ' '){
        tmp = c;
	    width[f] = tmp;
	    f++;
    }

		if(c == ' ' || c == '\n'){
			++count;
		}
	}
	printf("%s", VolumeGameMusic2);
    printf("%s", height);
	printf("%s\n", width);
	volumeMusicGame = atof(VolumeGameMusic2);
	printf("%f", volumeMusicGame);

	fclose(fp);


    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "login2-0.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "windows1"));
    gtk_builder_connect_signals(builder, NULL);

    // get pointers to the two labels
    Gtk_entryName = GTK_WIDGET(gtk_builder_get_object(builder, "Gtk_entryName"));
    btnConnect = GTK_WIDGET(gtk_builder_get_object(builder, "btnConnect"));
    Gtk_entryMdp = GTK_WIDGET(gtk_builder_get_object(builder, "Gtk_entryMdp"));
    lbl_error = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_error"));

gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER_ALWAYS);
    /**/
     gtk_builder_connect_signals(builder, NULL);

    g_object_unref(builder);

    /*on affiche notre fenetre (window)*/
    gtk_widget_show(window);
    gtk_main();


    return 0;
}

// called when button is clicked
void on_btnConnect_clicked(GtkButton *button)
{


    //const gchar* str_text=gtk_label_get_text (GTK_LABEL(lblName));

    /* On stocke le pseudo dans la variable UserPseudo*/
    sprintf(UserPseudo,"%s",gtk_entry_get_text(Gtk_entryName));
     sprintf(UserMdp,"%s",gtk_entry_get_text(Gtk_entryMdp));

     /* Une fois qu'on a stocker les infos de login dans les variables tout est possible
     (je parle bien sur de l'insertion ou la verification dans la bdd)*/

    printf("\n---Info Connexion :");
    printf("\n--User Pseudo : %s",UserPseudo);
     printf("\n--User Pseudo : %s\n",UserMdp);

     /*Vérification log_in SQL*/

    mysql = mysql_init(NULL);
    mysql_options(mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    if(mysql_real_connect(mysql,"localhost","root","","C_PROJECT",3308,NULL,0)) {
        sprintf(sql_cmd,"SELECT * FROM user WHERE username = '%s' AND password = '%s'", UserPseudo, UserMdp);
        printf("%s\n", sql_cmd);
        if(mysql_query(mysql, sql_cmd)){
            fprintf(stderr, "%s\n", mysql_error(mysql));
            printf("\nAn error occured!\n");
            mysql_close(mysql);
            exit(1);
        }
         res = mysql_store_result(mysql);
        /* output table name */

        if(mysql_num_rows(res) == 0){
        printf("\nThe username or password you entered are wrong!\n\n");
        gtk_label_set_text(lbl_error, "The username or password you entered are wrong!");
    }
        else{
        printf("MySQL Data:\n");
        while ((row = mysql_fetch_row(res)) != NULL){
        printf("%s %s \n", row[0], row[1]);
        }
        printf("\nWelcome %s", UserPseudo);
            builder = gtk_builder_new();
            gtk_builder_add_from_file (builder, "index2-0.glade", NULL);


            window3 = GTK_WIDGET(gtk_builder_get_object(builder, "windows11"));
            gtk_builder_connect_signals(builder, NULL);


            volumeBtn = GTK_WIDGET(gtk_builder_get_object(builder, "volumeBtn"));
            prog1 = GTK_WIDGET(gtk_builder_get_object(builder, "prog1"));
            timer = GTK_WIDGET(gtk_builder_get_object(builder, "timer"));
            lblTime=GTK_WIDGET(gtk_builder_get_object(builder, "lblTime"));
            lbl_CreateNewPlaylist=GTK_WIDGET(gtk_builder_get_object(builder, "lbl_CreateNewPlaylist"));
            lbl_LookPlaylist=GTK_WIDGET(gtk_builder_get_object(builder, "lbl_LookPlaylist"));
            fileOpen=GTK_WIDGET(gtk_builder_get_object(builder, "fileOpen"));
            lbl_reponseFile=GTK_WIDGET(gtk_builder_get_object(builder, "lbl_reponseFile"));

            gtk_window_set_position(GTK_WINDOW(window3), GTK_WIN_POS_CENTER_ALWAYS);

             guint ID=g_timeout_add_seconds(1,(GSourceFunc)timer_handler,timer);
             guint IDT=g_timeout_add_seconds(1,(GSourceFunc)ZicTime,lblTime);

            /**/
            gtk_builder_connect_signals(builder, NULL);


            g_object_unref(builder);

            /*on affiche notre fenetre (window)*/
            gtk_widget_show(window3);
            /*on ferme la fenetre précédente*/
            gtk_widget_destroy(window);




        }

           /* close connection */
        mysql_free_result(res);
        mysql_close(mysql);
    } else {
        printf("\nConnection Error !");
     }
}
void on_click_new(GtkLabel *label){
            builder = gtk_builder_new();
            gtk_builder_add_from_file (builder, "signup.glade", NULL);


            window2 = GTK_WIDGET(gtk_builder_get_object(builder, "windows1"));
            gtk_builder_connect_signals(builder, NULL);

            // get pointers to the two labels
            Gtk_entryName = GTK_WIDGET(gtk_builder_get_object(builder, "Gtk_entryName"));
            btnConnect = GTK_WIDGET(gtk_builder_get_object(builder, "btnConnect"));
            Gtk_entryMdp = GTK_WIDGET(gtk_builder_get_object(builder, "Gtk_entryMdp"));
            lbl_error = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_error"));

    gtk_window_set_position(GTK_WINDOW(window2), GTK_WIN_POS_CENTER_ALWAYS);


            /**/
            gtk_builder_connect_signals(builder, NULL);


            g_object_unref(builder);

            /*on affiche notre fenetre (window)*/
            gtk_widget_show(window2);
            /*on ferme la fenetre précédente*/
            gtk_widget_destroy(window);

}

void on_btnConnect_clicked2(GtkButton *button){

    /* On stocke le pseudo dans la variable UserPseudo*/
    sprintf(UserPseudo,"%s",gtk_entry_get_text(Gtk_entryName));
     sprintf(UserMdp,"%s",gtk_entry_get_text(Gtk_entryMdp));

     /* Une fois qu'on a stocker les infos de login dans les variables tout est possible
     (je parle bien sur de l'insertion ou la verification dans la bdd)*/

    printf("\n---Info Connexion :");
    printf("\n--User Pseudo : %s",UserPseudo);
     printf("\n--User Pseudo : %s\n",UserMdp);

       /*Vérification sign_up SQL*/

    mysql = mysql_init(NULL);
    mysql_options(mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    if(mysql_real_connect(mysql,"localhost","root","","C_PROJECT",3308,NULL,0)) {
            sprintf(sql_cmd,"INSERT INTO user(username, password) VALUES ('%s', '%s')", UserPseudo, UserMdp);
        printf("%s\n", sql_cmd);
        if(mysql_query(mysql, sql_cmd)){
            printf("\nThat username is already taken, choose another!\n");
            gtk_label_set_text(lbl_error, "That username is already taken, choose another!");
        }
        else{
            printf("\n Welcome %s \n", UserPseudo);
            builder = gtk_builder_new();
            gtk_builder_add_from_file (builder, "index2-0.glade", NULL);


            window3 = GTK_WIDGET(gtk_builder_get_object(builder, "windows11"));
            gtk_builder_connect_signals(builder, NULL);

            volumeBtn = GTK_WIDGET(gtk_builder_get_object(builder, "volumeBtn"));
            prog1 = GTK_WIDGET(gtk_builder_get_object(builder, "prog1"));
            timer = GTK_WIDGET(gtk_builder_get_object(builder, "timer"));
            lblTime=GTK_WIDGET(gtk_builder_get_object(builder, "lblTime"));
            lbl_CreateNewPlaylist=GTK_WIDGET(gtk_builder_get_object(builder, "lbl_CreateNewPlaylist"));
            lbl_LookPlaylist=GTK_WIDGET(gtk_builder_get_object(builder, "lbl_LookPlaylist"));
            lbl_reponseFile=GTK_WIDGET(gtk_builder_get_object(builder, "lbl_reponseFile"));
             fileOpen=GTK_WIDGET(gtk_builder_get_object(builder, "fileOpen"));

                gtk_window_set_position(GTK_WINDOW(window3), GTK_WIN_POS_CENTER_ALWAYS);
            /**/
             guint ID=g_timeout_add_seconds(1,(GSourceFunc)timer_handler,timer);
             guint IDT=g_timeout_add_seconds(1,(GSourceFunc)ZicTime,lblTime);

            gtk_builder_connect_signals(builder, NULL);


            g_object_unref(builder);

            /*on affiche notre fenetre (window)*/
            gtk_widget_show(window3);
            /*on ferme la fenetre précédente*/
            gtk_widget_destroy(window2);



}
}
}

// called when window is closed
void on_window_main_destroy(){
    gtk_main_quit();
}
void on_lblName_changed(GtkEntry *e){
   // sprintf(tmp,"%s",gtk_entry_get_text(e));
}
void on_btn_reset_clicked(GtkButton *button){
    //gtk_label_set_text(GTK_LABEL(lblYName), "........");
}
void on_click_games(GtkImageMenuItem *ImageMenuItem){
            builder = gtk_builder_new();
            gtk_builder_add_from_file (builder, "games.glade", NULL);


            window4 = GTK_WIDGET(gtk_builder_get_object(builder, "windows1"));
            gtk_builder_connect_signals(builder, NULL);

       gtk_window_set_position(GTK_WINDOW(window4), GTK_WIN_POS_CENTER_ALWAYS);
            gtk_builder_connect_signals(builder, NULL);


            g_object_unref(builder);

            /*if(strcmp(color == "red")){
                PangoAttrColor =
            }*/

            /*on affiche notre fenetre (window)*/
            gtk_widget_show(window4);
            /*on ferme la fenetre précédente*/
            gtk_widget_hide(window3);

}
void on_click_back(GtkLabel *Label){
            builder = gtk_builder_new();
            gtk_builder_add_from_file (builder, "index2-0.glade", NULL);


            window3 = GTK_WIDGET(gtk_builder_get_object(builder, "windows11"));
            gtk_builder_connect_signals(builder, NULL);

            /**/
            gtk_builder_connect_signals(builder, NULL);

         volumeBtn = GTK_WIDGET(gtk_builder_get_object(builder, "volumeBtn"));
            prog1 = GTK_WIDGET(gtk_builder_get_object(builder, "prog1"));
            timer = GTK_WIDGET(gtk_builder_get_object(builder, "timer"));
            lblTime=GTK_WIDGET(gtk_builder_get_object(builder, "lblTime"));
            lbl_CreateNewPlaylist=GTK_WIDGET(gtk_builder_get_object(builder, "lbl_CreateNewPlaylist"));
            lbl_LookPlaylist=GTK_WIDGET(gtk_builder_get_object(builder, "lbl_LookPlaylist"));
            fileOpen=GTK_WIDGET(gtk_builder_get_object(builder, "fileOpen"));
            lbl_reponseFile=GTK_WIDGET(gtk_builder_get_object(builder, "lbl_reponseFile"));

            gtk_window_set_position(GTK_WINDOW(window3), GTK_WIN_POS_CENTER_ALWAYS);

             guint ID=g_timeout_add_seconds(1,(GSourceFunc)timer_handler,timer);
             guint IDT=g_timeout_add_seconds(1,(GSourceFunc)ZicTime,lblTime);
            g_object_unref(builder);
            /*on affiche notre fenetre (window)*/
            gtk_widget_show(window3);
            /*on ferme la fenetre précédente*/
            gtk_widget_destroy(window4);
}
void on_click_culture(GtkLabel* label){
            builder = gtk_builder_new();
            gtk_builder_add_from_file (builder, "culture.glade", NULL);


            window5 = GTK_WIDGET(gtk_builder_get_object(builder, "windows1"));
            gtk_builder_connect_signals(builder, NULL);

            // get pointers to the labels
            lbl_Question = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_Question"));
            lbl_result = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_Result"));
            btn1 = GTK_WIDGET(gtk_builder_get_object(builder, "btn1"));
            btn2 = GTK_WIDGET(gtk_builder_get_object(builder, "btn2"));
            btn3 = GTK_WIDGET(gtk_builder_get_object(builder, "btn3"));
            btn4 = GTK_WIDGET(gtk_builder_get_object(builder, "btn4"));

        gtk_window_set_position(GTK_WINDOW(window5), GTK_WIN_POS_CENTER_ALWAYS);


            /**/
            gtk_builder_connect_signals(builder, NULL);
            gtk_label_set_text(lbl_Question, "What is the most viewed music on Youtube?");
            gtk_button_set_label(btn1, "Despacito");
            gtk_button_set_label(btn2, "Gangnam Style");
            gtk_button_set_label(btn3, "Rockstar");
            gtk_button_set_label(btn4, "Shape of You");

            g_object_unref(builder);
            /*on affiche notre fenetre (window)*/
            gtk_widget_show(window5);
            /*on ferme la fenetre précédente*/
            gtk_widget_destroy(window4);

}
void on_click_back2(GtkLabel* label){
            builder = gtk_builder_new();
            gtk_builder_add_from_file (builder, "games.glade", NULL);


            window4 = GTK_WIDGET(gtk_builder_get_object(builder, "windows1"));
            gtk_builder_connect_signals(builder, NULL);

            /**/
            gtk_builder_connect_signals(builder, NULL);
gtk_window_set_position(GTK_WINDOW(window4), GTK_WIN_POS_CENTER_ALWAYS);

            g_object_unref(builder);
            /*on affiche notre fenetre (window)*/
            gtk_widget_show(window4);
            /*on ferme la fenetre précédente*/
            gtk_widget_destroy(window5);
}
void on_click_back3(GtkLabel* label){
            builder = gtk_builder_new();
            gtk_builder_add_from_file (builder, "games.glade", NULL);


            window4 = GTK_WIDGET(gtk_builder_get_object(builder, "windows1"));
            gtk_builder_connect_signals(builder, NULL);

            uscore = 0;


            gtk_builder_connect_signals(builder, NULL);
gtk_window_set_position(GTK_WINDOW(window4), GTK_WIN_POS_CENTER_ALWAYS);

            g_object_unref(builder);
            /*on affiche notre fenetre (window)*/
            gtk_widget_show(window4);
            /*on ferme la fenetre précédente*/
            gtk_widget_destroy(window6);
}
void on_click_back4(GtkLabel* label){
            builder = gtk_builder_new();
            gtk_builder_add_from_file (builder, "games.glade", NULL);


            window4 = GTK_WIDGET(gtk_builder_get_object(builder, "windows1"));
            gtk_builder_connect_signals(builder, NULL);

            uscore = 0;

gtk_window_set_position(GTK_WINDOW(window4), GTK_WIN_POS_CENTER_ALWAYS);
            gtk_builder_connect_signals(builder, NULL);


            g_object_unref(builder);
            /*on affiche notre fenetre (window)*/
            gtk_widget_show(window4);
            /*on ferme la fenetre précédente*/
            gtk_widget_destroy(window7);
}
void on_click_back5(GtkLabel* label){
    if (play==0 ){

        FMOD_System_Close(systemet);
        FMOD_System_Create(&systemet);
        FMOD_System_Init(systemet, 1, FMOD_INIT_NORMAL, NULL);

        /* On ouvre la musique */
        /*strcpy(filename2, FileFolder);*/
        resultat = FMOD_System_CreateSound(systemet, "silence.mp3", FMOD_HARDWARE | FMOD_LOOP_OFF | FMOD_2D, 0, &musique);


        /* On active la répétition de la musique à l'infini */
        FMOD_Sound_SetLoopCount(musique, -1);

        /* On joue la musique */
        FMOD_System_PlaySound(systemet, FMOD_CHANNEL_FREE, musique, 0, NULL);
        etat=0;
          guint ID=g_timeout_add_seconds(1,(GSourceFunc)timer_handler,timer);
        /*la variable guint IDT pour appeler la fonction ZicTime chaque seconde et donne
        en parametre le variable lblTime qui stocke le currentTime de la music et
        comme la fonction est appeler chaque seconde alors lblTime va changer chaque
        seconde egalement en fonction du current time );*/
        guint IDT=g_timeout_add_seconds(1,(GSourceFunc)ZicTime,lblTime);

        gtk_scale_button_set_value(GTK_SCALE_BUTTON(volumeBtn),1.0);
        /* ******** */
        FMOD_System_GetMasterChannelGroup(systemet,&channelGroup);
        FMOD_ChannelGroup_SetVolume (channelGroup, volumeMusic);/* le volume max*/

        play=0;

        }
            builder = gtk_builder_new();
            gtk_builder_add_from_file (builder, "games.glade", NULL);


            window4 = GTK_WIDGET(gtk_builder_get_object(builder, "windows1"));
            gtk_builder_connect_signals(builder, NULL);

            uscore = 0;
        gtk_window_set_position(GTK_WINDOW(window4), GTK_WIN_POS_CENTER_ALWAYS);
            gtk_builder_connect_signals(builder, NULL);


            g_object_unref(builder);
            /*on affiche notre fenetre (window)*/
            gtk_widget_show(window4);
            /*on ferme la fenetre précédente*/
            gtk_widget_destroy(window8);
}
void on_click_back6(GtkLabel* label){
    if (play==0 ){

        FMOD_System_Close(systemet);
        FMOD_System_Create(&systemet);
        FMOD_System_Init(systemet, 1, FMOD_INIT_NORMAL, NULL);

        /* On ouvre la musique */
        /*strcpy(filename2, FileFolder);*/
        resultat = FMOD_System_CreateSound(systemet, "silence.mp3", FMOD_HARDWARE | FMOD_LOOP_OFF | FMOD_2D, 0, &musique);


        /* On active la répétition de la musique à l'infini */
        FMOD_Sound_SetLoopCount(musique, -1);

        /* On joue la musique */
        FMOD_System_PlaySound(systemet, FMOD_CHANNEL_FREE, musique, 0, NULL);
        etat=0;
          guint ID=g_timeout_add_seconds(1,(GSourceFunc)timer_handler,timer);
        /*la variable guint IDT pour appeler la fonction ZicTime chaque seconde et donne
        en parametre le variable lblTime qui stocke le currentTime de la music et
        comme la fonction est appeler chaque seconde alors lblTime va changer chaque
        seconde egalement en fonction du current time );*/
        guint IDT=g_timeout_add_seconds(1,(GSourceFunc)ZicTime,lblTime);

        gtk_scale_button_set_value(GTK_SCALE_BUTTON(volumeBtn),1.0);
        /* ******** */
        FMOD_System_GetMasterChannelGroup(systemet,&channelGroup);
        FMOD_ChannelGroup_SetVolume (channelGroup, volumeMusic);/* le volume max*/

        play=0;

        }
            builder = gtk_builder_new();
            gtk_builder_add_from_file (builder, "games.glade", NULL);


            window4 = GTK_WIDGET(gtk_builder_get_object(builder, "windows1"));
            gtk_builder_connect_signals(builder, NULL);

            uscore = 0;
            gtk_window_set_position(GTK_WINDOW(window4), GTK_WIN_POS_CENTER_ALWAYS);
            gtk_builder_connect_signals(builder, NULL);


            g_object_unref(builder);
            /*on affiche notre fenetre (window)*/
            gtk_widget_show(window4);
            /*on ferme la fenetre précédente*/
            gtk_widget_destroy(window9);
}
void on_click_back7(GtkLabel* label){
    if (play==0 ){

        FMOD_System_Close(systemet);
        FMOD_System_Create(&systemet);
        FMOD_System_Init(systemet, 1, FMOD_INIT_NORMAL, NULL);

        /* On ouvre la musique */
        /*strcpy(filename2, FileFolder);*/
        resultat = FMOD_System_CreateSound(systemet, "silence.mp3", FMOD_HARDWARE | FMOD_LOOP_OFF | FMOD_2D, 0, &musique);


        /* On active la répétition de la musique à l'infini */
        FMOD_Sound_SetLoopCount(musique, -1);

        /* On joue la musique */
        FMOD_System_PlaySound(systemet, FMOD_CHANNEL_FREE, musique, 0, NULL);
        etat=0;
          guint ID=g_timeout_add_seconds(1,(GSourceFunc)timer_handler,timer);
        /*la variable guint IDT pour appeler la fonction ZicTime chaque seconde et donne
        en parametre le variable lblTime qui stocke le currentTime de la music et
        comme la fonction est appeler chaque seconde alors lblTime va changer chaque
        seconde egalement en fonction du current time );*/
        guint IDT=g_timeout_add_seconds(1,(GSourceFunc)ZicTime,lblTime);

        gtk_scale_button_set_value(GTK_SCALE_BUTTON(volumeBtn),1.0);
        /* ******** */
        FMOD_System_GetMasterChannelGroup(systemet,&channelGroup);
        FMOD_ChannelGroup_SetVolume (channelGroup, volumeMusic);/* le volume max*/

        play=0;

        }
            builder = gtk_builder_new();
            gtk_builder_add_from_file (builder, "games.glade", NULL);


            window4 = GTK_WIDGET(gtk_builder_get_object(builder, "windows1"));
            gtk_builder_connect_signals(builder, NULL);

            uscore = 0;
            gtk_window_set_position(GTK_WINDOW(window4), GTK_WIN_POS_CENTER_ALWAYS);
            gtk_builder_connect_signals(builder, NULL);


            g_object_unref(builder);
            /*on affiche notre fenetre (window)*/
            gtk_widget_show(window4);
            /*on ferme la fenetre précédente*/
            gtk_widget_destroy(window10);
}
void on_click_back8(GtkLabel* label){
    if (play==0 ){

        FMOD_System_Close(systemet);
        FMOD_System_Create(&systemet);
        FMOD_System_Init(systemet, 1, FMOD_INIT_NORMAL, NULL);

        /* On ouvre la musique */
        /*strcpy(filename2, FileFolder);*/
        resultat = FMOD_System_CreateSound(systemet, "silence.mp3", FMOD_HARDWARE | FMOD_LOOP_OFF | FMOD_2D, 0, &musique);


        /* On active la répétition de la musique à l'infini */
        FMOD_Sound_SetLoopCount(musique, -1);

        /* On joue la musique */
        FMOD_System_PlaySound(systemet, FMOD_CHANNEL_FREE, musique, 0, NULL);
        etat=0;
          guint ID=g_timeout_add_seconds(1,(GSourceFunc)timer_handler,timer);
        /*la variable guint IDT pour appeler la fonction ZicTime chaque seconde et donne
        en parametre le variable lblTime qui stocke le currentTime de la music et
        comme la fonction est appeler chaque seconde alors lblTime va changer chaque
        seconde egalement en fonction du current time );*/
        guint IDT=g_timeout_add_seconds(1,(GSourceFunc)ZicTime,lblTime);

        gtk_scale_button_set_value(GTK_SCALE_BUTTON(volumeBtn),1.0);
        /* ******** */
        FMOD_System_GetMasterChannelGroup(systemet,&channelGroup);
        FMOD_ChannelGroup_SetVolume (channelGroup, volumeMusic);/* le volume max*/

        play=0;

        }
            builder = gtk_builder_new();
            gtk_builder_add_from_file (builder, "games.glade", NULL);


            window4 = GTK_WIDGET(gtk_builder_get_object(builder, "windows1"));
            gtk_builder_connect_signals(builder, NULL);

            uscore = 0;
            gtk_window_set_position(GTK_WINDOW(window4), GTK_WIN_POS_CENTER_ALWAYS);
            gtk_builder_connect_signals(builder, NULL);


            g_object_unref(builder);
            /*on affiche notre fenetre (window)*/
            gtk_widget_show(window4);
            /*on ferme la fenetre précédente*/
            gtk_widget_destroy(window7);
}

void on_click_tryagain(GtkLabel* label){
            builder = gtk_builder_new();
            gtk_builder_add_from_file (builder, "culture.glade", NULL);


            window5 = GTK_WIDGET(gtk_builder_get_object(builder, "windows1"));
            gtk_builder_connect_signals(builder, NULL);

                     // get pointers to the labels
            lbl_Question = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_Question"));
            lbl_result = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_Result"));
            btn1 = GTK_WIDGET(gtk_builder_get_object(builder, "btn1"));
            btn2 = GTK_WIDGET(gtk_builder_get_object(builder, "btn2"));
            btn3 = GTK_WIDGET(gtk_builder_get_object(builder, "btn3"));
            btn4 = GTK_WIDGET(gtk_builder_get_object(builder, "btn4"));
gtk_window_set_position(GTK_WINDOW(window5), GTK_WIN_POS_CENTER_ALWAYS);

            uscore = 0;
            gtk_builder_connect_signals(builder, NULL);
            gtk_label_set_text(lbl_Question, "What is the most viewed music on Youtube?");
            gtk_button_set_label(btn1, "Despacito");
            gtk_button_set_label(btn2, "Gangnam Style");
            gtk_button_set_label(btn3, "Rockstar");
            gtk_button_set_label(btn4, "Shape of You");


            gtk_builder_connect_signals(builder, NULL);


            g_object_unref(builder);
            /*on affiche notre fenetre (window)*/
            gtk_widget_show(window5);
            /*on ferme la fenetre précédente*/
            gtk_widget_destroy(window6);
}
void on_click_tryagain2(GtkLabel* label){
    if (play==0 ){

        FMOD_System_Close(systemet);
        FMOD_System_Create(&systemet);
        FMOD_System_Init(systemet, 1, FMOD_INIT_NORMAL, NULL);

        /* On ouvre la musique */
        /*strcpy(filename2, FileFolder);*/
        resultat = FMOD_System_CreateSound(systemet, "silence.mp3", FMOD_HARDWARE | FMOD_LOOP_OFF | FMOD_2D, 0, &musique);


        /* On active la répétition de la musique à l'infini */
        FMOD_Sound_SetLoopCount(musique, -1);

        /* On joue la musique */
        FMOD_System_PlaySound(systemet, FMOD_CHANNEL_FREE, musique, 0, NULL);
        etat=0;
          guint ID=g_timeout_add_seconds(1,(GSourceFunc)timer_handler,timer);
        /*la variable guint IDT pour appeler la fonction ZicTime chaque seconde et donne
        en parametre le variable lblTime qui stocke le currentTime de la music et
        comme la fonction est appeler chaque seconde alors lblTime va changer chaque
        seconde egalement en fonction du current time );*/
        guint IDT=g_timeout_add_seconds(1,(GSourceFunc)ZicTime,lblTime);

        gtk_scale_button_set_value(GTK_SCALE_BUTTON(volumeBtn),1.0);
        /* ******** */
        FMOD_System_GetMasterChannelGroup(systemet,&channelGroup);
        FMOD_ChannelGroup_SetVolume (channelGroup, volumeMusic);/* le volume max*/

        play=0;

        }
            builder = gtk_builder_new();
            gtk_builder_add_from_file (builder, "blindtest.glade", NULL);


            window8 = GTK_WIDGET(gtk_builder_get_object(builder, "windows1"));
            gtk_builder_connect_signals(builder, NULL);

            // get pointers to the labels
            lbl_Question3 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_Question3"));
            lbl_result3 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_Result3"));
            btnblind1 = GTK_WIDGET(gtk_builder_get_object(builder, "btnblind1"));
            btnblind2 = GTK_WIDGET(gtk_builder_get_object(builder, "btnblind2"));
            btnblind3 = GTK_WIDGET(gtk_builder_get_object(builder, "btnblind3"));
            btnblind4 = GTK_WIDGET(gtk_builder_get_object(builder, "btnblind4"));
            gtk_window_set_position(GTK_WINDOW(window8), GTK_WIN_POS_CENTER_ALWAYS);


            uscore = 0;
            /**/
            gtk_builder_connect_signals(builder, NULL);
            gtk_label_set_text(lbl_Question3, "What's the name of this viral song?");
            gtk_button_set_label(btnblind1, "Blue");
            gtk_button_set_label(btnblind2, "Numa Numa");
            gtk_button_set_label(btnblind3, "Dragostea din tei");
            gtk_button_set_label(btnblind4, "O-Zone");

            g_object_unref(builder);
            /*on affiche notre fenetre (window)*/
            gtk_widget_show(window8);
            /*on ferme la fenetre précédente*/
            gtk_widget_destroy(window4);


    //sound

    if (play==0 ){

        FMOD_System_Close(systemet);
        FMOD_System_Create(&systemet);
        FMOD_System_Init(systemet, 1, FMOD_INIT_NORMAL, NULL);

        /* On ouvre la musique */
        /*strcpy(filename2, FileFolder);*/
        resultat = FMOD_System_CreateSound(systemet, "numa.mp3", FMOD_HARDWARE | FMOD_LOOP_OFF | FMOD_2D, 0, &musique);


        /* On active la répétition de la musique à l'infini */
        FMOD_Sound_SetLoopCount(musique, -1);

        /* On joue la musique */
        FMOD_System_PlaySound(systemet, FMOD_CHANNEL_FREE, musique, 0, NULL);
        etat=0;
          guint ID=g_timeout_add_seconds(1,(GSourceFunc)timer_handler,timer);
        /*la variable guint IDT pour appeler la fonction ZicTime chaque seconde et donne
        en parametre le variable lblTime qui stocke le currentTime de la music et
        comme la fonction est appeler chaque seconde alors lblTime va changer chaque
        seconde egalement en fonction du current time );*/
        guint IDT=g_timeout_add_seconds(1,(GSourceFunc)ZicTime,lblTime);

        gtk_scale_button_set_value(GTK_SCALE_BUTTON(volumeBtn),1.0);
        /* ******** */
        FMOD_System_GetMasterChannelGroup(systemet,&channelGroup);
        FMOD_ChannelGroup_SetVolume (channelGroup, volumeMusicGame);/* le volume max*/

        play=0;

        }

}
void on_click_tryagain3(GtkLabel* label){
    if (play==0 ){

        FMOD_System_Close(systemet);
        FMOD_System_Create(&systemet);
        FMOD_System_Init(systemet, 1, FMOD_INIT_NORMAL, NULL);

        /* On ouvre la musique */
        /*strcpy(filename2, FileFolder);*/
        resultat = FMOD_System_CreateSound(systemet, "silence.mp3", FMOD_HARDWARE | FMOD_LOOP_OFF | FMOD_2D, 0, &musique);


        /* On active la répétition de la musique à l'infini */
        FMOD_Sound_SetLoopCount(musique, -1);

        /* On joue la musique */
        FMOD_System_PlaySound(systemet, FMOD_CHANNEL_FREE, musique, 0, NULL);
        etat=0;
          guint ID=g_timeout_add_seconds(1,(GSourceFunc)timer_handler,timer);
        /*la variable guint IDT pour appeler la fonction ZicTime chaque seconde et donne
        en parametre le variable lblTime qui stocke le currentTime de la music et
        comme la fonction est appeler chaque seconde alors lblTime va changer chaque
        seconde egalement en fonction du current time );*/
        guint IDT=g_timeout_add_seconds(1,(GSourceFunc)ZicTime,lblTime);

        gtk_scale_button_set_value(GTK_SCALE_BUTTON(volumeBtn),1.0);
        /* ******** */
        FMOD_System_GetMasterChannelGroup(systemet,&channelGroup);
        FMOD_ChannelGroup_SetVolume (channelGroup, volumeMusicGame);/* le volume max*/

        play=0;

        }
            builder = gtk_builder_new();
            gtk_builder_add_from_file (builder, "instrument.glade", NULL);


            window7 = GTK_WIDGET(gtk_builder_get_object(builder, "windows1"));
            gtk_builder_connect_signals(builder, NULL);

            // get pointers to the labels
            lbl_Question2 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_Question2"));
            lbl_result2 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_Result2"));
            btninst1 = GTK_WIDGET(gtk_builder_get_object(builder, "btninst1"));
            btninst2 = GTK_WIDGET(gtk_builder_get_object(builder, "btninst2"));
            btninst3 = GTK_WIDGET(gtk_builder_get_object(builder, "btninst3"));
            btninst4 = GTK_WIDGET(gtk_builder_get_object(builder, "btninst4"));
            gtk_window_set_position(GTK_WINDOW(window7), GTK_WIN_POS_CENTER_ALWAYS);

            uscore = 0;


            gtk_label_set_text(lbl_Question2, "What instrument is playing this\n iconic song?");
            gtk_button_set_label(btninst1, "Flute");
            gtk_button_set_label(btninst2, "Piano");
            gtk_button_set_label(btninst3, "Electric Guitar");
            gtk_button_set_label(btninst4, "Banjo");

            g_object_unref(builder);
            /*on affiche notre fenetre (window)*/
            gtk_widget_show(window7);
            /*on ferme la fenetre précédente*/
            gtk_widget_destroy(window4);


    //sound

    if (play==0 ){

        FMOD_System_Close(systemet);
        FMOD_System_Create(&systemet);
        FMOD_System_Init(systemet, 1, FMOD_INIT_NORMAL, NULL);

        /* On ouvre la musique */
        /*strcpy(filename2, FileFolder);*/
        resultat = FMOD_System_CreateSound(systemet, "TITANIC.mp3", FMOD_HARDWARE | FMOD_LOOP_OFF | FMOD_2D, 0, &musique);


        /* On active la répétition de la musique à l'infini */
        FMOD_Sound_SetLoopCount(musique, -1);

        /* On joue la musique */
        FMOD_System_PlaySound(systemet, FMOD_CHANNEL_FREE, musique, 0, NULL);
        etat=0;
          guint ID=g_timeout_add_seconds(1,(GSourceFunc)timer_handler,timer);
        /*la variable guint IDT pour appeler la fonction ZicTime chaque seconde et donne
        en parametre le variable lblTime qui stocke le currentTime de la music et
        comme la fonction est appeler chaque seconde alors lblTime va changer chaque
        seconde egalement en fonction du current time );*/
        guint IDT=g_timeout_add_seconds(1,(GSourceFunc)ZicTime,lblTime);

        gtk_scale_button_set_value(GTK_SCALE_BUTTON(volumeBtn),1.0);
        /* ******** */
        FMOD_System_GetMasterChannelGroup(systemet,&channelGroup);
        FMOD_ChannelGroup_SetVolume (channelGroup, volumeMusicGame);/* le volume max*/

        play=0;

        }

}

void on_btn1_clicked(GtkButton *button){
    sprintf(question, "%s", gtk_label_get_text(lbl_Question));
    printf("\n%s\n", question);
    if(strcmp(question, "What is the most viewed music on Youtube?" ) == 0){
       printf("\nEz");
       uscore += 10;
       printf("\n%d\n", uscore);
       gtk_label_set_text(lbl_result, "10");
       gtk_label_set_text(lbl_Question, "Who is the most followed\n Musician on Instagram?");
        gtk_button_set_label(btn1, "Beyonce");
        gtk_button_set_label(btn2, "Justin Bieber");
        gtk_button_set_label(btn3, "Ariana Grande");
        gtk_button_set_label(btn4, "Selena Gomez");
    }
    if(strcmp(question, "Who is the most followed\n Musician on Instagram?") == 0){
       printf("\nTry Again");
       score();
    }
    if(strcmp(question, "What famous US festival hosted \nover 350,000 fans in 1969?" ) == 0){
        printf("\nTry Again");
        score();
    }

    if(strcmp(question, "What's Evanescence's most popular song?") == 0){
       printf("\nTry Again");
       score();
    }
     if(strcmp(question, "What was the name of Michael Jackson's\n famous dance move?") == 0){
       printf("\nTry Again");
       score();
    }
}
void on_btn2_clicked(GtkButton *button){
    sprintf(question, "%s", gtk_label_get_text(lbl_Question));
    printf("\n%s\n", question);
    if(strcmp(question, "What is the most viewed music on Youtube?" ) == 0){
       printf("\nTry Again");
       score();
    }
    if(strcmp(question, "Who is the most followed\n Musician on Instagram?") == 0){
       printf("\nTry Again");
       score();
    }
    if(strcmp(question, "What famous US festival hosted \nover 350,000 fans in 1969?" ) == 0){
       printf("\nEz");
       uscore += 10;
       printf("\n%d\n", uscore);
       gtk_label_set_text(lbl_result, "30");
       gtk_label_set_text(lbl_Question, "What's Evanescence's most popular song?");
        gtk_button_set_label(btn1, "My Heart is Broken");
        gtk_button_set_label(btn2, "Going Under");
        gtk_button_set_label(btn3, "My Immortal");
        gtk_button_set_label(btn4, "Bring Me to Life");
    }

    if(strcmp(question, "What's Evanescence's most popular song?") == 0){
       printf("\nTry Again");
       score();
    }
     if(strcmp(question, "What was the name of Michael Jackson's\n famous dance move?") == 0){
       printf("\nTry Again");
       score();
    }
}
void on_btn3_clicked(GtkButton *button){
    sprintf(question, "%s", gtk_label_get_text(lbl_Question));
    printf("\n%s\n", question);
    if(strcmp(question, "What is the most viewed music on Youtube?" ) == 0){
       printf("\nTry Again");
       score();
    }
    if(strcmp(question, "Who is the most followed\n Musician on Instagram?") == 0){
       printf("\nEz");
       uscore += 10;
       printf("\n%d\n", uscore);
       gtk_label_set_text(lbl_result, "20");
       gtk_label_set_text(lbl_Question, "What famous US festival hosted \nover 350,000 fans in 1969?");
       gtk_button_set_label(btn1, "Tommowland");
       gtk_button_set_label(btn2, "Woodstock");
       gtk_button_set_label(btn3, "Coachella");
       gtk_button_set_label(btn4, "Lollapalooza");
    }
    if(strcmp(question, "What famous US festival hosted \nover 350,000 fans in 1969?" ) == 0){
        printf("\nTry Again");
        score();
    }
    if(strcmp(question, "What's Evanescence's most popular song?") == 0){
       printf("\nTry Again");
       score();
    }
    if(strcmp(question, "What was the name of Michael Jackson's\n famous dance move?") == 0){
       printf("\nTry Again");
       score();
    }
}
void on_btn4_clicked(GtkButton *button){
    sprintf(question, "%s", gtk_label_get_text(lbl_Question));
    printf("\n%s\n", question);
    if(strcmp(question, "What is the most viewed music on Youtube?" ) == 0){
       printf("\nTry Again");
       score();
    }
    if(strcmp(question, "Who is the most followed\n Musician on Instagram?") == 0){
       printf("\nTry Again");
       score();
    }
    if(strcmp(question, "What famous US festival hosted \nover 350,000 fans in 1969?" ) == 0){
        printf("\nTry Again");
        score();
    }
    if(strcmp(question, "What's Evanescence's most popular song?") == 0){
       printf("\nEz");
       uscore += 10;
       printf("\n%d\n", uscore);
       gtk_label_set_text(lbl_result, "40");
       gtk_label_set_text(lbl_Question, "What was the name of Michael Jackson's\n famous dance move?");
       gtk_button_set_label(btn1, "The Wizard of Oz");
       gtk_button_set_label(btn2, "Floss");
       gtk_button_set_label(btn3, "Vogue");
       gtk_button_set_label(btn4, "Moonwalk");
    }
    if(strcmp(question, "What was the name of Michael Jackson's\n famous dance move?") == 0){
       printf("\nEz");
       if(uscore < 50)
       uscore += 10;
       printf("\n%d\n", uscore);
       gtk_label_set_text(lbl_result, "50");
       score();
    }
}
void on_btninst1_clicked(GtkButton *button){
    sprintf(question, "%s", gtk_label_get_text(lbl_Question2));
    printf("\n%s\n", question);
    if(strcmp(question, "What instrument is playing this\n iconic song?" ) == 0){
     printf("\nEz");
       uscore += 10;
       printf("\n%d\n", uscore);
       gtk_label_set_text(lbl_result2, "10");
       gtk_label_set_text(lbl_Question2, "Known for it's appearance in Eurovision");
       gtk_button_set_label(btninst1, "None of the others");
       gtk_button_set_label(btninst2, "Piano");
       gtk_button_set_label(btninst3, "Flute");
       gtk_button_set_label(btninst4, "Saxophone");
         if (play==0 ){
        FMOD_System_Close(systemet);
        FMOD_System_Create(&systemet);
        FMOD_System_Init(systemet, 1, FMOD_INIT_NORMAL, NULL);

        /* On ouvre la musique */
        /*strcpy(filename2, FileFolder);*/
        resultat = FMOD_System_CreateSound(systemet, "epic.mp3", FMOD_HARDWARE | FMOD_LOOP_OFF | FMOD_2D, 0, &musique);
        /* On active la répétition de la musique à l'infini */
        FMOD_Sound_SetLoopCount(musique, -1);
        /* On joue la musique */
        FMOD_System_PlaySound(systemet, FMOD_CHANNEL_FREE, musique, 0, NULL);
        etat=0;
          guint ID=g_timeout_add_seconds(1,(GSourceFunc)timer_handler,timer);
        /*la variable guint IDT pour appeler la fonction ZicTime chaque seconde et donne
        en parametre le variable lblTime qui stocke le currentTime de la music et
        comme la fonction est appeler chaque seconde alors lblTime va changer chaque
        seconde egalement en fonction du current time );*/
        guint IDT=g_timeout_add_seconds(1,(GSourceFunc)ZicTime,lblTime);
        gtk_scale_button_set_value(GTK_SCALE_BUTTON(volumeBtn),1.0);
        FMOD_System_GetMasterChannelGroup(systemet,&channelGroup);
        FMOD_ChannelGroup_SetVolume (channelGroup, volumeMusicGame);/* le volume max*/
        play=0;
        }
    }
    if(strcmp(question, "Known for it's appearance in Eurovision" ) == 0){
     printf("\nTry Again");
     score3();
    }
     if(strcmp(question, "Crystallize by Lindsey Stirling" ) == 0){
     printf("\nTry Again");
     score3();
    }
    if(strcmp(question, "Beethoven" ) == 0){
     printf("\nTry Again");
     score3();
    }
    if(strcmp(question, "Lyrics of a very known\n song through a" ) == 0){
    printf("\nTry Again");
    score3();
    }
}
void on_btninst2_clicked(GtkButton *button){
    sprintf(question, "%s", gtk_label_get_text(lbl_Question2));
    printf("\n%s\n", question);
    if(strcmp(question, "What instrument is playing this\n iconic song?" ) == 0){
     printf("\nTry Again");
     score3();
    }
    if(strcmp(question, "Known for it's appearance in Eurovision" ) == 0){
     printf("\nTry Again");
     score3();
    }
     if(strcmp(question, "Crystallize by Lindsey Stirling" ) == 0){
     printf("\nTry Again");
     score3();
    }
    if(strcmp(question, "Beethoven" ) == 0){
     printf("\nEz");
       uscore += 10;
       printf("\n%d\n", uscore);
       gtk_label_set_text(lbl_result2, "40");
       gtk_label_set_text(lbl_Question2, "Lyrics of a very known\n song through a");
       gtk_button_set_label(btninst1, "Piano");
       gtk_button_set_label(btninst2, "Bamboo flute");
       gtk_button_set_label(btninst3, "Flute");
       gtk_button_set_label(btninst4, "Guitar");
         if (play==0 ){
        FMOD_System_Close(systemet);
        FMOD_System_Create(&systemet);
        FMOD_System_Init(systemet, 1, FMOD_INIT_NORMAL, NULL);

        /* On ouvre la musique */
        /*strcpy(filename2, FileFolder);*/
        resultat = FMOD_System_CreateSound(systemet, "flute.mp3", FMOD_HARDWARE | FMOD_LOOP_OFF | FMOD_2D, 0, &musique);
        /* On active la répétition de la musique à l'infini */
        FMOD_Sound_SetLoopCount(musique, -1);
        /* On joue la musique */
        FMOD_System_PlaySound(systemet, FMOD_CHANNEL_FREE, musique, 0, NULL);
        etat=0;
          guint ID=g_timeout_add_seconds(1,(GSourceFunc)timer_handler,timer);
        /*la variable guint IDT pour appeler la fonction ZicTime chaque seconde et donne
        en parametre le variable lblTime qui stocke le currentTime de la music et
        comme la fonction est appeler chaque seconde alors lblTime va changer chaque
        seconde egalement en fonction du current time );*/
        guint IDT=g_timeout_add_seconds(1,(GSourceFunc)ZicTime,lblTime);
        gtk_scale_button_set_value(GTK_SCALE_BUTTON(volumeBtn),1.0);
        FMOD_System_GetMasterChannelGroup(systemet,&channelGroup);
        FMOD_ChannelGroup_SetVolume (channelGroup, volumeMusicGame);/* le volume max*/
        play=0;
        }
    }
    if(strcmp(question, "Lyrics of a very known\n song through a" ) == 0){
    printf("\nTry Again");
    score3();
    }
}
void on_btninst3_clicked(GtkButton *button){
    sprintf(question, "%s", gtk_label_get_text(lbl_Question2));
    printf("\n%s\n", question);
    if(strcmp(question, "What instrument is playing this\n iconic song?" ) == 0){
     printf("\nTry Again");
     score3();
    }
    if(strcmp(question, "Known for it's appearance in Eurovision" ) == 0){
     printf("\nTry Again");
     score3();
    }
     if(strcmp(question, "Crystallize by Lindsey Stirling" ) == 0){
     printf("\nEz");
       uscore += 10;
       printf("\n%d\n", uscore);
       gtk_label_set_text(lbl_result2, "30");
       gtk_label_set_text(lbl_Question2, "Beethoven");
       gtk_button_set_label(btninst1, "Violin");
       gtk_button_set_label(btninst2, "Piano");
       gtk_button_set_label(btninst3, "Saxophone");
       gtk_button_set_label(btninst4, "None of the others");
         if (play==0 ){
        FMOD_System_Close(systemet);
        FMOD_System_Create(&systemet);
        FMOD_System_Init(systemet, 1, FMOD_INIT_NORMAL, NULL);

        /* On ouvre la musique */
        /*strcpy(filename2, FileFolder);*/
        resultat = FMOD_System_CreateSound(systemet, "piano.mp3", FMOD_HARDWARE | FMOD_LOOP_OFF | FMOD_2D, 0, &musique);
        /* On active la répétition de la musique à l'infini */
        FMOD_Sound_SetLoopCount(musique, -1);
        /* On joue la musique */
        FMOD_System_PlaySound(systemet, FMOD_CHANNEL_FREE, musique, 0, NULL);
        etat=0;
          guint ID=g_timeout_add_seconds(1,(GSourceFunc)timer_handler,timer);
        /*la variable guint IDT pour appeler la fonction ZicTime chaque seconde et donne
        en parametre le variable lblTime qui stocke le currentTime de la music et
        comme la fonction est appeler chaque seconde alors lblTime va changer chaque
        seconde egalement en fonction du current time );*/
        guint IDT=g_timeout_add_seconds(1,(GSourceFunc)ZicTime,lblTime);
        gtk_scale_button_set_value(GTK_SCALE_BUTTON(volumeBtn),1.0);
        FMOD_System_GetMasterChannelGroup(systemet,&channelGroup);
        FMOD_ChannelGroup_SetVolume (channelGroup, volumeMusicGame);/* le volume max*/
        play=0;
        }
    }
    if(strcmp(question, "Beethoven" ) == 0){
     printf("\nTry Again");
     score3();
    }
    if(strcmp(question, "Lyrics of a very known\n song through a" ) == 0){
     printf("\nEz");
       uscore += 10;
       printf("\n%d\n", uscore);
       gtk_label_set_text(lbl_result2, "50");
       score3();
    }
}

void on_btninst4_clicked(GtkButton *button){
    sprintf(question, "%s", gtk_label_get_text(lbl_Question2));
    printf("\n%s\n", question);
    if(strcmp(question, "What instrument is playing this\n iconic song?" ) == 0){
     printf("\nTry Again");
     score3();
    }
    if(strcmp(question, "Known for it's appearance in Eurovision" ) == 0){
     printf("\nEz");
       uscore += 10;
       printf("\n%d\n", uscore);
       gtk_label_set_text(lbl_result2, "20");
       gtk_label_set_text(lbl_Question2, "Crystallize by Lindsey Stirling");
       gtk_button_set_label(btninst1, "Piano");
       gtk_button_set_label(btninst2, "Guitar");
       gtk_button_set_label(btninst3, "Violin");
       gtk_button_set_label(btninst4, "Cello");
         if (play==0 ){
        FMOD_System_Close(systemet);
        FMOD_System_Create(&systemet);
        FMOD_System_Init(systemet, 1, FMOD_INIT_NORMAL, NULL);

        /* On ouvre la musique */
        /*strcpy(filename2, FileFolder);*/
        resultat = FMOD_System_CreateSound(systemet, "violin.mp3", FMOD_HARDWARE | FMOD_LOOP_OFF | FMOD_2D, 0, &musique);
        /* On active la répétition de la musique à l'infini */
        FMOD_Sound_SetLoopCount(musique, -1);
        /* On joue la musique */
        FMOD_System_PlaySound(systemet, FMOD_CHANNEL_FREE, musique, 0, NULL);
        etat=0;
          guint ID=g_timeout_add_seconds(1,(GSourceFunc)timer_handler,timer);
        /*la variable guint IDT pour appeler la fonction ZicTime chaque seconde et donne
        en parametre le variable lblTime qui stocke le currentTime de la music et
        comme la fonction est appeler chaque seconde alors lblTime va changer chaque
        seconde egalement en fonction du current time );*/
        guint IDT=g_timeout_add_seconds(1,(GSourceFunc)ZicTime,lblTime);
        gtk_scale_button_set_value(GTK_SCALE_BUTTON(volumeBtn),1.0);
        FMOD_System_GetMasterChannelGroup(systemet,&channelGroup);
        FMOD_ChannelGroup_SetVolume (channelGroup, volumeMusicGame);/* le volume max*/
        play=0;
        }
    }
    if(strcmp(question, "Crystallize by Lindsey Stirling" ) == 0){
     printf("\nTry Again");
     score3();
    }
    if(strcmp(question, "Beethoven" ) == 0){
     printf("\nTry Again");
     score3();
    }
    if(strcmp(question, "Lyrics of a very known\n song through a" ) == 0){
    printf("\nTry Again");
    score3();
    }
}


void on_btnblind1_clicked(GtkButton *button){
    sprintf(question, "%s", gtk_label_get_text(lbl_Question3));
    printf("\n%s\n", question);
    if(strcmp(question, "What's the name of this viral song?" ) == 0){
       printf("\nTry Again");
       score2();
    }
    if(strcmp(question, "In what famous movie was this iconic\n song featured?" ) == 0){
        printf("\nTry Again");
       score2();
    }
    if(strcmp(question, "Livin on a prayer By ?" ) == 0){
       printf("\nEz");
       uscore += 10;
       printf("\n%d\n", uscore);
       gtk_label_set_text(lbl_result3, "30");
       gtk_label_set_text(lbl_Question3, "What's the name of this popular\n90's band?");
       gtk_button_set_label(btnblind1, "Queen");
       gtk_button_set_label(btnblind2, "Nirvana");
       gtk_button_set_label(btnblind3, "Backstreet Boys");
       gtk_button_set_label(btnblind4, "Foo Fighters");
         if (play==0 ){
        FMOD_System_Close(systemet);
        FMOD_System_Create(&systemet);
        FMOD_System_Init(systemet, 1, FMOD_INIT_NORMAL, NULL);

        /* On ouvre la musique */
        /*strcpy(filename2, FileFolder);*/
        resultat = FMOD_System_CreateSound(systemet, "everybody.mp3", FMOD_HARDWARE | FMOD_LOOP_OFF | FMOD_2D, 0, &musique);
        /* On active la répétition de la musique à l'infini */
        FMOD_Sound_SetLoopCount(musique, -1);
        /* On joue la musique */
        FMOD_System_PlaySound(systemet, FMOD_CHANNEL_FREE, musique, 0, NULL);
        etat=0;
          guint ID=g_timeout_add_seconds(1,(GSourceFunc)timer_handler,timer);
        /*la variable guint IDT pour appeler la fonction ZicTime chaque seconde et donne
        en parametre le variable lblTime qui stocke le currentTime de la music et
        comme la fonction est appeler chaque seconde alors lblTime va changer chaque
        seconde egalement en fonction du current time );*/
        guint IDT=g_timeout_add_seconds(1,(GSourceFunc)ZicTime,lblTime);
        gtk_scale_button_set_value(GTK_SCALE_BUTTON(volumeBtn),1.0);
        FMOD_System_GetMasterChannelGroup(systemet,&channelGroup);
        FMOD_ChannelGroup_SetVolume (channelGroup, volumeMusicGame);/* le volume max*/
        play=0;
        }
    }
       if(strcmp(question, "What's the name of this popular\n90's band?" ) == 0){
        printf("\nTry Again");
        score2();
    }
    if(strcmp(question, "In what movie was this song featured?" ) == 0){
        printf("\nTry Again");
        score2();
    }

}
void on_btnblind2_clicked(GtkButton *button){
    sprintf(question, "%s", gtk_label_get_text(lbl_Question3));
    printf("\n%s\n", question);
    if(strcmp(question, "What's the name of this viral song?" ) == 0){
         printf("\nTry Again");
         score2();
    }
    if(strcmp(question, "In what famous movie was this iconic\n song featured?" ) == 0){
        printf("\nTry Again");
       score2();
    }
    if(strcmp(question, "Livin on a prayer By ?" ) == 0){
        printf("\nTry Again");
       score2();
    }
       if(strcmp(question, "What's the name of this popular\n90's band?" ) == 0){
        printf("\nTry Again");
       score2();
    }
    if(strcmp(question, "In what movie was this song featured?" ) == 0){
       printf("\nEz");
       uscore += 10;
       printf("\n%d\n", uscore);
       gtk_label_set_text(lbl_result3, "50");
       score2();
    }

}
void on_btnblind3_clicked(GtkButton *button){
    sprintf(question, "%s", gtk_label_get_text(lbl_Question3));
    printf("\n%s\n", question);
    if(strcmp(question, "What's the name of this viral song?" ) == 0){
        printf("\nEz");
       uscore += 10;
       printf("\n%d\n", uscore);
       gtk_label_set_text(lbl_result3, "10");
        gtk_label_set_text(lbl_Question3, "In what famous movie was this iconic\n song featured?");
       gtk_button_set_label(btnblind1, "Dragons");
       gtk_button_set_label(btnblind2, "The Smurfs");
       gtk_button_set_label(btnblind3, "Toy Story");
       gtk_button_set_label(btnblind4, "Shrek");
    if (play==0 ){
        FMOD_System_Close(systemet);
        FMOD_System_Create(&systemet);
        FMOD_System_Init(systemet, 1, FMOD_INIT_NORMAL, NULL);

        /* On ouvre la musique */
        /*strcpy(filename2, FileFolder);*/
        resultat = FMOD_System_CreateSound(systemet, "shrek.mp3", FMOD_HARDWARE | FMOD_LOOP_OFF | FMOD_2D, 0, &musique);
        /* On active la répétition de la musique à l'infini */
        FMOD_Sound_SetLoopCount(musique, -1);
        /* On joue la musique */
        FMOD_System_PlaySound(systemet, FMOD_CHANNEL_FREE, musique, 0, NULL);
        etat=0;
          guint ID=g_timeout_add_seconds(1,(GSourceFunc)timer_handler,timer);
        /*la variable guint IDT pour appeler la fonction ZicTime chaque seconde et donne
        en parametre le variable lblTime qui stocke le currentTime de la music et
        comme la fonction est appeler chaque seconde alors lblTime va changer chaque
        seconde egalement en fonction du current time );*/
        guint IDT=g_timeout_add_seconds(1,(GSourceFunc)ZicTime,lblTime);
        gtk_scale_button_set_value(GTK_SCALE_BUTTON(volumeBtn),1.0);
        FMOD_System_GetMasterChannelGroup(systemet,&channelGroup);
        FMOD_ChannelGroup_SetVolume (channelGroup, volumeMusicGame);/* le volume max*/
        play=0;
        }
    }
    if(strcmp(question, "In what famous movie was this iconic\n song featured?" ) == 0){
        printf("\nTry Again");
       score2();
    }
    if(strcmp(question, "Livin on a prayer By ?" ) == 0){
        printf("\nTry Again");
       score2();
    }
    if(strcmp(question, "What's the name of this popular\n90's band?" ) == 0){
       printf("\nEz");
       uscore += 10;
       printf("\n%d\n", uscore);
       gtk_label_set_text(lbl_result3, "40");
       gtk_label_set_text(lbl_Question3, "In what movie was this song featured?");
       gtk_button_set_label(btnblind1, "Raging Bull");
       gtk_button_set_label(btnblind2, "Rocky");
       gtk_button_set_label(btnblind3, "Fight Club");
       gtk_button_set_label(btnblind4, "3 ways to die");
       if (play==0 ){
        FMOD_System_Close(systemet);
        FMOD_System_Create(&systemet);
        FMOD_System_Init(systemet, 1, FMOD_INIT_NORMAL, NULL);

        /* On ouvre la musique */
        /*strcpy(filename2, FileFolder);*/
        resultat = FMOD_System_CreateSound(systemet, "survivor.mp3", FMOD_HARDWARE | FMOD_LOOP_OFF | FMOD_2D, 0, &musique);
        /* On active la répétition de la musique à l'infini */
        FMOD_Sound_SetLoopCount(musique, -1);
        /* On joue la musique */
        FMOD_System_PlaySound(systemet, FMOD_CHANNEL_FREE, musique, 0, NULL);
        etat=0;
          guint ID=g_timeout_add_seconds(1,(GSourceFunc)timer_handler,timer);
        /*la variable guint IDT pour appeler la fonction ZicTime chaque seconde et donne
        en parametre le variable lblTime qui stocke le currentTime de la music et
        comme la fonction est appeler chaque seconde alors lblTime va changer chaque
        seconde egalement en fonction du current time );*/
        guint IDT=g_timeout_add_seconds(1,(GSourceFunc)ZicTime,lblTime);
        gtk_scale_button_set_value(GTK_SCALE_BUTTON(volumeBtn),1.0);
        FMOD_System_GetMasterChannelGroup(systemet,&channelGroup);
        FMOD_ChannelGroup_SetVolume (channelGroup, volumeMusicGame);/* le volume max*/
        play=0;
        }
    }
    if(strcmp(question, "In what movie was this song featured?" ) == 0){
        printf("\nTry Again");
       score2();
    }
}
void on_btnblind4_clicked(GtkButton *button){
    sprintf(question, "%s", gtk_label_get_text(lbl_Question3));
    printf("\n%s\n", question);
    if(strcmp(question, "What's the name of this viral song?" ) == 0){
        printf("\nTry Again");
        score2();
    }
    if(strcmp(question, "In what famous movie was this iconic\n song featured?" ) == 0){
       printf("\nEz");
       uscore += 10;
       printf("\n%d\n", uscore);
       gtk_label_set_text(lbl_result3, "20");
       gtk_label_set_text(lbl_Question3, "Livin on a prayer By ?");
       gtk_button_set_label(btnblind1, "Bon Jovi");
       gtk_button_set_label(btnblind2, "The Beatles");
       gtk_button_set_label(btnblind3, "Micheal Jackson");
       gtk_button_set_label(btnblind4, "Nirvana");
        if (play==0 ){
        FMOD_System_Close(systemet);
        FMOD_System_Create(&systemet);
        FMOD_System_Init(systemet, 1, FMOD_INIT_NORMAL, NULL);

        /* On ouvre la musique */
        /*strcpy(filename2, FileFolder);*/
        resultat = FMOD_System_CreateSound(systemet, "bonjovi.mp3", FMOD_HARDWARE | FMOD_LOOP_OFF | FMOD_2D, 0, &musique);
        /* On active la répétition de la musique à l'infini */
        FMOD_Sound_SetLoopCount(musique, -1);
        /* On joue la musique */
        FMOD_System_PlaySound(systemet, FMOD_CHANNEL_FREE, musique, 0, NULL);
        etat=0;
          guint ID=g_timeout_add_seconds(1,(GSourceFunc)timer_handler,timer);
        /*la variable guint IDT pour appeler la fonction ZicTime chaque seconde et donne
        en parametre le variable lblTime qui stocke le currentTime de la music et
        comme la fonction est appeler chaque seconde alors lblTime va changer chaque
        seconde egalement en fonction du current time );*/
        guint IDT=g_timeout_add_seconds(1,(GSourceFunc)ZicTime,lblTime);
        gtk_scale_button_set_value(GTK_SCALE_BUTTON(volumeBtn),1.0);
        FMOD_System_GetMasterChannelGroup(systemet,&channelGroup);
        FMOD_ChannelGroup_SetVolume (channelGroup, volumeMusicGame);/* le volume max*/
        play=0;
        }
    }
     if(strcmp(question, "Livin on a prayer By ?" ) == 0){
        printf("\nTry Again");
       score2();
    }
       if(strcmp(question, "What's the name of this popular\n90's band?" ) == 0){
        printf("\nTry Again");
       score2();
    }
    if(strcmp(question, "In what movie was this song featured?" ) == 0){
        printf("\nTry Again");
       score2();
    }
}
void score3(){
//instrument
printf("%d", uscore);
     mysql = mysql_init(NULL);
    mysql_options(mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    if(mysql_real_connect(mysql,"localhost","root","","C_PROJECT",3308,NULL,0)) {
     /*Vérification max score SQL*/
     sprintf(sql_cmd,"SELECT max(leaderboards) from games where id_username = '%s'", UserPseudo);
     printf("%s\n", sql_cmd);
        if(mysql_query(mysql, sql_cmd)){
            fprintf(stderr, "%s\n", mysql_error(mysql));
            printf("\nAn error occured!\n");
            mysql_close(mysql);
            exit(1);
        }
     res = mysql_store_result(mysql);
        /* output table name */
        printf("MySQL Data:\n");
        while ((row = mysql_fetch_row(res)) != NULL){
        printf("%s \n", row[0]);
        uleader = row[0];
        }
        if(uleader == (NULL)){
            uleader2 = uscore;
            sprintf(sql_cmd,"Insert into games(game, uscore, leaderboards, id_username) Values(3, '%d', '%d', '%s')", uscore, uleader2, UserPseudo);
        printf("%s\n", sql_cmd);
        if(mysql_query(mysql, sql_cmd)){
            fprintf(stderr, "%s\n", mysql_error(mysql));
            printf("\nAn error occured!\n");
            mysql_close(mysql);
            exit(1);
        }
        }else{
        uleader = atoi(uleader);

        printf("%d", uleader);
        printf("%d", uscore);

     /*Ajout score SQL*/
            if(uscore > uleader){
            uleader = uscore;
            printf("%d", uleader);
      sprintf(sql_cmd,"Insert into games(game, uscore, leaderboards, id_username) Values(3, '%d', '%d', '%s')", uscore, uleader, UserPseudo);
        printf("%s\n", sql_cmd);
        if(mysql_query(mysql, sql_cmd)){
            fprintf(stderr, "%s\n", mysql_error(mysql));
            printf("\nAn error occured!\n");
            mysql_close(mysql);
            exit(1);
        }
        }
        }

      /* close connection */
        mysql_free_result(res);
        mysql_close(mysql);
    } else {
        printf("\nConnection Error !");
     }
      builder = gtk_builder_new();
            gtk_builder_add_from_file (builder, "instrumentsEnd.glade", NULL);

            window10 = GTK_WIDGET(gtk_builder_get_object(builder, "windows1"));
            gtk_builder_connect_signals(builder, NULL);

            // get pointers to the two labels
            lbl_result = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_Result"));
            lbl_endmsg = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_endmsg"));
            gtk_window_set_position(GTK_WINDOW(window10), GTK_WIN_POS_CENTER_ALWAYS);

            g_object_unref(builder);
            /*on affiche notre fenetre (window)*/
            gtk_widget_show(window10);
            /*on ferme la fenetre précédente*/
            gtk_widget_destroy(window7);
            itoa(uscore, uscore_end, 10);
            gtk_label_set_text(lbl_result, uscore_end);
            if(uscore <10)
            gtk_label_set_text(lbl_endmsg, "Not even the Titanic?\n Shame!");
            else if(uscore < 20)
            gtk_label_set_text(lbl_endmsg, "At least you saved the\n Titanic!");
            else if(uscore < 30)
            gtk_label_set_text(lbl_endmsg, "Better than I thought");
            else if(uscore < 40)
            gtk_label_set_text(lbl_endmsg, "You're good at this.");
            else if(uscore < 50)
            gtk_label_set_text(lbl_endmsg, "God tier!");
            else
            gtk_label_set_text(lbl_endmsg, "Flawless!");

}

void score2(){
//blindtest
printf("%d", uscore);
     mysql = mysql_init(NULL);
    mysql_options(mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    if(mysql_real_connect(mysql,"localhost","root","","C_PROJECT",3308,NULL,0)) {
     /*Vérification max score SQL*/
     sprintf(sql_cmd,"SELECT max(leaderboards) from games where id_username = '%s'", UserPseudo);
     printf("%s\n", sql_cmd);
        if(mysql_query(mysql, sql_cmd)){
            fprintf(stderr, "%s\n", mysql_error(mysql));
            printf("\nAn error occured!\n");
            mysql_close(mysql);
            exit(1);
        }
     res = mysql_store_result(mysql);
        /* output table name */
        printf("MySQL Data:\n");
        while ((row = mysql_fetch_row(res)) != NULL){
        printf("%s \n", row[0]);
        uleader = row[0];
        }
        if(uleader == (NULL)){
            uleader2 = uscore;
            sprintf(sql_cmd,"Insert into games(game, uscore, leaderboards, id_username) Values(1, '%d', '%d', '%s')", uscore, uleader2, UserPseudo);
        printf("%s\n", sql_cmd);
        if(mysql_query(mysql, sql_cmd)){
            fprintf(stderr, "%s\n", mysql_error(mysql));
            printf("\nAn error occured!\n");
            mysql_close(mysql);
            exit(1);
        }
        }else{
        uleader = atoi(uleader);

        printf("%d", uleader);
        printf("%d", uscore);

     /*Ajout score SQL*/
            if(uscore > uleader){
            uleader = uscore;
            printf("%d", uleader);
      sprintf(sql_cmd,"Insert into games(game, uscore, leaderboards, id_username) Values(1, '%d', '%d', '%s')", uscore, uleader, UserPseudo);
        printf("%s\n", sql_cmd);
        if(mysql_query(mysql, sql_cmd)){
            fprintf(stderr, "%s\n", mysql_error(mysql));
            printf("\nAn error occured!\n");
            mysql_close(mysql);
            exit(1);
        }
        }
        }

      /* close connection */
        mysql_free_result(res);
        mysql_close(mysql);
    } else {
        printf("\nConnection Error !");
     }
      builder = gtk_builder_new();
            gtk_builder_add_from_file (builder, "blindtestEnd.glade", NULL);

            window9 = GTK_WIDGET(gtk_builder_get_object(builder, "windows1"));
            gtk_builder_connect_signals(builder, NULL);

            // get pointers to the two labels
            lbl_result = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_Result"));
            lbl_endmsg = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_endmsg"));
            gtk_window_set_position(GTK_WINDOW(window9), GTK_WIN_POS_CENTER_ALWAYS);

            g_object_unref(builder);
            /*on affiche notre fenetre (window)*/
            gtk_widget_show(window9);
            /*on ferme la fenetre précédente*/
            gtk_widget_destroy(window8);
            itoa(uscore, uscore_end, 10);
            gtk_label_set_text(lbl_result, uscore_end);
            if(uscore <10)
            gtk_label_set_text(lbl_endmsg, "Never seen worse!");
            else if(uscore < 20)
            gtk_label_set_text(lbl_endmsg, "You can do better!");
            else if(uscore < 30)
            gtk_label_set_text(lbl_endmsg, "That's alright");
            else if(uscore < 40)
            gtk_label_set_text(lbl_endmsg, "You're going places!");
            else if(uscore < 50)
            gtk_label_set_text(lbl_endmsg, "How are you doing this!");
            else
            gtk_label_set_text(lbl_endmsg, "Flawless!");

}
void score(){
//culture
    printf("%d", uscore);
     mysql = mysql_init(NULL);
    mysql_options(mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    if(mysql_real_connect(mysql,"localhost","root","","C_PROJECT",3308,NULL,0)) {
     /*Vérification max score SQL*/
     sprintf(sql_cmd,"SELECT max(leaderboards) from games where id_username = '%s'", UserPseudo);
     printf("%s\n", sql_cmd);
        if(mysql_query(mysql, sql_cmd)){
            fprintf(stderr, "%s\n", mysql_error(mysql));
            printf("\nAn error occured!\n");
            mysql_close(mysql);
            exit(1);
        }
     res = mysql_store_result(mysql);
        /* output table name */
        printf("MySQL Data:\n");
        while ((row = mysql_fetch_row(res)) != NULL){
        printf("%s \n", row[0]);
        uleader = row[0];
        }
        if(uleader == (NULL)){
            uleader2 = uscore;
            sprintf(sql_cmd,"Insert into games(game, uscore, leaderboards, id_username) Values(2, '%d', '%d', '%s')", uscore, uleader2, UserPseudo);
        printf("%s\n", sql_cmd);
        if(mysql_query(mysql, sql_cmd)){
            fprintf(stderr, "%s\n", mysql_error(mysql));
            printf("\nAn error occured!\n");
            mysql_close(mysql);
            exit(1);
        }
        }else{
        uleader = atoi(uleader);

        printf("%d", uleader);
        printf("%d", uscore);

     /*Ajout score SQL*/
            if(uscore > uleader){
            uleader = uscore;
            printf("%d", uleader);
      sprintf(sql_cmd,"Insert into games(game, uscore, leaderboards, id_username) Values(2, '%d', '%d', '%s')", uscore, uleader, UserPseudo);
        printf("%s\n", sql_cmd);
        if(mysql_query(mysql, sql_cmd)){
            fprintf(stderr, "%s\n", mysql_error(mysql));
            printf("\nAn error occured!\n");
            mysql_close(mysql);
            exit(1);
        }
        }
        }

      /* close connection */
        mysql_free_result(res);
        mysql_close(mysql);
    } else {
        printf("\nConnection Error !");
     }
      builder = gtk_builder_new();
            gtk_builder_add_from_file (builder, "cultureEnd.glade", NULL);

            window6 = GTK_WIDGET(gtk_builder_get_object(builder, "windows1"));
            gtk_builder_connect_signals(builder, NULL);

            // get pointers to the two labels
            lbl_result = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_Result"));
            lbl_endmsg = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_endmsg"));
            gtk_window_set_position(GTK_WINDOW(window6), GTK_WIN_POS_CENTER_ALWAYS);

            g_object_unref(builder);
            /*on affiche notre fenetre (window)*/
            gtk_widget_show(window6);
            /*on ferme la fenetre précédente*/
            gtk_widget_destroy(window5);
            itoa(uscore, uscore_end, 10);
            gtk_label_set_text(lbl_result, uscore_end);
            if(uscore <10)
            gtk_label_set_text(lbl_endmsg, "That's bad!");
            else if(uscore < 20)
            gtk_label_set_text(lbl_endmsg, "Better than 0!");
            else if(uscore < 30)
            gtk_label_set_text(lbl_endmsg, "Halfway there! Kinda");
            else if(uscore < 40)
            gtk_label_set_text(lbl_endmsg, "Amazing!");
            else if(uscore < 50)
            gtk_label_set_text(lbl_endmsg, "Almost perfect!");
            else
            gtk_label_set_text(lbl_endmsg, "Flawless!");

}
void on_click_instrument(GtkLabel* label){
            builder = gtk_builder_new();
            gtk_builder_add_from_file (builder, "instrument.glade", NULL);


            window7 = GTK_WIDGET(gtk_builder_get_object(builder, "windows1"));
            gtk_builder_connect_signals(builder, NULL);

            // get pointers to the labels
            lbl_Question2 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_Question2"));
            lbl_result2 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_Result2"));
            btninst1 = GTK_WIDGET(gtk_builder_get_object(builder, "btninst1"));
            btninst2 = GTK_WIDGET(gtk_builder_get_object(builder, "btninst2"));
            btninst3 = GTK_WIDGET(gtk_builder_get_object(builder, "btninst3"));
            btninst4 = GTK_WIDGET(gtk_builder_get_object(builder, "btninst4"));
            gtk_window_set_position(GTK_WINDOW(window7), GTK_WIN_POS_CENTER_ALWAYS);



            /**/
            gtk_builder_connect_signals(builder, NULL);
            gtk_label_set_text(lbl_Question2, "What instrument is playing this\n iconic song?");
            gtk_button_set_label(btninst1, "Flute");
            gtk_button_set_label(btninst2, "Piano");
            gtk_button_set_label(btninst3, "Electric Guitar");
            gtk_button_set_label(btninst4, "Banjo");

            if (play==0 ){
        FMOD_System_Close(systemet);
        FMOD_System_Create(&systemet);
        FMOD_System_Init(systemet, 1, FMOD_INIT_NORMAL, NULL);

        /* On ouvre la musique */
        /*strcpy(filename2, FileFolder);*/
        resultat = FMOD_System_CreateSound(systemet, "TITANIC.mp3", FMOD_HARDWARE | FMOD_LOOP_OFF | FMOD_2D, 0, &musique);
        /* On active la répétition de la musique à l'infini */
        FMOD_Sound_SetLoopCount(musique, -1);
        /* On joue la musique */
        FMOD_System_PlaySound(systemet, FMOD_CHANNEL_FREE, musique, 0, NULL);
        etat=0;
          guint ID=g_timeout_add_seconds(1,(GSourceFunc)timer_handler,timer);
        /*la variable guint IDT pour appeler la fonction ZicTime chaque seconde et donne
        en parametre le variable lblTime qui stocke le currentTime de la music et
        comme la fonction est appeler chaque seconde alors lblTime va changer chaque
        seconde egalement en fonction du current time );*/
        guint IDT=g_timeout_add_seconds(1,(GSourceFunc)ZicTime,lblTime);
        gtk_scale_button_set_value(GTK_SCALE_BUTTON(volumeBtn),1.0);
        FMOD_System_GetMasterChannelGroup(systemet,&channelGroup);
        FMOD_ChannelGroup_SetVolume (channelGroup, volumeMusicGame);/* le volume max*/
        play=0;
        }

            g_object_unref(builder);
            /*on affiche notre fenetre (window)*/
            gtk_widget_show(window7);
            /*on ferme la fenetre précédente*/
            gtk_widget_destroy(window4);


    //sound


}

void on_click_blindtest(GtkLabel* label){
            builder = gtk_builder_new();
            gtk_builder_add_from_file (builder, "blindtest.glade", NULL);


            window8 = GTK_WIDGET(gtk_builder_get_object(builder, "windows1"));
            gtk_builder_connect_signals(builder, NULL);

            // get pointers to the labels
            lbl_Question3 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_Question3"));
            lbl_result3 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_Result3"));
            btnblind1 = GTK_WIDGET(gtk_builder_get_object(builder, "btnblind1"));
            btnblind2 = GTK_WIDGET(gtk_builder_get_object(builder, "btnblind2"));
            btnblind3 = GTK_WIDGET(gtk_builder_get_object(builder, "btnblind3"));
            btnblind4 = GTK_WIDGET(gtk_builder_get_object(builder, "btnblind4"));
            gtk_window_set_position(GTK_WINDOW(window8), GTK_WIN_POS_CENTER_ALWAYS);



            /**/
            gtk_builder_connect_signals(builder, NULL);
            gtk_label_set_text(lbl_Question3, "What's the name of this viral song?");
            gtk_button_set_label(btnblind1, "Blue");
            gtk_button_set_label(btnblind2, "Numa Numa");
            gtk_button_set_label(btnblind3, "Dragostea din tei");
            gtk_button_set_label(btnblind4, "O-Zone");

            g_object_unref(builder);
            /*on affiche notre fenetre (window)*/
            gtk_widget_show(window8);
            /*on ferme la fenetre précédente*/
            gtk_widget_destroy(window4);


    //sound

    if (play==0 ){

        FMOD_System_Close(systemet);
        FMOD_System_Create(&systemet);
        FMOD_System_Init(systemet, 1, FMOD_INIT_NORMAL, NULL);

        /* On ouvre la musique */
        /*strcpy(filename2, FileFolder);*/
        resultat = FMOD_System_CreateSound(systemet, "numa.mp3", FMOD_HARDWARE | FMOD_LOOP_OFF | FMOD_2D, 0, &musique);


        /* On active la répétition de la musique à l'infini */
        FMOD_Sound_SetLoopCount(musique, -1);

        /* On joue la musique */
        FMOD_System_PlaySound(systemet, FMOD_CHANNEL_FREE, musique, 0, NULL);
        etat=0;
          guint ID=g_timeout_add_seconds(1,(GSourceFunc)timer_handler,timer);
        /*la variable guint IDT pour appeler la fonction ZicTime chaque seconde et donne
        en parametre le variable lblTime qui stocke le currentTime de la music et
        comme la fonction est appeler chaque seconde alors lblTime va changer chaque
        seconde egalement en fonction du current time );*/
        guint IDT=g_timeout_add_seconds(1,(GSourceFunc)ZicTime,lblTime);

        gtk_scale_button_set_value(GTK_SCALE_BUTTON(volumeBtn),1.0);
        /* ******** */
        FMOD_System_GetMasterChannelGroup(systemet,&channelGroup);
        FMOD_ChannelGroup_SetVolume (channelGroup, volumeMusicGame);/* le volume max*/

        play=0;

        }


        }





//MusicG_MODULE_EXPORT

void on_btnEnter_clicked(GtkButton *button){
       if (play==0 ){
        if(fileExist==1){
        FMOD_System_Close(systemet);
        FMOD_System_Create(&systemet);
        FMOD_System_Init(systemet, 1, FMOD_INIT_NORMAL, NULL);

        /* On ouvre la musique */
        strcpy(filename2, FileFolder);
        resultat = FMOD_System_CreateSound(systemet, filename2, FMOD_HARDWARE | FMOD_LOOP_OFF | FMOD_2D, 0, &musique);

        /* On vérifie si elle a bien été ouverte (IMPORTANT) */
        if (resultat != FMOD_OK)
        {
            fprintf(stderr, "Impossible to read the file! The file must be a .mp3\n");
           gtk_label_set_text(GTK_LABEL(lbl_reponseFile),"Impossible to read the file! The file must be a .mp3");

        }

        /* On active la répétition de la musique à l'infini */
        FMOD_Sound_SetLoopCount(musique, -1);

        /* On joue la musique */
        FMOD_System_PlaySound(systemet, FMOD_CHANNEL_FREE, musique, 0, NULL);
        etat=0;
          guint ID=g_timeout_add_seconds(1,(GSourceFunc)timer_handler,timer);
        /*la variable guint IDT pour appeler la fonction ZicTime chaque seconde et donne
        en parametre le variable lblTime qui stocke le currentTime de la music et
        comme la fonction est appeler chaque seconde alors lblTime va changer chaque
        seconde egalement en fonction du current time );*/
        guint IDT=g_timeout_add_seconds(1,(GSourceFunc)ZicTime,lblTime);

        gtk_scale_button_set_value(GTK_SCALE_BUTTON(volumeBtn),1.0);
        /* ******** */
        FMOD_System_GetMasterChannelGroup(systemet,&channelGroup);
        FMOD_ChannelGroup_SetVolume (channelGroup, volumeMusic);/* le volume max*/

        play=0;


        /* ******************** */


        /*petit algo pour determiner la duree de la musique et l'afficher ensuite*/

        FMOD_Sound_GetLength(musique,&dure,FMOD_TIMEUNIT_MS);
        dure=dure/1000;
        dureMin=dure/60;
        int dureSecond=dure - (dureMin * 60);
        /* **********Fin de l'algo */



        printf("\n\n---Music opened successfully");
        gtk_label_set_text(GTK_LABEL(lbl_reponseFile),"Music opened successfully");


        /* **Petite condition if pour reguler l'affichage de la duré de la musique ** */
         if (dureMin > 9 && dureSecond > 9){
        sprintf(MusicTimeTotal,"%d:%d",dureMin,dureSecond);}

    else if (dureMin < 10 && dureSecond > 9){
        sprintf(MusicTimeTotal,"0%d:%d",dureMin,dureSecond);}

    else if (dureMin > 9 && dureSecond< 10){
        sprintf(MusicTimeTotal,"%d:0%d",dureMin,dureSecond);}

    else if (dureMin < 10 && dureSecond < 10){
        sprintf(MusicTimeTotal,"0%d:0%d",dureMin,dureSecond);
    }

        }
        else{
            printf("\n\n Wrong Format!!");
            gtk_label_set_text(GTK_LABEL(lbl_reponseFile),"Wrong Format!!");

        }
    }
    else
    {

        printf("\n\n Music already started!!");
    }


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

/*Reglage du volume */
void on_volumeBtn_value_changed(GtkVolumeButton *v1){

    volumeMusic=gtk_scale_button_get_value(GTK_SCALE_BUTTON(v1));
    printf(" \n--volume : %f",gtk_scale_button_get_value(GTK_SCALE_BUTTON(v1)));
    FMOD_ChannelGroup_SetVolume (channelGroup, volumeMusic);
}

/* ******************* */


 gboolean timer_handler(GtkWidget *timer){
     //time_t t=time(0);
     int DureT=getLength();
     posAct=getCurrentPos();
/*     printf("\n%d\n", DureT);
     printf("\n%d\n", posAct);*/
    // gtk_label_set_text(GTK_LABEL(timer),ctime(&t));
     if(posAct<getLength()){

            posAct=posAct+1000;
            gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(prog1), (gdouble) posAct/DureT );
     }
        return TRUE;

}

/* ****************** */





gboolean ZicTime(GtkWidget *lblTimef){

   /*petit algo pour determiner la duree de la musique et l'afficher ensuite*/


        dure=getCurrentPos()/1000;
        dureMin=dure/60;
        int dureSecond=dure - (dureMin * 60);
        /* **********Fin de l'algo */

    char Time[5];

 if (dureMin >25 ){
            dureSecond=0;
            dureMin=0;
       sprintf(Time,"0%d:0%d/%s",dureMin,dureSecond,MusicTimeTotal);
    }
    else if (dureMin > 9 && dureSecond > 9){
       sprintf(Time,"%d:%d/%s",dureMin,dureSecond,MusicTimeTotal);}

    else if (dureMin < 10 && dureSecond > 9){
        sprintf(Time,"0%d:%d/%s",dureMin,dureSecond,MusicTimeTotal);}

    else if (dureMin > 9 && dureSecond< 10){
        sprintf(Time,"%d:0%d/%s",dureMin,dureSecond,MusicTimeTotal);}

    else if (dureMin < 10 && dureSecond < 10){
        sprintf(Time,"0%d:0%d/%s",dureMin,dureSecond,MusicTimeTotal);
    }



        gtk_label_set_text(GTK_LABEL(lblTimef),Time);
    return TRUE;

}




void on_btn_FileChoose_file_set(GtkFileChooserButton *f){
    printf("\n\n-->Filename : %s ",gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(f)));

     strcpy(FileFolder,gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(f)));
    printf("\nColder name : %s ",gtk_file_chooser_get_current_folder(GTK_FILE_CHOOSER(f)));

/* ********Algo qui verifie si le fichier est en mp3 :) xD Oui je sais je pouvais faire Un code plus court ******** */
int sizeTotal=strlen(FileFolder);
char formatpart0=FileFolder[sizeTotal-4];
char formatpart1=FileFolder[sizeTotal-3];
char formatpart2=FileFolder[sizeTotal-2];
char formatpart3=FileFolder[sizeTotal-1];
fflush(stdin);/*Je vide le buffer*/

char formatpart[4]={formatpart0,formatpart1,formatpart2,formatpart3};

    int mp3valide=strncmp(".mp3",formatpart,4);
    printf("\n %s ", formatpart);
    if(mp3valide!=0){
        printf("\n----erreur format");
    }
    else if(mp3valide==0){
        printf("\n---format valider");
        fileExist=1;
    }
/* * ************************ */

}









void on_btn_CreatePlaylist_clicked(GtkButton *button){
//const gchar* str_text=gtk_label_get_text (GTK_LABEL(lblName));

    /* On stocke le pseudo dans la variable UserPseudo*/
    sprintf(PlaylistName,"%s",gtk_entry_get_text(Gtk_entryNamePl));


     /* Une fois qu'on a stocker les infos de login dans les variables tout est possible
     (je parle bien sur de l'insertion ou la verification dans la bdd)*/

    printf("\n---Info Playlist :");
    printf("\n--Playlist Name : %s",PlaylistName);

       /*Ajout Playlist*/
     mysql = mysql_init(NULL);
    mysql_options(mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    if(mysql_real_connect(mysql,"localhost","root","","C_PROJECT",3308,NULL,0)) {
        sprintf(sql_cmd,"INSERT INTO playlist(playlist_name,id_username) VALUES ('%s','%s')", PlaylistName, UserPseudo);
        printf("\n%s\n", sql_cmd);
        if(mysql_query(mysql, sql_cmd)){
            fprintf(stderr, "%s\n", mysql_error(mysql));
            printf("\nError Playlist Already exists!\n");

            gtk_label_set_text(GTK_LABEL(lbl_ReponsePl),"Error Playlist Already exists!");
        }
        else{
            printf("\n Playlist created with success! \n");
            gtk_label_set_text(GTK_LABEL(lbl_ReponsePl),"Playlist created with success!");

}
}









}
void on_lbl_CreateNewPlaylist_activate(GtkMenuItem *menuitem){
            builder = gtk_builder_new();
            gtk_builder_add_from_file (builder, "Playlist_Edit.glade", NULL);


            window2Playlist = GTK_WIDGET(gtk_builder_get_object(builder, "windows12"));


            gtk_builder_connect_signals(builder, NULL);

            Gtk_entryNamePl = GTK_WIDGET(gtk_builder_get_object(builder, "Gtk_entryNamePlaylist"));
            btn_CreatePl = GTK_WIDGET(gtk_builder_get_object(builder, "btn_CreatePlaylist"));
            lbl_ReponsePl = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_reponsePl"));
            btn_Quit12=GTK_WIDGET(gtk_builder_get_object(builder, "btn_Quit12"));

            gtk_window_set_position(GTK_WINDOW(window2Playlist), GTK_WIN_POS_CENTER_ALWAYS);


            gtk_builder_connect_signals(builder, NULL);


            g_object_unref(builder);

            /*on affiche notre fenetre (window)*/
            gtk_widget_show(window2Playlist);

}

void on_lbl_LookPlaylist_activate(GtkMenuItem *menuitem){

builder = gtk_builder_new();
            gtk_builder_add_from_file (builder, "Playlist_Edit.glade", NULL);


            window3ListPlaylist = GTK_WIDGET(gtk_builder_get_object(builder, "windows13"));
           Gtk_entryNamePl = GTK_WIDGET(gtk_builder_get_object(builder, "Gtk_EntryPLname2"));
    btn_listeSoundOnPl = GTK_WIDGET(gtk_builder_get_object(builder, "btn_GetPlExist"));
     lbl_ReponsePl3 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_ReponsePlExist"));
    btn_Quit12=GTK_WIDGET(gtk_builder_get_object(builder, "btn_Quit12"));
    textbuffer1=GTK_WIDGET(gtk_builder_get_object(builder, "textbuffer1"));
    btn_readPL=GTK_WIDGET(gtk_builder_get_object(builder, "btn_readPL"));
    hbox2=GTK_WIDGET(gtk_builder_get_object(builder, "hbox2"));
            etatListePl=1;/*Juste pour savoir si on est bien dans la fenetre*/
            gtk_builder_connect_signals(builder, NULL);
            g_object_unref(builder);

            /*on affiche notre fenetre (window)*/
          gtk_widget_show(window3ListPlaylist);
          gtk_widget_hide(hbox2);
            /*on ferme la fenetre précédente*/

            if(etatListePl==1){

    /* On stocke le pseudo dans la variable UserPseudo*/
    sprintf(PlaylistName,"%s",gtk_entry_get_text(Gtk_entryNamePl));


     /* Une fois qu'on a stocker les infos de login dans les variables tout est possible
     (je parle bien sur de l'insertion ou la verification dans la bdd)*/

    printf("\n---Liste Playlist :");
    printf("\n--Playlist : %s",PlaylistName);

       /*On affiche les Playlists de l'user*/

    mysql = mysql_init(NULL);
    mysql_options(mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    if(mysql_real_connect(mysql,"localhost","root","","C_PROJECT",3308,NULL,0)) {
            sprintf(sql_cmd,"SELECT playlist_name from playlist where id_username='%s'",UserPseudo);
        printf("\n%s\n", sql_cmd);
        if(mysql_query(mysql, sql_cmd)){
            fprintf(stderr, "%s\n", mysql_error(mysql));
            printf("\nError No playlist has that name\n");

            gtk_text_buffer_set_text(textbuffer1, "---------------------------------------------------------------NO PLAYLIST-----------------------------------------------------------", -1);
        }

        else{
                gtk_text_buffer_set_text(textbuffer1,"",-1);
                 res = mysql_store_result(mysql);
        /* output table name */
        printf("MySQL LIST PLaylist:\n");
        while ((row = mysql_fetch_row(res)) != NULL){
        printf("%s \n", row[0]);
        uleader = row[0];
        gtk_text_buffer_insert_at_cursor(textbuffer1, row[0], -1);
        gtk_text_buffer_insert_at_cursor(textbuffer1, "\n", -1);

        }
            printf("\n Your Playlists \n");
            //gtk_label_set_text(GTK_LABEL(lbl_ReponsePl),"Playlist cree avec succes !");

}
        }
}
}

void on_Gtk_AddToPL_activate(GtkMenuItem *menuitem){


builder = gtk_builder_new();
            gtk_builder_add_from_file (builder, "Playlist_Edit2-0.glade", NULL);


            window3ListPlaylist = GTK_WIDGET(gtk_builder_get_object(builder, "window14"));

           Gtk_entryNamePl = GTK_WIDGET(gtk_builder_get_object(builder, "Gtk_entryNamePlaylist"));
    btn_AddToPL= GTK_WIDGET(gtk_builder_get_object(builder, "btn_AddTothePl"));
     lbl_reponsePl2 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_reponsePl2"));
    btn_Quit13=GTK_WIDGET(gtk_builder_get_object(builder, "btn_Quit13"));

            gtk_builder_connect_signals(builder, NULL);
                 fflush(stdout);
fflush(stdin);
            g_object_unref(builder);

            /*on affiche notre fenetre (window)*/
          gtk_widget_show(window3ListPlaylist);




}

void on_btn_AddTothePl_clicked(GtkButton *button){

            if (fileExist==1 ){

                   int j=0;

                              for( j=0;j<strlen(FileFolder);j++){

if(FileFolder[j]=='\\'){
    FileFolder[j]='/';
}


}

printf("TOTOTOTOTOTTOTO/ %s",FileFolder);
            //VERIFICATION DE L'existance de la playlist*/
              sprintf(PlName,"%s",gtk_entry_get_text(Gtk_entryNamePl));

                             mysql = mysql_init(NULL);
                 mysql_options(mysql,MYSQL_READ_DEFAULT_GROUP,"option");
                   /*  CODE POUR AJOUTER LA MUSIC A LA PLAYLIST SI ELLE EXITE AVEC PLAY==1 */
                       sprintf(PlName,"%s",gtk_entry_get_text(Gtk_entryNamePl));
                      if(mysql_real_connect(mysql,"localhost","root","","C_PROJECT",3308,NULL,0)) {
            sprintf(sql_cmd,"SELECT * from playlist where id_username='%s' AND playlist_name='%s'",UserPseudo,PlName);
        printf("\n%s\n", sql_cmd);
        if(mysql_query(mysql, sql_cmd)){
            fprintf(stderr, "%s\n", mysql_error(mysql));
            printf("\nError no playlist with that name!!\n");
           gtk_label_set_text(GTK_LABEL(lbl_reponsePl2),"Please fill in the fields");


}
        else{
                 res = mysql_store_result(mysql);
        /* output table name */
        printf("MySQL LIST PLaylist:\n");
        if((row = mysql_fetch_row(res)) != NULL){
            /* output table name */
        printf("Playlist found!");

                mysql = mysql_init(NULL);

                 mysql_options(mysql,MYSQL_READ_DEFAULT_GROUP,"option");
                   /*  CODE POUR AJOUTER LA MUSIC A LA PLAYLIST SI ELLE EXISTE AVEC PLAY==1 */
                          printf("\ndestination : %s\n", FileFolder);
                          printf("\nid_Playlist : %s\n", PlName);
                      if(mysql_real_connect(mysql,"localhost","root","","C_PROJECT",3308,NULL,0)) {
            sprintf(sql_cmd,"INSERT INTO songs(destination,id_PlaylistSoungs,id_UsersSong) VALUES('%s','%s','%s')",FileFolder,PlName,UserPseudo);
        printf("\n%s\n", sql_cmd);
        if(mysql_query(mysql, sql_cmd)){
            fprintf(stderr, "%s\n", mysql_error(mysql));
            printf("\nError no playlist with that name!!\n");
           gtk_label_set_text(GTK_LABEL(lbl_reponsePl2),"Please fill in the fields");

}
        else{
        /* output table name */
        printf("Added to the Playlist with success!");
         gtk_label_set_text(GTK_LABEL(lbl_reponsePl2),"Added to the Playlist with success!");

}

}}
}    }

        }

            else if(fileExist==0)
            {
                gtk_label_set_text(GTK_LABEL(lbl_reponsePl2),"No music charged!");
            }

}


void on_btn_GetPlExist_clicked(GtkButton *button){

            //VERIFICATION DE L'existance de la playlist*/
              sprintf(PlName,"%s",gtk_entry_get_text(Gtk_entryNamePl));

                             mysql = mysql_init(NULL);
                 mysql_options(mysql,MYSQL_READ_DEFAULT_GROUP,"option");
                   /*  CODE POUR AJOUTER LA MUSIC A LA PLAYLIST SI ELLE EXITE AVEC PLAY==1 */
                       sprintf(PlName,"%s",gtk_entry_get_text(Gtk_entryNamePl));
                      if(mysql_real_connect(mysql,"localhost","root","","C_PROJECT",3308,NULL,0)) {
            sprintf(sql_cmd,"SELECT * from playlist where id_username='%s' AND playlist_name='%s'",UserPseudo,PlName);
        printf("\n%s\n", sql_cmd);
        if(mysql_query(mysql, sql_cmd)){
            fprintf(stderr, "%s\n", mysql_error(mysql));
            printf("\nError no playlist with that name found\n");


}
        else{
                 res = mysql_store_result(mysql);
        /* output table name */

        if((row = mysql_fetch_row(res)) != NULL){
            /* output table name */
        printf("Playlist found!");

                mysql = mysql_init(NULL);
                 mysql_options(mysql,MYSQL_READ_DEFAULT_GROUP,"option");
                   /*  CODE POUR recuperer toute les music associer a la playlist
                   et les afficher dans le textBUFFER1 et les stocker dans un tableau de chaine de caractères dynamique */

                      if(mysql_real_connect(mysql,"localhost","root","","C_PROJECT",3308,NULL,0)) {
            sprintf(sql_cmd,"SELECT * from songs where id_PlaylistSoungs='%s' AND id_UsersSong='%s'",PlName,UserPseudo);
        printf("\n%s\n", sql_cmd);
        if(mysql_query(mysql, sql_cmd)){
            fprintf(stderr, "%s\n", mysql_error(mysql));
            printf("\nError!\n");

}
        else{
        /* output table name */
        printf("Opened with success!");
         gtk_label_set_text(GTK_LABEL(lbl_ReponsePl3),"Opened with success!");
         gtk_text_buffer_set_text(textbuffer1,"",-1);
            gtk_widget_show(hbox2);
        res = mysql_store_result(mysql);
        /* output table name */
        int i=0;

        printf("MySQL LIST PLaylist:\n");
        while ((row = mysql_fetch_row(res)) != NULL){
            i=0;j=0;


        /*pour inserer toute les music de la playlist dans le
        tableau TABMusic */
            sprintf(tabMusic[i],row[1]);

        i++;
        printf("--------------------------------------------------------------- \n");
/* * ******************************************** */

        gtk_text_buffer_insert_at_cursor(textbuffer1, row[1], -1);
        gtk_text_buffer_insert_at_cursor(textbuffer1, "\n", -1);

        }


}

}}
else{
    printf("\No playlist with that name found\n");
    gtk_label_set_text(GTK_LABEL(lbl_ReponsePl3),"No playlist with that name found\n");


}
}    }

}


void on_btn_readPL_clicked(GtkButton *button){
    if (play==0 ){
        FMOD_System_Close(systemet);
        FMOD_System_Create(&systemet);

        FMOD_System_Init(systemet, 1, FMOD_INIT_NORMAL, NULL);

        /* On ouvre la musique */

        int taillTab=strlen(tabMusic);



        printf("\n\nThe Size: %d MY MUSIC /%s\n\n\n",taillTab,tabMusic[1]);
        resultat = FMOD_System_CreateSound(systemet, tabMusic[0], FMOD_HARDWARE | FMOD_LOOP_NORMAL | FMOD_2D, 0, &musique);

        /* On vérifie si elle a bien été ouverte (IMPORTANT) */
        if (resultat != FMOD_OK)
        {
            fprintf(stderr, "Impossible to read the file! The file must be a .mp3\n");
           gtk_label_set_text(GTK_LABEL(lbl_reponseFile),"Impossible to read the file! The file must be a .mp3");

        }

        /* On active la répétition de la musique à l'infini */
        FMOD_Sound_SetLoopCount(musique, -1);

        /* On joue la musique */
        FMOD_System_PlaySound(systemet, FMOD_CHANNEL_FREE, musique, 0, NULL);
        etat=0;
          guint ID=g_timeout_add_seconds(1,(GSourceFunc)timer_handler,timer);
        /*la variable guint IDT pour appeler la fonction ZicTime chaque seconde et donne
        en parametre le variable lblTime qui stocke le currentTime de la music et
        comme la fonction est appeler chaque seconde alors lblTime va changer chaque
        seconde egalement en fonction du current time );*/
        guint IDT=g_timeout_add_seconds(1,(GSourceFunc)ZicTime,lblTime);

        gtk_scale_button_set_value(GTK_SCALE_BUTTON(volumeBtn),1.0);
        /* ******** */
        FMOD_System_GetMasterChannelGroup(systemet,&channelGroup);
        FMOD_ChannelGroup_SetVolume (channelGroup, volumeMusic);/* le volume max*/

        play=0;


        /* ******************** */


        /*petit algo pour determiner la duree de la musique et l'afficher ensuite*/

        FMOD_Sound_GetLength(musique,&dure,FMOD_TIMEUNIT_MS);
        dure=dure/1000;
        dureMin=dure/60;
        int dureSecond=dure - (dureMin * 60);
        /* **********Fin de l'algo */



        printf("\n\n---Music opened successfully");
        gtk_label_set_text(GTK_LABEL(lbl_reponseFile),"Music opened successfully");


        /* **Petite condition if pour reguler l'affichage de la duré de la musique ** */
         if (dureMin > 9 && dureSecond > 9){
        sprintf(MusicTimeTotal,"%d:%d",dureMin,dureSecond);}

    else if (dureMin < 10 && dureSecond > 9){
        sprintf(MusicTimeTotal,"0%d:%d",dureMin,dureSecond);}

    else if (dureMin > 9 && dureSecond< 10){
        sprintf(MusicTimeTotal,"%d:0%d",dureMin,dureSecond);}

    else if (dureMin < 10 && dureSecond < 10){
        sprintf(MusicTimeTotal,"0%d:0%d",dureMin,dureSecond);
    }




    }
    else
    {

        printf("\n\n Music already started!!");
    }
}




/* Gestion d'ouverture et fermeture des fenetre*/

void on_btn_Quit13_clicked(GtkButton *button) {
 printf("\nquit");
    gtk_widget_hide(window3ListPlaylist );
    }

void on_btn_Quit12_clicked(GtkButton *button){
        printf("\nquit");
    gtk_widget_hide(window2Playlist );
    }
    /* *************************** */





void on_windows11_destroy()
{


    FMOD_System_Close(systemet);

    FMOD_System_Release(systemet);
    gtk_main_quit();
}

//Music


