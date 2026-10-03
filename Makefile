CROSS   ?= arm-none-eabi-
CC      := $(CROSS)gcc
OBJCOPY := $(CROSS)objcopy
SIZE    := $(CROSS)size

CFLAGS  := -mcpu=cortex-a8 -marm -mfloat-abi=soft -O2 -ffreestanding -nostdlib -Wall -Wextra -Wall -Werror -Wpedantic -Wnull-dereference -Wextra -Wunreachable-code -Wpointer-arith -Wmissing-include-dirs -Wstrict-prototypes -Wunused-result -Waggregate-return -Wredundant-decls -Wanalyzer-use-of-uninitialized-value -fanalyzer -fanalyzer-verbose-edges -MMD -MP
LDFLAGS := -T am335x.ld -nostdlib -nostartfiles
INCLUDE := -I ./include/

all: dirmake ./bin/MLO

./build/main.elf: ./src/startup.s ./src/main.c ./src/am335x_registers.c am335x.ld
	$(CC) $(CFLAGS) $(LDFLAGS) ${INCLUDE} ./src/startup.s ./src/main.c ./src/am335x_registers.c -o ./build/main.elf
	$(SIZE) ./build/main.elf

./bin/MLO: ./build/main.elf
	$(OBJCOPY) -O binary ./build/main.elf ./bin/MLO

cleanall:
	rm -rf ./build ./bin

clean:
	rm -rf ./build

dirmake:
	mkdir -p ./build 
	mkdir -p ./bin
