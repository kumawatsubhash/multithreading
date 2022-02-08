SHELL:=/bin/bash

CC = gcc

# File to store Compilation logs
COMPILE_ERROR_LOG = errorLog.txt

all : exeMulThread

csrc = $(wildcard *.c)

exeMulThread : 
	@echo "Multi-Threading Code Running ... "
	@echo "Compiling with : $(CC)"
	$(CC) $(CFLAGS) -o exeMulThread $(csrc) $(CFLAGS) 2>&1 | tee $(COMPILE_ERROR_LOG)


CFLAGS += -w -g -Wall -lm -unroll-aggressive -Winline -D_GNU_SOURCE -lpthread -pthread -O3
CFLAGS += $(WERROR_FLAGS)


.PHONY: clean 
clean:
	clear 	
	rm -rf $(obj) exeMulThread *.txt 
	@echo "All Object Files and executable have been removed"
