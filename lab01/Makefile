SOURCES = main.c math.c log.c
ASSEMBLIES = $(SOURCES:.c=.s)
OBJECTS = $(SOURCES:.c=.o)
SYS_PRE_OBJECTS = /lib64/ld-linux-x86-64.so.2 /usr/lib64/crt1.o /usr/lib64/crti.o
SYS_POS_OBJECTS = /usr/lib64/crtn.o
SYS_LIB_PATH = /usr/lib64

%.s: %.c
	gcc -S $< -o $@

%.o: %.s
	as -o $@ $<

%.x: $(OBJECTS)
	ld -dynamic-linker $(SYS_PRE_OBJECTS) -L$(SYS_LIB_PATH) $(OBJECTS) -lc $(SYS_POS_OBJECTS) -o $@

clean:
	rm -f $(ASSEMBLIES) $(OBJECTS) *.x