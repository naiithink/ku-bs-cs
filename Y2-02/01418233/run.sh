#! /usr/bin/env bash
# xterm-256color

stty sane
export TERM='vt100'

MODE_GUI='GUI - Graphical User Interface'
MODE_CLI='CLI - Command Line Interface'
MODES=("$MODE_GUI" "$MODE_CLI")

run() {
    GRAPHIC_OPT=${1:-''};
    qemu-system-i386 \
        -machine pc \
        -cpu 486 \
        -m 64M \
        -hda "./local_disk_c.qcow2" \
        -drive "file=fat:rw:./D,media=disk" \
        $1
}

echo "SELECT MODE:";
select MODE in "${MODES[@]}"
do
    case $MODE in
        "$MODE_GUI")
            echo "\
--------------------------------------------------------------------------------
Look for a newly created QEMU window.

To release the cursor,
    press 'Control-Option-Command-G' or 'Ctrl-Alt-Win-G'.
To hault MS-DOS,
    just terminate the process by 'Control-C' down here
    or hit the 'X' button on the QEMU window.
--------------------------------------------------------------------------------\n";
            run;
            break;
            ;;
        "$MODE_CLI")
            run "-nographic -serial mon:stdio";
            break;
            ;;
        *)
            echo "WTF did you choose?";
            exit 1;
            ;;
    esac
done
