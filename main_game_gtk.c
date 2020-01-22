#include <gtk/gtk.h>

static void
activate (GtkApplication *app,
          gpointer        user_data)
{

  GtkWidget *window;
  GtkWidget *Tried_word;
  GtkWidget *Go_button;
  GtkWidget *grid;
  GtkWidget *box;
  GtkWidget *image;
  GtkWidget *label_1;
  GtkWidget *table;
  gchar *values[65] = {0};
  GtkWidget *button;


  /*Create a window with a set title and default size.
  Also, set a border width for the amount of space to leave
  inside the window*/
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "MOTUS");
  gtk_window_set_default_size (GTK_WINDOW (window), 250, 100);
  gtk_container_set_border_width (GTK_CONTAINER(window), 20);


   Tried_word=gtk_entry_new ();
   Go_button= gtk_button_new_with_label ("Go");
   g_signal_connect (Go_button, "clicked", G_CALLBACK (gtk_main_quit), NULL);
   label_1=gtk_label_new("TRY YOUR BEST !");
  box=gtk_box_new(TRUE,2);
  gtk_box_set_baseline_position (GTK_BOX(box),GTK_BASELINE_POSITION_CENTER);
  image = gtk_image_new_from_file("/Users/soufianehajazi/Downloads/motus-master\ 3/Graphique/Motus.jpg");
  gtk_box_pack_start(GTK_BOX(box), image, TRUE, TRUE, 5);
gtk_box_pack_start(GTK_BOX(box),label_1,TRUE,TRUE,NULL);
  gtk_box_pack_start(GTK_BOX(box),Tried_word,TRUE,TRUE,NULL);
   gtk_box_pack_start (GTK_BOX(box),
                     Go_button,
                     TRUE,
                     TRUE,
                     NULL);

  table = gtk_table_new(8, 8, TRUE);
  gtk_table_set_row_spacings(GTK_TABLE(table), 2);
  gtk_table_set_col_spacings(GTK_TABLE(table), 2);



  int i = 0;
  int j = 0;
  int pos = 0;

  for (i=0; i < 8; i++) {
    for (j=0; j < 8; j++) {
      button = gtk_button_new_with_label(values[pos]);
      gtk_table_attach_defaults(GTK_TABLE(table), button, j, j+1, i, i+1);
      pos++;
    }
  }


  /*Be sure to set the initial state of each button*/
gtk_container_add (GTK_CONTAINER (window), GTK_WIDGET(box));
gtk_container_add (GTK_CONTAINER (box), GTK_WIDGET(table));
  gtk_widget_show_all (window);
}



int
main (int argc, char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
