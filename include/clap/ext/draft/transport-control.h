#pragma once

#include "../../plugin.h"

// This extension let the plugin submit transport requests to the host

static CLAP_CONSTEXPR const char CLAP_EXT_CV[] = "clap.transport-control.draft/0";

#ifdef __cplusplus
extern "C" {
#endif

typedef struct clap_host_transport_control {
   // Jumps back to the start point and starts the transport
   // [main-thread]
   void (*request_start)(const clap_host_t *host);

   // If not playing, starts the transport from its current position
   // [main-thread]
   void (*request_continue)(const clap_host_t *host);

   // If playing, stops the transport at the current position
   // [main-thread]
   void (*request_pause)(const clap_host_t *host);

   // Stops the transport, and jumps to the start point
   // [main-thread]
   void (*request_stop)(const clap_host_t *host);

   // Jumps the transport to the given position.
   // Does not start the transport.
   // [main-thread]
   void (*request_jump)(const clap_host_t *host, clap_beattime position);

   // Equivalent to what "space bar" does with most DAW
   // [main-thread]
   void (*request_toggle_play)(const clap_host_t *host);
} clap_host_transport_control_t;

#ifdef __cplusplus
}
#endif
