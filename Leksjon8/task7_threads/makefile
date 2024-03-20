# makefile template

INCLDIR = ./include
TARGET = task7
CC = gcc
CFLAGS = -O2
CFLAGS += -I$(INCLDIR)
TFLAG = -lpthread -lrt

LIBDIR = ../my-C-Debugger
LDFLAGS = -L$(LIBDIR) -lcoolBananaLogger

OBJDIR = obj

_DEPS = coolBananaLogger.h threadBuf.h
DEPS = $(patsubst %,$(INCLDIR)/%,$(_DEPS))

_OBJS = task7_threads.o
OBJS = $(patsubst %,$(OBJDIR)/%,$(_OBJS))



$(OBJDIR)/%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)


$(TARGET): $(OBJS)
		$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) $(TFLAG)

.PHONY: clean
clean:
		rm -f $(OBJDIR)/*.o *~ core $(INCLDIR)/*