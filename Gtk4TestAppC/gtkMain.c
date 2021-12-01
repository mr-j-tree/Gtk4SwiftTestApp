//
//  gtkMain.c
//  Gtk4SwiftTestApp
//
//  Created 01/12/2021.
//

#include "gtkMain.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#include <gtk/gtk.h>
#pragma clang diagnostic pop

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
    g_print ("Hello World\n");
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *box;
    
    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "A working Swift / GTK4 Test app!");
    gtk_window_set_default_size (GTK_WINDOW (window), 640, 360);
    
    box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_halign (box, GTK_ALIGN_CENTER);
    gtk_widget_set_valign (box, GTK_ALIGN_CENTER);
    
    gtk_window_set_child (GTK_WINDOW (window), box);
    
    // In this example, Swift is providing the String contents of the button via argv[0] as a (const char *) pointer to a properly terminated C string, which (importantly) only exists for the lifetime of the call to main_c(). Refer to Apple's WWDC session "Unsafe Swift" at https://developer.apple.com/wwdc20/10648 for a killer explanation of how all that stuff works.
    button = gtk_button_new_with_label ((const char *)user_data);
    
    g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
    g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_window_destroy), window);
    
    gtk_box_append (GTK_BOX (box), button);
    
    gtk_widget_show (window);
}

int main_c (int argc, char **argv) {
    GtkApplication *app;
    int status;
    
    const char * versionFromSwift = argv[0];
    
    app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), (gpointer) versionFromSwift);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);
    
    return status;
}
