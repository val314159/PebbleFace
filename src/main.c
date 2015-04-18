#include <pebble.h>
#include "main.h"
static Window *s_main_window=0;
static TextLayer *s_time_layer=0;
static void main_window_load(Window *window) {
   // Create time TextLayer
  s_time_layer = text_layer_create(GRect(0, 55, 144, 50));
  text_layer_set_background_color(s_time_layer, GColorClear);
  text_layer_set_text_color(s_time_layer, GColorBlack);
  text_layer_set_text(s_time_layer, "val: hello\nannebot: why, hello there.\nval gives annebot a kiss!");

  // Improve the layout to be more like a watchface
  //text_layer_set_font(s_time_layer, fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD));
  //text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);

  // Add it as a child layer to the Window's root layer
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_time_layer));
}
static void main_window_unload(Window *window) {
   text_layer_destroy(s_time_layer);
}
static void init() {
  s_main_window = window_create();
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });
  window_stack_push(s_main_window, /*animated=*/true);
}
static void deinit() {  
   window_destroy(s_main_window);
}
int main() {
  init();
  app_event_loop();
  deinit();
}