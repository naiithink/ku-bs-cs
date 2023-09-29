BEGIN {
    T_BORDER = "---------------------------------------------";
    
    NUM_FIELDS = 6;

    MAX[1] = 0;
    MAX[2] = 0;
    MAX[3] = 0;
    MAX[4] = 0;
    MAX[5] = 0;
    
    MIN[1] = 100;
    MIN[2] = 100;
    MIN[3] = 100;
    MIN[4] = 100;
    MIN[5] = 100;
    
    TOTAL[1] = 0;
    TOTAL[2] = 0;
    TOTAL[3] = 0;
    TOTAL[4] = 0;
    TOTAL[5] = 0;

    # Write output
    
    print T_BORDER;

    print " ID\tQuiz1\tQuiz2\tQuiz3\tQuiz4\tQuiz5";

    print T_BORDER;
}

function compare(val1, val2) {
    return val1 - val2;
}

{
    if (NR > 1) {
	print $0;

	ni = NF + 1;

	for (i = 2; i < ni; ++i) {
	    TOTAL[i-1] += $i;

	    if (compare(MAX[i-1], $i) < 0)
		MAX[i-1] = $i;

	    if (compare(MIN[i-1], $i) > 0)
		MIN[i-1] = $i;
	}
    }
}

END {
    printf("Max");

    for (i = 1; i < NUM_FIELDS; ++i) {
	printf("\t%d", MAX[i]);
    }

    print "";

    printf("Min");

    for (i = 1; i < NUM_FIELDS; ++i) {
	printf("\t%d", MIN[i]);
    }

    print "";

    print T_BORDER;

    printf("Avg");

    for (i = 1; i < NUM_FIELDS; ++i) {
	printf("\t%.1f", TOTAL[i] / (NR - 1));
    }

    print "";

    print T_BORDER;
}
