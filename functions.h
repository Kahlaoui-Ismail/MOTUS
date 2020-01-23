static void show_best_score(){

  GtkWidget *window1, *score,*grid,*calculate;


  window1=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW(window1), "score");
  gtk_window_set_default_size (GTK_WINDOW(window1),100,100);

  grid = gtk_grid_new();
  gtk_container_add(GTK_CONTAINER(window1),grid);
  g_signal_connect(GTK_CONTAINER(window1),"clicked",G_CALLBACK(best_score),NULL);
  max=gtk_label_new(" Your best score :");
  gtk_grid_attach(GTK_GRID(grid), max, 4, 1, 1, 1);


       gtk_widget_show_all(window1);

}

static void set_color (void)
{

  gdk_color_parse ("blue", &colorBlue);
  gdk_color_parse ("red",  &colorRed);
  gdk_color_parse ("yellow",  &colorYellow);
  gdk_color_parse ("gray",  &colorGray);
  gdk_color_parse ("lightgray",  &colorLightGray);
  gdk_color_parse("#20F0DF", &colorCustom02);

}

static void button_toggled_cb (GtkWidget *button, gpointer   user_data)
{
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
static GtkWidget *max;
void best_score(GtkWidget *calculate, gpointer data){//shows the best score
  FILE*fscore;
  fscore=fopen("/Users/soufianehajazi/Desktop/Screen\ Shot\ 2020-01-23\ at\ 13.00.44.png","r");
  int max=0;
  int num;
  while(!feof(fscore)){
  fscanf(fscore,"%d", &num);

  if(max<num){
    max=num;
  }

}
fclose(fscore);
char buffer[32];
snprintf(buffer, sizeof(buffer), "Your best score: %d", max);
gtk_label_set_text(GTK_LABEL(max), buffer);
}
