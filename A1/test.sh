testdir="tests"



if [ ! -d "$testdir" ]; 
then
	echo "No directory named $testdir"
	exit
fi

make

for filename in "$testdir"/*.c; do
	./mysclp -tokens -parse "$filename"
	mv "$filename.toks" "$filename.mytoks"
	./sclp -tokens -parse "$filename"
	DIFF=$(diff "$filename.toks" "$filename.mytoks")
	if [ "$DIFF" != "" ]
	then
		echo "Failed on $filename. Did not run further tests (lexicographic ordering)."
		echo "Showing diff:"
		echo "$DIFF"
		exit
	fi
done
echo "All tests passed!"
