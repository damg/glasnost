#ifndef __GLASNOST_LOGGER_LOGGER_H__
#define __GLASNOST_LOGGER_LOGGER_H__

#include <glib.h>

enum GLSN_LOG_LEVEL_E
  {
    GLSN_LOG_LEVEL_TRACE,
    GLSN_LOG_LEVEL_DEBUG,
    GLSN_LOG_LEVEL_INFO,
    GLSN_LOG_LEVEL_WARN,
    GLSN_LOG_LEVEL_ERROR,
    GLSN_LOG_LEVEL_FATAL
  };

typedef enum GLSN_LOG_LEVEL_E GLSN_LOG_LEVEL_T;

/*! \brief Converts a GLSN_LOG_LEVEL_T value to its string representation. 

  \return String representation.
  \note The returned string is a static constant.
*/
const gchar*
glsn_log_level_to_str (const GLSN_LOG_LEVEL_T level);

struct glsn_log_entry_s
{
  GLSN_LOG_LEVEL_T level;
  time_t timestamp;
  gchar* component;
  gchar* message;
};

typedef struct glsn_log_entry_s glsn_log_entry_t;

/*! \brief Allocate a new glsn_log_entry_t instance on the heap.
  The component and message strings are being duped.
*/
glsn_log_entry_t*
glsn_log_entry_init (const GLSN_LOG_LEVEL_T level,
		     time_t timestamp,
		     gchar *component, gchar *message);


void
glsn_log_entry_free (glsn_log_entry_t *e);

gchar*
glsn_log_entry_to_str (const glsn_log_entry_t *e);

#endif
