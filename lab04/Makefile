USER_RA = 157104
ASSEMBLIES = ra$(USER_RA).s
OBJECTS = $(ASSEMBLIES:.s=.o)
ASSEMBLER_PATH = /home/specg12-1/mc404/simulador/arm-eabi-4.4.3/bin/arm-eabi-as
LINKER_PATH = /home/specg12-1/mc404/simulador/arm-eabi-4.4.3/bin/arm-eabi-ld
SIMULATOR_PATH = /home/specg12-1/mc404/simulador/bin/arm-sim
SD_MAKER_PATH = /home/specg12-1/mc404/simulador/bin/mksd.sh
SO_PATH = /home/specg12-1/mc404/simulador/dummyos.elf
ROM_PATH = /home/specg12-1/mc404/simulador/dumboot.bin
TTEXT=0x77802000
TDATA=0x77802050

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