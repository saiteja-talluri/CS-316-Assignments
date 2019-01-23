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
	DIFF1=$(diff "$filename.toks" "$filename.mytoks")


	./mysclp -eval "$filename"
	mv "$filename.eval" "$filename.myeval"
	./sclp -eval "$filename"
	DIFF2=$(diff "$filename.eval" "$filename.myeval")

	if [ "$DIFF1" != "" ]
	then
		echo "-parse -tokens failed on $filename. Did not run further tests (lexicographic ordering)."
		echo "Showing diff:"
		echo "$DIFF1"
		exit
	fi

	if [ "$DIFF2" != "" ]
	then
		echo "-eval failed on $filename. Did not run further tests (lexicographic ordering)."
		echo "Showing diff:"
		echo "$DIFF1"
		exit
	fi
done
echo "All tests passed!"
