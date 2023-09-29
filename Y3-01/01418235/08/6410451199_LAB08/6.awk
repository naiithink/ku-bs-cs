BEGIN {
    OPERATING_EXPENSE = 0;
    
    print "Weekly Report\n\
First Name\tLast Name\tRate\tHours\tTotal Income";
}

{
    TTL_INCOME = 0;
    
    if ($4 < 40)
	TTL_INCOME = $3 * $4;
    else
	TTL_INCOME = $3 * 40 + (($4 - 40) * ($3 * 1.5));

    OPERATING_EXPENSE += TTL_INCOME;

    printf("%s\t\t%s\t\t%s\t%s\t%.2f\n", $1, $2, $3, $4, TTL_INCOME);
    # print $1 "\t\t" $2 "\t\t" $3 "\t" $4 "\t" TTL_INCOME;
}

END {
    print "\nNet Operating Expense: " OPERATING_EXPENSE;
}
    
