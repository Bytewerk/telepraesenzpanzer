CC=avr-gcc
CFLAGS += -Os -mmcu=atmega32 -DF_CPU=8000000UL -std=c99 -Wall #-pedantic

TARGET=rp6
SOURCE=$(wildcard *.c)

OBJS=$(SOURCE:.c=.o)

$(TARGET): $(OBJS) $(DEPS)
	@printf "LINKING \033\13301;33m-\033\13301;37m %-20s\n\033\13300;39m" $@
	@$(CC) $(CFLAGS) $(LDFLAG) -o $(TARGET).elf $(OBJS) $(LIBS)

	@printf "MAKING HEX \033\13301;33m-\033\13301;37m %-20s\n\033\13300;39m" $@
	@avr-objcopy -O ihex $(TARGET).elf $(TARGET).hex

	@printf "MAKING BIN \033\13301;33m-\033\13301;37m %-20s\n\033\13300;39m" $@
	@avr-objcopy -O binary $(TARGET).elf $(TARGET).bin

%.o: %.c $(DEPS)
	@printf "CC \033\13301;33m-\033\13301;37m %-20s\n\033\13300;39m" $@
	@$(CC) -c $(CFLAGS) -o $@ $< $(INCLUDES)

flash:
	#avrdude -c mcprog -p m32 -U flash:w:$(TARGET).hex
	avrdude -c mcprog -p m32 -x clockrate=125000  -U flash:w:$(TARGET).hex
clean:
	rm *.o
	rm *.elf
	rm *.hex
	rm *.bin

.PHONY: doc clean
