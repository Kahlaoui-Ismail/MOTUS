#include <gtk/gtk.h>
#include <stdlib.h>

#include "optionwindowx.h"

void show_best_score(){
  GtkWidget *window2;
  GtkWidget *label_max;
  window2= gtk_window_new (GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title (GTK_WINDOW (window2), "MOTUS");
   gtk_window_set_default_size (GTK_WINDOW (window2), 100, 100);
   gtk_container_set_border_width(GTK_CONTAINER(window2), 40);//shows the best score
  FILE*fscore;
  fscore=fopen("/Users/soufianehajazi/Downloads/MOTUS-master\ 8/MOTUS_GUI/score.txt","r");
  int max=0;
  int num;
  while(!feof(fscore)){
  fscanf(fscore,"%d", &num);

  if(max<num){
    max=num;
  }

}
fclose(fscore);
label_max = gtk_label_new("Ton meilleur score :");
gtk_container_add(GTK_WINDOW(window2), label_max);
gtk_widget_show_all (window2);

}



static void menu (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *button1;
  GtkWidget *button_box;
  GtkWidget *button3;
  GtkWidget *button_box3;
  GtkWidget *button2;
  GtkWidget *button_box2;
  GtkWidget *pVBox;
  GtkWidget *image;
  static GtkWidget *max;


  GtkWidget *label;

 window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "MOTUS");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 400);
  gtk_container_set_border_width(GTK_CONTAINER(window), 40);



  button_box = gtk_button_box_new (GTK_ORIENTATION_VERTICAL);
  gtk_container_add (GTK_CONTAINER (window), button_box);

  /* Chargement d'une image a partir d'un fichier */
  image = gtk_image_new_from_file("MOTUS_GTK_UPDATED/Screen Shot 2020-01-23 at 13.00.44.png");
  gtk_box_pack_start(GTK_BOX(button_box), image, FALSE, FALSE, 5);




  button1 = gtk_button_new_with_label ("NOUVELLE PARTIE");


  g_signal_connect (button1, "clicked", G_CALLBACK(option), NULL);
  
  gtk_container_add (GTK_CONTAINER (button_box), button1);
  button2 = gtk_button_new_with_label ("MEILLEUR SCORE");
  g_signal_connect (button2, "clicked", G_CALLBACK (show_best_score), NULL);

  gtk_container_add (GTK_CONTAINER (button_box), button2);
  button3 = gtk_button_new_with_label ("SORTIR DU JEU");
  g_signal_connect (button3, "clicked", G_CALLBACK (print_hello), NULL);
  g_signal_connect_swapped (button3, "clicked", G_CALLBACK (gtk_widget_destroy), window);
  gtk_container_add (GTK_CONTAINER (button_box), button3);

  label = gtk_label_new("Game Designed By Hajazi Soufiane & Ismail Kahlaoui\n\n ENSIAS 2019-2020 ");
  gtk_label_set_justify(GTK_LABEL(label), GTK_JUSTIFY_CENTER);
       gtk_container_add(GTK_CONTAINER(button_box), label);


  gtk_widget_show_all (window);

}

int main (int    argc, char **argv)
{
  GtkApplication *app;

  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (menu), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);



  return status;
}
