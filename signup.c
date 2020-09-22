#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <mysql.h>


// called when button is clicked
void on_btnConnect_clicked2(GtkButton *button)
{
char UserPseudo[36];
char UserMdp[36];
MYSQL *mysql;
MYSQL_RES *res;
MYSQL_ROW row;
char sql_cmd[1024];

GtkWidget *Gtk_entryName;
GtkWidget *btnConnect;
GtkWidget *Gtk_entryMdp;
    //const gchar* str_text=gtk_label_get_text (GTK_LABEL(lblName));

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
    if(mysql_real_connect(mysql,"localhost","root","root","C_PROJECT",3308,NULL,0)) {
            sprintf(sql_cmd,"INSERT INTO user(username, password) VALUES ('%s', '%s')", UserPseudo, UserMdp);
        printf("%s\n", sql_cmd);
        if(mysql_query(mysql, sql_cmd)){
            printf("\nThat username is already taken, choose another!\n");
            mysql_close(mysql);
            exit(1);
        }
        else{
            printf("\n Welcome %s \n", UserPseudo);
		}
