# HueVita

### Controls your Hue bridge with your favorite console

Use a phone or your voice to controls your lights isn't what you want because you love your PSVita.

HueVita allows you to controls with your PSVita system your lights and so, your life.

## Changelog

### Version 1.0 - First Version

- Initial Release

## F.A.Q

### Can I use HueVita remotely, not connected to the wifi where the Hue bridge is connected ?

Currently, the application doesn't support remote controls where you are not connected to your own wifi.

### Where can I download it?

You can download [here](https://github.com/Applelo/SwitchSD2Vita/releases) and install like any like Vita homebrew.


### Can I use without Hue bridge?
No. Why? Because... Ok :)

## Build
Install **VitaSDK** with [**VDPM**](https://github.com/vitasdk/vdpm) and run the followed commands :

```shell
cmake .
make
```

You can also use this followed commands to send directly built files :

```shell
#send eboot.bin file with FTP
make send
#send vpk with FTP
make send_vpk
#copy eboot.bin file with USB
make copy
#send vpk with USB
make copy_vpk
#emulate in Vita3K but doesn't work :p
make emulate
```

## Credits

* Developped & maintained by *Applelo*
* Thanks to *devingDev* for the Touch, Pad & IME classes
* My master, *MisterAlex*
