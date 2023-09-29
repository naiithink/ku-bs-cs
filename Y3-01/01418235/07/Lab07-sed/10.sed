/\blease\b.*{/ {
        s/lease \(.*\) {/\1/
        h
	d
}

/\bhardware\b/ {
        s/.*hardware .* \(.*\);/\1/
        G
	s/\(.*\)\n\(.*\)/\2 \1/p
}

d