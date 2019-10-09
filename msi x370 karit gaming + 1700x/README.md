# 由于我换成了华擎X570+R7 3700X,因此这里不再更新

# because of i have changed my hardware to asrock x570 taichi and r7 3700x,this efi will not be update

# ryzen-hackintosh-efi for macOS mojave 10.14.6(not test on other version)

---

重要: 不要安装在NVME固态硬盘，也不要在NVME固态硬盘上创建MAC可写的硬盘分区

Important: DO NOT INSTALL ON NVME SSD, ALSO DO NOT CREATE MAC WRITABLE PATITION OF NVME SSD

ACPI/patched/SSDT-NVMe.aml是用来将nvme硬盘（黄色图标的硬盘）转换为正确的pcie设备

ACPI/patched/SSDT-NVMe.aml is used to change nvme ssd which the icon is yellow from External to PCIE SSD 

--- 

R7 1700X，微星X370银环蛇，RX VEGA64 黑苹果可用的EFI

hackintosh efi for ryzen 1700x and msi krait gaming x370

硬件规格:

this is my hardware:

* cpu（处理器）: ryzen r7 1700x
* matherboard（主板）: msi krait gaming x370
* graphic card（显卡）:rx vega64
* hard disk（硬盘）:1 nvme ssd（1个nvme固态硬盘）,1 nvme ssd with pci card（1个通过pcie转接的nvme固态硬盘）,2 sata ssd with windows dynamic disk（2个sata固态硬盘，通过windows创建成了动态磁盘【Windows下的软RAID】）,1 sata ssd (MACOS INSTALL HERE)（1个sata接口的固态硬盘，我的mac安装在这个硬盘）
* memery(内存):8g x 4
* wireless network card(无线网卡):bcm943602cdp with pci card(博通943602cdp)

--- 

正常工作:

what work:

* onboard network(板载网卡)
* onboard audio（板载声卡）
* graphic card(don't need drive)(显卡，我的显卡免驱)
* power manage under apple menu(shutdown,reboot,sleep,weakup)（苹果菜单下的电源管理正常，包括重启，睡眠，关机，唤醒都正常）
* front audio jack（机箱前置的音频接口）
* all usb port(include usb3.0 and usb2.0)（所有usb接口正常）
* bcm943602cdp wifi,bluetooth,airdrop(博通943602cdp的wifi,蓝牙,隔空投送都正常)

---

不工作:

not work:

* power button (when login and press power button to shutdown)（进入系统后按机箱电源键没反应）
* all softwares which can‘t run with amd cup(photoshop,vmware etc)（所有用到了intel虚拟化技术的软件不能使用，指令集不同）
* can not show cpu model.(display as unknow,you can modify it by yourself)（CPU型号显示未知，这个可以自定义）
* memory frequency read error,just a half(内存频率读取有问题，只能读取到运行频率的1/2)

---

未知：

unknow:

* microphone jack（no devices）（麦克风接口，没有设备测试）

---

BIOS升级到E7A33AMS.1JM及以上，获取更好体验

BIOS Version is better update to E7A33AMS.1JM or above(the newest bios)

BIOS设置（基于版本 E7A33AMS.1JM）：

BIOS(Base on E7A33AMS.1JM):

Advanced Tab:
* Integrated Peripherals -> SATA Mode: ACHI Mode
* USB Configuration -> XHCI Hand-off: Disable
* USB Configuration -> Legacy USB Support: Auto
* Super IO Configuration -> Serial Port 0 Configuration -> Serial Port: Disable
* Super IO Configuration -> Parallel Port 0 Configuration -> Parallel Port: Disable
* Windows  OS Configuration -> BIOS UEFI/CSM Mode: UEFI
* Windows  OS Configuration -> Secure Boot: Disable
---

其他黑苹果机型：https://github.com/daliansky/Hackintosh
