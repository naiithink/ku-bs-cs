@ECHO OFF

qemu-system-i386 ^
    -machine pc ^
    -cpu 486 ^
    -m 2M ^
    -hda "./local_disk_c.qcow2" ^
    -drive "file=fat:rw:./ASSG,media=disk" & :: ^
    :: -nographic
