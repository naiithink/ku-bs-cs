BEGIN {
    HOUR_MAX = 0;
    RES_RECORD = "";
}

{
    if ($4 > HOUR_MAX) {
	HOUR_MAX = $4;
	RES_RECORD = $0;
    } else if ($4 == HOUR_MAX)
	RES_RECORD = RES_RECORD "\n" $0;
}

END {
    print RES_RECORD;
}
