<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_2" />
        <signal name="B" />
        <signal name="D" />
        <signal name="E" />
        <signal name="XLXN_8" />
        <signal name="H" />
        <signal name="S" />
        <signal name="XLXN_14" />
        <signal name="XLXN_16" />
        <signal name="XLXN_21" />
        <signal name="XLXN_23" />
        <signal name="XLXN_24" />
        <signal name="XLXN_26" />
        <signal name="Buzzer" />
        <signal name="XLXN_27" />
        <port polarity="Input" name="B" />
        <port polarity="Input" name="D" />
        <port polarity="Input" name="E" />
        <port polarity="Input" name="H" />
        <port polarity="Input" name="S" />
        <port polarity="Output" name="Buzzer" />
        <blockdef name="and3">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="192" y1="-128" y2="-128" x1="256" />
            <line x2="144" y1="-176" y2="-176" x1="64" />
            <line x2="64" y1="-80" y2="-80" x1="144" />
            <arc ex="144" ey="-176" sx="144" sy="-80" r="48" cx="144" cy="-128" />
            <line x2="64" y1="-64" y2="-192" x1="64" />
        </blockdef>
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
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <blockdef name="or4">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="48" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="48" y1="-256" y2="-256" x1="0" />
            <line x2="192" y1="-160" y2="-160" x1="256" />
            <arc ex="112" ey="-208" sx="192" sy="-160" r="88" cx="116" cy="-120" />
            <line x2="48" y1="-208" y2="-208" x1="112" />
            <line x2="48" y1="-112" y2="-112" x1="112" />
            <line x2="48" y1="-256" y2="-208" x1="48" />
            <line x2="48" y1="-64" y2="-112" x1="48" />
            <arc ex="48" ey="-208" sx="48" sy="-112" r="56" cx="16" cy="-160" />
            <arc ex="192" ey="-160" sx="112" sy="-112" r="88" cx="116" cy="-200" />
        </blockdef>
        <block symbolname="and3" name="XLXI_1">
            <blockpin signalname="E" name="I0" />
            <blockpin signalname="S" name="I1" />
            <blockpin signalname="XLXN_2" name="I2" />
            <blockpin signalname="XLXN_24" name="O" />
        </block>
        <block symbolname="and3" name="XLXI_3">
            <blockpin signalname="XLXN_14" name="I0" />
            <blockpin signalname="D" name="I1" />
            <blockpin signalname="B" name="I2" />
            <blockpin signalname="XLXN_23" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_5">
            <blockpin signalname="H" name="I0" />
            <blockpin signalname="XLXN_8" name="I1" />
            <blockpin signalname="XLXN_21" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_6">
            <blockpin signalname="E" name="I0" />
            <blockpin signalname="XLXN_16" name="I1" />
            <blockpin signalname="XLXN_26" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_8">
            <blockpin signalname="B" name="I" />
            <blockpin signalname="XLXN_2" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_16">
            <blockpin signalname="E" name="I" />
            <blockpin signalname="XLXN_8" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_17">
            <blockpin signalname="S" name="I" />
            <blockpin signalname="XLXN_14" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_18">
            <blockpin signalname="D" name="I" />
            <blockpin signalname="XLXN_16" name="O" />
        </block>
        <block symbolname="or4" name="XLXI_19">
            <blockpin signalname="XLXN_26" name="I0" />
            <blockpin signalname="XLXN_23" name="I1" />
            <blockpin signalname="XLXN_21" name="I2" />
            <blockpin signalname="XLXN_24" name="I3" />
            <blockpin signalname="Buzzer" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1776" y="416" name="XLXI_1" orien="R0" />
        <instance x="1776" y="896" name="XLXI_3" orien="R0" />
        <instance x="1776" y="608" name="XLXI_5" orien="R0" />
        <instance x="1776" y="1088" name="XLXI_6" orien="R0" />
        <branch name="XLXN_2">
            <wire x2="1776" y1="224" y2="224" x1="1744" />
        </branch>
        <instance x="1520" y="256" name="XLXI_8" orien="R0" />
        <branch name="B">
            <wire x2="1440" y1="224" y2="224" x1="640" />
            <wire x2="1440" y1="224" y2="704" x1="1440" />
            <wire x2="1776" y1="704" y2="704" x1="1440" />
            <wire x2="1520" y1="224" y2="224" x1="1440" />
        </branch>
        <branch name="D">
            <wire x2="960" y1="288" y2="288" x1="640" />
            <wire x2="960" y1="288" y2="960" x1="960" />
            <wire x2="1120" y1="960" y2="960" x1="960" />
            <wire x2="1360" y1="288" y2="288" x1="960" />
            <wire x2="1360" y1="288" y2="768" x1="1360" />
            <wire x2="1776" y1="768" y2="768" x1="1360" />
        </branch>
        <branch name="XLXN_8">
            <wire x2="1776" y1="480" y2="480" x1="1344" />
        </branch>
        <iomarker fontsize="28" x="640" y="224" name="B" orien="R180" />
        <instance x="1120" y="512" name="XLXI_16" orien="R0" />
        <branch name="E">
            <wire x2="880" y1="352" y2="352" x1="640" />
            <wire x2="1040" y1="352" y2="352" x1="880" />
            <wire x2="1040" y1="352" y2="480" x1="1040" />
            <wire x2="1120" y1="480" y2="480" x1="1040" />
            <wire x2="1776" y1="352" y2="352" x1="1040" />
            <wire x2="880" y1="352" y2="1024" x1="880" />
            <wire x2="1776" y1="1024" y2="1024" x1="880" />
        </branch>
        <branch name="H">
            <wire x2="1776" y1="544" y2="544" x1="640" />
        </branch>
        <branch name="S">
            <wire x2="1040" y1="608" y2="608" x1="640" />
            <wire x2="1040" y1="608" y2="832" x1="1040" />
            <wire x2="1120" y1="832" y2="832" x1="1040" />
            <wire x2="1520" y1="608" y2="608" x1="1040" />
            <wire x2="1520" y1="288" y2="608" x1="1520" />
            <wire x2="1776" y1="288" y2="288" x1="1520" />
        </branch>
        <branch name="XLXN_14">
            <wire x2="1360" y1="832" y2="832" x1="1344" />
            <wire x2="1776" y1="832" y2="832" x1="1360" />
        </branch>
        <instance x="1120" y="864" name="XLXI_17" orien="R0" />
        <instance x="1120" y="992" name="XLXI_18" orien="R0" />
        <branch name="XLXN_16">
            <wire x2="1776" y1="960" y2="960" x1="1344" />
        </branch>
        <instance x="2480" y="784" name="XLXI_19" orien="R0" />
        <branch name="XLXN_21">
            <wire x2="2048" y1="512" y2="512" x1="2032" />
            <wire x2="2320" y1="512" y2="512" x1="2048" />
            <wire x2="2320" y1="512" y2="592" x1="2320" />
            <wire x2="2480" y1="592" y2="592" x1="2320" />
        </branch>
        <branch name="XLXN_23">
            <wire x2="2320" y1="768" y2="768" x1="2032" />
            <wire x2="2480" y1="656" y2="656" x1="2320" />
            <wire x2="2320" y1="656" y2="768" x1="2320" />
        </branch>
        <branch name="XLXN_24">
            <wire x2="2400" y1="288" y2="288" x1="2032" />
            <wire x2="2400" y1="288" y2="528" x1="2400" />
            <wire x2="2480" y1="528" y2="528" x1="2400" />
        </branch>
        <branch name="XLXN_26">
            <wire x2="2400" y1="992" y2="992" x1="2032" />
            <wire x2="2400" y1="720" y2="992" x1="2400" />
            <wire x2="2480" y1="720" y2="720" x1="2400" />
        </branch>
        <branch name="Buzzer">
            <wire x2="2768" y1="624" y2="624" x1="2736" />
        </branch>
        <iomarker fontsize="28" x="2768" y="624" name="Buzzer" orien="R0" />
        <iomarker fontsize="28" x="640" y="608" name="S" orien="R180" />
        <iomarker fontsize="28" x="640" y="544" name="H" orien="R180" />
        <iomarker fontsize="28" x="640" y="288" name="D" orien="R180" />
        <iomarker fontsize="28" x="640" y="352" name="E" orien="R180" />
    </sheet>
</drawing>