BDIR = bin
CONFDIR = conf

KERNELIMAGE = stark_os.bin
KERNELISO = stark_os.iso
GRUBCONF = grub.cfg

.PHONY: all run kernel clean

all: clean kernel
	mkdir -p isodir/boot/grub
	cp $(BDIR)/$(KERNELIMAGE) isodir/boot/$(KERNELIMAGE)
	cp $(CONFDIR)/$(GRUBCONF) isodir/boot/grub/$(GRUBCONF)
	grub-mkrescue -o isodir/$(KERNELISO) isodir

run: all
	./run.sh

kernel:
	mkdir -p $(BDIR)
	$(MAKE) -C kernel/

clean:
	$(MAKE) -C kernel/ clean
	rm -rf isodir
	rm -rf $(BDIR)

