# makefile template

INCLDIR = ./include
TARGET = task1
CC = gcc
CFLAGS = -O2
CFLAGS += -I$(INCLDIR)

LIBDIR = ../../my-C-Debugger
LDFLAGS = -L$(LIBDIR) -lcoolBananaLogger

OBJDIR = obj

_DEPS = coolBananaLogger.h
DEPS = $(patsubst %,$(INCLDIR)/%,$(_DEPS))

_OBJS = task1.o
OBJS = $(patsubst %,$(OBJDIR)/%,$(_OBJS))



$(OBJDIR)/%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)


$(TARGET): $(OBJS)
		$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean
clean:
		rm -f $(OBJDIR)/*.o *~ core $(INCLDIR)/*