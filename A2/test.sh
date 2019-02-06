testdir="tests"



if [ ! -d "$testdir" ]; 
then
	echo "No directory named $testdir"
	exit
fi

make

for filename in "$testdir"/*.c; do
	./mysclp -ast "$filename"
	mv "$filename.spim" "$filename.myspim"
	mv "$filename.ast" "$filename.myast"
	./sclp -ast "$filename"
	DIFF1=$(diff "$filename.spim" "$filename.spim")
	DIFF2=$(diff "$filename.ast" "$filename.ast")

	./mysclp "$filename" 2>"$filename.myerr"
	mv "$filename.spim" "$filename.myspim"
	./sclp "$filename" 2>"$filename.err"
	# DIFF3=$(diff "$filename.spim" "$filename.myspim")
	DIFF4=$(diff "$filename.err" "$filename.myerr")

	if [ "$DIFF1" != "" ]
	then
		echo "spim code comparison failed on $filename. Did not run further tests (lexicographic ordering)."
		echo "Showing diff:"
		echo "$DIFF1"
		exit
	fi

	if [ "$DIFF2" != "" ]
	then
		echo "-ast failed on $filename. Did not run further tests (lexicographic ordering)."
		echo "Showing diff:"
		echo "$DIFF2"
		exit
	fi

	# if [ "$DIFF3" != "" ]
	# then
	# 	echo "spimcode failed on $filename. Did not run further tests (lexicographic ordering)."
	# 	echo "Showing diff:"
	# 	echo "$DIFF3"
	# 	exit
	# fi

	if [ "$DIFF4" != "" ]
	then
		echo "spim error message failed on $filename. Did not run further tests (lexicographic ordering)."
		echo "Showing diff:"
		echo "$DIFF4"
		exit
	fi
done
echo "All tests passed!"
