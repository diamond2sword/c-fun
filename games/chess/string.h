#pragma once

#include <string.h>
#include <stdint.h>

typedef struct {
	char* chars;
	uint16_t length;	
} String;
#define __STRING_LENGTH(s) ((sizeof(s) / sizeof((s)[0])) - sizeof((s)[0]))
#define __ENSURE_STRING_LITERAL(x) ("" x "")
#define STRING(string) (__INIT(String) { .length = __STRING_LENGTH(__ENSURE_STRING_LITERAL(string)), .chars = (string) })
#define STRING_CONST(string) { .length = __STRING_LENGTH(__ENSURE_STRING_LITERAL(string)), .chars = (string) }
#define __INIT(type) (type)
