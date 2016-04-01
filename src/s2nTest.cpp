//============================================================================
// Name        : s2nTest.cpp
// Author      : YuchenWang
// Version     :
// Copyright   : 
// Description : Copy from Lucky MicroSeconds
//============================================================================
#include "s2nHeader.h"

int main(int argc,char** argv) {
	GtkWidget *window;
	GtkWidget *halign;
	GtkWidget *valign;
	GdkPixbuf *icon;

	GtkWidget *vbox;
	GtkWidget *hbox;

	GtkWidget *button_md5;
	GtkWidget *button_sha1;
	GtkWidget *button_sha256;

	struct EntryStruct entry;
	//GtkWidget *entry_context;
	//GtkWidget  *hash_context;

	gtk_init(&argc,&argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),"Hash from s2n libaray");
	gtk_window_set_default_size(GTK_WINDOW(window),260,150);
	gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
	gtk_container_set_border_width(GTK_CONTAINER(window),15);


	icon = create_pixbuf("hash_icon.png");
	gtk_window_set_icon(GTK_WINDOW(window),icon);

	entry.input = gtk_entry_new();
	entry.hash = gtk_entry_new();
	gtk_editable_set_editable(GTK_EDITABLE(entry.hash),false);
	vbox = gtk_vbox_new(FALSE,5);
	valign = gtk_alignment_new(0,1,0,0);

	gtk_container_add(GTK_CONTAINER(vbox),valign);
	gtk_container_add(GTK_CONTAINER(vbox),entry.input);
	gtk_container_add(GTK_CONTAINER(vbox),entry.hash);
	gtk_container_add(GTK_CONTAINER(window),vbox);

	hbox = gtk_hbox_new(true,3);
	button_md5 = gtk_button_new_with_label("MD5 hash");
	button_sha1 = gtk_button_new_with_label("SHA-1 hash");
	button_sha256 = gtk_button_new_with_label("SHA-256 hash");
	//button =gtk_button_new_with_mnemonic("_Button");
	g_signal_connect(G_OBJECT(button_md5),"clicked",G_CALLBACK(button_md5_clicked),&entry);
	g_signal_connect(G_OBJECT(button_sha1),"clicked",G_CALLBACK(button_sha1_clicked),NULL);
	g_signal_connect(G_OBJECT(button_sha256),"clicked",G_CALLBACK(button_sha256_clicked),NULL);
	gtk_widget_set_tooltip_text(button_md5,"calcutate the MD5 disget of the text");
	gtk_widget_set_tooltip_text(button_sha1,"calculate the SHA1 digest of the text");
	gtk_widget_set_tooltip_text(button_sha256,"calculate the SHA-256 digest of the text");


	//gtk_box_pack_start(GTK_BOX(vbox),button_md5,TRUE,TRUE,0);
	//gtk_box_pack_start(GTK_BOX(vbox),button_sha1,TRUE,TRUE,0);

	gtk_container_add(GTK_CONTAINER(hbox),button_md5);
	gtk_container_add(GTK_CONTAINER(hbox),button_sha1);
	gtk_container_add(GTK_CONTAINER(hbox),button_sha256);
	halign = gtk_alignment_new(0,1,0,0);
	gtk_container_add(GTK_CONTAINER(halign),hbox);
	gtk_container_add(GTK_CONTAINER(vbox),halign);
	gtk_box_pack_start(GTK_BOX(vbox),halign,FALSE,FALSE,0);
	gtk_widget_show_all(window);

	g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);
	gtk_main();

	g_object_unref(icon);
	return 0;
}

