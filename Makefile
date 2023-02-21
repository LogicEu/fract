# utopia makefile

NAME = libfract

CC = gcc
STD = -std=c99
WFLAGS = -Wall -Wextra -pedantic
OPT = -O2 -ffast-math
INC = -I.

SRCDIR = src
TMPDIR = tmp
BINDIR = bin

SCRIPT = build.sh
SRC = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c,$(TMPDIR)/%.o,$(SRC))

OS=$(shell uname -s)
ifeq ($(OS),Darwin)
	DLIB = -dynamiclib
	SUFFIX = .dylib
else
	DLIB = -shared -fPIC
	SUFFIX = .so
endif

TARGET = $(BINDIR)/$(NAME)
LIB = $(TARGET)$(SUFFIX)

CFLAGS = $(STD) $(WFLAGS) $(OPT) $(INC)

$(TARGET).a: $(BINDIR) $(OBJS)
	ar -cr $@ $(OBJS)

.PHONY: shared all clean install uninstall

shared: $(LIB)

all: $(LIB) $(TARGET).a

$(LIB): $(BINDIR) $(OBJS)
	$(CC) $(CFLAGS) $(DLIB) -o $@ $(OBJS)

$(TMPDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS): | $(TMPDIR)

$(TMPDIR):
	mkdir -p $@

$(BINDIR):
	mkdir -p $@

clean: $(SCRIPT)
	./$^ $@

install: $(SCRIPT)
	./$^ $@

uninstall: $(SCRIPT)
	./$^ $@
