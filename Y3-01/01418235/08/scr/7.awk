BEGIN {
    print "ID\tQuiz1\tQuiz2\tQuiz3\tQuiz4\tQuiz5";
}

{
    N_RECORDS = 40;

    while (N_RECORDS--) {
	printf("%04d", int(rand() * 10000) % 5000);

	N_FIELDS = 5;

	while (N_FIELDS--)
	    printf("\t%d", int(rand() * 10000) % 100);

	print;
    }
}
