/*
 * Graphics.cpp
 *
 *  Created on: 2016-3-31
 *      Author: root
 */

#include "s2nHeader.h"


void button_md5_clicked(GtkWidget *widget,gpointer p){
	struct EntryStruct *entry;
	const gchar *context;
	char *hash,*hash_str;
	int context_len;
	s2n_hash_algorithm alg=S2N_HASH_MD5;
	s2n_hash_state state;

	entry = (struct EntryStruct*)p;
	context = gtk_entry_get_text((GtkEntry*)entry->input);
	context_len=strlen(context);

	hash = new gchar[MD5_DIGEST_LENGTH+1];
	hash_str = new char[MD5_DIGEST_LENGTH*2+1];
	s2n_hash_init(&state,alg);
	s2n_hash_update(&state,(char*)context,context_len);
	s2n_hash_digest(&state,(char*)hash,MD5_DIGEST_LENGTH);
	ByteToHexStr((const unsigned char*)hash,16,hash_str);
	hash_str[MD5_DIGEST_LENGTH*2]='\0';

	gtk_entry_set_text((GtkEntry*)entry->hash,(const char*)hash_str);
	//context = gtk_entry_get_text();
	g_print("button md5 clicked\n");
}

void button_sha1_clicked(GtkWidget *widget,gpointer window){
	g_print("button sha1 clicked\n");
}

void button_sha256_clicked(GtkWidget *widget,gpointer window){
	g_print("button sha256 clicked\n");
}

GdkPixbuf *create_pixbuf(const char *filename){
	GdkPixbuf *pixbuf;
	GError *error = NULL;
	pixbuf = gdk_pixbuf_new_from_file(filename,&error);
	if(!pixbuf){
		fprintf(stderr,"%s\n",error->message);
		g_error_free(error);
	}
	return pixbuf;
}

void ByteToHexStr(const unsigned char* input,int input_length,char* output){
	char high,low;
	for(int i=0;i<input_length;i++){
		high = input[i]>>4;
		low = input[i]&0x0f;
		if(high>0x09){
			high-=0x09;
			high=high|0x40;
		}
		else
			high= high|0x30;
		if(low>0x09){
			low-=0x09;
			low|=0x40;
		}
		else
			low|=0x30;
		output[i*2]=high;
		output[i*2+1]=low;
	}
}

