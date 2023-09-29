BEGIN {
    NUM_FILES = 0;

    EXTS[0] = "*";
    EXTS_NEXT = 1;
    
    EXT_COUNT[EXTS[0]] = 0;
    EXT_SIZE[EXTS[0]] = 0;
}

function arr_find(arr, size, elem) {
    for (i = 0; i < size; ++i)
	if (arr[i] == elem)
	    return i;

    return -1;
}

{
    if (NR <= 1)
	next;

    file_name = $NF;

    last = split(file_name, slugs, ".", seps);

    file_extension = slugs[last];

    if ((i = arr_find(EXTS, EXTS_NEXT, file_extension)) < 0) {
	EXTS[EXTS_NEXT] = file_extension;
	EXTS_NEXT++;
    }

    EXT_COUNT[file_extension]++;
    EXT_SIZE[file_extension] += $5;
}

END {
    asort(EXTS);
    
    print("Number of files : " (NR - 1));

    exts_bound = EXTS_NEXT + 1;

    for (i = 2; i < exts_bound; ++i) {
	print("Number of file type - " EXTS[i] " : " EXT_COUNT[EXTS[i]] "\t\ttotal size: " EXT_SIZE[EXTS[i]] " bytes");
    }

    print("Number of unknown file type : " EXT_COUNT["*"] "\t\ttotal size: " EXT_SIZE["*"] " bytes");
}
