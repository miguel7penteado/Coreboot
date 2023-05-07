
# Inside an Open Source BIOS

## coreboot and FSP

### bootblock
An x86 processor starts by fetching some code from the motherboard flash and execute it. In coreboot, this stage is called bootblock.

At this point the processor has almost no knowledge of its peripheral sometime not even the flash controller! (In that case, the first fetch is done automatically by the hardware).

So the bootblock configure the flash controller if needed: mostly mapping the flash in the memory space for reading only. It can configure the console on an UART port to help debugging. Then it passes to the next stage called romstage.

At the end of bootblock the system enabled components are CPU (partial) and Flash (read-only) as shown on the following figure:
http://silicone.homelinux.org/wp-uploads/2018/04/system-view-flash.svg

### romstage

Now the processor has access to the full flash so it can fetch more code, but it still has no RAM! romstage main purpose is to configure the DDR controller to access the external memory.

In order to run some “normal” executable, some writable memory is needed. With only the flash available so far we will need to find some RAM!

### Cache as Ram (CAR)

There is some memory available inside the CPU: the caches. So the idea behind CAR is to configure the cache so that code can use it as its ram. Then once the external RAM is available, the important values are copied to RAM and the cache is configured back as a cache.

### Memory Initialisation

The memory initialisation is a complex process, this part is mostly provided as binary by the CPU vendor. In our case we use Intel FSP for the memory initialisation.

The FSP is a binary provided by Intel to handle the specificities of the SoC.

Here coreboot calls the part called FSP_M. It will initialise the SoC and configure the memory Controller. Once done, it returns to coreboot. coreboot will then start the next stage: ramstage.

At the end of romstage the system enabled components are CPU (partial), Flash and RAM as shown on the following figure:
http://silicone.homelinux.org/wp-uploads/2018/04/system-view-ram.svg

### ramstage

In ramstage the CPU finally has access to external memory, it will now initialize the remaining specific hardware component.

### Inicialização MultiProcessador

Modern CPU have more than one core, the other cores need to be started, this is done during ramstage.

During that phase the SMM handler are setup (Note that coreboot is managing SMM not FSP, this is good news for security).

### Barramento PCI

Here again we used Intel’s help to setup the peripheral in the right state. This is done by calling FSP again, the part is now FSP_S for Silicon Initialisation.

Once prepared, coreboot does the configuration of the peripheral. This is where the PCI enumeration takes place. For each device coreboot will do the required configuration so that the device will function at later stage. Note that for most of them coreboot does not have a driver, this is left for the payload.

Then FSP_S need to be notified so it can further update the configuration of some devices. (Well it’s binary only so we don’t really know what it does).

### Tables generation

coreboot then prepare the different information tables:

ACPI: Mainly used for power management,
SMBIOS: Used for configuration management and inventory (read by dmidecode under linux).

### Preparing to call the payload
Again FSP_S need to be notified that we will leave coreboot, it will mainly protect some configuration registers to prevent further configuration.

coreboot also can protect some registers to prevent the OS from changing them and risking damaging the hardware (like changing the configuration of general purpose pins that are connected on the board).

At last coreboot calls the payload, in our case Tianocore’s coreboot payload package.

At the end of ramstage all system components are enabled as shown on the following figure:
http://silicone.homelinux.org/wp-uploads/2018/04/system-view-full.svg

## Tianocore

So Tianocore is used to boot the OS using the uEFI interface. I wont go into details here, uEFI would need a full article to describe 🙂
Here the early board bringup is done by coreboot so the PEI phase in uEFI will be reduced to the minimum.

## Development

### On coreboot
The development on coreboot was first to adapt the configuration to our board:

GPIO configurations
Add BMC interface
Add secure update process (Allow Flash access only when authorized by BMC)
Then we had to enable the CPU features:

Power Configuration (Enable SpeedStep and Turbo)
Enable FastStrings
Confiure and enable Machine Check Exceptions
Allow the UART to use the Legacy Address
Finally we completed the ACPI and SMBIOS implementation:

ACPI tables for cpu power management (C-States, P-States and T-States),
ACPI description of the UART Interrupt which is not the standard one,
SMBIOS description of the memory DIMM modules,
SMBIOS description of the system (serial number, node location in chassis…).
We’d like to thank Intel and their support team that assisted us in these tasks.

### On Tianocore

In Tianocore we mainly enabled existing feature by creating a specific package that use the coreboot payload package and extend it with:

Network stack and network driver,
NVMe Drivers.
Support for Console (UART) and SATA was already enabled.

This really was just a matter of enabling some modules that are already available. Looking how they where integrated in OVMF was a great help.

## Contribuições
Now that Intel published the initial support for the denverton SoC, we ported all our change to the current coreboot master and started to upstream them.

The basic support of the board and the UART configuration have been accepted in coreboot already.

Adding all the features as described above is still work in progress: The patches have been submitted and the review are in progress.

You can see our accepted contributions on coreboot’s git.

