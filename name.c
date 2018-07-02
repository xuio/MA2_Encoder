#include "usb_names.h"

// set MIDI name

#define MIDI_NAME   {'M','A','2',' ','E','N','C','O','D','E','R'}
#define MIDI_NAME_LEN  11

struct usb_string_descriptor_struct usb_string_product_name = {
        2 + MIDI_NAME_LEN * 2,
        3,
        MIDI_NAME
};
