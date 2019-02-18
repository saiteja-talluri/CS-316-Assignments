testdir="tests"


if [ ! -d "$testdir" ]; 
then
	echo "No directory named $testdir"
	exit
fi

make

nodiff=true
stopondiff=false
#ignore these for now

for filename in "$testdir"/*.c; do
	./mysclp -ast -eval "$filename" 2> /dev/null
	mv "$filename.eval" "$filename.myeval"
	mv "$filename.ast" "$filename.myast"
	./sclp -ast -eval "$filename" 2> /dev/null
	DIFF1=$(diff "$filename.ast" "$filename.myast")
	DIFF2=$(diff "$filename.eval" "$filename.myeval")
	
	./mysclp "$filename" 2>"$filename.myerr"
	mv "$filename.spim" "$filename.myspim"
	./sclp "$filename" 2>"$filename.err"
	DIFF3=$(diff "$filename.spim" "$filename.myspim")
	DIFF4=$(diff "$filename.err" "$filename.myerr")

	if [ "$DIFF1" != "" ]
	then
		echo "ast comparison failed on $filename. Did not run further tests (lexicographic ordering)."
		echo "Showing diff:"
		echo "$DIFF1"
		exit
	fi

	if [ "$DIFF2" != "" ]
	then
		echo "eval comparison failed on $filename. Did not run further tests (lexicographic ordering)."
		echo "Showing diff:"
		echo "$DIFF2"
		exit
	fi

	if [ "$DIFF3" != "" ]
	then
		echo "spim code comparison failed on $filename. Did not run further tests (lexicographic ordering)."
		echo "Showing diff:"
		echo "$DIFF3"
		exit
	fi

	if [ "$DIFF4" != "" ]
	then
		echo "error message comparison failed on $filename. "
		echo "Showing diff:"
		echo "$DIFF4"
		echo "Continuing with further tests."
		echo ""
		echo ""
		# exit
	fi
done
echo "All tests passed!"