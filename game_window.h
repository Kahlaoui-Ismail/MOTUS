#include <gtk/gtk.h>

static GdkColor colorBlue;
static GdkColor colorRed;
static GdkColor colorYellow;
static GdkColor colorGray;
static GdkColor colorLightGray;
static GdkColor colorCustom01 = {0, 0xAAAA, 0x1234, 0xF0F0};
static GdkColor colorCustom02;




static void
set_color ()
{

  gdk_color_parse ("blue", &colorBlue);
  gdk_color_parse ("red",  &colorRed);
  gdk_color_parse ("yellow",  &colorYellow);
  gdk_color_parse ("gray",  &colorGray);
  gdk_color_parse ("lightgray",  &colorLightGray);
  gdk_color_parse("#20F0DF", &colorCustom02);

}

 void gtk_main_quit();
static void
main_game (GtkApplication *app1,
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
  gchar *values[65] = {"A","B","C","d"};
  GtkWidget *button;
  GtkWidget *quit_button;
  GtkWidget *cd;
  GtkWidget *image_red_box;
  GtkWidget *image_yellow_box;

  set_color();


  /*Create a window with a set title and default size.
  Also, set a border width for the amount of space to leave
  inside the window*/
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "MOTUS");
  gtk_window_set_default_size (GTK_WINDOW (window), 250, 100);
  gtk_container_set_border_width (GTK_CONTAINER(window), 20);



   Tried_word=gtk_entry_new ();
   Go_button= gtk_toggle_button_new_with_label("GO");

   quit_button= gtk_button_new_with_label ("QUIT THE GAME");
   g_signal_connect_swapped(quit_button, "destroy", G_CALLBACK (gtk_main_quit), NULL);

   label_1=gtk_label_new("TRY YOUR BEST !");
   box=gtk_box_new(TRUE,2);
   gtk_box_set_baseline_position (GTK_BOX(box),GTK_BASELINE_POSITION_CENTER);
   image = gtk_image_new_from_file("/Users/soufianehajazi/Desktop/Screen\ Shot\ 2020-01-23\ at\ 13.00.44.png");
   gtk_box_pack_start(GTK_BOX(box), image, TRUE, TRUE, 5);
   gtk_box_pack_start(GTK_BOX(box),label_1,TRUE,TRUE,NULL);
   gtk_box_pack_start(GTK_BOX(box),Tried_word,TRUE,TRUE,NULL);
   gtk_box_pack_start (GTK_BOX(box), Go_button, TRUE, TRUE, 10);
   gtk_box_pack_end (GTK_BOX(box), quit_button,   TRUE,  FALSE,20);
   image_red_box=gtk_image_new_from_file("/Users/soufianehajazi/Downloads/motus-master\ 3/Graphique/FondOK.png");

  table = gtk_table_new(8, 8, TRUE);
  gtk_table_set_row_spacings(GTK_TABLE(table), 2);
  gtk_table_set_col_spacings(GTK_TABLE(table), 2);


  int i = 0;
  int j = 0;
  int pos = 0;
  for (i=0; i < 8; i++) {
    for (j=0; j < 8; j++) {
      //const gchar *word=gtk_entry_get_text (Tried_word);
      cd=gtk_label_new(values[pos]);
      gtk_table_attach_defaults(GTK_TABLE(table), cd, j, j+1, i, i+1);


      image_yellow_box= gtk_image_new_from_file("/Users/soufianehajazi/Downloads/motus-master\ 3/Graphique/FondMauvaisePos.png");
      gtk_table_attach_defaults(GTK_TABLE(table), image_yellow_box, j, j+1, i, i+1);

      gtk_widget_modify_fg (cd, GTK_STATE_NORMAL, &colorRed);
      pos++;
    }
  }
  if(gtk_toggle_button_get_active(Go_button)){
    int m= 0;
    int n = 0;
    int posi = 0;
    for (m=0; m< 8; m++) {
      for (n=0; n < 8; n++) {
        const gchar *word=gtk_entry_get_text (Tried_word);
        cd=gtk_label_new(*(word+m));
        gtk_table_attach_defaults(GTK_TABLE(table), cd, m, m+1, n, n+1);


        image_yellow_box= gtk_image_new_from_file("/Users/soufianehajazi/Downloads/motus-master\ 3/Graphique/FondMauvaisePos.png");
        gtk_table_attach_defaults(GTK_TABLE(table), image_yellow_box,  m, m+1, n, n+1);

        gtk_widget_modify_fg (cd, GTK_STATE_NORMAL, &colorRed);
        posi++;
      }
    }

  }

  /*Be sure to set the initial state of each button*/
 gtk_container_add (GTK_CONTAINER (window), GTK_WIDGET(box));
 gtk_container_add (GTK_CONTAINER (box), GTK_WIDGET(table));
 gtk_widget_show_all (window);
}
