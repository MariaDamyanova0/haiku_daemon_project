// master/haiku_master.h
#ifndef HAIKU_MASTER_H
#define HAIKU_MASTER_H

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 100

void start_master(int port, const char *dict_filename, int cooldown);

#endif
