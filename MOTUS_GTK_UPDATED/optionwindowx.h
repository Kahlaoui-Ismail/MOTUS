#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include "gamewindowx.h"
static void button_toggled_cb(GtkWidget *button, gpointer   user_data){
  char *b_state;
  const char *button_label;

  if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (button)))
          b_state = "on";
  else {
          b_state = "off";
          g_print ("\n");
  }

  button_label = gtk_button_get_label (GTK_BUTTON (button));

  g_print ("%s was turned %s\n", button_label, b_state);
}
static void print_hello (GtkWidget *widget,gpointer   data)
{
  g_print ("Hello SOUFIANE\n");
}

static void option(GtkApplication *app2,
          gpointer        user_data){
  GtkWidget *window1;
  GtkWidget *button_a;
  GtkWidget *button_b;
  GtkWidget *button_c;
  GtkWidget *button_d;
  GtkWidget *button_e;
  GtkWidget *button_f;
GtkWidget *button_9;
GtkWidget *button_10;

  GtkWidget *label_x;
  GtkWidget *label_y;
  GtkWidget *label_z;
  GtkWidget *app1;
  GtkWidget *grid;
  GtkWidget *box;
  GtkWidget *image;
  GtkWidget *nom_joueur;
  GtkWidget *Go_button;


   window1 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title (GTK_WINDOW (window1), "MOTUS");
   gtk_window_set_default_size (GTK_WINDOW (window1), 90, 150);
   gtk_container_set_border_width(GTK_CONTAINER(window1), 50);

   button_a= gtk_radio_button_new_with_label(NULL,"6 lettres");


   
   button_b = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON (button_a),
                                                          "7 lettres");

   /*Create a third button, and add it to the same group as Button 1*/
   button_c = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON (button_a),
                                                          "8 lettres");
button_9 = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON (button_a),
                                                          "9 lettres");
button_10 = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON (button_a),
                                                          "10 lettres");



    button_d=gtk_radio_button_new_with_label(NULL,
                                                          "facile");

    button_e = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON (button_d),
                                                           "difficile");
    button_f = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON (button_d),
                                                                "très difficile");
   label_x= gtk_label_new("Choisir le nombre de lettres par mot: ");//choix nombre de mots
   label_y= gtk_label_new("Nom du joueur:");
   label_z=gtk_label_new("Niveau de Difficulté: ");

   nom_joueur=gtk_entry_new ();
   Go_button= gtk_button_new_with_label ("JOUER");
   g_signal_connect (Go_button, "clicked", G_CALLBACK (main_game), NULL);
g_signal_connect_swapped (Go_button, "clicked", G_CALLBACK (gtk_widget_destroy), window1);



   grid = gtk_grid_new ();

   gtk_grid_attach (GTK_GRID (grid), label_x,  0, 0, 1, 1);
   gtk_grid_attach (GTK_GRID (grid), button_a, 1, 0, 1, 1);
   gtk_grid_attach (GTK_GRID (grid), button_b, 2, 0, 1, 1);
   gtk_grid_attach (GTK_GRID (grid), button_c, 3, 0, 1, 1);
   gtk_grid_attach (GTK_GRID (grid), button_9, 4, 0, 1, 1);
   gtk_grid_attach (GTK_GRID (grid), button_10, 5, 0, 1, 1);
   gtk_grid_attach (GTK_GRID (grid), label_z,  0, 1, 1, 1);
   gtk_grid_attach (GTK_GRID (grid), button_d, 1, 1, 1, 1);
   gtk_grid_attach (GTK_GRID (grid), button_e, 2, 1, 1, 1);
   gtk_grid_attach (GTK_GRID (grid), button_f, 3, 1, 1, 1);
   gtk_grid_attach (GTK_GRID (grid), label_y,  0, 4, 1, 1);
   gtk_grid_attach (GTK_GRID (grid), nom_joueur,  1, 4, 1, 1);
   gtk_grid_attach (GTK_GRID (grid), Go_button,  3, 4, 1, 1);
   GtkEntryBuffer *joueur;
   joueur=gtk_entry_get_buffer (nom_joueur);


   /*Be sure to set the initial state of each button*/
   gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (button_a), TRUE);
   gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (button_b), FALSE);
   gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (button_c), FALSE);
   gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (button_9), FALSE);
   gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (button_10), FALSE);
   gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (button_d), TRUE);
   gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (button_e), FALSE);
   gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (button_f), FALSE);

   /*Connect the signal handlers (aka Callback functions) to the buttons*/
   g_signal_connect (GTK_TOGGLE_BUTTON (button_a), "toggled",
                     G_CALLBACK (button_toggled_cb), window1);
   g_signal_connect (GTK_TOGGLE_BUTTON (button_b), "toggled",
                     G_CALLBACK (button_toggled_cb), window1);
   g_signal_connect (GTK_TOGGLE_BUTTON (button_c), "toggled",
                     G_CALLBACK (button_toggled_cb), window1);
g_signal_connect (GTK_TOGGLE_BUTTON (button_9), "toggled",
                     G_CALLBACK (button_toggled_cb), window1);
g_signal_connect (GTK_TOGGLE_BUTTON (button_10), "toggled",
                     G_CALLBACK (button_toggled_cb), window1);

                     g_signal_connect (GTK_TOGGLE_BUTTON (button_d), "toggled",
                                       G_CALLBACK (button_toggled_cb), window1);
                     g_signal_connect (GTK_TOGGLE_BUTTON (button_e), "toggled",
                                       G_CALLBACK (button_toggled_cb), window1);
                     g_signal_connect (GTK_TOGGLE_BUTTON (button_f), "toggled",
                                       G_CALLBACK (button_toggled_cb), window1);




   gtk_container_add (GTK_CONTAINER (window1), GTK_WIDGET (grid));


    gtk_widget_show_all (window1);

}
