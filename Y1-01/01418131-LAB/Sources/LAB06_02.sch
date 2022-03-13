<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_6">
        </signal>
        <signal name="XLXN_10" />
        <signal name="XLXN_11" />
        <signal name="XLXN_25" />
        <signal name="XLXN_29" />
        <signal name="XLXN_30" />
        <signal name="XLXN_34" />
        <signal name="XLXN_36" />
        <signal name="XLXN_41" />
        <signal name="XLXN_45" />
        <signal name="XLXN_47" />
        <signal name="XLXN_5" />
        <signal name="S0" />
        <signal name="XLXN_52" />
        <signal name="XLXN_28" />
        <signal name="XLXN_31" />
        <signal name="XLXN_35" />
        <signal name="XLXN_37" />
        <signal name="XLXN_63" />
        <signal name="B" />
        <signal name="C" />
        <signal name="D" />
        <signal name="XLXN_72" />
        <signal name="A" />
        <signal name="XLXN_77" />
        <signal name="XLXN_78" />
        <signal name="XLXN_79" />
        <signal name="XLXN_80" />
        <signal name="XLXN_81" />
        <signal name="XLXN_82" />
        <signal name="XLXN_26" />
        <signal name="XLXN_93" />
        <signal name="XLXN_96" />
        <signal name="XLXN_105" />
        <signal name="C1" />
        <signal name="XLXN_111" />
        <signal name="S1" />
        <signal name="XLXN_116" />
        <signal name="XLXN_117" />
        <port polarity="Output" name="S0" />
        <port polarity="Input" name="B" />
        <port polarity="Input" name="C" />
        <port polarity="Input" name="D" />
        <port polarity="Input" name="A" />
        <port polarity="Output" name="C1" />
        <port polarity="Output" name="S1" />
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
        <blockdef name="or2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="192" ey="-96" sx="112" sy="-48" r="88" cx="116" cy="-136" />
            <arc ex="48" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <line x2="48" y1="-144" y2="-144" x1="112" />
            <arc ex="112" ey="-144" sx="192" sy="-96" r="88" cx="116" cy="-56" />
            <line x2="48" y1="-48" y2="-48" x1="112" />
        </blockdef>
        <blockdef name="vcc">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-64" x1="64" />
            <line x2="64" y1="0" y2="-32" x1="64" />
            <line x2="32" y1="-64" y2="-64" x1="96" />
        </blockdef>
        <blockdef name="gnd">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-96" x1="64" />
            <line x2="52" y1="-48" y2="-48" x1="76" />
            <line x2="60" y1="-32" y2="-32" x1="68" />
            <line x2="40" y1="-64" y2="-64" x1="88" />
            <line x2="64" y1="-64" y2="-80" x1="64" />
            <line x2="64" y1="-128" y2="-96" x1="64" />
        </blockdef>
        <block symbolname="vcc" name="XLXI_16">
            <blockpin signalname="XLXN_81" name="P" />
        </block>
        <block symbolname="gnd" name="XLXI_17">
            <blockpin signalname="XLXN_80" name="G" />
        </block>
        <block symbolname="and2" name="XLXI_3">
            <blockpin signalname="B" name="I0" />
            <blockpin signalname="A" name="I1" />
            <blockpin signalname="XLXN_31" name="O" />
        </block>
        <block symbolname="xor2" name="XLXI_4">
            <blockpin signalname="B" name="I0" />
            <blockpin signalname="A" name="I1" />
            <blockpin signalname="S0" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_5">
            <blockpin signalname="D" name="I0" />
            <blockpin signalname="C" name="I1" />
            <blockpin signalname="XLXN_28" name="O" />
        </block>
        <block symbolname="xor2" name="XLXI_6">
            <blockpin signalname="D" name="I0" />
            <blockpin signalname="C" name="I1" />
            <blockpin signalname="XLXN_5" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_9">
            <blockpin signalname="XLXN_28" name="I0" />
            <blockpin signalname="XLXN_26" name="I1" />
            <blockpin signalname="C1" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_7">
            <blockpin signalname="XLXN_5" name="I0" />
            <blockpin signalname="XLXN_31" name="I1" />
            <blockpin signalname="XLXN_26" name="O" />
        </block>
        <block symbolname="xor2" name="XLXI_8">
            <blockpin signalname="XLXN_5" name="I0" />
            <blockpin signalname="XLXN_31" name="I1" />
            <blockpin signalname="S1" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1168" y="672" name="XLXI_3" orien="R0" />
        <instance x="1168" y="512" name="XLXI_4" orien="R0" />
        <instance x="1168" y="1312" name="XLXI_5" orien="R0" />
        <instance x="1168" y="1152" name="XLXI_6" orien="R0" />
        <branch name="S0">
            <wire x2="1440" y1="416" y2="416" x1="1424" />
            <wire x2="2400" y1="416" y2="416" x1="1440" />
        </branch>
        <branch name="XLXN_28">
            <wire x2="2032" y1="1216" y2="1216" x1="1424" />
        </branch>
        <branch name="B">
            <wire x2="960" y1="544" y2="544" x1="720" />
            <wire x2="960" y1="544" y2="608" x1="960" />
            <wire x2="1168" y1="608" y2="608" x1="960" />
            <wire x2="960" y1="448" y2="544" x1="960" />
            <wire x2="1168" y1="448" y2="448" x1="960" />
        </branch>
        <branch name="C">
            <wire x2="1040" y1="704" y2="704" x1="720" />
            <wire x2="1040" y1="704" y2="1024" x1="1040" />
            <wire x2="1040" y1="1024" y2="1184" x1="1040" />
            <wire x2="1168" y1="1184" y2="1184" x1="1040" />
            <wire x2="1168" y1="1024" y2="1024" x1="1040" />
        </branch>
        <branch name="D">
            <wire x2="960" y1="864" y2="864" x1="720" />
            <wire x2="960" y1="864" y2="1088" x1="960" />
            <wire x2="1168" y1="1088" y2="1088" x1="960" />
            <wire x2="960" y1="1088" y2="1248" x1="960" />
            <wire x2="1168" y1="1248" y2="1248" x1="960" />
        </branch>
        <branch name="XLXN_80">
            <wire x2="240" y1="416" y2="576" x1="240" />
            <wire x2="240" y1="576" y2="736" x1="240" />
            <wire x2="240" y1="736" y2="896" x1="240" />
            <wire x2="640" y1="896" y2="896" x1="240" />
            <wire x2="240" y1="896" y2="1024" x1="240" />
            <wire x2="640" y1="736" y2="736" x1="240" />
            <wire x2="640" y1="576" y2="576" x1="240" />
            <wire x2="640" y1="416" y2="416" x1="240" />
        </branch>
        <text x="668" y="308">[A]</text>
        <text x="672" y="460">[B]</text>
        <text x="672" y="624">[C]</text>
        <text x="672" y="784">[D]</text>
        <instance x="1680" y="1024" name="XLXI_7" orien="R0" />
        <instance x="1680" y="864" name="XLXI_8" orien="R0" />
        <branch name="C1">
            <wire x2="2304" y1="1184" y2="1184" x1="2288" />
            <wire x2="2400" y1="720" y2="720" x1="2304" />
            <wire x2="2304" y1="720" y2="1184" x1="2304" />
        </branch>
        <branch name="S1">
            <wire x2="1952" y1="768" y2="768" x1="1936" />
            <wire x2="2400" y1="576" y2="576" x1="1952" />
            <wire x2="1952" y1="576" y2="768" x1="1952" />
        </branch>
        <branch name="XLXN_5">
            <wire x2="1520" y1="1056" y2="1056" x1="1424" />
            <wire x2="1680" y1="800" y2="800" x1="1520" />
            <wire x2="1520" y1="800" y2="960" x1="1520" />
            <wire x2="1520" y1="960" y2="1056" x1="1520" />
            <wire x2="1680" y1="960" y2="960" x1="1520" />
        </branch>
        <branch name="XLXN_31">
            <wire x2="1520" y1="576" y2="576" x1="1424" />
            <wire x2="1520" y1="576" y2="736" x1="1520" />
            <wire x2="1600" y1="736" y2="736" x1="1520" />
            <wire x2="1600" y1="736" y2="896" x1="1600" />
            <wire x2="1680" y1="896" y2="896" x1="1600" />
            <wire x2="1680" y1="736" y2="736" x1="1600" />
        </branch>
        <branch name="XLXN_26">
            <wire x2="1968" y1="928" y2="928" x1="1936" />
            <wire x2="1968" y1="928" y2="1152" x1="1968" />
            <wire x2="2032" y1="1152" y2="1152" x1="1968" />
        </branch>
        <instance x="2032" y="1280" name="XLXI_9" orien="R0" />
        <instance x="96" y="224" name="XLXI_16" orien="R0" />
        <instance x="176" y="1152" name="XLXI_17" orien="R0" />
        <iomarker fontsize="28" x="2400" y="720" name="C1" orien="R0" />
        <iomarker fontsize="28" x="2400" y="576" name="S1" orien="R0" />
        <iomarker fontsize="28" x="2400" y="416" name="S0" orien="R0" />
        <branch name="XLXN_81">
            <wire x2="160" y1="224" y2="352" x1="160" />
            <wire x2="160" y1="352" y2="512" x1="160" />
            <wire x2="160" y1="512" y2="672" x1="160" />
            <wire x2="640" y1="672" y2="672" x1="160" />
            <wire x2="160" y1="672" y2="832" x1="160" />
            <wire x2="640" y1="832" y2="832" x1="160" />
            <wire x2="640" y1="512" y2="512" x1="160" />
            <wire x2="640" y1="352" y2="352" x1="160" />
        </branch>
        <branch name="A">
            <wire x2="1040" y1="384" y2="384" x1="720" />
            <wire x2="1040" y1="384" y2="544" x1="1040" />
            <wire x2="1168" y1="544" y2="544" x1="1040" />
            <wire x2="1168" y1="384" y2="384" x1="1040" />
        </branch>
        <iomarker fontsize="28" x="720" y="384" name="A" orien="R180" />
        <iomarker fontsize="28" x="720" y="544" name="B" orien="R180" />
        <iomarker fontsize="28" x="720" y="704" name="C" orien="R180" />
        <iomarker fontsize="28" x="720" y="864" name="D" orien="R180" />
    </sheet>
</drawing>