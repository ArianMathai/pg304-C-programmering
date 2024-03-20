# makefile template

INCLDIR = ./include
TARGET = myAlloc
CC = gcc
CFLAGS = -O2
CFLAGS += -I$(INCLDIR)

OBJDIR = obj

_DEPS = myAlloc.h
DEPS = $(patsubst %,$(INCLDIR)/%,$(_DEPS))

_OBJS = myAlloc.o main.o
OBJS = $(patsubst %,$(OBJDIR)/%,$(_OBJS))

$(OBJDIR)/%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)


$(TARGET): $(OBJS)
		$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
		rm -f $(OBJDIR)/*.o *~ core $(INCLDIR)/*