<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="b" />
        <signal name="a" />
        <signal name="x" />
        <signal name="y" />
        <signal name="XLXN_5" />
        <signal name="XLXN_6" />
        <port polarity="Input" name="b" />
        <port polarity="Input" name="a" />
        <port polarity="Output" name="x" />
        <port polarity="Output" name="y" />
        <blockdef name="and2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="144" ey="-144" sx="144" sy="-48" r="48" cx="144" cy="-96" />
            <line x2="64" y1="-48" y2="-48" x1="144" />
            <line x2="144" y1="-144" y2="-144" x1="64" />
            <line x2="64" y1="-48" y2="-144" x1="64" />
        </blockdef>
        <blockdef name="xor2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="60" y1="-128" y2="-128" x1="0" />
            <line x2="208" y1="-96" y2="-96" x1="256" />
            <arc ex="44" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <arc ex="64" ey="-144" sx="64" sy="-48" r="56" cx="32" cy="-96" />
            <line x2="64" y1="-144" y2="-144" x1="128" />
            <line x2="64" y1="-48" y2="-48" x1="128" />
            <arc ex="128" ey="-144" sx="208" sy="-96" r="88" cx="132" cy="-56" />
            <arc ex="208" ey="-96" sx="128" sy="-48" r="88" cx="132" cy="-136" />
        </blockdef>
        <block symbolname="and2" name="XLXI_3">
            <blockpin signalname="a" name="I0" />
            <blockpin signalname="b" name="I1" />
            <blockpin signalname="y" name="O" />
        </block>
        <block symbolname="xor2" name="XLXI_4">
            <blockpin signalname="b" name="I0" />
            <blockpin signalname="a" name="I1" />
            <blockpin signalname="x" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <branch name="x">
            <wire x2="1184" y1="288" y2="288" x1="1152" />
        </branch>
        <branch name="y">
            <wire x2="1168" y1="448" y2="448" x1="1152" />
            <wire x2="1184" y1="448" y2="448" x1="1168" />
        </branch>
        <iomarker fontsize="28" x="640" y="256" name="a" orien="R180" />
        <iomarker fontsize="28" x="1184" y="288" name="x" orien="R0" />
        <iomarker fontsize="28" x="640" y="320" name="b" orien="R180" />
        <branch name="a">
            <wire x2="800" y1="256" y2="256" x1="640" />
            <wire x2="896" y1="256" y2="256" x1="800" />
            <wire x2="800" y1="256" y2="480" x1="800" />
            <wire x2="896" y1="480" y2="480" x1="800" />
        </branch>
        <branch name="b">
            <wire x2="864" y1="320" y2="320" x1="640" />
            <wire x2="896" y1="320" y2="320" x1="864" />
            <wire x2="864" y1="320" y2="416" x1="864" />
            <wire x2="896" y1="416" y2="416" x1="864" />
        </branch>
        <instance x="896" y="544" name="XLXI_3" orien="R0" />
        <instance x="896" y="384" name="XLXI_4" orien="R0" />
        <iomarker fontsize="28" x="1184" y="448" name="y" orien="R0" />
    </sheet>
</drawing>