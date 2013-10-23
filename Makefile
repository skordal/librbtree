# librbtree - Red-black tree library
# Written by Kristian Klomsten Skordal 2013 <kristian.skordal@gmail.com>
# Report bugs and issues on <http://github.com/skordal/librbtree>
.PHONY: all clean

# Build tools:
CC      ?= gcc
INSTALL ?= install
LIBTOOL ?= libtool

# Install directories:
PREFIX      ?= /usr/local
INCLUDE_DIR ?= $(PREFIX)/include
LIBRARY_DIR ?= $(PREFIX)/lib

# Build flags:
CFLAGS  += -Wall -O2 -g
LDFLAGS += -rpath $(LIBRARY_DIR)

all: librbtree.la rbtree_test

clean:
	$(LIBTOOL) --mode=clean $(RM) -f librbtree.la rbtree.lo

install: librbtree.la
	$(INSTALL) rbtree.h $(INCLUDE_DIR)
	$(LIBTOOL) --mode=install $(INSTALL) librbtree.la $(LIBRARY_DIR)

uninstall:
	$(RM) -f $(INCLUDE_DIR)/rbtree.h
	$(LIBTOOL) --mode=uninstall $(RM) -f $(LIBRARY_DIR)/librbtree.la

rbtree_test: librbtree.la rbtree_test.c
	$(LIBTOOL) --mode=link --tag=CC $(CC) $(CFLAGS) $(LDFLAGS) -o rbtree_test rbtree_test.c librbtree.la

librbtree.la: rbtree.o
	$(LIBTOOL) --mode=link --tag=CC $(CC) $(CFLAGS) $(LDFLAGS) -version-info 1:0:0 -o librbtree.la rbtree.lo

rbtree.o: rbtree.h rbtree.c
	$(LIBTOOL) --mode=compile --tag=CC $(CC) $(CFLAGS) -o rbtree.o -c rbtree.c

test_rbtree: librbtree.la test_rbtree.c

