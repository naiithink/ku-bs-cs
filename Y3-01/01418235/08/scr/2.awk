BEGIN {
    FS = "\t";
}

{
    print NF;
}
