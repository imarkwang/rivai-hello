hello:
	riscv64-unknown-elf-gcc hello.c -o hello.elf -T hello_64.ld
	riscv64-unknown-elf-objdump -xD hello.elf > hello.dump

helloec:
	riscv64-unknown-elf-gcc helloec.c -o helloec.elf -T hello_64.ld
	riscv64-unknown-elf-objdump -xD helloec.elf > helloec.dump

hello.ld:
	riscv64-unknown-elf-gcc hello.c -o hello.elf -Wl,--verbose > hello.ld

run:
	spike --pc=0x40011c00 ++$(PROJ_ROOT)/tool/riscv/riscv64-unknown-elf/bin/pk_4k ++hello.elf ++load_pk |& tee run.log
	#spike-32 --pc=0x40000000 ++$(PROJ_ROOT)/tool/riscv/riscv32-unknown-elf/bin/pk ++hello.elf ++load_pk |& tee run.log

clean:
	rm -rf *.elf *.dump *.log
