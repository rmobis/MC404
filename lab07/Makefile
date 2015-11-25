MAKEFLAGS += --no-builtin-rules

EXECUTABLE = robot_ctrl
SOURCES = main.c
ASSEMBLIES = main.s api_robot.s
OBJECTS = $(ASSEMBLIES:.s=.o)
COMPILER_PATH = arm-eabi-gcc
ASSEMBLER_PATH = arm-eabi-as
LINKER_PATH = arm-eabi-ld
SIMULATOR_PATH = armsim_player
SD_MAKER_PATH = mksd.sh
SO_PATH = /home/specg12-1/mc404/simulador/simulador_player/bin/knrl
ROM_PATH = /home/specg12-1/mc404/simulador/simulador_player/bin/dumboot.bin
TTEXT = 0x77802000
ARCHIVE_FILE = ra157104.tar.gz
ARCHIVES = main.c api_robot.h api_robot.s Makefile

build: link
	$(SD_MAKER_PATH) --so $(SO_PATH) --user $(EXECUTABLE)

link: $(OBJECTS)
	$(LINKER_PATH) $(OBJECTS) -o $(EXECUTABLE) -Ttext=$(TTEXT)

%.o: %.s
	$(ASSEMBLER_PATH) $< -o $@

%.s: %.c
	$(COMPILER_PATH) $< -S -o $@

archive:
	tar -cvzf $(ARCHIVE_FILE) $(ARCHIVES)

clean:
	rm -f $(OBJECTS) main.s $(EXECUTABLE) disk.img $(ARCHIVE_FILE)
