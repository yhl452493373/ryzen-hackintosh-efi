# ryzen-hackintosh-efi for macOS mojave 10.14.6(not test on other version)

--- 

hackintosh efi for ryzen 1700x and msi krait gaming x370
this is my hardware

* cpu: ryzen r7 1700x
* matherboard: msi krait gaming x370
* graphic card:rx vega64
* hard disk:1 nvme ssd,1 nvme ssd on pci card,2 sata ssd with windows dynamic disk,1 sata ssd
* memery:8g x 4

--- 

what work:

* onboard network
* onboard audio
* graphic card(don't  need drive)
* power manage under apple menu(shutdown,reboot,sleep,weakup)
* all usb port(include usb3.0 and usb2.0)

---

not work:

* power button (when press to shutdown)
* all softwares which can‘t run with amd cup(photoshop,vmware etc)
* can not show cpu model.(display as unknow,you can modify it by yourself)

---

unknow:

* front audio jack
* microphone jack

---

BIOS(if you can find):
* Spread Spectrum:AUTO
* Serial:Disable
* Parallel:Disable
* XHCI:Enable
* EHCI:Enable
* Sata Mode:ACHI
* IDE:Disable
* IOMMU:Disable
* Boot Mode:UEFI Only
* CSM:Disable

