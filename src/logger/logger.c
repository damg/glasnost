#include "logger.h"

#include <time.h>

const gchar*
glsn_log_level_to_str (const GLSN_LOG_LEVEL_T level)
{
  switch (level)
    {
    case GLSN_LOG_LEVEL_TRACE:
      return "TRACE";
    case GLSN_LOG_LEVEL_DEBUG:
      return "DEBUG";
    case GLSN_LOG_LEVEL_INFO:
      return "INFO";
    case GLSN_LOG_LEVEL_WARN:
      return "WARN";
    case GLSN_LOG_LEVEL_ERROR:
      return "ERROR";
    case GLSN_LOG_LEVEL_FATAL:
      return "FATAL";
    default:
      return "UNKNOWN";
    }
}

glsn_log_entry_t*
glsn_log_entry_init (const GLSN_LOG_LEVEL_T level,
		     time_t timestamp,
		     gchar *component, gchar *message)
{
  glsn_log_entry_t* result = g_malloc (sizeof (glsn_log_entry_t));
  result->level = level;
  result->timestamp = timestamp;
  result->component = g_strdup (component);
  result->message = g_strdup (message);

  return result;
}

void
glsn_log_entry_free (glsn_log_entry_t *e)
{
  if (e)
    {
      g_free (e->component);
      g_free (e->message);
      g_free (e);
    }
}

gchar*
glsn_log_entry_to_str (const glsn_log_entry_t *e)
{
  const gchar* level_s;
  gchar* result;

  if (!e)
    return NULL;

  level_s = glsn_log_level_to_str (e->level);
  result = g_strdup_printf ("[%ld] [%s] (%s) %s",
			    e->timestamp, level_s,
			    e->component, e->message);

  return result;
}

