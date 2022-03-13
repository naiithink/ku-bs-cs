<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="B" />
        <signal name="A" />
        <signal name="X" />
        <signal name="Y" />
        <port polarity="Input" name="B" />
        <port polarity="Input" name="A" />
        <port polarity="Output" name="X" />
        <port polarity="Output" name="Y" />
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
        <block symbolname="and2" name="XLXI_1">
            <blockpin signalname="B" name="I0" />
            <blockpin signalname="A" name="I1" />
            <blockpin signalname="X" name="O" />
        </block>
        <block symbolname="xor2" name="XLXI_2">
            <blockpin signalname="A" name="I0" />
            <blockpin signalname="B" name="I1" />
            <blockpin signalname="Y" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="736" y="384" name="XLXI_1" orien="R0" />
        <instance x="752" y="560" name="XLXI_2" orien="R0" />
        <branch name="B">
            <wire x2="704" y1="320" y2="320" x1="480" />
            <wire x2="736" y1="320" y2="320" x1="704" />
            <wire x2="704" y1="320" y2="432" x1="704" />
            <wire x2="752" y1="432" y2="432" x1="704" />
        </branch>
        <branch name="A">
            <wire x2="640" y1="256" y2="256" x1="480" />
            <wire x2="736" y1="256" y2="256" x1="640" />
            <wire x2="640" y1="256" y2="496" x1="640" />
            <wire x2="752" y1="496" y2="496" x1="640" />
        </branch>
        <branch name="X">
            <wire x2="1024" y1="288" y2="288" x1="992" />
        </branch>
        <branch name="Y">
            <wire x2="1024" y1="464" y2="464" x1="1008" />
        </branch>
        <iomarker fontsize="28" x="480" y="256" name="A" orien="R180" />
        <iomarker fontsize="28" x="1024" y="288" name="X" orien="R0" />
        <iomarker fontsize="28" x="480" y="320" name="B" orien="R180" />
        <iomarker fontsize="28" x="1024" y="464" name="Y" orien="R0" />
    </sheet>
</drawing>