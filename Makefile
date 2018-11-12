CC        = gcc
CFLAGS    = -g
DEPS      = simpleprime.h
MKDIR_P   = mkdir -p

PROG_NAME = primechecker

ODIR      = build
_OBJ      = main.o simpleprime.o aks.o
OBJ       = $(patsubst %, $(ODIR)/%,$(_OBJ))


.PHONY: directories
.PHONY: clean

all: directories $(PROG_NAME)

directories: $(ODIR)

clean:
		rm -rf $(ODIR) $(PROG_NAME)

$(ODIR):
		$(MKDIR_P) $(ODIR)

$(ODIR)/%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

$(PROG_NAME): $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)

