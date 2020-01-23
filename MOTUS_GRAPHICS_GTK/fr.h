#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
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

static void option_one(){
  GtkWidget *window1;
  GtkWidget *button_a;
  GtkWidget *button_b;
  GtkWidget *button_c;
  GtkWidget *label_x;
  GtkWidget *app1;
  GtkWidget *grid;
  GtkWidget *box;

  window1= gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_widget_show(window1);
  g_signal_connect(window1, "destroy",G_CALLBACK(gtk_main_quit), NULL);
  gtk_container_set_border_width(GTK_CONTAINER(window1), 40);
  label_x= gtk_label_new("Nombre de lettres par mot : ");
  gtk_label_set_justify(GTK_LABEL(label_x), GTK_JUSTIFY_LEFT);
  gtk_container_add(GTK_CONTAINER(window1), label_x);
  grid = gtk_grid_new ();
  gtk_container_add(GTK_CONTAINER(window1), grid);
  gtk_grid_attach (GTK_GRID (grid), label_x,  0, 0, 1, 1);
  gtk_grid_attach (GTK_GRID (grid), button_a, 1, 0, 1, 1);
  gtk_grid_attach (GTK_GRID (grid), button_b, 2, 0, 1, 1);
  gtk_grid_attach (GTK_GRID (grid), button_c, 3, 0, 1, 1);
  button_a= gtk_radio_button_new_with_label (NULL, "Button 1");

  /*Create a second radio button, and add it to the same group as Button 1*/
  button_b = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON (button_a),
                                                         "Button 2");

  /*Create a third button, and add it to the same group as Button 1*/
  button_c = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON (button_c),
                                                         "Button 3");
  /*Create a second radio button, and add it to the same group as Button 1*/
   gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (button_a), TRUE);
    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (button_b), FALSE);
    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (button_c), FALSE);

    /*Connect the signal handlers (aka Callback functions) to the buttons*/
    g_signal_connect (GTK_TOGGLE_BUTTON (button_a), "toggled",
                      G_CALLBACK (button_toggled_cb), window1);
    g_signal_connect (GTK_TOGGLE_BUTTON (button_b), "toggled",
                      G_CALLBACK (button_toggled_cb), window1);
    g_signal_connect (GTK_TOGGLE_BUTTON (button_c), "toggled",
                      G_CALLBACK (button_toggled_cb), window1);

    gtk_container_add (GTK_CONTAINER (window1), GTK_WIDGET (grid));
    gtk_widget_show_all (window1);

}

int main (int    argc, char **argv)
{

option_one();




  return 0;
}
