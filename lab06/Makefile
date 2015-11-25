USER_RA = 157104
ASSEMBLIES = ra$(USER_RA).s
OBJECTS = $(ASSEMBLIES:.s=.o)
ASSEMBLER_PATH = arm-eabi-as
LINKER_PATH = arm-eabi-ld
SIMULATOR_PATH = armsim_player
SD_MAKER_PATH = mksd.sh
PLAYER_= /home/specg12-1/mc404/simulador/set_path_player.sh
SO_PATH = /home/specg12-1/mc404/simulador/simulador_player/bin/knrl
ROM_PATH = /home/specg12-1/mc404/simulador/simulador_player/bin/dumboot.bin
TTEXT=0x77802000
TDATA=0x77802100


build: link
	$(SD_MAKER_PATH) --so $(SO_PATH) --user ra$(USER_RA).x

link: $(OBJECTS)
	$(LINKER_PATH) $(OBJECTS) -o ra$(USER_RA).x -Ttext=$(TTEXT) -Tdata=$(TDATA)

%.o: %.s
	$(ASSEMBLER_PATH) $< -o $@

test: build
	-$(SIMULATOR_PATH) --rom=$(ROM_PATH) --sd=disk.img > ra$(USER_RA).out

clean:
	rm -f $(OBJECTS) ra$(USER_RA).x disk.img ra$(USER_RA).out ra$(USER_RA).tar.gz
