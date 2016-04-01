/*
 * s2nHeader.h
 *
 *  Created on: 2016-3-30
 *      Author: root
 */

#ifndef S2NHEADER_H_
#define S2NHEADER_H_

extern "C"
{
#include "api/s2n.h"
#include "crypto/s2n_hash.h"
}
#include <iostream>
#include <cstring>
using namespace std;

#include <gtk/gtk.h>

struct EntryStruct{
	GtkWidget*input;
	GtkWidget *hash;
};

GdkPixbuf *create_pixbuf(const char *filename);
void button_md5_clicked(GtkWidget *widget,gpointer window);
void button_sha1_clicked(GtkWidget *widget,gpointer window);
void button_sha256_clicked(GtkWidget *widget,gpointer window);

void ByteToHexStr(const unsigned char* input,int input_length,char* output);

#endif /* S2NHEADER_H_ */
