SRC := sample1.c
OBJ := $(patsubst %.c,%.o,$(SRC))
DEP := $(patsubst %.c,%.d,$(SRC))
PROG := $(patsubst %.c,%,$(SRC))

CFLAGS+=`sdl2-config --cflags` `pkg-config glesv2 --cflags` -I. -I/opt/vc/include
LDFLAGS+=`sdl2-config --libs` `pkg-config glesv2 --libs` -L/opt/vc/lib -lm -lpthread -lbcm_host

all: $(DEP)
	@$(MAKE) $(PROG)

clean:
	@$(RM) $(DEP) $(OBJ) $(PROG)

ifneq ($(filter clean,$(MAKECMDGOALS)),clean)
-include $(DEP)
endif

%.d: %.c
	$(info GEN $@)
	@$(CC) -MM $(CFLAGS) $< | sed 's/\($*\)\.o[ :]*/\1.o $@ : /g' > $@

%: %.d

