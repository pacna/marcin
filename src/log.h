#ifndef LOG__
#define LOG__

#define RED "\x1B[31m"
#define YELLOW "\x1B[33m"
#define GREEN "\x1B[32m"

extern void log_error_with_added_text(char *text, const char *added_text);
extern void log_error(char *text);
extern void log_warn(char *text);
extern void log_success(char *text);

#endif